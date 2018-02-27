#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string dna, name;
	vector <int> A, C, G, T;

	// read first dna
	cin >> name >> dna;
	int n = dna.size();

	// init vectors
	for (int i=0; i<n; i++) {
		A.push_back(dna[i]=='A');
		C.push_back(dna[i]=='C');
		G.push_back(dna[i]=='G');
		T.push_back(dna[i]=='T');
	}

	// calc of numer of nucleos
	while (cin >> name >> dna) {
		for (int i=0; i<n; i++) {
			A[i] += dna[i]=='A';
			C[i] += dna[i]=='C';
			G[i] += dna[i]=='G';
			T[i] += dna[i]=='T';
		}
	}

	// print the consensus string
	for (int i=0; i<n; i++) {
		if (A[i] >= C[i] && A[i] >= G[i] && A[i] >= T[i]) cout << 'A';
		else if (C[i] >= A[i] && C[i] >= G[i] && C[i] >= T[i]) cout << 'C';
		else if (G[i] >= A[i] && G[i] >= C[i] && G[i] >= T[i]) cout << 'G';
		else if (T[i] >= A[i] && T[i] >= C[i] && T[i] >= G[i]) cout << 'T';
	}
	cout << endl;

	// print the profile matrix
	cout << "A: ";
	for (int i=0; i<n; i++) cout << A[i] << " ";
	cout << endl;
	cout << "C: ";
	for (int i=0; i<n; i++) cout << C[i] << " ";
	cout << endl;
	cout << "G: ";
	for (int i=0; i<n; i++) cout << G[i] << " ";
	cout << endl;
	cout << "T: ";
	for (int i=0; i<n; i++) cout << T[i] << " ";
	cout << endl;
	return 0;
}