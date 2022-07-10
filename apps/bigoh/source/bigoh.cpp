//
// File:    bigoh.cpp
// Author: Kaylee Hurst & Your Glorious Instructor 
// Purpose:
// Determine the big-oh of the algorithm
//

#include <iostream> 
#include <chrono>
#include <iomanip>
using namespace std; 

//function prototypes 
int anyEqual(const int, int*);
void fillArray(const int, int*);


int main()
{
    const int NUM1 = 10;
    const int NUM2 = 20;
    const int NUM3 = 30;
    const int NUM4 = 40;
    const int NUM5 = 50;
    const int NUM6 = 100;
    const int NUM7 = 500;
    const int NUM8 = 1000; 
    int array1[NUM1][NUM1];
    int array2[NUM2][NUM2];
    int array3[NUM3][NUM3];
    int array4[NUM4][NUM4];
    int array5[NUM5][NUM5];
    int array6[NUM6][NUM6];
    int array7[NUM7][NUM7];
    int array8[NUM8][NUM8];

    fillArray(NUM1, *array1);
    auto start1 = chrono::steady_clock::now();
    anyEqual(NUM1, *array1);
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start1; 

    fillArray(NUM2, *array2);
    auto start2 = chrono::steady_clock::now();
    anyEqual(NUM2, *array2);
    auto end2 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2; 

    fillArray(NUM3, *array3);
    auto start3 = chrono::steady_clock::now();
    anyEqual(NUM3, *array3);
    auto end3 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds3 = end3 - start3; 

    fillArray(NUM4, *array4);
    auto start4 = chrono::steady_clock::now();
    anyEqual(NUM4, *array4);
    auto end4 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds4 = end4 - start4; 

    fillArray(NUM5, *array5);
    auto start5 = chrono::steady_clock::now();
    anyEqual(NUM5, *array5);
    auto end5 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds5 = end5 - start5; 

    fillArray(NUM6, *array6);
    auto start6 = chrono::steady_clock::now();
    anyEqual(NUM6, *array6);
    auto end6 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds6 = end6 - start6; 

    fillArray(NUM7, *array7);
    auto start7 = chrono::steady_clock::now();
    anyEqual(NUM7, *array7);
    auto end7 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds7 = end7 - start7; 

    fillArray(NUM8, *array8);
    auto start8 = chrono::steady_clock::now();
    anyEqual(NUM8, *array8);
    auto end8 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds8 = end8 - start8; 

    //Print table
    cout << "\t\t\tArray Size and Times: \n";
    cout << NUM1 << "\t" << NUM2 << "\t" << NUM3 << "\t" << NUM4 << "\t" << NUM5 << "\t" << NUM6 << "\t" << NUM7 << "\t" << NUM8 << endl;
    cout << elapsed_seconds1.count() << "\t" << elapsed_seconds2.count() << "\t" << elapsed_seconds3.count() << "\t" << elapsed_seconds4.count() << "\t";
    cout << elapsed_seconds5.count() << "\t" << elapsed_seconds6.count() << "\t" << elapsed_seconds7.count() << "\t" << elapsed_seconds8.count() << endl;

    return 0;
}

void fillArray(const int n, int* A)
{
    int loop = 20;
    srand(0);

    for (int count = 0; count < n; count++)         //need to add another nested loop here?  
    {
        for (int counter = 0; counter < loop; counter++)
        {
            A[count][counter] = (rand() % loop);
        }
    }
}

int anyEqual(const int n, int* A)
{
    int i,j,k,m;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= n; k++)
            {
                for (m = 1; m <= n; m++)
                {
                    if (A[i][j] == A[k][m] && !(i == k && j == m))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}