/*Christopher Unger
CSC 205 - E1
Test Score Analyzer
Create arrays with functions that calculate and display output*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes
void getData(int[], int[], int);
void calculate(int[], int[], int[], const int, const int);
double findAverage(const int[], const int);
void Display(int[], int[], int[], const int[], double, const int);
int findHigh(const int[], const int);

int main()
{
	const int NUM_Q = 50;				// Constant Number of Questions
	const int NUM_STUDENTS = 5;			// Constant Number of Students
	int id[NUM_STUDENTS];				// Student ID Numbers Array
	int correct[NUM_STUDENTS];			// Number Correct answers Array
	int incorrect[NUM_STUDENTS];		// Number Incorrect answer Array
	int score[NUM_STUDENTS];			// Student Score Array
	double average;						// Variable holds the average score
	int high;							// Variable holds the highest score

	getData(id, correct, NUM_STUDENTS);								// Call Function
	calculate(correct, incorrect, score, NUM_Q, NUM_STUDENTS);		// Call Function
	average = findAverage(score, NUM_STUDENTS);						// RV Call Function
	Display(id, correct, incorrect, score, average, NUM_STUDENTS);	// Call Function
	high = findHigh(score, NUM_STUDENTS);							// RV Call Function

	// Display Highest Score
	cout << "Highest Score: " << right << fixed << setw(12) << high << endl << endl;

	system("pause");

	return 0;
}

void getData(int id[], int correct[], int NUM_STUDENTS)
// Function to get values for ID and Correct Answers Arrays
{
	for (int count = 0; count < NUM_STUDENTS; count++)
	{
		cout << "Enter Student " << (count+1) << "'s ID Number:  ";
		cin >> id[count];
		cout << "Enter Number of Correct Answers for Student " << (count + 1) <<":  ";
		cin >> correct[count];
	}
}

void calculate(int correct[], int incorrect[], int score[], const int NUM_Q, const int NUM_STUDENTS)
// Function to calculate number of incorrect answers, score, and create Array for both.
{
	// Calculate number of incorrect answers
	for (int index = 0; index < NUM_STUDENTS; index++)
		incorrect[index] = NUM_Q - correct[index];

	// Calculate score
	for (int i = 0; i < NUM_STUDENTS; i++)
		score[i] = correct[i] * 2;
}

double findAverage(const int score[], const int NUM_STUDENTS)
// RV Function calculates the average of the scores
{
	int sum = 0;		// Gather scores for running total
	for (int total = 0; total < NUM_STUDENTS; total++)
		sum += score[total];

	//Calculate average
	double average = (double)sum / NUM_STUDENTS;

	return average;
}

void Display(int id[], int correct[], int incorrect[], const int score[], double average, const int NUM_STUDENTS)
// Function Displays output
{
	system("cls");

	// Display Output
	cout << " ID	Correct Answers		Incorrect Answers	     Score	" << endl;

	for (int i = 0; i < NUM_STUDENTS; i++)
		cout << right << fixed << id[i] << right << setw(12) << correct[i] << setw(26) << incorrect[i]
		<< setw(23) << score[i] << endl;

	// Display Average
	cout << "\n  SUMMARY REPORT" << endl << endl;
	cout << "Test Score Average:	" << right << fixed << showpoint << setprecision(2)
		<< setw(6) << average << endl;
}

int findHigh(const int score[], const int NUM_STUDENTS)
// RV Function finds Highest Score
{
	int high = score[0];
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		if (score[i] > high)
			high = score[i];
	}
	return high;
}