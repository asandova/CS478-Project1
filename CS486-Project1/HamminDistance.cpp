/**
*	Class: CS486
*	File: HamminDistance.cpp
*	Assignment: Project 1
*	Author(s): August B.Sandoval
*	Purpose: contains the class implementation of HammingDistance
**/
#include "HamminDistance.h"
#include <cctype>
using namespace std;

int HammingDistance::HamminDistance(string s1, string s2) {
	string ls1 = Lower(s1), ls2 = Lower(s2);

	int distance = 0;
	if (s1.length() != s2.length()) {
		return -1;
	}
	else {
		string::iterator itr1 = ls1.begin() , itr2 = ls2.begin();
		for (; itr1 != ls1.end(); ++itr1, ++itr2) {
			if (*itr1 != *itr2) {
				distance++;
			}
		}
		return distance;
	}
}

string HammingDistance::Lower(string s) {
	
	for (string::iterator itr = s.begin(); itr != s.end(); ++itr ) {
		*itr = tolower(*itr);
	}
	return s;
}