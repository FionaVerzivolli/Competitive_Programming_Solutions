class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(curr_str, open_count, close_count):
            if len(curr_str) == 2 * n:
                # If the current string has used all n pairs, add it to the result
                result.append(curr_str)
                return

            if open_count < n:
                # Add an opening parenthesis if we still have open brackets left
                backtrack(curr_str + "(", open_count + 1, close_count)
            
            if close_count < open_count:
                # Add a closing parenthesis if it won't unbalance the string
                backtrack(curr_str + ")", open_count, close_count + 1)

        result = []
        backtrack("", 0, 0)
        return result
