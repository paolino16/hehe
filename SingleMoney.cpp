//SingleMoney.cpp
#include"SingleMoney.h"
#include<iostream>
double ExchangeRate[1000]{ 100,88.792,689.770,514.677,853.253,6.212,517.418,730.456,0.609,19.947,22.541 };
string CurrencyType[1000]{ "CNY", "HKD", "USD", "CAD", "GBP", "JPY", "AUD", "EUR", "KRW", "THB", "TWD" };//Ԥ�������������ʣ�

SingleMoney::SingleMoney(double single_money, string currency_type_now)
	:SingleMoneyAmount(single_money), CurrencyTypeNow(currency_type_now)
{
}


SingleMoney& SingleMoney:: operator+(SingleMoney& m)
{
	this->SingleMoneyAmount = this->SingleMoneyAmount + m.converseCurrency(CurrencyTypeNow);
	return *this;
}


void SingleMoney::addCurrencyTypeAmount()//һ�μ�һ�֣�
{
	string CurrencyName;
	double CurrencyExchangeRate;
	cin >> CurrencyName;
	cin >> CurrencyExchangeRate;
	CurrencyTypeAmount++;
	ExchangeRate[CurrencyTypeAmount - 1] = CurrencyExchangeRate;
	CurrencyType[CurrencyTypeAmount - 1] = CurrencyName;
}

double SingleMoney::findRate(string name)
{
	for (int i = 0; i < CurrencyTypeAmount; i++)
	{
		if (name== CurrencyType[i])
		{
			return ExchangeRate[i];
		}
	}
	return 0;
}

double SingleMoney::converseCurrency(string DstCurrency)
{
	double n;
	n = SingleMoneyAmount * findRate(CurrencyTypeNow) / findRate(DstCurrency);
	return n;
}

void SingleMoney::showSingleMoney()
{
	cout << SingleMoneyAmount << " " << CurrencyTypeNow << endl;
}


int SingleMoney::CurrencyTypeAmount = 11;