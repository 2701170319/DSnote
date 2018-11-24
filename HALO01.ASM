code segment
     assume cs:code
start: mov ah,01H
       int 21h
       sub al,20h
       mov dl,al
       mov ah,02h
       int 21h
mov ah,4ch
int 21h
code ends
end start
 
