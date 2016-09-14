/*#include <iostream>				//uncomment to test

int main()
{
  unsigned long int c;
  for (unsigned long int a=0; ; a++)
  {
      for (unsigned long int b=1000; b>a; b--)
      {
          c = 1000-a-b;
          if ((a*a+b*b) == (c*c) && (a*b*c != 0)) {
            std::cout << "Solution:"
                    << a*b*c << std::endl;
           
          }
      }
  }

  system("pause");
}