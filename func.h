#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int finishX;
int finishY;

void generation(){
    int field[50][50];

    for (int y = 0; y < 50; y++){ //обнуляем поле
        for (int x = 0; x < 50; x++){
            field[x][y] = 0;
        }
    }

    srand ( time(NULL) );

    for (int i = 0; i < 10; i++){ //распределяем препятствия
        int random1 = rand()% 50 + 0;
        int random2 = rand()% 50 + 0;
        field[random1][random2] = 1;
    }

    int randomStartX, randomStartY, randomFinishX, randomFinishY;

    do {
        randomStartX = rand()% 50 + 0;
        randomStartY = rand()% 50 + 0;
        randomFinishX = rand()% 50 + 0;
        randomFinishY = rand()% 50 + 0;
    } while ((abs(randomStartX - randomFinishX) < 15) || (abs(randomStartY - randomFinishY) < 15));

    field[randomStartX][randomStartY] = 2;
    field[randomFinishX][randomFinishY] = 3;

    ofstream numbers("field.txt");

     for (int y = 0; y < 50; y++){
        for (int x = 0; x < 50; x++){
            numbers << field[x][y] << " ";
        }
        numbers << "\n";
    }

    numbers.close();

    for (int j = 0; j < 50; j++){ // вычисляем, где у нас начало
        for (int i = 0; i < 50; i++){
            if (field[i][j] == 3){
                finishX = i;
                finishY = j;
                cout << "finish x " << finishX << "y " << finishY << endl;
            }
        }
     }
}

void nearFarAway(int x, int y){
    if ((abs(x - finishX) < 10) && (abs(y - finishY) < 10)){
        cout << "Ты уже близко!" << endl;
    }
}
