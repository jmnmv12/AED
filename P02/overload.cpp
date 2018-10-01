//
// Tomás Oliveira e Silva, AED, September 2014, September 2017
//
// example of function overloading (same function name, different argument numbers and/or data types)
//

#include <iostream>

using std::cout; // make this symbol from the std namespace directly visible

void show(const char i)
{
  cout << "char: "
       << i
       << std::endl;
}

void show(const int *i)
{
  cout << "[";
  for (int j=0;j<2;j++)
    cout<<i[j]<<",";
  
   cout<<i[2]<<"]"<< std::endl;
}

void show(const int i)
{
  cout << "int: "
       << i
       << std::endl;
}

void show(const double d)
{
  cout << "double: "
       << d
       << std::endl;
}

void show(const char *s,const char *h = "string: ") // second argument with default value, strings são passdas com ponteiros
{
  cout << h
       << s
       << std::endl;
}

int main(void)
{
  show('a');
  int a[3] = { 2,7,-1 };
  show(a);
  show(1.0);
  show("hello");
  show(-3);
  show("John","name: ");
  return 0;
}
