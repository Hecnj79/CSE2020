#include "Sort.h"
#include "Vector.h"
#include "Random.h"
#include "List.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    Vector<int> nums1;
    Vector<int> nums2;
    Vector<int> ascending1, ascending2;
    Vector<int> descending1, descending2;

    for (int i = 1; i <= 25; i++)
    {
	ascending1.push_back(2 * i);
	ascending2.push_back(2 * i);
    }
    for (int i = 25; i > 0; i--)
    {
	descending1.push_back(3 * i);
	descending2.push_back(3 * i);
    }

    int ops1;
    int ops2;

    insertionSort(ascending1, ops1);
    selectionSort(ascending2, ops2);

    std::cout << "insertSort on 25 ascending: " << ops1 << std::endl;
    std::cout << "selectSort on 25 ascending: " << ops2 << std::endl;
    std::cout << endl;

    insertionSort(descending1, ops1);

    selectionSort(descending2, ops2);

    cout << "insertSort on 25 descending: " << ops1 << endl;
    cout << "selectSort on 25 descending: " << ops2 << endl;
    cout << endl;

    for(int i = 1; i <= 10; i++)
    {
	nums1.clear();
	nums2.clear();
	rand_seed();
	random_vector(25, 1, 250, nums1, 0);
	for (int i = 0; i < nums1.size(); i++)
	    nums2.push_back(nums1[i]);

	insertionSort(nums1, ops1);
	selectionSort(nums2, ops2);

	cout << "insertSort on 25 random values: " << ops1 << endl;
	cout << "selectSort on 25 random values: " << ops2 << endl;
	cout << endl;

	this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
