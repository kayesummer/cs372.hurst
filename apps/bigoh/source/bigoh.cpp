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
void initializeArray(const int, int**);
int anyEqual(const int, int**);
double fillAndTest(const int, int**);
void clearArray(const int, int**);


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
    double average1 = 0;
    double average2 = 0;
    double average3 = 0;
    double average4 = 0;
    double average5 = 0;
    double average6 = 0;
    double average7 = 0;
    double average8 = 0;
    
    //double pointer array initialization
    int ** array1 = new int*[NUM1];
    initializeArray(NUM1, array1);
    int ** array2 = new int*[NUM2];
    initializeArray(NUM2, array2);
    int ** array3 = new int*[NUM3];
    initializeArray(NUM3, array3);
    int ** array4 = new int*[NUM4];
    initializeArray(NUM4, array4);
    int ** array5 = new int*[NUM5];
    initializeArray(NUM5, array5);
    int ** array6 = new int*[NUM6];
    initializeArray(NUM6, array6);
    int ** array7 = new int*[NUM7];
    initializeArray(NUM7, array7);
    int ** array8 = new int*[NUM8];
    initializeArray(NUM8, array8);

    //call functions to fill array & then time algorithm
    average1 = fillAndTest(NUM1, array1);

    average2 = fillAndTest(NUM2, array2);

    average3 = fillAndTest(NUM3, array3);

    average4 = fillAndTest(NUM4, array4);

    average5 = fillAndTest(NUM5, array5);

    average6 = fillAndTest(NUM6, array6);

    average7 = fillAndTest(NUM7, array7);

    average8 = fillAndTest(NUM8, array8);
   
    //Print table
    cout << setprecision(8) << fixed << showpoint;
    cout << "    Array Size and Average Times: \n";
    cout << "\tSize:\tAverage Time:\n";
    cout << "\t" << NUM1 << "\t" << average1 << endl;
    cout << "\t" << NUM2 << "\t" << average2 << endl;
    cout << "\t" << NUM3 << "\t" << average3 << endl;
    cout << "\t" << NUM4 << "\t" << average4 << endl;
    cout << "\t" << NUM5 << "\t" << average5 << endl;
    cout << "\t" << NUM6 << "\t" << average6 << endl;
    cout << "\t" << NUM7 << "\t" << average7 << endl;
    cout << "\t" << NUM8 << "\t" << average8 << endl;

    //delete the pointers
    clearArray(NUM1, array1);
    clearArray(NUM2, array2);
    clearArray(NUM3, array3);
    clearArray(NUM4, array4);
    clearArray(NUM5, array5);
    clearArray(NUM6, array6);
    clearArray(NUM7, array7);
    clearArray(NUM8, array8);
    
    return 0;
}

void initializeArray(const int n, int** A)
{
    for (int count = 0; count < n; count++)
    {
        A[count] = new int[n];
    }
}

double fillAndTest(const int n, int** A)
{
    int loop = 20;
    srand(0);
    double sum = 0;
    double average = 0;
    int result = 0;

    for (int count = 0; count < n; count++)   
    {
        for (int counter = 0; counter < n; counter++) 
        {
            A[count][counter] = (rand() % loop);
        }
    }
    for (int counting = 0; counting < loop; counting++)
    {
        auto start = chrono::steady_clock::now();
        result = anyEqual(n, A);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end - start; 
        sum += elapsed_seconds.count();
    }
    average = sum / loop;
    return average;
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

void clearArray(const int n, int** A)
{
    for (int count = 0; count < n; count++)
    {
        delete[] A[count];
        A[count] = nullptr;
    }
    delete[] A;
    A = nullptr;
}