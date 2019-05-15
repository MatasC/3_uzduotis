#ifndef FUNCTION
#define FUNCTION
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<random>
#include<algorithm>
#include"vector.h"
#include<sstream>
#include<ctype.h>
#include<chrono>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::sort;

class Zmogus
{
protected:
	string vardas_;
	string pavarde_;
public:
	virtual void fun() = 0;
	Zmogus(const string& a = " ", const string& b = " ") : vardas_{a}, pavarde_{b} {}
	Zmogus(string&& a, string&& b) : vardas_{a}, pavarde_{b} {}
	inline std::string vardas() const { return vardas_; }
	inline std::string pavarde() const { return pavarde_; }
	inline int vard_ilgis() const { return vardas_.length(); }
	inline int pavard_ilgis() const { return pavarde_.length(); }
	~Zmogus() {}
};
class Studentas : public Zmogus
{
private:
	double egzaminas_;
	double galutinis_;
	Vector <double> namu_darbai_;
public:
	void fun() {};
	Studentas(const string& a = " ", const string& b = " ", const double& egz = 10) : Zmogus(a, b), egzaminas_{egz} {}
	Studentas(const Studentas& a) : Zmogus(a.vardas_, a.pavarde_), egzaminas_{a.egzaminas_}, galutinis_{a.galutinis_}, namu_darbai_{a.namu_darbai_} {}
	Studentas(Studentas&& a) : Zmogus(std::move(a.vardas_), std::move(a.pavarde_)), egzaminas_{std::move(a.egzaminas_)}, galutinis_{std::move(a.galutinis_)}, namu_darbai_{std::move(a.namu_darbai_)} {}
	inline double galutinis() const { return galutinis_; }
	void galutinis(char &);
	void spausdinimas(std::ofstream& out, int &, int &);
	std::istringstream Duomenu_irasymas(std::istringstream&);
	Studentas& operator=(const Studentas&);
	friend std::istream& operator>>(std::istream& in, Studentas& studentas)
	{
		in >> studentas.vardas_ >> studentas.pavarde_;
		double temp;
		for (int i = 0; i < 10; i++)
		{
			in >> temp;
			studentas.namu_darbai_.push_back(temp);
		}
		in >> studentas.egzaminas_ >> studentas.galutinis_;
		return in;
	}
	bool operator==(const Studentas& d)
	{
		return galutinis_ == d.galutinis_;
	}
	bool operator!=(const Studentas& d)
	{
		return galutinis_ != d.galutinis_;
	}
	~Studentas() {}
};

std::ostream& operator<<(std::ostream&, const Studentas&);

bool tikrinimas(Studentas, Studentas);
bool tikrinimas_gal(Studentas, Studentas);
bool tikrinimas_5(Studentas);
bool tikrinimas_vard(Studentas, Studentas);
bool tikrinimas_pavard(Studentas, Studentas);
char Ivestis_kr(char);

void skaitymas(Vector <Studentas>&, int, char&);

void ilgio_nustatymas(Vector<Studentas>&, int&, int&);

void isvedimas(Vector <Studentas>&, Vector <Studentas>&, int&, int&);

void atrinkimas_1(Vector <Studentas>&, Vector <Studentas>&, Vector <Studentas>&);
void atrinkimas_2(Vector <Studentas>&, Vector<Studentas>&);

void generavimas(std::ofstream&, int);

#endif // FUNCTION