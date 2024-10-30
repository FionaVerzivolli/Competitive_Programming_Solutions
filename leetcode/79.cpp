class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        vis = []
        for i in range(len(board)):
            tmp = []
            for j in range(len(board[0])):
                tmp.append(0)
            vis.append(tmp)
        
        def valid_move(board: List[List[str]], yy: int, xx: int):
            if xx < 0 or xx >= len(board[0]):
                return False
            if yy < 0 or yy >= len(board):
                return False
            if vis[yy][xx] == 1:
                return False
            return True
        print(len(board))
        def dfs(yy, xx, board, vis, word, idx):
            if len(word) == idx:
                return True

            if (valid_move(board, yy + 1, xx) and board[yy + 1][xx] == word[idx]):
                vis[yy + 1][xx] = 1
                tmp = dfs(yy + 1, xx, board, vis, word, idx + 1)
                if tmp == True:
                    return True
                vis[yy + 1][xx] = 0
            if (valid_move(board, yy - 1, xx) and board[yy - 1][xx] == word[idx]):
                vis[yy - 1][xx] = 1
                tmp = dfs(yy - 1, xx, board, vis, word, idx + 1)
                if tmp == True:
                    return True
                vis[yy - 1][xx] = 0
            if (valid_move(board, yy, xx + 1) and board[yy][xx + 1] == word[idx]):
                vis[yy][xx + 1] = 1
                tmp = dfs(yy, xx + 1, board, vis, word, idx + 1)
                if tmp == True:
                    return True
                vis[yy][xx + 1] = 0
            if (valid_move(board, yy, xx - 1) and board[yy][xx - 1] == word[idx]):
                vis[yy][xx - 1] = 1
                tmp = dfs(yy, xx - 1, board, vis, word, idx + 1)
                if tmp == True:
                    return True
                vis[yy][xx - 1] = 0
            return False
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    vis[i][j] = 1
                    if dfs(i, j, board, vis, word, 1):
                        return True
                    vis[i][j] = 0
        return False
