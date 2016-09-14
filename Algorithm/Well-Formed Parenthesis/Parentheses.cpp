//Coded by Saw Xue Zheng
//Generates a list of well-formed parentheses

#include <iostream>
#include <list>
#include <string>


//parenthesis perfectly unfolded
bool isPerfect_unfold(std::string parentheses)
{
	//checks for 1 and 0 at front and back
	if (parentheses.front() != '1' && parentheses.back() != '0')
	{
		return false; 
	}

	//checks for consecutive 1's and 0's 
	for (int i = 1 ; i < parentheses.length(); i++)
	{
		//if exist consecutive 1's or 0's
		if (parentheses[i-1] == parentheses[i])
		{
			return false; //return false
		}
	}

	return true;

}

std::list<std::string> p_multiply(std::string A)
{
	std::list<std::string> string_arr;
	//if A is perfectly unfolded
	if (isPerfect_unfold(A))
	{
		//return ()A and (A)
		string_arr.push_back(std::string(A).append("10"));
		std::string temp ="1";
		temp.append(A);
		temp.append("0");
		string_arr.push_back(temp);
		return string_arr; 
	}
	//if A is not perfectly unfolded
	else
	{
		//return ()A, A(), (A)
		string_arr.push_back(std::string(A).append("10"));
		std::string temp ="10";
		temp.append(A);
		string_arr.push_back(temp);
		std::string temp2 ="1";
		temp2.append(A);
		temp2.append("0");
		string_arr.push_back(temp2);

		return string_arr;
	}
}

//generate the list of parentheses using recursion
std::list<std::string> generate_parentheses(int n)
{
	std::list<std::string> l1; 
	std::list<std::string> l2; 

	//base case
	if (n == 1) 
	{
		l1.push_back("10");
		return l1;
	}
	else
	{
		//if n is not 1 then get the list of parentheses for n-1 and store it in l1
		l1 = generate_parentheses(n-1);
		
		//for each element in l1, 'multiply' by a parenthesis
		for (std::string s : l1)
		{
			//and appends to the list, l2
			l2.splice(l2.end(),p_multiply(s));
		}

		return l2;
	}

}

//display given the strings of 1's and 0's
void displayParentheses(std::string s)
{
	for (char c : s)
	{
		if ( c == '1')
		{
			std::cout << "(";
		}
		else if ( c == '0')
		{
			std::cout << ")";
		}
	}

	std::cout << std::endl;
}

void main()
{

	int num;
	std::cout << "Enter the number of pair of parentheses:	";
	std::cin >> num; 
	std::cout << std::endl;
	
	std::list<std::string> l;
	
	l = generate_parentheses(num);

	for (std::string s : l)
		{
			displayParentheses(s);
		}

	system("PAUSE");
}

