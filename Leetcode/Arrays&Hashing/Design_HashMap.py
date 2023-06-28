class MyHashMap:

    def __init__(self):
        self.hm = [[]]

    def put(self, key: int, value: int) -> None:
        for i in self.hm:
            if i and i[0] == key:
                i[1] = value
                return
        self.hm.append([key, value])

    def get(self, key: int) -> int:
        for i in self.hm:
            if i and i[0] == key:
                return i[1]
        return -1

    def remove(self, key: int) -> None:
        for i in range(len(self.hm)):
            if self.hm[i] and self.hm[i][0] == key:
                self.hm.pop(i)
                return