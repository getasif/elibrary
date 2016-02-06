#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "eLibrary.h"

FILE *fptr1=NULL;

void writefile_user(USERPTR sptr)
{
	/*write to file the Book List*/
	/*sptr=mhead;*/


	if( !(fptr1=fopen("user.dat","w")))
	{
		printf("opening of user.dat failed \r\n");
		perror("fopen");
	}
	/*include for error in opening*/
	while (sptr != NULL)
	  { fwrite(sptr,sizeof(struct user),1,fptr1);
	  
	    sptr=sptr->link;
	  }/*end while*/
	  
	fclose(fptr1);
}/*end write to file book list*/  
   

void readfile_user(void)
{

	USERPTR sptr;
	USERPTR tempptr;
	int a;
	if(!(fptr1=fopen("user.dat","a+r")))
	{
		printf("opening of user.dat failed \r\n");
		perror("fopen");
	}
	uhead=NULL;
	tempptr=Createnode();
	tempptr->link=NULL;

	while(1)
	{
		a=fread(tempptr,sizeof(struct user),1,fptr1);
		if(a==0)
		{ 
			free(tempptr);break;
		}
		else  
		{  
			tempptr->link=uhead;
			uhead=tempptr;
			tempptr=Createnode();
		}
	}
	
	fclose(fptr1);
	printf("user list recreated\n");
}/*end function read book list from file*/

      
   
  
