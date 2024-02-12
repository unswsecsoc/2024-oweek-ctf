# Writeup for `maths test`

|   author  | category | value |
|-----------|----------|-------|
| larrabyte |  binary  |  100  |

I didn't do that well in this year's advanced exam, could you help me solve this question?

| cost |                                                     content                                                     |
|------|-----------------------------------------------------------------------------------------------------------------|
|  0   | Is over/underflow possible in this program?                                                                     |
|  0   | The binary is running on an x86_64 Linux system. How many bits would a standard C `int` on such a platform use? |

## Files

- [src/challenge.c](src/challenge.c): The challenge source code.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Taking advantage of integer overflow to make two non-zero integers multiply to zero.

### Walkthrough

The program asks for two integers and prints their product. The code suggests 0 is explicitly rejected by the program, which can be confirmed after a quick test. Therefore, we must somehow conjure up two non-zero integers whose product is 0.

In the world of pure mathematics, this is impossible. However, computers **usually** represent integers using a fixed number of bits (binary digits), the number of which usually depends on the speed and complexity of the computer in question. On most modern platforms, a C `int` uses 32 bits, meaning it can represent integers from -2^31 to 2^31 - 1 (the reason for this why this range can be found in COMP1521), and mathematical operations are assumed to not require more than 32 bits of integer precision (i.e. the result of an operation is assumed to never exceed what can be represented).

So what happens if we try anyway? In most cases (specific platforms do exist where this behaviour is different), the result is evaluated and then truncated to the lowest 32 bits. An example (note that `0b` is just a prefix that indicates binary, it's not actually apart of the number itself):

```
  65536      (0b10000000000000000)
* 65536      (0b10000000000000000)
= 4294967296 (0b100000000000000000000000000000000)
= 0          (0b 00000000000000000000000000000000) (truncated to lowest 32 bits)
```

If we input `65536` for both numbers, the program prints our flag as the result of the multiplication is zero (when truncated).

### Flag(s)

- `OWEEK{1_n3V3r_m45t3r3d_my_t1m35_t4bl3z}`

</details>
