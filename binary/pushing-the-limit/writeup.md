# Writeup for `pushing the limit`

|   author  | category | value |
|-----------|----------|-------|
| larrabyte |  binary  |  100  |

A great prize awaits for those who have stood the test of time.

| cost |                                                content                                                |
|------|-------------------------------------------------------------------------------------------------------|
|  0   | What does `scanf("%s", &person.name)` do? Does it have any unexpected behaviours for certain inputs?  |
|  0   | ASCII is a computer standard that maps numbers to letters. What letter does the number 100 represent? |
|  0   | What happens if you supply a name over 64 characters in length?                                       |

## Files

- [src/challenge.c](src/challenge.c): The challenge source code.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Taking advantage of a buffer overflow to overwrite the `age` member of the `person` variable.

### Walkthrough

The program asks for an input-validated age which must be within the range 0-100 exclusive. The flag is only printed if the age is 100, but 100 is rejected by the program is invalid.

The program then asks for a name using `scanf("%s", &person.name)`. This method of scanning in input does not perform any bounds checking, meaning that it will simply overwrite the contents of the buffer given with input from the user. Crucially, this means that if we supply input larger than the length of the provided buffer, we can potentially overwrite adjacent variables.

The buffer that `scanf` is writing into is 64 characters in size. Since the `age` variable is of type `char`, that means the 65th character (if there was one) would overwrite its value.

Letters themselves are represented by numbers in the world of computers. For the Latin alphabet, the most widely used standard is ASCII, which provides a mapping of integers to letters (the table can be found on CSE by running `man 7 ascii`). In our case, since we want the value 100 to be written, we can work backwards from the table and see that the letter `d` maps to 100. Inputting 64 random characters and then `d` will then print the flag.

### Flag(s)

- `OWEEK{l3ts_h0p3_y0ur3_5t1ll_4l1v3_4t_100}`

</details>
