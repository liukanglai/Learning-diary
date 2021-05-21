assume cs:code, ds:data, ss:stack

stack segment stack
	dw 20(?)
stack ends

data segment 
	tennumber dw 1, 0, 2, 3, 9, 10, 3, 8, 9, 11
	putneg db '-$'
data ends

code segment

start:
	mov ax, data
	mov ds, ax
	lea bx, tennumber
	mov cx, 9
	
findmin1:
	mov ax, [bx]
findmin2:
	inc bx
	inc bx
	cmp ax, [bx]
	jg findmin1
	loop findmin2

	mov cx, ax
	cmp cx, 0
	jge put
	mov dl, offset putneg
	mov ah, 09h
	int 21h
	neg cx
	
put:
	mov ax, cx
	div 10
	push dx
	loop 
	pop ax
	mov dl, cl
	add dl, 30h
	mov ah, 02h
	int 21h
	 
	mov ax, 4c00h
	int 21h

code ends
end start
