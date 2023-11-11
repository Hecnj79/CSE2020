#include <iostream>
#include <fstream>
#include <string>
#include "Vector.h"
using namespace std;

template <typename T>
void print_vector(Vector<T> vec)
{
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	return;
}

int main()
{
	Vector<string> numbers;
	ifstream inp;
	inp.open("hw1_input.txt");
	string next;

	inp >> next;
	while(!inp.fail())
	{
		numbers.push_back(next);
		inp >> next;
	}
	inp.close();

	cout << endl << endl;
	print_vector(numbers);
	cout << endl;

	Vector<string>::reverse_iterator ritr;
	for (ritr = numbers.rbegin(); ritr !=numbers.rend(); ritr--)
		cout << *ritr << " ";
	cout << endl << endl;

	numbers.reverse();
	print_vector(numbers);
	cout << endl;

	numbers.push_back("seven");

	print_vector(numbers);
	cout << endl;

	numbers.replace("seven", "SEVEN");
	numbers.reverse();
	print_vector(numbers);

	cout << endl;
	cout << "The front value is: " << numbers.front()
		<< endl << endl;

	return 0;
}
