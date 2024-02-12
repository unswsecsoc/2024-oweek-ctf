# Writeup for `pinpoint precision`

|   author  |  category | value |
|-----------|-----------|-------|
| larrabyte | forensics |  100  |

I can't seem to remember where I took this photo. Think you could help?

**Note**: Your answer should be the address of where you think the photo was taken, you do not need to wrap your answer with `OWEEK{}`. For example, if you think the photo was taken at Kirribilli House, then supply `109 Kirribilli Ave, Kirribilli` as the flag.

| cost |                                     content                                     |
|------|---------------------------------------------------------------------------------|
|  0   | There's more to the image then just the picture itself.                         |
|  0   | Google Maps may be of use for converting latitudes and longitudes to addresses. |

## Files

- [image.jpeg](image.jpeg): An image.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Pasting the location metadata from the image file into Google Maps to get the address where the photo was taken at.

### Walkthrough

Photos are often made up of more than just the image itself - phones and digital cameras will almost always include additional metadata about the state of the camera at the time of shooting, time of shooting as well as potentially the location of the shot if the device supports GPS (among other things). In this case, the location metadata has been intentionally left in and can be extracted with tools such as `exiftool`. Once the latitude and longitude has been acquired, pasting it into Google Maps will return an address, which can be supplied in the specified format to retrieve the flag.

### Flag(s)

- `42 Pirrama Rd, Pyrmont`

</details>
