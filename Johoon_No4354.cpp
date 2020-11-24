#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> T;

vector<int> FailureFunction(vector<string>& parent) {
	int cases = parent.size();
	vector<int> ans(cases, 0);

	for (int tc = 0; tc < cases; tc++) {
		int parentSize = parent[tc].size();

		int j = 0;
		vector<int> fail(parentSize, 0);
		bool doesHaveValue = false;

		for (int i = 1; i < parentSize; i++) {
			while (j > 0 && parent[tc][i] != parent[tc][j]) {
				j = fail[j - 1];
			}

			if (parent[tc][i] == parent[tc][j]) fail[i] = ++j;

			if (i % 2) // if i is odd number
				if (fail[i] == (i + 1) / 2) // if fail[i] is doubly repeated sentence
					if (parentSize % ((i + 1) / 2) == 0) {
						string patternTemp = parent[tc].substr(0, (i - 1) / 2 + 1);
						int patternTempSize = patternTemp.size();
						
						for (int j = 0; j < parentSize; j += patternTempSize) {
							if (patternTemp != parent[tc].substr(j,patternTempSize)) break;

							if (j == parentSize - patternTempSize) {
								ans[tc] = parentSize / patternTempSize;
								doesHaveValue = true;
							}
						}
					}
			// ****************************
			if (ans[tc] || i == parentSize - 1) break;
		}
		if (!doesHaveValue) ans[tc] = 1;
	}

	return ans;
}

int main() {
	while (1) {
		string input;
		getline(cin,input);

 		if (input == ".") break;

		T.push_back(input);
	}

	vector<int> ans = FailureFunction(T);
	
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}