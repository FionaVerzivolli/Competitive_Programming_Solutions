class Codec:

    def __init__(self):
        self.stored = ""


    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        # https:// [0:7]
        key = len(longUrl)
        tiny_part = ""
        tiny_part += chr(ord(longUrl[8]) + key % 26)

        for i in range(7, len(longUrl), 2): # note that this will be key - 7 units long
            tiny_part += chr(ord(longUrl[i]) % key)
        self.stored = longUrl

        return tiny_part

        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.stored

        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
