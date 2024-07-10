# BearOS
This is a little side project of mine with a goal of building a multicore OS for the ARMv8-A architecture. I also plan to have it run on actual hardware, right now I'm planning to have it run on the Raspberry Pi 3, since the documentation for the BCM2837 SoC that it uses is easy to find and seems pretty readable.

# Getting Started

- I'm doing this all on Debian 12 running on WSL2, but this workflow should work on most Linux distros.
- To get the cross-compiler, you can run the equivalent of `apt-get install gcc-aarch64-linux-gnu` on your system.
- You'll probably also want QEMU, so that you can run the OS on your own computer using `make run`. Just run the equivalent of `apt-get install qemu-system`.
- TODO: Add instructions for running on actual Rpi3

# Progress
- First Commit: Setup inital boot 
