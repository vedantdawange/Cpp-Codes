#include<iostream>
using namespace std;
	class node
	{
		public:
		int price;	
	    string item;
	    node *next;
	    node *prev;
	};

	class double_llist
	{
	    public:
	        node* start = NULL;
	        void createlist(char value[], int price);
	        void addbegin(char value[], int price);
	        void addafter(char value[], int position, int price);
	        void deleteelement(char value[]);
	        void searchelement(char value[]);
	        void displaydlist();
	        void total();
	        void Sort();  
	        
	};

	int main()
	{
	    int choice, price, position;
	    char element[20];
	    double_llist dl;
	    cout<<endl<<"--------------------"<<endl;
	    cout<<endl<<" Welcome To D-Mart! "<<endl;
	    cout<<endl<<"--------------------"<<endl;
	    while (1)
	    {         
	        cout<<"1.Create Shopping List"<<endl;
	        cout<<"2.Add at Item begining"<<endl;
	        cout<<"3.Add after an Item"<<endl;
	        cout<<"4.Delete an Item from List"<<endl;
	        cout<<"5.Display the List"<<endl;
	        cout<<"6.Payable Amount"<<endl;
	        cout<<"7.Sorting the list"<<endl;
	        cout<<"8.Quit"<<endl;
	        cout<<"Enter your choice : ";
	        cin>>choice;
	        switch (choice)
	        {
	        case 1:
	            cout<<"Enter the Item name: ";
	            cin>>element;
	            cout<<"Enter the Price: ";
	            cin>>price;
	            dl.createlist(element,price);
				cout<<endl;
	            break;
	        case 2:
	            cout<<"Enter the Item name: ";
	            cin>>element;
	            cout<<"Enter the Price: ";
	            cin>>price;
	            dl.addbegin(element,price);
	            cout<<endl;
	            break;
	        case 3:
	            cout<<"Enter the Item name: ";
	            cin>>element;
	            cout<<"Enter the Price: ";
	            cin>>price;
                cout<<"Insert postion after which Item is to be inserted: ";
                cin>>position;
	            dl.addafter(element, position, price);
	            cout<<endl;
	            break;
	        case 4:
	            cout<<"Enter the Item name to be deleted: ";
	            cin>>element;
	            dl.deleteelement(element);
	            cout<<endl;
	            break;
	        case 5:
	            dl.displaydlist();
	            cout<<endl;
	            break;
	        case 6:
	        	dl.displaydlist();
	            dl.total();
	            break;    
	        case 7:
	            dl.Sort();
	            dl.displaydlist();
	            cout<<endl;
	            break;
	        case 8:
	            exit(1);
	        default:
	            cout<<"Wrong choice"<<endl;
	        }
	    }
	    return 0;
	}
	 
	void double_llist::createlist(char value[], int price)
	{
	    node *s, *temp;
	    temp = new(node); 
	    temp->item = value;
	    temp->price = price;
	    temp->next = NULL;
	    if (start == NULL)
	    {
	        temp->prev = NULL;
	        start = temp;
	    }
	    else
	    {
	        s = start;
	        while (s->next != NULL)
	            s = s->next;
	        s->next = temp;
	        temp->prev = s;
	    }
	}
	 
	void double_llist::addbegin(char value[], int price)
	{
	    if (start == NULL)
	    {
	        cout<<"Sorry, No Items found."<<endl;
	        return;
	    }
	    node *temp;
	    temp = new(node);
    	temp->prev = NULL;
	    temp->item = value;
	    temp->price = price;
	    temp->next = start;
	    start->prev = temp;
	    start = temp;
	    cout<<"Item Inserted!"<<endl;
}
	 

	void double_llist::addafter(char value[], int pos, int price)
	{
	    if (start == NULL)
	    {
	        cout<<"Sorry, No Items found."<<endl;
	        return;
	    }
	    node *tmp, *q;
	    int i;
        q = start;
	    for (i = 0;i < pos - 1;i++)
	    {
	        q = q->next;
	        if (q == NULL)
	        {
	            cout<<"There are less than ";
	            cout<<pos<<" Items in your list."<<endl;
	            return;
	        }
	    }
	    tmp = new(node);
	    tmp->item = value;
	    tmp->price = price;
	    if (q->next == NULL)
	    {
	        q->next = tmp;
	        tmp->next = NULL;
	        tmp->prev = q;      
	    }
	    else
	    {
        	tmp->next = q->next;
	        tmp->next->prev = tmp;
	        q->next = tmp;
	        tmp->prev = q;
	    }
	    cout<<"Item Inserted"<<endl;
}

	void double_llist::deleteelement(char value[])
	{
	    node *tmp, *q;
     /*first element deletion*/
     if(start == NULL)
	    {                      
	        cout<<"Sorry, No Items found."<<endl;  
	    }
	    if (start->item == value)
    {
	        tmp = start;
	        start = start->next;  
        start->prev = NULL;
	        cout<<"Item Deleted"<<endl;
	        delete(tmp);
        return;
	    }
	    q = start;
	    while (q->next->next != NULL)
	    {   
	        /*Element deleted in between*/
	        if (q->next->item == value)  
	        {
	            tmp = q->next;
	            q->next = tmp->next;
            tmp->next->prev = q;
	            cout<<"Item Deleted"<<endl;
	            delete(tmp);
	            return;
	        }
	        q = q->next;
	    }
	     /*last element deleted*/
	    if (q->next->item == value)    
	    { 	
	        tmp = q->next;
	        delete(tmp);
	        q->next = NULL;
	        cout<<"Item Deleted"<<endl;
        return;
	    }
	    cout<<"Item "<<value<<" not found"<<endl;
	}

	void double_llist::displaydlist()
	{
		int length=0, i=1;
	    node *q;
	    if (start == NULL)
	    {
      cout<<"List empty,nothing to display"<<endl;
	        return;
	    }
	    q = start;
	    cout<<"----------------------"<<endl; 
	    cout<<"Your Shopping List is :"<<endl;
	    while (q != NULL)
	    {
	        cout<<i<<")"<<"Item:"<<q->item<<" Price,Rs. "<<q->price<<endl;
	        q = q->next;
	        length++;
	        i++;
	    }
	    cout<<"No. of Items in your list are "<<length<<endl;
	    cout<<"----------------------"<<endl; 
	}

	void double_llist::total()
	{ 	
	    node *q = start;
        int sum=0;
	    while (q != NULL)
	    {
	    	sum=sum + q->price;
	        q = q->next;
	    }
	cout<<"----------------------"<<endl;    
	cout<<"Payable Amount is Rs. "<<sum<<endl;    
    cout<<"----------------------"<<endl; 
	}
	 
 
void double_llist::Sort() 
{ 
    node* temp = start; 
  
    // Traverse the List 
    while (temp) { 
        node* min = temp; 
        node* r = temp->next; 
  
        // Traverse the unsorted sublist 
        while (r) { 
            if (min->price > r->price) 
                min = r; 
  
            r = r->next; 
        } 
  
        // Swap Data 
        int x = temp->price; 
        temp->price = min->price; 
        min->price = x; 
        temp = temp->next; 
    } 
} 
