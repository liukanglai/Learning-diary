assume cs:code, ds:data

data segment 
    str0 db 80, ?, 80 dup(?)
    enter db 0ah, 0dh, '$'
    count db 0
data ends

code segment

main proc far
start: 
    mov ax, data
    mov ds, ax

    mov ah, 0ah
    lea dx, str0
    int 21h

    lea dx, enter
    mov ah, 09h
    int 21h

    mov bx, 0
    mov bl, str0+1
    mov al, '$'
    mov 2[bx], al

    lea si, str0+2
    mov cx, 0
    mov cl, str0+1

    call findmaxAscii
    ;mov ah, 09h
    ;lea dx, str0+2
    ;int 21h

    lea dx, enter
    mov ah, 09h
    int 21h

    mov ax, 4c00h
    int 21h

main endp

findmaxAscii proc near

  push cx ;记住串长度与起始地址
  push si 
findmax0:
  mov al,[si]
  cmp al,count ;count用来存放ascill最大的字符
  jbe findmax1
  mov count,al
findmax1:
  inc si
  dec cl
  jnz findmax0

  pop si
  pop cx
  cld ;清df为0，正方向
putStr:
    push cx ;cx的值在输出时用到
    lodsb               ;ds:si取数据至al
    cmp al,count
    jz maxPut           ;字符为ascill码最大
    mov bl,00000111b   ;bl属性正常输出,  银灰???
    mov bh,0           ;显示页为0
    mov cx,1           ;显示字符为1个
    mov ah,09h
    int 10h            ;输出bl属性的al字符, cx为个数，bh为页码
    mov ah,03h
    int 10h             ;读光标位置, 返回ax = 0，ch行扫描开始, cl结束, dh行, dl列
    inc dl             ;输出列+1, 光标后移一位
    mov ah,02h
    int 10h            ;置光标位置 dl为列,dh为行 bh为页码
    jmp putNext
maxPut:
   mov bl,10000100b   ;bl属性为红色输出
   mov bh,0
   mov cx,1
   mov ah,09h
   int 10h
   mov ah,03h
   int 10h
   inc dl
   mov ah,02h
   int 10h
putNext:
  pop cx
  loop putStr

  lea dx,enter        ;输出后，回车换行
  mov ah,09
  int 21h

    ret 

findmaxAscii endp

code ends
end start
