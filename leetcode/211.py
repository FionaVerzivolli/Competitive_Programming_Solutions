class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEndOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.isEndOfWord = True

    def search(self, word: str) -> bool:
        return self._searchInNode(word, 0, self.root)

    def _searchInNode(self, word: str, index: int, node: TrieNode) -> bool:
        if index == len(word):
            return node.isEndOfWord
        
        char = word[index]
        if char == '.':
            for child in node.children.values():
                if self._searchInNode(word, index + 1, child):
                    return True
        elif char in node.children:
            return self._searchInNode(word, index + 1, node.children[char])
        
        return False
