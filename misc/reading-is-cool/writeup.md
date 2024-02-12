# Writeup for `reading is cool`

| author | category | value |
|--------|----------|-------|
| mtnull |   misc   |  100  |

`0x41D07cE76470F75A5d3b945B755FfD82D3CC738c`

While investigating the SCONES coin contract, I stumbled across this mysterious address. What does it mean?


| cost |                                                                content                                                                 |
|------|----------------------------------------------------------------------------------------------------------------------------------------|
|  0   | Try using an [Ethereum blockchain explorer](https://sepolia.etherscan.io) to investigate the contract on the Ethereum Sepolia Testnet. |
|  0   | Can you read any public values belonging to the contract?                                                                              |

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Reading a public string from a deployed Ethereum contract by using a blockchain explorer.

### Walkthrough

1. Go to [https://sepolia.etherscan.io](https://sepolia.etherscan.io).
2. Input the contract address provided (`0x41D07cE76470F75A5d3b945B755FfD82D3CC738c`) in the testnet explorer search box.
3. You can now read the contract [source code](https://sepolia.etherscan.io/address/0x41D07cE76470F75A5d3b945B755FfD82D3CC738c#code) containing the flag for this challenge.

### Flag(s)

- `OWEEK{sc0n3s_c01n_t0_th3_m0on!}`

</details>
