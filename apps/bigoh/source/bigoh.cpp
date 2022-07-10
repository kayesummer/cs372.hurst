//
// File:    bigoh.cpp
// Author: Kaylee Hurst & Your Glorious Instructor 
// Purpose:
// Determine the big-oh of the algorithm
//

#include <iostream> 
#include <chrono>
using namespace std; 

//function prototypes 
int anyEqual(const int, int**);
void fillArray(const int, int**);


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
    
    //double pointer array initialization
    int ** array1 = new int*[NUM1];
    for (int count = 0; count < NUM1; count++)
    {
        array1[count] = new int[NUM1];
    }
    int ** array2 = new int*[NUM2];
    for (int count = 0; count < NUM2; count++)
    {
        array2[count] = new int[NUM2];
    }
    int ** array3 = new int*[NUM3];
    for (int count = 0; count < NUM3; count++)
    {
        array3[count] = new int[NUM3];
    }
    int ** array4 = new int*[NUM4];
    for (int count = 0; count < NUM4; count++)
    {
        array4[count] = new int[NUM4];
    }
    int ** array5 = new int*[NUM5];
    for (int count = 0; count < NUM5; count++)
    {
        array5[count] = new int[NUM5];
    }
    int ** array6 = new int*[NUM6];
    for (int count = 0; count < NUM6; count++)
    {
        array6[count] = new int[NUM6];
    }
    int ** array7 = new int*[NUM7];
    for (int count = 0; count < NUM7; count++)
    {
        array7[count] = new int[NUM7];
    }
    int ** array8 = new int*[NUM8];
    for (int count = 0; count < NUM8; count++)
    {
        array8[count] = new int[NUM8];
    }

    //call functions to fill array & then time each algorithm
    fillArray(NUM1, array1);
    auto start1 = chrono::steady_clock::now();
    anyEqual(NUM1, array1);
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start1; 

    fillArray(NUM2, array2);
    auto start2 = chrono::steady_clock::now();
    anyEqual(NUM2, array2);
    auto end2 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2; 

    fillArray(NUM3, array3);
    auto start3 = chrono::steady_clock::now();
    anyEqual(NUM3, array3);
    auto end3 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds3 = end3 - start3; 

    fillArray(NUM4, array4);
    auto start4 = chrono::steady_clock::now();
    anyEqual(NUM4, array4);
    auto end4 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds4 = end4 - start4; 

    fillArray(NUM5, array5);
    auto start5 = chrono::steady_clock::now();
    anyEqual(NUM5, array5);
    auto end5 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds5 = end5 - start5; 

    fillArray(NUM6, array6);
    auto start6 = chrono::steady_clock::now();
    anyEqual(NUM6, array6);
    auto end6 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds6 = end6 - start6; 

    fillArray(NUM7, array7);
    auto start7 = chrono::steady_clock::now();
    anyEqual(NUM7, array7);
    auto end7 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds7 = end7 - start7; 

    fillArray(NUM8, array8);
    auto start8 = chrono::steady_clock::now();
    anyEqual(NUM8, array8);
    auto end8 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds8 = end8 - start8; 

    //Print table
    cout << "\t\t\tArray Size and Times: \n";
    cout << NUM1 << "\t" << NUM2 << "\t" << NUM3 << "\t" << NUM4 << "\t" << NUM5 << "\t" << NUM6 << "\t" << NUM7 << "\t" << NUM8 << endl;
    cout << elapsed_seconds1.count() << "\t" << elapsed_seconds2.count() << "\t" << elapsed_seconds3.count() << "\t" << elapsed_seconds4.count() << "\t";
    cout << elapsed_seconds5.count() << "\t" << elapsed_seconds6.count() << "\t" << elapsed_seconds7.count() << "\t" << elapsed_seconds8.count() << endl;

    //delete the pointers
    for (int count = 0; count < NUM1; count++)
    {
        delete[] array1[count];
    }
    delete[] array1;
    for (int count = 0; count < NUM2; count++)
    {
        delete[] array2[count];
    }
    delete[] array2;
    for (int count = 0; count < NUM3; count++)
    {
        delete[] array3[count];
    }
    delete[] array3;
    for (int count = 0; count < NUM4; count++)
    {
        delete[] array4[count];
    }
    delete[] array4;
    for (int count = 0; count < NUM5; count++)
    {
        delete[] array5[count];
    }
    delete[] array5;
    for (int count = 0; count < NUM6; count++)
    {
        delete[] array6[count];
    }
    delete[] array6;
    for (int count = 0; count < NUM7; count++)
    {
        delete[] array7[count];
    }
    delete[] array7;
    for (int count = 0; count < NUM8; count++)
    {
        delete[] array8[count];
    }
    delete[] array8;
    
    return 0;
}

void fillArray(const int n, int** A)
{
    int loop = 20;
    srand(0);

    for (int count = 0; count < n; count++)   
    {
        for (int counter = 0; counter < n; counter++)
        {
            for (int counting = 0; counting < 20; counting++)
            {
                A[count][counter] = (rand() % loop);
            }
            
        }
    }
}

int anyEqual(const int n, int** A)
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