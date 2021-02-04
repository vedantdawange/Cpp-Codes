#include<iostream>
#include<string>
#include<sstream>
#define size 100

using namespace std;

class Stack{
	public:
		string stack[size];
		int top;
		
		Stack()
		{
			top = -1;
		}
		
		bool Stack_full()
		{
			if(top == size-1) return true;
			else return false;
		}
		
		bool Stack_empty()
		{
			if(top == -1) return true;
			else return false;
		}
		
		void push(string Str_1)
		{
			if(Stack_full())
			cout<<"Stack is full ";
			else
			{
				top++;
				stack[top] = Str_1;
			}
		}
		
		string pop(){
			string comment = "Stack is empty ";
			if(Stack_empty())
			{
				top--;
				return comment;
			}
			else{
				string Str_1 = stack[top];
				top--;
				return Str_1;
			}
		}
};

class Expression{
	public:
	string postfix;
	string infix;
	Stack Str_1;
	bool isOperator(char x)
	{
		if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	
	
	void postfix_evaluation()
	{
		char arr_1[100];
		int arr_2[100];
		int ctr = 0;
		int i,j;
		string postfix;
		cout<<"\nEnter the postfix expression : ";
		cin>>postfix;
		for(i=0;i<postfix.length();i++)
		{
			if(isOperator(postfix[i])){
				int ans;
				int t2,t1;
				string t_2 = Str_1.pop();
				string t_1 = Str_1.pop();
				stringstream change_2(t_2);
				stringstream change_1(t_1);
				change_2>>t2;
				change_1>>t1;
				if(postfix[i]=='+') ans = t1+t2;
				else if(postfix[i]=='-')
					 ans = t1-t2;
				else if(postfix[i]=='/') 
					ans = t1/t2;
				else if (postfix[i]=='*') 
					ans = t1*t2;
				else if(postfix[i]=='^') 
					ans = t1^t2;
				ostringstream ans_1;
				ans_1<<ans;
				string ans__1 = ans_1.str();
				Str_1.push(ans__1);
			}
			else
			{
				if(isdigit(postfix[i]))
				{
					Str_1.push(string(1,postfix[i]));
				}
			}
		}
		string result = Str_1.pop();
		cout<<"\nThe answer of postfix evaluation : "<<result<<endl;
	}
};


int main()
{
Expression E1;

	cout<<"Postfix evaluation ";
	E1.postfix_evaluation();

return 0;
}
