// Classroom Management.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include<iostream>
#include<string>

using namespace std;

double negativemark()                       //function to check if a number is negative.
{
    double student_grade = 0;
    do
    {
        cout << " ";
        cin >> student_grade;
        if (student_grade < 0)
        {
            cout << "Please enter positive grade";
        }
    }     while (student_grade < 0);
    return student_grade;
}

string displayStudentinfo(string name[3][3], int index)         //function to display the first name and the student number.
{
    string fname = "First name:" + name[index][0] + " Student id " + name[index][2];
    return fname;
}

void convertstritoint(string student_info[3][3])                //function to convert the string infomation to int
{
    int i, x;

    string value;
    cout << "\nThe first name , last name and  student id of all student are: ";
    for (i = 0; i < 3; i++)
    {
        int x = stoi(student_info[i][2]);
        if (x % 2 != 0)
        {
            cout << "\n" << student_info[i][0] << "\t" << student_info[i][1] << "\t" << student_info[i][2];
        }
    }
}

double totalgrade(double student_grade[3][5], int i)            //function to calculate a student's total score.
{
    double total_grade;
    total_grade = student_grade[i][0] + student_grade[i][1] + student_grade[i][2] + student_grade[i][3] + student_grade[i][4];
    return total_grade;
}

double calculation(double student_grade[3][5])                  //function to calculate a student's total score.
{
    double total_grad = 0, class_average;
    int i;
    for (i = 0; i < 3; i++)
    {
        total_grad = total_grad + totalgrade(student_grade, i);
        class_average = total_grad / 5;
    }
    return class_average / 3;
}

void information()                                        //Function to display infomation of students before the user enters the marks

{
    cout << "\n Enter the grades for student: ";
}

int main()
{
    string student_info[3][3];                  //First array which stores the student infomation   
    double student_grade[3][5];                 //Second array which stores the student grades
    int i;

    for (i = 0; i < 3; i++)
    {
        cout << "Enter the first name of student " << i + 1;
        cout << "\n Enter the first name: ";
        cin >> student_info[i][0];
        cout << "Enter the last name ";
        cin >> student_info[i][1];
        cout << "Enter the student id: ";
        cin >> student_info[i][2];
    }

    for (i = 0; i < 3; i++)
    {
        information();                          //information function called
        cout << student_info[i][0] << "\t" << student_info[i][2];  
        cout << "\nEnter the midterm grade: ";
        student_grade[i][0] = negativemark();   //negetive function called
        cout << "Enter the final term grade: ";
        student_grade[i][1] = negativemark();   //negetive function called
        cout << "Enter grade of 1st assignment: ";
        student_grade[i][2] = negativemark();   //negetive function called
        cout << "Enter grade of 2nd assignment: ";
        student_grade[i][3] = negativemark();   //negetive function called
        cout << "Enter grade of 3rd assignment: ";
        student_grade[i][4] = negativemark();   //negetive function called
    }

    int method;
    bool exit = false;
    char select;
    while (!exit)
    {
        cout <<
            "\n1)Display the first name and student number for all students."
            "\n2)Display the first name, student number and total grades for a chosen student."
            "\n3)Display first name, last name and student number for all students with an odd student number."
            "\n4)Display the average of the grade for the class."
            "\n5)Quit the program."
            "\nplease select one choice\n";
        cin >> method;

        switch (method)
        {
        case 1:                                                       //displayStudentinfo function called
            for (i = 0; i < 3; i++)
            {
                cout << displayStudentinfo(student_info, i);        
            }
            break;

        case 2:                                                     //displayStudentinfo function and total grade function called
            cout << "please select a choice: ";
            cin >> i;
            cout << displayStudentinfo(student_info, i - 1);
            cout << "total grade is: " << totalgrade(student_grade, i - 1);
            break;
        
        case 3:                                                     //convertstritoint function called
            convertstritoint(student_info);
        break;

        case 4:                                                     // calculation function called
            cout << "class average is: " << calculation(student_grade);
            break;

        case 5:                                                     //Loop exits only if user chooses this case
            exit = true;
            break;

        default:                                                     //default, if user choses incorrect choice
            cout << "Enter correct choice, choose between 1-5 ";
        }
    }
    return 0;
}