#include<stdio.h>
#include"eLibrary.h"


USERPTR Createnode(void)
{
	USERPTR p;
	p=(USERPTR)malloc(sizeof(struct user));
	return(p);
}


void Adduser(USERPTR *p)
{   
	int i=1,j=1;
	char *pswd;
    char c,ch1;
	USERPTR q=NULL;
	
	q=Createnode();
    fflush(stdin);
    scanf("%c",&c);
	
	printf("\nEnter name :\t");
        gets(q->name); 
	printf("\nEnter the address :\t");
        gets(q->address);
	printf("\nEnter the phone number:\t");
        scanf("%ld",&(q->phone));
	//printf("\nEnter the User id :\t");
    	//scanf("%d",&(q->id));
	while(j)
    { 
    	printf("\nEnter the User Id:\t");
	    scanf("%d",&(q->id));
	    j=check_uid(q);
	    if(j==0)
		{
			break;
	    }
		else
		{
			printf("\n\nUser Id already exists, try another User Id......\n\n");
			scanf("%c",&ch1);
		}
	}/*end while(j)*/
	
	printf("\nEnter the User Type (1 for Customer : 2 for Librarian):\t");
    scanf("%d",&(q->usertype));
		
	while(i)
    { 
      	printf("\nEnter the User Name:\t");
	    scanf("%s",&(q->usrname));
	    i=check_uname(q);
    	if(i==0)
	  	{
	   		break;
		}
		else
		{
			printf("\n\nUsername already exists, try another username......\n\n");
			scanf("%c",&ch1);
		}
	}/*end while(i)*/
		
    pswd=(char *)getpass("\nEnter password:\t");
	strcpy(q->passwd,pswd); 
	q->card1=q->card2=q->card3=0;
	q->b_reserve=0,q->fine=0;
	fflush(stdin);
    scanf("%c",&c);
    printf("\n");
	
    if(*p!=NULL)
	{
		q->link=*p;
		*p=q;
	}
	else
	{
		*p=q;
		q->link=NULL;
	}
}


int check_uname(USERPTR q)
{ USERPTR temp=uhead;
  int j=0;
  while(temp!=NULL)
	{       
	    if(!strcmp(temp->usrname,q->usrname))
		{	
		  	j=1;
		    return j;
		}		
	    else 
		{      
			j=0;
		}
        temp=temp->link;   	
	}
  return 0;
}

int check_uid(USERPTR q)
{ USERPTR temp=uhead;
  int j=0;
  while(temp!=NULL)
	{       
	    if(temp->id==q->id)
		 {	
		      	j=1;
		        return j;
		}		
	    else 
		{      
			j=0;
		}
		
         temp=temp->link;   	
	}
  return 0;
}

void Disp(USERPTR p)	 
{        MPTR temp=mhead;
	 char c='n';
         printf("\nUser Inforamtion is\n\n");
         printf("\nName is:         \t%s",p->name);
         printf("\nAddress is:      \t%s",p->address);
         printf("\nPhone Number is: \t%ld",p->phone);
         printf("\nThe User Id is:  \t%d",p->id);
	 printf("\n\n\nDo you wish to view your Account Information(y/n)\n");
	 fflush(stdin);
	 scanf("%c",&c);
	 scanf("%c",&c);
	 
         
	 if(c=='y' || c=='Y')
         {	printf("\n\nAccount Information for %s:\t\n\n",p->name);
		while(temp!=NULL)
	      { if(temp->issue==p->id)
			calc_fine(temp);
		temp=temp->next;
               }
		printf("\n\nAccount Information for %s:\t\n\n",p->name);
 	
	 if(!p->card1 && !p->card2 && !p->card3)
	 printf("\nNo Book is issued to you\n");
	 else if(p->card1)
	 printf("\nBook Id %d is issued to you\n",p->card1);
	 else if(p->card2)
	 printf("\nBook Id %d is issued to you\n",p->card2);
	 else if(p->card3)
	 printf("\nBook Id %d is issued to you\n",p->card3);
	 if(!p->b_reserve)
	 printf("\nNo Book is reserved by you\n");
	 /*else if(p->b_reserve)
	 printf("\nBook Id %d is reserved by you\n",p->b_reserve);*/
         printf("\nYou have active fines of Rs.%d",p->fine);
	 }
}

	 
	 
	
void Disp1(USERPTR p)
{ printf("\nUser Inforamtion is\n\n");
  if(p!=NULL)
    { while(1)
       { printf("\nName is:\t%s",p->name);
         printf("\nAddress is:\t%s",p->address);
         printf("\nPhone Number is:\t%d",p->phone);
         printf("\nThe User Id is:\t%d",p->id);
         p=p->link;
         if(p==NULL)
           break;
         printf("\n\n");
       }
     }
}
         

void Del_User(USERPTR *p,int uid)	//uid is for getting user id
{  
	int i=0;
	USERPTR temp=*p,temp1;
	if(temp->id==uid)
	{
		*p=temp->link;
		free(temp);
	}
	else
	{
		while(temp->link!=NULL)
		{
			if(uid==temp->link->id)
			{
				temp1=temp->link;
				temp->link=temp1->link;
				free(temp1);
				i=1;
				break;
			}
			temp=temp->link;
		}
	}
	
	if(temp->link==NULL)
	{
		printf("USER NOT FOUND"); 
	}
	
	if(i==1)
	{
		printf("USER DELETED");
	}
}


void modify_detail(USERPTR *p)
{ 
  USERPTR temp=*p;
  char ch='y',*str1,*str2,c, t_password[20];
  int opt,cmp=0;
  
  while(ch=='y'||ch=='Y')
	{ 
		printf("\n\n.....Enter Choice For Modification.....\n\n");
		printf("\n1.Password \t2.Phone \t3.Address \t4.Exit\n\n");
		scanf("%d",&opt);
     	  switch(opt)
            {  
            	case 1:
					  str1=(char *)getpass("\nNew Password:\t");
                      strcpy(t_password,str1);
		      		  str2=(char *)getpass("\nReEnter Password:\t");
                      cmp=strcmp(t_password,str2);
                      if(cmp==0)
                      { 
                      	strcpy(temp->passwd,str1);
						printf("\nPassword Successfully Changed:\t");
                      }
		 		      else
				      {
				        printf("\n\nPasswords Do Not Match\n\n");
		 		      }
				      fflush(stdin);	
				      scanf("%c",&c);	
                      break;
					  
               case 2:printf("\n\nEnter new Phone Number:\t");
                      scanf("%d",&(temp->phone));
                      break;
					  
	 	       case 3:printf("\n\nEnter New Address:\t");
	                  fflush(stdin);
				      scanf("%c",&c);	
                      gets(temp->address);
                      break;
					  
			   case 4:return;
 
	       default:("\n\nWrong choice\n\n");
		      continue;
 	    }
	  printf("\n\nDo You want more Modifications(y/n):\t");
	  fflush(stdin);
	  scanf("%c",&c);
	  scanf("%ch",&c); 
	  //ch=getchar();
 	 *p=temp;
  	}
}

void Reset_pass()
{ 
  USERPTR temp=uhead;
  char ch='y',t_password[20],name[20],c,a,*str1,*str2;
  int opt,cmp=0,tid,lop=1;
  
	while(lop!=0)
	{  
		printf("\n\n.....Enter UID OR USER NAME For PASSWORD reset.....\n\n");
		printf("\n1.USER NAME \n2.UID \n3.Exit\n\n");
		scanf("%d",&opt);
		system("clear");
	
		switch(opt)
		{  
			case 1:printf("\n\nEnter the USERNAME:\t");
				fflush(stdin);
				scanf("%c",&c);
				gets(name);//user name from key board.
				 while(temp!=NULL)
				 {
		       		a=strcmp(temp->name,name);
					if(0==a)
					{
				    		str1=(char *)getpass("\nNew Password:\t");
			                	strcpy(t_password,str1);
							str2=(char *)getpass("\nReEnter Password:\t");
			                	cmp=strcmp(t_password,str2);
								
		                	if(cmp==0)
		                	{ 
								strcpy(temp->passwd,str1);
								printf("\nPassword Successfully Changed:\t");
		                	}
				 			else
				 			{
								printf("\n\nPasswords Do Not Match\n\n");
				 			}
					}
					temp=temp->link;
				}
				//fflush(stdin);	
				//scanf("%c",&c);	
				lop=0;
		        break;
					   
		  	case 2:printf("\n\nEnter the USER ID:\t");
					fflush(stdin);
					scanf("%c",&c);
					scanf("%d",&tid);//user id from key board.
					 while(temp!=NULL)
					 {
		       			 a=(temp->id==tid);
							if(1==a)
							{
				      			str1=(char *)getpass("\nNew Password:\t");
		                      			strcpy(t_password,str1);
				      			str2=(char *)getpass("\nReEnter Password:\t");
		                      			cmp=strcmp(t_password,str2);
		                      			if(cmp==0)
		                      			{ 
											strcpy(temp->passwd,str1);
											printf("\nPassword Successfully Changed:\t");
		                      			}
				 		      			else
						        		{
						        			printf("\n\nPasswords Do Not Match\n\n");
				 		      			}
				      		}
						temp=temp->link;
					}
					fflush(stdin);	
				    scanf("%c",&c);
					lop=0;
					break;	

			case 3:return;
			default:printf("\n\nWrong choice\n\n please Enter Correct Choise\n\n");
				lop=1;opt=0;     
				
		}
	}  
}




int login()
{
	int set;
	USERPTR tmp;
	
	char *pswd,uname[20],c;
	char tuser[20],tpaswd[20];
	int count;
	printf("\n\nEnter the USERNAME:\t");
	fflush(stdin);
	scanf("%c",&c);
	gets(uname);//user name from key board.
	for(count=0;count<3;count++)
	  {	tmp=uhead;
		printf("\n");
		pswd=(char *)getpass("\n\nEnter the PASSWORD:\t");//user password from key board.
		strcpy(tpaswd,pswd);
		
		int a,b;
		do
		{       system("clear");
                        printf("");
			printf("");
			a=strcmp(tmp->usrname,uname);
			b=strcmp(tmp->passwd,tpaswd);
			if(a==0 && b==0)
			{
				//printf("\n\nLogin Successful\n\n");
				set=1;
				count=4;
				current_user=tmp;
                                
				return(tmp->usertype);
			}						
			else
				set=0;	     
		        tmp=tmp->link;
                }while(tmp!=NULL && set==0);
		 if(count<2)
		   	printf("\nIncorrect Username or Password:\t");	
	 }

	if(count==3)
	{
		printf("\n\n.............Max Tries Over................\n\n");
	}
return 0;
}
