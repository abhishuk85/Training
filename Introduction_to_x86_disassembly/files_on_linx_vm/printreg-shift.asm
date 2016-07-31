section .data
loop_index db 0x0, 0x0, 0x0, 0x0				;counter for buffer index
byteToPrint db 0x0

section .text

global _start 

_safe_exit:
    mov eax, 1  ;initiate 'exit' syscall
	mov ebx, 0  ;exit with error code 0
	int 0x80    ;invoke kernel to do its bidding 

;EAX - ORIG VALUE
;ECX - Bits to Shift
;EBX - LOOP INDEX
;EDX - DO LOOP MATH ON THIS ONE
_print_eax:
mov ebx, 7
loop:
	mov edx, eax	;copy the value into edx for us to do manipulations on
	mov ecx, ebx
	shl ecx, 2	;multiply by 4
	shr	edx, cl 
	and edx, 0xf	;get rid of all but the bottom nibble

	cmp	dl, 10		;check if the re_startder is less than 10	
	jge _ascii_to_hex	;if it was greater or equal to 10 then we know its A-F
	add dl, '0'		; its a numeric digit, add '0' to conver to ascii
	jmp _ascii_to_end
_ascii_to_hex:
	add dl,'7' 		;its A-F, add 0x55 which how to convert to a letter 
_ascii_to_end:
	dec ebx
	mov [byteToPrint], dl; store the result into memory
	;save our values
	push eax
	push ebx
	;print it 
	mov eax, 4                ; system call #4 = sys_write
	mov ebx, 1                ; file descriptor 1 = stdout
	mov ecx, byteToPrint     ; store *address* into ecx
	mov edx, 1                ; len 
	int 0x80                  ; syscall

	;get our values back
	pop ebx
	pop eax			;restore the re_starting value from the last iteration

	cmp ebx, 0		;check if we've shifted enough times 
	jge loop				;if its not zero we still need to iterate
	ret

_start:
mov eax, 0xABCDEF12;register value we want to print
call _print_eax
jmp _safe_exit
