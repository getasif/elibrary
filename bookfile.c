#include "eLibrary.h"
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>
FILE *fptr=NULL;

void writefile_book(MPTR sptr) 
{
	/*write to file the Book List*/
	/*sptr=mhead;*/


	fptr=fopen("book.dat","w+");
	/*include for error in opening*/

	while (sptr != NULL)
	{ 
		fwrite(sptr,sizeof(struct media),1,fptr);
		sptr=sptr->next;
	}/*end while*/
	  
	fclose(fptr);

}/*end wirte to file book list*/  
   

void readfile_book(void)
{
	MPTR sptr;
	MPTR tempptr;
	int a;
	fptr=fopen("book.dat","a+r");

	mhead=NULL;
	tempptr=Create_media_node();
	tempptr->next=NULL;

	while(1)
	{
		a=fread(tempptr,sizeof(struct media),1,fptr);
		if(a==0) 
		{ 
			free(tempptr);
			break; 
		}
		else  
		{ 
			tempptr->next=mhead;
			mhead=tempptr;
			tempptr=Create_media_node();
		} 
	}
	
	printf("book list recreated\n");
	fclose(fptr);
}/*end function read book list from file*/

      

  

