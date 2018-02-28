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
/*
public:
	static vector<string> GibbsSampler(vector<string>& DNA,int k, int t, int N);
	static double score(vector<string> motifs);
	static vector<double> profile(vector<string> motifs, int ex);
	static vector<string> selectKmer(vector<string>& DNA, int k);
*/

private:
	static int motifLength;
	static vector< vector< int > > sequenceSet;
	static vector< int > startingPosition;
	static vector< vector< double > > profileMatrice;
	static vector<double> charFrequency;
	static const string lettersAllowed;
public:
	static int generateRandom(vector<double> const &d);
	static int GibbsAlgorithm(vector<string> const &s, int const motifSize);
	void normalize(vector<double> v);
	void train(size_t const maxIt);
};

#endif // !GIBBSSAMPLER_H
