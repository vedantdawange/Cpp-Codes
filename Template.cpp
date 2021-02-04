#include <iostream>
using namespace std;

// template function
template <class T>
T Large(T n1, T n2)
{
	return (n1 > n2) ? n1 : n2;
}

template <typename T>
void Swap(T &n1, T &n2)
{
	T temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}

int main()
{
	int int1, int2,ch,op;
	float flt1, flt2;
	char chr1, chr2,cont;
	cout<<"----2 Operation on 2 Inputs----\n";
	do{
	cout<<"Choose The type of input\n1. Integer\n2. Float\n3. Character\n4. Exit\nEnter Type of your Input: ";
	cin>>ch;
	if(ch==4){
		exit(1);
	}
	cout<<"\n\nChoose The type of Operation\n1. Larger Of 2 Values\n2. Swap the 2 Values\nEnter Type of your Choice: ";
	cin>>op;
	
	
	switch(ch){
		case 1:
			cout << "Enter First Integer (Int1): ";
			cin >> int2;
			cout << "Enter Second Integer (Int2): ";
			cin >> int2;
			if(op==1){
				cout << Large(int1, int2) <<" is larger." << endl;	
			}
			else if(op==2){
				Swap(int1, int2);
				cout << "\nThe Values after Swaping are: \n";
				cout<<"Int1= "<<int1<<"\tInt2= "<<int2;
			}
			else{
				cout<<"\nInvalid Choice...!";
			}
			
			break;
			
		case 2:
			cout << "\nEnter First Float (Flt1): ";
			cin >> flt1;
			cout << "\nEnter Second Integer (Flt2): ";
			cin >> flt2;
			if(op==1){
				cout << Large(flt1, flt2) <<" is larger." << endl;	
			}
			else if(op==2){
				Swap(flt1,flt2);
				cout << "\nThe Values after Swaping are: \n";
				cout<<"Flt1= "<<flt1<<"\tFlt2= "<<flt2;
			}
			else{
				cout<<"\nInvalid Choice...!";
			}
			
			break;
			
		case 3:
			cout << "Enter First Character (Char1): ";
			cin >> chr1;
			cout << "Enter Second Character (Char2): ";
			cin >> chr2;
			if(op==1){
				cout << Large(chr1, chr2) <<" is larger Of the 2 Charactrers." << endl;	
			}
			else if(op==2){
				Swap(chr1,chr2);
				cout << "\nThe Values after Swaping are: \n";
				cout<<"Char1= "<<chr1<<"\tChar2= "<<chr2;
			}
			else{
				cout<<"\nInvalid Choice...!";
			}
			
			break;
			
		default:
			exit(1);
		}
		
		cout<<"\nDo you wish to continue?(Y For Yes / N for No) : ";
		cin>>cont;
		if(cont=='n' || cont=='N'){
			exit(1);
		}
		cout<<"\n\n";
	}while(cont=='y' || cont=='Y')	;
	return 0;
}
