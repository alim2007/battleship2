#include <iostream>
#include <conio.h>
#include <Windows.h> 
using namespace std;
#include "functions.h"

int main()
{
	srand(time(NULL));
	for (int i = 0; i < BOARD_SIZE; i++) arr[i] = new char[BOARD_SIZE];

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (j == 0 && i != 0) arr[i][j] = i + 64; // a-h
			else if (i == 0 && j != 0) arr[i][j] = j + 48; // 1-8
			else arr[i][j] = ' ';
		}
	}

    int currOption = 0;
    bool menuLoop = true;

    while (menuLoop) {
        system("cls"); 
        showMainMenu(currOption);

        int key = _getch(); 
        if (key == 224 || key == ENTER) 
        {
            key = _getch(); 
            cout << "key pressed: " << key << endl;
            //cout << "currSubOption: " << currSubOption << endl;
            switch (key) 
            {
            case UP:
                currOption--;
                if (currOption < 0) currOption = 2;
                break;
            case DOWN:
                currOption++;
                if (currOption > 2) currOption = 0;
                break;
            case ENTER:
                switch (currOption) 
                {
                case 0:
                    int currSubOption;
                    cout << "key pressed: " << key << endl;
                    while (true)
                    {
                        char key = _getch();
                        if (key == ENTER) 
                        { 
                            if (currSubOption == 0) 
                            {
                                getPlayerShips();
                            }
                            else if (currSubOption == 1) 
                            {
                                getPlayerShipsRand();
                                printBoard();
                            }
                        }
                        else if (key == UP && currSubOption > 0)
                        {
                            currSubOption--;
                        }
                        else if (key == DOWN && currSubOption < 1)
                        {
                            currSubOption++;
                        }

                    }
                    break;
                case 1: // Help
                    break;
                case 2: // Exit
                    return 0;
                }
                break;
            }
        }
    }

	
	
	
	
	
	
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}