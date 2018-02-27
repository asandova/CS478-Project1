/**
*	Class: CS486
*	File: FASTA.h
*	Assignment: Project 1
*	Author(s): August B.Sandoval
*	Purpose: contains the class definition of FASTA
**/
#ifndef FASTA_H
#define FASTA_H
#include <vector>
#include <list>


using namespace std;

class FASTA {
	/*
	stores and reads data in FASTA format
	"headers" is where all the headers found in the file are stored
	"sequences" is where all the sequience for a partiular header are stored
	These two vector are one to one, The index of a header in the header corosponds to the index of it matching sequences
	*/
private:
	vector<string> headers;
	vector< vector<string> > sequences;

public:
	FASTA();
	FASTA(string filename);
	void readFile(string filename);
	void addHeader(string header);
	void addSequences(string sequence, int headerID);
	int getHeaderID(string header);
	vector<string> getSequences(int HeaderID);

};

#endif // !FASTA_H

