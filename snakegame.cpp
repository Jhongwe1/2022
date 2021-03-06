#include<iostream>
#include<conio.h>
#include<string>
#include<windows.h>
using namespace std;
bool gameover = false;
string name;
int xsnake, ysnake, fruitx, fruity;
int tailx[100], taily[100];
int ntail;
int points = 0;
const int width = 20;
const int length = 20;
enum edirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
int i,j;
edirection dir;

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}

void setup()
{
	dir = STOP;
	xsnake = width / 2;
	ysnake = length / 2;
	fruitx = rand() % width;
	fruity = rand() % length;
}

void logic()
{
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = xsnake;
	taily[0] = ysnake;
	for (i = 1; i<ntail ; i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch (dir)
	{
	case LEFT:
		xsnake--;
		break;
	case RIGHT:
		xsnake++;
		break;
	case UP:
		ysnake--;
		break;
	case DOWN:
		ysnake++;
		break;
	default:
		break;
	}
	if (xsnake > width || xsnake < 0 || ysnake > length||ysnake<0 )
		gameover = true;
	for (i = 0; i < ntail; i++)
	{
		if (xsnake == tailx[i] && ysnake == taily[i])
			gameover = true;
	}
	if (xsnake == fruitx && ysnake == fruity)
	{
		points+=10;
		fruitx = rand() % width;
		fruity = rand() % length;
		ntail++;
	}
}

void draw()
{
	system("cls");
	for (i = 0; i <= width+2; i++)
		cout << "#";
	cout<<endl;

	for (int i = 0; i <=width; i++)
	{
		for (int j = 0; j <=length; j++)
		{
			if(j == 0)
				cout << "#";

			//snake
			if (i == ysnake && j == xsnake)
				cout << "O";

			//fruit
			else if (i == fruity && j == fruitx)
				cout << "@";
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailx[k] == j && taily[k] == i)
					{
						cout << 'o';
						print = true;
					}

				}
				if (!print)
					cout << " ";
			}

			if (j == width)
				cout << "#";
		}
		cout << endl;
		
	}
	//cout<<endl;
	for(i = 0; i <= width+2; i++)
		cout << "#";
	cout <<"\n"<<name<<endl;
	cout << points<<endl;
}

int main()
{

	setup();
	cout << "enter name: ";
	cin >> name;
	while (!gameover)
	{
		input();
		draw();
		logic();
		Sleep(100);
	}
	return 0;
}

