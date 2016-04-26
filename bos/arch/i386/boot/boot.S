; Blake Arnold 21-4-16
; Removed include lines. Make was not picking up changes to the files

%define STACK_SIZE 0x4000	;16k stack

;-------------------------------------------------------------------------
; MULTIBOOT                                                              |
;-------------------------------------------------------------------------
MBALIGN     equ  1<<0                   ; align loaded modules on page boundaries
MEMINFO     equ  1<<1                   ; provide memory map
FLAGS       equ  MBALIGN | MEMINFO      ; this is the Multiboot 'flag' field
MAGIC       equ  0x1BADB002             ; 'magic number' lets bootloader find the header
CHECKSUM    equ -(MAGIC + FLAGS)        ; checksum of above, to prove we are multiboot

section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

;-------------------------------------------------------------------------
; START                                                                  |
;-------------------------------------------------------------------------
section .text
global _start
extern page_directory
_start:

; Enable 4MB paging
	mov eax, cr4
	or 	eax, 0x00000010
	mov cr4, eax

; Set page directory
	mov eax, page_directory
	mov cr3, eax

; Enable paging
	mov eax, cr0
	or	eax, 0x80010000
	mov cr0, eax

; Stack setup
	mov esp, stack_top

	mov eax, page_directory
	push eax

	extern main
	call main

; We shouldn't return to here
hang:
	cli
	hlt
	jmp hang

section .stack
align 4
global stack_bottom
global stack_top
stack_bottom:
	resb STACK_SIZE
stack_top:
