#include<iostream>
using namespace std; 
void swap(int *a, int *b);
void display(int a[],int n);
void bubblesort(int a[],int n);
void selectionsort(int a[],int n);
void insertionsort(int a[],int n);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high); 
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixsort(int arr[], int n); 
int main()
{
   int n,choice,i;
   cout<<"Sorting Town Population by locality \n";
   cout<<"Enter no. of Town localities you want to sort : ";
   cin>>n;
   int arr[n];
   for(i=0;i<n;i++)
   {
        cout<<"Population of Locality "<<i+1<<": ";
        cin>>arr[i];
   }
   cout<<"Select the sort you want to perform : \n";
 
while(1)
   {
    cout<<"\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Radix Sort\n6. Exit \nEnter your Choice : \n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        bubblesort(arr,n);
        break;
    case 2:
        selectionsort(arr,n);
        break;
    case 3:
        insertionsort(arr,n);
        break;
    case 4:
 		quickSort(arr,0,n-1);
 		cout<<"After Quick sort , population in ascending order is :";
 		display(arr,n);
        break;
    case 5:
        radixsort(arr, n);
        cout<<"After Radix sort , population in ascending order is : ";
 		display(arr,n);
 		break;
 	case 6:
	 	cout<<"Exiting now...";
		exit(0);
		break;	
    default:
        cout<<"\nInvalid Choice \n";
    }
}
return 0;
}

void swap(int *a, int *b) 
{ 
	int t;
    t = *a; 
    *a = *b; 
    *b = t; 
}  

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
   {
        cout<<arr[i]<<" ";
   }
 
}
 
void bubblesort(int arr[],int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
        	swap(&arr[j],&arr[j+1]);
        }
    }
  }
cout<<"After Bubble sort , populaton in ascending order is : ";
display(arr,n);
}
 
void selectionsort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
            swap(&arr[i],&arr[i+1]);	
            }
        }
 
    }
cout<<"After Selection sort , population in ascending order is : ";
display(arr,n);
}
 
void insertionsort(int arr[],int n)
{
    int i,j,min;
    for(i=1;i<n;i++)
    {
        min=arr[i];
        j=i-1;
        while(min<arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=min;
    }
cout<<"After Insertion sort , population in ascending order is : ";
display(arr,n);
} 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
	}	 
} 

int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

void countSort(int arr[], int n, int exp) 
{ 
    int output[n];
    int i, count[10] = { 0 }; 
  
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
        
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 

    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

void radixsort(int arr[], int n) 
{ 
    int m = getMax(arr, n); 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
