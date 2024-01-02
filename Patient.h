#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;
struct patient
{
	int id;
	string name;
	int age;
	string email;
};

void ReadFromFile(patient p[], int size)
{
	ifstream fin;
	fin.open("Patient.txt");//Exception Handling remaining
	int i = 0;
	while (fin >> p[i].id >> p[i].name >> p[i].age >> p[i].email)
	{
		i++;
	}
	fin.close();
}

bool addpatient(patient p[],int size)//Position where to be added
{
	int j;
	for (j = 0; p[j].id != 0; j++)
	{
		if (j >= size)
		{
			cout << "No More Space Available\n";
			return false;
		}
	}
	cout << "Enter ID :";
	cin >> p[j].id;
	cout << "Enter Name :";
	cin >> p[j].name; 
	cout << "Enter Age :";
	cin >> p[j].age;
	cout << "Enter Email :";
	cin >> p[j].email;
	return true;
}

void viewpatient(patient p[])//Next to Last Position to Show
{
	cout << setw(5) << "ID" << setw(12) << "Name" << setw(18) << "Age" << setw(30) << "Email\n";
	for (int j = 0; p[j].id != 0; j++)
	{
		cout << setw(5) << p[j].id << setw(12) << p[j].name << setw(18) << p[j].age << setw(30) << p[j].email << endl;
	}
}

bool searchpatient(patient p[], int checkid)//Total Positions + 1
{
	for (int j = 0; p[j].id != 0; j++)
	{
		if (checkid == p[j].id)
		{
			cout << "ID : " << p[j].id << endl;
			cout << "Name : " << p[j].name << endl;
			cout << "Age : " << p[j].age << endl;
			cout << "Email : " << p[j].email << endl;
			return true;
		}
	}
	cout << "Not found\n";
	return false;
}

void updatepatient(patient p[], int checkid)
{
	for (int j = 0; p[j].id != 0; j++)
	{
		if (checkid == p[j].id)
		{
			cout << "Enter email to modify : ";
			cin >> p[j].email;
			return;
		}
	}
	cout << "Not found\n";
}

void deletepatient(patient p[], int checkid)
{
	for (int j = 0; p[j].id != 0; j++)
	{
		if (checkid == p[j].id)
		{
			for (int i = j; p[i].id != 0; i++)
			{
				p[i].id = p[i + 1].id;
				p[i].name = p[i + 1].name;
				p[i].age = p[i + 1].age;
				p[i].email = p[i + 1].email;
			}
			return;
		}
	}
	cout << "Not found\n";
}

void WriteToFile(patient p[])
{
	ofstream fout;
	fout.open("Patient.txt");
	for (int j = 0; p[j].id != 0; j++)
	{
		//cout << "Printing " << j << endl;
		fout << p[j].id << "\t" << p[j].name << "\t" << p[j].age << "\t" << p[j].email << endl;
	}
	fout.close();
}
