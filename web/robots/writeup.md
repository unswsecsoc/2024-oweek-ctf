# Writeup for `robots`

| author | category | value |
|--------|----------|-------|
| mtnull |   web    |  100  |

AI is getting scary. Did you know that OpenAI has a web crawler that scrapes websites to improve future GPT models?

In order to prevent OpenAI from crawling my site, I have locked it down completely with a captcha that no one can solve and by enabling a secret setting!


| cost |                                                         content                                                         |
|------|-------------------------------------------------------------------------------------------------------------------------|
|  0   | Websites can use a `robots.txt` file to outline the permissions web crawlers have and what directories they can access. |

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Analysing a robots.txt file.

### Walkthrough

1. Go to the `robots.txt` file by adding `/robots.txt` to the site domain name. For example, this would be `localhost:8080/robots.txt` if you were hosting this challenge locally to port `8080`.
2. Listed in the `robots.txt` file will be `/no_one_will_ever_access_this_flag.txt`, which contains the flag for this challenge.

### Flag(s)

- `OWEEK{w3b_cr4wl3r5_alw4y5_f1nd_4_way}`

</details>
