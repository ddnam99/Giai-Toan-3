#include "pch.h"

void PhanSo::Math(vector <vector <PhanSo> >& A, vector <PhanSo>& B, vector <vector <PhanSo> > D, vector <PhanSo> C, int Choose)
{
	switch (Choose)
	{
		case 1: Cong(A, B, D, C); break;
		case 2: Tru(A, B, D, C); break;
		case 3: Nhan(A, B, D, C); break;
		case 4: Chia(A, B, D, C); break;
		case 5: ChuyenVi(A, B); break;
		case 6: Gauss(A, B); break;
		case 7: Hadamas(A, B, D, C); break;
		case 10: GiaiPhuongTrinh(A, B); break;
		case 12: TichVoHuong(A, B, D, C); break;
	}
}

void Cong(vector <vector <PhanSo> >& A, vector <PhanSo>& B, vector <vector <PhanSo> > D, vector <PhanSo> C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++) A[i][j] += D[i][j];
	wcout << L"\n\t\tĐã cộng thành công 2 ma trận ! ! !\n";
}
void Tru(vector <vector <PhanSo> >& A, vector <PhanSo>& B, vector <vector <PhanSo> > D, vector <PhanSo> C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++) A[i][j] -= D[i][j];
	wcout << L"\n\t\tĐã trừ thành công 2 ma trận ! ! !\n";
}
void Nhan(vector <vector <PhanSo> > &A, vector <PhanSo> &B, vector <vector <PhanSo> > D, vector <PhanSo> C)
{
	vector <PhanSo> _Temp1(C.size(), 0);
	vector <vector <PhanSo> > _Temp(A.size(), _Temp1);
	for (int i = 0; i < _Temp.size(); i++)
		for (int j = 0; j < _Temp1.size(); j++)
			for (int k = 0; k < B.size(); k++)
				_Temp[i][j] += A[i][k] * D[k][j];
	A.clear();
	B.resize(_Temp1.size());
	A.resize(_Temp.size(), B);
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++) A[i][j] = _Temp[i][j];
}
void Chia(vector<vector<PhanSo>>& A, vector<PhanSo>& B, vector<vector<PhanSo>> D, vector<PhanSo> C)
{

}
void ChuyenVi(vector <vector <PhanSo> >& A, vector <PhanSo>& B)
{
	vector <PhanSo> C(A.size());
	vector <vector <PhanSo> > D(B.size(), C);
	for (int i = 0; i < D.size(); i++)
		for (int j = 0; j < C.size(); j++) D[i][j] = A[j][i];
	A.clear();
	B.resize(C.size());
	A.resize(D.size(), B);
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++) A[i][j] = D[i][j];
}
void Gauss(vector <vector <PhanSo> >& A, vector <PhanSo>& B, PhanSo Det)
{
	bool While = false;
	SwapRow(A, B, While);
	if (While);
	else
	{
		PhanSo temp;
		vector <PhanSo> _Temp1(B.size() * 2, 0);
		vector <vector <PhanSo> > _Temp(A.size(), _Temp1);
		for (int i = 0; i < _Temp.size(); i++)
			for (int j = 0; j < _Temp1.size() / 2; j++) _Temp[i][j] = A[i][j];
		for (int j = 0; j < _Temp1.size() / 2; j++)
			_Temp[j][j + _Temp1.size() / 2] = 1;
		wcout << L"Khử tam giác dưới:\n";
		for (int i = 0; i < _Temp.size() - 1; i++)
		{
			for (int j = i + 1; j < _Temp.size(); j++)
			{
				temp = 0;
				temp -= _Temp[j][i] / _Temp[i][i];
				for (int k = 0; k < _Temp1.size(); k++) _Temp[j][k] += temp * _Temp[i][k];
			}
			wcout << endl << L"Bước " << i + 1 << ":\n";
			Det.output(_Temp, _Temp1);
			SwapRow(_Temp, _Temp1, While);
			if (While) break;
		}
		if (While);
		else
		{
			wcout << L"Khử đường chéo chính:\n";
			for (int i = 0; i < _Temp.size(); i++)
			{
				//Det = Det.BCNN(Det, _Temp[i][i]);
				Det *= _Temp[i][i];
				for (int j = 0; j < _Temp1.size(); j++) _Temp[i][j] /= _Temp[i][i];
			}
			Det.output(_Temp, _Temp1);
			int count = 0;
			wcout << L"Khử tam giác trên:\n";
			for (int i = _Temp.size() - 1; i > 0; i--)
			{
				count += 1;
				for (int j = i - 1; j >= 0; j--)
				{
					temp = 0;
					temp -= _Temp[j][i] / _Temp[i][i];
					for (int k = 0; k < _Temp1.size(); k++) _Temp[j][k] += temp * _Temp[i][k];
				}
				wcout << endl << L"Bước " << count << ":\n";
				Det.output(_Temp, _Temp1);
			}
			for (int i = 0; i < A.size(); i++)
				for (int j = 0; j < B.size(); j++) A[i][j] = _Temp[i][j + _Temp1.size() / 2];
			wcout << L"Hệ số= " << Det << endl;
		}
	}
}
void Hadamas(vector <vector <PhanSo> >& A, vector <PhanSo>& B, vector <vector <PhanSo> > D, vector <PhanSo> C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++) A[i][j] *= D[i][j];
}
void TichVoHuong(vector <vector <PhanSo> > A, vector <PhanSo> B, vector <vector <PhanSo> > D, vector <PhanSo> C)
{
	PhanSo Sum(0);
	Hadamas(A, B, D, C);
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++) Sum += A[i][j];
	wcout << L"Tích vô hướng= " << Sum << endl;
}
void Rank(vector <vector <PhanSo> > A, vector <PhanSo> B, int & rank,int io)
{
	PhanSo temp;
	vector <int> count;
	int size = A.size() < B.size() ? A.size() - 1 : B.size();
	if (io != 1) SwapRow(A, B);
	else
	{
		wcout << endl;
		SwapRow(A, B, 1);
	}
	for (int i = 0; i < size; i++)
	{
		if (io == 1) wcout << L"\nBước " << i + 1 << ": \n";
		for (int j = i + 1; j < A.size(); j++)
		{
			temp = 0;
			temp -= A[j][i] / A[i][i];
			for (int k = 0; k < B.size(); k++) A[j][k] += temp * A[i][k];
		}
		
		if (io != 1) SwapRow(A, B);
		else
		{
			temp.output(A, B);
			SwapRow(A, B, 1);
		}
	}
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++)
			if (A[i][j] != 0)
				if (count.size() == 0)
				{
					count.resize(count.size() + 1);
					count[count.size() - 1] = j;
					break;
				}
				else
				{
					bool test = true;
					for (int k = 0; k < count.size(); k++)
						if (j == count[k])
						{
							test = false;
							break;
						}
					if (test)
					{
						count.resize(count.size() + 1);
						count[count.size() - 1] = j;
						break;
					}
				}
	rank = count.size();
}
void GiaiPhuongTrinh(vector <vector <PhanSo> > A, vector <PhanSo> B)
{
	PhanSo temp;
	vector <PhanSo> _Temp1(B.size() + 1, 0);
	vector <vector <PhanSo> > _Temp(A.size(), _Temp1);
	vector <PhanSo> KQ(B.size(), 0);
	for (int i = 0; i < _Temp.size(); i++)
		for (int j = 0; j < _Temp1.size() - 1; j++) _Temp[i][j] = A[i][j];
	wcout << L"Nhập vế phải:\n";
	for (int i = 0; i < _Temp.size(); i++)
	{
		wstring TempX;
		while (1)
		{
			for (int j = 0; j < _Temp1.size() - 1; j++)
				if (j == _Temp1.size() - 2 and j == 0)
					if (_Temp[i][j].Tu != 0)
						if (_Temp[i][j].Mau != 1) wcout << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << "/" << left << setw(5) << _Temp[i][j].Mau << " = " << left << _Temp[i][_Temp1.size() - 1];
						else wcout << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << setw(6) << " " << " = " << left << _Temp[i][_Temp1.size() - 1];
					else wcout << right << setw(5) << 0 << setw(8) << " ";
				else
					if (j == 0)
						if (_Temp[i][j].Tu != 0)
							if (_Temp[i][j].Mau != 1) wcout << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << "/" << left << setw(5) << _Temp[i][j].Mau;
							else wcout << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << setw(6) << " ";
						else wcout << right << setw(5) << 0 << setw(8) << " ";
					else
					{
						if (_Temp[i][j] >= 0)
							if (_Temp[i][j].Tu != 0)
								if (_Temp[i][j].Mau != 1) wcout << " + " << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << "/" << left << setw(5) << _Temp[i][j].Mau;
								else wcout << " + " << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << setw(6) << " ";
							else wcout << " + " << right << setw(5) << 0 << setw(8) << " ";
						else
							if (_Temp[i][j].Tu != 0)
								if (_Temp[i][j].Mau != 1) wcout << " - " << right << setw(5) << -_Temp[i][j].Tu << "X" << j + 1 << "/" << left << setw(5) << _Temp[i][j].Mau;
								else wcout << " - " << right << setw(5) << -_Temp[i][j].Tu << "X" << j + 1 << setw(6) << " ";
							else wcout << " + " << right << setw(5) << 0 << setw(8) << " ";
						if (j == _Temp1.size() - 2) wcout << " = ";
					}
			getline(wcin, TempX);
			if (inputData(TempX, _Temp[i][_Temp1.size() - 1])) break;
		}
	}
	int rank1, rank2;
	Rank(A, B, rank1);
	Rank(_Temp, _Temp1, rank2);
	int size = _Temp.size() < _Temp1.size() ? _Temp.size() : _Temp1.size();
	wcout << endl;
	SwapRow(_Temp, _Temp1,1);
	wcout << L"\nI, Tìm biến trụ, biến tự do\n\n";
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < _Temp.size(); j++)
		{
			temp = 0;
			temp -= _Temp[j][i] / _Temp[i][i];
			for (int k = 0; k < _Temp1.size(); k++) _Temp[j][k] += temp * _Temp[i][k];
		}
		wcout << L"Bước " << i + 1 << ":\n";
		output_gpt(_Temp, _Temp1);
		SwapRow(_Temp, _Temp1, 1);
	}
	if (rank1 < rank2) wcout << L"Rank(A) < Rank(A|b) \n=> Hệ vô nghiệm ! ! !\n";
	if (rank1 == rank2 and _Temp.size() == _Temp1.size() - 1)
	{
		wcout << L"Rank(A) == Rank(A|b) && 0 có biến tự do \n=> Hệ có nghiệm duy nhất ! ! !\n";
		for (int i = KQ.size() - 1; i >= 0; i--)
			for (int j = _Temp.size() - 1 - (KQ.size() - 1 - i); j >= 0;)
			{
				PhanSo TempX = 0;
				for (int k = KQ.size() - 1; k > i; k--) TempX += KQ[k] * _Temp[i][k];
				KQ[j] = (_Temp[i][_Temp1.size() - 1] - TempX) / _Temp[i][j];
				break;
			}
		wcout << L"\nNghiệm của hệ: \n";
		for (int i = 0; i < KQ.size(); i++)
			wcout << left << "X" << i + 1 << "= " << right << setw(6) << KQ[i].Tu << "/" << left << setw(6) << KQ[i].Mau << endl;
		wcout << right << endl;
	}
	if (rank1 == rank2 and rank1 < _Temp1.size() - 1)
	{
		vector <int> VT(_Temp.size());
		wcout << L"Rank(A) == Rank(A|b) && có " << _Temp1.size() - 1 - rank1 << L" biến tự do \n=> Hệ có vô số nghiệm ! ! !\n";
		for (int i = 0; i < _Temp.size(); i++)
		{
			bool test = true;
			for (int j = 0; j < _Temp1.size() - 1; j++)
				if (_Temp[i][j] != 0)
				{
					if (test)
						for (int k = 0; k < VT.size(); k++)
							if (VT[k] == j)
							{
								test = false;
								break;
							}
					if (test)
					{
						VT[i] = j;
						test = false;
					}
					if (j != VT[i]) _Temp[i][j] = -_Temp[i][j];
				}
		}
		wcout << L"\nII, Chuyển biến tự do sang vế phải\n";
		output_gpt(_Temp, _Temp1, VT);
		wcout << L"\n\nIII, Giải ngược\n";
		int count = 1;
		for (int i = _Temp.size() - 1; i >= 0; i--)
		{
			for (int j = _Temp1.size() - 1; j >= 0; j--) _Temp[i][j] /= _Temp[i][VT[i]];
			if (i != _Temp.size() - 1)
				for (int k = i + 1; k < VT.size(); k++)
				{
					for (int j = 0; j < _Temp1.size(); j++)
						if (j != VT[k]) _Temp[i][j] += _Temp[i][VT[k]] * _Temp[k][j];
					_Temp[i][VT[k]] = 0;
				}
			wcout << L"\nBước " << count++ << ": \n";
			output_gpt(_Temp, _Temp1, VT);
		}
		wcout << L"\nNghiệm của hệ:\n";
		for (int i = 0; i < _Temp.size(); i++)
		{
			wcout << "X" << VT[i] + 1 << "= " << right << setw(6) << _Temp[i][_Temp1.size() - 1].Tu << "/" << left << setw(6) << _Temp[i][_Temp1.size() - 1].Mau;
			for (int j = 0; j < _Temp1.size() - 1; j++)
				if (_Temp[i][j] != 0 and j != VT[i])
					if (_Temp[i][j] != 1 and _Temp[i][j] != -1)
						if (_Temp[i][j] < 0)
							if (_Temp[i][j] != 0)
								if (_Temp[i][j].Mau != 1) wcout << right << " - " << setw(5) << -_Temp[i][j].Tu << "X" << j + 1 << "/" << left << setw(5) << _Temp[i][j].Mau;
								else wcout << right << " - " << setw(5) << -_Temp[i][j].Tu << "X" << j + 1 << setw(6) << " ";
							else wcout << right << setw(5) << 0 << setw(8) << " ";
						else
							if (_Temp[i][j] != 0)
								if (_Temp[i][j].Mau != 1) wcout << right << " + " << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << "/" << left << setw(5) << _Temp[i][j].Mau;
								else wcout << right << " + " << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << setw(6) << " ";
							else wcout << right << setw(5) << 0 << setw(8) << " ";
					else
						if (_Temp[i][j] < 0) wcout << " - X" << j + 1;
						else wcout << " + X" << j + 1;
			wcout << endl;
		}
		for (int i = 0; i < _Temp1.size() - 1; i++)
		{
			bool test = true;
			for (int j = 0; j < VT.size(); j++)
				if (i == VT[j])
				{
					test = false;
					break;
				}
			if (test) wcout << "X" << i + 1 << L": Tùy ý\n";
		}
	}
}