# Blake Arnold arnold.blake@gmail.com 7-4-16

DIR:=/home/barnold/Documents/osdev

# System Architecture
HOSTARCH:=i386
ARCHDIR:=arch/$(HOSTARCH)
include $(ARCHDIR)/Makefile

# Library LIBC
LIBCDIR:=$(DIR)/libc
include $(LIBCDIR)/Makefile

# Directories
DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

# List of Object Files
OBJ:=\
$(KERNEL_ARCH_OBJ) \
kernel/kernel.o \
$(LIBC_OBJ)

# Location of cross-compiler, assembler/compiler/linker flags
CC=~/opt/cross/bin/i686-elf-gcc

CFLAGS?=-O2 -g
CFLAGS:=$(CFLAGS) -ffreestanding -fno-builtin -Wall -Wextra -Iinclude -I../libc/include

AS=nasm
AFLAGS=-felf32

LFLAGS?=
LFLAGS:=$(LFLAGS)

LIB?=
LIB:=$(LIB)-nostdlib -lgcc

all: bos.kernel

# Assembly
%.o : %.S
	$(AS) $(AFLAGS) $< -o $@

# Compile
%.o: %.c
	$(CC) -c $(CFLAGS) -std=gnu99 $< -o $@

# Link
bos.kernel: $(OBJ) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(OBJ) $(LFLAGS) $(LIB)


# Clean
clean:
	rm -f bos.kernel $(OBJ)
