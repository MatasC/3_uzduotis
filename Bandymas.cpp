#include"Headers/function.h"
int main()
{
	Vector<Studentas> test1, test2, test3;
	int a = 0, b = 0;
	char pasirinkimas = 'v';
	skaitymas(test1, 0, pasirinkimas);
	std::sort(test1.begin(), test1.end(), tikrinimas_gal);

	// atrinkimas_1(test1,test2,test3);
}