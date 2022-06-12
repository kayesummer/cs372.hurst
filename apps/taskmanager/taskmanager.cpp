//
// File:   taskmanager.cpp
// Author: Kaylee Hurst
// Purpose:
// Create a menu-driven task manager that allows user to display all items, 
// display selected item, mask a task as done, or exit the program.
//

#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>
#include "vector.h"
using namespace std;

struct ReadingRow
{
    int taskNumber;     //my list starts at 0
    char status; 
    string description;
};

Vector<ReadingRow> taskData;

//function prototypes
bool readData();
int getChoice();
void displayAll();
void displaySelected();
void completeTask();
void updateFile();

//global variables
const string DATAFILE = "todo.txt";
int Choice = 0;


int main ()
{
    
    bool goodRead = readData();
    if (goodRead)
    {
        int taskChoice = 0;
        
        do
        {
            Choice = getChoice();
            switch(Choice)
            {
                case 1:
                displayAll();
                break;

                case 2:
                displaySelected();
                break;

                case 3:
                completeTask();
                break;
            }
        } while (Choice != 4);
        
        updateFile();
        return 0;
    }
    else 
    {
        cout << "Error reading text file." << endl;
    }
     

    return 0;
}

bool readData()
{
    bool goodRead = true;
    ReadingRow tempRow;
    ifstream inFile;

    inFile.open(DATAFILE);
    if (inFile.is_open())
    {
        inFile >> tempRow.taskNumber >> tempRow.status >> tempRow.description;
        while (!inFile.eof())
        {
            taskData.push_back(tempRow);
            inFile >> tempRow.taskNumber >> tempRow.status >> tempRow.description;
        }
        inFile.close();
    }
    else
    {
        cerr << "Error: Unable to open data file \n";
        goodRead = false;
    }
    return goodRead;
}

int getChoice()
{
    int choice = 0;
    cout << "Welcome to your Task Manager! \n";
    cout << "Please enter your selection: \n";
    cout << "\t (1) Display full To-Do List \n";
    cout << "\t (2) Display a specific task \n";
    cout << "\t (3) Mark a task as done \n";
    cout << "\t (4) Exit the program \n";
    cin >> choice;
    while (choice < 1 || choice > 4)
    {
        cout << "Error: Choice must be an integer between 1 and 4: \n";
        cin >> choice;
    }

    return choice;
}

void displayAll()
{
    for (int count = 0; count < taskData.size(); count++)
    {
        cout << taskData[count].taskNumber << " " << taskData[count].status << " " << taskData[count].description << endl;
    }
}

void displaySelected()
{
    int taskChoice = 0;
    cout << "What is the task number you would like to view? \n";
    cin >> taskChoice;
    while (taskChoice < 0 || taskChoice > taskData.size())
    {
        cout << "Error: That is not a valid task number: \n";
        cin >> taskChoice; 
    }
    cout << taskData[taskChoice].taskNumber << " " << taskData[taskChoice].status << " " << taskData[taskChoice].description << endl;    
}

void completeTask()
{   
    int taskChoice = 0;
    cout << "What is the task number you would like to mark as done? \n";
    cin >> taskChoice;
    while (taskChoice < 0 || taskChoice > taskData.size())
    {
        cout << "Error: That is not a valid task number: \n";
        cin >> taskChoice; 
    }
    taskData[taskChoice].status = 'D';
}

void updateFile()
{

}