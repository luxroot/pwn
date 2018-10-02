from pwn import *

s=process("./calc")

for _ in range(100):
    s.recvuntil(' >')
    inp = s.recv(3)
    (a,b)=map(int,s.recvline().split())
    if inp=='mul':
        snd=a*b
    elif inp=="add":
        snd=a+b
    elif inp=="sub":
        snd=a-b
    elif inp=="div":
        snd=a/b
    s.sendline(str(snd))
    sleep(0.01)

s.interactive()
