#pragma once
#include<iostream>
#include<fstream>
#include"Doctor.h"
#include"Patient.h"
using namespace std;
struct appointments
{
	doctor dr;
	patient pt;
	int time;
	float fees;
};

void ReadFromFile(appointments a[], int size)
{
	ifstream fin;
	fin.open("Appointments.txt");//Exception Handling remaining
	int i = 0;
	while (fin >>a[i].pt.id >> a[i].dr.id >> a[i].time >> a[i].fees)
	{
		i++;
	}
	fin.close();
}

void addappointments(appointments a[],patient p[], doctor d[], int size)
{
	int j, id;
	for (j = 0; a[j].pt.id != 0; j++)
	{
		if (j >= size)
		{
			cout << "No More Space Available\n";
			return;
		}
	}
	cout << "Enter Patient ID :";
	cin >> id;
	bool flag1 = searchpatient(p, id);
	if (flag1 == false)
	{
		char decide;
		cout << "Patient not found ";
		cout << "\nEnter y to add patient record\n";
		cin >> decide;
		if (decide == 'y')
		{
			bool flag2 = addpatient(p, size);
			if (flag2 == false)
			{
				cout << "Fail to add Record\n";
				return;
			}
		}
		else
		{
			cout << "Fail to add Record\n";
			return;
		}
	}
	a[j].pt.id = id;
	cout << "Enter Doctor ID :";
	cin >> id;
	flag1 = searchdoctor(d, id);
	if (flag1 == false)
	{
		cout << "Doctor not found\nFail to add record\n";
		a[j].pt.id = 0;
		return;
	}
	a[j].dr.id = id;
	cout << "Enter Time :";
	cin >> a[j].time;
	cout << "Enter Fees :";
	cin >> a[j].fees;
}

void viewappointments(appointments a[])
{
	cout << setw(5) << "Patient ID" << setw(12) << "Doctor ID" << setw(18) << "Time" << setw(30) << "Fees\n";
	for (int j = 0; a[j].pt.id != 0; j++)
	{
		cout << setw(5) << a[j].pt.id << setw(12) << a[j].dr.id << setw(18) << a[j].time << setw(30) << a[j].fees << endl;
	}
}

void searchappointments(appointments a[],int time)
{
	for (int j = 0; a[j].time != 0; j++)
	{
		if (time == a[j].time)
		{
			cout << "Patient ID : " << a[j].pt.id << endl;
			cout << "Doctor ID : " << a[j].dr.id << endl;
			cout << "Time : " << a[j].time << endl;
			cout << "Fees : " << a[j].fees << endl;
			return;
		}
	}
	cout << "Not found\n";
}

void WriteToFile(appointments a[])
{
	ofstream fout;
	fout.open("Appointments.txt");
	for (int j = 0; a[j].pt.id != 0; j++)
	{
		//cout << "Printing " << j << endl;
		fout << a[j].pt.id << "\t" << a[j].dr.id << "\t" << a[j].time << "\t" << a[j].fees << endl;
	}
	fout.close();
}