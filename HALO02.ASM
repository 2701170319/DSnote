data segment
     buf db 65,72,67,43,95,76,78,86,89,68,53,67,80,90,98,87,87,89,65,83
g5 db 0
g6 db 0
g7 db 0
g8 db 0
g9 db 0
data ends

code segment
     assume cs:code, ds:data
start: mov ax,data
       mov ds,ax
       lea si,buf
       mov cx,20

again: mov al,[si]
       cmp al,60
       jl a0

       cmp al,70
       jl a1

       cmp al,80
       jl a2

       cmp al,90
       jl a3

a4: inc g9
    jmp exit
a0: inc g5
    jmp exit
a1: inc g6
    jmp exit
a2: inc g7
    jmp exit
a3: inc g8
    jmp exit
exit: inc si
loop again

mov ah,4ch
int 21h
code ends
end start
