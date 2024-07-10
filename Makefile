BUILD_DIR = build
SRC_DIR = src

CFLAGS = -nostdlib -nostartfiles -ffreestanding -Iinclude -march=armv8-a -mfix-cortex-a53-835769
SFLAGS = -Iinclude

QFLAGS =

all: kernel8.img

run: kernel8.img
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -serial null -serial stdio -display none $(QFLAGS)

clean:
	rm -rf $(BUILD_DIR) kernel8.img

$(BUILD_DIR)/%-c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	aarch64-linux-gnu-gcc $(CFLAGS) -MMD -c $< -o $@

$(BUILD_DIR)/%-S.o: $(SRC_DIR)/%.S
	mkdir -p $(@D)
	aarch64-linux-gnu-gcc $(SFLAGS) -MMD -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%-c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%-S.o)
DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

kernel8.img: $(SRC_DIR)/linker.ld $(OBJ_FILES)
	aarch64-linux-gnu-ld -T $(SRC_DIR)/linker.ld -o $(BUILD_DIR)/kernel8.elf $(OBJ_FILES)
	aarch64-linux-gnu-objcopy $(BUILD_DIR)/kernel8.elf -O binary kernel8.img
