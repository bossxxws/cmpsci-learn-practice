class Sokoban:
    def __init__(self, board):
        self.oriboard = board
        self.fixboard = [row[:] for row in self.oriboard]
        self.oriplayer_pos = self.findori()
        self.player_pos = self.find_player_pos()
        self.num_steps = 0
        self.move_history = []  # 移动历史记录的列表
        move = ([row[:] for row in self.fixboard], self.player_pos)
        self.move_history.append(move)
        self.i = len(board)
        self.j = len(board[0])

    def findori(self):
        for i in range(len(self.fixboard)):
            for j in range(len(self.fixboard[i])):
                if self.fixboard[i][j] == "P":
                    return i, j

    def find_player_pos(self):
        for i in range(len(self.fixboard)):
            for j in range(len(self.fixboard[i])):
                if self.fixboard[i][j] == "P":
                    return i, j

    def move(self, direction):
        # 记录移动到历史记录
      
        new_i, new_j = self.player_pos[0], self.player_pos[1]

        if direction == "w":
            new_i -= 1
            if new_i<0:
                new_i = self.i -1
        elif direction == "s":
            new_i += 1
            if new_i>self.i-1:
                new_i = 0
        elif direction == "a":
            new_j -= 1
            if new_j <0:
                new_j = self.j-1
        elif direction == "d":
            new_j += 1
            if new_j >self.j-1:
                new_j = 0

        if self.fixboard[new_i][new_j] in ["*", "o"]:
            return  # 不能移动到墙壁

        if self.fixboard[new_i][new_j] == "#":
            new_box_i, new_box_j = new_i, new_j

            if direction == "w":
                new_box_i -= 1
                if new_box_i<0:
                    new_box_i = self.i -1
            elif direction == "s":
                new_box_i += 1
                if new_box_i>self.i:
                    new_box_i = 0
            elif direction == "a":
                new_box_j -= 1
                if new_box_j <0:
                    new_box_j = self.j-1
            elif direction == "d":
                new_box_j += 1
                if new_box_j >self.j-1:
                    new_box_j = 0

            if self.fixboard[new_box_i][new_box_j] in ["*", "#"]:
                return  # 不能推动箱子到墙壁或其他箱子
            elif self.fixboard[new_box_i][new_box_j] == "o":
                self.fixboard[new_box_i][new_box_j] = " "
                self.fixboard[self.player_pos[0]][self.player_pos[1]] = " "
                self.fixboard[new_i][new_j] = "P"
                self.player_pos = new_i, new_j
                self.num_steps += 1
                move = ([row[:] for row in self.fixboard], self.player_pos)
                self.move_history.append(move)
                return

            self.fixboard[new_box_i][new_box_j] = "#"

        self.fixboard[self.player_pos[0]][self.player_pos[1]] = " "
        self.fixboard[new_i][new_j] = "P"
        self.player_pos = new_i, new_j
        self.num_steps += 1

        # 记录移动到历史记录
        if(new_i != self.move_history[-1][1][0] or new_j != self.move_history[-1][1][1] ):
            move = ([row[:] for row in self.fixboard], self.player_pos)
            self.move_history.append(move)

    def undo(self):
        if len(self.move_history) <2:
            return  # 没有历史记录可撤销

        # 获取上一个历史记录
        prev_board, prev_player_pos = self.move_history[-2]

        self.fixboard = prev_board
        self.player_pos = prev_player_pos
        self.num_steps -= 1
        self.move_history.pop(-1)
    def restart(self):
        self.fixboard = [row[:] for row in self.oriboard]
        self.player_pos = self.findori()
        self.num_steps = 0

    def is_complete(self):
        for row in self.fixboard:
            if "o" in row:
                return False
        return True

    def steps(self):
        return self.num_steps

    def __str__(self):
        rows = [' '.join(row) for row in self.fixboard]
        return '\n'.join(rows)

board = [
    ['*', '*', ' ', '*', '*'],
    ['*', ' ', ' ', ' ', '*'],
    ['*', ' ', ' ', ' ', '*'],
    [' ', '#', 'P', ' ', ' '],
    ['*', ' ', ' ', ' ', '*'],
    ['*', '*', ' ', '*', '*'],
]
game = Sokoban(board)

for _ in range(6):
    game.move("s")
print(game)

