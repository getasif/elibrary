#ifndef eLibrary
#define eLibrary

struct user
{ char name[50];
  char address[100];
  long int phone;
  char usrname[15];
  char passwd[15];
  int id,card1,card2,card3;
  int cardstatus;
  int b_reserve;
  int fine;
  int usertype;
  struct user * link;
} ;
typedef struct user *USERPTR;
USERPTR uhead,current_user;

struct media
{ int bid;
  int price;
  char authdir[50];
  int year;
  char title[50];
  char type;
  int ISBN;
  char bookstatus;
  int userid;
  int duedate;
  int duemonth;
  int dueyear;
  int issdate;
  int issmonth;
  int issyear;
  int b_count,reserve,issue,retstatus;
  struct media * next;
};
typedef struct media *MPTR;
MPTR mhead;


int login(void);
void uhelp(void);
void lhelp(void);
void readfile_user(void);
void readfile_book(void);
void writefile_user(USERPTR);
void writefile_book(MPTR);
void loss(void);

USERPTR Createnode(void);
void Adduser(USERPTR *);
void Disp(USERPTR);
void Del_User(USERPTR *,int);
void modify_detail(USERPTR *);
void Disp1(USERPTR );
void Reset_pass(void);
int check_uname(USERPTR);

MPTR Create_media_node(void);
void auto_renew();
void add_media(MPTR *);
void book_disp(MPTR); 
void book_del(MPTR *,int);
void search_media(int,int );
void resrv();
void book_issue();
void book_return();
void calc_duedate(MPTR);
void calc_fine(MPTR sptr);
int datecompare(int,int,int,int,int,int);




#endif
