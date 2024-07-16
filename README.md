# BearOS
This is a little side project of mine with a goal of building a multicore OS for the ARMv8-A architecture. Right now I'm planning to have it run on the Raspberry Pi 3, since the documentation for the BCM2837 SoC that it uses is easy to find and seems pretty readable.

# Getting Started

- I'm doing this all on Debian 12 running on WSL2, but this workflow should work on most Linux distros.
- To get the cross-compiler, you can run the equivalent of `apt-get install gcc-aarch64-linux-gnu` on your system.
- You'll probably also want QEMU, so that you can run the OS on your own computer using `make run SFLAGS='-DQEMU=TRUE'`. Just run the equivalent of `apt-get install qemu-system`.
- TODO: Add instructions for running on actual Rpi3

# Progress
- First Commit: Setup inital boot and mini UART, successfully loads and runs kernel_main() and writes to mini UART.
- Commit 2: Add a utility function for printing strings that abstracts the hardware. Some makefile improvements.
- Commit 3: Implemented some additional startup configuration(so we only run in el1/el0). Created exception vector table to handle exceptions/interrupts. Need to actually implement the handlers and set up timer interrupt for core 0.
- Commit 4/5: Configured generic timer and interrupt controlller, basic interrupts now working. Create handler for 