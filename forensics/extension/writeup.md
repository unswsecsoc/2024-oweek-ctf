# Writeup for `extension`

|   author  |  category | value |
|-----------|-----------|-------|
| larrabyte | forensics |  100  |

NESA just released a new video detailing the secret to getting the elusive 100 ATAR. Problem is the video doesn't play.

| cost |                                                                                                                      content                                                                                                                      |
|------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|  0   | Try opening the file inside a text editor.                                                                                                                                                                                                        |
|  0   | Could the file possibly be of another type (as opposed to being a corrupted video)?                                                                                                                                                               |
|  0   | Try changing the file extension. If you can't see the file extension (.mp4), [read here](https://support.microsoft.com/en-us/windows/common-file-name-extensions-in-windows-da4a4430-8e76-89c5-59f7-1cdbbc75cb01) to enable file name extensions. |

## Files

- [nesa-how-to-get-100-atar-top-secret.mp4](nesa-how-to-get-100-atar-top-secret.mp4): A seemingly corrupt video file.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

PDF disguised as an MP4.

### Walkthrough

File extensions are merely guides for the operating system to determine which program it should use to open a certain file, it has nothing to do with the actual file content itself. If we try and open the challenge file with a video player, it will refuse to play anything as it appears to be corrupted. Examining the file in a text editor reveals signs of a PDF (PDF signature). Renaming the file extension to PDF and then opening it reveals the flag.

### Flag(s)

- `OWEEK{h1d1n9_1n_pla1n_s1gh7}`

</details>
