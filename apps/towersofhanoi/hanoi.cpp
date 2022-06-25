//
// File:    hanoi.cpp
// Author: Your Glorious Instructor 
// Purpose:
// Implement recursive and iterative solutions to the Towers of Hanoi.
// Iterative Solution Credit: https://iq.opengenus.org/tower-of-hanoi/
//

#include <iostream> 
#include <chrono>
#include <stack>
using namespace std; 

class Hanoi 
{
    public:
        char from;
        char to;
        char temp;
        int n;
};

//function prototypes
void recursiveMoveDisks (int, int, int, int);
void iterativeMoveDisks (int, char, char, char);
void swap (char&, char&);

int main()  //driver program
{
    const int NUMDISKS = 5;
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;

    auto start1 = chrono::steady_clock::now();
    recursiveMoveDisks(NUMDISKS, FROMPEG, TOPEG, TEMPPEG);
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start1; 
    cout << "Recursive elapsed time: " << elapsed_seconds1.count() << " s\n";

    cout << endl << endl;

    auto start2 = chrono::steady_clock::now();
    iterativeMoveDisks(NUMDISKS, 'A', 'B', 'C');
    auto end2 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2;
    cout << "Iterative elapsed time: " << elapsed_seconds2.count() << " s\n"; 

    return 0;
}

void recursiveMoveDisks (int num, int fromPeg, int toPeg, int tempPeg)
{
    if (num > 0)
    {
        recursiveMoveDisks(num - 1, fromPeg, tempPeg, toPeg);
        cout << "Move a disk from peg " << fromPeg << " to peg " << toPeg << endl;
        recursiveMoveDisks(num - 1, tempPeg, toPeg, fromPeg);
    }
}

void iterativeMoveDisks (int num, char fromPeg, char tempPeg, char toPeg)
{
    stack<Hanoi> st;

    while (num >= 1 || !st.empty())
    {
        Hanoi current; 
        current.from = fromPeg;
        current.temp = tempPeg; 
        current.to = toPeg;
        current.n = num;
        st.push(current);
        swap(toPeg, tempPeg);
        num--;
    }

    Hanoi current = st.top();
    st.pop();
    cout << "Move disk " << current.n << " from peg " << current.from << " to peg " << current.to << endl;

    if (current.n >= 1)
    {
        fromPeg = current.temp;
        tempPeg = current.from;
        toPeg = current.to;
        num = current.n-1;
    } 
}

void swap (char& toPeg, char& tempPeg)
{
    char temporary;
    temporary = toPeg;
    toPeg = tempPeg;
    tempPeg = temporary;
}