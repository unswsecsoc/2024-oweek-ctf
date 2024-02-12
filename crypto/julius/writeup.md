# Writeup for `julius`

|   author  | category | value |
|-----------|----------|-------|
| larrabyte |  crypto  |  100  |

We've managed to unearth an ancient Roman scroll with some garbled text on it. Can you can help us decipher what it says?

| cost |                              content                               |
|------|--------------------------------------------------------------------|
|  0   | What do you expect the text to look like when deciphered?          |
|  0   | Is there a pattern to the scrambling?                              |
|  0   | You may find [CyberChef](https://gchq.github.io/CyberChef) useful. |

## Files

- [message.txt](message.txt): The encrypted message.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

14-character offset Caesar cipher.

### Walkthrough

Using the theme of the description and category of the challenge (plus some searching), you should stumble on something known as a Caesar cipher. A Caesar cipher is an example of a substitution cipher, where each letter is substituted with another according to a constant offset. As an example, if we were to encrypt text with a 6-character offset, then the substitution would look something like this:

```
 Plaintext: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
Ciphertext: G H I J K L M N O P Q R S T U V W X Y Z A B C D E F
```

Using this table, we can then substitute each plaintext character for its ciphertext equivalent to create our encrypted message. Decryption follows essentially the same procedure, replacing each ciphertext character with its plaintext equivalent (assuming you know the offset).

We don't know the offset... so how can we decode the message? We know that the ciphertext has to contain `OWEEK` at the beginning when decrypted, and that there are only effectively 26 possible offsets as the rotations will cancel out every 26 letters. Using either manual methods or CyberChef, we can determine that the correct offset is 14.

### Flag(s)

- `OWEEK{d0n7_90_t0_7h3_s3n4t3_70m0rr0w}`

</details>
