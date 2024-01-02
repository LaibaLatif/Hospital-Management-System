#pragma once
#include<iostream>
#include<fstream>
using namespace std;
struct doctor
{
	int id;
	string name;
	int age;
	float WorkingHours;
};

void ReadFromFile(doctor d[], int size)
{
	ifstream fin;
	fin.open("Doctor.txt");//Exception Handling remaining
	int i = 0;
	while (fin >> d[i].id >> d[i].name >> d[i].age >> d[i].WorkingHours)
	{
		i++;
	}
	fin.close();
}

void adddoctor(doctor d[], int size)//Position where to be added
{
	int j;
	for (j = 0; d[j].id != 0; j++)
	{
		if (j >= size)
		{
			cout << "No More Space Available\n";
			return;
		}
	}
	cout << "Enter ID :";
	cin >> d[j].id;
	cout << "Enter Name :";
	cin >> d[j].name;
	cout << "Enter Age :";
	cin >> d[j].age;
	cout << "Enter Working hours :";
	cin >> d[j].WorkingHours;
}

void viewdoctor(doctor d[])//Next to Last Position to Show
{
	cout << setw(5) << "ID" << setw(12) << "Name" << setw(18) << "Age" << setw(30) << "Working Hours\n";
	for (int j = 0; d[j].id != 0; j++)
	{
		cout << setw(5) << d[j].id << setw(12) << d[j].name << setw(18) << d[j].age << setw(30) << d[j].WorkingHours << endl;
	}
}

bool searchdoctor(doctor d[], int checkid)//Total Positions + 1
{
	for (int j = 0; d[j].id != 0; j++)
	{
		if (checkid == d[j].id)
		{
			cout << "ID : " << d[j].id << endl;
			cout << "Name : " << d[j].name << endl;
			cout << "Age : " << d[j].age << endl;
			cout << "Working Hours : " << d[j].WorkingHours << endl;
			return true;
		}
	}
	cout << "Not found\n";
	return false;
}

void updatedoctor(doctor d[], int checkid)
{
	for (int j = 0; d[j].id != 0; j++)
	{
		if (checkid == d[j].id)
		{
			cout << "Enter working hours to modify : ";
			cin >> d[j].WorkingHours;
			return;
		}
	}
	cout << "Not found\n";
}

void deletedoctor(doctor d[], int checkid)
{
	for (int j = 0; d[j].id != 0; j++)
	{
		if (checkid == d[j].id)
		{
			for (int i = j; d[i].id != 0; i++)
			{
				d[i].id = d[i + 1].id;
				d[i].name = d[i + 1].name;
				d[i].age = d[i + 1].age;
				d[i].WorkingHours = d[i + 1].WorkingHours;
			}
			return;
		}
	}
	cout << "Not found\n";
}

void WriteToFile(doctor d[])
{
	ofstream fout;
	fout.open("Doctor.txt");
	for (int j = 0; d[j].id != 0; j++)
	{
		//cout << "Printing " << j << endl;
		fout << d[j].id << "\t" << d[j].name << "\t" << d[j].age << "\t" << d[j].WorkingHours << endl;
	}
	fout.close();
}
