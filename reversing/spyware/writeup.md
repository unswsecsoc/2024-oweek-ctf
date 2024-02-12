# Writeup for `spyware`

| author |  category | value |
|--------|-----------|-------|
| mtnull | reversing |  100  |

I downloaded this tool that supposedly generates free RP to your League of Legends account, but I can't get the tool working. Can you investigate?

| cost |                                                                 content                                                                 |
|------|-----------------------------------------------------------------------------------------------------------------------------------------|
|  0   | Try using a malware analysis tool (you can find many of these online) to scan the suspicious file for clues in a sandboxed environment. |

## Files

- [spyware.exe](spyware.exe): Fake spyware file that contains a flag.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Inspect a suspicious file and observe its behaviour.

### Walkthrough

1. Upload the file to a malware analysis tool such as [VirusTotal](https://www.virustotal.com/gui/home/upload).
2. Go to the behaviour tab, where an automated scan of the executable will be provided.
3. As the executable constantly makes `GET` requests to Pastebin, this is detected by the automated scan, and a link is provided containing the flag for this challenge.

### Flag(s)

- `OWEEK{5n00p1ng_th3_5n00p3r}`

</details>
