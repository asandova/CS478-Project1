/**
*	Class: CS486
*	File: HamminDistance.h
*	Assignment: Project 1
*	Author(s): August B.Sandoval
*	Purpose: contains the class definition of HammingDistance
**/
#include <string>
#ifndef HAMMINGDISTANCE_H
#define HAMMINGDISTANCE_H

using namespace std;

class HammingDistance {

public:
	static int HamminDistance(string s1, string s2);
	static string Lower(string s);
};

#endif // !HAMMINGDISTANCE_H