CC := zig cc
CFLAGS := -target x86_64-windows-gnu -ffreestanding -fno-stack-protector -fno-asynchronous-unwind-tables -mno-red-zone -O3
LDFLAGS := -Wl,--subsystem,efi_application -nostdlib
OVMF_PATH := /opt/homebrew/share/qemu/edk2-x86_64-code.fd

all: efi/boot/bootx64.efi

fib.o: fib.c
	$(CC) $(CFLAGS) -c -o fib.o fib.c

efi/boot/bootx64.efi: fib.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o efi/boot/bootx64.efi fib.o

run: efi/boot/bootx64.efi
	qemu-system-x86_64 -drive if=pflash,format=raw,readonly=on,file=$(OVMF_PATH) -drive format=raw,file=fat:rw:.