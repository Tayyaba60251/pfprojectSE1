#include <iostream>
#include<stdlib.h>
using namespace std;

struct Patient 
{
    int id;
    string name;
    int age;
    string disease;
};

struct Doctor 
{
    int id;
    string name;
    string specialization;
    string availability;
};

Patient patients[100];                        
Doctor doctors[100];                          
int patientCount=0, doctorCount=0;

void patientManagement();
void addPatient();
void viewPatients();
void updatePatient(); 
void deletePatient();
void doctorManagement();
void addDoctor();
void viewDoctors();
void updateDoctor();
void deleteDoctor();
int main() 
{
    cout<<"\n                                     ====================================\n";
    cout<<"                                         Hospital Management System\n";
    cout<<"                                     ====================================\n\n\n";
    int choice;
    do 
	{
        cout<<"1. Patient Management"<<endl;
        cout<<"2. Doctor Management"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice) 
		{
        case 1:
            patientManagement();
            break;
        case 2:
            doctorManagement();
            break;
        case 3:
            cout<<"\nExiting system...\nThank you!\n";
            abort();
            break;
        default:
            cout<<"\nInvalid choice. Please try again.\n";
        }
    } 
	while (choice != 5);
    return 0;
}

void patientManagement() 
{
    int choice;
    cout<<"\n====================================\n";
    cout<<"   Patient Management\n";
    cout<<"====================================\n";
    do 
	{
        cout<<"1. Add Patient\n";
        cout<<"2. View Patients\n";
        cout<<"3. Update Patient\n";
        cout<<"4. Delete Patient\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
		{
        case 1:
            addPatient();
            break;
        case 2:
            viewPatients();
            break;
        case 3:
            updatePatient();
            break;
        case 4:
            deletePatient();
            break;
        case 5:
        	cout<<"EXITING!!!\n";
        	cout<<"Again move towards hospital management system.\n\n";
            break;
        default:
            cout<<"\nInvalid choice. Please try again.\n";
        }
    } 
	while (choice != 5);
}

void addPatient() 
{
    int numPatients;
    cout<<"\n------------------------------------\n";
    cout<<"How many patients do you want to enter? ";
    cin>>numPatients;
    cout<<"\n------------------------------------\n";
    
    for (int i=0; i<numPatients; i++) 
	{
        cout<<"\nEnter Patient "<<patientCount+1<<" Details:\n";
        cout<<"Patient ID: ";
        cin>>patients[patientCount].id;
        cout<<"Patient Name: ";
        cin.ignore();
        getline(cin, patients[patientCount].name);
        cout<<"Patient Age: ";
        cin>>patients[patientCount].age;
        cout<<"Patient Disease: ";
        cin.ignore();
        getline(cin, patients[patientCount].disease);
        patientCount++;
    }
    cout<<"\nPatient(s) added successfully!\n\n";
}

void viewPatients() 
{
    if (patientCount == 0) 
	{
        cout<<"\n**No patients to display.**\n\n";
        return;
    }
    cout<<"\n------------------------------------\n";
    cout<<"   Patient Details\n";
    cout<<"------------------------------------\n";
    for (int i=0; i<patientCount; i++) 
	{
        cout<<"\nPatient ID: "<<patients[i].id<<endl;
        cout<<"Name: "<<patients[i].name<<endl;
        cout<<"Age: "<<patients[i].age<<endl;
        cout<<"Disease: "<<patients[i].disease<<endl;
    }
    cout<<"\n------------------------------------\n";
}

void updatePatient() 
{
    int id;
    cout<<"\nEnter Patient ID to update: ";
    cin>>id;
    bool found=false;
    for (int i=0; i<patientCount; i++)
	{
        if (patients[i].id == id) 
		{
            cout<<"Enter new name: ";
            cin.ignore();
            getline(cin, patients[i].name);
            cout<<"Enter new age: ";
            cin >>patients[i].age;
            cout<<"Enter new disease: ";
            cin.ignore();
            getline(cin, patients[i].disease);
            found=true;
            cout<<"\nPatient details updated successfully!\n\n";
            break;
        }
    }
    if (!found) 
	{
        cout<<"\nPatient not found.\n\n";
    }
}

void deletePatient() 
{
    int id;
    cout<<"\nEnter Patient ID to delete: ";
    cin>>id;
    bool found=false;
    for (int i=0; i<patientCount; i++) 
	{
        if (patients[i].id == id) 
		{
            for (int j=i; j<patientCount-1; j++) 
			{
                patients[j] = patients[j+1];
            }
            patientCount--;
            found=true;
            cout<<"\nPatient deleted successfully.\n";
            break;
        }
    }
    if (!found) 
	{
        cout<<"\nPatient not found.\n";
    }
}

void doctorManagement()
{
    int choice;
    cout<<"\n====================================\n";
    cout<<"   Doctor Management\n";
    cout<<"====================================\n";
    do 
	{
        cout<<"1. Add Doctor\n";
        cout<<"2. View Doctors\n";
        cout<<"3. Update Doctor\n";
        cout<<"4. Delete Doctor\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) 
		{
        case 1:
            addDoctor();
            break;
        case 2:
            viewDoctors();
            break;
        case 3:
            updateDoctor();
            break;
        case 4:
            deleteDoctor();
            break;
        case 5:
        	cout<<"EXITING!!!\n";
        	cout<<"Again move towards hospital management system.\n\n";
            break;
        default:
            cout<<"\nInvalid choice. Please try again.\n";
        }
    } 
	while (choice != 5);
}

void addDoctor() 
{
    int numDoctors;
    cout<<"\n------------------------------------\n";
    cout<<"How many doctors do you want to enter? ";
    cin>>numDoctors;
    cout<<"\n------------------------------------\n";

    for (int i=0; i<numDoctors; i++) 
	{
        cout<<"\nEnter Doctor "<<doctorCount+1<<" Details:\n";
        cout<<"Doctor ID: ";
        cin>>doctors[doctorCount].id;
        cout<<"Doctor Name: ";
        cin.ignore();
        getline(cin, doctors[doctorCount].name);
        cout<<"Doctor Specialization: ";
        getline(cin, doctors[doctorCount].specialization);
        cout<<"Doctor Availability: ";
        getline(cin, doctors[doctorCount].availability);
        doctorCount++;
    }
    cout<<"\nDoctor(s) added successfully!\n";
}

void viewDoctors() 
{
    if (doctorCount == 0) 
	{
        cout<<"\nNo doctors to display.\n";
        return;
    }
    cout<<"\n------------------------------------\n";
    cout<<"   Doctor Details\n";
    cout<<"------------------------------------\n";
    for (int i=0; i<doctorCount; i++) 
	{
        cout<<"\nDoctor ID: "<<doctors[i].id<<endl;
        cout<<"Name: "<<doctors[i].name<<endl;
        cout<<"Specialization: "<<doctors[i].specialization<<endl;
        cout<<"Availability: "<<doctors[i].availability<<endl;
    }
    cout<<"\n------------------------------------\n";
}

void updateDoctor() 
{
    int id;
    cout<<"\nEnter Doctor ID to update: ";
    cin>>id;
    bool found=false;
    for (int i=0; i<doctorCount; i++) 
	{
        if (doctors[i].id == id) 
		{
            cout<<"Enter new name: ";
            cin.ignore();
            getline(cin, doctors[i].name);
            cout<<"Enter new specialization: ";
            getline(cin, doctors[i].specialization);
            cout<<"Enter new availability: ";
            getline(cin, doctors[i].availability);
            found=true;
            cout<<"\nDoctor details updated successfully!\n\n";
            break;
        }
    }
    if (!found) 
	{
        cout<<"\nDoctor not found.\n\n";
    }
}

void deleteDoctor() 
{
    int id;
    cout<<"\nEnter Doctor ID to delete: ";
    cin>>id;
    bool found=false;
    for (int i=0; i<doctorCount; i++) 
	{
        if (doctors[i].id == id) 
		{
            for (int j=i; j<doctorCount-1; j++) 
			{
                doctors[j] = doctors[j+1];
            }
            doctorCount--;
            found= true;
            cout<<"\nDoctor deleted successfully.\n";
            break;
        }
    }
    if (!found) 
	{
        cout<<"\nDoctor not found.\n";
    }
}

