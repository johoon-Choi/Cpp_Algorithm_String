#include <iostream>
#include <string>
#include <vector>

using namespace std;

int boardLen;
string AD_Sentence;

int FailureFunction(string sentence) {
	int sentenceLen = sentence.size();
	int curLen = sentenceLen;
	string curSentence = sentence;
	int curPosition = 0;
	int ans = 0;
	int i = 0;
	int j = 0;
	bool didFindAnswer = false;

	vector<int> pi(sentenceLen, 0);

	do {
		i++;

		if (i == sentenceLen) { // new space allocation to pi vector is required
			curLen++;
			curPosition = j;
			curSentence += sentence[curPosition];
			pi.push_back(0); // get one new space by push_back zero
		}
		else if (i > sentenceLen) { // new space allocation to pi vector is required
			curLen++;
			if (j < sentenceLen) {
				curPosition++;
				curSentence += sentence[curPosition];
			}
			else { // if j is same or bigger than sentenceLen
				curPosition = pi[curPosition];
				curSentence += sentence[curPosition];
			}
			pi.push_back(0); // get one new space by push_back zero
		}

		while (j > 0 && curSentence[i] != curSentence[j])
			j = pi[j - 1];

		if (curSentence[i] == curSentence[j]) pi[i] = ++j;


		// ********** End condition **********

		if (i >= sentenceLen - 1) // need to check all sentence before getting answer
			if (i % 2) // i is odd number
				if (pi[i] == curLen / 2) { // pi.substr(0, curLen/2) == pi.substr(curLen/2 - 1, curLen/2) ?
					didFindAnswer = true;
					ans = pi[i];
				}
				else if (pi[i] > curLen / 2) {
					didFindAnswer = true;
					ans = i - (pi[i] - 1);
				}

		// ***********************************
	} while (!didFindAnswer);

	return ans;
}

int main() {
	cin >> boardLen;
	cin >> AD_Sentence;

	int ans = FailureFunction(AD_Sentence);

	cout << ans;
}