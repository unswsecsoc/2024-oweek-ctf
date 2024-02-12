# Writeup for `discord`

|   author  | category | value |
|-----------|----------|-------|
| larrabyte |   misc   |  100  |

Check out our [Discord](https://secso.cc/discord)! One of the bots might just have a flag...

| cost |                    content                    |
|------|-----------------------------------------------|
|  0   | Check each bot's profile picture.             |
|  0   | You'll need to open Discord in a web browser. |

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Using `Inspect Element` to extract the full profile picture of a bot to scan.

### Walkthrough

One of the bots appears to have a QR code, but trying to scan it yields no useful results since Discord renders profile pictures with a circular overlay. The full image can be extracted using `Inspect Element` and selecting the picture, which reveals the `<img>` tag and the actual link to the full profile picture, which then then be scanned.

### Flag(s)

- `OWEEK{h3y_7h15_d15c0rd_53rv3r'5_pr377y_k3wl}`

</details>
