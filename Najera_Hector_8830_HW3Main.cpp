#include "BinarySearchTreeHW.h"
#include "Vector.h"
#include "Random.h"
#include <iostream>
using namespace std;

template <typename T>
void balance_BST(BinarySearchTree<T>& bst);

template <typename T>
void balance_BST_inner(const Vector<T>& vec, int low, int high, BinarySearchTree<T>& bst);

int main()
{

    int randnum;
    Vector<int> numbers;

    BinarySearchTree<int> mybst;

    cout << "How many integers? (12-25) ";
    cin >> randnum;
    while(randnum < 12 || randnum > 25)
    {
	cout << "How many integers? (12-25) ";
	cin >> randnum;
    }

    random_vector(randnum, 1, 50, numbers, 0);
    for(int i = 0; i < randnum; i++)
	mybst.insert(numbers[i]);

    cout << "Tree:" << endl;
    mybst.printTree();

    cout << endl << endl << "Internal Tree:" << endl;
    mybst.printInternal();
    cout << endl << endl << "Depth of Tree: " << mybst.depth() << endl << endl;

    balance_BST(mybst);

    cout << "Balanced Tree:" << endl;
    mybst.printTree();
    cout << endl << endl << "Balanced Internal Tree:" << endl;
    mybst.printInternal();
    cout << endl << endl << "Depth of Tree: " << mybst.depth() << endl << endl;

}

//def
template <typename T>
void balance_BST(BinarySearchTree<T>& bst)
{
    Vector<T> values;
    bst.collect_values(values);

    bst.makeEmpty();

    balance_BST_inner(values, 0, values.size() - 1, bst);
    return;
}

template <typename T>
void balance_BST_inner(const Vector<T>& vec, int low, int high, BinarySearchTree<T>& bst)
{
    if(high <= low)
    {
	bst.insert(vec[low]);
	return;
    }

    bst.insert(vec[(low + high)/2]);
    balance_BST_inner(vec, low, ((low + high)/2)-1, bst);

    balance_BST_inner(vec, ((low + high)/2)+1, high, bst);

    return;

}


