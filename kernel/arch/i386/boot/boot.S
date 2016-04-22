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
; GLOBAL DESCRIPTOR TABLE                                                |
;-------------------------------------------------------------------------
gdt:
.null		dq 0x0	
.codepl0	dd 0x0000FFFF, 0x00CF9A00
.datapl0	dd 0x0000FFFF, 0x00CF9200	
.codepl3	dd 0x0000FFFF, 0x00CFFA00
.datapl3	dd 0x0000FFFF, 0x00CFF200
	
gdt_descriptor:
.size	dw gdt_descriptor - gdt - 1
.addr	dd gdt

_GDT_start:
	cli
	lgdt [gdt_descriptor]
	jmp 0x08:_GDT_jump
	
_GDT_jump:
; Setup segement registers for data GDT entry
	mov ax, 0x10
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	sti	
	ret
	
;-------------------------------------------------------------------------
; INTERUPT DESCRIPTOR TABLE                                              |
;-------------------------------------------------------------------------
idt:
	resd 50*2

idt_descriptor:
.size	dw idt_descriptor - idt - 1
.addr	dd idt

_IDT_start:
	cli
	lidt [idt_descriptor]
	
	mov ebx, 0x49
	call _IDT_ADD
	
	mov ebx, 0x0
	call _IDT_ADD
		
	sti
	ret
	
_IDT_ADD:
	push eax
	mov eax, isr
	mov [idt+ebx*8], ax
	mov word [idt+ebx*8+2], 0x08
	mov word [idt+ebx*8+4], 0x8E00
	shr eax, 16
	mov [idt+ebx*8+6], ax
	pop eax
	ret

isr:
	mov ax, 0x10
	mov gs, ax
	mov dword [gs:0xB8000], ') : '
	hlt
	iretd

;-------------------------------------------------------------------------
; PAGING                                                                 |
;-------------------------------------------------------------------------
_PAGING_start:
; Enable page size extension
	push eax
	mov eax, cr4
	or  eax, 1 << 4
	mov cr4, eax
	
; Set page directory
	extern page_directory
	mov eax, page_directory
	mov cr3, eax
	
; Turn on paging
	mov eax, cr0
	or  eax, (8 << 28) | (1 << 16)
	mov cr0, eax
	
; Jump to high half
	xor eax, eax
	mov eax, call_kmain
	add eax, 0x80000000
	jmp eax
	pop eax
	ret

;-------------------------------------------------------------------------
; START                                                                  |
;------------------------------------------------------------------------- 
section .text
global _start
_start:
	call _GDT_start
	call _IDT_start
	call _PAGING_start

call_kmain:
; Stack setup
	mov ebp, stack_top
	mov esp, stack_top
	
	extern kmain
	call kmain
	
; We shouldn't return to here
	cli	
hang:
	hlt
	jmp hang
	
section ._stack, nobits
align 4
resb STACK_SIZE
stack_top:
