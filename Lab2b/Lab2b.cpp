//Victoria Todd, Jayson Morgado, Shaun Shahan
//TA: Lauren Olson
// 09/4/19
// CISC220 Lab 2b===========================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
void star ();
void func(int *x, int size);
//void printArray(int x[], int size);
void problem1(int x, int &y);
void problem2(int x);
void problem3(int x, int y);
int *problem4();
void printArray (int *arr, int size);
int* arrayOnHeap (int *size, int *high, int *low);
void valueInArray (int *num, int size);
void valueInArrayDouble (double *num, int size);
int* modifyArraySize (int *array, int *size);
int hanningWindow11(int arr[], int len, int window);
int * hanningWindow12(int arr[], int length,int window);
void func13(int arr[], int length, int high, int low);
int** func14(int *x, int *y);


int main() {
//Lab 2b: problem 1
//*******************************************************************
	star ();
	cout << "problem #1"<<endl;
	int sizeOf = 5;
	int lowest=-1;
	problem1(sizeOf, lowest);
	cout << "lowest = "<< lowest<< endl;

//Lab 2b: problem 2
//*******************************************************************
	star ();
	cout << "problem #2"<<endl;
	problem2(8);


//Lab 2b: problem 3
//*******************************************************************
	star ();
	cout << "problem #3"<<endl;
	problem3(9,51);
	cout<<endl;

//Lab 2b: problem 4
//*******************************************************************
	star();
	cout << "problem #4"<<endl;
	int *y = problem4();
	cout << "the value of the parameter is " << y << endl;
	cout << "the address of the parameter is " << &y << endl;

	//Yes this compiles. No this doesn't work, the pointer contains a different address than the one assigned to it via the return.

//Lab 2b: problem 5
//*******************************************************************
	star();
	cout<<("Problem 5a&b")<<endl;
	int array [25];
	for (int i = 0; i<25; i++)
		{
			array[i] = (rand() % 10) +1;
		}
		printArray (array, 25);

		star();

//	****************(DONT INCLUDE THESE)**********

	cout<<("Problem 6")<<endl;
		int size = 5;
		int high = 9;
		int low = -6;
		int *array1 = arrayOnHeap (&size, &high, &low);
		printArray(array1, size);

		star();

//********************************************

		cout<<("Problem 8")<<endl;
		int array30 [3] = { 4,7,9};
		int array31 [4] = {6,7,3,9};
		valueInArray(array, 25);
		valueInArray (array30, 3);
		valueInArray (array31, 4);
		star();

//	******************************************

		cout<<("Problem 9")<<endl;

		double array2 [5] = {2.0, 3.7,2.9,4.6,1.5};
		valueInArrayDouble(array2, 5);
		double array20 [6] = {2.0,3.7,2.9,4.6,1.5,2.8};
		valueInArrayDouble(array20, 5);
		double array21 [4] = {2.0, 3.7,2.9,4.6};
		valueInArrayDouble(array21, 5);



		star();

//***********************************************
		cout<<("Problem 10")<<endl;
		//
		int size2 = 5;
		int array3 [] = {2,2,3,3,4};
		printArray(array3,size2);
		printArray(modifyArraySize (array3, &size2),size2 -2);

		star();
		int array4 []= {2,3,4};
		int size3 = 3;
		printArray(array4,size3);
		printArray(modifyArraySize (array4, &size3), size3);



		star();
		int array99 [] = {7,7,5,4,4,3,8};
		int size99 = 7;
		printArray(array99,size99);
		printArray(modifyArraySize (array99, &size99), size99-2);


//***********************************************
		int arr1[] = {3,8,2,5,1,4,6,0,2};
		cout << "problem 11: " << hanningWindow11(&arr1[0],9,5) << endl;


//***********************************************
		cout << "problem 12: " << endl;
		hanningWindow12(&arr1[0],9,5);


//***********************************************
		cout << "problem 13: " << endl;
		printArray(arr1,9);
		func13(arr1, 9, 8,0);


//***********************************************
		cout << "problem 14: " << endl;
		int x;
		int ss;

		int **arr = func14(&x,&ss);
		for(int j=0; j<x; j++){ // prints the array.
				for(int i=0; i<ss; i++){
			cout << arr[j][i];
		}
		cout << endl;
		}
}

//Lab 2b: problem 1
//*******************************************************************
void problem1(int x, int &y){
	srand(time(NULL)); // calls random number generator
	int arr[x];//intializes array of length x;
	y=51; // sets y equal a number larger than any number in the array
	for (int i=0; i<x; i++){ // changes the value of each element in the array
		arr[i]=rand()%50; // creates a random number and stores it at element i
		if(y>arr[i]){ 	//stores the lowest value in i, evaluates each element as it goes through the loop.
			y=arr[i];
		}

	}
	printArray(arr, x);
}


//Lab 2b: problem 2
//*******************************************************************
void problem2(int x){
		srand(time(NULL)); // calls random number generator
		int arr[x];//intializes array of length x;
		for (int i=0; i<x; i++){ // changes the value of each element in the array
			arr[i]=rand()%50;
		}
		printArray(arr,x);

		int swap = 0;
		for (int i=0; i<=x/2; i++){ // changes the value of each element in the array
				swap = arr[i];
				arr[i]=arr[x-i];
				arr[x-i]=swap;
		}
		printArray(arr+1,x);// need to understand why I need the +1...
}

//Lab 2b: problem 3
//*******************************************************************
void problem3(int x, int y){
	srand(time(NULL)); // calls random number generator
	int arr[x];//intializes array of length x;
	for (int i=0; i<x; i++){ // changes the value of each element in the array
		arr[i]=rand()%y;
	}
	printArray(arr,x);

	for (int j=0; j<x;j++){//sorts array lowest to highest. prints the arr[j] after lowest available value is located.
		for (int l=j+1; l<x;l++){//this loop swap arr[j] with the next lowest value
			if (arr[j]>arr[l]){//swap logic
				y= arr[j];
				arr[j]=arr[l];
				arr[l]= y;
				}
			}
	cout << arr[j] << " " ; // prints each element in the reordered array.
		}

}

//Lab 2b: problem 4
//*******************************************************************
int *problem4(){
	int y = 3;
	cout << "the value of the parameter is " << y << endl;
	cout << "the address of the parameter is " << &y << endl;
	return &y;
}

// Problem 5.
// Go through an array and print out each item in the
// array



void printArray (int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i<size-1)
		cout<< ", ";
	}
	cout<<endl;
}



//********************************************
// Problem 6.
//Takes as input parameter 3 integers using call by pointer
//creates an array on the heap of that length, generates a random
//high number between 5 & 10 and random low number between -10 &-5
//fills in array with those random numbers

int* arrayOnHeap (int *size, int *high, int *low)
{
	*size = ((rand () % 50) + 25);
	int * array;
	array = new int [*size];
	*low = ((rand() % 5) -9);
	*high = ((rand () % 5)+5);

	for ( int i = 0; i < *size; i++)
	{
		array[i] = rand () % (*high - *low) + *low;
	}
	return array;

}

//********************************************
// Problem 7.
// This fails because the variables are not stored on the heap
// therefore the array cannot be returned because it no longer
// exists since it was not allocated memory after the function
// runs.

/*int* arrayOnStack (int size)

{
	int array [size];
	int low = ((rand() % 5) -9);
	int high = ((rand () % 5)+5);

	for (int i = 0; i <size; i++)
	{
		array[i] = rand () % (*high - *low) + *low;
	}
	return array;
}
*/

//**LEAVE THIS COMMENTED OUT**

//**********************************************
//Problem 8.
//Takes an input paramter an array of integers and size of the array
//function prints out the address of each value in array

void valueInArray (int *num, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout<< &num[i]<< endl;
	}
}

//******************************************
//Problem 9.
//Takes an input parameter an array of doubles
// function prints out address of each value in array

void valueInArrayDouble (double *num, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout<< &num[i]<< endl;
	}
}

//********************************************
//Problem 10.
//Takes an input paramter an array of integers and size of array as pointers
//goes through array on heap and removes all doubles and returns a newly created
//array
int* modifyArraySize (int *array, int *size)
{
	int *arrayNew = new int [*size];
	int newSize = *size;
	for (int i = 0, j=0; i < *size; i++ )
	{
		if ( array[i] == array[i+1])
		{
			newSize --;
		} else if (i == *size -1)
		{
			if (array[i] == array [i-1])
				arrayNew[j] = array[i];
			else{
					arrayNew[j] = array[i];
					j++;
					}
		}
		else{
		arrayNew[j] = array[i];
		j++;
		}
	}
	*size = newSize;
	return arrayNew;
}

//**********************************************************
int hanningWindow11(int arr[],int len, int window){
int length = window/2 + 1;
int sum = 0;
int multiplier = 1;
int index = 0;
while(multiplier <= length){
if(multiplier == length){
sum = multiplier * arr[index] + sum;
}
else{
sum =  (multiplier * arr[0 + index] + multiplier * arr[window - (1 +index)]) + sum;
}
multiplier++;
index++;
}
int avg = sum / len;

return avg;
}

//************************************************************
int* hanningWindow12(int arr[], int length, int window){
int filter[length];
for(int i = 0; i < length; i++){
if(i < window/2 || length - i <= window/2)
filter[i] = 0;
if(i > length - window/2)
break;
filter[i + window/2] = hanningWindow11(&arr[i], length, window);
}
for(int i = 0; i < 9; i++){
cout << filter[i] << endl;
}
return filter;
}


void func13(int arr[], int length, int high, int low){
	int rows = high - low;
	char graph[rows][length];
	for(int c = high; c>low-1; c--){ // specifies row
		cout<<c<<":";
		for(int r = 0; r < rows; r++){ // specifies column
			if(arr[r] == c){ // prints star when the index number for the element matches the row number.
				cout << "*"; //
				break;
			}
			else
				cout << " "; //prints spaces when the element number doesn't match the row number.
		}
		cout <<endl;
	}

}

int** func14(int* num1, int* num2){
	*num1 = rand() % 6 + 5; // determines dimensions of the array
	*num2 = rand() % 5 + 4; // determines dimensions of the array
	int **arr = 0;
	arr = new int *[*num1]; // creates 2d array on the heap.
	for (int i = 0; i < *num1; i++) {
		arr[i] = new int[*num2];
	} //for
	for(int j = 0; j < *num1; j++){ // sets all elements in the arry to 0
		for(int k = 0; k < *num2; k++){
			arr[j][k] = 0;
		}
	}
	int i = 0;
	int r,c;
	while(i < 5){
		r = rand() % *num1;
		c = rand() % *num2;
		for(int j = 0; j < *num1; j++){//sets 5 random number pairs(coordinates) to 1 in the 2d array.
			for(int k = 0; k < *num2; k++){
				if(r == j && c == k && arr[j][k] != 1){
					arr[j][k] = 1;
				}//if
			}//for
		}//for
		i++;
	}//while
	return arr;
	}


	void star () {
		cout << "***********************************************" << endl;}
