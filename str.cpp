#include "str.h"
#include <cstring>

str::str() //default constructor
{
  _buf = nullptr;
  _n = 0;
  //cout << "String created.\n"; //for testing purposes
}

str::str(char ch) //character constructor
{
   _n = 1;
  _buf = new char[_n+1];
  _buf[0] = ch;
  //cout << "String created.\n"; //for testing purposes
}

str::str(const char* c_str) //c-string constructor
{
  _n = strlen(c_str);
  _buf = new char[_n+1];
  for (int i = 0; i < _n; ++i) 
    _buf[i] = c_str[i];
  //cout << "String created.\n"; //for testing purposes

}
str::str(const str &s) //copy constructor
{
  _n = s._n;
  _buf = new char[_n+1];
  for (int i = 0; i < _n; ++i) 
    _buf[i] = s._buf[i];
  //cout << "String created.\n"; //for testing purposes
}

str::~str() //destructor
{
  if (_buf) 
    delete [] _buf;
  _n = 0;
  _buf = nullptr;
  //cout << "String deleted.\n"; //for testing purposes
}

void str::print() //print method
{
  for (int i = 0; i < _n; ++i) 
    cout << _buf[i];
  cout << endl;
}

void str::clear() //erase contents in string
{
  if (_buf) 
    delete [] _buf;

  _buf = nullptr;
  _n = 0;
}

void str::append(const str & s) //append one given string to the end of another string
{
  char *p = new char[_n + s._n +1];

  int i;
  
  for (i = 0; i < _n; ++i) 
    p[i] = _buf[i];
  
  for (int j = 0; j < s._n; ++i,++j) 
    p[i] = s._buf[j];

  if (_buf) 
    delete [] _buf;

  _buf = p;  
  _n = _n + s._n;
}

void swap(str& x, str& y) //swap two given strings
{
  char *tmp;
  int ntmp;
  
  tmp = x._buf;
  x._buf = y._buf;
  y._buf = tmp;

  ntmp = x._n;
  x._n = y._n;
  y._n = ntmp;
  
}

//Sam added operators
str & str::operator=(const str &s){ //set left hand string equal to right hand string
  if (_buf) 
    delete [] _buf;
  _buf = new char[s._n+1];
  _n = s._n;
  strcpy(_buf, s._buf);
  return *this;
}

str str::operator+(str &s) const{ //returns concatenation of two strings
  str temp; //Why is there no & after the & return type?
  temp._n = _n + s._n;
  temp._buf = new char[temp._n+1];
  for (int i = 0; i < _n; ++i) 
    temp._buf[i] = _buf[i];
  for (int i = 0; i < s._n; ++i) 
    temp._buf[i+_n] = s._buf[i];
  return temp;
}

ostream & operator<<(ostream & os, const str &s){ //cout operator
    os << s._buf;
  return os;
}

istream & operator>>(istream & is, str &s){ //cin operator (does not support spaces)
  char tmp_text[200];
  is >> tmp_text;
  //create temporary string to be returned
  s = str(tmp_text);
  return is;
}
