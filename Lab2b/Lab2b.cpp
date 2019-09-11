//Victoria Todd, Jayson Morgado, Shaun Shahan
//TA: Lauren Olson
// 09/4/19
// CISC220 Lab 2b/ Homework 1===========================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
void star ();
void func(int *x, int size);
void printArray(int x[], int size);
void problem1(int x, int &y);
void problem2(int x);
void problem3(int x, int y);
int &problem4();

int main() {
//Lab 2b: problem 1
//*******************************************************************
	star ();
	cout << "problem #1"<<endl;
	int size = 5;
	int low=-1;
	problem1(size, low);
	cout << "low = "<< low<< endl;

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
	star ();
	cout << "problem #4"<<endl;
	int *y = &problem4();
	cout << "the value of the parameter is " << y << endl;
	cout << "the address of the parameter is " << &y << endl;

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
int &problem4(){
	int y = 3;
	cout << "the value of the parameter is " << y << endl;
	cout << "the address of the parameter is " << &y << endl;
	return y;
}












void printArray(int x[], int size){
	cout<<"{";
	for (int i = 0; i<size; i++){
	if(i<size-1)
		cout<<x[i]<< ",";  //prints each element in the array. except the last element
	else
		cout<<x[i]; // prints the last element in the array.
	}
	cout << "}"<< endl;
}























	void star () {
		cout << "***********************************************" << endl;}
