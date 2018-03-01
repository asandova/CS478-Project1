/**
*	Class: CS 486
*	File: FASTA.cpp
*	Assignment: Project 1
*	Author(s): August B.Sandoval
*	Purpose: contains the class implementation of FASTA
**/

#include "FASTA.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

FASTA::FASTA() {
	headers = vector<string>();
	sequences = vector< vector <string> >();
}

FASTA::FASTA(string filename) {
	FASTA();
	readFile(filename);
}

void FASTA::readFile(string filename) {
	fstream ifile;
	string l;
	int num = 0;
	ifile.open(filename, ifstream::in);
	if (ifile.is_open()) {
		while (!ifile.eof() ) {
			getline(ifile, l);
			if (l[0] == '>') {
				addHeader(l.substr(2, l.size()-2 ));
				num++;
			}
			else if(num > 0){
				addSequences(l, num-1);
			}
		}
	}
}
void FASTA::addHeader(string header) {

	if (getHeaderID(header) == -1) {
		headers.push_back(header);
		vector<string> seq = vector<string>();
		sequences.push_back(seq);
	}
}
void FASTA::addSequences(string sequence, size_t headerID) {
	sequences[headerID].push_back(sequence);
}
int FASTA::getHeaderID(string header) {
	//will get the index of given header
	//if the header does not exist, then return -1
	for (size_t i = 0; i < headers.size(); i++) {
		if (headers[i] == header) {
			return i;
		}
	}
	return -1;
}
vector<string> FASTA::getSequences(size_t HeaderID) {
	return sequences[HeaderID];
}

ostream& operator<<(ostream & out, const FASTA& f) {
	for (size_t i = 0; i < f.headers.size(); i++) {
		out << f.headers[i] << endl;
		vector<string> seq = f.sequences[i];
		vector<string>::const_iterator itr;
		for (itr = seq.begin(); itr != seq.end(); ++itr) {
			out << *itr << endl;
		}
	}
	return out;
}