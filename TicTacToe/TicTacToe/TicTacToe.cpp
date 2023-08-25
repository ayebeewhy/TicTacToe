#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Square {
public:
    bool taken;
    char choice;
    int place;
};

int main()
{
    int input;
    int count = 1;
    int xCount = 0;
    int oCount = 0;
    int takenCount = 0;
    char OGchoice = ' ';
    char choice = ' ';

    cout << "Tic Tac Toe\n";
    cout << "Would you like to start with X or O ?\n";
    cin >> OGchoice;
    
    // Decides first player's choice (X or O)
    while (!(OGchoice == 'X' || OGchoice == 'O' || OGchoice == 'x' || OGchoice == 'o')) {
        cout << "Invalid Input. Please try again.\n";
        cin >> OGchoice;
    }


    
    // Initializes each square
    Square squares[9];

    Square sq1;
    sq1.taken = false;
    sq1.choice = '_';
    sq1.place = 1;
    squares[0] = sq1;

    Square sq2;
    sq2.taken = false;
    sq2.choice = '_';
    sq2.place = 2;
    squares[1] = sq2;

    Square sq3;
    sq3.taken = false;
    sq3.choice = '_';
    sq3.place = 3;
    squares[2] = sq3;

    Square sq4;
    sq4.taken = false;
    sq4.choice = '_';
    sq4.place = 4;
    squares[3] = sq4;

    Square sq5;
    sq5.taken = false;
    sq5.choice = '_';
    sq5.place = 5;
    squares[4] = sq5;

    Square sq6;
    sq6.taken = false;
    sq6.choice = '_';
    sq6.place = 6;
    squares[5] = sq6;

    Square sq7;
    sq7.taken = false;
    sq7.choice = ' ';
    sq7.place = 7;
    squares[6] = sq7;

    Square sq8;
    sq8.taken = false;
    sq8.choice = ' ';
    sq8.place = 8;
    squares[7] = sq8;

    Square sq9;
    sq9.taken = false;
    sq9.choice = ' ';
    sq9.place = 9;
    squares[8] = sq9;


 

    cout << endl;
    cout << "_1_|_2_|_3_" << endl;
    cout << "_4_|_5_|_6_" << endl;
    cout << "_7_|_8_|_9_" << endl;
    cout << endl;
    cout << "Take turns and select the corresponding number for the place you want to play\n";


    while (count < 10) {

        if (OGchoice == 'X' || OGchoice == 'x') {
            if (count % 2 == 0) {
                choice = 'O';
            }
            else {
                choice = 'X';
            }
        }
        else if (OGchoice == 'O' || OGchoice == 'o') {
            if (count % 2 == 0) {
                choice = 'X';
            }
            else {
                choice = 'O';
            }
        }

        if (xCount == 3 || oCount == 3) {
            // get most recent squares[i].place and compare
            // 123
            if (squares[0].choice == squares[1].choice && squares[1].choice == squares[2].choice) {
                cout << "Winner " << squares[1].choice << endl;
                return 0;
            }
            // 456
            else if (squares[3].choice == squares[4].choice && squares[4].choice == squares[5].choice) {
                cout << "Winner " << squares[3].choice << endl;
                return 0;
            }
            // 789
            else if (squares[6].choice == squares[7].choice && squares[7].choice == squares[8].choice) {
                cout << "Winner " << squares[6].choice << endl;
                return 0;
            }
            // 147
            else if (squares[0].choice == squares[3].choice && squares[3].choice == squares[6].choice) {
                cout << "Winner " << squares[0].choice << endl;
                return 0;
            }
            // 258
            else if (squares[1].choice == squares[4].choice && squares[4].choice == squares[7].choice) {
                cout << "Winner " << squares[1].choice << endl;
                return 0;
            }
            // 369
            else if (squares[2].choice == squares[5].choice && squares[5].choice == squares[8].choice) {
                cout << "Winner " << squares[2].choice << endl;
                return 0;
            }
            // 159
            else if (squares[0].choice == squares[4].choice && squares[4].choice == squares[8].choice) {
                cout << "Winner " << squares[0].choice << endl;
                return 0;
            }
            // 357
            else if (squares[2].choice == squares[4].choice && squares[4].choice == squares[6].choice) {
                cout << "Winner " << squares[2].choice << endl;
                return 0;
            }
        }
        
        cin >> input;
        // if x count or o count is 3
        // check to see if there is a winner

        for (int i = 0; i < 9; i++) {
            //cin >> input;
            //cout << squares[i].place << endl;
            if (squares[i].place == input) {
                if (squares[i].taken == true) {
                    cout << "Taken!" << endl;
                    
                    count--;
                }
                else {
                    //update taken
                    squares[i].taken = true;
                    //update choice
                    squares[i].choice = choice;
                    //display
                    if (choice == 'X') {
                        xCount++;
                    }
                    else if (choice == 'O') {
                        oCount++;
                    }
                }
            }
        }
        cout << endl;
        cout << "_" << squares[0].choice << "_|_" << squares[1].choice << "_|_" << squares[2].choice << "_" << "    _1_|_2_|_3_" << endl;
        cout << "_" << squares[3].choice << "_|_" << squares[4].choice << "_|_" << squares[5].choice << "_" << "    _4_|_5_|_6_" << endl;
        cout << " " << squares[6].choice << " | " << squares[7].choice << " | " << squares[8].choice << " " << "    _7_|_8_|_9_" << endl;

        count++;
    }

    return 0;
}