#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class toDoList
{
private:
	int id;
	char data[50];
	char status[10];

public:
	void intro();
	void creatTask();
	void modifystatus();
	void updatestatus(int);
	void deleteTask(int);
	void showAllTask() const;
	int retID() const;
};

void toDoList ::intro()
{
	cout << "\t\t\t####### #######    ######  #######    #       ###  #####  ####### " << endl;
	cout << "\t\t\t   #    #     #    #     # #     #    #        #  #     #    #    " << endl;
	cout << "\t\t\t   #    #     #    #     # #     #    #        #  #          #    " << endl;
	cout << "\t\t\t   #    #     #    #     # #     #    #        #   #####     #    " << endl;
	cout << "\t\t\t   #    #     #    #     # #     #    #        #        #    #    " << endl;
	cout << "\t\t\t   #    #     #    #     # #     #    #        #  #     #    #    " << endl;
	cout << "\t\t\t   #    #######    ######  #######    ####### ###  #####     #    " << endl;
}

void toDoList ::creatTask()
{

	cout << "Enter The Id Of The Task : ";
	cin >> id;
	cout << "Write The Detail Of Task : ";
	cin.ignore();
	cin.getline(data, 50);
	cout << "Enter The Status Of Task (Pending/Approval): ";
	cin >> status;
}

void toDoList ::showAllTask() const
{
	cout << "Id Of Task : " << id << endl;
	cout << "Task : " << data << endl;
	cout << "Status : " << status << endl;
}

void toDoList ::modifystatus()
{
	cout << "Id Of Task : " << id << endl;
	cout << "Task : " << data << endl;
	cout << "Enter the status : ";
	cin >> status;
}

void toDoList ::updatestatus(int num)
{
	toDoList list;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Data.txt", ios::app | ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
	}
	else
	{
		outFile.open("Temp.txt", ios::binary);
		while (inFile.read((char *)&list, sizeof(toDoList)))
		{
			if (list.retID() == num)
			{
				cout << "Updating status for Task with ID: " << num << endl;
				list.modifystatus();
			}
			outFile.write((char *)&list, sizeof(toDoList));
		}
		outFile.close();
		inFile.close();
		remove("Data.txt");
		rename("Temp.txt", "Data.txt");
		cin.ignore();
	}
}

void toDoList ::deleteTask(int num)
{
	toDoList list;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Data.txt", ios::app | ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
	}
	else
	{
		bool recordFound = false;
		outFile.open("Temp.txt", ios::binary);
		while (inFile.read((char *)&list, sizeof(toDoList)))
		{
			if (list.retID() == num)
			{
				cout << "Record Deleted ..";
				recordFound = true;
			}
			else
			{
				outFile.write((char *)&list, sizeof(toDoList));
			}
		}
		if (!recordFound)
		{
			cout << "Record Not Found ..";
		}
		outFile.close();
		inFile.close();
		remove("Data.txt");
		rename("Temp.txt", "Data.txt");
		cin.ignore();
		cin.get();
	}
}

int toDoList::retID() const
{
	return id;
}

int main()
{
	toDoList list;
	list.intro();
	cin.get();
	system("cls");

	char choice;
	int num;
	bool flag = true;
	while (flag)
	{
		cout << "To-Do List Manager" << endl;
		cout << "1. Creat Task" << endl;
		cout << "2. View Tasks" << endl;
		cout << "3. Mark Task as Completed" << endl;
		cout << "4. Delete Task" << endl;
		cout << "5. Quit" << endl;

		cout << "Enter your choice: ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case '1':
		{
			ofstream out;
			out.open("Data.txt", ios::app | ios::binary);
			list.creatTask();
			out.write((char *)&list, sizeof(toDoList));
			out.close();
			break;
		}
		case '2':
		{
			ifstream inFile;
			inFile.open("Data.txt", ios::app | ios::binary);
			if (!inFile)
			{
				cout << "File could not be open !! Press any Key...";
				cin.ignore();
				cin.get();
				return 0;
			}
			while (inFile.read((char *)&list, sizeof(toDoList)))
			{
				list.showAllTask();
			}
			inFile.close();
			cin.ignore();
			cin.get();
			break;
		}
		case '3':
		{
			cout << "Enter The Id Of Task You Want To Update The Status : ";
			cin >> num;
			list.updatestatus(num);
			break;
		}
		case '4':
		{
			cout << "Enter The Id Of Task You Want To Delete : ";
			cin >> num;
			list.deleteTask(num);
			break;
		}
		case '5':
			flag = false;
			break;
		default:
			cout << "Invalid input" << endl;
		}
	}
}