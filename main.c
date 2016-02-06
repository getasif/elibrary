#include<stdio.h>
#include"eLibrary.h"

int main()
{
	system("clear");
	int i,bookid,k,m,log;
   	char c,ch='y',cho='y';
	uhead=NULL;		//head pointer of user linklist
	mhead=NULL;		//head pointer of media linklist
	int choice1,choice2,media1,media2;
                    
		
					//enter book & user information
	//readfile_user();
	//readfile_book();
       

	while(ch=='y'||ch=='Y')
	{
	cho='y';system("clear");
	printf("\nEnter The choice..............................\n1.Customer\n2.Librarian\n3.EXIT\n\n\n\n\n\n\n ENTER YOUR choice...............................................\n");
	scanf("%d",&choice1);
	system("clear");
	  if(choice1==3)
	     exit(0);
	log=login();  //LOGIN PROCESS
	 
	        
	if(choice1==log)
	{
		switch(choice1)
		{
			case 1:
				while(cho=='y'||cho=='Y')
				{system("clear");
				printf("\n\n\n\t\t\t******************** HELLO  %s *******************\n\n\n\t1.For Media Search \n\n\t2.For Media Reserve \n\n\t3.For User Information\n\n\t4.For Modify User Info\n\n\t5.HELP\n\n\t6.LOGOUT\n\n\n\n\n\n\n\nENTER YOUR choice....................................\t",current_user->name);
					scanf("%d",&choice2);
					//break;	
					switch(choice2)
					{
						system("clear");
					
						case 1:printf("\nSearch For Meadia.............\n1.Search Book\n2.Search Video\n\n\n\n\n\n\nENTER YOUR choice.................................\t");
							scanf("%d",&media1);
						
						system("clear");
						printf("\nSearch By........\n1.Title\n2.Author\n3.Year \n\n\n\n\n\n\nENTER YOUR choice.....................................\t");
							scanf("%d",&media2);
						search_media(media1,media2);
						break;
						case 2:printf("\nResreve media");
							resrv();
						break;
						case 3:printf("\nUser Info");
							Disp(current_user);		//Display All users
						break;
						case 4:printf("\nModify user info");
							modify_detail(&current_user);
						break;
						case 5:printf("\nHELP");
							uhelp();
						break;
						
						case 6:printf("\nLOGOUT\n\n");
						//exit(0);
						break;

						default:
							printf("Wrong choice");
			
					}
				fflush(stdin);
				scanf("%c",&c);if((choice2)==6){break;}
				printf("\n\n Go Back To PREVIOUS Menu......(Y/N)\t"); 
	        		scanf("%c",&cho);
				}
			break;	
			case 2:while(cho=='y'||cho=='Y')
				{system("clear");
				printf("\n\n\n\t\t\t******************** HELLO LIBRARIAN *******************\n\n\t\t1.Add Customer \n\t\t2.Delete Customer \n\t\t3.Delete Book\n\t\t4.Add Book\n\t\t5.Display Book List\n\t\t6.View Customer Detail\n\t\t7.Return BOOK\n\t\t8.Book Issue\n\t\t9.Automatic Renewal\n\t\t10.Reset Password\n\t\t11.Show Fine\n\t\t12.Lost Media\n\t\t13.HELP\n\t\t14.Logout\n\n\n\nENTER YOUR CHOICE.......\t");
				scanf("%d",&choice2);
					switch(choice2)
					{
						system("clear");
					
						case 1: printf("Add Customer\n\n");
							Adduser(&uhead);
						break;
						case 2: printf("\nDelete Customer\n\n");
							printf("\n\n\nEnter the user id of the user u want to delete:\t");
	   						scanf("%d",&i);printf("\n\n\n");
	   						Del_User(&uhead,i);
						break;
						case 3: printf("\nDelete Book\n\n");
							printf("Enter the book id to be deleted\t");
	   						scanf("%d",&bookid);
	   						book_del(&mhead,bookid);
						break;
						case 4: printf("\nAdd Book\n\n");
							add_media(&mhead);
						break;
						case 5: printf("\nDisplay Book List\n\n");
							book_disp(mhead);
						break;
						case 6: printf("\nView Customer Detail\n\n");
							Disp1(uhead);
						break;

						case 7:printf("\nReturn BOOK\n");
							book_return();
						break;
						case 8: printf("\nISSUE The BOOK\n ");
							book_issue();
						break;
					        case 9: printf("\nAutomatic Renewal\n ");
							auto_renew();
						        break;
						case 10:printf("\nReset PASSWORD\n ");
							Reset_pass();
						break;
						case 11:printf("\nShow Fine\n");
						break;
						case 12:printf("\nLost Media\n");
							loss();
						break;
						case 13:printf("\nHELP\n");
							lhelp();
						break;
						case 14:printf("\nLOGOUT\n\n");
							//exit(0);
						break;

						default:
							printf("Wrong choice");
							
					}
				fflush(stdin);
				scanf("%c",&c);if((choice2)==14){break;}
				printf("\n\n Go Back To PREVIOUS Menu..(Y/N)....\t"); 
	        		scanf("%c",&cho);
				}
				
			break;
			case 3:
				exit(0);
			default:printf("Wrong choice");			
	}
		writefile_user(uhead);
		writefile_book(mhead);
	        
		fflush(stdin);
		scanf("%c",&c);
		printf("\n\n Go Back To MAIN Menu..(Y/N)....\t"); 
	        scanf("%c",&ch);
		}
	else
	printf("SORRY..............................\n\t\tWrong choice Or LOGINID Or PASSWORD......\n");
	scanf("%c",&c);
	system("clear");
	}/*end while ch=='y'||ch=='Y'*/
	
	return 0;
}/*end main()*/
