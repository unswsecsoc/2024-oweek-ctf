# Writeup for `green bubble`

| author |  category | value |
|--------|-----------|-------|
| mtnull | reversing |  100  |

I randomly stumbled upon this APK file that contains a hidden message. Can you find it?

| cost |                                                                           content                                                                           |
|------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
|  0   | An APK is a package format that contains all the code and assets of an app on Android devices.                                                              |
|  0   | Since APK files are a type of archive format, it is possible to inspect the contents of an APK with a file archiver such as [7-Zip](https://www.7-zip.org). |

## Files

- [green-bubble.apk](green-bubble.apk): APK file for this challenge.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Reading a metadata tag inside a AndroidManifest.xml binary.

### Walkthrough

1. Extract the APK with a file archiver such as 7-Zip.
2. Open AndroidManifest.xml in a text editor or `cat` the binary file, inside will be the flag for this challenge.
3. Since AndroidManifest.xml is a binary file, you may not see the flag if you try to `grep` for it on Linux, for example.
4. If this occurs, using the `apktool d green-bubble.apk` command with [apktool](https://apktool.org) will decode the binary into a readable file.
5. After decoding the APK, you can then run `cat AndroidManifest.xml | grep "OWEEK"` to get the flag.

### Flag(s)

- `OWEEK{n3v3r_tru5t_gr33n_bubbl3s}`

</details>
