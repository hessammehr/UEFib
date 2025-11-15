# UEFib
Fibonacci on UEFI from scratch.

## What you need to build this
* Make
* Zig (used as a C cross-compiler)
* qemu for testing or an AMD64 PC

## Testing on bare metal
* Make sure secure boot is disabled. Format a USB drive using GUID partition table (GPT); not MBR, with at least one FAT32 partition.
* Copy the `efi` folder to your USB drive.
* Plug in and enjoy!

![85908CC9-D797-4221-A099-7F91C52A1539_1_105_c](https://github.com/user-attachments/assets/e335a02f-324c-4783-a64b-2966ee12c90a)
