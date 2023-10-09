#include<iostream>
#include<ctime>
#include"kazuate.h"

#define DEBUG_ON

using namespace std;

void KazuGame() {
	int find = 0, search = -1, count = 0;//見つける数,捜す数,かかった回数
	bool victory = false;
	srand((unsigned int )time(NULL));
	find = rand() % 10;
#ifdef DEBUG_ON
	
	cout << "CPの数字は" << find << "です。\n";

#endif // DEBUG_ON

	while (victory == false)
	{
		while (search > 9 || search < 0)
		{
			cout << "あなたが思う相手の数を入力してください(0から9)>" << endl;
			cin >> search;
		}
		count++;
		if (find == search) {
			cout << "正ッ解ッ!!" << endl;
			victory = true;
		}
		else {
			cout << "失敗" << endl;
			search = -1;
		}
	}
	cout << "正解するまでに" << count << "回かかりました\n";
}
