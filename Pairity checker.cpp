
#include <iostream>
using namespace std; 

long int ASCIIconvert(string str) 
{ 
    int l = str.length(); 
    int convert; 
    for (int i = 0; i < l; i++) { 
        convert = str[i] - NULL; 
        cout << convert; 
    } 
    return convert;
} 


bool getParity(unsigned int n) 
{ 
    bool parity = 0; 
    while (n) 
    { 
        parity = !parity; 
        n     = n & (n - 1); 
    }      
    return parity; 
} 


int main() 
{ 
    string str ; 
    long int ascii;
    char cont;
    do {
    	
    	cout<<"Enter Your String : ";
		cin>>str;
	    cout << "ASCII Equavalent of the String: "; 
	    ascii=ASCIIconvert(str); 
	    cout<<"\n\n"<<ascii;
	    cout<<"\nParity of ASCII Equivalent of the String "<<str<<"  = "<<(getParity(ascii)? "odd": "even"); 
	    cout<<"\nDo you wish to Continue? (Y/N) : ";
	    cin>>cont;
	}while (cont=='y' || cont=='Y');
	
    return 0; 
} 
