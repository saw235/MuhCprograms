#include <sstream>
#include <string>

int chartoint(char a)
{
	using namespace std;
	stringstream convert;
	convert << a;
	int converted;

	convert >> converted;

	return converted;
}
