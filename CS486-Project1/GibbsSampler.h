/**
*	Class: CS 486
*	File: GibbsSampler.h
*	Assignment: Project 1
*	Author(s): August B.Sandoval, Hector Rodriguez Alva
*	Purpose: contains the class definition of Gibbs
**/
#ifndef GIBBSSAMPLER_H
#define GIBBSSAMPLER_H
#include <vector>
#include <string>


using namespace std;

class Gibbs {

public:
	static vector<string> GibbsSampler(string DNA,int k, int t, int N);
};

#endif // !GIBBSSAMPLER_H
