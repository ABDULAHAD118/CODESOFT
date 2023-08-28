#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;
void intro();
void playgame();

int main()
{
	int number, value, tries = 0, chances = 4;
	intro();
	cin.get();
	system("cls");
	srand(time(0));
	value = rand() % 10;

	playgame();
	system("cls");
	cout << "\n\n\n\n";
	while (tries != 4)
	{
		cout << "\t\tGUSSE THE NUMBER BETWEEN 0 TO 9. YOU HAVE " << chances << " CHANCES TO GUSS THE CORRECT NUMBER - ";
		cin >> number;
		if (number == value)
		{
			cout << "\n\t\tCongratulations! You Guss The Correct Number" << endl;
			cout << "\n\t\tYou Guss The Number In " << tries << " Tries";
			break;
		}
		else if (number >= value)
		{
			cout << "\n\t\tYou  number is larger . Please try again" << endl;
			tries++;
			chances--;
		}
		else if (number <= value)
		{
			cout << "\n\t\tYou number is smaller. Please try again" << endl;
			tries++;
			chances--;
		}
	}
	if (tries == 4)
	{
		cout << "\n\t\tThe correct number is " << value;
	}
	return 0;
}

void intro()
{
	cout << "\n\n\n\n";
	cout << "\t\t#     # #     # #     # ######  ####### ######      #####  #     #  #####   #####  ### #     #  #####      #####     #    #     # ####### " << endl;
	cout << "\t\t##    # #     # ##   ## #     # #       #     #    #     # #     # #     # #     #  #  ##    # #     #    #     #   # #   ##   ## #       " << endl;
	cout << "\t\t# #   # #     # # # # # #     # #       #     #    #       #     # #       #        #  # #   # #          #        #   #  # # # # #       " << endl;
	cout << "\t\t#  #  # #     # #  #  # ######  #####   ######     #  #### #     #  #####   #####   #  #  #  # #  ####    #  #### #     # #  #  # #####   " << endl;
	cout << "\t\t#   # # #     # #     # #     # #       #   #      #     # #     #       #       #  #  #   # # #     #    #     # ####### #     # #       " << endl;
	cout << "\t\t#    ## #     # #     # #     # #       #    #     #     # #     # #     # #     #  #  #    ## #     #    #     # #     # #     # #       " << endl;
	cout << "\t\t#     #  #####  #     # ######  ####### #     #     #####   #####   #####   #####  ### #     #  #####      #####  #     # #     # ####### " << endl;
}

void playgame()
{
	char a;
	cout << "\n\n\n\n";
	cout << setw(40) << "1.PLAY GUSS NUMBER GAME" << endl;
	cout << setw(23) << "2.EXIT" << endl;
	cout << setw(43) << "SELECT THE OPTION (1-2) ";
	cin >> a;
	if (a == '1')
	{
	}
	else if (a == '2')
		exit(0);
	else
		playgame();
}
