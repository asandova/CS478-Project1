#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <random>

struct GibbsAlgorithm
{

	//Variables
    int motifLength;
    std::vector<std::vector<int>> sequenceSet;
    std::vector<int> startingPosition;
    std::vector<std::vector<double>> profileMatrice;
    std::vector<double> charFrequency;
    std::string const lettersAllowed = "ATCGatcg";


    //from given histogram
    int generateRandom(std::vector<double> const &d)
    {
        std::random_device rd; //random variable device
        std::mt19937 generator(rd());  //random # generator
        std::discrete_distribution<int> distribution(d.begin(), d.end());
        return distribution(generator);
    }


    GibbsAlgorithm(std::vector<std::string> const &s, int const motifSize)
    {
    	motifLength = motifSize;
        sequenceSet.resize(s.size());
        startingPosition.resize(s.size(), 0.);
        charFrequency.resize(lettersAllowed.size(), 1. );
        for (size_t i = 0; i < s.size(); ++ i) {
            sequenceSet[i].resize(s[i].size());
            std::transform(s[i].begin(), s[i].end(), sequenceSet[i].begin(), [&](char c){return lettersAllowed.find(c);});
            std::for_each(sequenceSet[i].begin(), sequenceSet[i].end(), [&](int c){++ charFrequency[c];});
        }
        profileMatrice = std::vector<std::vector<double>>(motifSize + 1, std::vector<double>(lettersAllowed.size(), 1. / lettersAllowed.size()));
    }

    void normalize(std::vector<double> v)
    {
        double sum = 0.;
        for (size_t i = 0; i < v.size(); ++ i) sum += v[i];
        for (size_t i = 0; i < v.size(); ++ i) v[i] /= sum;
    }

    void train(unsigned int const maxIt)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        for (size_t i = 0; i < sequenceSet.size(); ++ i) startingPosition[i] = rand() % (sequenceSet[i].size() - motifLength + 1);
        for (size_t i = 0, count = 0; count < 10 + sequenceSet.size() && i < maxIt; ++ i) {
            int hold = rand() % sequenceSet.size();
            std::fill_n(profileMatrice.begin(), motifLength + 1, std::vector<double>(lettersAllowed.size(), 1.0 ));
            profileMatrice[0] = charFrequency;
            for (size_t j = 0; j < sequenceSet.size(); ++ j) /* update Matrice*/
                if (hold != (int)j)
                    for (int k = 0; k < motifLength; ++ k) {
                        ++ profileMatrice[k + 1][sequenceSet[j][startingPosition[j] + k]];
                        -- profileMatrice[0][sequenceSet[j][startingPosition[j] + k]];
                    }
            for (size_t j = 0; j < sequenceSet[hold].size(); ++ j) -- profileMatrice[0][sequenceSet[hold][j]]; /* update null */
            for (size_t j = 0; j < profileMatrice.size(); ++ j) normalize(profileMatrice[j]);
            std::vector<double> weightNew(sequenceSet[hold].size() - motifLength + 1, 1.);
            for (size_t j = 0; j < sequenceSet[hold].size() - motifLength + 1; ++ j)
                for (int k = 0; k < motifLength; ++ k)
                    weightNew[j] *= profileMatrice[k + 1][sequenceSet[hold][j + k]] / profileMatrice[0][sequenceSet[hold][j + k]];
            double old = startingPosition[hold];
            count = old == (startingPosition[hold] = generateRandom(weightNew))? count + 1: 0; //criteria of convergence
        }
    }
};



int main(int const, char const * const argv[]){
    std::ifstream fasta(argv[1]);
    std::vector<std::string> dnaLinesOnly;
    for (std::string dnaFile; getline(fasta, dnaFile);)
        if ('>' == dnaFile.at(0))
            dnaLinesOnly.push_back("");
        else
        	dnaLinesOnly.back() += dnaFile;
    int const motifLength = atoi(argv[2]);
    GibbsAlgorithm g(dnaLinesOnly, motifLength);
    g.train(1000000);
    for (size_t i = 0; i < dnaLinesOnly.size(); ++ i)
        std::cerr << g.startingPosition[i] << "\t"<< dnaLinesOnly[i].substr(g.startingPosition[i], motifLength) << std::endl;
    return 0;
}

