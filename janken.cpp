//ジャンケン処理全般
#include"janken.h"
#include <iostream>
#include<ctime>

#define DEBUG_ON

using namespace std;

struct JUDGE {
	int Player;
	int Enemy;
	int judge;
};
enum RPS {
	ROCK = 0,
	PEPAL = 1,
	SCIOSSORS = 2,
};
enum WinLoseDollow {
	DOLLOW = 0,
	WIN = 1,
	LOSE = 2,
};
JUDGE const judge[9] = {
	{0,0,0},
	{0,1,2},
	{0,2,1},
	{1,0,1},
	{1,1,0},
	{1,2,2},
	{2,0,2},
	{2,1,1},
	{2,2,0},
};

void Game() {

	int P = -1, E = -1, a = 100;

	while (a == 100)
	{
		srand((unsigned int)time(NULL));
		E = rand() % 3;

#ifdef DEBUG_ON
		switch (E) {
		case ROCK:cout << "\nCPはグーを出す\n";break;
		case PEPAL:cout << "\nCPはパーを出す\n";break;
		case SCIOSSORS:cout << "\nCPはチョキを出す\n";break;
		}
#endif // DEBUG_ON

		while (P < 0 || P>2)
		{
			cout << "\n何を出しますか？\n0　グー\n1 パー\n2 チョキ\n ";
			cin >> P;
		}

		switch (E)
		{
		case ROCK:cout << "CPはグーを出した\n" << endl;break;
		case PEPAL:cout << "CPはパーを出した\n" << endl;break;
		case SCIOSSORS:cout << "CPはチョキを出した\n" << endl;break;
		}

		

		if (P == ROCK) //グー
		{
			switch (E) {
			case ROCK:a = judge[0].judge;break;
			case PEPAL:a = judge[1].judge;break;
			case SCIOSSORS:a = judge[2].judge;break;
			}
		}

		else if (P == PEPAL) //パー
		{
			switch (E) {
			case ROCK:a = judge[3].judge;break;
			case PEPAL:a = judge[4].judge;break;
			case SCIOSSORS:a = judge[5].judge;break;
			}
		}

		else //チョキ
		{
			switch (E)
			{
			case ROCK:a = judge[6].judge;break;
			case PEPAL:a = judge[7].judge;break;
			case SCIOSSORS:a = judge[8].judge;break;
			}
		}

		switch (a)
		{
		case DOLLOW:cout << "あいこ\n" << endl;P = -1;a = 100;break;
		case WIN:cout << "あなたの勝ちです\n" << endl;break;
		case LOSE:cout << "あなたの負けです\n" << endl;break;
		}
	}
}
