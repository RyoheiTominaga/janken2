//�W�����P�������S��
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
		case ROCK:cout << "\nCP�̓O�[���o��\n";break;
		case PEPAL:cout << "\nCP�̓p�[���o��\n";break;
		case SCIOSSORS:cout << "\nCP�̓`���L���o��\n";break;
		}
#endif // DEBUG_ON

		while (P < 0 || P>2)
		{
			cout << "\n�����o���܂����H\n0�@�O�[\n1 �p�[\n2 �`���L\n ";
			cin >> P;
		}

		switch (E)
		{
		case ROCK:cout << "CP�̓O�[���o����\n" << endl;break;
		case PEPAL:cout << "CP�̓p�[���o����\n" << endl;break;
		case SCIOSSORS:cout << "CP�̓`���L���o����\n" << endl;break;
		}

		

		if (P == ROCK) //�O�[
		{
			switch (E) {
			case ROCK:a = judge[0].judge;break;
			case PEPAL:a = judge[1].judge;break;
			case SCIOSSORS:a = judge[2].judge;break;
			}
		}

		else if (P == PEPAL) //�p�[
		{
			switch (E) {
			case ROCK:a = judge[3].judge;break;
			case PEPAL:a = judge[4].judge;break;
			case SCIOSSORS:a = judge[5].judge;break;
			}
		}

		else //�`���L
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
		case DOLLOW:cout << "������\n" << endl;P = -1;a = 100;break;
		case WIN:cout << "���Ȃ��̏����ł�\n" << endl;break;
		case LOSE:cout << "���Ȃ��̕����ł�\n" << endl;break;
		}
	}
}
