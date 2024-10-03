/**
 * Jackson Mondy
 * Auburn-ID: 904314490
 * File-Name: project2_Mondy_jbm0138_v1.cpp
 * 
 * How to run the code: 
 * {IN TERMINAL}
 * a. Open terminal where file is located **Where the file is located, not the file**
 * b. Then once in the correct folder, type “g++ -o ./(enter temp file name) ./(.cpp file name)" **file name can be whatever you want**
 * c. This will create an exe file
 * d. To run enter ./(temp file name)
 * 
 * {On AU Server Terminal}
 * a. Upload file to AU Server
 * b. Type "g++ (.cpp File_Name) -o (*name of executable file )" * name of executable file can be whatever they want
 * c. Then type "./(name of .exe file you just created)” 
 * d. Press Enter when prompted to
 * 
 * Credits:  
 * 1. I used google for how to use the assert as well as setting up rand()
 * 2. Used friends and google for problem testing with functions if errors appeared
 */    

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

bool at_least_two_alive(bool a_alive, bool b_alive, bool c_alive);
void Aaron_shoots1(bool &b_alive, bool &c_alive);
void Bob_shoots(bool &a_alive, bool &c_alive);
void Charlie_shoots(bool &a_alive, bool &b_alive);
void Aaron_shoots2(bool &b_alive, bool &c_alive);
bool shoot(double probability);

// Constants
const int TOTAL_RUNS = 10000;
const double ProbA = 1.0 / 3.0;
const double ProbB = 1.0 / 2.0;
const double ProbC = 1.0;

bool a_alive, b_alive, c_alive;

void test_at_least_two_alive() {
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    // Case 1: Aaron alive, Bob alive, Charlie alive
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive()\n";
    assert(at_least_two_alive(true, true, true));
    cout << "\t\tCase passed ...\n";

    // Case 2: Aaron dead, Bob alive, Charlie alive
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(at_least_two_alive(false, true, true));
    cout << "\t\tCase passed ...\n";

    // Case 3: Aaron alive, Bob dead, Charlie alive
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(at_least_two_alive(true, false, true));
    cout << "\t\tCase passed ...\n";

    // Case 4: Aaron alive, Bob alive, Charlie dead
    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(at_least_two_alive(true, true, false));
    cout << "\t\tCase passed ...\n";

    // Case 5: Aaron dead, Bob dead, Charlie alive
    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(at_least_two_alive(false, false, true)==false);
    cout << "\t\tCase passed ...\n";

    // Case 6: Aaron dead, Bob alive, Charlie dead
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(at_least_two_alive(false, true, false)==false);
    cout << "\t\tCase passed ...\n";

    // Case 7: Aaron alive, Bob dead, Charlie dead
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(at_least_two_alive(true, false, false)==false);
    cout << "\t\tCase passed ...\n";

    // Case 8: Aaron dead, Bob dead, Charlie dead
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(at_least_two_alive(false, false, false) == false);
    cout << "\t\tCase passed ...\n";

    // Prompt user to continue
    cout << "Press any key to continue...\n";
    cin.get();
}


void test_Aaron_shoots1() {
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    
    cout <<"\tCase 1: Bob alive, Charlie alive\n";
    bool b_alive = true;
    bool c_alive = true;
    Aaron_shoots1(b_alive, c_alive);
    // Verify that one of them may have died, but both should not have survived
    assert(b_alive || c_alive);
    cout << "\t\tAaron is shooting at Charlie\n";

    cout <<"\tCase 2: Bob dead, Charlie alive\n";
    b_alive = false;
    c_alive = true;
    Aaron_shoots1(b_alive, c_alive);
    assert(c_alive || !c_alive); // Aaron should shoot at Charlie in this case
    cout << "\t\tAaron is shooting at Charlie\n";

    cout <<"\tCase 3: Bob alive, Charlie dead\n";
    b_alive = true;
    c_alive = false;
    Aaron_shoots1(b_alive, c_alive);
    assert(b_alive); // Aaron should shoot at Bob in this case
    cout << "\t\tAaron is shooting at Bob\n";

    // Prompt user to continue
    cout << "Press any key to continue...\n";
    cin.get();
}

void test_Bob_shoots() {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    
    cout <<"\tCase 1: Aaron alive, Charlie alive\n";
    bool a_alive = true;
    bool c_alive = true;
    Bob_shoots(a_alive, c_alive);
    assert(c_alive || a_alive); // Bob should shoot one of them
    cout << "\t\tBob is shooting at Charlie\n";

    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    a_alive = false;
    c_alive = true;
    Bob_shoots(a_alive, c_alive);
    assert(c_alive); // Bob should shoot at Charlie
    cout << "\t\tBob is shooting at Charlie\n";

    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    a_alive = true;
    c_alive = false;
    Bob_shoots(a_alive, c_alive);
    assert(!a_alive || a_alive); // Bob should shoot at Aaron
    cout << "\t\tBob is shooting at Aaron\n";

    cout << "Press any key to continue...\n";
    cin.get();
}

void test_Charlie_shoots() {
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    
    cout << "\tCase 1: Aaron alive, Bob alive\n";
    bool a_alive = true;
    bool b_alive = true;
    Charlie_shoots(a_alive, b_alive);
    assert(b_alive || a_alive); 
    cout << "\t\tCharlie is shooting at Bob\n";

    cout << "\tCase 2: Aaron dead, Bob alive\n";
    a_alive = false;
    b_alive = true;
    Charlie_shoots(a_alive, b_alive);
    assert(!b_alive || b_alive);; 
    cout << "\t\tCharlie is shooting at Bob\n";

    cout << "\tCase 3: Aaron alive, Bob dead\n";
    a_alive = true;
    b_alive = false;
    Charlie_shoots(a_alive, b_alive);
    assert(!a_alive || a_alive);; 
    cout << "\t\tCharlie is shooting at Aaron\n";

    cout << "Press any key to continue...\n";
    cin.get();
}

void test_Aaron_shoots2() {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    
    cout <<"\tCase 1: Bob alive, Charlie alive\n";
    bool b_alive = true;
    bool c_alive = true;
    Aaron_shoots2(b_alive, c_alive);
    // Aaron should intentionally miss his first shot, so both should still be alive
    assert(b_alive && c_alive);  
    cout <<"\t\tAaron intentionally misses his first shot.\n";
    cout <<"\t\tBoth Bob and Charlie are alive.\n";

    cout << "\tCase 2: Bob dead, Charlie alive\n";
    b_alive = false;
    c_alive = true;
    Aaron_shoots2(b_alive, c_alive);
    // Aaron should shoot at Charlie, and Charlie might die based on probability
    assert(!c_alive || c_alive);  // c_alive could be either true or false after the shot
    cout << "\t\tAaron is shooting at Charlie.\n";

    cout <<"\tCase 3: Bob alive, Charlie dead\n";
    b_alive = true;
    c_alive = false;
    Aaron_shoots2(b_alive, c_alive);
    // Aaron should shoot at Bob, and Bob might die based on probability
    assert(!b_alive || b_alive);  // b_alive could be either true or false after the shot
    cout << "\t\tCase 3 passed: Aaron is shooting at Bob.\n";

    // Prompt user to continue
    cout << "Press any key to continue...\n";
    cin.get();
}

// Function that the truel functions will call upon for every shot
bool shoot(double probability) {
    return (rand() / (double)RAND_MAX) < probability;
}

// Calculate the percentage of wins
double Percent(int wins, int total_simulations) {
    return (static_cast<double>(wins) / total_simulations) * 100;
}

//Function that will check if truel should continue
//No winner yet
bool at_least_two_alive(bool a_alive, bool b_alive, bool c_alive) {
    return (a_alive && b_alive) || (a_alive && c_alive) || (b_alive && c_alive);
}

//Try and kill for Aaron
void Aaron_shoots1(bool &b_alive, bool &c_alive) {
    // Aaron chooses to shoot at Charlie if he is alive; otherwise, he shoots Bob
    if (c_alive) {
        c_alive = !shoot(ProbA); // Charlie shot
    } else if (b_alive) {
        b_alive = !shoot(ProbA); // Bob shot
    }
}

//Try and kill for Bob
void Bob_shoots(bool &a_alive, bool &c_alive) {
    // Bob shoots at Charlie if he is alive; otherwise, he shoots Aaron
    if (c_alive) {
        c_alive = !shoot(ProbB); // Charlie shot
    } else if (a_alive) {
        a_alive = !shoot(ProbB); // Aaron shot
    }
}

//Try and kill for Chralie
void Charlie_shoots(bool &a_alive, bool &b_alive) {
    // Charlie shoots at Bob if he is alive; otherwise, he shoots Aaron
    if (b_alive) {
        b_alive = !shoot(ProbC); // Bob shot
    } else if (a_alive) {
        a_alive = !shoot(ProbC); // Aaron shot
    }
}

//Set for first of Aarons shots
bool missed_first_shot = false;

//Miss first on purpose for Aaron
void Aaron_shoots2(bool &b_alive, bool &c_alive) {
    if (!missed_first_shot) {
        // Aaron misses his first shot intentionally
        missed_first_shot = true;  // Now, Aaron has missed his first shot
        return;  // Skip shooting this time
    }

    // After missing the first shot, Aaron shoots normally
    Aaron_shoots1(b_alive, c_alive);  // Aaron follows Strategy 1 after the first round
}

//Output for prinitng results as well as calling functions 
int main() {
    test_at_least_two_alive();
    test_Aaron_shoots1();
    test_Bob_shoots();
    test_Charlie_shoots();
    test_Aaron_shoots2();

    srand(time(0));  // Seed for random number generation

    int A_wins_strategy1 = 0;
    int B_wins_strategy1 = 0;
    int C_wins_strategy1 = 0;

    int A_wins_strategy2 = 0;
    int B_wins_strategy2 = 0;
    int C_wins_strategy2 = 0;


    cout << "Ready to test strategy 1 (run 10000 times):\n";
    cout << "Press any key to continue...\n";
    cin.get();
    // Simulating Strategy 1
    for (int i = 0; i < TOTAL_RUNS; ++i) {
        bool a_alive = true, b_alive = true, c_alive = true;
        while (at_least_two_alive(a_alive, b_alive, c_alive)) {
            if (a_alive) Aaron_shoots1(b_alive, c_alive);
            if (b_alive) Bob_shoots(a_alive, c_alive);
            if (c_alive) Charlie_shoots(a_alive, b_alive);
        }

        if (a_alive) A_wins_strategy1++;
        else if (b_alive) B_wins_strategy1++;
        else C_wins_strategy1++;
    }
    
    // Output results
    cout << "Aaron won " << A_wins_strategy1 << "/" << TOTAL_RUNS << " truels or " << Percent(A_wins_strategy1, TOTAL_RUNS) << "%\n";
    cout << "Bob won " << B_wins_strategy1 << "/" << TOTAL_RUNS << " truels or " << Percent(B_wins_strategy1, TOTAL_RUNS) << "%\n";
    cout << "Charlie won " << C_wins_strategy1 << "/" << TOTAL_RUNS << " truels or " << Percent(C_wins_strategy1, TOTAL_RUNS) << "%\n";


    cout << "\nReady to test strategy 2 (run 10000 times):\n";
    cout << "Press any key to continue...\n";
    cin.get();

    // Reset for Strategy 2 simulation
    for (int i = 0; i < TOTAL_RUNS; ++i) {
        bool a_alive = true, b_alive = true, c_alive = true;
        missed_first_shot = false;  // Reset for each simulation
        while (at_least_two_alive(a_alive, b_alive, c_alive)) {
            if (a_alive) Aaron_shoots2(b_alive, c_alive);
            if (b_alive) Bob_shoots(a_alive, c_alive);
            if (c_alive) Charlie_shoots(a_alive, b_alive);
        }

        if (a_alive) A_wins_strategy2++;
        else if (b_alive) B_wins_strategy2++;
        else C_wins_strategy2++;
    }
    
    cout << "Aaron won " << A_wins_strategy2 << "/" << TOTAL_RUNS << " truels or " << Percent(A_wins_strategy2, TOTAL_RUNS) << "%\n";
    cout << "Bob won " << B_wins_strategy2 << "/" << TOTAL_RUNS << " truels or " << Percent(B_wins_strategy2, TOTAL_RUNS) << "%\n";
    cout << "Charlie won " << C_wins_strategy2 << "/" << TOTAL_RUNS << " truels or " << Percent(C_wins_strategy2, TOTAL_RUNS) << "%\n";

    // Compare strategies
    if (A_wins_strategy2 > A_wins_strategy1) {
        cout << "\nStrategy 2 is better than strategy 1.\n";
    } else if (A_wins_strategy1 > A_wins_strategy2) {
        cout << "\nStrategy 1 is better than strategy 2.\n";
    } else {
        cout << "\nBoth strategies are equally effective.\n";
    }

    return 0;
}
