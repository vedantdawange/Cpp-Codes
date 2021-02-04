#include<iostream>
using namespace std;
const int MAX=50;
class StudentExam
{
	int marks[MAX];
	int n;
public:
	int sentinelSearch(int val);
	int binarySearch(int val);
	void accept(int num);
	void display();
	int fibo(int j);
	int fibSearch(int val);

};

void StudentExam::accept(int num)
{
	n=num;
	cout<<"\nEnter "<<num<<" Student's Marks: \n";
	for(int i=0;i<n;i++)
	{
		cin>>marks[i];
	}
}

void StudentExam::display()
{
	cout<<"\nMarks scored by Students Are:\n ";
	for(int i=0;i<n;i++)
	{
		cout<<marks[i]<<"\t";
	}
}

int StudentExam::sentinelSearch(int val)
{
	int i;
	marks[n]=val;
	for(i=0;marks[i]!=val;i++)
	{
		;
	}
	if(i<n)
		return (i+1);
	else
		return 0;
}

int StudentExam::binarySearch(int val)
{
	int mid;
	int low=0;
	int high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(val==marks[mid])
		{
			return (mid+1);
		}
		if(val<marks[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return 0;
}

int StudentExam::fibo(int j)
{
	if(j==0)
		return 0;
	if(j==1)
		return 1;
	else
		return ((fibo(j-1))+(fibo(j-2)));
}

int StudentExam::fibSearch(int val)
{
	int f1,f2,j,mid;
	j=1;
	while(fibo(j)<=n)
		j++;


	f1=fibo(j-2);
	f2=fibo(j-3);
	mid=n-f1+1;

	while(val!=marks[mid])
	{
		if(val>marks[mid])
		{
			if(f1==1)
				break;
			mid=mid+f2;
			f1=f1-f2;
			f2=f2-f1;
		}
		else
		{
			if(f2==0)
				break;
			mid=mid-f2;
			int temp=f1-f2;
			f1=f2;
			f2=temp;
		}
	}
	if(marks[mid]==val)
		return (mid+1);
	else
		return 0;
}

int main()
{
	StudentExam s;
	int choice;
	int val,n;
	cout<<"Program to search Student's Marks";
	do
	{
		cout<<"\n\nChoose the searching method:";
		cout<<"\n1. Sentinel Search\n2. Binary Search\n3. Fibonacci Search\n4. Exit";
		cout<<"\nEnter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"\nEnter Number of Marks to entered ";
			cin>>n;
			s.accept(n);
			cout<<"\nEnter the score to be searched ";
			cin>>val;
			if(s.sentinelSearch(val))
				cout<<"\nPosition of "<<val<<" is "<<s.sentinelSearch(val)<<endl;
			else
				cout<<"\nScore "<<val<<" not found";
			break;
			
		case 2:
			cout<<"\nEnter Number of Marks to entered ";
			cin>>n;
			s.accept(n);
			cout<<"\nEnter the score to be searched ";
			cin>>val;
			if(s.binarySearch(val))
				cout<<"\nPosition  of "<<val<<" is  "<<s.binarySearch(val)<<endl;
			else
				cout<<"\nScore "<<val<<" not found";
			break;
			
		case 3:
			cout<<"\nEnter Number of Marks to entered : ";
			cin>>n;
			s.accept(n);
			cout<<"\nEnter the score to be searched : ";
			cin>>val;
			if(s.fibSearch(val))
				cout<<"\nPosition of "<<val<<" is "<<s.fibSearch(val)<<endl;
			else
				cout<<"\nScore "<<val<<" not found";
			break;
			
		case 4: 
			exit(0); 
			break;	
			
		default:
			cout<<"Invalid Choice";	
		}

	}while(choice!=4);


	return 0;
}
