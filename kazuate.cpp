#include<iostream>
#include<ctime>
#include"kazuate.h"
using namespace std;

void KazuGame() {
	int find = 0, search = -1, count = 0;//�����鐔,�{����,����������
	bool victory = false;
	srand((unsigned int )time(NULL));
	find = rand() % 10;

	while (victory == false)
	{
		while (search > 9 || search < 0)
		{
			cout << "���Ȃ����v������̐�����͂��Ă�������(0����9)>" << endl;
			cin >> search;
		}
		count++;
		if (find == search) {
			cout << "���b���b!!" << endl;
			victory = true;
		}
		else {
			cout << "���s" << endl;
			search = -1;
		}
	}
	cout << "��������܂ł�" << count << "�񂩂���܂���\n";
}
