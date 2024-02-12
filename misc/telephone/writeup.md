# Writeup for `telephone`

|   author  | category | value |
|-----------|----------|-------|
| larrabyte |   misc   |  100  |

My old modem seems to have stopped working and just plays a bunch of tones on repeat.

| cost |                            content                             |
|------|----------------------------------------------------------------|
|  0   | Do any patterns exist in the audio (pitch, timing, amplitude)? |
|  0   | Are any sounds grouped in any meaningful way?                  |
|  0   | Can you assign a meaning to each sound?                        |

## Files

- [telephone.mp3](telephone.mp3): Modem tones.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Transcribing ASCII characters transmitted over telephone.

### Walkthrough

The tones in the audio file appear to be grouped into chunks of 8 and alternate between two states. This suggests some form of 8-bit encoding, most likely 8-bit ASCII. Assuming the low tones are 0 and the high tones are 1, transcribing them will yield a series of bits which can then be split and decoded according to an ASCII table (`man 7 ascii`) to yield the flag.

### Flag(s)

- `OWEEK{n0k1a_3310}`

</details>
