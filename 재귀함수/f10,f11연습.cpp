#include <iostream>
using namespace std;

void MC()
{
	cout << "MC ";
}

void BHC()
{
	MC();
	cout << "BHC ";
}

void MOMS()
{
	BHC();
	cout << "MOMS ";
}

void BBQ()
{
	MOMS();
	cout << "BBQ ";
}

void KFC()
{
	BHC();
	BBQ();
	cout << "KFC ";
}

int main()
{
	KFC();
	BBQ();
}