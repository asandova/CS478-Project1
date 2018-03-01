/**
*	Class: CS 486
*	File: GibbsSampler.cpp
*	Assignment: Project 1
*	Author(s): August B.Sandoval
*	Purpose: contains the implementation of static class Gibbs
**/
#include "GibbsSampler.h"
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

/*
vector<string> Gibbs::GibbsSampler(vector<string>& DNA, int k, int t, int N) {
	vector<string> kmer = selectKmer(DNA,k);
	vector<string> BestMotifs = kmer;
	vector<double> prof;
	vector<string>temp = vector<string>();
	int ran;
	for (int i = 0; i < N; i++) {
		ran = rand() % t;
		prof = profile(DNA, ran);
		if (score(kmer) < score(BestMotifs)) {
			BestMotifs = kmer;

		}
	}
	return BestMotifs;
}

double Gibbs::score(vector<string> motifs) {

}

vector<double> profile(vector<string> motifs, int ex) {
	//index: A = 0, C = 1, G = 3, T = 4
	vector<int> counts(4,0);

	for()
}

*/
vector< vector< int > > Gibbs::sequenceSet = vector< vector<int>>();
vector< int > Gibbs::startingPosition = vector <int>();
vector< vector< double > > Gibbs::profileMatrice = vector< vector<double>>();
vector<double> Gibbs::charFrequency = vector<double>();
const string Gibbs::lettersAllowed = "ATCGatcg";
int Gibbs::motifLength = 0;

int Gibbs::generateRandom(std::vector<double> const &d)
{
	random_device rd; //random variable device
	mt19937 generator(rd());  //random # generator
	discrete_distribution<int> distribution(d.begin(), d.end());
	return distribution(generator);
}


void Gibbs::GibbsAlgorithm(vector<string> const &s, int const motifSize)
{
	motifLength = motifSize;
	sequenceSet.resize(s.size());
	startingPosition.resize(s.size(), 0);
	charFrequency.resize(lettersAllowed.size(), 1.);
	for (size_t i = 0; i < s.size(); ++i) {
		sequenceSet[i].resize(s[i].size());
		transform(s[i].begin(), s[i].end(), sequenceSet[i].begin(), [&](char c) {return lettersAllowed.find(c); });
		for_each(sequenceSet[i].begin(), sequenceSet[i].end(), [&](int c) {++charFrequency[c]; });
	}
	profileMatrice = vector<vector<double>>(motifSize + 1, vector<double>(lettersAllowed.size(), 1. / lettersAllowed.size()));
	
}

void Gibbs::normalize(vector<double> v)
{
	double sum = 0.;
	for (size_t i = 0; i < v.size(); ++i) sum += v[i];
	for (size_t i = 0; i < v.size(); ++i) v[i] /= sum;
}

void Gibbs::train(size_t const maxIt)
{
	srand(static_cast<size_t>(time(NULL)));
	for (size_t i = 0; i < sequenceSet.size(); ++i) startingPosition[i] = rand() % (sequenceSet[i].size() - motifLength + 1);
	for (size_t i = 0, count = 0; count < 10 + sequenceSet.size() && i < maxIt; ++i) {
		int hold = rand() % sequenceSet.size();
		fill_n(profileMatrice.begin(), motifLength + 1, vector<double>(lettersAllowed.size(), 1.0));
		profileMatrice[0] = charFrequency;
		for (size_t j = 0; j < sequenceSet.size(); ++j) /* update Matrice*/
			if (hold != (int)j)
				for (int k = 0; k < motifLength; ++k) {
					++profileMatrice[k + 1][sequenceSet[j][startingPosition[j] + k]];
					--profileMatrice[0][sequenceSet[j][startingPosition[j] + k]];
				}
		for (size_t j = 0; j < sequenceSet[hold].size(); ++j) --profileMatrice[0][sequenceSet[hold][j]]; /* update null */
		for (size_t j = 0; j < profileMatrice.size(); ++j) normalize(profileMatrice[j]);
		vector<double> weightNew(sequenceSet[hold].size() - motifLength + 1, 1.);
		for (size_t j = 0; j < sequenceSet[hold].size() - motifLength + 1; ++j)
			for (int k = 0; k < motifLength; ++k)
				weightNew[j] *= profileMatrice[k + 1][sequenceSet[hold][j + k]] / profileMatrice[0][sequenceSet[hold][j + k]];
		double old = startingPosition[hold];
		count = old == (startingPosition[hold] = generateRandom(weightNew)) ? count + 1 : 0; //criteria of convergence
	}
}