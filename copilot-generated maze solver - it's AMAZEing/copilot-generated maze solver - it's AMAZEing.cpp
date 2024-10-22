#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::stack;
using std::vector;
using std::pair;

const int ROWS = 10;
const int COLS = 10;

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'S', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '.', '.', '.', 'E', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

struct Position {
    int row;
    int col;
};

bool isValidMove(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && (maze[row][col] == '.' || maze[row][col] == 'E');
}

bool solveMaze() {
    stack<Position> s;
    Position start = { 1, 1 }; // Starting position (row, col)
    s.push(start);

    while (!s.empty()) {
        Position current = s.top();
        s.pop();

        int row = current.row;
        int col = current.col;

        if (maze[row][col] == 'E') {
            return true; // Maze solved
        }

        maze[row][col] = '*'; // Mark as visited

        // Move in all four possible directions
        if (isValidMove(row - 1, col)) s.push({ row - 1, col }); // Up
        if (isValidMove(row + 1, col)) s.push({ row + 1, col }); // Down
        if (isValidMove(row, col - 1)) s.push({ row, col - 1 }); // Left
        if (isValidMove(row, col + 1)) s.push({ row, col + 1 }); // Right
    }

    return false; // No solution found
}

void printMaze() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << maze[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    if (solveMaze()) {
        cout << "Maze solved:\n";
    }
    else {
        cout << "No solution found for the maze.\n";
    }

    printMaze();
    return 0;
}
