#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
int n;
int *p = new int[n];
void qs(int l, int r) 
{
	int c = p[(l + r) / 2];// Нахождение центрально элемента
	int a = l;
	int b = r;
	while (a <= b)
	{
		while (p[a] < c)
		{
			a++;
		}
		while (p[b] > c)
		{
			b--;
		}
		if (a <= b)
		{
			swap(p[a] , p[b]);
			a++;
			b--;
		}
	}
	if (a<r)
		qs(a, r);

	if (l<b)
		qs(l, b);
	return;
}

int main()
{
	setlocale (LC_ALL, "Russian");
	cout << "number of elements"<<endl;
	cin >> n;
	cout << "edit number"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	qs(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	delete[] p;
	system("pause");
	return 0;
}