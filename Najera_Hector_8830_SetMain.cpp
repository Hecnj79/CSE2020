#include "BST_Set.h"
#include "Vector.h"
#include "Random.h"
#include <iostream>
using namespace std;

//prototypes
template <typename T>
Set<T> set_union( Set<T>& set1,  Set<T>& set2);

template <typename T>
Set<T> set_intersection( Set<T>& set1,  Set<T>& set2);

template <typename T>
Set<T> set_difference(Set<T>& set1, Set<T>& set2);

int main()
{

    Vector<int> numbers;
    Set<int> set1;
    Set<int> set2;

    random_vector(24, 1, 30, numbers, 0);
    for(int i = 0; i < 12; i++)
	set1.insert(numbers[i]);

    for(int i = 12; i < 24; i++)
	set2.insert(numbers[i]);

    cout << "Set1:\n";
    set1.printSet();
    cout << endl << endl << "Set2:\n";

    set2.printSet();
    cout << endl << endl << "The Union:\n";

    set_union(set1, set2).printSet();
    cout << endl << endl << "The Intersection:\n";

    set_intersection(set1, set2).printSet();
    cout << endl << endl << "The union internal tree structure:\n";

    set_union(set1, set2).printInternal();
    cout << endl << endl << "The intersection internal tree structure:\n";

    set_intersection(set1, set2).printInternal();
    cout << endl << endl << "Set1 with cardinality " << set1.cardinality() << ":\n";

    set1.printSet();
    cout << endl << endl << "Set2 with cardinality " << set2.cardinality() << ":\n";

    set2.printSet();
    cout << endl << endl << "The union of Set1 and Set2 with cardinality " << set_union(set1, set2).cardinality() << ":\n";

    set_union(set1, set2).printSet();
    cout << endl << endl << "The intersection of Set1 and Set2 with cardinality " << set_intersection(set1, set2).cardinality() << ":\n";

    set_intersection(set1, set2).printSet();
    cout << endl << endl << "The set difference Set1 - Set2 with cardinality " << set_difference(set1, set2).cardinality() << ":\n";

    set_difference(set1, set2).printSet();
    cout << endl << endl << "The difference Set2 - Set1 with cardinality " << set_difference(set2, set1).cardinality() << ":\n";

    set_difference(set2, set1).printSet();
    cout << endl << endl;
}

//definitions
template <typename T>
Set<T> set_union( Set<T>& set1,  Set<T>& set2)
{
    Set<T> theunion;
    for(Set<int>::iterator itr = set1.begin(); itr != set1.end(); itr++)
	theunion.insert(*itr);

    for(Set<int>::iterator itr = set2.begin(); itr != set2.end(); itr++)
	if(!theunion.contains(*itr))
	    theunion.insert(*itr);

    return theunion;
}

template <typename T>
Set<T> set_intersection( Set<T>& set1,  Set<T>& set2)
{
    Set<T> theintersection;

    for(Set<int>::iterator itr = set1.begin(); itr != set1.end(); itr++)
	if(set2.contains(*itr))
	    theintersection.insert(*itr);

    return theintersection;

}

template <typename T>
Set<T> set_difference(Set<T>& set1, Set<T>& set2)
{
    Set<T> thedifference;

    for(Set<int>::iterator itr = set1.begin(); itr != set1.end(); itr++)
	if(!set2.contains(*itr))
	    thedifference.insert(*itr);

    return thedifference;

}
