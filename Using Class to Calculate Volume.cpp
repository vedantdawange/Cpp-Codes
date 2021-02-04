#include <iostream> 
using namespace std; 
  
class Cube{
   
    public: 
        float len,bre,hgt,vol;
        
        void getvals(){
        	cout<<"Enter the Value of Length Of Cube :";
        	cin>>len;
        	cout<<"Enter the Value of Breadth Of Cube :";
        	cin>>bre;
        	cout<<"Enter the Value of Height Of Cube :";
        	cin>>hgt;
		}
		
		void calc(){
			vol=len*bre*hgt;
			
		}
		
		void output(){
			calc();
			cout<<"The Volume of the Cube is : "<<vol;
		}
		
};


  
int main() 
{ 
    Cube c1, *t;
    int cont;
    do{
    t=&c1;

    cout<<"\n\n----Volume Calculator of Cube----\n\n";
    t->getvals();
    t->output();
    cout<<"\nDo you wish to continue?(Press 1 For Yes 0 For No) :";
    cin>>cont;
	}while(cont==1);
    return 0; 
} 
