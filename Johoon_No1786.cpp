#include <iostream>
#include <string>
#include <vector>

using namespace std;

string T, P;

vector<int> getPi(string pattern) {
	int patternSize = pattern.size();
	int j = 0;
	vector<int> pi(patternSize, 0);

	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];

		if (pattern[i] == pattern[j]) pi[i] = ++j;
	}

	return pi;
}

vector<int> KMP(string parent, string pattern) {
	vector<int> ans;

	auto pi = getPi(pattern);

	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;

	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j])
			j = pi[j - 1];

		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				ans.push_back(i - patternSize + 1);
				j = pi[j];
			}
			else j++;
		}
	}

	return ans;
}

int main() {
	getline(cin, T);
	getline(cin, P);

	auto ans = KMP(T, P);

	cout << ans.size() << '\n';

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << ' ';
}