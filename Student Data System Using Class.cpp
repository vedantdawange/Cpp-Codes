

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class data
{
	char name[30],dob[15],bg[5],add[30],no[15];
	int height,weight;


	public:

		data()
		{
			strcpy(name,"");
			strcpy(dob,"00-00-0000");
			strcpy(bg,"");
			strcpy(add,"");
			strcpy(no,"");
			height=0;
			weight=0;

		}

		static int count;
		friend class Student;
		static void dispcount()
		{
			cout<<"\n\n\n TOTAL NUMBER OF RECORDS CREATED: "<<count;
		}
};

class Student 
{
	char policy_no[10],license_no[10];
	public:
		Student()
		{
			strcpy(policy_no,"");
			strcpy(license_no,"");
		}

		friend class data;

		void getdata(data *b);
		void putdata(data *b);

};

inline void Student :: getdata(data *b)
{
	cout<<"ENTER THE DETAILS";
	cout<<"\n    --------------------------";
	cout<<"\n\n NAME: ";
	cin.ignore(256,'\n');
	cin.getline(b->name,30);
	cout<<"\nDATE OF BIRTH(DD-MM-YYYY): ";
	cin.getline(b->dob,30);
	cout<<"\nADDRESS: ";
	cin.getline(b->add,30);
	cout<<"\nTELEPHONE NUMBER: ";
	cin.getline(b->no,30);
	cout<<"\nBLOOD GROUP: ";
	cin.getline(b->bg,30);
	cout<<"\nHEIGHT: ";
	cin>>b->height;
	cout<<"\nWEIGHT: ";
	cin>>b->weight;
	cout<<"\nDRIVING LICENSE NUMBER: ";
	cin.ignore(256,'\n');
	cin.getline(this->license_no,30);
	cout<<"\nPOLICY NUMBER: ";
	cin.getline(this->policy_no,30);
	b->count++;
}

inline void Student :: putdata(data *b)
{
	cout<<"\n\n\n--------------------------------------------";
	cout<<"\n\t.... Student DATABASE ....";
	cout<<"\n--------------------------------------------";
	cout<<"\n\n NAME               : "<<b->name;
	cout<<"\n\n DATE OF BIRTH      : "<<b->dob;
	cout<<"\n\n ADDRESS            : "<<b->add;
	cout<<"\n\n TELEPHONE NUMBER   : "<<b->no;
	cout<<"\n\n BLOOD GROUP        : "<<b->bg;
	cout<<"\n\n HEIGHT             : "<<b->height;
	cout<<"\n\n WEIGHT             : "<<b->weight;
	cout<<"\n\n DRIVING LICENSE NO.: "<<this->license_no;
	cout<<"\n\n POLICY NUMBER      : "<<this->policy_no;
}

int data::count=0;

int main()
{
	Student *a[10];
	data *c[10];
	int n=0,i,choice;
	char ans;
	do
	{
		cout<<"\n\nMENU: ";
		cout<<"\n1.Create\n2.Display";
		cout<<"\n\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
		   case 1:
			  do
			  {
				a[n]=new Student;
				c[n]=new data;
				a[n]->getdata(c[n]);
				n++;
				data::dispcount();
				cout<<"\n\nDo you want to add more records?(y/n): ";
				cin>>ans;
			  }while(ans=='y' || ans=='Y');
			  break;

		   case 2:
			  for(int i=0;i<n;i++)
			  a[i]->putdata(c[i]);
			  data::dispcount();
			  break;

		  default:
			  cout<<"\n\nPlease enter correct choice.";
			  break;
		}

	cout<<"\nDo you want to continue?(y/n): ";
	cin>>ans;
	}while(ans=='y' || ans=='Y');
	delete[] a;
	delete[] c;
return 0;
}

