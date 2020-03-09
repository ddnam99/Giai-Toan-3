#include "pch.h"

void PhanSo::inputManual(vector <vector <PhanSo> > & A, vector <PhanSo> & B)
{
	wstring TempX;
	wcout << L"Nhập dữ liệu: \n";
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++)
			while (1)
			{
				wcout << "Data[" << i + 1 << "][" << j + 1 << "]= ";
				getline(wcin, TempX);
				if (inputData(TempX, A[i][j])) break;
			}
}
void PhanSo::inputAuto(vector <vector <PhanSo> > & A, vector <PhanSo> & B)
{
	srand(time(NULL));
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++)
			if (rand() % 50 % 2 == 0) A[i][j] = rand() % 10;
			else A[i][j] = -rand() % 10;
}
void PhanSo::output(vector <vector <PhanSo> > A, vector <PhanSo> B)
{
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++) wcout << right << A[i][j] << " ";
		wcout << endl << endl;
	}
}
void output_gpt(vector <vector <PhanSo> > _Temp, vector <PhanSo> _Temp1)
{
	for (int i = 0; i < _Temp.size(); i++)
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
					if (j == _Temp1.size() - 2) wcout << " = " << left << _Temp[i][_Temp1.size() - 1];
				}
		wcout << endl;
	}
	wcout << endl;
}
void output_gpt(vector <vector <PhanSo> > _Temp, vector <PhanSo> _Temp1, vector <int> VT)
{
	for (int i = 0; i < _Temp.size(); i++)
	{
		for (int j = 0; j < _Temp1.size() - 1; j++)
		{
			bool Test = false;
			for (int k = 0; k < VT.size(); k++)
				if (j == VT[k])
				{
					Test = true;
					break;
				}
			if (Test)
				if (j == 0)
					if (_Temp[i][j].Tu != 0)
						if (_Temp[i][j].Mau != 1) wcout << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << "/" << left << setw(5) << _Temp[i][j].Mau;
						else wcout << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << setw(6) << " ";
					else wcout << right << setw(5) << 0 << setw(8) << " ";
				else
					if(j!=VT[i])
						if (_Temp[i][j] < 0)
							if (_Temp[i][j].Tu != 0)
								if (_Temp[i][j].Mau != 1) wcout << " + " << right << setw(5) << -_Temp[i][j].Tu << "X" << j + 1 << "/" << left << setw(5) << _Temp[i][j].Mau;
								else wcout << " + " << right << setw(5) << -_Temp[i][j].Tu << "X" << j + 1 << setw(6) << " ";
							else wcout << " + " << right << setw(5) << 0 << setw(8) << " ";
						else
							if (_Temp[i][j].Tu != 0)
								if (_Temp[i][j].Mau != 1) wcout << " - " << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << "/" << left << setw(5) << _Temp[i][j].Mau;
								else wcout << " - " << right << setw(5) << _Temp[i][j].Tu << "X" << j + 1 << setw(6) << " ";
							else wcout << " + " << right << setw(5) << 0 << setw(8) << " ";
					else
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
		}
		if (_Temp[i][_Temp1.size() - 1] != 0)
			if (_Temp[i][_Temp1.size() - 1].Mau != 1) wcout << "=" << right << setw(5) << _Temp[i][_Temp1.size() - 1].Tu << "/" << left << setw(5) << _Temp[i][_Temp1.size() - 1].Mau;
			else wcout << "=" << right << setw(5) << _Temp[i][_Temp1.size() - 1].Tu << setw(6) << " ";
		else wcout << "=";
		for (int j = 0; j < _Temp1.size() - 1; j++)
		{
			bool Test = true;
			for (int k = 0; k < VT.size(); k++)
				if (j == VT[k])
				{
					Test = false;
					break;
				}
			if (Test)
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
		}
		wcout << endl;
	}
}
bool inputChoose(wstring TempX, int & Choose)
{
	bool Test = true;
	bool Am = false;
	vector <int> VT;
	setlocale(LC_CTYPE, "");
	string Temp(TempX.begin(), TempX.end());
	for (int i = 0; i < Temp.size(); i++)
		if (Temp[i] == ' ') Temp.erase(i, 1);
	if (Temp[0] == '-')
	{
		Am = true;
		Temp.erase(0, 1);
	}
	for (int i = 0; i < Temp.size(); i++)
		if (Temp[i]<'0' or Temp[i]>'9')
		{
			Test = false;
			VT.resize(VT.size() + 1);
			if (Am) VT[VT.size() - 1] = i + 2;
			else VT[VT.size() - 1] = i + 1;
		}
	if (Test)
		if (Am) Choose = -atoi(Temp.c_str());
		else Choose = atoi(Temp.c_str());
	else
		if (Temp.size() > 1)
		{
			wcout << L"\n\t\tError: Kí tự ";
			for (int i = 0; i < VT.size(); i++)
				if (i < VT.size() - 1) wcout << VT[i] << ", ";
				else wcout << VT[i] << " ";
			wcout << L"không hợp lệ !!!\n";
		}
		else wcout << L"\n\t\tError: Kí tự không hợp lệ !!!\n";
	return Test;
}
bool inputData(wstring TempX, PhanSo & A)
{
	setlocale(LC_CTYPE, "");
	string Temp(TempX.begin(), TempX.end());
	bool Test = true;
	bool Am = false;
	bool ps = false, thuc = false, nguyen = true, ck = false;
	bool test1 = false, test2 = false;
	for (int i = 0; i < Temp.size(); i++)
		if (Temp[i] == ' ') Temp.erase(i, 1);
	if (Temp[0] == '-')
	{
		Am = true;
		Temp.erase(0, 1);
	}
	if (Temp[Temp.size() - 1] == ')') //Kiểm tra dữ liệu đầu vào là kiểu phân số, thực, nguyên,....
	{
		nguyen = false;
		for (int i = 0; i < Temp.size() - 1; i++)
			if (Temp[i] <'0' or Temp[i]>'9')
				if (Temp[i] == '.' or Temp[i] == '(' or Temp[i] == ')')
				{
					if (Temp[i] == ')') goto Break0;
					if (Temp[i] == '.')
						if (Temp[i + 1] == '(' or Temp[i + 1] >= '0' and Temp[i + 1] <= '9')
							if (Temp[i - 1] >= '0' and Temp[i - 1] <= '9')
								if (test1 == false and test2 == false)
									if (Temp[i + 1] == '(') test1 = true;
									else test2 = true;
								else goto Break0;
					if (Temp[i] == '(')
						if (Temp[i - 1] == '.' or Temp[i - 1] >= '0' and Temp[i - 1] <= '9')
							if (Temp[i + 1] >= '0' and Temp[i] <= '9')
								if (test1 == true and test2 == false and ck == false or test1 == false and test2 == true and ck == false)
									ck = true;
								else goto Break0;
				}
				else
				{
				Break0:;
					Test = false;
					break;
				}
	}
	else
		for (int i = 0; i < Temp.size(); i++)
			if (Temp[i]<'0' or Temp[i]>'9')
			{
				nguyen = false;
				if (Temp[i] == '.' or Temp[i] == '/' or Temp[i] == '-')
				{
					if (Temp[i] == '/' and Temp[i - 1] >= '0' and Temp[i - 1] <= '9' and i < Temp.size() - 1 and (Temp[i + 1] == '-' or Temp[i + 1] >= '0' and Temp[i + 1] <= '9'))
						if (ps == false and thuc == false) ps = true;
						else goto Break;
					if (Temp[i] == '-' and i < Temp.size() - 1 and Temp[i + 1] >= '0' and Temp[i + 1] <= '9')
						if (Temp[i - 1] == '/')
						{
							if (Am) Am = false;
							else Am = true;
							Temp.erase(i, 1);
						}
						else goto Break;
					if (Temp[i] == '.' and Temp[i - 1] >= '0' and Temp[i - 1] <= '9' and i < Temp.size() - 1 and Temp[i + 1] >= '0' and Temp[i + 1] <= '9')
						if (ps == false and thuc == false) thuc = true;
						else goto Break;
				}
				else
				{
				Break:;
					Test = false;
					break;
				}
			}
	if (Test) //chuyển dữ liệu đầu vào sang phân số
	{
		if (nguyen)
			if (Am) A = -atoi(Temp.c_str());
			else A = atoi(Temp.c_str());
		if (ps)
		{
			int a, b;
			if (Am) a = -atoi(Temp.c_str());
			else a = atoi(Temp.c_str());
			for (int i = 0; i < Temp.size(); i++)
				if (Temp[i] == '/')
				{
					Temp.erase(0, i + 1);
					break;
				}
			b = atoi(Temp.c_str());
			A = ToiGian(PhanSo(a, b));
		}
		if (thuc)
		{
			double a = atoi(Temp.c_str());
			for (int i = 0; i < Temp.size(); i++)
				if (Temp[i] == '.')
				{
					Temp.erase(0, i + 1);
					break;
				}
			a += (double)atoi(Temp.c_str()) / pow(10, Temp.size());
			for (int k = 1;; k++)
				if ((double)(k*a) == (int)(k*a))
				{
					if (Am) A = PhanSo(-k * a, k);
					else A = PhanSo(k * a, k);
					break;
				}
		}
		if (ck)
		{
			int a = atoi(Temp.c_str()), b = 0;
			for (int i = 0; i < Temp.size(); i++)
				if (Temp[i] == '.')
				{
					if (test1)
					{
						Temp.erase(0, i + 2);
						Temp.erase(Temp.size() - 1, 1);
						for (int j = 0; j < Temp.size(); j++) b += 9 * pow(10, j);
						A = PhanSo(atoi(Temp.c_str()), b) + a;
						if (Am) A = -A;
						break;
					}
					if (test2)
					{
						Temp.erase(0, i + 1);
						string Temp1;
						for (int j = 0; j < Temp.size(); j++)
							if (Temp[j] != '(') Temp1.push_back(Temp[j]);
							else
							{
								Temp.erase(0, j + 1);
								break;
							}
						Temp.erase(Temp.size() - 1, 1);
						b = atoi(Temp1.c_str());
						int c = 0;
						for (int j = 0; j < Temp.size(); j++) c += 9 * pow(10, j);
						c *= pow(10, Temp1.size());
						int count = 0;
						for (int j = 0; j < Temp.size(); j++)
							if (Temp[j] == 0) count += 1;
							else break;
						A = PhanSo(b*pow(10, Temp1.size() + count) + atoi(Temp.c_str()) - b, c) + a;
						if (Am) A = -A;
						break;
					}
				}
		}
	}
	else wcout << L"\n\t\tError: Dữ liệu không hợp lệ !!!\n\n";
	return Test;
}