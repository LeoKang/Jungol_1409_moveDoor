#include <iostream>
#include <stack>

using namespace std;

stack<int> shelf;
int nShelf = 7;
int isUsed[7] = { 0, };
//int moveSeq[] = { 3, 1, 6, 5 };
int moveSeq[] = { 3, 1 };
int cur = 0;
//int nMove = 4;
int nMove = 2;

void initIsUsed(void) {
	for (int i = 0; i < 7; i++) {
		isUsed[i] = 0;
	}
}

void moveCloset(int p, int open1, int open2) {
	int open[2];
	open[0] = open1;
	open[1] = open2;
	cout << __FUNCTION__ << "(" << p << ") : " << open[0] << ", " << open[1] << endl;

	isUsed[open1 - 1] = 1;
	isUsed[open2 - 1] = 1;

	if (p == nMove) {
		cout << "p == nMove" << endl;
		return;
	}

	if (open1 == moveSeq[p] || open2 == moveSeq[p]) {
		cout << open1 << "," << open2 << endl;
		cur++;

		initIsUsed();
		moveCloset(cur, open1, open2);
	}
	else{
//		cout << " : false" << endl;
	}
	
	if (open1 > 1 && isUsed[open1-2] == 0) {
		open1--;
		moveCloset(cur, open1, open2);
	}
	if (open1 < nShelf && isUsed[open1] == 0) {
		open1++;
		moveCloset(cur, open1, open2);
	}

	if (open2 > 1 && isUsed[open2 - 2] == 0) {
		open2--;
		moveCloset(cur, open1, open2);
	}
	if (open2 < nShelf && isUsed[open2] == 0) {
		open2++;
		moveCloset(cur, open1, open2);
	}


}

int main(void) {
	cout << "nShelf : " << nShelf << endl;
//	cout << "open : " << open[0] << ", " << open[1] << endl;
	cout << "nMove : " << nMove << endl;
	cout << "moveSeq : ";
	for (int i = 0; i < nMove; i++) {
		cout << moveSeq[i] << " ";
	}
	cout << endl << endl;

	//stack test
	shelf.push(2);
	cout << "shelf.size() : " << shelf.size() << endl;
	cout << "shelf.top() : " << shelf.top() << endl;
	shelf.pop();
	cout << endl;
	//stack test end.


	moveCloset(cur, 2, 5);


	system("pause");
	return 0;
}