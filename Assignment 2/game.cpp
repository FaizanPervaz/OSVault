#include <iostream>
#include <pthread.h>
#include <vector>
#include <termios.h>
#include <unistd.h>
using namespace std;

int generateBoardSize() {
    int randomNum = rand() % 90 + 10; 
    int lastDigit = 5;  
    int multipliedNum = randomNum * lastDigit; 
    int divisionResult = 565 / multipliedNum;  
    int modResult = divisionResult % 25;  
    if (modResult < 10) {
        modResult = modResult + 15;  
    }
    return modResult;
}

const int BOARD_SIZE = generateBoardSize();
vector <pthread_t> playerThreads;

const int NUM_PLAYERS = 4;

vector<vector<char>> gameBoard(BOARD_SIZE, vector<char>(BOARD_SIZE, '.'));
bool gameIsRunning = true;
int gameItemCount = 0;

class Player {
public:
    int x, y;
    int score;
};

vector<Player> players(NUM_PLAYERS);

void displayGameBoard() {
    system("clear");

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            bool playerPresent = false;
            for (const Player& player : players) {
                if (player.x == i && player.y == j) {
                    playerPresent = true;
                    break;
                }
            }
            if (playerPresent) {
                cout << 'P' << " ";
            } else {
                cout << gameBoard[i][j] << " ";
            }
        }
        cout << endl;
    }

    // Display player scores
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        cout << "Player " << i + 1 << " Score: " << players[i].score << endl;
    }

    // Winner Check 
    if (gameItemCount == 0) {
        gameIsRunning = false;
        int maxScore = 0;

        // finding max score
        for (const Player& player : players) {
            if (player.score > maxScore) {
                maxScore = player.score;
            }
        }

        // displaying players with max score as winner
        cout << "Winners: ";
        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (players[i].score == maxScore) {
                cout << "Player " << i + 1 << " ";
            }
        }
        cout << endl;
    }
}

void movePlayer(Player& player, int dx, int dy) {
    int new_x = player.x + dx;
    int new_y = player.y + dy;

    if (new_x >= 0 && new_x < BOARD_SIZE && new_y >= 0 && new_y < BOARD_SIZE) {
        gameBoard[player.x][player.y] = '.';
        player.x = new_x;
        player.y = new_y;
    }
}

void placeRandomSymbols() {
    for (int i = 0; i < 2; ++i) {
        int x, y;
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
        } while (gameBoard[x][y] != '.');
        gameBoard[x][y] = "^&$#"[i];
        gameItemCount++;
    }
}

int getKeyPress() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int currentPlayerTurn = 0;

void playerThreadFunction(int playerID) {
    Player& player = players[playerID];

    while (gameIsRunning) {
        if (playerID == currentPlayerTurn) {
            int input = 0;

            int key = getKeyPress();
            switch (key) {
                case 65: // ASCII code for Up arrow
                    input = 1;
                    break;
                case 66: // ASCII code for Down arrow
                    input = 2;
                    break;
                case 68: // ASCII code for Left arrow
                    input = 3;
                    break;
                case 67: // ASCII code for Right arrow
                    input = 4;
                    break;
            }

            int dx = 0, dy = 0;
            switch (input) {
                case 1: // Up
                    dy = -1;
                    break;
                case 2: // Down
                    dy = 1;
                    break;
                case 3: // Left
                    dx = -1;
                    break;
                case 4: // Right
                    dx = 1;
                    break;
                default:
                    break;
            }

            movePlayer(player, dx, dy);

            int x = player.x;
            int y = player.y;
            char cell = gameBoard[x][y];
            if (cell == '^' || cell == '&' || cell == '$' || cell == '#') {
                player.score += 10;
                gameBoard[x][y] = '.';
                gameItemCount--;
            }
            currentPlayerTurn = (currentPlayerTurn + 1) % NUM_PLAYERS;
        }

        usleep(100000);
    }
}

void initializePlayers() {
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        int x, y;
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
        } while (gameBoard[x][y] != '.');
        players[i].x = x;
        players[i].y = y;
    }
}

void gameLoop() {
    initializePlayers();
    placeRandomSymbols();

    while (gameIsRunning) {
        for (const Player& player : players) {
            gameBoard[player.x][player.y] = 'P';
        }

        displayGameBoard();
        usleep(100000);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < NUM_PLAYERS; ++i) {
        pthread_t thread;
        pthread_create(&thread, NULL, (void *(*)(void *))playerThreadFunction, (void*)(intptr_t)i);
        playerThreads.push_back(thread);
    }

    gameLoop();

    for (pthread_t thread : playerThreads) {
        pthread_join(thread, NULL);
    }

    return 0;
}
