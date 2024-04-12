#include <stdio.h>

int board[9];
int gameover;

void draw_board() {
  system('cls');  //may or may not work depending on C version (function to update screen after each move)
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int k = i * 3 + j;
            printf("%c | ", board[k] == 1 ? 'X' : board[k] == 2 ? 'O' : ' ');
        }
        printf("\n");
    }
}

int check_win() {
    for (int i = 0; i < 3; i++) {
        if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != 0) {
            return 1;
        }
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != 0) {
            return 1;
        }
    }
    if (board[0] == board[4] && board[4] == board[8] && board[0] != 0) {
        return 1;
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != 0) {
        return 1;
    }
    return 0;
}

int check_draw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void mark_board(int pos, char player) {
    board[pos - 1] = player == 'X' ? 1 : 2;
}

int main() {
    int play_again = 1; // Flag to indicate whether to play again
    while (play_again) {
        gameover = 0;
        for (int i = 0; i < 9; i++) {
            board[i] = 0;
        }

        char current_player = 'X';

        while (!gameover) {
            draw_board();
            int pos;
            printf("Player %c, enter your move (1-9): ", current_player);
            if (scanf("%d", &pos) != 1 || pos < 1 || pos > 9 || board[pos - 1] != 0) {
                printf("Invalid input! Please enter a number from 1 to 9 representing an empty position.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            mark_board(pos, current_player);
            if (check_win()) {
                draw_board(); // Draw the board again to show the winning move
                printf("Player %c wins!\n", current_player);
                gameover = 1;
            } else if (check_draw()) {
                printf("It's a draw!\n");
                gameover = 1;
            } else {
                current_player = current_player == 'X' ? 'O' : 'X';
            }
        }

        printf("Do you want to play again? (1 for Yes, 0 for No): ");
        scanf("%d", &play_again);
    }

    return 0;
}
