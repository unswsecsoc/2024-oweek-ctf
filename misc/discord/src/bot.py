import discord
import asyncio

async def main():
    async with discord.Client(intents=discord.Intents.none()) as client:
        await client.start("REDACTED")

if __name__ == "__main__":
    asyncio.run(main())
