# Writeup for `jwt`

| author |  category | value |
|--------|-----------|-------|
| mtnull | reversing |  100  |

`eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJmbGFnIjoiT1dFRUt7bjN2M3Jfc2g0cjNfeTB1cl90MGszbjV9In0.97K5QMRXbMOI5pxYjDs5EiI1yLmOJ5AP0NTsONs3Plc`

All this talk about JWTs in the [Discord](https://secso.cc/discord) has got me excited about using them and I've finally made one! Since these tokens are secure, I'm confident no one can possibly steal the secret inside.


| cost |                                                                                                       content                                                                                                       |
|------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|  0   | In simple terms, a JSON Web Token (JWT) is a secure way of allowing a device to prove something to another device. However, sharing a JWT you own will potentially allow someone else to pretend that they are you! |
|  0   | A JWT decoder might help you with this challenge.                                                                                                                                                                   |

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Decoding a JWT.

### Walkthrough

1. Paste the JWT provided by the challenge into a [JWT decoder](https://www.jstoolset.com/jwt).
2. JWTs are never meant to be used for encryption. In fact, JWTs are simply encoded values, and while they may look like gibbersh, all tokens follow the same format of providing a header, payload and signature. In the case of this challenge, the payload will contain the flag. 

### Flag(s)

- `OWEEK{n3v3r_sh4r3_y0ur_t0k3n5}`

</details>
