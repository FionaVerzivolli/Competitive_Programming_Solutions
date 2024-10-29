import random
class RandomizedSet:

    def __init__(self):
        self.indices = []
        self.randomDict = {}


    def insert(self, val: int) -> bool:
        if val in self.randomDict:
            return False
        else:
            self.randomDict[val] = val
            self.indices.append(val)
        return True
        
    def remove(self, val: int) -> bool:
        if val not in self.randomDict:
            return False
        else:
            self.randomDict.pop(val)
            self.indices.remove(val)
            return True

    def getRandom(self) -> int:
        size = len(self.indices)
        random_value = random.randint(0, size - 1)
        return self.indices[random_value]



# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
