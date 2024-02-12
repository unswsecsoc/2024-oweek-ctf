# Writeup for `impossible login`

|   author  | category | value |
|-----------|----------|-------|
| larrabyte |   web    |  100  |

I've made a brand new flag storage service for SecSoc so we can store all our flags for future CTFs securely. Problem is, I can't seem to login to see the flags. Why don't you try? The username is `root` and the password is `correct horse battery staple`.

| cost |                                     content                                     |
|------|---------------------------------------------------------------------------------|
|  0   | How is the 10 character password limit enforced?                                |
|  0   | Could you possibly edit the HTML on your side to bypass the limit?              |
|  0   | You may find right-clicking on the webpage and pressing `Inspect` to be useful. |

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Bypassing a client-side input length check present in the password field.

### Walkthrough

Attempting to enter the specified password, we are met with an error telling us that the password must be less than 10 characters in length. The check seems to immediately trigger regardless of input and upon inspecting the page with `Inspect Element`, we can see that the check is client-side, as the `pattern` field is specified as `.{0,10}`, meaning any input 0-10 (inclusive) characters in length. Changing the field to be `.{0,9999}` and inputting the password yields the flag.

### Flag(s)

- `OWEEK{cli3n7_5id3_v3rific47i0n_m34n5_n0_v3rific47i0n}`

</details>
