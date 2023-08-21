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
	void updateTask();
	void deleteTask(int);
	void showAllTask();
	int retID();
};

void toDoList ::intro()
{
	cout << "Created By Abdulahad";
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

void toDoList ::showAllTask()
{
	cout << "Id Of Task : " << id << endl;
	cout << "Task : " << data << endl;
	cout << "Status : " << status << endl;
}

void toDoList ::updateTask()
{
}

void toDoList ::deleteTask(int num)
{
	toDoList list;
	ifstream inFile;
	inFile.open("Data.txt", ios::app | ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
	}
	ofstream outFile;
	outFile.open("Temp.txt");
	inFile.seekg(0, ios::beg);
	while (inFile.read((char *)&list, sizeof(toDoList)))
	{
		if (list.retID() != num)
		{
			outFile.write((char *)&list, sizeof(toDoList));
			cout << "Record Not Exist ..";
			break;
		}
		else
		{
			cout << "Record Deleted ..";
		}
	}
	outFile.close();
	inFile.close();
	remove("Data.txt");
	rename("Temp.txt", "Data.txt");
	cin.ignore();
	cin.get();
}

int toDoList::retID()
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
			cin.ignore();
			cin.get();
			inFile.close();

			break;
		}
		case '3':
			list.updateTask();
			break;
		case '4':
		{
			cout << "Enter The Id Of Task You Want To Delete ";
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