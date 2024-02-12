# Writeup for `no nacl`

| author | category | value |
|--------|----------|-------|
| mtnull |  crypto  |  100  |

What happens if you do not salt your hashes to make them more secure?

| cost |                                                                                  content                                                                                   |
|------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|  0   | Each line in the text file represents an MD5 hash. Hashes are commonly used to convert some text value, such as a password, to gibberish that cannot be easily deciphered. |
|  0   | Try using a hash cracker to map each MD5 hash digest to its original input to create the flag for this challenge.                                                          |
|  0   | You can find a hash cracker online if you search hard enough :)                                                                                                            |

## Files

- [hashes.txt](hashes.txt): Weak MD5 hashes representing the challenge flag.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Cracking weak password hashes.

### Walkthrough

1. Open `hashes.txt` in a text editor.
2. Paste all the hashes into [CrackStation](https://crackstation.net), a password cracking site.
3. Click "Crack Hashes" to return the flag for this challenge.

### Flag(s)

- `OWEEK{n0_5a1t_n0_f4n}`

</details>
