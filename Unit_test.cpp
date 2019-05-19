#include "Headers/function.h"
#include <gtest/gtest.h>

Studentas a, b;
std::istringstream in1("matas cenys 1 2 3 4 5 6 7 8 9 10 10");
std::istringstream in2("matas tas 1 2 3 4 5 6 7 8 9 10 10");
std::istringstream in3("matas anas 1 2 3 4 5 6 7 8 9 10 10");
std::istringstream in4("matas sitas 1 2 3 4 5 6 7 8 9 10 10");

TEST(kriterijus, vidurkis)
{
	ASSERT_EQ('v', Ivestis_kr('v'));
}
TEST(kriterijus, mediana)
{
	ASSERT_EQ('m', Ivestis_kr('m'));
}
TEST(tikrinimas, galutinio_ok)
{
	ASSERT_EQ(true, tikrinimas_5(a));
}
TEST(tikrinimas, galutinio_bad)
{
	ASSERT_EQ(false, tikrinimas_5(b));
}
TEST(Klase, Duomenu_irasymas)
{
	EXPECT_EQ("matas", a.vardas());

	a.Duomenu_irasymas(in1);

	EXPECT_EQ("cenys", a.pavarde());

	a.Duomenu_irasymas(in2);

	EXPECT_EQ("tas", a.pavarde());

	a.Duomenu_irasymas(in3);

	EXPECT_EQ("anas", a.pavarde());

	a.Duomenu_irasymas(in4);

	EXPECT_EQ("sitas", a.pavarde());

}

int main(int argc, char **argv)
{
	cout << "Ivesti pirma mokini testavimui: " << endl;
	cin >> a;
	cout << "Ivesti antra mokini: " << endl;
	cin >> b;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}