#include <iostream>
#include <string>
#include <set>

using namespace std;
#define MAX_LEN_SCORE 60
#define MAX_LEN_ALPHA 40

struct CountResult
{
	int strDb1Len;
	int strDb2Len;
	int sameCnt;
};
class SimilarityChecker
{
public:
	bool isNonUpperAlpha(const string s)
	{
		for (char c : s)
		{
			if (!(c >= 'A' && c <= 'Z')) return true;
		}
		return false;
	}
	int getScoreLength(const string& s1, const string& s2)
	{
		if (isNonUpperAlpha(s1) || isNonUpperAlpha(s2)) return -1;

		int A = s1.length();
		int B = s2.length();

		if (isLenEqual(A, B)) return MAX_LEN_SCORE;
		if (isLen2xMore(A, B)) return 0;

		return getFracScore(A, B);
	}

	CountResult getCntResult(string s1, string s2)
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
		if (cntRslt.strDb1Len == cntRslt.sameCnt) return MAX_LEN_ALPHA;
		if (cntRslt.sameCnt == 0) return 0;
		return (cntRslt.sameCnt * MAX_LEN_ALPHA / (cntRslt.strDb1Len + cntRslt.strDb2Len - cntRslt.sameCnt));
	}

	int getScoreAlpha(string s1, string s2)
	{
		if (isNonUpperAlpha(s1) || isNonUpperAlpha(s2)) return -1;

		return getAlphaScoreValue(getCntResult(s1, s2));
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
};