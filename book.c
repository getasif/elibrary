#include<stdio.h>
#include"eLibrary.h"

MPTR Create_media_node(void)
{
    MPTR p;
    p=(MPTR)malloc(sizeof(struct media));
    return(p);
}
void add_media(MPTR *p)
{
    MPTR q;
    char c;
    q=Create_media_node();
    printf("\nEnter book id\t");
    scanf("%d",&(q->bid));
 	
        

    printf("\nEnter ISBN\t");
	scanf("%d",&(q->ISBN));  
    fflush(stdin);
    scanf("%c",&c);     
    printf("\nEnter book title\t");
    gets(q->title);
	printf("\nEnter the author or director\t");
	gets(q->authdir);
	printf("\nEnter year\t");
	scanf("%d",&(q->year));
 	fflush(stdin);
        scanf("%c",&c);
        printf("\nEnter the media type(v for video,b for book):\t");
 	scanf("%c",&(q->type));
        printf("\nEnter price of book:\t");
        scanf("%d",&(q->price));
	q->issdate=q->issmonth=q->issyear=0;
	q->duedate=q->duemonth=q->dueyear=0;	
        q->issue=0; q->reserve=0;q->retstatus=0;
        fflush(stdin);
        scanf("%c",&c);
        printf("\n");
		
    if(*p!=NULL)
    {
        q->next=*p;
        *p=q;
    }
    else
    {
        q->next=NULL;
		*p=q;
    }
}
void book_disp(MPTR p)
{ printf("\nBook Inforamtion is\n\n");
   if(p!=NULL)
    { while(1)
       { printf("Book ID is:\t%d\n",p->bid);
         printf("ISBN is:   \t%d\n",p->ISBN);
         printf("Title is:  \t%s\n",p->title);
	 printf("Author is: \t%s\n",p->authdir);
	 printf("Year is:    \t%20d\n",p->year);
         if(!p->issue)
	 printf("Book is available\n");
	 else
	 printf("Book is issued to User Id:%d\n",p->issue);
	 if(!p->reserve)
	 printf("Book is not reserved\n");
	 else
         printf("Book is reserved for the User Id:%d\n",p->reserve);
         printf("No. of times the book is issued is:%d\n",p->b_count);
	 printf("The Issue date of the book is %d %d %d\n",p->issdate,p->issmonth,p->issyear);
	 printf("The Due date of the book is %d %d %d\n",p->duedate,p->duemonth,p->dueyear);

	 p=p->next;
         if(p==NULL)
         {
         	break;
         }
         printf("\n");
       }
    }
}

void book_del(MPTR *p,int bookid)	
{  
	MPTR temp=*p,temp1;
	
	if(temp->bid==bookid)
	{
		*p=temp->next;
		free(temp);
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(bookid==temp->next->bid)
			{
				temp1=temp->next;
				temp->next=temp1->next;
				free(temp1);
				return;
			}
			temp=temp->next;
		}
	}
	if(temp->next==NULL)
	{
		printf("BOOK NOT FOUND"); 
	}
}




void book_issue()
{ 
  MPTR temp1=mhead;
  USERPTR temp2=uhead;
  int j=0;
  int uid,bid;
  printf("\n\nEnter User Id:\t");
  scanf("%d",&uid);
  printf("\n\nEnter The Book Id:\t");
  scanf("%d",&bid);
  while(temp1!=NULL)
    { if(temp1->bid==bid) 
           { 	
	      if (temp1->issue==0)
	       {
		while(temp2!=NULL)
                   { 
			if(temp2->id==uid)
                    	{ 
				if(!temp2->card1)
                       		{ 
					temp2->card1=bid;
			 		j=1;
			 		break;
				}
				else if(!temp2->card2)
                       		{ 
					temp2->card2=bid;
			 		j=1;
			 		break;
				}
				else if(!temp2->card3)
                       		{ 
					temp2->card3=bid;
			 		j=1;
			 		break;
				}
				else
				{ 
					printf("\n\nCard Not Empty\n\n");
					break;
				}
			}
	     temp2=temp2->link;
	       }

     if(j==1)
       	{ 	
	       	printf("\n\nEnter the issue date in the format dd mm yyyy:\t");
			scanf("%d %d %d",&(temp1->issdate),&(temp1->issmonth),&(temp1->issyear));
			calc_duedate(temp1);
			temp1->issue=uid;
			temp1->b_count++;  
			printf("\n\nBook ID:\t%d issued to User:\t %s (User Id-%d)\n\n",bid,temp2->name,uid);
        }
	 }

       	else 
    	{
    		printf("\n\nBook Already Issued\n\n");
   		}
       	break;
        
    	}
       temp1=temp1->next;
  }
  
	if(temp2==NULL || temp1==NULL )
	{
		printf("\n\nBook with this BookId does not exist or User Id doesn't exit\n\n");
	}
} 	
void resrv()
{

	MPTR temp1=mhead;
	int isbn;
	printf("\n\nEnter The ISBN:\t");
  	scanf("%d",&isbn);	
	while(temp1!=NULL)
	{	if(temp1->ISBN==isbn)
		{   if(temp1->issue)
			{
				if(!temp1->reserve)
				{
					temp1->reserve=current_user->id;	
					current_user->b_reserve=temp1->bid;
					printf("\nThis Book is Reserved for User:\t%s (User Id-%d)\n\n\n",current_user->name,current_user->id);
				}
				else
				{
					printf("\nThis Book is Already Reserved.....\n\n\n");
				}
			}
			else
			{
				printf("\nThis Book is Avilable NO Need to Reserve.....\n\n\n");
			}
			break;
		}
		
		temp1=temp1->next;
	}
	
	if(temp1==NULL)
	{
		printf("\nSORRY This Book is NOT Avilable.............\n PLEASE Check The ISBN No........\n\n\n");
	}
}


void book_return()
{ 
	MPTR temp1=mhead;
	USERPTR temp2=uhead;  
	int uid,bid,j=0;
	printf("\n\nEnter User Id:\t");
	scanf("%d",&uid);
	printf("\n\nEnter The Book Id:\t");
	scanf("%d",&bid);
	
 	while(temp1!=NULL)
    { 
    	if(temp1->bid==bid)
         {  if(uid==temp1->issue)
               
		 { while(temp2->id!=uid)
		  	temp2=temp2->link;
		  		if(temp2->card1==bid)
                       		{ 
					temp2->card1=0;
			 		temp1->issue=0;
					j=1;
			 		
				}
				else if(temp2->card2==bid)
                       		{ 
					temp2->card2=0;
					temp1->issue=0;
			 		j=1;
			 		
				}
				else if(temp2->card3==bid)
                       		{ 
					temp2->card3=0;
					temp1->issue=0;
			 		j=1;
			 		
				}
		
                
		  calc_fine(temp1);
                  temp1->retstatus=1;
                  temp2->fine=0;
		  temp1->issdate=temp1->issmonth=temp1->issyear=0;
		  temp1->duedate=temp1->duemonth=temp1->dueyear=0;	
                  printf("\n\nReturn Successful\n\n");
		}
        else
        {
        	printf("\n\nThis book is not issued to you\n\n");
        }
            break;
       }
       temp1=temp1->next;
     }

   if(temp1==NULL)
   {
   		printf("\n\nBook with this ISBN does not exist or User Id doesn't exit\n\n");
   }
}


void search_media(int type,int criteria)
{
	int ctr=0;
	char c,comptype;
	MPTR sptr;
	sptr=mhead;
	char input_auth[50];
	char input_title[20];
	int input_year;

	if (type==1)
	{
		comptype='b';
	}
	if (type==2)
	{
		comptype='v';
	}

	if (criteria==1)/*title*/
	{ 
		printf("\nEnter the title you want to search for:\n");
		fflush(stdin);
		scanf("%c",&c);
		gets(input_title);
	         	 
		while(sptr!=NULL)
		{  
			if((sptr)->type==comptype && !(strcmp (sptr->title,input_title)))
			{
				ctr++;
				printf("\n\nThe Book Id is:\t%d\nThe Author is:\t%s",(sptr)->bid,(sptr)->authdir);  
				sptr=(sptr)->next; 
			}
			else
			{
			  	sptr=(sptr)->next;
			}		 
		}/*end while*/
	   
	  
		if (ctr==0)
		{ 
			printf("\nYour search returned no results\n");
		    return;
		}
		else
		{
			printf("\nfound %d matches\n",ctr);
		}
	      

		/* else book_disp(sptr);*/
		return;        
	}/*end criteria1*/

	if (criteria==2)/*author/director*/
	{ 
		if (comptype=='b')
		{
			printf("\nEnter the Author you want to search for:\n");
		}
		if (comptype=='v')
		{
			printf("\nEnter the Director you want to search for:\n");
		}
			
		fflush(stdin);
		scanf("%c",&c); 
		gets(input_auth);
 
	   while(sptr!=NULL)
	   {  
		   	if((sptr)->type==comptype && !(strcmp (sptr->authdir,input_auth)))
			{
				ctr++;
				if (comptype=='v')
				{
					printf("\n\nThe Video Id is:\t%d\nThe Director is:\t%s\n",(sptr)->bid,(sptr)->authdir);
				}
				else 
				{ 
					printf("\n\nThe Book Id is:\t%d\nThe Author is:\t%s\n",(sptr)->bid,(sptr)->authdir);
				}
				sptr=(sptr)->next; 	
		    }
		    else
		    {
		    	sptr=(sptr)->next;
		    }
	     
	   }/*end of while*/
	   

		if (ctr==0)
		{ 
			printf("\nYour search returned no results\n");
			return;
		}
		else
		{
	 		printf("\nfound %d matches\n",ctr);
		}
	   

	   /*use book_disp function*/
	  return;
	}/*end criteria2*/


	if (criteria==3)/*year*/
	{ 
		if (comptype=='b')
		{
			printf("\nEnter the year of publication you want to search for:\n");
		}
		if (comptype=='v')
		{
			printf("\nEnter the year of release you want to search for:\n");
		}
	 	scanf("%d",&input_year);


		while(sptr!=NULL)
		{
			if ((sptr)->type==comptype && ((sptr)->year==input_year) && (sptr!=NULL) )
			{
				printf("\nBook ID :- %d\nAuthor Name:- %s\n",(sptr)->bid,(sptr)->authdir);
				ctr++;}
				sptr=(sptr)->next;
			}

			if (ctr==0)
			{
				printf("\nYour search returned no results\n");
				return;
			}

			/*else book_disp(sptr);*/
			else
			{
				printf("\nfound %d results\n",ctr);
			}
			return;
		}/*end criteria3*/
}/*end function search*/



void calc_duedate(MPTR sptr) 
{
	int x=0,leap=0,m,m1,d1,y1;
	d1=sptr->issdate;
	m1=sptr->issmonth;
	y1=sptr->issyear;

	printf("\n\nThe issue Date is:\t %d %d %d",d1,m1,y1);
	d1=d1+15;

	if ((y1%4==0) && (y1%100!=0)) {leap=1;}

	if ((leap==1) && (m1==2))
	{ if (d1>29) 
		{x=d1-29;m=m1+1;} 
	  else
	       {x=d1;m=1;}
	}
	 
	if ((leap!=1) && (m1==2))
	{ if (d1>28) 
		{x=d1-28;m=m1+1;} 
	  else
	        {x=d1;m=m1;}
	}

	if (m1==4 || m1==6 || m1==9 || m1==11)  
	{ if (d1>30) 
		{x=d1-30;m=m1+1;} 
	   else
	      { x=d1;m=m1;}
	}
	if (m1==1 || m1==3 || m1==5 || m1==7 ||m1==8 || m1==10 || m1==12 )
	{ if (d1>31) 
		{x=d1-31;m=m1+1;} 
	   else
	      {x=d1;m=m1;}
	}

	/*check for month>12*/
	if (m>12)
	{
		y1=y1+1;
		m=1;
	}


	/*put the due date into the book struct*/
	sptr->duedate=x;
	sptr->duemonth=m;
	sptr->dueyear=y1;
	printf("\n\nThe Due Date is:\t %d %d %d",x,m,y1);
	/*end function calc_duedate*/
}


void auto_renew()
{  
   int bid,uid,j;
   
   MPTR sptr;
   printf("\n\nEnter the Bood Id\n");
   scanf("%d",&bid);
   printf("\n\nEnter the User Id\n");
   scanf("%d",&uid);
   MPTR temp1=mhead;
   USERPTR temp2=uhead;

   while(temp1!=NULL)
    { if(temp1->bid==bid) 
           {   while(temp2!=NULL)
                   { 
			if(temp2->id==uid)
                    	{       current_user=temp2;
			        calc_fine(temp1);
				if(temp2->fine>0)
					{ printf("\n\nYou have active fines,book cannot be renewed\n\n");				
					  return;
				         }
				if(temp1->reserve)
				{  printf("\n\nBook is already reserved for User Id %d, You cannot renew",temp1->reserve);
				    break;
                                }
				else if(temp2->card1==bid)
                       		{ 
					temp2->card1=bid;
			 		j=1;
			 		break;
				}
				else if(temp2->card2==bid)
                       		{ 
					temp2->card2=bid;
			 		j=1;
			 		break;
				}
				else if(!temp2->card3==bid)
                       		{ 
					temp2->card3=bid;
			 		j=1;
			 		break;
				}
				
			}
	     temp2=temp2->link;
	       }

	if(j==1)
	{ 	
		sptr=temp1;
		int x=0,leap=0,m,m1,d1,y1;
		d1=sptr->duedate;
		m1=sptr->duemonth;
		y1=sptr->dueyear;
		printf("\n\nThe old due Date was:\t %d %d %d",d1,m1,y1);
		d1=d1+15;

		if ((y1%4==0) && (y1%100!=0)) {leap=1;}

		if ((leap==1) && (m1==2))
		{ if (d1>29) 
			{x=d1-29;m=m1+1;} 
			else
			{x=d1;m=1;}
		}

		if ((leap!=1) && (m1==2))
		{ if (d1>28) 
			{x=d1-28;m=m1+1;} 
		else
			{x=d1;m=m1;}
		}


		if (m1==4 || m1==6 || m1==9 || m1==11)  
		{ 
			if (d1>30) 
			{x=d1-30;m=m1+1;} 
			else
			{ x=d1;m=m1;}
			}
		if (m1==1 || m1==3 || m1==5 || m1==7 ||m1==8 || m1==10 || m1==12 )
		{ if (d1>31) 
			{x=d1-31;m=m1+1;}
			else
			{x=d1;m=m1;}
		}

		/*check for month>12*/

		if (m>12)
		{
			y1=y1+1;
			m=1;
		}

		/*put the due date into the book struct*/
		sptr->duedate=x;
		sptr->duemonth=m;
		sptr->dueyear=y1;
		printf("\n\nThe Due Date is:\t %d %d %d",x,m,y1);
		/*end function calc_duedate*/
		temp1->issue=uid;
		temp1->b_count++;  
		printf("\n\nBook ID:\t%d re-issued to User:\t %s (User Id-%d)\n\n",bid,temp2->name,uid);
	}

    break;
        
    }
       temp1=temp1->next;
  }
}

