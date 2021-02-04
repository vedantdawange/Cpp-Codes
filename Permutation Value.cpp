#include <iostream> 
using namespace std;   

int fact(int n)    
{    
	if(n<0)    
		return(-1);     
	if(n==0)    
		return(1);     
	else    
	{    
		return(n*fact(n-1));        
	}    
}  


void permute(string a, int l, int r)  
{  
    if (l == r){
	cout<<a<<endl;	
	}
    else
    { 
        for (int i = l; i <= r; i++)  
        {         	
            swap(a[l], a[i]);  
            
            permute(a, l+1, r);  

            swap(a[l], a[i]);  
        }  
    }  
}  
  
// Driver Code  
int main()  
{  
    string str ; 
    int count;
	char cont;
    do{
    	cout<<"Enter Your String : ";
		cin>>str; 
	    int n = str.size();  
	    permute(str, 0, n-1);  
	    count=fact(n);
		cout<<"Total Number of Combinations : "<<count;
		cout<<"\n\nDo you wish to continue?(Y/N) :";
		cin>>cont;
	}while(cont=='y'|| cont=='Y');
	
    return 0;  
}  
