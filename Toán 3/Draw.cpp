#include "pch.h"

void PhanSo::Draw(vector <vector <PhanSo> > A, vector <PhanSo> B, int Choose)
{
	switch (Choose)
	{
		case 1: CheoChinh(A, B); break;
		case 2: CheoPhu(A, B); break;
		case 3: TamGiacTren(A, B); break;
		case 4: TamGiacDuoi(A, B); break;
	}
}

void CheoChinh(vector <vector <PhanSo> > A, vector <PhanSo> B)
{
	wstring Title = L"Đường chéo chính ma trận " + to_wstring(A.size()) + L'x' + to_wstring(B.size()) + L':';
	int temp = PhanSo_double(PhanSo(B.size() * 6 - Title.size())) / 2 - 0.5;
	wcout << endl << setw(temp > 0 ? temp : 0) << "" << Title << endl;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
			if (i == j) wcout << A[i][j] << " ";
			else wcout << setw(5) << " ";
		wcout << endl << endl;
	}
}
void CheoPhu(vector <vector <PhanSo> > A, vector <PhanSo> B)
{
	wstring Title = L"Đường chéo phụ ma trận " + to_wstring(A.size()) + L'x' + to_wstring(B.size()) + L':';
	int temp = PhanSo_double(PhanSo(B.size() * 6 - Title.size())) / 2 - 0.5;
	wcout << endl << setw(temp > 0 ? temp : 0) << "" << Title << endl;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
			if (j == B.size() - 1 - i) wcout << A[i][j];
			else wcout << setw(5) << " ";
		wcout << endl << endl;
	}
}
void TamGiacTren(vector<vector<PhanSo>> A, vector<PhanSo> B)
{
	wstring Title = L"Tam giác trên ma trận " + to_wstring(A.size()) + L'x' + to_wstring(B.size()) + L':';
	int temp = PhanSo_double(PhanSo(B.size() * 6 - Title.size())) / 2 - 0.5;
	wcout << endl << setw(temp > 0 ? temp : 0) << "" << Title << endl;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
			if (i <= j) wcout << A[i][j];
			else wcout << setw(5) << " ";
		wcout << endl << endl;
	}
}
void TamGiacDuoi(vector<vector<PhanSo>> A, vector<PhanSo> B)
{
	wstring Title = L"Tam giác dưới ma trận " + to_wstring(A.size()) + L'x' + to_wstring(B.size()) + L':';
	int temp = PhanSo_double(PhanSo(B.size() * 6 - Title.size())) / 2 - 0.5;
	wcout << endl << setw(temp > 0 ? temp : 0) << "" << Title << endl;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
			if (j <= i) wcout << A[i][j];
			else wcout << setw(5) << " ";
		wcout << endl << endl;
	}
}