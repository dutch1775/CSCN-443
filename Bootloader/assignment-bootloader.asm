
mov si, output
mov ah, 0x0e

loop:
mov al, [si]

cmp al, 0
je endloop

int 0x10
inc si
jmp loop


endloop:

output db 'Welcome to CSIS-443', 0

times 510-($-$$) db 0
dw 0xaa55

