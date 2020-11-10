#include<iostream>
#include<fstream>
using namespace std;
int static no=0;
class car
{
	public:
	int vehicle_number;
	float count;
	char  driver_name[15],yes_no,time_slot[50];
	void user_ip()
	{
		system("clear");
			int dn;
		cout<<"\n\n\t\tEnter the name of driver : ";
		cin>>driver_name;
		cout<<"\n\n\t\tEnter the car no : ";
		cin>>vehicle_number;
		cout<<"\n\n\t\tEnter the no of hours of stay : ";
		cin>>count;
		cout<<"\n\n\t\tEnter the time slot : ";
		cin>>time_slot;

		//no of hours is less than 8 and no of cars
		if(dn<20&&count<8)
   			{
   				cout<<"\n\n\t\tParking Available! You can park your car. ";
                no=+1;
   			}
   			else
   				cout<<"\n\n\t\t Parking is not possible!!";
   			cout<<"\n\n\t\tYour Car is parked!!";
		
	}
	
	

	
	
	
	void details()//print the details
	{
		cout<<"\n\n\t\tThe Driver Name : "<<driver_name<<endl;
		cout<<"\n\n\t\tThe Car No : "<<vehicle_number<<endl;
		cout<<"\n\n\t\tThe Hours Of Stay : " <<count;
		cout<<"\n\n\t\tThe Time Slot Of Parking : " <<time_slot;
	
	}
	

		
}a,a1;



void parking_delete()
{
	int depart;
	system("clear");
	cout<<"\n\n\t\tEnter the car no you want to get depart : ";
	cin>>depart;
	ifstream inFile;
    inFile.open("parking3.dat", ios::binary);
	ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary); 
    while(inFile.read((char*)&a, sizeof(a)))
    {
        if(a.vehicle_number!= depart)
        {	
        	
            outFile.write((char*)&a, sizeof(a));
        }
         
    }
    cout<<"\n\n\t\t Parking Record Deleted";
	no=-1;

    inFile.close();
    outFile.close();
    
    remove("parking3.dat");
    rename("temp.dat", "parking3.dat");
}