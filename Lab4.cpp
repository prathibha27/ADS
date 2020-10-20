#include<iostream>

using namespace std;

//AVL Tree (Insertion and Deletion)

class node
{
	public:
	int data;
	node *left;
	node *right;
	node(int val)																			//Constructor 
	{
		data = val;
		left = NULL;
		right  = NULL;
	}
};


int height(node *head)																		//To get the height of the node
{
	if(head==NULL)
		return 0;
	int leftHeight = 1, rightHeight = 1;
	leftHeight += height(head->left);
	rightHeight += height(head->right);
	if(leftHeight>rightHeight)
		return (leftHeight);
	return (rightHeight);
}

node *leftRotate(node *head)																//Left Rotate Function
{
	node *child = head->right;
	node *grandChild = head->right->left;
	child->left = head;
	head->right = grandChild;
	return child;
}

node *rightRotate(node *head)																//Right Rotate Fuction
{
	node *child = head->left;
	node *grandChild = head->left->right;
	child->right = head;
	head->left = grandChild;
	return child;
}


node *balance(node *head)													   				//To balance the AVL Tree after deletion or insertion 
{
	int bf = height(head->left) - height(head->right);
	
	if(bf>1)
	{
		
		if(height(head->left->right) <= height(head->left->left)) 							//Left Rotate
		{
			return rightRotate(head);
		}
		else if(height(head->left->right) > height(head->left->left)) 						//Left-Right Rotate
		{
			head->left = leftRotate(head->left);
			return rightRotate(head);
		}
	}
	else if(bf<-1)
	{
		
		if(height(head->right->left) <= height(head->right->right)) 						//Right Rotate
		{
			return leftRotate(head);
		}
		else if(height(head->right->left) > height(head->right->right))  					//Right-Left Rotate
		{
			head->right = rightRotate(head->right);
			return leftRotate(head);
		}
	}
	return head;
}

node *inorderSuccessor(node *head)															//To find inorder successor after deletion
{																							// Inorder Successor -> leftmost leaf child node of the right child
	node *temp = head;
	while(head->left!=NULL)
		head = head->left;
	return head;
}

node *insert(node *head, int val)
{
	if(head==NULL)																			//Insert new node
		return new node(val);
		
	if(val < head->data)
		head->left = insert(head->left,val);
	else if(val > head->data)
		head->right = insert(head->right,val);
	else																					//Value Already exists in the tree
		return head;
	return balance(head);																	//Balance after Insertion
}

node *deleteNode(node *head, int val)
{
	if(head==NULL)																			//Value doesen't exist in the tree
		return head;
	if(val < head->data)
		head->left = deleteNode(head->left,val);
	else if(val > head->data)
		head->right = deleteNode(head->right,val);
	else																					//Found the node with the value
	{
		if(head->left == NULL && head->right == NULL)										//Value node is a leaf node
		{
			delete head;
			return NULL;
		}
		else if(head->left==NULL)															//Value node has no left child (1 child)
		{
			node *temp = head;
			head = head->right;
			delete temp;
		}
		else if(head->right==NULL)															//Value node has no right child (1 child)
		{
			node *temp = head;
			head= head->left;
			delete temp;
		}
		else																				//Value node has two children 
		{
			node *temp = inorderSuccessor(head->right);										//Copying the data of Inorder Successor to the current  
			head->data = temp->data;														//node therefore deleting the current node in a way
			head->right = deleteNode(head->right,temp->data);								//Deleting the now redundant leaf node
		}
	}
	if(head==NULL)
	return NULL;
	
	return balance(head);
	
}


void preOrderTraversal(node *head)  														//Printing the tree in preorder traversal
{  
	node *temp = head;
    if(temp == NULL)   
    	return;
    cout << temp->data << " ";  
    preOrderTraversal(temp->left);  
    preOrderTraversal(temp->right);  
}  

int main()
{
	node *head = NULL;
	
	cout<<"Press 1 to give costom input and press 2 to display the inbuild input: ";
	int choice;
	cin>>choice;
	if(choice!=1)
	{
		head = insert(head, 100); 
    	head = insert(head, 200); 
    	head = insert(head, 300); 
    	head = insert(head, 250); 
    	head = insert(head, 270); 
    	head = insert(head, 70); 
    	head = insert(head, 40); 
  		/* Class Example
  		
  						200
  					   /   \
					 70    270
					/  \  /   \
				  40 100 250  300
				  
		*/
		cout<<"\nDisplaying preoder traversal after insertion of (100,200,300,250,270,70,40):"<<endl;
    	preOrderTraversal(head);  
    	head = deleteNode(head, 270); 
    	/* Class Example
       	   After Deleting 270
       
  						200
  					   /   \
					 70    300
					/  \   /   
				  40 100  250  
				  
		*/
		cout<<"\n\nDisplaying preorder traversal after deletion of 270: "<<endl;
    	preOrderTraversal(head); 
	}
	else
	{
		for(;;)
		{
			cout<<"[1]Insert \n[2]Delete \n[3]Exit: ";
			cin>>choice;
			switch(choice)
			{
				case 1: cout<<"Enter the number to be inserted: ";
						cin>>choice;
						head = insert(head,choice);
						preOrderTraversal(head);
						cout<<endl;
						break;
				case 2: cout<<"Enter the number to be deleted: ";
						cin>>choice;
						head = deleteNode(head,choice);
						preOrderTraversal(head);
						cout<<endl;
						break;
				default: return 0;
			}
		}
	} 
    return 0;  
}