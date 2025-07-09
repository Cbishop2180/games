#include <iostream>
using namespace std;
std::string a[3] = { "*" ,"*" ,"*" };
std::string b[3] = { "*" ,"*" ,"*" };
std::string c[3] = { "*" ,"*" ,"*" };

int comp_row;
int comp_col;

void change(int row, int col, string ch) {
	switch (row) {
	case 0:
		a[col] = ch;
		break;
	case 1:
		b[col] = ch;
		break;
	case 2:
		c[col] = ch;
		break;
	default:
		break;
	}
}

int check(int moves) {
	int statement;
	//User player
	//first row
	if (a[0] == "x" && a[1] == "x" && a[2] == "x") {
		statement = 1;
	}
	//second row
	else if (b[0] == "x" && b[1] == "x" && b[2] == "x") {
		statement = 1;
	}
	//third row
	else if (c[0] == "x" && c[1] == "x" && c[2] == "x") {
		statement = 1;
	}
	// left to right diagonal
	else if (a[0] == "x" && b[1] == "x" && c[2] == "x") {
		statement = 1;
	}
	//right to left diagonal
	else if (a[2] == "x" && b[1] == "x" && c[0] == "x") {
		statement = 1;
	}
	//first column
	else if (a[0] == "x" && b[0] == "x" && c[0] == "x") {
		statement = 1;
	}
	//second column
	else if (a[1] == "x" && b[1] == "x" && c[1] == "x") {
		statement = 1;
	}
	//third column
	else if (a[2] == "x" && b[2] == "x" && c[2] == "x") {
		statement = 1;
	}

	//Computer plater
	else if (a[0] == "o" && a[1] == "o" && a[2] == "o") {
		statement = 2;
	}
	//second row
	else if (b[0] == "o" && b[1] == "o" && b[2] == "o") {
		statement = 2;
	}
	//third row
	else if (c[0] == "o" && c[1] == "o" && c[2] == "o") {
		statement = 2;
	}
	// left to right diagonal
	else if (a[0] == "o" && b[1] == "o" && c[2] == "o") {
		statement = 2;
	}
	//right to left diagonal
	else if (a[2] == "o" && b[1] == "o" && c[0] == "o") {
		statement = 2;
	}
	//first column
	else if (a[0] == "o" && b[0] == "o" && c[0] == "o") {
		statement = 2;
	}
	//second column
	else if (a[1] == "o" && b[1] == "o" && c[1] == "o") {
		statement = 2;
	}
	//third column
	else if (a[2] == "o" && b[2] == "o" && c[2] == "o") {
		statement = 2;
	}
	else if (moves == 9) {
		statement = 3;
	}
	else {
		statement = 0;
	}
	return statement;
}


void board() {
	system("cls");
	cout << a[0] << a[1] << a[2] << endl;
	cout << b[0] << b[1] << b[2] << endl;
	cout << c[0] << c[1] << c[2] << endl;
}

bool verify(int row, int col) {
	bool stat = false;
	if (row == 0) {
		if (a[col] == "*") {
			stat = true;
		}
		else if (a[col] != "*") {
			stat = false;
		}
	}
	else if (row == 1) {
		if (b[col] == "*") {
			stat = true;
		}
		else if (b[col] != "*") {
			stat = false;
		}
	}
	else if (row == 2) {
		if (c[col] == "*") {
			stat = true;
		}
		else if (c[col] != "*") {
			stat = false;
		}
	}
	else {
		stat = false;
	}
	return stat;
}

int main() {
	int moves = 0;
	int ch = 0;
	int player_row;
	int player_col;
	do {
		cout << "What row? \n0, \n1, \n2.\n";
		cin >> player_row;
		cout << "What column? 0, 1, 2.\n";
		cin >> player_col;
		bool check_validity;
		check_validity = verify(player_row, player_col);
		while (check_validity != true && player_row < 3 && player_row > -1 && player_col < 3 && player_col > -1 && comp_row < 3 && comp_row > -1 && comp_col < 3 && comp_col > -1) {
			cout << "Can't do that. something is already there.\n";
			cout << "What row? \n0, \n1, \n2.\n";
			cin >> player_row;
			cout << "What column? 0, 1, 2.";
			cin >> player_col;
			check_validity = verify(player_row, player_col);
		}
		change(player_row, player_col, "x");
		comp_row = rand() % 3;
		comp_col = rand() % 3;
		check_validity = verify(comp_row, comp_col);
		while (check_validity != true) {
			comp_row = rand() % 3;
			comp_col = rand() % 3;
			check_validity = verify(comp_row, comp_col);
		}
		change(comp_row, comp_col, "o");
		board();
		ch = check(moves);
		moves++;
	} while (ch == 0);
	if (ch == 1) {
		cout << "You Win!\n";
	}
	else if (ch == 2) {
		cout << "You Lose. :/\n";
	}
	/*else if (ch == 3) {
		cout << "Tie!\n";
	}*/
	else {
		cout << " Tie!"; //"Homie, no earthly idea how you managed to do this.\n";
	}
	return 0;
}
