# Writeup for `metadata blob`

| author |  category | value |
|--------|-----------|-------|
| mtnull | forensics |  100  |

I received an emoji message from someone on Discord and apparently this emoji contains a hidden message. Can you find it?

| cost |                                                                 content                                                                  |
|------|------------------------------------------------------------------------------------------------------------------------------------------|
|  0   | Most images contain hidden metadata within the image file that may reveal sensitive information such as the location an image was taken. |

## Files

- [blob.gif](blob.gif): Image containing flag for this challenge.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Reading the EXIF data embedded within `blob.gif`.

### Walkthrough

1. Upload `blob.gif` to an [EXIF viewer site](https://jimpl.com).
2. Inside the "Author" EXIF tag is the flag for this challenge.

### Flag(s)

- `OWEEK{3v3n_1mag3s_can_b3_5us}`

</details>
