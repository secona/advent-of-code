#include <iostream>
#include <set>

using namespace std;

int main()
{
	int a, b;
	multiset<int> l, r;

	while (cin >> a >> b) {
		l.insert(a);
		r.insert(b);
	}

	int distance = 0, similarity = 0;

	auto left = l.begin();
	auto right = r.begin();

	while (left != l.end() && right != r.end()) {
		distance += abs(*left - *right);
		similarity += (*left) * r.count(*left);

		++left;
		++right;
	}

	cout << "Part 1: " << distance << endl;
    cout << "Part 2: " << similarity << endl;

	return 0;
}
