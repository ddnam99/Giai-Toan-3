#include "pch.h"

void PhanSo::operator=(PhanSo A)
{
	int a = A.Tu, b = A.Mau;
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	this->Tu = (A.Mau / a) < 0 ? (-A.Tu / a) : (A.Tu / a);
	this->Mau = (A.Mau / a) < 0 ? (-A.Mau / a) : (A.Mau / a);
}
void PhanSo::operator=(int a)
{
	this->Tu = a;
	this->Mau = 1;
}
void PhanSo::operator=(double a)
{
	if (a != (int)a)
		for (int i = 2;; i++)
			if (a*i == (int)(a*i))
			{
				this->Tu = a * i;
				this->Mau = i;
				break;
			}
	else
	{
		this->Tu = a;
		this->Mau = 1;
	}
}
PhanSo PhanSo::operator+(PhanSo A)
{
	return PhanSo(this->Tu*A.Mau + A.Tu*this->Mau, (this->Tu*A.Mau + this->Mau*A.Tu == 0) ? 1 : this->Mau*A.Mau);
}
PhanSo PhanSo::operator-(PhanSo A)
{
	return PhanSo(this->Tu*A.Mau - this->Mau*A.Tu, (this->Tu*A.Mau - this->Mau*A.Tu == 0) ? 1 : this->Mau*A.Mau);
}
PhanSo PhanSo::operator*(PhanSo A)
{
	return PhanSo(this->Tu*A.Tu, (this->Tu*A.Tu == 0) ? 1 : (this->Mau*A.Mau));
}
PhanSo PhanSo::operator/(PhanSo A)
{
	return PhanSo(this->Tu*A.Mau, (this->Tu*A.Mau == 0) ? 1 : (this->Mau*A.Tu));
}
PhanSo PhanSo::operator+(int a)
{
	return PhanSo(this->Tu, this->Mau) + PhanSo(a);
}
PhanSo PhanSo::operator-(int a)
{
	return PhanSo(this->Tu, this->Mau) - PhanSo(a);
}
PhanSo PhanSo::operator*(int a)
{
	return PhanSo(this->Tu, this->Mau) * PhanSo(a);
}
PhanSo PhanSo::operator/(int a)
{
	return PhanSo(this->Tu, this->Mau) / PhanSo(a);
}
bool PhanSo::operator!=(PhanSo A)
{
	if (this->Tu != A.Tu or this->Mau != A.Mau) return true;
	return false;
}
bool PhanSo::operator==(PhanSo A)
{
	if (this->Tu == A.Tu and this->Mau == A.Mau) return true;
	return false;
}
bool PhanSo::operator<(PhanSo A)
{
	if ((double)this->Tu / this->Mau < (double)A.Tu / A.Mau) return true;
	return false;
}
bool PhanSo::operator>(PhanSo A)
{
	if ((double)this->Tu / this->Mau > (double)A.Tu / A.Mau) return true;
	return false;
}
bool PhanSo::operator>=(PhanSo A)
{
	if ((double)this->Tu / this->Mau >= (double)A.Tu / A.Mau) return true;
	return false;
}
bool PhanSo::operator<=(PhanSo A)
{
	if ((double)this->Tu / this->Mau <= (double)A.Tu / A.Mau) return true;
	return false;
}
bool PhanSo::operator!=(int a)
{
	if ((double)this->Tu / this->Mau != a) return true;
	return false;
}
bool PhanSo::operator==(int a)
{
	if ((double)this->Tu / this->Mau == a) return true;
	return false;
}
bool PhanSo::operator<(int a)
{
	if ((double)this->Tu / this->Mau < a) return true;
	else return false;
}
bool PhanSo::operator>(int a)
{
	if ((double)this->Tu / this->Mau > a) return true;
	return false;
}
bool PhanSo::operator>=(int a)
{
	if ((double)this->Tu / this->Mau >= a) return true;
	return false;
}
bool PhanSo::operator<=(int a)
{
	if ((double)this->Tu / this->Mau <= a) return true;
	return false;
}
PhanSo operator+(int a, PhanSo A)
{
	return PhanSo(a) + A;
}
PhanSo operator-(int a, PhanSo A)
{
	return PhanSo(a) - A;
}
PhanSo operator*(int a, PhanSo A)
{
	return PhanSo(a)*A;
}
PhanSo operator/(int a, PhanSo A)
{
	return PhanSo(a) / A;
}
void operator+=(PhanSo & A, PhanSo B)
{
	A = A + B;
}
void operator-=(PhanSo & A, PhanSo B)
{
	A = A - B;
}
void operator*=(PhanSo & A, PhanSo B)
{
	A = A * B;
}
void operator/=(PhanSo & A, PhanSo B)
{
	A = A / B;
}
void operator+=(PhanSo & A, int a)
{
	A += PhanSo(a);
}
void operator-=(PhanSo & A, int a)
{
	A -= PhanSo(a);
}
void operator*=(PhanSo & A, int a)
{
	A *= PhanSo(a);
}
void operator/=(PhanSo & A, int a)
{
	A /= PhanSo(a);
}
wistream & operator>>(wistream & input, PhanSo & A)
{
	input >> A.Tu;
	return input;
}
wostream & operator<<(wostream & output, PhanSo A)
{
	if (A.Mau == 1) output << setw(5) << A.Tu;
	else output << setw(2) << right << A.Tu << "/" << setw(2) << left << A.Mau;
	return output;
}