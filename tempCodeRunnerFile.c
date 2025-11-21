#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For usleep()
#include <termios.h> // For non-blocking key input
#include <fcntl.h>

#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20
#define PADDLE_HEIGHT 4

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void draw(int paddle1Y, int paddle2Y, int ballX, int ballY) {
    system("clear");

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            if (y == 0 || y == SCREEN_HEIGHT - 1) {
                printf("#");
            } else if ((x == 1 && y >= paddle1Y && y < paddle1Y + PADDLE_HEIGHT) ||
                       (x == SCREEN_WIDTH - 2 && y >= paddle2Y && y < paddle2Y + PADDLE_HEIGHT)) {
                printf("|");
            } else if (x == ballX && y == ballY) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int paddle1Y = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2;
    int paddle2Y = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2;
    int ballX = SCREEN_WIDTH / 2, ballY = SCREEN_HEIGHT / 2;
    int ballDX = 1, ballDY = 1;

    while (1) {
        // Input
        if (kbhit()) {
            char ch = getchar();
            if (ch == 'w' && paddle1Y > 1) paddle1Y--;
            if (ch == 's' && paddle1Y < SCREEN_HEIGHT - PADDLE_HEIGHT - 1) paddle1Y++;
            if (ch == 'i' && paddle2Y > 1) paddle2Y--;
            if (ch == 'k' && paddle2Y < SCREEN_HEIGHT - PADDLE_HEIGHT - 1) paddle2Y++;
            if (ch == 'q') break;
        }

        // Ball movement
        ballX += ballDX;
        ballY += ballDY;

        if (ballY <= 1 || ballY >= SCREEN_HEIGHT - 2) ballDY = -ballDY;

        if ((ballX == 2 && ballY >= paddle1Y && ballY < paddle1Y + PADDLE_HEIGHT) ||
            (ballX == SCREEN_WIDTH - 3 && ballY >= paddle2Y && ballY < paddle2Y + PADDLE_HEIGHT)) {
            ballDX = -ballDX;
        }

        if (ballX <= 0 || ballX >= SCREEN_WIDTH - 1) {
            ballX = SCREEN_WIDTH / 2;
            ballY = SCREEN_HEIGHT / 2;
        }

        draw(paddle1Y, paddle2Y, ballX, ballY);
        usleep(50000);
    }

    return 0;
}
