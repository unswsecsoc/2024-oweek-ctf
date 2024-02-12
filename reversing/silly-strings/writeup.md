# Writeup for `silly strings`

|   author  |  category | value |
|-----------|-----------|-------|
| larrabyte | reversing |  100  |

You ever wanted to know how to make silly string? Just crack this box!

**Note**: This challenge requires access to a Linux environment, which can either be done with CSE machines given to you by the university or WSL on Windows.

| cost |                                                         content                                                          |
|------|--------------------------------------------------------------------------------------------------------------------------|
|  0   | How does the program know whether the password is correct or not? It must have a copy of the correct password somewhere. |
|  0   | There are many tools on Linux for examining executable programs. For this challenge, `strings` will be the most useful.  |

## Files

- [a.out](a.out): Top secret program.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Using `strings` to locate a password embedded within the binary.

### Walkthrough

`strings` is a program on Linux that prints all valid strings of length 4 or more embedded inside a file. If we run it on our binary, we don't see any mention of a flag, but we do see `TOP_SECRET_PASSWORD_DO_NOT_REVEAL`. If we input this for the password, the flag is revealed.

### Flag(s)

- `OWEEK{n07_ex4c7ly_7he_m057_5ecure_b0x}`

</details>
