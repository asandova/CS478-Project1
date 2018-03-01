#include <iostream>
#include "FASTA.h"
#include "MedianString.h"
#include "GibbsSampler.h"

using namespace std;

void testall() {
	FASTA seq = FASTA();
	seq.readFile("Test1.fasta");
	///Median String tests
	
	cout << seq;
	cout << "MedianString" << endl;
	cout << "input Sequence set 1 with 3-kers" << endl;
	cout << MidString::MedianString(seq.getSequences(0), 3);
	
	///Gibbs Sampler tests
	/*
	vector<string> DNAlines = seq.getSequences(0);
	Gibbs::GibbsAlgorithm(DNAlines, 3);
	Gibbs::train(1000000);
	for (size_t i = 0; i < DNAlines.size(); ++i)
		cerr << Gibbs::startingPosition[i] << "\t" << DNAlines[i].substr(Gibbs::startingPosition[i], Gibbs::motifLength) << endl;
	*/
}

int main() {
	testall();
	return 0;
}

/** R


*/