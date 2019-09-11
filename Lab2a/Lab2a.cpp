//Victoria Todd, Jayson Morgado, Shaun Shahan
//TA: Lauren Olson
// 09/12/19
// CISC220 Lab 2a/===========================================================================


#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void star ();
void swapByPointer(int *m, int *n);
void swapByReference(int &m, int &n);
void problem1();
void problem2(int x);
int problem3();
void problem4(int *x);
void problem5(int &x);
void problem6(int *x, int *y);
void problem7(char *a, char *b, char &c, char *d, char e);
bool problem8a(int *x, int *y);
void problem8b();

int main() {
//Try on computer problem #1
//*******************************************************************
	star ();
	int a = 3;
	cout << a << endl; // variable's value
	cout << &a << endl; // variables memory address
	cout << "a" << endl; // print out variables name
//*******************************************************************

//Try on computer problem #2
//*******************************************************************
	star ();
	int x=3; // creates a variable x
	int *y = &x; // creates a variable that can store an address & sets y equal to the address of x
	cout << *y << endl; //prints out the value the pointer points to
	cout << y << endl; // prints out the address stored in y
	cout << &x << endl; //prints out the variables address
	cout << &y << endl;	// prints out y's memory address
	x=7;//changes the value of x
	cout << *y << endl; //prints out the value the pointer points to

//Try on computer problem #3
//*******************************************************************
	star ();
	*y = 12; // change the vale y points to
	cout << x << endl; // print out x

//Try on computer problem #4
//*******************************************************************
	star ();
	int b = 2; // declare and initialize b
	int c = 4; // declare and initialize c
	cout << b << c << endl; // prints bc
	swapByPointer(&b,&c); // swaps bc
	cout << b << c << endl; // prints bc

//Try on computer problem #5
//*******************************************************************
	star ();
	cout << b << c << endl; // prints bc
	swapByReference(b,c); // swaps bc
	cout << b << c << endl; // prints bc

//Lab Problem #1
//*******************************************************************
	star ();
	cout << "Lab Problem #1"<< endl;
	problem1();

//Lab Problem #2
//*******************************************************************
	star ();
	cout << "Lab Problem #2"<< endl;
	int d = 4;
	problem2(d);//this is a call by value function call

//Lab Problem #3
//*******************************************************************
	star ();
	cout << "Lab Problem #3"<< endl;
	int f = problem3();// sets f equal to a random number.
	cout << " the value of the variable is:"<< f <<endl; // prints the value of the variable f
	cout << " the address of the variable is:"<< &f <<endl; // prints the address of the variable f

//Lab Problem #4
//*******************************************************************
	star ();
	int g = 3;
	cout << " the value at the address is:"<< g <<endl; //prints the value @ address of g
	cout << " the address of the parameter is:"<< &g <<endl; // prints the address of g
	cout << endl;
	problem4(&g); // modifies g using call by reference
	cout << endl;
	cout << " the value at the address is:"<< g <<endl;
	cout << " the address of the parameter is:"<< &g <<endl;

//Lab Problem #5
//*******************************************************************
	star ();
	cout << "Lab Problem #5"<< endl;
	int h = 3;
	cout << " the value at the address is:"<< h <<endl;
	cout << " the address of the parameter is:"<< &h <<endl;
	problem5(h);
	cout << " the value at the address is:"<< h <<endl;
	cout << " the address of the parameter is:"<< &h <<endl;

//Lab Problem #6
//*******************************************************************
	star ();
	cout << "Lab Problem #6"<< endl;
	int j=10, k=20;
	problem6(&j,&k);
	cout << " the value of the first parameter is:"<< j <<endl;
	cout << " the value of the second parameter is:"<< k <<endl;

//Lab Problem #7
//*******************************************************************
	star ();
	// declares char variables, transforms variables via call by pointer, reference & value
	cout << "Lab Problem #7"<< endl;
	char aa = 'e';
	char bb = 'f';
	char cc = 'b';
	char dd = 'o';
	char ee = 'r';
	cout << cc << aa << bb << dd<< ee<<aa<< endl;
	problem7(&aa, &bb, cc, &dd, ee);
	cout << cc << aa << bb << dd<< ee<< endl;

//Lab Problem #8a
//*******************************************************************
	star ();
	cout << "Lab Problem #8a"<< endl;
	int jj = 12;
	int ll = 9;
	problem8a(&jj,&ll);
	cout << "jj:"<< jj<< endl;
	cout << "ll:"<< ll << endl;
	jj = 9;
	ll = 12;
	cout << endl;
	problem8a(&jj,&ll);
	cout << "jj:"<< jj<< endl;
	cout << "ll:"<< ll << endl;

//Lab Problem #8a
//*******************************************************************
	star ();
	cout << "Lab Problem #8b"<< endl;
	problem8b();

}







//Try on computer problem #4
//*******************************************************************
// swaps m & n using call by pointer
void swapByPointer(int *m, int *n){
	int tmp = *m;
	*m=*n;
	*n = tmp;
}
//Try on computer problem #5
//*******************************************************************
// swaps m & n using call by reference
void swapByReference(int &m, int &n){
	int tmp = m;
	m=n;
	n = tmp;
}

//Lab Problem #1
//*******************************************************************
void problem1(){
	int x = 3;
	cout << " the value of the variable is:"<< x <<endl; // prints the value of the variable
	cout << " the address of the variable is:"<< &x <<endl; // prints the address of the variable
	}

//Lab Problem #2
//*******************************************************************
void problem2(int x){ // call by value function call
	x=x+4;
	cout << " the value of the variable is:"<< x <<endl; // prints the value of the variable
	cout << " the address of the variable is:"<< &x <<endl; // prints the address of the variable
}

//Lab Problem #3
//*******************************************************************
int problem3(){ //
	srand(time(NULL)); // calls random number generator
	int x= rand()%50; // sets x equal to a random number between 1 & 50 excluding 50
	cout << " the value of the variable is:"<< x <<endl; // prints the value of the variable
	cout << " the address of the variable is:"<< &x <<endl; // prints the address of the variable
	return x;

}

//Lab Problem #4
//*******************************************************************
void problem4(int *x){ //Call by pointer
	*x=*x^3;
	cout << " the value at the address is:"<< *x <<endl;
	cout << " the address in the parameter is:"<< x <<endl; //prints the value of x
	cout << " the address of the parameter is:"<< &x <<endl; // prints the address of the variable

}

//Lab Problem #5
//*******************************************************************
void problem5(int &x){ //
	srand(time(NULL)); // calls random number generator
	int y= rand()%11; // sets x equal to a random number between 1 & 10
	x=x+y;
	cout << " the value of the random number is:"<< y <<endl; //prints the value of the random number
	cout << " the value of the parameter is:"<< x <<endl; //prints the value of x
	cout << " the address of the parameter is:"<< &x <<endl; // prints the address of x

}

//Lab Problem #6
//*******************************************************************
void problem6(int *x, int *y){ //
	int z = 32;
	*x = z; // sets the pointer for x to the value in z
	z= 42;
	*y=z; //sets the pointer for y to the value of z
}

//Lab Problem #7
//*******************************************************************
void problem7(char *a, char *b, char &c, char *d, char e){ // reassigns char variables via call by pointer, call by reference & call by value
	*a = 'f'; // call by pointer
	*b = 't'; // call by pointer
	c = 'a'; //call by reference
	*d = 'e'; // call by pointer
	e = 't'; // call by value

}

//Lab Problem #8a
//*******************************************************************
bool problem8a(int *x, int *y){ //
	int temp = *y; // set temp equal to the value y points to
	if (*x>*y){
		*y = *x; // sets y equal to x
		*x= temp; // sets x equal to the temp value (y)
		return true;
	}
	else{
		return false;
	}
}

void problem8b(){ //
	srand(time(NULL)); // calls random number generator
	for (int i=0; i<20; i++){ // initiates for loop
	int x = rand()%26; // creates random number 1-25 and stores in x
	int y = rand()%26; // creates random number 1-25 and stores in y
	bool tf = problem8a(&x, &y); // true if values are swapped
	cout << "Value 1=" << x<< endl;
	cout << "Value 2=" << y << endl;
	if (tf == true){ //if statements show whether or not values were swapped.
		cout << "these value were swapped!"<< endl;
		cout << endl;
	}
	if (tf == false){
		cout << "no swap"<< endl;
		cout << endl;
	}

	}
}


// No input parameters
//prints a row of stars

	void star () {
		cout << "***********************************************" << endl;}
