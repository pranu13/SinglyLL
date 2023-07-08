#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next ;    //12  bytes   
};

typedef struct Node NODE;
typedef struct Node * PNODE;      //Node * = PNODE
typedef struct Node ** PPNODE;



void InsertFirst(PPNODE Head , int No)
{
    PNODE newn = NULL;
    
    //Allocate memory for node
    newn = (PNODE)malloc(sizeof(NODE));   //sizeof(NODE) = 12 Bytes

    //Initialise to the node

    newn->data = No;
    newn-> next = NULL;

    if(*Head == NULL) // LL is empty
    {
        *Head = newn;

    }
    else   // LL contains atleast one node
    {
        newn->next = *Head;
        
        *Head = newn;

    
    }

}
void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    
    //Allocate memory for node
    newn = (PNODE)malloc(sizeof(NODE));

    //Initialise to the node

    newn->data = No;
    newn-> next = NULL;
    
    if(*Head == NULL) // LL is empty
    {
        *Head = newn;

    }
    else   // LL contains atleast one node
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        newn->next = NULL;


    }
    
}

void Display(PNODE Head)
{
    printf("Elements of Linked list are :\n");

    while(Head != NULL)
    {
        printf("|%d| -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");

}

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
   return iCnt;
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)   //LL is empty
    {
        return ;

    }
    else if ((*Head)-> next == NULL)   // LL contains 1 node  //Due to precedece error
    {
        free(*Head);
        *Head = NULL;

    }
    else             //LL contains more than one node
    {
        *Head = (*Head)->next;
        free(temp);

        
    }
    
    
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
    if(*Head == NULL)   //LL is empty
    {
        return ;
    }
    else if ((*Head)-> next == NULL)   // LL contains 1 node  //Due to precedece error
    {
        free(*Head);
        *Head = NULL;

    }
    else             //LL contains more than one node
    {
        while(temp->next->next != NULL)   //Type 3 while loop
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;

        
    }
    
    
}

void InsertAtPos(PPNODE Head ,  int No , int Pos)
{
     int iLength = 0 , iCnt = 0;
     iLength = Count(*Head);  //Calculate length of LL

     PNODE temp = *Head;
     PNODE newn = NULL;

     if((Pos < 1) || (Pos > iLength + 1))   //Invalid Position
     {
        printf("Invalid Position ");
        return;

     }
     if(Pos == 1)
     {
        InsertFirst(Head,No);
     }
     else if(Pos == iLength+1)
     {
        InsertLast(Head,No);
     }
     else
     {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn-> next = NULL;

        for(iCnt = 1;iCnt < Pos -1 ; iCnt++)
        {
           temp = temp-> next;
        }
          
        newn->next = temp->next;
        temp->next = newn;

     }
}

void DeleteAtPos(PPNODE Head  , int Pos)
{
     int iLength = 0,iCnt = 0;

     PNODE temp = *Head;
     PNODE tempX = NULL;

     iLength = Count(*Head);  //Calculate length of LL

     if((Pos < 1) || (Pos > iLength + 1))   //Invalid Position
     {
        printf("Invalid Position ");
        return;

     }
     if(Pos == 1)
     {
        DeleteFirst(Head);
     }
     else if(Pos == iLength)
     {
        DeleteLast(Head);
     }
     else
     {
        for(iCnt = 1;iCnt < Pos -1 ; iCnt++)
        {
           temp = temp-> next;
        }

        tempX = temp->next;

        //Sequence is important

        temp->next = temp->next->next;
        free(tempX);


     }
}






int main()
{
    PNODE First = NULL;
    int iRet = 0;
    
    InsertFirst(&First,111);
    InsertFirst(&First,101);
    InsertFirst(&First,51);    //InsertFirst(60 , 51)  
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    Display(First);
    iRet = Count(First);

    printf("Number of nodes are %d\n",iRet);

    InsertLast(&First,121);
    InsertLast(&First,151);

    Display(First);
    iRet = Count(First);

    printf("Number of nodes are %d\n",iRet);

   InsertAtPos(&First , 25 ,5);
   
   Display(First);
   iRet = Count(First);

   printf("Number of nodes are %d\n",iRet);
   
   DeleteAtPos(&First , 5);

   Display(First);
   iRet = Count(First);

   printf("Number of nodes are %d\n",iRet);
   
    DeleteFirst(&First);
   
    DeleteFirst(&First);
   
   Display(First);
   iRet = Count(First);

   printf("Number of nodes are %d\n",iRet);

   DeleteLast(&First);
  
   Display(First);
   iRet = Count(First);

   printf("Number of nodes are %d\n",iRet);

   
   
  
    return 0;
}

