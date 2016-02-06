#include<stdio.h>
#include"eLibrary.h"

void uhelp()
{
	char choice;
	printf("\t\t\t\t\t\t\tHELP CONTENTS\n");
	do
	{
	int ch,ch1,ch2,c;
	printf("\nUSER GUIDE......1");
	printf("\nQUIT............2");
	printf("\n\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	       printf("\n\t\tUser Guide:");
	       printf("\nSEARCH MEDIA.....................1");
	       printf("\nRESERVE MEDIA....................2");
	       printf("\nUSER INFORMATION.................3");
	       printf("\nMODIFY USERINFORMATION...........4");
	       printf("\nQUIT.............................5");
	       printf("\n\nEnter your choice ");
	       scanf("%d",&ch1);
	       switch(ch1)
	       {

	         case 1:
	                 printf("\nSearch Media:-> To search a media i.e to search any book or video.\n\nPress:-1->Search Book2->Search Video.\n\nAfter Pressing 1-page is displayed to enter the book information(title,Author,year) which you want to check whether book is in the library and to issue.press enter and you will get a list of books according to your specification.\n\nAfter Pressing 2-enter the video information(title,director,year),searched information is displayed according to your choice.");
	                 break;
	        case 2: 
	                 printf("\nReserve Media:->Reserve Media gives you a facility to reserve a book/video\n when a book/video is available in the library but currently issued to some other user");
	                 break;
	        case 3:
	                 printf("\nUser Information:->User Information shows your Personal Information/n i.e UserID,Username,Useraddress & UserInformation");
	                 break;
	        case 4:
	                 printf("\nModify UserInformation:->Modify gives you an option to update your Personal Information\n in your account details.");
	                 break;
	        case 5:
	                 return;
	        default:
	                 printf("\nEnter VALID choice"); 
	       }
	break;
	         
	case 2:
	       return;
	break;
	default:
	        printf("\nEnter right choice");
	}
	printf("\n\nDo you want to continue\t\t");
	fflush(stdin);
	scanf("%c",&c);
	scanf("%c",&choice);
	}while(choice=='Y'|| choice=='y');

}    




void lhelp()
{
	char choice;
	printf("\t\t\t\t\t\t\tHELP CONTENTS\n");
	do
	{
	int ch,ch1,ch2,c;
	printf("\nLIBRARIAN.......1");
	printf("\nQUIT............2");
	printf("\n\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{

	      case 1:
	              printf("\nLibrarian:");
	              printf("\nADD CUSTOMER............1");
	              printf("\nDELETE CUSTOMER.........2");
	              printf("\nADD BOOK.............3");
	              printf("\nDISPLAY BOOK.........4");
	              printf("\nDELETE BOOK..........5");
	              printf("\nRESET PASSWORD.......6");
	              printf("\nQUIT.................7");
	              printf("\n\nEnter your choice");
	              scanf("%d",&ch2); 
	              switch(ch2)
	               {
	                 case 1:
	                         printf("\nAdd Customer:->Add Customer is used to add or create new user account into library database \n as a new library member.The username entered must not be the same as any existing username");
	                 break;
	                 case 2:
	                         printf("\nDelete Customer:->Delete Customer is used to delete an already existing user account \n from library database");
	                 break;
	                 case 3:
	                         printf("\nAdd Book:->Add book is used to add new books to the library with book details");
	                 break;
	                 case 4:
	                         printf("\nDisplay Book:->Display book used to display detailed book information ");
	                 break;
	                 case 5:
	                         printf("\nDelete Book:->Delete book used to delete an already existing book from library database");
	                 break;
	                 case 6:
	                        printf("\nReset Password:->used when any user forgets the password, it can be reset by the librarian using this option using USER ID or USER NAME");
	                 break;
	                 case 7:
	                         return;
	                 break;
	                 default:
	                         printf("Enter the valid choice");
	              }     
	 break;   
	case 2:
	       return;
	break;
	default:
	        printf("\nEnter right choice");
	}
	printf("\n\nDo you want to continue\t\t");
	fflush(stdin);
	scanf("%c",&c);
	scanf("%c",&choice);
	}while(choice=='Y'|| choice=='y');

}                              
