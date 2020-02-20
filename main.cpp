// main.cpp
//Lab 5, Week 6
//Samuel Shard, 100745640

#include "str.h"

int main()
{
  cout << "TEST PROGRAM !!" << endl;

  str s1("Hello"); 
  
  cout << "s1 = "; 
  s1.print();

  str s2 = s1;
  
  cout << "s2 = "; 
  s2.print();

  str s3("!!!"); 
  
  cout << "s3 = "; 
  s3.print();

  cout << "DO s1.clear()" << endl;
  s1.clear();
  cout << "\ts1 = "; 

  s1.print(); 
  
  cout << "DO s2.append(s3)" << endl;
  s2.append(s3);

  cout << "\ts2 = "; 
  s2.print();

  cout << "DO swap(s2,s3)" << endl;
  swap(s2,s3);

  cout << "\ts2 = "; 
  s2.print();

  cout << "\ts3 = "; 
  s3.print();

  //Sam added test program
  cout << "s2 = s3" << endl;
  s2=s3; //test assignment operator
  cout << "s2: ";
  s2.print();
  cout << "s3: "; //s3 is equal to a copy of s2
  s3.print();

  //test concatination operator
  cout << "DO s8 = s6+s7" << endl;
  str s6("Hello");
  str s7(" Sam");
  str s8 = s6+s7; //s8 equals "Hello Sam"
  cout << s8 << endl;

  //test cin operator
  cout << "DO cin >> s9" << endl;
  str s9;
  cout << "Enter s9: ";
  cin >> s9;
  cout << s9 << endl;
  
  return 0;
}