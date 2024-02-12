# Writeup for `yellow pages`

|   author  | category | value |
|-----------|----------|-------|
| larrabyte |  recon   |  100  |

This URL is a little special...

| cost |                                               content                                               |
|------|-----------------------------------------------------------------------------------------------------|
|  0   | The flag isn't on the website itself.                                                               |
|  0   | How do computers resolve websites like `https://ctf.secso.cc` into IP addresses like `192.168.0.1`? |

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Checking DNS TXT records for `ctf.secso.cc`.

### Walkthrough

The main job of the Domain Name System (DNS) is to translate domains such as `ctf.secso.cc` into IP addresses such as `192.168.0.1` using what are known as A (or AAAA for IPv6) records, as computers only understand the latter when communicating with one another. DNS however also supports storing arbitrary text in the form of TXT records, which are usually used for confirming ownership of a domain. In this case, this challenge's CTF flag was stored as a TXT record.

### Flag(s)

- `OWEEK{wh3n_w45_7h3_l457_71m3_y0u_4c7u4lly_u53d_y3ll0w_p4g3s?}`

</details>
