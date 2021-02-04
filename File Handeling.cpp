#include <iostream>
#include <fstream>
 
using namespace std;
 

class student
{
    private:
        char name[30];
        int age;
        
    public:
    	
        void getData()
        { 
			cout<<"Enter name:"; 
			cin.getline(name,30);
        	cout<<"Enter age:"; 
			cin>>age;
        }
 
        void showData()
        {
        	cout<<"Name: "<<name<<"\nAge: "<<age<<endl;
        }
};
 
int main()
{
    student s;
	int count;     
    ofstream file;
 

    file.open("StudentInfo.txt",ios::out);
    
	if(!file)
    {
      cout<<"Error in creating file.."<<endl;
      return 0;
    }
    
	cout<<"\nFile created successfully."<<endl;
	

    s.getData();   
    file.write((char*)&s,sizeof(s));    
 
    file.close();   
    cout<<"\nFile saved and closed succesfully."<<endl;
 
    
    ifstream file1;
    
    file1.open("StudentInfo.txt",ios::in);
    if(!file1){
        cout<<"Error in opening file..";
        return 0;
    }
  
    file1.read((char*)&s,sizeof(s));
 
    
    s.showData();

    file1.close();
     
    return 0;
}
