// str.h

#ifndef __str_h__
#define __str_h__

#include <iostream>

using namespace std;


class str
{
  private:
    char* _buf;  // pointer to the underlying storage
    int _n;      // size of the buffer

  public:
  
    // constructors of various forms
    str();      
    str(char ch);
    str(const char* c_str);

    str(const str &);   // copy constructor 
    ~str();

    // function for finding length of the string
    int length() const { return _n; }

    // function for checking if string is null string
    bool is_empty() const { return _n == 0; }

    void print();
  
    // clear erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    void clear();

    // append extends the string by appending additional characters at the end of its current value:
    void append(const str& str);

    //Added Code
    //assignment operator: set a string object equal to another
    //delete and create new dynamic memory variable of correct length
    str & operator=(const str &s); //why str & operator? Passed return value and argument be reference

    //concatination operator: add a string object to the end of another
    str operator+(str& s) const;  //why does this one not need & operator? Only passed

  friend void swap(str &, str &);
  friend ostream & operator<<(ostream & os, const str &s);
  friend istream & operator>>(istream & is, str &s);

};

#endif