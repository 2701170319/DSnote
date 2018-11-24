data segment
buf db 5,8,1,3,2,9,4,7,6,10
cnt equ $-buf
data ends

code segment
     assume cs:code, ds:data
start:mov ax,data
     mov ds,ax
     lea bx,buf
     mov cx,cnt-1
loop1: mov dx,cx
       mov si,1
       mov al,[bx]
loop2: cmp al,[bx+si]
       jl next
       xchg al,[bx+si]
next: inc si
      dec dx
      jnz loop2
mov [bx],al
    inc bx
    loop loop1
mov ah,4ch
int 21h
code ends
end start

