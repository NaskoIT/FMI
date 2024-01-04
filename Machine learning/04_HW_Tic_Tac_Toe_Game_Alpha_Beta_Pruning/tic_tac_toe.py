import time


class Game:
    def __init__(self):
        self.result = None
        self.player_turn = None
        self.current_state = None
        self.board_size = 3
        self.computer_mark = '0'
        self.player_mark = 'X'
        self.initialize_game()

    def initialize_game(self):
        self.current_state = [['.', '.', '.'],
                              ['.', '.', '.'],
                              ['.', '.', '.']]

        # Player X always plays first
        self.player_turn = 'X'

    def draw_board(self):
        for i in range(0, self.board_size):
            for j in range(0, self.board_size):
                print('{}|'.format(self.current_state[i][j]), end=" ")
            print()
        print()

    def is_valid(self, px, py):
        if px < 0 or px >= self.board_size or py < 0 or py >= self.board_size:
            return False
        elif self.current_state[px][py] != '.':
            return False
        else:
            return True

    def is_end(self):
        # Vertical win
        for i in range(0, self.board_size):
            if (self.current_state[0][i] != '.' and
                    self.current_state[0][i] == self.current_state[1][i] and
                    self.current_state[1][i] == self.current_state[2][i]):
                return self.current_state[0][i]

        # Horizontal win
        for i in range(0, self.board_size):
            if self.current_state[i] == ['X', 'X', 'X']:
                return 'X'
            elif self.current_state[i] == ['O', 'O', 'O']:
                return 'O'

        # Main diagonal win
        if (self.current_state[0][0] != '.' and
                self.current_state[0][0] == self.current_state[1][1] and
                self.current_state[0][0] == self.current_state[2][2]):
            return self.current_state[0][0]

        # Second diagonal win
        if (self.current_state[0][2] != '.' and
                self.current_state[0][2] == self.current_state[1][1] and
                self.current_state[0][2] == self.current_state[2][0]):
            return self.current_state[0][2]

        # Is the whole board full?
        for i in range(0, self.board_size):
            for j in range(0, self.board_size):
                # There's an empty field, we continue the game
                if self.current_state[i][j] == '.':
                    return None

        # It's a tie!
        return '.'

    # Player 'O' is max, in this case AI
    def max(self):

        # Possible values for maxv are:
        # -1 - loss
        # 0  - a tie
        # 1  - win

        # We're initially setting it to -2 as worse than the worst case:
        maxv = -2

        px = None
        py = None

        result = self.is_end()

        # If the game came to an end, the function needs to return
        # the evaluation function of the end. That can be:
        # -1 - loss
        # 0  - a tie
        # 1  - win
        if result == 'X':
            return -1, 0, 0
        elif result == 'O':
            return 1, 0, 0
        elif result == '.':
            return 0, 0, 0

        for i in range(0, self.board_size):
            for j in range(0, self.board_size):
                if self.current_state[i][j] == '.':
                    # On the empty field player 'O' makes a move and calls Min
                    # That's one branch of the game tree.
                    self.current_state[i][j] = 'O'
                    (m, min_i, min_j) = self.min()
                    # Fixing the maxv value if needed
                    if m > maxv:
                        maxv = m
                        px = i
                        py = j
                    # Setting back the field to empty
                    self.current_state[i][j] = '.'
        return maxv, px, py

    # Player 'X' is min, in this case human
    def min(self):

        # Possible values for minv are:
        # -1 - win
        # 0  - a tie
        # 1  - loss

        # We're initially setting it to 2 as worse than the worst case:
        minv = 2

        qx = None
        qy = None

        result = self.is_end()

        if result == 'X':
            return -1, 0, 0
        elif result == 'O':
            return 1, 0, 0
        elif result == '.':
            return 0, 0, 0

        for i in range(0, self.board_size):
            for j in range(0, self.board_size):
                if self.current_state[i][j] == '.':
                    self.current_state[i][j] = 'X'
                    (m, max_i, max_j) = self.max()
                    if m < minv:
                        minv = m
                        qx = i
                        qy = j
                    self.current_state[i][j] = '.'

        return minv, qx, qy

    def play(self):
        while True:
            self.draw_board()
            self.result = self.is_end()

            # Printing the appropriate message if the game has ended
            if self.result is not None:
                if self.result == 'X':
                    print('The winner is X!')
                elif self.result == 'O':
                    print('The winner is O!')
                elif self.result == '.':
                    print("It's a tie!")

                self.initialize_game()
                return

            # If it's player's turn
            if self.player_turn == 'X':

                while True:

                    start = time.time()
                    (m, qx, qy) = self.min()
                    end = time.time()
                    print('Evaluation time: {}s'.format(round(end - start, 7)))
                    print('Recommended move: X = {}, Y = {}'.format(qx, qy))

                    px = int(input('Insert the X coordinate: '))
                    py = int(input('Insert the Y coordinate: '))

                    if self.is_valid(px, py):
                        self.current_state[px][py] = 'X'
                        self.player_turn = 'O'
                        break
                    else:
                        print('The move is not valid! Try again.')

            # If it's AI's turn
            else:
                (m, px, py) = self.max()
                self.current_state[px][py] = 'O'
                self.player_turn = 'X'

    def max_alpha_beta(self, alpha, beta):
        maxv = -2
        px = None
        py = None

        result = self.is_end()

        if result == self.player_mark:
            return -1, 0, 0
        elif result == self.computer_mark:
            return 1, 0, 0
        elif result == '.':
            return 0, 0, 0

        for i in range(0, 3):
            for j in range(0, 3):
                if self.current_state[i][j] == '.':
                    self.current_state[i][j] = self.computer_mark
                    (m, min_i, in_j) = self.min_alpha_beta(alpha, beta)
                    if m > maxv:
                        maxv = m
                        px = i
                        py = j
                    self.current_state[i][j] = '.'

                    if maxv >= beta:
                        return maxv, px, py

                    if maxv > alpha:
                        alpha = maxv

        return maxv, px, py

    def min_alpha_beta(self, alpha, beta):
        minv = 2
        qx = None
        qy = None

        result = self.is_end()

        if result == self.player_mark:
            return -1, 0, 0
        elif result == self.computer_mark:
            return 1, 0, 0
        elif result == '.':
            return 0, 0, 0

        for i in range(0, 3):
            for j in range(0, 3):
                if self.current_state[i][j] == '.':
                    self.current_state[i][j] = self.player_mark
                    (m, max_i, max_j) = self.max_alpha_beta(alpha, beta)
                    if m < minv:
                        minv = m
                        qx = i
                        qy = j
                    self.current_state[i][j] = '.'

                    if minv <= alpha:
                        return minv, qx, qy

                    if minv < beta:
                        beta = minv

        return minv, qx, qy

    def play_alpha_beta(self):
        choice = int(input('Enter 1 if you want to play first or enter 2 if you want to play after the computer: '))
        if choice == 1:
            self.computer_mark = 'O'
            self.player_mark = 'X'
        else:
            self.computer_mark = 'X'
            self.player_mark = 'O'

        while True:
            self.draw_board()
            self.result = self.is_end()

            if self.result is not None:
                if self.result == self.computer_mark:
                    print('The winner is the computer!')
                elif self.result == self.player_mark:
                    print('You are the winner!')
                elif self.result == '.':
                    print("It's a tie!")

                self.initialize_game()
                return

            if self.player_turn == self.player_mark:

                while True:
                    # start = time.time()
                    # (m, qx, qy) = self.min_alpha_beta(-2, 2)
                    # end = time.time()
                    # print('Evaluation time: {}s'.format(round(end - start, 7)))
                    # print('Recommended move: X = {}, Y = {}'.format(qx, qy))

                    px = int(input('Insert the X coordinate: '))
                    py = int(input('Insert the Y coordinate: '))

                    if self.is_valid(px, py):
                        self.current_state[px][py] = self.player_mark
                        self.player_turn = self.computer_mark
                        break
                    else:
                        print('The move is not valid! Try again.')

            else:
                (m, px, py) = self.max_alpha_beta(-2, 2)
                self.current_state[px][py] = self.computer_mark
                self.player_turn = self.player_mark


def main():
    g = Game()
    g.play_alpha_beta()


if __name__ == "__main__":
    main()
