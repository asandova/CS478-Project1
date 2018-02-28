all: link

link: GibbsSampler.o MedianString.o HamminDistance.o FASTA.o
	g++ Main.cpp GibbsSampler.o MedianString.o HamminDistance.o FASTA.o -o Project1

GibbsSamper.o: GibbsSampler.cpp GibbsSampler.h
	g++ -c GibbsSampler.cpp

MedianString.o: MedianString.cpp MedianString.cpp
	g++ -c MedianString.cpp

HamminDistance.o: HamminDistance.cpp HamminDistance.h
	g++ -c HamminDistance.cpp

FASTA.o: FASTA.cpp FASTA.h
	g++ -c FASTA.cpp