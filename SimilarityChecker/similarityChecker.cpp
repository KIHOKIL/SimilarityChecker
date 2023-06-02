#include <iostream>
#include <string>
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