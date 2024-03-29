import copy
class Sokoban:
    def __init__(self, board):
        self.__board=board
        self.__restart=copy.deepcopy(board)
        self.__record=[]
    def find_player(self):
        self.row=len(self.__board)
        self.col=len(self.__board[0])
        for i in range(self.row):
            for j in range(self.col):
                if self.__board[i][j]=='P':
                    return (i, j)
    def is_complete(self):
        for i in self.__board:
            if 'o' in i:
                return False
        return True
    def steps(self):
        return len(self.__record)
    def restart(self):
        self.__board=copy.deepcopy(self.__restart)
        self.__record=[]
    def undo(self):
        if self.__record!=[]:
            self.__record.pop(-1)
            if self.__record==[]:
                self.__board=copy.deepcopy(self.__restart)
            else:
                self.__board=copy.deepcopy(self.__record[-1])
        else:
            self.__board=copy.deepcopy(self.__restart)
    def move(self,direction):
        r=self.find_player()[0]
        c=self.find_player()[1]
        if direction=='w':
            if r==0:
                if self.__board[self.row-1][c]==' ':
                    self.__board[r][c],self.__board[self.row-1][c]=' ','P'
                elif self.__board[self.row-1][c]=='#':
                    if self.__board[self.row-2][c]==' ':
                        self.__board[r][c],self.__board[self.row-1][c],self.__board[self.row-2][c]=' ','P','#'
                    elif self.__board[self.row-2][c]=='o':
                        self.__board[r][c],self.__board[self.row-1][c],self.__board[self.row-2][c]=' ','P',' '
                    elif self.__board[self.row-2][c]=='*':
                        pass
            else:
                if self.__board[r-1][c]==' ':
                    self.__board[r][c],self.__board[r-1][c]=' ','P'
                elif self.__board[r-1][c]=='o' or self.__board[r-1][c]=='*':
                    pass
                elif self.__board[r-1][c]=='#':
                    if r==1:
                        if self.__board[self.row-1][c]==' ':
                            self.__board[r][c],self.__board[r-1][c],self.__board[self.row-1][c]=' ','P','#'
                        elif self.__board[self.row-1][c]=='o':
                            self.__board[r][c],self.__board[r-1][c],self.__board[self.row-1][c]=' ','P',' '
                        elif self.__board[self.row-1][c]=='*':
                            pass

                    else:
                        if self.__board[r-2][c]==' ':
                            self.__board[r][c],self.__board[r-1][c],self.__board[r-2][c]=' ','P','#'
                        elif self.__board[r-2][c]=='o':
                            self.__board[r][c],self.__board[r-1][c],self.__board[r-2][c]=' ','P',' '
                        elif self.__board[r-2][c]=='*':
                            pass
        elif direction=='s':
            if r==self.row-1:
                if self.__board[0][c]==' ':
                    self.__board[r][c],self.__board[0][c]=' ','P'
                elif self.__board[0][c]=='#':
                    if self.__board[1][c]==' ':
                        self.__board[r][c],self.__board[0][c],self.__board[1][c]=' ','P','#'
                    elif self.__board[1][c]=='o':
                        self.__board[r][c],self.__board[0][c],self.__board[1][c]=' ','P',' '
                    elif self.__board[1][c]=='*':
                        pass
            else:
                if self.__board[r+1][c]==' ':
                    self.__board[r][c],self.__board[r+1][c]=' ','P'
                elif self.__board[r+1][c]=='o' or self.__board[r+1][c]=='*':
                    pass
                elif self.__board[r+1][c]=='#':
                    if r==self.row-2:
                        if self.__board[0][c]==' ':
                            self.__board[r][c],self.__board[r+1][c],self.__board[0][c]=' ','P','#'
                        elif self.__board[0][c]=='o':
                            self.__board[r][c],self.__board[r+1][c],self.__board[0][c]=' ','P',' '
                        elif self.__board[0][c]=='*':
                            pass

                    else:
                        if self.__board[r+2][c]==' ':
                            self.__board[r][c],self.__board[r+1][c],self.__board[r+2][c]=' ','P','#'
                        elif self.__board[r+2][c]=='o':
                            self.__board[r][c],self.__board[r+1][c],self.__board[r+2][c]=' ','P',' '
                        elif self.__board[r+2][c]=='*':
                            pass
        elif direction=='a':
            if c==0:
                if self.__board[r][self.col-1]==' ':
                    self.__board[r][c],self.__board[r][self.col-1]=' ','P'
                elif self.__board[r][self.col-1]=='#':
                    if self.__board[r][self.col-2]==' ':
                        self.__board[r][c],self.__board[r][self.col-1],self.__board[r][self.col-2]=' ','P','#'
                    elif self.__board[r][self.col-2]=='o':
                        self.__board[r][c],self.__board[r][self.col-1],self.__board[r][self.col-2]=' ','P',' '
            else:
                if self.__board[r][c-1]==' ':
                    self.__board[r][c],self.__board[r][c-1]=' ','P'
                elif self.__board[r][c-1]=='#':
                    if c==1:
                        if self.__board[r][self.col-1]==' ':
                            self.__board[r][c],self.__board[r][c-1],self.__board[r][self.col-1]=' ','P','#'
                        elif self.__board[r][self.col-1]=='o':
                            self.__board[r][c],self.__board[r][c-1],self.__board[r][self.col-1]=' ','P',' '
                    else:
                        if self.__board[r][c-2]==' ':
                            self.__board[r][c],self.__board[r][c-1],self.__board[r][c-2]=' ','P','#'
                        elif self.__board[r][c-2]=='o':
                            self.__board[r][c],self.__board[r][c-1],self.__board[r][c-2]=' ','P',' '
        elif direction=='d':
            if c==self.col-1:
                if self.__board[r][0]==' ':
                    self.__board[r][c],self.__board[r][0]=' ','P'
                elif self.__board[r][0]=='#':
                    if self.__board[r][1]==' ':
                        self.__board[r][c],self.__board[r][0],self.__board[r][1]=' ','P','#'
                    elif self.__board[r][1]=='o':
                        self.__board[r][c],self.__board[r][0],self.__board[r][1]=' ','P',' '
            else:
                if self.__board[r][c+1]==' ':
                    self.__board[r][c],self.__board[r][c+1]=' ','P'
                elif self.__board[r][c+1]=='#':
                    if c==self.col-2:
                        if self.__board[r][0]==' ':
                            self.__board[r][c],self.__board[r][c+1],self.__board[r][0]=' ','P','#'
                        elif self.__board[r][0]=='o':
                            self.__board[r][c],self.__board[r][c+1],self.__board[r][0]=' ','P',' '
                    else:
                        if self.__board[r][c+2]==' ':
                            self.__board[r][c],self.__board[r][c+1],self.__board[r][c+2]=' ','P','#'
                        elif self.__board[r][c+2]=='o':
                            self.__board[r][c],self.__board[r][c+1],self.__board[r][c+2]=' ','P',' '
        if self.__record==[]:
            self.__record=copy.deepcopy(self.__record+[self.__board])

        elif self.__board!=self.__record[-1]:
            self.__record=copy.deepcopy(self.__record+[self.__board])
    def __str__(self):
        lst=[]
        for i in self.__board:
            lst+=[' '.join(i)]
        return '\n'.join(lst)

