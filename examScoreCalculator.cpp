// Program Description
/*
This program stores grades for a number of students (determined by user). Individual letter
grade averages are calculated for each student. Overall class grade average is calculated.
A tabular report is formatted and displayed at the end of the program.
*/


#include <iostream>				// for cin, cout, endl;
#include <iomanip>              // for formatting output;
#include <string>
using namespace std;


// Global Constant
const int SCORE_COUNT = 3;

struct Student
{
	string studentName;
	int testScore1;
	int testScore2;
	int testScore3;
};


// Function Prototype
void getNumOfStudents(int& numOfStudents);
void initializeArray(int& numOfStudents, int& scoreCounter, Student* ptr);
void getStudentName(Student* ptr, int& count);
void getTestScore1(Student* ptr, int& count);
void getTestScore2(Student* ptr, int& count);
void getTestScore3(Student* ptr, int& count);
int averageOfAllScores(int& numOfStudents, int& scoreCounter, Student* ptr);
void individualAverage(int& numOfStudents, Student* ptr, string* ptr_letterGrades);
string determineLetterGrade(int studentAverage);
void displayOutput(int& averageScore, int& numOfStudents, Student* ptr, string* ptr_letterGrades);
void sortArray(int& numOfStudents, Student* ptr);
void swapGrades(int& currentScore, int& nextScore);

int main()
{
	// Declare variables
	int numOfStudents;
	int studentAverage;
	int averageScore;

	// Initialize score counter
	int scoreCounter = 0;

	// Call function; Pass argument by reference
	getNumOfStudents(numOfStudents);

	// Dynamically allocate an array of structs 
	// large enough to hold that many number of students
	Student* ptr = new Student[numOfStudents];

	// Dynamically allocate an array of strings
	// large enough to hold that many number of letter grades
	string* ptr_letterGrades = new string[numOfStudents];

	// Function calls
	initializeArray(numOfStudents, scoreCounter, ptr);

	sortArray(numOfStudents, ptr);

	individualAverage(numOfStudents, ptr, ptr_letterGrades);

	// Function call; Store returning value in averageScore
	averageScore = averageOfAllScores(numOfStudents, scoreCounter, ptr);

	// Function call
	displayOutput(averageScore, numOfStudents, ptr, ptr_letterGrades);

	return 0;
}// end of main


// Functions below

// This function prompts,gets, and validates input for number of students
void getNumOfStudents(int& numOfStudents) {
	// Declare flag
	bool flag;

	// Loop until valid input is accepted
	do {
		//Initialize flag
		flag = true;

		// prompt user
		cout << "Enter number of students to be processed: ";
		// Get input
		cin >> numOfStudents;

		// Check if input is invalid
		if (cin.fail() || numOfStudents < 0) {
			cout << "Invalid input. Enter a non-negative integer.\n" << endl;
			flag = false;
		} // End of if block

		// Reset stream state
		cin.clear();

		// Ignore to the end of the line
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (!flag); // End of do-while loop

} // End of getNumOfStudents

// This function initializes the array of structs through function calls
void initializeArray(int& numOfStudents, int& scoreCounter, Student* ptr) {
	for (int count = 0; count < numOfStudents; count++) {

		// Call function; Pass pointer and counter variable
		getStudentName(ptr, count);

		// Call function; Pass pointer and counter variable
		getTestScore1(ptr, count);

		// Reset stream state
		cin.clear();

		// Ignore to the end of the line
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Increment scoreCounter after each valid input
		scoreCounter++;

		// Call function; Pass pointer and counter variable
		getTestScore2(ptr, count);

		// Reset stream state
		cin.clear();

		// Ignore to the end of the line
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Increment scoreCounter after each valid input
		scoreCounter++;

		// Call function; Pass pointer and counter variable
		getTestScore3(ptr, count);

		// Increment scoreCounter after each valid input
		scoreCounter++;

		// Reset stream state
		cin.clear();

		// Ignore to the end of the line
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} // End of for loop
} // End of initializeArray

// This function prompts, gets, validates input for student name
void getStudentName(Student* ptr, int& count) {
	//temp variable
	string fullName;

	// Loop until valid input is accepted for student name
	do {
		// Prompt for student name
		cout << "\n\nEnter student name: ";
		// Get input
		getline(cin, fullName);

		// Check if input is more than 30 character
		if (fullName.length() > 30) {
			// Display informative error message
			cout << "Invalid name. Student name cannot be greater than 30 characters." << endl;

			// Set current name element to null
			(ptr + count)->studentName = "";
		} // End of if block

		// If input is valid, assign literal to current element in array
		else {
			(ptr + count)->studentName = fullName;
		} // End of else block

	} while ((ptr + count)->studentName == "");  // End of do-while loop

} // End of getStudentName

// This function prompts, gets, and validates input for test score 1
void getTestScore1(Student* ptr, int& count) {
	do {
		// Prompt user
		cout << "Enter Test score #1: ";
		// Get input
		cin >> (ptr + count)->testScore1;

		if ((ptr + count)->testScore1 < 0 || (ptr + count)->testScore1 > 110 || cin.fail()) {
			// Display informative error message
			cout << "Invalid value. Score must be between 0-110 inclusive." << endl;

			// Assign -1 to testScore1
			(ptr + count)->testScore1 = -1;

			// Reset stream state
			cin.clear();
			// Ignore to the end of the line
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} // End of if block
	} while ((ptr + count)->testScore1 < 0); // End of do-while loop
} // End of getTestScore1

// This function prompts, gets, and validates input for test score 2
void getTestScore2(Student* ptr, int& count) {
	do {
		// Prompt user
		cout << "Enter Test score #2: ";
		// Get input
		cin >> (ptr + count)->testScore2;

		if ((ptr + count)->testScore2 < 0 || (ptr + count)->testScore2 > 110 || cin.fail()) {
			// Display informative error message
			cout << "Invalid value. Score must be between 0-110 inclusive." << endl;

			// Assign -1 to testScore1
			(ptr + count)->testScore2 = -1;

			// Reset stream state
			cin.clear();
			// Ignore to the end of the line
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} // End of if block
	} while ((ptr + count)->testScore2 < 0); // End of do-while loop
} // End of getTestScore2

// This function prompts, gets, and validates input for test score 3
void getTestScore3(Student* ptr, int& count) {
	do {
		// Prompt user
		cout << "Enter Test score #3: ";
		// Get input
		cin >> (ptr + count)->testScore3;

		if ((ptr + count)->testScore3 < 0 || (ptr + count)->testScore3 > 110 || cin.fail()) {
			// Display informative error message
			cout << "Invalid value. Score must be between 0-110 inclusive." << endl;

			// Assign -1 to testScore1
			(ptr + count)->testScore3 = -1;

			// Reset stream state
			cin.clear();
			// Ignore to the end of the line
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} // End of if block
	} while ((ptr + count)->testScore3 < 0); // End of do-while loop
} // End of getTestScore3

//This function calculates indivdual numerical averages for each student
void individualAverage(int& numOfStudents, Student* ptr, string* ptr_letterGrades) {
	// Declare variables
	int studentAverage;
	int sumOfScores;

	for (int count = 0; count < numOfStudents; count++) {
		// Initialize running total
		sumOfScores = 0;

		// Sum of each student's scores
		sumOfScores = sumOfScores + (ptr + count)->testScore1 + (ptr + count)->testScore2 + (ptr + count)->testScore3;

		// Divide sum of scores by number of scores
		studentAverage = sumOfScores / SCORE_COUNT;

		// Call function and store returning string into letterGrades array (Pointer notation)
		ptr_letterGrades[count] = determineLetterGrade(studentAverage);

	} // End of for loop
} // End of indivudalAverage

// This function determines an individual student's letter grade from numerical average
string determineLetterGrade(int studentAverage) {
	string letterGrade;

	// Determine letter grade
	if (studentAverage >= 90) {
		letterGrade = "A";
	} // End of if block
	else if (studentAverage >= 80) {
		letterGrade = "B";
	} // End of else if
	else if (studentAverage >= 70) {
		letterGrade = "C";
	}
	else if (studentAverage >= 60) {
		letterGrade = "D";
	}
	else {
		letterGrade = "F";
	} // End of else block

	return letterGrade;
} // End of determineLetterGrade

// Value returning function that calculates average of all test scores
int averageOfAllScores(int& numOfStudents, int& scoreCounter, Student* ptr) {
	// Declare variable
	int averageScore;
	// Initialize running total
	int sumOfScores = 0;

	// Loop through array
	for (int count = 0; count < numOfStudents; count++) {
		// Sum all three test scores from each student
		sumOfScores = sumOfScores + (ptr + count)->testScore1 + (ptr + count)->testScore2 + (ptr + count)->testScore3;
	} // End of for loop

	// Calculate Average
	averageScore = sumOfScores / scoreCounter;

	return averageScore;
} // End of averageOfAllScores

// This function displays in tabular format name, grades, letter grade, and average
void displayOutput(int& averageScore, int& numOfStudents, Student* ptr, string* ptr_letterGrades) {
	// Display column headers
	cout << left << setw(30) << "\n\nName";
	cout << left << setw(20) << "Grades";
	cout << left << setw(20) << "Letter Grade" << endl;

	// Loop through array
	for (int count = 0; count < numOfStudents; count++) {
		// Display name, scores, and letter grade in tabular format
		cout << left << setw(28) << (ptr + count)->studentName;
		cout << left << setw(2) << (ptr + count)->testScore1 << left << setw(1) << ", " << left << setw(2) << (ptr + count)->testScore2 << left << setw(1) << ", " << left << setw(17) << (ptr + count)->testScore3;
		cout << left << setw(20) << ptr_letterGrades[count] << endl;
	} // End of for loop

	// Display average of all grades
	cout << "-------------------------------------------------" << endl;
	cout << left << setw(30) << "Average";
	cout << left << setw(20) << averageScore << endl;
} // End of displayOutput

// This function compares each of the three scores in a single object for all objects in the array of structs
void sortArray(int& numOfStudents, Student* ptr) {
	// intialize bool variable that allows for the for loop to start iterating
	bool madeAswap = true;

	for (int maxCount = numOfStudents; maxCount > 0 && madeAswap; maxCount--) {
		// No swaps have occured yet
		madeAswap = false;

		for (int index = 0; index < maxCount; index++) {
			// Loop iterates until all three scores in a single object are in ascending order
			do {
				// Check if testScore1 is greater than testScore2
				if ((ptr + index)->testScore1 > (ptr + index)->testScore2) {
					// Call function pass both test score values as arguments
					swapGrades((ptr + index)->testScore1, (ptr + index)->testScore2);
					madeAswap = true;
				} // End of if block

				// Check if testScore2 is greater than testScore3
				if ((ptr + index)->testScore2 > (ptr + index)->testScore3) {
					// Call function pass both test score values as arguments
					swapGrades((ptr + index)->testScore2, (ptr + index)->testScore3);
					madeAswap = true;
				} // End of second if block

			} while ((ptr + index)->testScore1 > (ptr + index)->testScore2); // End of do-while loop
		} // End of nested for loop

	} // End of outer for loop

} // End of sortArray

// This function swaps two ints in memory
void swapGrades(int& currentScore, int& nextScore) {
	int temp = currentScore;
	currentScore = nextScore;
	nextScore = temp;
} // End of swapGrades