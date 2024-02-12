# Writeup for `cookie monster`

| author | category | value |
|--------|----------|-------|
| mtnull |   web    |  100  |

Cookie Monster from Sesame Street has created a login page that is apparently secure. Can you try to crack into the admin account to prove Cookie Monster wrong? 

When attempting to log in, use `admin` for the username and `admin` for the password.


| cost |                                                                 content                                                                  |
|------|------------------------------------------------------------------------------------------------------------------------------------------|
|  0   | How does this site distinguish between an administrator and a normal user?                                                               |
|  0   | Cookies are pieces of data stored on your browser, commonly used to store sensitive information such as session tokens.                  |
|  0   | Try right-clicking on the site, then click `Inspect`. After this, locate a storage inspector to look at the cookies stored on this site. |

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Changing client-side cookies to bypass login checks.

### Walkthrough

1. Open devtools by right-clicking on the site and clicking `Inspect`.
2. Go to storage inspector and find the `isAdmin` cookie.
3. Change `false` to `true`.
4. After logging in again, the server will think that you are indeed an admin, and the flag for this challenge will be returned.
    
### Flag(s)

- `OWEEK{0m_n0m_n0m_c00k135_ta5t3_n1c3}`

</details>
