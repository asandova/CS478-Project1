/**
*	Class: CS 486
*	File: MedianString.cpp
*	Assignment: Project 1
*	Author(s): August B.Sandoval, Hector Rodriguez Alva
*	Purpose: contains the implementation of static class MidString
**/
#include "MedianString.h"
#include "HamminDistance.h"
#include <limits>
#include <math.h>
using namespace std;

string MidString::MedianString(vector<string> dna, int k) {
	size_t distance = numeric_limits<size_t>::max();
	string median = "";
	for (int i = 0; i < pow(4, k); ++i) {
		string pattern = numberToPattern(i, k);
		int d = dist(pattern, dna);
		if (d <= distance) {
			distance = d;
			median = pattern;
		}
	}
	return median;
}


string MidString::numberToPattern(int index, int k) {
	if (k == 1) {
		string temp = "" + numberToSymbol(index);
		return temp;
	}
	int prefixIndex = index / 4;
	int r = index % 4;
	string prefixPattern = numberToPattern(prefixIndex, k - 1);
	char symbol = numberToSymbol(r);
	string pat = prefixPattern + symbol;
	return (pat);
}

char MidString::numberToSymbol(int num) {
	if (num == 0) {
		return 'A';
	}
	else if (num == 1) {
		return 'C';
	}
	else if (num == 2) {
		return 'G';
	}
	else if (num == 3) {
		return 'T';
	}
	else {
		return '\0';
	}
}

int MidString::dist(string pattern, vector<string> dna) {
	int sum = 0;
	for (size_t i = 0; i < dna.size(); ++i) {
		sum += dist(pattern, dna[i]);
	}
	return sum;
}

int MidString::dist(string pattern, string text) {
	int k = pattern.length();
	size_t min = numeric_limits<size_t>::max();

	for (int i = 0; i <= text.length() - k; ++i) {
		string curr = text.substr(i, i + k);
		int hamming = HammingDistance::HamminDistance(pattern, curr);
		if (hamming < min) {
			min = hamming;
		}
	}
	return min;
}