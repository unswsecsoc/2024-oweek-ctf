# Writeup for `ret2future`

|   author  | category | value |
|-----------|----------|-------|
| larrabyte |  binary  |  100  |

![The illusion of free choice.](https://i.redd.it/flf7majdwls71.png)

TODO: fix image


| cost |                                                 content                                                  |
|------|----------------------------------------------------------------------------------------------------------|
|  0   | The statement `typedef void (function)(void)` describes a function pointer, which is denoted `function`. |
|  0   | The binary is running on an x86_64 Linux system.                                                         |
|  0   | Are there any input functions which have unexpected behaviour for certain inputs?                        |
|  0   | The `pwntools` library has facilities for sending arbitrary bytes.                                       |

## Files

- [src/challenge.c](src/challenge.c): The challenge source code.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Taking advantage of a buffer overflow to overwrite a stored function pointer.

### Walkthrough

The program initialises a structure with the `function` member set to `lose`, and then asks for a name. If we abided by the 64 character limit, then we always end up jumping to the `lose` function.

Recall that input scanned using `scanf("%s")` performs no bounds checking, meaning we can simply supply more characters than the buffer can store in order to overwrite adjacent variables. In our case, we wish to overwrite the `function` member of the `data` variable. If we simply copy-paste 64 random characters and then the address of the `win` function as-is, it will fail to jump to the correct location. Why?

This is because the address was printed in a text format, rather than in raw byte form.
As a demonstration, here are the underlying bytes of a text-formatted address:

```
0    x    d    e    a    d    b    e    e    f    (hexadecimal address)
0x30 0x78 0x64 0x65 0x61 0x64 0x62 0x65 0x65 0x66 (underlying bytes)
```

On x86_64 processors, function addresses (or function pointers) take up 8 bytes in [little-endian](https://en.wikipedia.org/wiki/Endianness) format. What this means can be found via a bit of searching, but what it results in is the program jumping to `0x6562646165647830` rather than `0xdeadbeef`. In order to write the raw bytes for the address, we must use a tool that can generate raw bytes, such as a combination of Python with the [`pwntools`](https://github.com/Gallopsled/pwntools) library. As a future hint, you'll find most binary challenges significantly easier if you use `pwntools` as it provides many convenient facilities for completing binary CTFs.

Using Python and `pwntools`, we can supply the raw bytes [as can be seen in the sample solution](solution.py) for the function pointer and overwrite the address to print the flag.

### Flag(s)

- `OWEEK{88_m1l35_an_h0ur_m34n5_53r10u5_5h1t5_4b0ut_t0_h4pp3n}`

</details>
