#include<bits/stdc++.h>
const int MAX = 3;
using namespace std;

struct node {
	int data;
	struct node *next[3];
	//int level;
};

struct node * newnode(int data,int levels)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	temp->data= data;
	//temp->level = 0;
	//cout<<"eteresss";
	for(int i=0; i<levels; i++)
	{
	//	cout<<"loop"<<i;
		temp->next[i] = NULL;
	}
	//cout<<"eteres";
	return temp;
}

struct node * insert(struct node *head, int levels, int insertlevel, int data)
{
	struct node *temp = newnode(data,levels);
	struct node *header = head;
	struct node *nex = NULL;
	struct node *heading = head;
	for(int i=levels-1; i>=0; i--)
	{
		header = heading;
		while(header->next[i]!=NULL)
		{
			if(header->next[i]->data>data)
			{
				break;
			}
			header = header->next[i];
		}
		if(i<insertlevel)
		{
			nex = header->next[i];
			header->next[i] = temp;
			temp->next[i] = nex;
		}
		heading = header;
	}
	return head;
}

struct node * del(struct node *head, int levels,int data)
{
	struct node *header = head;
	struct node *next = NULL;
	struct node *heading = head;
	for(int i=levels-1; i>=0; i--)
	{
		header = heading;
		while(header->next[i]!=NULL)
		{
			if(header->next[i]->data >= data)
			{
				break;
			}
			header = header->next[i];
		}
		
		if(header->next[i]->data == data)
		{
			next = header->next[i];
			header->next[i] = header->next[i]->next[i];
			//temp->next[i] = next;
			
		}
		
		heading = header;
		
	}
	//free(next);
	return head;
}

bool search(struct node *head, int levels,int data)
{
	struct node *header = head;
	struct node *next = NULL;
	struct node *heading = head;
	for(int i=levels-1; i>=0; i--)
	{
		header = heading;
		while(header->next[i]!=NULL)
		{
			if(header->next[i]->data >= data)
			{
				break;
			}
			header = header->next[i];
		}
		
		if(header->next[i]->data == data)
		{
			return true;
			
		}
		
		heading = header;
		
	}
	
	return false;
}


void print(struct node *head,int levels)
{
	struct node *temp = head;
	for(int i=levels-1; i>=0; i-- )
	{
		while(temp!=NULL)
		{
			if(temp->data!=-1)
			cout<<temp->data<<"->";
			temp = temp->next[i];
		}
		cout<<endl;
		temp = head;
	}
}


int main()
{
	int levels = MAX;
	//cout<<"Enter the no of levels: ";
	//cin>>levels;
	struct node *head = newnode(-1,levels);    //Initialize head with -1 as the value
	//cout<<endl;
	//print(head,levels);
	cout<<"20 at level 2: \n";
	head = insert(head,levels,2,20);			
	
	print(head,levels);
	head = insert(head,levels,3,5);
	cout<<endl;
	cout<<"5 at level 3: \n";
	print(head,levels);
	
	head = insert(head,levels,1,2);
	cout<<endl;
	cout<<"2 at level 1:\n";
	print(head,levels);
	head = insert(head,levels,2,19);
	cout<<endl;
	cout<<"19 at level 2: \n";
	print(head,levels);
	head = insert(head,levels,2,60);
	cout<<endl;
	cout<<"60 at level 2: \n";
	print(head,levels);
	head = insert(head,levels,3,48);
	cout<<endl;
	cout<<"48 at level 3: \n";
	print(head,levels);
	cout<<endl;
	//cout<<"end";
	cout<<"Deleting  19"<<endl;
	head = del(head,levels,19);
		cout<<endl;
	print(head,levels);
	
	cout<<endl<<"Searching 2: ";
	if(search(head,levels,2))
	{
		cout<<"Found";
	}
	else
	{
		cout<<"Not Found";
	}
	cout<<endl<<"Searching 7: ";
	if(search(head,levels,7))
	{
		cout<<"Found";
	}
	else
	{
		cout<<"Not Found";
	}
	

}