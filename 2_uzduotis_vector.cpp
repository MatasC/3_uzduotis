#include "Headers/function.h"
#include "Headers/Time.h"
int main()
{
    char pasirinkimas, pasirinkimas_str;
    duomenys v;
    cin>>v;
    duomenys b{v};
    cout<<b.vardas()<<endl;
    cout << "Ar studentus skirstyti pagal pirma (1), ar pagal antra (2) strategija: ";
    pasirinkimas_str = Ivestis_kr(pasirinkimas_str);
    switch (pasirinkimas_str)
    {
    case '2':
    {
        std::ofstream lout;
        lout.open("Laiku_suvestine.txt", std::fstream::app);
        lout << "2 strategija - Vector: " << endl;
        cout << "Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
        pasirinkimas = Ivestis_kr(pasirinkimas);
        int skaicius = 10000;
        for (int i = 0; i < 2; i++)
        {
            cout << "Apdorojami " << i + 1 << "-ieji duomenys." << endl;
            vector <duomenys> studentai, blogi;
            Time laikas;
            laikas.Start_clock();
            studentai.reserve(skaicius);
            skaitymas(studentai, i, pasirinkimas);
            int ilgiausias_vardas = 6, ilgiausia_pavarde = 7;
            ilgio_nustatymas(studentai, ilgiausias_vardas, ilgiausia_pavarde);
            atrinkimas_2(studentai, blogi);
            isvedimas(studentai, blogi, ilgiausias_vardas, ilgiausia_pavarde);
            blogi.clear();
            laikas.Stop_clock();
            laikas.Get_time(lout, skaicius);
        }
        lout.close();
        cout << "Programos darbas baigtas." << endl;
        break;
    }
    case '1':
    {
        std::ofstream lout;
        lout.open("Laiku_suvestine.txt", std::fstream::app);
        lout << "1 strategija - Vector: " << endl;
        cout << "Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
        pasirinkimas = Ivestis_kr(pasirinkimas);
        int skaicius = 10000;
        for (int i = 0; i < 2; i++)
        {
            cout << "Apdorojami " << i + 1 << "-ieji duomenys." << endl;
            vector <duomenys> studentai, geri, blogi;
            Time laikas;
            laikas.Start_clock();
            studentai.reserve(skaicius);
            skaitymas(studentai, i, pasirinkimas);
            int ilgiausias_vardas = 6, ilgiausia_pavarde = 7;
            ilgio_nustatymas(studentai, ilgiausias_vardas, ilgiausia_pavarde);
            atrinkimas_1(studentai, blogi, geri);
            isvedimas(blogi, geri, ilgiausias_vardas, ilgiausia_pavarde);
            studentai.clear();
            blogi.clear();
            geri.clear();
            laikas.Stop_clock();
            laikas.Get_time(lout, skaicius);
        }
        lout.close();
        cout << "Programos darbas baigtas." << endl;
        break;
    }
    }
}
