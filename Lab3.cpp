#include<iostream>

using namespace std;

int check(int arr[][5], int n, int i, int j, int disjoint[][5])
{
	if(i>0 && arr[i-1][j] == 1 )
	return disjoint[i-1][j];
	else if(j>0 && arr[i][j-1] == 1)
	return disjoint[i][j-1];
	else if(j>0 && i>0 && arr[i-1][j-1] == 1)
	return disjoint[i-1][j-1];
	else if(i>0 && j<n-1 && arr[i-1][j+1] == 1)
	return disjoint[i-1][j+1];
	return -1;
}

int islands(int arr[][5], int n, int disjoint[][5])
{
	int count = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i][j] == 1)
			{
				int num = check(arr,n,i,j,disjoint);
				if(num!=-1)
				{
					disjoint[i][j] = num;
				}
				else
				{
					count++;
					disjoint[i][j] = count;
				}
			}
			
		}
	}
	return count;
}

void print(int arr[][5], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

void printdis(int arr[][5], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i][j]!=0)
			cout<<arr[i][j]<<"\t";
			else
			cout<<" "<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int arr[][5] =  {{1, 1, 0, 0, 0}, 
                    {0, 1, 0, 0, 1}, 
                    {1, 0, 0, 1, 1}, 
                    {0, 0, 0, 0, 0}, 
                    {1, 0, 1, 0, 1}};
    int disjoint[][5] = {{0, 0, 0, 0, 0}, 
                    {0, 0, 0, 0, 0}, 
                    {0, 0, 0, 0, 0}, 
                    {0, 0, 0, 0, 0}, 
                    {0, 0, 0, 0, 0}};
    cout<<"The 2D matrix is: \n";
    print(arr,5);
    
	cout<<"Number of islands is: "<<islands(arr,5,disjoint);
	cout<<endl;
	cout<<endl;
	cout<<"The Islands are as follows: \n";
	printdis(disjoint,5);
	
}