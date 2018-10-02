from pwn import *

s = remote("akaraka.xyz", 9006)

for _ in range(280):
    s.recv()
    s.send("rock")

s.interactive()
