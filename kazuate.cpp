#include<iostream>
#include<ctime>
#include"kazuate.h"
using namespace std;

void KazuGame() {
	int find = 0, search = -1, count = 0;//Œ©‚Â‚¯‚é”,‘{‚·”,‚©‚©‚Á‚½‰ñ”
	bool victory = false;
	srand((unsigned int )time(NULL));
	find = rand() % 10;

	while (victory == false)
	{
		while (search > 9 || search < 0)
		{
			cout << "‚ ‚È‚½‚ªŽv‚¤‘ŠŽè‚Ì”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢(0‚©‚ç9)>" << endl;
			cin >> search;
		}
		count++;
		if (find == search) {
			cout << "³ƒb‰ðƒb!!" << endl;
			victory = true;
		}
		else {
			cout << "Ž¸”s" << endl;
			search = -1;
		}
	}
	cout << "³‰ð‚·‚é‚Ü‚Å‚É" << count << "‰ñ‚©‚©‚è‚Ü‚µ‚½\n";
}
