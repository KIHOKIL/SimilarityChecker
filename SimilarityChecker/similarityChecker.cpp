#include <iostream>
#include <string>
#include <set>

using namespace std;
#define MAX_LEN_SCORE 60

class SimilarityChecker
{
public:
	SimilarityChecker(string str1, string str2)
	: s1(str1), s2(str2) {}

	int getScoreLength()
	{
		int A = s1.length();
		int B = s2.length();

		if (isLenEqual(A, B)) return MAX_LEN_SCORE;
		if (isLen2xMore(A, B)) return 0;

		return getFracScore(A, B);
	}

	int getScoreAlpha()
	{
		set <char> sc1, sc2;

		for(char c : s1)	sc1.insert(c);
		for(char cc : s2)	sc2.insert(cc);

		int sameCnt = 0;
		int lengthA = sc1.size();
		int lengthB = sc2.size();

		for (char c : sc1)
			if (sc2.count(c)) sameCnt++;

		if (sc1.size() == sameCnt) return 40;
		if (sameCnt == 0) return 0;
		return (sameCnt * 40 / (lengthA + lengthB - sameCnt));
	}

private:
	bool isLenEqual(int A, int B)
	{
		return A == B;
	}

	bool isLen2xMore(int A, int B)
	{
		return A >= B * 2 || A * 2 <= B;
	}

	int getFracScore(int A, int B)
	{
		if (B > A) swap(A, B);
		return (2 * B - A) * MAX_LEN_SCORE / B;	//(1 - (A - B) / B) * 60;
	}
	string s1;
	string s2;
};