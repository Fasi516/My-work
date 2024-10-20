#include<stdio.h>

int getDayOfWeek(int day, int month, int year) {

    if (month < 3) {
        month += 12;
        year--;

    }

    int k = year % 100;
    int j = year / 100;

    int dayOfWeek = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;

    // Adjust the result to match the desired output (0 for Saturday, 1 for Sunday, etc.)

    return (dayOfWeek + 7) % 7;
}




int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

char *months[]=
{
	" ",
	
	"\n\n\nJanuary",
	
	"\n\n\nFebruary",
	
	"\n\n\nMarch",
	
	"\n\n\nApril",
	
	"\n\n\nMay",
	
	"\n\n\nJune",
	
	"\n\n\nJuly",
	
	"\n\n\nAugust",
	
	"\n\n\nSeptember",
	
	"\n\n\nOctober",
	
	"\n\n\nNovember",
	
	"\n\n\nDecember" };


int inputyear(void)
{
	int year;
	

	printf("Please enter a year (example: 1989) : ");

	scanf("%d", &year);

	return year;
}

int determinedaycode(int year)
{
	int daycode;

	int d1, d2, d3;
	

	d1 = (year - 1.)/ 4.0;

	d2 = (year - 1.)/ 100.;

	d3 = (year - 1.)/ 400.;

	daycode = (year + d1 - d2 + d3) %7;

	return daycode;
}


int determineleapyear(int year)
{
	if(year% 4==0&&year%100!=0||year%400==0)
	{
		days_in_month[2]=29;

		return 1;
	}
	else
	{
		days_in_month[2]=28;

		return 0;
	}
}

void calendar(int year, int daycode) {
  int month, day, saturday_count;

  for (month = 1; month <= 12; month++) {
    saturday_count = 0;
    printf("%s", months[month]);

    printf("\n\nSun Mon Tue Wed Thu Fri Sat\n");

    // Correct the position for the first date
    for (day = 1; day <= 1 + daycode * 5; day++) {
      printf(" ");
    }

    // Print all the dates for one month
    for (day = 1; day <= days_in_month[month]; day++) {
      printf("%2d", day);

      // Check if it's Saturday and increment count
      if (getDayOfWeek(day, month, year) == 0) {
        saturday_count++;
      }

      // Is day before Sat? Else start next line Sun.
      if ((day + daycode) % 7 > 0) {
        printf("  ");
      } else {
        printf("\n ");
      }
    }

    // Print the number of Saturdays for the month
    printf("\nNumber of Saturdays: %d\n", saturday_count);

    // Set position for next month
    daycode = (daycode + days_in_month[month]) % 7;
  }
  }
  
int main(){

	int p;

	printf("press 1 for day prediction:\n");

	printf("press 2 to get calander:\n");

	scanf("%d",&p);

	if(p<2&&p>0){
		
		 int day, month, year;

    // Input date from the user

    printf("Enter date (DD MM YYYY): ");

    scanf("%d %d %d", &day, &month, &year);

    // Validate the input
    if (day <= 0 || day > 31 || month <= 0 || month > 12 || year < 1583) {

        printf("Invalid date!\n");

        return 1;
    }


    // Get the day of the week

    int dayOfWeek = getDayOfWeek(day, month, year);

    // Display the result

    printf("The day of the week for %02d-%02d-%04d is ", day, month, year);

    switch (dayOfWeek) {

        case 0: printf("Saturday\n"); break;

        case 1: printf("Sunday\n"); break;

        case 2: printf("Monday\n"); break;

        case 3: printf("Tuesday\n"); break;

        case 4: printf("Wednesday\n"); break;

        case 5: printf("Thursday\n"); break;

        case 6: printf("Friday\n"); break;

        default: printf("Error\n");
    }
		}

	else if(p>1&&p<3){

			int year, daycode, leapyear;
	
	year = inputyear();

	daycode = determinedaycode(year);

	determineleapyear(year);

	calendar(year, daycode);

	printf("\n");

	}

	else{

		printf("invalid no!");
		
	}

	return 0;

}

