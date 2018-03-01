#include <iostream>
#include "FASTA.h"
#include "MedianString.h"
#include "GibbsSampler.h"

using namespace std;

FASTA Test = FASTA("Test1.fasta");

//[[Rcpp::export]]
void MedianWrap(int k) {
	MidString::MedianString(Test.getSequences(0), k);
}

//[[Rcpp::export]]
void GibbsWarp(int k) {
	vector<string> DNAlines = Test.getSequences(0);
	Gibbs::GibbsAlgorithm(DNAlines, k);
	Gibbs::train(1000000);
	for (size_t i = 0; i < DNAlines.size(); ++i)
		cerr << Gibbs::startingPosition[i] << "\t" << DNAlines[i].substr(Gibbs::startingPosition[i], Gibbs::motifLength) << endl;
}

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
k <- c(10,20,30,40,50)

runtimeMedian <- vector(length = 5)
runtimeGibb <- vector(length = 5)

for(i in c(1:5)){
	runtimeMedian <- system.time( MedianWrap(k[i]) )["user.self"]
	runtimeGibb <- system.time( GibbsWarp(k[i]) )["user.self"]
}

plot(k, runtimeMedian, type="o", xlab="k length", ylab = "runtime(seconds)")
points(k, runtimeGibb, col="red", pch="*")
lines(k, runtimeGibb, col="red",ity=2)
*/