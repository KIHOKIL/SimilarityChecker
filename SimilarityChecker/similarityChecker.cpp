#include <iostream>
#include <string>
#include <set>

using namespace std;
#define MAX_LEN_SCORE 60
struct CountResult
{
	int strDb1Len;
	int strDb2Len;
	int sameCnt;
};
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

	CountResult getCntResult()
	{
		set <char> strDb1, strDb2;

		for(char c : s1)	strDb1.insert(c);
		for(char cc : s2)	strDb2.insert(cc);

		int sameCnt = 0;
		int strDb1Len = strDb1.size();
		int strDb2Len = strDb2.size();

		for (char c : strDb1)
			if (strDb2.count(c)) sameCnt++;

		return { strDb1Len ,strDb2Len ,sameCnt };
	}

	int getAlphaScoreValue(CountResult cntRslt)
	{
		if (cntRslt.strDb1Len == cntRslt.sameCnt) return 40;
		if (cntRslt.sameCnt == 0) return 0;
		return (cntRslt.sameCnt * 40 / (cntRslt.strDb1Len + cntRslt.strDb2Len - cntRslt.sameCnt));
	}

	int getScoreAlpha()
	{
		CountResult cntRslt = getCntResult();

		return getAlphaScoreValue(cntRslt);
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