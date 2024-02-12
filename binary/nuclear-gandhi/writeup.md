# Writeup for `nuclear gandhi`

|   author  | category | value |
|-----------|----------|-------|
| larrabyte |  binary  |  100  |

Only the chosen ones will be able to read Gandhi's final words...

| cost |                                    content                                     |
|------|--------------------------------------------------------------------------------|
|  0   | What range of integers will `scanf("%d", &i)` scan in?                         |
|  0   | Are there limits on how small or large integers can be on a computer?          |
|  0   | What happens if you exceed the limits of how small or large an integer can be? |

## Files

- [src/challenge.c](src/challenge.c): The challenge source code.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Taking advantage of integer underflow to cause the flag-reading loop to run for longer than expected.

### Walkthrough

The program asks for the number of characters to read from a flag file, with an explicit check preventing inputs greater than 5. However, there are no checks for negative inputs.

If we input a random negative number, like `-1` for `i`, the loop decrements `i`, adds 1 and then checks if the result is greater than zero. For almost all negative numbers, this means nothing is printed.

However, it is possible to cause the decrement to underflow `i` such that `i` wrapsaround to being an extremely large positive number by inputting the largest negative number representable. On modern x86_64 Linux systems, an `int` is represented with 32 bits. This makes the largest representable negative integer `-2147483648`, or -(2^31). The decrement will then wrap `i` to the largest representable positive integer, `2147483647`, or 2^31 - 1, which causes the loop to print the entire flag.

### Flag(s)

- `OWEEK{i_7h0u9ht_num83r5_w3n7_t0_inf1n17y}`

</details>
