//Built-in Libraries included in program
#include<iostream>//for cout and cin
#include<fstream>//for file handling

//User-defined Libraries(.h files) included in .cpp file
#include"Patient.h"//Handling patient structure and functions 
#include"Doctor.h"//Handling doctor structure and functions 
#include"Appointments.h"//Handling appointments structure and functions 

using namespace std;

const int MAX_SIZE=100;//Maximum size for each structure array
//Initializing structure arrays to zero
doctor d[MAX_SIZE] = { 0 };
patient p[MAX_SIZE] = { 0 };
appointments a[MAX_SIZE] = { 0 };

//Prototypings of funtion defined in .cpp file other than modules
void menu(void);
void doctormenu(void);
void patientmenu(void);
void appointmentsmenu(void);

//main function
int main()
{
	//cout<,"Printing";
	cout << "*** HOSPITAL MANAGEMENT SYSTEM ***" << endl;
	menu();//Calling menu function for main menu to select entities
}

//Definition for function showing doctor menu 
void doctormenu(void)
{
	int id;//Will pass to search or update or delete function after getting value from user 
	while (true)//Infinite loop
	{
		int choice;//Will save user choice
		cout << "Select an option for Doctor Record :";
		cout << "\n1. Add\n2. View\n3. Search\n4. Update\n5. Delete\n6. Exit menu\n";
		cin >> choice;

		switch (choice)//for showing menu 
		{
		case 1:
			adddoctor(d,MAX_SIZE);
			//Calling add function by passing it a structure array and length of this array
			break;
		case 2:
			viewdoctor(d);
			//Calling view function by passing it a structure array
			break;
		case 3:
			cout << "Enter ID you want to search\n";
			cin >> id;
			searchdoctor(d, id);
			//Calling search function by passing it a structure array and the value to search
			break;
		case 4:
			cout << "Enter ID you want to update\n";
			cin >> id;
			updatedoctor(d, id);
			//Calling update function by passing it a structure array and the id of record to be updated
			break;
		case 5:
			cout << "Enter ID you want to delete\n";
			cin >> id;
			deletedoctor(d, id);
			//Calling delete function by passing it a structure array and id to be deleted
			break;
		case 6: 
			return;
		default:
			cout << "Invalid Choice";
		}
	}

}

void patientmenu(void)
{
	int id;//Will pass to search or update or delete function after getting value from user 

	while (true)
	{
		int choice;//Will save user choice
		cout << "Select an option for Patient Record :";
		cout << "\n1. Add\n2. View\n3. Search\n4. Update\n5. Delete\n6. Exit menu\n";
		cin >> choice;

		switch (choice)//for showing menu 
		{
		case 1:
			addpatient(p, MAX_SIZE);
			break;
		case 2:
			viewpatient(p);
			break;
		case 3:
			cout << "Enter ID you want to search\n";
			cin >> id;
			searchpatient(p, id);
			break;
		case 4:
			cout << "Enter ID you want to update\n";
			cin >> id;
			updatepatient(p, id);
			break;
		case 5:
			cout << "Enter ID you want to delete\n";
			cin >> id;
			deletepatient(p, id);
			break;
		case 6:
			return;
		default:
			cout << "Invalid Choice";
		}
	}


}

void appointmentsmenu(void)
{
	int time;
	while (true)
	{
		int choice;
		cout << "Select an option for Appointments Record :";
		cout << "\n1. Add\n2. View\n3. Search\n4. Exit menu\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			addappointments(a, p, d, MAX_SIZE);
			break;
		case 2:
			viewappointments(a);
			break;
		case 3:
			cout << "Enter time you want to search\n";
			cin >> time;
			searchappointments(a, time);
			break;
		case 4:
			WriteToFile(a);
			return;
		default:
			cout << "Invalid Choice";
		}
	}
}

void menu(void)
{
	ReadFromFile(p, MAX_SIZE);//Patient file
	ReadFromFile(d, MAX_SIZE);//Doctor file
	ReadFromFile(a, MAX_SIZE);//Appointments file

	int entity;
	while (true)
	{
		cout << "Select an entity to work on : ";
		cout << "\n1.Patient\n2.Doctor\n3.Appointments\n4.Exit Menu\n";
		cin >> entity;

		switch (entity)
		{
		case 1:
			patientmenu();
			break;
		case 2:
			doctormenu();
			break;
		case 3:
			appointmentsmenu();
			break;
		case 4:
			WriteToFile(p);
			WriteToFile(d);
			WriteToFile(a);
			exit(0);
			break;
		default:
			cout << "Invalid choice!" << endl;
		}
	}
}