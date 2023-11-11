#include <iostream>
#include <algorithm>
#include "Vector.h"
#include "Random.h"
using namespace std;

int main()
{
	Vector<int> myvec;
	random_vector(25, 1, 100, myvec, 0);

	Vector<int>::iterator itr;

	cout << "Vector myvec printed with iterators:" << endl;
	for(itr = myvec.begin(); itr != myvec.end(); itr++)
		cout << *itr << " ";
		cout << endl << endl;

	sort(myvec.begin(), myvec.end());

	cout << "Vector myvec now sorted:" << endl;
	for(itr = myvec.begin(); itr != myvec.end(); itr++)
		cout << *itr << " ";
		cout << endl << endl;

	int tofind;
	cout << "Find which value in myvec? ";
	cin >> tofind;
	cout << endl << endl;

	if(find(myvec.begin(), myvec.end(), tofind))
		cout << "found value " << tofind << " :-)";
	else
		cout << "Value " << tofind << " not found :-(";
		cout << endl << endl;

	Vector<int>::iterator max;
	Vector<int>::iterator min;

	max = max_element(myvec.begin(), myvec.end());
	min = min_element(myvec.begin(), myvec.end());

	cout << "The maximal and minimal values are: "
		<< *max << " and " << *min << endl << endl;

	fill(myvec.begin(), myvec.end(), 7);

	cout << "Vector myvec covered in 7s ..." << endl;
	for (itr = myvec.begin(); itr != myvec.end(); itr++)
		cout << *itr << " ";
		cout << endl << endl;

	return 0;
}
