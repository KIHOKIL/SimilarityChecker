#include "pch.h"
#include "../SimilarityChecker/similarityChecker.cpp"

class LengthFixture : public testing::Test
{
public:
	SimilarityChecker smChk;
};

TEST_F(LengthFixture, maxlength) {

	EXPECT_EQ(60, smChk.getScoreLength("ABCDEFG", "HIJKLMN"));

}

TEST_F(LengthFixture, 2xLenDiff1) {

	EXPECT_EQ(0, smChk.getScoreLength("ABCDEF", "HIJ"));

}

TEST_F(LengthFixture, 2xLenDiff2) {

	EXPECT_EQ(0, smChk.getScoreLength("ABCDEFU", "HIJ"));

}

TEST_F(LengthFixture, 2xLenDiff3) {

	EXPECT_EQ(0, smChk.getScoreLength("ABC", "HIJHDJFF"));

}

TEST_F(LengthFixture, 2xLenDiff4) {

	EXPECT_EQ(0, smChk.getScoreLength("ABC", "HIJFFF"));

}

TEST_F(LengthFixture, fractional1) {

	EXPECT_EQ(48, smChk.getScoreLength("ABCER", "HIJFFF"));

}

TEST_F(LengthFixture, fractional2) {

	EXPECT_EQ(30, smChk.getScoreLength("ABCE", "HIJFFF"));

}

TEST_F(LengthFixture, fractional3) {

	EXPECT_EQ(48, smChk.getScoreLength("HIJFFF", "ABCER"));

}

TEST_F(LengthFixture, fractional4) {

	EXPECT_EQ(30, smChk.getScoreLength("HIJFFF", "ABCE"));

}

TEST_F(LengthFixture, fractional5) {

	EXPECT_EQ(51, smChk.getScoreLength("HIJFFFG", "ABCEOPOP"));

}

TEST_F(LengthFixture, fractional6) {

	EXPECT_EQ(51, smChk.getScoreLength("ABCEOPOP", "HIJFFFG"));

}

TEST_F(LengthFixture, alphaMaxScore1) {

	EXPECT_EQ(40, smChk.getScoreAlpha("ABCEOPOP", "ABCEOPOP"));

}

TEST_F(LengthFixture, alphaMaxScore2) {

	EXPECT_EQ(40, smChk.getScoreAlpha("ABCEOPOP", "ABCEOP"));

}

TEST_F(LengthFixture, alphaMaxScore3) {

	EXPECT_EQ(40, smChk.getScoreAlpha("BBAAA", "AB"));

}

TEST_F(LengthFixture, alphaZeroScore1) {

	EXPECT_EQ(0, smChk.getScoreAlpha("ABCEOPOP", "DFRR"));

}

TEST_F(LengthFixture, alphaZeroScore2) {

	EXPECT_EQ(0, smChk.getScoreAlpha("GHJI", "KLOPY"));

}

TEST_F(LengthFixture, alphaFractional1) {

	EXPECT_EQ(17, smChk.getScoreAlpha("GHJI", "GHJKOP"));

}