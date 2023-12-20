#include<stdio.h>

int getFirstDayOfTheYear(int year){
  int day = (1 + 5 * ((year - 1) % 4) + 4 * ((year - 1) % 100) + 6 * ((year - 1) % 400)) % 7;
  return day;
}

int main() {
    system("clear");
  char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  int dayInMonth[] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
  int i, j, totalDays, weekDay= 0, spaceCounter = 0, year;
    printf("Enter the year: \n");
  scanf("%d", &year);
  printf("\n****************** WELCOME TO %d ******************\n", year);

  // checking leap year
  if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
     dayInMonth[1] = 29;
  }

  // checking 1st day of the year
  weekDay = getFirstDayOfTheYear(year);

  // printing calendar
  for(i = 0; i< 12; i++){
    printf("\n\n\n------------------- %s -------------------\n", months[i]);
    printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat \n\n");


    for(spaceCounter =1; spaceCounter <= weekDay; spaceCounter++){
      printf("      ");
    }

    // printing days
    totalDays = dayInMonth[i];
    for(j =1; j <= totalDays; j++){
      printf("%6d", j);
      weekDay++;
      if(weekDay > 6){
        weekDay = 0;
        printf("\n");
      }
    }
  }
    return 0;
}