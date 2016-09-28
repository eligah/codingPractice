class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        r,c=len(board),len(board[0])
        for row in range(r):
            for col in range(c):
                # check row
                if board[row][col]=='.':
                    continue
                if board[row][col] in board[row][col+1:]:
                    return False
                if board[row][col] in [board[i][col] for i in range(row+1,r)]:
                    return False
                for k in range(row//3*3,(row//3+1)*3):
                    for l in range(col//3*3,(col//3+1)*3):
                        if k==row and l==col:
                            continue
                        if board[row][col]==board[k][l]:
                            return False
        return True
