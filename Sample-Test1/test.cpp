#include "pch.h"
#include "../SimilarityChecker/similarityChecker.cpp"

class LengthFixture : public testing::Test
{
public:
	SimilarityChecker smChk;
};

TEST_F(LengthFixture, maxlength) {

	EXPECT_EQ(60, smChk.getScoreLength("abcdefg", "hijklmn"));

}

TEST_F(LengthFixture, 2xLenDiff1) {

	EXPECT_EQ(0, smChk.getScoreLength("abcdef", "hij"));

}

TEST_F(LengthFixture, 2xLenDiff2) {

	EXPECT_EQ(0, smChk.getScoreLength("abcdefu", "hij"));

}

TEST_F(LengthFixture, 2xLenDiff3) {

	EXPECT_EQ(0, smChk.getScoreLength("abc", "hijhdjff"));

}

TEST_F(LengthFixture, 2xLenDiff4) {

	EXPECT_EQ(0, smChk.getScoreLength("abc", "hijfff"));

}

TEST_F(LengthFixture, fractional1) {

	EXPECT_EQ(48, smChk.getScoreLength("abcer", "hijfff"));

}

TEST_F(LengthFixture, fractional2) {

	EXPECT_EQ(30, smChk.getScoreLength("abce", "hijfff"));

}

TEST_F(LengthFixture, fractional3) {

	EXPECT_EQ(48, smChk.getScoreLength("hijfff", "abcer"));

}

TEST_F(LengthFixture, fractional4) {

	EXPECT_EQ(30, smChk.getScoreLength("hijfff", "abce"));

}

TEST_F(LengthFixture, fractional5) {

	EXPECT_EQ(51, smChk.getScoreLength("hijfffg", "abceopop"));

}

TEST_F(LengthFixture, fractional6) {

	EXPECT_EQ(51, smChk.getScoreLength("abceopop", "hijfffg"));

}

TEST_F(LengthFixture, alphaMaxScore1) {

	EXPECT_EQ(40, smChk.getScoreAlpha("abceopop", "abceopop"));

}

TEST_F(LengthFixture, alphaMaxScore2) {

	EXPECT_EQ(40, smChk.getScoreAlpha("abceopop", "abceop"));

}

TEST_F(LengthFixture, alphaMaxScore3) {

	EXPECT_EQ(40, smChk.getScoreAlpha("BBAAA", "AB"));

}

TEST_F(LengthFixture, alphaZeroScore1) {

	EXPECT_EQ(0, smChk.getScoreAlpha("abceopop", "dfrr"));

}

TEST_F(LengthFixture, alphaZeroScore2) {

	EXPECT_EQ(0, smChk.getScoreAlpha("GHJI", "KLOPY"));

}

TEST_F(LengthFixture, alphaFractional1) {

	EXPECT_EQ(17, smChk.getScoreAlpha("GHJI", "GHJKOP"));

}