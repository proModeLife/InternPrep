class TrieNode:
    def __init__(self):
        self.nodes = [None] * 26
        self.end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        if not word:
            return
        curr = self.root
        for i in range(len(word)):
            idx = ord(word[i]) - ord('a')
            if not curr.nodes[idx]:
                curr.nodes[idx] = TrieNode()
            curr = curr.nodes[idx]
        curr.end = True

    def search(self, word: str) -> bool:
        curr = self.root
        for i in range(len(word)):
            idx = ord(word[i]) - ord('a')
            if not curr.nodes[idx]:
                return False
            curr = curr.nodes[idx]
        return curr.end

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for i in range(len(prefix)):
            idx = ord(prefix[i]) - ord('a')
            if not curr.nodes[idx]:
                return False
            curr = curr.nodes[idx]
        return True