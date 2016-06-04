#include <iostream>
#include <fstream>
#include "func.h"
#include <string>

using namespace std;

int x, y;
int c = 1;
int health = 5;

void finish(int userStep[50][50]){
    if (userStep[x][y] == 3){
        cout << "\n �� ��������!!!!!"<< endl;
        c = 0;
    }
}

void verifyY(int y1, int y2, int userStep[50][50]) {
    if ((userStep[x][y1] == 1) || (y < 0) || (y > 50)) {
        health -= 1;
        cout << "\n stooooooooooop" << "�� ����, � ���� " << health << " ������" << endl;
        y = y2;
    } else {
        y = y1;
    }
}

void verifyX(int x1, int x2, int userStep[50][50]) {
    if ((userStep[x1][y] == 1) || (x < 0) || (x > 50)){
        health -= 1;
        cout << "\n stooooooooooop" << "�� ����, � ���� " << health << " ������" << endl;
        x = x2;
    } else {
        x = x1;
    }
}

void up(int userStep[50][50]){
    int y1 = y - 1;
    int y2 = y;
    verifyY(y1, y2, userStep);
}

void down(int userStep[50][50]){
    int y1 = y + 1;
    int y2 = y;
    verifyY(y1, y2, userStep);
}

void right(int userStep[50][50]){
    int x1 = x + 1;
    int x2 = x;
    verifyX(x1, x2, userStep);
}

void left(int userStep[50][50]){
    int x1 = x - 1;
    int x2 = x;
    verifyX(x1, x2, userStep);
}

int main(){
    setlocale(LC_ALL, "russian_russia.1251");

    cout << "����... �������� �������... ����� ���, ��� ���� ���� ������... � ��� �������� �����..." << endl;
    cout << "� � ���� ����� 5 ������... � ������ �����������..." << endl;
    cout << "������ �� ������� ��� ������!!!" << endl;
    generation();
    cout << "w - ����� d - ������ s - ���� a - �����" << endl;
    cout << "��� �, ������" << endl;

    ifstream field("field.txt");
    int userStep[50][50];

    for (y = 0; y < 50; y++){
        for (x = 0; x < 50; x++){
            field >> userStep[x][y];
        }
    }

    field.close();

     for (int j = 0; j < 50; j++){ // ���������, ��� � ��� ������
        for (int i = 0; i < 50; i++){
            if (userStep[i][j] == 2){
                x = i;
                y = j;
            }
        }
     }

    while(c){
        char userChoice;
		cout << "����?" << endl;
		cin >> userChoice;

		switch(userChoice) {
			case 'w':
				up(userStep);
				finish(userStep);
				break;

			case 's':
				down(userStep);
				finish(userStep);
				break;

			case 'a':
				left(userStep);
				finish(userStep);
				break;

			case 'd':
				right(userStep);
				finish(userStep);
				break;

            default:
				cout << "�� ��� ������";
				break;
		}
		nearFarAway(x, y);

		if (health < 1){
            c = 0;
		}
	}
}


