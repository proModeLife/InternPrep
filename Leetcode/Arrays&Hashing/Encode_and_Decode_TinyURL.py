class Codec:
    def __init__(self, encMap=None, decMap=None, nums=0):
        if encMap is None:
            encMap = {}
        if decMap is None:
            decMap = {}
        self.nums = nums
        self.encMap = encMap
        self.decMap = decMap

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL."""
        if longUrl not in self.encMap:
            shortUrl = "http://tinyurl.com/" + str(self.nums)
            self.encMap[longUrl] = shortUrl
            self.decMap[shortUrl] = longUrl
            self.nums += 1
        return self.encMap[longUrl]

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL."""
        return self.decMap[shortUrl]