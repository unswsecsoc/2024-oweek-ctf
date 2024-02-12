# Writeup for `riot rand`

| author | category | value |
|--------|----------|-------|
| mtnull |  crypto  |  100  |

I managed to break into the Riot Games account management system (in Minecraft) and I want some free RP. Can you crack the Riot ID algorithm being used?

| cost |                                               content                                               |
|------|-----------------------------------------------------------------------------------------------------|
|  0   | No code needs to be written or read for this challenge. Try figuring out the ID generation pattern. |
|  0   | What happens if you alter the length of a username given? Does the ID change?                       |
|  0   | Is the ID generated influenced by the number of users that currently exist?                         |

## Files
- [src/challenge.c](src/challenge.c): Source code for this challenge.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Exploit poorly implemented ID generation algorithm that uses `rand()`.

### Walkthrough

1. As this challenge is black boxed, the only way to solve it would be by observing how the ID changes when different usernames are given.
2. We can first test if the algorithm is deterministic, that is, it provides the same output for a specific input.
3. Sign up by using the username `a`, which should return `423337766`, although this can vary depending on what OS you're running on because the implementation of `rand()` is not defined by the C standard.
4. Restart the challenge and input the same username `a`. As the same ID `423337766` is returned, we now know the algorithm is deterministic and predictable.
5. Inputting usernames with only length `1` will allow us to produce the following sequence: `423337766, 423337835, 423337904, ...`
6. Observing the sequence above, we can easily determine that the IDs are increasing by `69`.
7. However, trying a username that is not of length `1` will produce a different sequence, which means the ID is also influenced by the length of a username.
8. Since the username of the adminstrator `rand` is of length `4`, we can try inputting usernames of length `4` instead, which will produce the following sequence: `423337769, 423337838, 423337907, ...`
9. Once again, the above sequence increases by `69`. In order to get the ID for `rand`, all we need to do is subtract `69` from the first ID `423337769`, which yields `423337700`.
10. Logging in with `423337700` (this ID can be different depending on your OS, but the steps to get the ID are the exact same) will give the flag for this challenge.

### Flag(s)

- `OWEEK{psu3d0_numb3r5_ar3_n0t_5ecur3}`

</details>
