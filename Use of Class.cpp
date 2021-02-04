#include<iostream>
using namespace std;

class Nums{
	public:	float num,deno,result;

};

int main(){
	
	Nums n1;
	//float num,deno,result;
	int cont;
	
	cout<<"Division Calculator";
	
	do{
	cout<<"\nEnter Numerator: ";
	cin>>n1.num;
	cout<<"Enter Denominator: ";
	cin>>n1.deno;
	
	try{
		if (n1.deno==0){
			n1.result =0;
			throw n1.deno;
		}
		
		n1.result= n1.num/n1.deno;
	}
	
	
	catch (float ex){
		cout<<"\nDivision By 'Zero' not Allowed\n";
	}	
	
	cout<<"\nThe Result of Division is : "<<n1.result;
	cout<<"\nDo you wish to Continue (Press 1 For Yes 0 For No): ";
	cin>>cont;
	cout<<"\n\n";
	}while(cont);

	return 0;
}
