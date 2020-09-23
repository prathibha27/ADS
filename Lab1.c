#include <stdio.h> 
#include <stdlib.h> 
#include <inttypes.h> 

struct Node 
{ 
    int data; 
    struct Node* link; 
}; 
  
struct Node* XOR (struct Node *a, struct Node *b) 
{ 
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
} 

void insert_at_beginning(struct Node **start, int data) 
{ 
    struct Node *newnode = (struct Node *) malloc (sizeof (struct Node) ); 
    newnode->data = data; 
    newnode->link =*start; 
    if (*start != NULL) 
    { 
        (*start)->link = XOR(newnode, (*start)->link); 
    } 
    *start = newnode; 
} 

struct Node insert_at_end(struct Node *start, int data){
    struct Node *newnode = (struct Node *) malloc (sizeof (struct Node) );  
    newnode->data = data; 
    if(start == NULL){
        newnode->link = NULL;
        return *newnode;
    }
    if(start->link == NULL){
        start->link = (struct Node*) ((uintptr_t)(start->link) ^(uintptr_t)(newnode));
        newnode->link = start;
        return *start;
    }
    struct Node* prevPointer = start;
    struct Node* nextPointer = start->link;
    struct Node* q;
    while(prevPointer != nextPointer->link){
        q = (struct Node*) ((uintptr_t)(nextPointer->link) ^ (uintptr_t)(prevPointer));
        prevPointer = nextPointer;
        nextPointer = q;
    }
    nextPointer->link = (struct Node*) ((uintptr_t)(nextPointer->link) ^ (uintptr_t)(newnode));
    newnode->link = nextPointer;
    return *start;
}

void printList (struct Node *head) 
{ 
    struct Node *curr = head; 
    struct Node *prev = NULL; 
    struct Node *next; 
  
    printf (">>Linked List: >> \n"); 
  
    while (curr != NULL) 
    { 
        printf ("%d ", curr->data); 
        next = XOR (prev, curr->link); 
        prev = curr; 
        curr = next; 
    } 
} 
  
    
int main () 
{ 
    struct Node *head = NULL; 
    int i,ch,ele;
     
    do{printf("\n Enter choice \n 1.Insert at the beginning \n 2.Insert at the end \n 3.exit \n");
    scanf("%d",&ch);
    switch(ch){
      case 1 : printf("\n Element to insert:");
                        scanf("%d", &ele);
                        insert_at_beginning(&head, ele); 
                        printList (head); 
                        break;
      case 2 : printf("\n Element to insert:");
                        scanf("%d", &ele);
                        insert_at_end(head, ele);
                         printList (head); 
                          break;
      case 3 : exit(0);
      default:printf("enter valid choice");
    }
    }while(3);
    return 0; 
}