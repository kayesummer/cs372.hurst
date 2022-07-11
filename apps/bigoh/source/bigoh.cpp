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
double fillArray(const int, int**);


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
    average1 = fillArray(NUM1, array1);
    auto start1 = chrono::steady_clock::now();
    if (anyEqual(NUM1, array1) == 1)
    {
        cout << "Array1 has a pair of matching values.\n";
    }
    else //anyEqual(NUM1, array1) == 0
    {
        cout << "Array1 has no matching values.\n";
    }
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start1; 

    average2 = fillArray(NUM2, array2);
    auto start2 = chrono::steady_clock::now();
    if (anyEqual(NUM2, array2) == 1)
    {
        cout << "Array2 has a pair of matching values.\n";
    }
    else //anyEqual(NUM2, array2) == 0
    {
        cout << "Array2 has no matching values.\n";
    }
    auto end2 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2; 

    average3 = fillArray(NUM3, array3);
    auto start3 = chrono::steady_clock::now();
    if (anyEqual(NUM3, array3) == 1)
    {
        cout << "Array3 has a pair of matching values.\n";
    }
    else //anyEqual(NUM3, array3) == 0
    {
        cout << "Array3 has no matching values.\n";
    }
    auto end3 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds3 = end3 - start3; 

    average4 = fillArray(NUM4, array4);
    auto start4 = chrono::steady_clock::now();
    if (anyEqual(NUM4, array4) == 1)
    {
        cout << "Array4 has a pair of matching values.\n";
    }
    else //anyEqual(NUM4, array4) == 0
    {
        cout << "Array4 has no matching values.\n";
    }
    auto end4 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds4 = end4 - start4; 

    average5 = fillArray(NUM5, array5);
    auto start5 = chrono::steady_clock::now();
    if (anyEqual(NUM5, array5) == 1)
    {
        cout << "Array5 has a pair of matching values.\n";
    }
    else //anyEqual(NUM5, array5) == 0
    {
        cout << "Array5 has no matching values.\n";
    }
    auto end5 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds5 = end5 - start5; 

    average6 = fillArray(NUM6, array6);
    auto start6 = chrono::steady_clock::now();
    if (anyEqual(NUM6, array6) == 1)
    {
        cout << "Array6 has a pair of matching values.\n";
    }
    else //anyEqual(NUM6, array6) == 0
    {
        cout << "Array6 has no matching values.\n";
    }
    auto end6 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds6 = end6 - start6; 

    average7 = fillArray(NUM7, array7);
    auto start7 = chrono::steady_clock::now();
    if (anyEqual(NUM7, array7) == 1)
    {
        cout << "Array7 has a pair of matching values.\n";
    }
    else //anyEqual(NUM7, array7) == 0
    {
        cout << "Array7 has no matching values.\n";
    }
    auto end7 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds7 = end7 - start7; 

    average8 = fillArray(NUM8, array8);
    auto start8 = chrono::steady_clock::now();
    if (anyEqual(NUM8, array8) == 1)
    {
        cout << "Array8 has a pair of matching values.\n";
    }
    else //anyEqual(NUM8, array8) == 0
    {
        cout << "Array8 has no matching values.\n";
    }
    auto end8 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds8 = end8 - start8; 

    //Print table
    cout << "\t\t\tArray Size and Average Times: \n";
    cout << NUM1 << "\t" << NUM2 << "\t" << NUM3 << "\t" << NUM4 << "\t" << NUM5 << "\t" << NUM6 << "\t" << NUM7 << "\t" << NUM8 << endl;
    cout << average1 << "\t" << average2 << "\t" << average3 << "\t" << average4 << "\t" << average5 << "\t" << average6 << "\t" << average7 << "\t" << average8 << endl;

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

double fillArray(const int n, int** A)
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
            for (int counting = 0; counting < loop; counting++)
            {
                auto start = chrono::steady_clock::now();
                result = anyEqual(n, A);
                auto end = chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = end - start; 
                sum += elapsed_seconds.count();
                if (result == 1)
                {
                    cout << "Array has a pair of matching values.\n";
                }
                else //result == 0
                {
                    cout << "Array has no matching values.\n";
                }

            }
            
        }
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