#include "pch.h"
#include "../SimilarityChecker/similarityChecker.cpp"


TEST(SimilarityChecker, maxlength) {

	SimilarityChecker smChk("abcdefg","hijklmn");

	EXPECT_EQ(60, smChk.getScoreLength());

}

TEST(SimilarityChecker, 2xLenDiff1) {

	SimilarityChecker smChk("abcdef", "hij");

	EXPECT_EQ(0, smChk.getScoreLength());

}

TEST(SimilarityChecker, 2xLenDiff2) {

	SimilarityChecker smChk("abcdefu", "hij");

	EXPECT_EQ(0, smChk.getScoreLength());

}

TEST(SimilarityChecker, 2xLenDiff3) {

	SimilarityChecker smChk("abc", "hijhdjff");

	EXPECT_EQ(0, smChk.getScoreLength());

}

TEST(SimilarityChecker, 2xLenDiff4) {

	SimilarityChecker smChk("abc", "hijfff");

	EXPECT_EQ(0, smChk.getScoreLength());

}

TEST(SimilarityChecker, fractional1) {

	SimilarityChecker smChk("abcer", "hijfff");

	EXPECT_EQ(48, smChk.getScoreLength());

}

TEST(SimilarityChecker, fractional2) {

	SimilarityChecker smChk("abce", "hijfff");

	EXPECT_EQ(30, smChk.getScoreLength());

}

TEST(SimilarityChecker, fractional3) {

	SimilarityChecker smChk( "hijfff", "abcer");

	EXPECT_EQ(48, smChk.getScoreLength());

}

TEST(SimilarityChecker, fractional4) {

	SimilarityChecker smChk("hijfff", "abce");

	EXPECT_EQ(30, smChk.getScoreLength());

}

TEST(SimilarityChecker, fractional5) {

	SimilarityChecker smChk("hijfffg", "abceopop");

	EXPECT_EQ(51, smChk.getScoreLength());

}

TEST(SimilarityChecker, fractional6) {

	SimilarityChecker smChk("abceopop", "hijfffg");

	EXPECT_EQ(51, smChk.getScoreLength());

}

TEST(SimilarityChecker, alphaMaxScore1) {

	SimilarityChecker smChk("abceopop", "abceopop");

	EXPECT_EQ(40, smChk.getScoreAlpha());

}

TEST(SimilarityChecker, alphaMaxScore2) {

	SimilarityChecker smChk("abceopop", "abceop");

	EXPECT_EQ(40, smChk.getScoreAlpha());

}

TEST(SimilarityChecker, alphaMaxScore3) {

	SimilarityChecker smChk("BBAAA", "AB");

	EXPECT_EQ(40, smChk.getScoreAlpha());

}

TEST(SimilarityChecker, alphaZeroScore1) {

	SimilarityChecker smChk("abceopop", "dfrr");

	EXPECT_EQ(0, smChk.getScoreAlpha());

}

TEST(SimilarityChecker, alphaZeroScore2) {

	SimilarityChecker smChk("GHJI", "KLOPY");

	EXPECT_EQ(0, smChk.getScoreAlpha());

}

TEST(SimilarityChecker, alphaFractional1) {

	SimilarityChecker smChk("GHJI", "GHJKOP");

	EXPECT_EQ(17, smChk.getScoreAlpha());

}