#include <iostream>

using namespace std;

int main () {
  int x = 5, y = 15;
  int * p1, *p2;

  cout << "\nvalue of\t\tx\ty\tp1\t\tp2" << endl;
  cout << "\t\t\t5\t15\tuninit\t\tuninit" << endl;

  p1 = &x; // References x to find the address of x, 
  // then assigns p1 as the pointer to the address
  cout << "(1) p1 = &x:\t\t" <<  x << "\t" << y << "\t" << p1 << "\tuninit" << endl; 
 
  p2 = &y;// References y to find the address of y, 
  // then assigns p2 as the pointer to the address
  cout << "(2) p2 = &y:\t\t" <<  x << "\t" << y << "\t" << p1 << "\t" << p2 << endl; 
  
  *p1 = 6; // Dereferences p1 to change the value of the
  // object found at the address to 6
  cout << "(3) *p1 = 6:\t\t" <<  x << "\t" << y << "\t" << p1 << "\t" << p2 << endl; 
  
  *p1 = *p2; // Deferences p1 and p2 and changes the value of the
  // object found at p1 to the value of the object found at p2
  cout << "(4) *p1 = *p2:\t\t" <<  x << "\t" << y << "\t" << p1 << "\t" << p2 << endl; 
  
  p2 = p1; // Assigns the address at p1 to p2, therefore now they point
  // at the same place
  // y no longer has a pointer pointed to its address 
  cout << "(5) p2 = p1:\t\t" <<  x << "\t" << y << "\t" << p1 << "\t" << p2 << endl; 
  
  *p1 = *p2+10; // Dereferences p1 and p2 to change the value of the object at
  // p1 to the value of the object found at p2 plus 10
  cout << "(6) *p1 = *p2+10:\t" <<  x << "\t" << y << "\t" << p1 << "\t" << p2 << endl << endl; 
  
  return 0;
}
