assume cs:code, ds:data

data segment

    stack dw ?, ?
    output db '1到100之间所有整数的和是:$'

data ends

code segment

start:
    mov ax, data
    mov ds, ax
    mov ax, stack ;定义栈段
    mov ss, ax
    mov sp, 4h

    mov ax, 0 ;将结果放入ax
    mov bx, 1
    mov cx, 100


s:  add ax, bx
    inc bx
    loop s

    mov cx, 0 ;计算输出位数
    mov bx, 10 ;每次除以10，余数dx入栈
div10:  
    mov dx, 0 ;这一步一定放入循环中。。。
    div bx
    push dx
    inc cx

    cmp ax, 0
    jz put1

    jmp div10

put1:
    mov dl, offset output ;当用lea时，显示type错
    mov ah, 09h
    int 21h

put:
    pop dx
    add dl, 30h
    mov ah, 02h
    int 21h

    loop put ;循环出栈

    mov ax, 4c00h
    int 21h

code ends
end start
