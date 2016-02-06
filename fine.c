#include <stdio.h>
#include "eLibrary.h"


/*assumes date2 is after date1*/
void calc_fine(MPTR sptr)
{
	int dt2,mnth2,yr2,dt1,mnth1,yr1;
	int fine=0;
	char ch;
	printf("\nEnter today's date in the format dd mm yyyy\n");
	scanf("%d %d %d", &dt2,&mnth2,&yr2);

	dt1=sptr->duedate;
	mnth1=sptr->duemonth;
	yr1=sptr->dueyear;

	if( dt1>dt2 && mnth1>mnth2 && yr1>yr2 ) return;/*book returned in time*/



	int diff=0;
	int leap1,leap2,leap;
	int month,year;

	leap1=0;
	if ((yr1%4==0) && (yr1%100!=0)) {leap1=1;}

	leap2=0;
	if ((yr2%4==0) && (yr2%100!=0)) {leap2=1;}


	if (yr1==yr2) {
	  if (mnth1==mnth2)
	   { diff=dt2-dt1;
	     
	   }/*end if same month also*/ 
	}

	if ((yr1==yr2) && (mnth1!=mnth2))
	{
	   { if (mnth1==2 && leap1==1) {diff=diff+(29-dt1);}
	     else if (mnth1==2 && leap1==0) {diff=diff+(28-dt1);}
	     else if (mnth1==4 || mnth1==6 || mnth1==9 || mnth1==11) {diff=diff+(30-dt1);}
	     else {diff=diff+(31-dt1);}/*for other months*/
	   }

	   for (month=mnth1+1;month<mnth2;month++) 
	     {  if (month==2 && leap1==1) {diff=diff+29;}
	        else if (month==2 && leap1==0) {diff=diff+28;}
	        else if (month==4 || month==6 || month==9 || month==11) {diff=diff+30;}
	        else {diff=diff+31;}/*for other months*/
	     }

	   /*in month2 now*/
	    
	     diff=diff+dt2;

	    /*Get diff here*/    
	}/*end if year1 is same as year2*/


	if (yr1 != yr2) {

	     if (mnth1==2 && leap1==1) {diff=diff+(29-dt1);}
	     else if (mnth1==2 && leap1==0) {diff=diff+(28-dt1);}
	     else if (mnth1==4 || mnth1==6 || mnth1==9 || mnth1==11) {diff=diff+(30-dt1);}
	     else {diff=diff+(31-dt1);}/*for other months*/
	     month=mnth1+1;
	     for (; month!=1; month++)
	        {  if (month==2 && leap1==1) {diff=diff+29;}
	           else if (month==2 && leap1==0) {diff=diff+28;}
	           else if (month==4 || month==6 || month==9 || month==11) {diff=diff+30;}
	           else {diff=diff+31;}/*for other months*/
	           month=month%12;
	        }

	     for (year=yr1+1; year<yr2 ; year++)
	        { leap=0;
	          if ((year%4==0) && (year%100!=0)) {leap=1;}
	          
	          if (leap=1) { diff=diff+366;}
	          if (leap=0) { diff=diff+365;}
	        }/*till end of year2 -1*/

	     /*now in year2*/
	     for (month=1;month<mnth2;month++)
	        {  if (month==2 && leap2==1) {diff=diff+29;}
	           else if (month==2 && leap2==0) {diff=diff+28;}
	           else if (month==4 || month==6 || month==9 || month==11) {diff=diff+30;}
	           else {diff=diff+31;}/*for other months*/
	        }/*now in month2 in year2*/
	    
	     diff=diff+dt2;/*add days=dt2*/

	    /*Get diff here for case2*/
	      
	}/*end if not in the same year*/


	fine=diff;
	current_user->fine=fine;

	printf("\nThe user has active fine of %d Rupees\n",current_user->fine);
	return;
}/*end function fine*/



