/**
*	Class: CS 486
*	File: MedianString.h
*	Assignment: Project 1
*	Author(s): August B.Sandoval, Hector Rodriguez Alva
*	Purpose: contains the class definition of MidString
**/
#ifndef MEDIANSTRING_H
#define MEDIANSTRING_H
#include <string>
#include <vector> 

using namespace std;
class MidString {

public:
	static string MedianString(vector<string> sequences, int k);
	static string numberToPattern(int index, int k);
	static char numberToSymbol(int num);
	static int dist(string pattern, vector<string> dna);
	static int dist(string pattern, string dna);
};

#endif // !MEDIANSTRING_H

