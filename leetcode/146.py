class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:
    # create a linked list
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}
        self.left, self.right = Node(0,0), Node(0,0)
        # left = LRU, right = MRU
        self.left.next = self.right
        self.right.prev = self.left

    def get(self, key: int) -> int:
        if key in self.cache:
            accessed = self.cache[key] # MRU node
            self.remove(accessed)
            self.insert(accessed) # update position
            return self.cache[key].val
        return -1
    
    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev     
    
    def insert(self, node):
        prev = self.right.prev
        nxt = self.right
        prev.next = nxt.prev = node
        node.next, node.prev = nxt, prev


    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            accessed = self.cache[key]
            self.remove(accessed)
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache) > self.cap:
            removed = self.left.next.key
            self.cache.pop(removed) # remove from dict
            self.remove(self.left.next)



        
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
