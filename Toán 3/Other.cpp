#include "pch.h"

bool PhanSo::TestMau(PhanSo A)
{
	if (A.Mau != 1) return true;
	return false;
}
PhanSo PhanSo::BCNN(PhanSo &A, PhanSo B)
{
	int a = A.Tu, b = B.Tu;
	int c = A.Mau, d = B.Mau;
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	while (d != 0)
	{
		int r = c % d;
		c = d;
		d = r;
	}
	return A * B / PhanSo(a, c);
}
PhanSo ToiGian(PhanSo A)
{
	int a = A.Tu, b = A.Mau;
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return PhanSo((A.Mau / a) < 0 ? (-A.Tu / a) : (A.Tu / a), (A.Mau / a) < 0 ? (-A.Mau / a) : (A.Mau / a));
}
void SwapRow(vector <vector <PhanSo> >& A, vector <PhanSo>& B, bool &While)
{
	while (1)
	{

		bool Test = true;
		for (int i = 0; i < A.size(); i++)
			if (A[i][i] == 0)
			{
				While = true;
				Test = false;
				for (int j = 0; j < A.size(); j++)
					if (A[j][i] != 0 and A[i][j] != 0)
					{
						swap(A[i], A[j]);
						wcout << L"Đổi chỗ hàng " << i + 1 << L" vói hàng " << j + 1 << endl;
						While = false;
						break;
					}
				if (While)
				{
					wcout << L"\n\t\tError: Không thể đổi hàng " << i + 1 << " ! ! !\n";
					break;
				}
			}
		if (Test) break;
		if (While) break;
	}
}
void SwapRow(vector <vector <PhanSo> >& A, vector <PhanSo>& B, int io)
{
	Erase(A, B);
	int size = A.size() < B.size() ? A.size() : B.size();
	for (int i = 0; i < size; i++)
		if (A[i][i] == 0)
			for (int j = 0; j < A.size(); j++)
				if (A[j][i] != 0 and A[i][j] != 0)
				{
					if (io == 1)wcout << L"Đổi chỗ hàng " << i + 1 << L" vói hàng " << j + 1 << endl;
					swap(A[j], A[i]);
					break;
				}
}
void Erase(vector <vector <PhanSo> >& A, vector <PhanSo>& B)
{
	for (int i = 0; i < A.size() - 1; i++)
		for (int j = i + 1; j < A.size(); j++)
		{
			bool Khong0 = true;
			bool Khong1 = true;
			bool HeSo = true;
			for (int k = 0; k < B.size(); k++)
			{
				if (A[i][k] != 0) Khong0 = false;
				if (A[j][k] != 0) Khong1 = false;
				if (k < B.size() - 1)
					if (ToiGian((A[j][k] / A[i][k]) / (A[j][k + 1] / A[i][k + 1])) != 1) HeSo = false;
				if (Khong1 == false and Khong0 == false and HeSo == false) break;
			}
			if (Khong1 or Khong0 or HeSo)
			{
				if (Khong0) for (int k = i; k < A.size() - 1; k++) A[k] = A[k + 1];
				else for (int k = j; k < A.size() - 1; k++) A[k] = A[k + 1];
				A.resize(A.size() - 1, B);
				i -= 1;
			}
		}
}