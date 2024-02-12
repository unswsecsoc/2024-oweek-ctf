# Writeup for `emojitis`

| author | category | value |
|--------|----------|-------|
| mtnull |  crypto  |  100  |

A friend of mine caught emojitis, a dangerous disease that causes people to speak only in emojis! Can you help me decode what my friend has said?

| cost |                                       content                                        |
|------|--------------------------------------------------------------------------------------|
|  0   | What two values represent on and off in terms of a computer?                         |
|  0   | Can you represent "on" and "off" respectively as the emojis in the text file?        |
|  0   | To decipher the message, a text editor with a "Find and Replace" feature might help. |

## Files

- [emojitis.txt](emojitis.txt): Encoded challenge flag.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Convert the emojis into binary, and then binary into a string. 

### Walkthrough

1. Open the `emojitis.txt` file in a text editor.
2. Using the "Find and Replace" feature of your chosen text editor, swap all 😀 faces with `1` and 😴 faces with `0`.
3. After swapping all the emojis, you should get the following binary string: `1001111 1010111 1000101 1000101 1001011 1111011 1111001 110000 1110101 1011111 1110011 1101110 110000 110000 1111010 110011 1011111 1111001 110000 1110101 1011111 110001 110000 1110011 110011 1111101`.
4. Use a [binary to string converter](https://www.rapidtables.com/convert/number/binary-to-string.html) to convert the binary sequence to a string with ASCII/UTF-8 encoding.
5. It's also possible to convert the whole `emojitis.txt` file programatically and a solution has been provided in the `solution.py` file.

### Flag(s)

- `OWEEK{y0u_sn00z3_y0u_10s3}`

</details>
