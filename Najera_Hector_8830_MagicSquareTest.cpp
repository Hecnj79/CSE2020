#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

void read_square(vector<vector<int> >&);
void print_magic(const vector<vector<int> >&);
bool test_magic(const vector<vector<int> >&, int&);
int row_sum(int i, const vector<vector<int> >&);
int col_sum(int j, const vector<vector<int> >&);
int diag1_sum(const vector<vector<int> >&);
int diag2_sum(const vector<vector<int> >&);

int main()
{
	vector<vector<int> > magicSQ;
	read_square(magicSQ);
	print_magic(magicSQ);

	int magic_sum;
	if(test_magic(magicSQ, magic_sum))
	{
		cout << endl;
		cout << "Magic Test passes -- the magic sum is "
			<< magic_sum << endl;
	}
	else
	{
		cout << endl;
		cout << "Magic Test fails" << endl;
	}
	return 0;
}

void read_square(vector<vector<int> >& square)
{
	ifstream inp;
	vector<int> nums;
	inp.open("square11A.txt");
	int next;
	inp >> next;
	while (!inp.fail())
	{
		nums.push_back(next);
		inp >> next;
	}
	inp.close();

	assert(sqrt(nums.size()) == floor(sqrt(nums.size())));

	int n = static_cast<int>(sqrt(nums.size()));

	int k = 0;
	for(int i = 1; i<= n; i++)
	{
		vector<int> row;
		for(int j = 1; j <= n; j++)
		{
			row.push_back(nums[k]);
			k++;
		}
		square.push_back(row);
	}
	return;
}

void print_magic(const vector<vector<int> >& mag)
{
	cout << endl;
	for(int i = 0; i < mag.size(); i++)
	{
		for(int j = 0; j < mag.size(); j++)
			if (mag[i][j] == 0)
				cout << left << setw(6) << "~" << " ";
			else
				cout << left << setw(6) << mag[i][j] << " ";
			cout << endl;
	}
	cout << endl;
	return;
}

bool test_magic(const vector<vector<int> >& mag, int& msum)
{
	int dim = mag[0].size();
	int rsum = row_sum(0, mag);

	for (int i = 1; i < dim; i++)
		if (row_sum(i, mag) != rsum)
			return false;
	for (int i = 0; i < dim; i++)
		if(col_sum(i, mag) != rsum)
			return false;
	if(diag1_sum(mag) != rsum || diag2_sum(mag) != rsum)
		return false;

	msum = rsum;
	return true;
}

int row_sum(int i, const vector<vector<int> >& mag)
{
	int dim = mag[0].size();
	int sum = 0;
	for (int j = 0; j < dim; j++)
		sum += mag[i][j];
	return sum;
}

int col_sum(int j, const vector<vector<int> >& mag)
{
	int dim = mag[0].size();
	int sum = 0;
	for (int i = 0; i < dim; i++)
		sum += mag[i][j];
	return sum;
}

int diag1_sum(const vector<vector<int> >& mag)
{
	int dim = mag[0].size();
	int sum = 0;
	for(int i = 0; i < dim; i++)
		sum += mag[i][i];
	return sum;
}

int diag2_sum(const vector<vector<int> >& mag)
{
	int dim = mag[0].size();
	int sum = 0;
	for(int i = dim - 1, j = 0; j < dim; i--, j++)
		sum += mag[i][j];
	return sum;
}

