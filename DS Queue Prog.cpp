#include<iostream>
//#include<stdlib.h> 
using namespace std;
class cqueue
{
   int q[5],front,rear;
   public:
      cqueue()
      {
         front=-1;
         rear=-1;
      }
      void push(int x)
      {
         if(front ==-1 && rear == -1)
         {
           q[++rear]=x;
           front=rear;
           return;
         }
         else if(front == (rear+1)%5 )
         {
            cout <<" Circular Queue over flow";
            return;
         }
         rear= (rear+1)%5;
         q[rear]=x;
     }
 
     void pop()
     {
        if(front==-1 && rear==  -1)
        {
          cout <<"under flow";
          return;
        }
        else if( front== rear  )
        {
          front=rear=-1;
          return;
        }
        front= (front+1)%5;
     }
 
 
 
 
 void display()
    {
      int i;
      if( front <= rear)
      {
        for(i=front; i<=rear;i++)
        cout << q[i]<<" ";
      }
      else
      {
         for(i=front;i<=4;i++)
         {
           cout <<q[i] << " ";
         }
         for(i=0;i<=rear;i++)
         {
            cout << q[i]<< " ";
         }
      }
    }
};

class queue
{
  public:
  int q[5],front,rear,x,result;
  void enq();
  void dque();
  void disp();
  queue()
  {
    front=0;
    rear=0;
  }
};
void queue::enq()
{
  if(rear>=5)
  cout<<"\nQueue overflow!!\n";
  else
  {
    cout<<"\nEnter Item No. to be added: ";
    cin>>x;
    rear++;
    q[rear]=x;
  }
}
void queue::dque()
{
  if(rear==0)
  cout<<"\nQueue underflow!!\n";
  else
  {
    if(front==rear)
    {
      front=0;
      rear=0;
    }
    else
      front++;
  }
  result=q[front];
  cout<<result;
}
void queue::disp()
{
	
  if(rear==0)
    cout<<"\nQueue underflow!!\n";
  else
    cout<<"\nItems in Your Cart :";
  for(int i=front+1;i<=rear;i++)
    cout<<q[i]<<"\t";
} 

class Node{
	public:
    int data;
    Node *next;
};
 
class Queuell{
    public:
    Node *front,*rear;
    Queuell(){front=rear=NULL;}
 
    void insert(int n);
    void deleteitem();
    void display();
    Queuee();
};
 
void Queuell::insert(int n){
    Node *temp=new Node;
    if(temp==NULL){
        cout<<"Overflow"<<endl;
        return;
    }
    temp->data=n;
    temp->next=NULL;
 
    //for first node
    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}
 
void Queuell::display(){
    if(front==NULL){
        cout<<"Underflow."<<endl;
        return;
    }
    Node *temp=front;
    //will check until NULL is not found
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
 
void Queuell :: deleteitem()
    {
    if (front==NULL){
        cout<<"underflow"<<endl;
        return;
    }
    if(front==rear)//if only one node is there
        front=rear=NULL;
    else
        front=front->next;
}
 
Queuell ::Queuee()
{
    while(front!=NULL)
    {
        Node *temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
}

class node
{
public:
    node()
    {
        next = NULL;
    }
  int data;
  node *next;
}*front=NULL,*rear=NULL,*n,*temp,*temp1;

class circularqueue
{
public:
    void insertion()
{
  n=new node[sizeof(node)];
  cout<<"\nEnter Item No.: ";
  cin>>n->data;
  if(front==NULL)
  {
      front=n;
  }
  else
  {
      rear->next=n;
  }
  rear=n;
  rear->next=front;
}

void deletion()
{
  int x;
  temp=front;
  if(front==NULL)
  {
      cout<<"\nCart is Empty!!!";
  }
  else
  {
     if(front==rear)
     {
       x=front->data;
       delete(temp);
       front=NULL;
       rear=NULL;
     }
     else
     {
        x=temp->data;
        front=front->next;
        rear->next=front;
        delete(temp);
     }
     display();
  }
}

void display()
{
  temp=front;
  temp1=NULL;
  if(front==NULL)
  {
    cout<<"\nCart is Empty!!!";
  }
  else
  {
    cout<<"\nItems in Cart are:";
    while(temp!=temp1)
    {
       cout<<temp->data<<"  ";
       temp=temp->next;
       temp1=front;
    }
  }
}
};

int main()
{
	int choice,a;
cout<<"--------Welcome to Uber Eats!-------\n";
cout<<"1. Order a Pizza.\n2.Order a Burger.\n";
cout<<"\nEnter Your Choice: ";
cin>>choice;
switch(choice){
	case 1:
		{
		cout<<"1.Order from Domino's\n2.Order from Pizza Hut\n";
		cout<<"Enter Your Choice :";
		cin>>a;
		switch(a){
			case 1:
				{
				//Using Circular Queue In an Array
				int ch;
				cqueue q1;
				cout<<"\nDomino's Menu\n1. Margherita\n2. Garlic cheese burst\n3. Peppy Paneer\n4. Tandoori Paneer\n";
				while(1)
				{
				cout<<"\n1.Add to Cart\n2.Remove First Item from Cart\n3.View Cart\n4.Place Order\nEnter choice: ";
				cin >> ch;
				switch(ch)
				{
				case 1: cout<<"Enter Item No. ";
				        cin >> ch;
				        q1.push(ch); break;
				 
				case 2: q1.pop(); break;
				case 3: {
					cout<<"\nItems in your cart: ";
				q1.display();
				}
				break;
				case 4: 
				{cout<<"Order Placed! Ariving At your doorstep Soon!";
				exit(0);}
				}
				}
			}
				break;
			case 2:
				{
				//Using Linear Queue In an Array
				int c;
				queue qu;
			  	cout<<"Pizza Hut Menu\n1. Cheese Corn\n2. Pepeeroni Cheese\n3.  Veg Extraveganza\n4. Cheese Chilli Chicken\n";
			  	do
			  	{
			  	cout<<"\n1.Add to Cart\n2.Remove First Item from Cart\n3.View Cart\n4.Place Order\nEnter choice: ";
			    cin>>c;
			    switch(c)
			    {
			      case 1:
			    qu.enq();
			    break;
			      case 2:
			    qu.dque();
			    break;
			      case 3:	
			    qu.disp();
			    break;
			    	case 4:
			    		{
						cout<<"Order Placed! Ariving At your doorstep Soon!";
			    		exit(0);
			      default:
			    cout<<"\nInvalid choice!!\n";
			    }
			  }
			}
				  while(c<4);				
		}
		break;
		default:
			cout<<"\nInvalid choice!!\n";
	}
}
break;
case 2:
	{
		cout<<"1. Order from Burger King\n2. Order from Mc. Donalds\n";
		cin>>a;
		switch(a){
			case 1:
				{
					//Using Linear Queue in a Linked List
					Queuell Q;
					int chh,ele;
					cout<<"Burger King Menu\n1. Burger King Special\n2. Grilled Cheese Burger\n3. Spicy Chicken Burger\n4. Paneer Schewan Burger\n";
					while(1)
					{
					cout<<"\n1.Add to Cart\n2.Remove First Item from Cart\n3.View Cart\n4.Place Order\nEnter choice: ";
					cin >> chh;
					switch(chh)
					{
					case 1: cout<<"Enter Item No.";
					        cin >> ele;
					        Q.insert(ele); break;			 
					case 2: Q.deleteitem(); break;
					case 3: {
						cout<<"\nItems in your cart: ";
					Q.display();
					}
					break;
					case 4: 
					{
					cout<<"Order Placed! We'll get it delivered ASAP!";
					exit(0);
					}
					}
				}
		}
		break;
		case 2:
			{
				//Using Circular Queue In Lined List
				circularqueue cqobj;
				  int ch;
				  cout<<"Mc Donalds Menu\n1. Aloo Tiki Burger to your cart \n2. Chicken Grilled Burger\n3. Mexican Paneer Burger\n4. Veg Maharaja Mac\n";
				  do
				  {
				     cout<<"\n1.Add to Cart\n2.Remove First Item from Cart\n3.View Cart\n4.Place Order\nEnter choice: ";
				     cin>>ch;
				     switch(ch)
				     {
				        case 1:
				          cqobj.insertion();
				          cqobj.display();
				          break;
				        case 2:
				          cqobj.deletion();
				          break;
				        case 3:						
				          cqobj.display();
				          break;
				        case 4:
				        	{
							cout<<"Order Placed! Ariving At your doorstep Soon!";
				        	exit(0);
						}
				          break;
				        default:
				          cout<<"\nInvalid Choice!!!";
				     }
				  }while(ch!=4);
			}
		break;
	}
}
break;
default:
cout<<"Invalid Choice";
}
return 0;
}

