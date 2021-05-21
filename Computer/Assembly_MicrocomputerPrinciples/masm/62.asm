assume cs:code, ds:data

data segment

    x dw 1110h
    y db 'Put a binary number:$'
    z dw 16 dup(?)

data ends

code segment

start:
    mov ax, data
    mov ds, ax
    mov ss, ax
    lea bx, z
    add bx, 20h
    mov sp, bx
    lea bx, x
    mov ax, [bx]
    mov cx, 0
    
s:    
    mov dx, ax
    and dx, 1b
    shr ax, 1
    push dx
    inc cx
    cmp ax, 0
    ja s

    mov dl, offset y
    mov ah, 09h
    int 21h

put:
    pop dx
    add dl, 30h
    mov ah, 02h
    int 21h
    loop put

    mov ax, 4c00h
    int 21h

code ends
end start
