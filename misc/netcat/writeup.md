# Writeup for `🌐😸`

| author | category | value |
|--------|----------|-------|
| mtnull |   misc   |   50  |

Meow! `netcat` is a tool used by cool cybercats like me in order to connect to other computers on the Internet! It's used to connect to some CTF challenges, so I'm going to teach you how to use it.

Don't worry if you find this daunting though, not many challenges in this CTF require `netcat` (in fact, the ones that require it are hidden until you complete this challenge). If you're stuck, feel free to try some other challenges or reach out to us on [Discord](https://secso.cc/discord), we'd love to help out.

See below for instructions.

<details>
<summary>Windows</summary>
The route we're going to take here is to install Windows Subsystem for Linux (WSL), which lets you open Linux terminals on Windows. If you're running Windows 10, <b>it is highly recommended</b> that you download <a href="https://aka.ms/terminal">Windows Terminal</a> as it offers a significantly better terminal experience compared to the traditional Command Prompt window.<br><br>
1. Open Windows Terminal (this can be done by searching for 'terminal' in the Start Menu).<br>
2. Type <code>wsl --install</code> and press Enter. Wait for it to complete.<br>
3. Reboot your computer.<br>
4. Re-open Windows Terminal. It should automatically open up WSL (this can be changed inside WT settings if you wish) and prompt you for initial setup. If WSL didn't open, click the arrow next to the first tab and open a new Ubuntu tab.<br>
5. Follow the prompts. You will eventually land at some text that reads something like <code>user@DESKTOP-XYZ:~$</code>.<br><br>

At this point, you've successfully installed WSL onto your system. Congratulations! If you're majoring in Computer Science, you will be getting very familiar with the Linux terminal as you progress.

For now though, open the Linux instructions and follow them to finish off the challenge.
</details>

<details>
<summary>macOS and Linux</summary>
This is super easy!<br><br>
1. Open an application called Terminal (if you came here from the Windows instructions, open a WSL tab). You can do this on macOS via Spotlight Search (Cmd+Space) or opening Finder and going to the <code>Applications</code> folder. If you're running Linux, I think you have this one figured out.<br>
2. Type <code>nc ctf.secso.cc 1001</code> and press Enter.<br>
3. Profit! You're now talking to another computer over the Internet.
</details><br>


## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Getting familiar with using netcat.

### Walkthrough

1. Open a terminal.
2. Connect to `ctf.secso.cc 1001` by typing `nc ctf.secso.cc 1001`.
3. Type "meow" in your terminal and click enter to get the flag for this challenge.

### Flag(s)

- `OWEEK{purr_n3t_cat5_ar3_c0ol}`

</details>
