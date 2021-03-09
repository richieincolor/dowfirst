//************************************
//  Day-of-Week Program for Month/Year
//************************************


#include <iostream>
using namespace std;


// Forward Declarations
void getInput(int& month, int& year, string& monthStr);
void doMath(int& a, int& m, int& y, int month, int day, int year, int& leapDays, int& jdn, int& dowInt);
void switchDow(int dowInt, string& dowStr);
void printResults(string dowStr, string monthStr, int year);
int yearFix(int year);
string switchMonth(int month);


int main() {
    // Vars
    int month, year, day,
    a, m, y,
    leapDays, jdn, dowInt;
    string dowStr, monthStr;
    
    // Day is 1 because we're only calculating the first of the month
    day = 1;
    
    //Get user input
    getInput(month, year, monthStr);
    
    //Calculate the JDN and Day of Week
    doMath(a, m, y,
           month, day, year,
           leapDays, jdn, dowInt);
    
    //Get string for day-of-week
    switchDow(dowInt, dowStr);
    
    //Print Results
    printResults(dowStr, monthStr, year);
    
    return 0;
}

void getInput(int& month, int& year, string& monthStr) {
    // Really exceptionally noobish input validation that I can't be bothered to fix right now
    bool validInput = 0;
    while(!validInput){
        cout << "month    : ";
        cin >> month;
        cout << endl;
        cout << "year     : ";
        cin >> year;
        cout << endl;
        
        // Little fix that should correct *most* 2-digit year inputs
        year=yearFix(year);
        
        // Get string for month name
        monthStr=switchMonth(month);
        
        // More super weak input validation
        if(month>=1 && month<=12 && year>=1600) {
            validInput = 1;
        } else if(year<1600) {
            cout << "This program only works for dates after the 16th Century. Try again! \n \n";
        } else {
            cout << "invalid entry, try again! \n \n";
        }
    }
}

void doMath(int& a, int& m, int& y, int month, int day, int year, int& leapDays, int& jdn, int& dowInt) {
    // This algorithm spits out all sorts of useful date info.
    a=(14-month)/12;
    m=(month-3)+(12*a);
    y=year+4800-a;
    leapDays=(y/4)-(y/100)+(y/400);
    jdn=day+(((153*m)+2)/5)+(365*y)+leapDays-32045;
    dowInt=(jdn+1)%7;
}

void switchDow(int dowInt, string& dowStr){
    // Switches day of week integer for a string for user readability
    switch(dowInt) {
        case 0: dowStr = "Sunday";
            break;
        case 1: dowStr = "Monday";
            break;
        case 2: dowStr = "Tuesday";
            break;
        case 3: dowStr = "Wednesday";
            break;
        case 4: dowStr = "Thursday";
            break;
        case 5: dowStr = "Friday";
            break;
        case 6: dowStr = "Saturday";
            break;
    }
}

string switchMonth(int month){
    // Switches month integer for a string for user readability
    switch(month){
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
    }
    return "ERROR: invalid month"; //this should theoretically never happen regardless of user input
}

void printResults(string dowStr, string monthStr, int year){
    // Prints results
    cout << endl;
    cout << "The first of " << monthStr << ", " << year << " was a " << dowStr << endl;
}

int yearFix(int year) {
    // Inputs 0-21 for "year" will fix to 2000-2021
    // Other 2-digit inputs will correct to the 1900's
    if(year<21 && year>=0) {
        year = year+2000;
        return year;
    } else if(year<100){
        year = year+1900;
        return year;
    }
    return year;
}
