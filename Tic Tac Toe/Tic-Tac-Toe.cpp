#include <iostream>
using namespace std;
char index[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int showboard();
void play();
int checkwin();
int player = 1, select,flag=-1;
char value;
int main()
{
	while (flag==-1)
	{
		showboard();
		play();
		flag = checkwin();
	}
	showboard();
	if (flag == 1)
	{
		player--;
		cout << "\n\n\t\t\tCongratulation! Player " << player << " won the match" << endl;
	}
	else
	{
		cout << "\n\n\t\t\tMatch draw" << endl;
	}
	cin.ignore();
    cin.get();
	return 0;
}

int showboard()
{
	system("cls");

	cout << "\t\t\t ####### ###  #####     #######    #     #####     ####### ####### ####### " << endl;
	cout << "\t\t\t    #     #  #     #       #      # #   #     #       #    #     # #       " << endl;
	cout << "\t\t\t    #     #  #             #     #   #  #             #    #     # #       " << endl;
	cout << "\t\t\t    #     #  #             #    #     # #             #    #     # #####   " << endl;
	cout << "\t\t\t    #     #  #             #    ####### #             #    #     # #       " << endl;
	cout << "\t\t\t    #     #  #     #       #    #     # #     #       #    #     # #       " << endl;
	cout << "\t\t\t    #    ###  #####        #    #     #  #####        #    ####### ####### " << endl;

	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t*******************" << endl;
	cout << "\t\t\t\t\t\t*     *     *     *" << endl;
	cout << "\t\t\t\t\t\t*  " << index[1] << "  *  " << index[2] << "  *  " << index[3] << "  *  " << endl;

	cout << "\t\t\t\t\t\t*******************" << endl;
	cout << "\t\t\t\t\t\t*     *     *     *" << endl;

	cout << "\t\t\t\t\t\t*  " << index[4] << "  *  " << index[5] << "  *  " << index[6] << "  *  " << endl;

	cout << "\t\t\t\t\t\t*******************" << endl;
	cout << "\t\t\t\t\t\t*     *     *     *" << endl;

	cout << "\t\t\t\t\t\t*  " << index[7] << "  *  " << index[8] << "  *  " << index[9] << "  *  " << endl;

	cout << "\t\t\t\t\t\t*******************" << endl;
}

void play()
{

	if (player % 2)
	{
		player = 1;
		value = 'X';
	}
	else
	{
		player = 2;
		value = 'O';
	}
	cout << "\n\n\t\t\tPlayer 1 have (X) and Player 2 have (O)" << endl;
	cout << "\t\t\tPlayer " << player << " Select the Index ";
	cin >> select;
	if (select == 1 && index[1] == '1')
	{
		index[1] = value;
	}
	else if (select == 2 && index[2] == '2')
	{
		index[2] = value;
	}
	else if (select == 3 && index[3] == '3')
	{
		index[3] = value;
	}
	else if (select == 4 && index[4] == '4')
	{
		index[4] = value;
	}
	else if (select == 5 && index[5] == '5')
	{
		index[5] = value;
	}
	else if (select == 6 && index[6] == '6')
	{
		index[6] = value;
	}
	else if (select == 7 && index[7] == '7')
	{
		index[7] = value;
	}
	else if (select == 8 && index[8] == '8')
	{
		index[8] = value;
	}
	else if (select == 9 && index[9] == '9')
	{
		index[9] = value;
	}
	else
	{
		cout << "\t\t\tInvalid move ";
		player--;
		cin.ignore();
		cin.get();
	}
	player++;
}

int checkwin()
{
	if (index[1] == index[2] && index[2] == index[3])
	{
		return 1;
	}
	else if (index[4] == index[5] && index[5] == index[6])
	{
		return 1;
	}
	else if (index[7] == index[8] && index[8] == index[9])
	{
		return 1;
	}
	else if (index[1] == index[4] && index[4] == index[7])
	{
		return 1;
	}
	else if (index[2] == index[5] && index[5] == index[8])
	{
		return 1;
	}
	else if (index[3] == index[6] && index[6] == index[9])
	{
		return 1;
	}
	else if (index[1] == index[5] && index[5] == index[9])
	{
		return 1;
	}
	else if (index[3] == index[5] && index[5] == index[7])
	{
		return 1;
	}
	else if (index[1] != '1' && index[2] != '2' && index[3] != '3' 
	&& index[4] != '4' && index[5] != '5' && index[6] != '6' 
	&& index[7] != '7' && index[8] != '8' && index[9] != '9')
	{
		return 0;
	}
	else{
		return -1;
	}
}
