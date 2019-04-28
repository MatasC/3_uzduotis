#ifndef FUNCTION
#define FUNCTION
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<random>
#include<algorithm>
#include<vector>
#include<sstream>
#include<ctype.h>
#include<chrono>
#include<list>
#include<deque>
#include<iterator>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::list;
using std::deque;

class duomenys
{
private:
	string vardas_;
	string pavarde_;
	double egzaminas_;
	double galutinis_;
	vector <double> namu_darbai_;
public:
	duomenys() {}
	duomenys(const duomenys&);
	duomenys(duomenys&& s) :
		vardas_{s.vardas_},
		pavarde_{s.pavarde_},
		egzaminas{s.egzaminas_},
		galutinis_{std::move(s.galutinis_)},
		namu_darbai_{std::move(s.namu_darbai_)}
	{}
	inline std::string vardas() const { return vardas_; }
	inline std::string pavarde() const { return pavarde_; }
	inline double galutinis() const { return galutinis_; }
	inline int vard_ilgis() const { return vardas_.length(); }
	inline int pavard_ilgis() const { return pavarde_.length(); }
	void galutinis(char &);
	void spausdinimas(std::ofstream& out, int &, int &);
	std::istringstream Duomenu_irasymas(std::istringstream&);
	duomenys& operator=(const duomenys&);
	friend std::istream& operator>>(std::istream& in, duomenys& studentas)
	{
		in >> studentas.vardas_ >> studentas.pavarde_;
		double temp;
		for (int i = 0; i < 10; i++)
		{
			in >> temp;
			studentas.namu_darbai_.push_back(temp);
		}
		in >> studentas.egzaminas_;
		return in;
	}
	bool operator==(const duomenys& d)
	{
		return galutinis_ == d.galutinis_;
	}
	bool operator!=(const duomenys& d)
	{
		if (galutinis_ != d.galutinis_)
			return true;
		return false;
	}
	~duomenys() {}
};


std::ostream& operator<<(std::ostream&, const duomenys&);

bool tikrinimas(duomenys, duomenys);
bool tikrinimas_gal(duomenys, duomenys);
bool tikrinimas_5(duomenys);
bool tikrinimas_vard(duomenys, duomenys);
bool tikrinimas_pavard(duomenys, duomenys);
char Ivestis_kr(char);

void skaitymas(vector <duomenys>&, int, char&);

void ilgio_nustatymas(vector<duomenys>&, int&, int&);

void isvedimas(vector <duomenys>&, vector <duomenys>&, int&, int&);

void atrinkimas_1(vector <duomenys>&, vector <duomenys>&, vector <duomenys>&);
void atrinkimas_2(vector <duomenys>&, vector<duomenys>&);

void generavimas(std::ofstream&, int);

#endif // FUNCTION
