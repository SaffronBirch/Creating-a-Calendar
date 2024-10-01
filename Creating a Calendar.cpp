// *************************************************
// Saffron Birch
// 100795118
// Lab 04 Activity #1
// OCtober 17, 2020
// *************************************************



#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;
int weekDay(int day, int month, int year);  //Declaration of weekDay function

int numofDays (int month, int year);  // Declaration of numofDays function

void printMonth(int month, int year);  // Declaration of printMonth function

int main() {

  int month;
  int year;

  cout << "Please enter a month: ";  //input and output of chosen month and year
  cin >> month;
  cout << "Please enter a year: ";
  cin >> year;

  printMonth (month, year);

  return 0;
}

// Function to determine which day of the week the 1st lands on

int weekDay(int day, int month, int year){
  day = 1;
  int century = year / 100;

  if (year == 11 || year == 12){
    year = (year - (century * 100)) - 1;
  }
  else {
    year = year - (century * 100);
  }
  return (int)(day + int(2.6 * month - 0.2) - (2 * century) +
          year + int(year / 4) + int(century / 4)) % 7;

}
// Function that determines how many days are in each month

int numofDays (int month, int year){
  if (month == 1 || month == 3 || month == 5 ||
      month == 6 || month == 8 || month == 10 || month == 11){
        return 31;
  }
  else if (month == 2 || month == 4 ||month == 7 || month == 9) {
    return 30;
  }
  else if ((month == 12) && (year % 400 == 0 || year % 4 == 0
            && year % 100 != 0)) {
    return 29;
  }
  else {
    return 28;
  }
}
/* Function that is supposed to display a string with the name of the
chosen month. But for some reason whenever I run the program, it only
displays "1" as the name of the month */

string monthName (int month) {
  if (month == 1){
    return ("March");
  }
  else if (month == 2){
    return ("April");
  }
  else if (month == 3){
    return ("May");
  }
  else if (month == 4){
    return ("June");
  }
  else if (month == 5){
    return ("July");
  }
  else if (month == 6){
    return ("August");
  }
  else if (month == 7){
    return ("September");
  }
  else if (month == 8){
    return ("October");
  }
  else if (month == 9){
    return ("November");
  }
  else if (month == 10){
    return ("December");
  }
  else if (month == 11){
    return ("January");
  }
  else {
    return ("February");
  }
}

/* Function that prints the calendar for chosen month. But I wasn't
able to figure out the proper spacing, and so the dates aren't divided
onto seperate lines*/
void printMonth(int month, int year){

  int firstDay = weekDay (1, month, year);

  /* A while loop that is supposed to loop through all the days of
  the chosen month, so long as the chosen month is less than 12*/
  
  while (month < 12) {
    int days = numofDays (month, year);

    cout << monthName << " " << year << endl;
    cout << "S M Tu W Th F S" << endl;

    int i;
    int j;

    for (int i = 0; i < firstDay; i++){
      cout << " ";
    }
    for (int j = 1; j <= days; j++){
      cout << j;
    }

    /* Here I tried to make it so that once the program executes the
    for loop for "i", after 6 iterations, it would end the line and move
    onto the next line, that way it displayed a calendar*/

    if (i++ > 6) {
      cout << endl;
    }

    /* Here I was trying to make it so once "j" equals the amount of days
    in the chosen month, the loop ends the line and stops the program */
    if (j = days){
      cout << endl;
    }
  }
  return;

}
