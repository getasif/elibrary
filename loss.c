#include<stdio.h>
#include"eLibrary.h"

void loss(void)
{  
	int i=1,j=0,bookid,uid;
	MPTR bptr=mhead;
	USERPTR sptr=uhead;
	MPTR prevptr;

   while(i)
   {
   printf("\nEnter the Book Id of the lost book\n");
   scanf("%d",&bookid);
   printf("Enter the User Id\n");
   scanf("%d",&uid);

   
    while(sptr!=NULL)
    {if (sptr->id==uid){ if ((sptr->card1==bookid)||(sptr->card1==bookid)||(sptr->card1==bookid))break;}
     sptr=sptr->link;
    }
    if(sptr=NULL) { printf("User Id is invalid or this Book has not been issued to this User\n");
                    return;
                  }

    while(bptr!=NULL)
    { prevptr=bptr;
      if (bptr->bid==bookid) {j=1;break;}
      else bptr=bptr->next;
    }
    if (j==1){ printf("The price of the book lost is %d Rupees\n.Please collect the amount\n",bptr->price);
               book_del(&mhead,bookid);
               printf("The Book has been deleted from the database.\n");
               i=0;
             }

    if (j=0){printf("Book not found.Please check and re-enter the Book Id\n");
             i=1;
            }
           
           
    }//end while(i)
return;
}//end loss function
