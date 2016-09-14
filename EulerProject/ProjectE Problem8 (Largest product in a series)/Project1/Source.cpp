#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

int productof5digits(const std::vector<int> &vectorlist, int upperlimit, int lowerlimit);
int chartoint(char a);
int main()
{
   using namespace std;
   ifstream readfile("randomnumbers.txt", ios::in);
   
   if (!readfile.is_open())
   {
	   cout << "Failed to open." << endl;
	   system("pause");
	   return 0;
   }
   else
   {
	   cout << "Opened ok!"<< endl;
   }
   stringstream buffer;
   while (readfile.good())
   {
   buffer.put(readfile.get()); //use put() because << operator coverts char to int
   }

   vector<char> vectorlist;

   while (buffer.good())
   {
	   if (buffer.peek() == '\n')
	   {
		buffer.seekg(1, buffer.cur); // set position to next to escape infiniteloop
		cout << buffer.tellg()<< endl;
	   }
	   
	   vectorlist.push_back(buffer.get());
   }

	readfile.close();

	 //uncomment to display
   for (int i = 0 ; i < vectorlist.size(); i++)
   {
     cout << vectorlist[i];
   }

   vector<int> nvectorlist;

	//convert vector<char> to <int>
   for (int i= 0; i < vectorlist.size(); i++)
   {
	   nvectorlist.push_back(chartoint(vectorlist[i]));
   }

   const int consecsize = 5;
   int greatestconsecproduct = 0;
	for (int index = 0; index+5 <= nvectorlist.size(); index++)
   {
	   int upperlim = index + consecsize ;
	   int lowerlim = index;
	   
	   int currentproduct = productof5digits(nvectorlist, upperlim, lowerlim);
		
	   if (currentproduct > greatestconsecproduct)
	   {
		   greatestconsecproduct = currentproduct;
	   }

   }

   cout << endl;
   cout << endl;
   cout << greatestconsecproduct << endl;

   system("pause");

}