#include "Headers/function.h"

duomenys::duomenys(duomenys&& studentas)
{
	vardas_ = std::move(studentas.vardas_);
	pavarde_ = std::move(studentas.pavarde_);
	egzaminas_ = std::move(studentas.egzaminas_);
	galutinis_ = std::move(studentas.galutinis_);
	namu_darbai_ = std::move(studentas.namu_darbai_);
}

duomenys::duomenys(const duomenys& studentas)
{
	vardas_ = studentas.vardas_;
	pavarde_ = studentas.pavarde_;
	egzaminas_ = studentas.egzaminas_;
	galutinis_ = studentas.galutinis_;
	namu_darbai_ = studentas.namu_darbai_;
}

std::ostream& operator<<(std::ostream out, const duomenys& studentas)
{
	out << studentas.vardas() << studentas.pavarde() << studentas.galutinis() << endl;
	return out;
}

duomenys& duomenys::operator=(const duomenys& studentas)
{
	if (&studentas == this) return *this;

	vardas_ = studentas.vardas_;
	pavarde_ = studentas.pavarde_;
	egzaminas_ = studentas.egzaminas_;
	galutinis_ = studentas.galutinis_;
	namu_darbai_ = studentas.namu_darbai_;
	return *this;
}

void duomenys::galutinis(char &pasirinkimas)
{
	switch (pasirinkimas)
	{
	case 'm':
	{
		if (namu_darbai_.size() == 0)
		{
			exit(0);
		}
		else
		{
			double mediana = 0;
			std::sort(namu_darbai_.begin(), namu_darbai_.end());
			if (namu_darbai_.size() % 2 == 0)
			{
				mediana = (namu_darbai_[namu_darbai_.size() / 2 - 1] + namu_darbai_[namu_darbai_.size() / 2]) / 2.0;
			}
			else
			{
				mediana = namu_darbai_[namu_darbai_.size() / 2] * 1.0;
			}
			galutinis_ = mediana * 0.4 + 0.6 * egzaminas_;
		}
		namu_darbai_.clear();
		break;
	}
	case 'v':
	{
		if (namu_darbai_.size() == 0)
		{
			exit(0);
		}
		else
		{
			double vidurkis = 0;
			for (int w = 0; w < namu_darbai_.size(); w++)
			{
				vidurkis += namu_darbai_[w];
			}
			vidurkis /= double(namu_darbai_.size());
			galutinis_ = vidurkis * 0.4 + 0.6 * egzaminas_;
		}
		namu_darbai_.clear();
		break;
	}
	}
}

void duomenys::spausdinimas(std::ofstream& out, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
	out << std::setw(ilgiausias_vardas + 2) << std::left << vardas_ << std::setw(ilgiausia_pavarde + 2) << std::left << pavarde_ << std::fixed << std::setprecision(2) << std::setw(4) << std::left << galutinis_ << endl;
}

std::istringstream duomenys::Duomenu_irasymas(std::istringstream& skaitymas)
{
	skaitymas >> vardas_;
	skaitymas >> pavarde_;
	int temp_nd;
	for (int i = 0; i < 10; i++)
	{
		skaitymas >> temp_nd;
		namu_darbai_.push_back(temp_nd);
	}
	skaitymas >> egzaminas_;
	try {
		if (namu_darbai_.size() == 0) throw std::runtime_error("Mokinio namu darbu skaicius lygus nuliui, todel jo galutinis pazymys bus laikomas 0\n");
	}
	catch (const std::runtime_error& e)
	{
		cout << e.what();
		galutinis_ = 0;
	}
	std::istringstream end;
	return end;
}

void skaitymas(vector <duomenys> &studentai, int i, char &pasirinkimas)
{
	std::ifstream in;
	in.open("mokiniai" + std::to_string(i + 1) + ".txt");
	try {
		if (!in) throw std::runtime_error("Failo atidarymo klaida\n");
	}
	catch (const std::runtime_error& e)
	{
		cout << e.what();
		exit(0);
	}
	int temp = 0;
	string eilute;
	while (getline(in, eilute))
	{
		std::istringstream skaityti(eilute);
		studentai.push_back(duomenys());
		studentai[temp].Duomenu_irasymas(skaityti);
		studentai[temp].galutinis(pasirinkimas);
		temp++;
	}
	in.close();
}

void isvedimas(vector <duomenys> &blogi, vector <duomenys> &geri, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
	std::ofstream out1("geri.txt");
	std::ofstream out2("blogi.txt");
	out1 << std::setw(ilgiausias_vardas + 2) << std::left << "Vardas" << std::setw(ilgiausia_pavarde + 2) << std::left << "Pavarde  " << std::left << "Galutinis" << endl;
	out2 << std::setw(ilgiausias_vardas + 2) << std::left << "Vardas" << std::setw(ilgiausia_pavarde + 2) << std::left << "Pavarde  " << std::left << "Galutinis" << endl;
	for (int i = 0; i < ilgiausias_vardas + ilgiausia_pavarde + 13; i++)
	{
		out1 << "-";
		out2 << "-";
	}
	out1 << endl;
	out2 << endl;
	for (auto i : blogi)
		i.spausdinimas(out2, ilgiausias_vardas, ilgiausia_pavarde);
	for (auto i : geri)
		i.spausdinimas(out1, ilgiausias_vardas, ilgiausia_pavarde);
	out1.close();
	out2.close();
}

void ilgio_nustatymas(vector<duomenys>& studentai, int &ilgiausias_vardas, int& ilgiausia_pavarde)
{
	std::vector<duomenys>::iterator it = std::max_element(studentai.begin(), studentai.end(), tikrinimas_vard);
	ilgiausias_vardas = it->vard_ilgis();
	it = std::max_element(studentai.begin(), studentai.end(), tikrinimas_pavard);
	ilgiausia_pavarde = it->pavard_ilgis();
}

void atrinkimas_1(vector <duomenys>& studentai, vector <duomenys>& blogi, vector <duomenys>& geri)
{
	sort(studentai.begin(), studentai.end(), tikrinimas_gal);
	std::vector<duomenys>::iterator it = std::find_if(studentai.begin(), studentai.end(), tikrinimas_5);
	std::copy(it, studentai.end(), std::back_inserter(geri));
	studentai.resize(studentai.size() - geri.size());
std: copy(studentai.begin(), it, std::back_inserter(blogi));
	studentai.clear();
}
void atrinkimas_2(vector <duomenys>& studentai, vector<duomenys> &blogi)
{
	sort(studentai.begin(), studentai.end(), tikrinimas_gal);
	std::vector<duomenys>::iterator it = std::find_if(studentai.begin(), studentai.end(), tikrinimas_5);
	std::copy(it, studentai.end(), std::back_inserter(blogi));
	studentai.resize(studentai.size() - blogi.size());
}


bool tikrinimas(duomenys stud1, duomenys stud2)
{
	return stud1.vardas() < stud2.vardas();
}

bool tikrinimas_gal(duomenys stud1, duomenys stud2)
{
	return stud1.galutinis() < stud2.galutinis();
}

bool tikrinimas_5(duomenys stud1)
{
	return stud1.galutinis() == 5;
}

bool tikrinimas_vard(duomenys stud1, duomenys stud2)
{
	return stud1.vard_ilgis() < stud2.vard_ilgis();
}

bool tikrinimas_pavard(duomenys stud1, duomenys stud2)
{
	return stud1.pavard_ilgis() < stud2.pavard_ilgis();
}

char Ivestis_kr(char pasirinkimas)
{
	cin >> pasirinkimas;
	while (pasirinkimas != 'v')
	{
		if (pasirinkimas == 'm' || pasirinkimas == '2' || pasirinkimas == '1')
			break;
		cout << "Neteisingas kriterijus. Bandykite dar karta." << endl;
		cin >> pasirinkimas;
	}
	return pasirinkimas;
}
