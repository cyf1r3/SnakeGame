#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int x, y, fruitX, fruitY, score;
const int height = 20;
const int width = 40;
bool gameOver = false;`
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
direction dir;

void Startup() {	//Inititalising the values at the startup
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width + 1;
	fruitY = rand() % height + 1;
	score = 0;	
}

void Draw() {	//Drawing the fruit and the snake
	system("cls");
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else if (i == 0 || i == (height - 1) || j == 0 || j == (width - 1))
				cout << "#";
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << endl << "Score: " << score << endl;
}

void Input() {	//Handling the input from the user
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': dir = LEFT;
			break;
		case 'w': dir = UP;
			break;
		case 's': dir = DOWN;
			break;
		case 'd': dir = RIGHT;
			break;
		case 'x': gameOver = true;
			break;
		default:
			break;
		}
	}

}

void Logic() {	//Handling the snake movement through the logic
	switch (dir)
	{
	case LEFT: x--;
			break;
		case RIGHT: x++;
			break;
		case UP: y--;
			break;
		case DOWN: y++;
			break;
		default:
			break;
	}
	if (x == fruitX && y == fruitY) {	//When the fruit is eaten then this randomises the next location of the fruit
		score += 10;
		fruitX = rand() % width + 1;
		fruitY = rand() % height + 1;
	}
	if (x == 0 || x == (width - 1) || y == 0 || y == (height - 1))
		gameOver = true;
}

int main() {	//The program exexution starts here calling all the funtions
	Startup();
	while (!gameOver) {
		Draw();
		Logic();
		Input();
		Sleep(10);
	}
	return 0;
}