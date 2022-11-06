 // using this to see if the code that I refer to works or not
//not my own code

#include <stdio.h>
void create();


void create()
{
        struct node *temp,*ptr;
    
        printf("nEnter the data value for the node:t");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}