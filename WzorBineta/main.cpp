#include <iostream>;
#include <cmath>;
#include <fstream>;
using namespace std;

unsigned long long wzorBineta(unsigned long long n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return 1 / sqrt(5) * (pow((1 + sqrt(5))/2,n)- pow((1 - sqrt(5)) / 2, n));
}

unsigned long long fibonaciInteracyjny(unsigned long long n) {
	unsigned long long poprz = 1;
	unsigned long long cur = 1;
	unsigned long long next = 1;
	if (n == 1 || n == 2) {
		return 1;
	}
	for (int i = 2; i < n; i++) {
		next = cur + poprz;
		poprz = cur;
		cur = next;
	}
	return next;
}

int main() {

	ofstream MyFile("wyniki.txt");

	for (unsigned long long i = 1; i <= 93; i++) {
		cout << "Wyraz nr " << i << endl;
		cout << "Iteracyjnie: " << endl;
		cout << fibonaciInteracyjny(i) << endl;
		cout << "Ze wzoru bineta: " << endl;
		cout << wzorBineta(i) << endl;
		cout << "Roznica: " <<  wzorBineta(i) - fibonaciInteracyjny(i) << endl;
		cout << endl;
		MyFile << i << ',' << fibonaciInteracyjny(i) << endl;
	}
	MyFile.close();
	return 0;
}