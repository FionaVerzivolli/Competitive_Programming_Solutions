class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        # step 1: find the prime numbers and make a list
        # distance between first and last prime number in array??
        
        
        list_of_primes =  []
        
        for i in range(len(nums)):
            if self.is_prime(nums[i]):
                list_of_primes.append(i)
                
        return max(list_of_primes) - min(list_of_primes)
            
    def is_prime(self, num: int) -> bool:
        if num <= 1:
            return False
        for i in range(2, int(num**0.5) + 1):
            if num % i == 0:
                return False
        return True
