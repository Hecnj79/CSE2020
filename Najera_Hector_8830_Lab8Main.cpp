#include <iostream>
#include <fstream>
#include <cassert>
#include "List.h"
using namespace std;

void print_list(const List<int>&);

int main()
{
    List<int> mylst;
    ifstream inp;
    inp.open("lab8_input.txt");
    int next;
    inp >> next;
    while (!inp.fail())
    {
	mylst.push_back(next);
	inp >> next;
    }
    inp.close();

    cout << endl;
    cout << "All items in the list: " << endl;
    print_list(mylst);

    cout << endl << endl;
    cout << "All list items at odd-numbered position:" << endl << endl;
    for(int i = 0; i < mylst.size(); i++)
    {
	if(i % 2 != 0)
	    cout << mylst.nth(i) << " "; //lab8mon
    }


    cout << endl << endl;
    cout << "All list items at even-numbered position:" << endl << endl;
    for (int i = 0; i < mylst.size(); i++)
    {
	if(i % 2 == 0)
	    cout << mylst.nth(i) << " "; //lab8mon
    }
    cout  << endl << endl;
    return 0;
}

void print_list(const List<int>& lst)
{
    List<int>::const_iterator itr = lst.begin();
    for(; itr !=lst.end(); ++itr)
	cout << *itr << " ";
    cout << endl << endl;
    return;
}
