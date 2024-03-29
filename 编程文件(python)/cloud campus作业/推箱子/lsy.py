import copy
class Sokoban:
    def __init__(self,board):
        self.board = board
        self.step = 0
        self.history = []
    def __str__(self):
        show = ''
        num = 0
        for i in self.board:
            num += 1
            for j in i:
                show += j + ' '
            show += '\n'
        return show[:-2]
    def find_player(self):
        for x in range(self.board_x()):
            for y in range(self.board_x()):
                if self.board[x][y] == 'P':
                    return (x,y)
    def is_complete(self):
        for i in self.board:
            for j in i :
                if j == 'o':
                    return False
        return True
    def steps(self):
        return self.step
    def restart(self):
        if len(self.history) == 0:
            return
        self.board = self.history[0]
        self.step = 0
        self.history.clear()
    def undo(self):
        if self.step == 0:
            return
        self.board = self.history[-1]
        self.step -= 1
        self.history.pop()

    def move(self,direction):
        x = self.find_player()[0]
        y = self.find_player()[1]
        ans = self.check(direction)
        if direction == 'w':
            if ans < 0:
                return
            else:
                self.step += 1
                self.history.append(copy.deepcopy(self.board))
                self.board[x][y] = ' '
                if ans == 0:
                    self.board[(x-1)%self.board_x()][y] = 'P'
                else:
                    if self.board[(x-2)%self.board_x()][y] == 'o':
                        self.board[(x-2)%self.board_x()][y] = ' '
                        self.board[(x-1)%self.board_x()][y] = 'P'
                    else:
                        self.board[(x-2)%self.board_x()][y] = '#'
                        self.board[(x-1)%self.board_x()][y] = 'P'
        elif direction == 'a':
            if ans < 0:
                return
            else:
                self.step += 1
                self.history.append(copy.deepcopy(self.board))

                self.board[x][y] = ' '
                if ans == 0:
                    self.board[x][(y - 1)%self.board_y()] = 'P'
                else:
                    if self.board[x][(y - 2)%self.board_y()] == 'o':
                        self.board[x][(y - 2)%self.board_y()] = ' '
                        self.board[x][(y - 1)%self.board_y()] = 'P'
                    else:
                        self.board[x][(y - 2)%self.board_y()] = '#'
                        self.board[x][(y - 1)%self.board_y()] = 'P'
        elif direction == 's':
            if ans < 0:
                return
            else:
                self.step += 1
                self.history.append(copy.deepcopy(self.board))

                self.board[x][y] = ' '
                if ans == 0:
                    self.board[(x + 1)%self.board_x()][y] = 'P'
                else:
                    if self.board[(x + 2)%self.board_x()][y] == 'o':
                        self.board[(x + 2)%self.board_x()][y] = ' '
                        self.board[(x + 1)%self.board_x()][y] = 'P'
                    else:
                        self.board[(x + 2)%self.board_x()][y] = '#'
                        self.board[(x + 1)%self.board_x()][y] = 'P'
        elif direction == 'd':
            if ans < 0:
                return
            else:
                self.step += 1
                self.history.append(copy.deepcopy(self.board))

                self.board[x][y] = ' '
                if ans == 0:
                    self.board[x][(y + 1)%self.board_y()] = 'P'
                else:
                    if self.board[x][(y + 2)%self.board_y()] == 'o':
                        self.board[x][(y + 2)%self.board_y()] = ' '
                        self.board[x][(y + 1)%self.board_y()] = 'P'
                    else:
                        self.board[x][(y + 2)%self.board_y()] = '#'
                        self.board[x][(y + 1)%self.board_y()] = 'P'
    def check(self,direction):
        x = self.find_player()[0]
        y = self.find_player()[1]
        if direction not in "wasd":
            return -1
        if direction == 'w':
            if self.board[(x-1)%self.board_x()][y] != '#':
                if self.board[(x-1)%self.board_x()][y] not in '*o':
                    return 0
                else:
                    return -1

            else:
                if self.board[(x-2)%self.board_x()][y] not in '*':
                    return 1
                else:
                    return -1
        elif direction == 'a':

            if self.board[x][(y - 1)%self.board_y()] != '#':
                if self.board[x][(y - 1)%self.board_y()] not in '*o':
                    return 0
                else:
                    return -1

            else:
                if self.board[x][(y - 2)%self.board_y()] not in '*':
                    return 1
                else:
                    return -1
        elif direction == 's':

            if self.board[(x + 1)%self.board_x()][y] != '#':
                if self.board[(x + 1)%self.board_x()][y] not in '*o':
                    return 0
                else:
                    return -1

            else:
                if self.board[(x + 2)%self.board_x()][y] not in '*':
                    return 1
                else:
                    return -1
        elif direction == 'd':

            if self.board[x][(y + 1)%self.board_y()] != '#':
                if self.board[x][(y + 1)%self.board_y()] not in '*o':
                    return 0
                else:
                    return -1
            else:
                if self.board[x][(y + 2)%self.board_y()] not in '*':
                    return 1
                else:
                    return -1
    def board_x(self):
        return len(self.board)
    def board_y(self):
        return len(self.board[0])


















