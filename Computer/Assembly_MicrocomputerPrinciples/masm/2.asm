assume cs:code, ds:data, ss:stack

stack segment stack
	dw 20 dup(?)
stack ends

data segment
	putstr db 'Input a character: $'
	b db 'Binary:$'
	o db 'Octal:$'
	d db 'Decimal:$'
	h db 'Hexadecimal:$'
	number dw 2, 8, 10, 16 ; div 
	straddress dw 4 dup(?) ;存放b, o, d, h的地址
  address dw ? ;存放number的地址
  backupcx dw ? ;备份cx
data ends

code segment

start:

    mov ax, data
    mov ds, ax

    lea ax, b
    mov ds:[straddress], ax
    lea ax, o
    mov ds:2[straddress], ax
    lea ax, d
    mov ds:4[straddress], ax
    lea ax, h
    mov ds:6[straddress], ax
    lea ax, number
    mov ds:[address], ax

    lea dx, putstr 
    mov ah, 09h
    int 21h
	  mov ah, 01h
	  int 21h
    push ax ; int 21h会改变al的值。。。
    mov ah, 02h
    mov dl, 0dh
    int 21h 
    mov ah, 02h
    mov dl, 0ah
    int 21h 


    pop ax
	  mov ah, 0
	  mov cx, 4
    mov si, address
    lea di, straddress

loop4:
    mov ds:[backupcx], cx
    mov cx, 0 ;计算输出位数
    mov bx, [si]
    push ax
div0:  
    mov dx, 0 ;这一步一定放入循环中。。。
    div bx
    push dx
    inc cx

    cmp ax, 0
    jz put1

    jmp div0

put1:
    mov dx, [di]
    mov ah, 09h
    int 21h

putnum:
    pop dx
    add dl, 30h
    mov ah, 02h
    int 21h

    loop putnum ;循环出栈

    mov ah, 02h
    mov dl, 0dh
    int 21h 
    mov ah, 02h
    mov dl, 0ah
    int 21h 

    add si, 2
    add di, 2
    pop ax
    mov cx, ds:[backupcx]
    loop loop4
    
    mov ax, 4c00h
    int 21h

code ends
end start
