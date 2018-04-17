// George Strauch
// reserves seats on an airplane
// 04/17/2018


/* instantiates sentinel value for loop, intX and intY as coordinate
 * values for reserving seats, the char array to represent reserved seats
 * calls function to clear the array
 * iterates while loop with the sentinel value to get reserved seats
 * prints the array with every iteration
 * prints the final seating arrangement*/


#include <iostream>
using namespace std;

// must be out here because of how array works
// syntax should be array[seats][rows]
int const intseats = 6;
int const introws = 12;


// 0 means the seat is free, # means reserved
void clearArry(char chrArray[intseats][introws]){

    for (int i = 0; i < introws; ++i) {
        for (int j = 0; j < intseats; ++j) {
            chrArray[j][i] = '0';
        }
    }

}


// reserves the seat that starts at (1,1) not (0,0) since most people start counting at 1, not 0
void reserve(char chrplane[intseats][introws], int intRowTmp, int intSeatTmp){

    if(chrplane[intSeatTmp - 1][intRowTmp - 1] == '#'){
        cout << "that seat is already reserved" << endl;
    } else{
        chrplane[intSeatTmp - 1][intRowTmp - 1] = '#';
        cout << "the seat " << intRowTmp << ',' << intSeatTmp << " has been reserved" << endl;
    }

}


void printSeats(char chrArray[intseats][introws]){

    cout << '\n' << "0 means the seat is free, # means reserved" << endl;
    cout << "rows go down, seats across" << endl << endl;

    for (int i = 0; i < introws; ++i) {
        for (int j = 0; j < intseats; ++j) {
            cout << chrArray[j][i];
        }
        cout << '\n';
    }
    cout << '\n';

}


int main() {

    char chrSentinel = 'y';
    int intX = 0;
    int intY = 0;
    char chrPlane[intseats][introws];
    clearArry(chrPlane);
    printSeats(chrPlane);

    while(chrSentinel == 'y'){

        cout << "enter a seat to reserve [ from (1,1) to (12,6) ]" << endl;

        cout << "enter row of seat to reserve" << endl;
        cin >> intY;
        cout << "enter seat to reserve" << endl;
        cin >> intX;

        reserve(chrPlane, intY, intX);
        printSeats(chrPlane);

        cout << "would you like to reserve another seat? [y,n]";
        cin >> chrSentinel;

    }

    printSeats(chrPlane);

    return 0;

}