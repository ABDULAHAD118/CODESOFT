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

	cout << "\n\n\t\tEnter The Id Of The Task : ";
	cin >> id;
	cout << "\t\tWrite The Detail Of Task : ";
	cin.ignore();
	cin.getline(data, 50);
	cout << "\t\tEnter The Status Of Task (Pending/Approval): ";
	cin >> status;
}

void toDoList ::showAllTask() const
{
	cout << "\n\n\t\tId Of Task : " << id << endl;
	cout << "\t\tTask : " << data << endl;
	cout << "\t\tStatus : " << status << endl;
	cout<<"\t\t==================="<<endl;
}

void toDoList ::modifystatus()
{
	cout << "\t\tId Of Task : " << id << endl;
	cout << "\t\tTask : " << data << endl;
	cout << "\t\tEnter the status : ";
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
		bool recordFound = false;
		outFile.open("Temp.txt", ios::binary);
		while (inFile.read((char *)&list, sizeof(toDoList)))
		{
			if (list.retID() == num)
			{
				cout << "\t\tUpdating status for Task with ID: " << num << endl;
				list.modifystatus();
					recordFound = true;
			}
				outFile.write((char *)&list, sizeof(toDoList));
			
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
				cout << "\t\tRecord Deleted ..";
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
		cout << "\n\n\t\tTo-Do List Manager" << endl;
		cout << "\n\t\t1. Creat Task" << endl;
		cout << "\n\t\t2. View Tasks" << endl;
		cout << "\n\t\t3. Mark Task as Completed" << endl;
		cout << "\n\t\t4. Delete Task" << endl;
		cout << "\n\t\t5. Quit" << endl;

		cout << "\n\n\t\tEnter your choice: ";
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
			system("cls");
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
			system("cls");
			break;
		}
		case '3':
		{
			cout << "\n\n\t\tEnter The Id Of Task You Want To Update The Status : ";
			cin >> num;
			list.updatestatus(num);
			system("cls");
			break;
		}
		case '4':
		{
			cout << "\n\n\t\tEnter The Id Of Task You Want To Delete : ";
			cin >> num;
			list.deleteTask(num);
			system("cls");
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
