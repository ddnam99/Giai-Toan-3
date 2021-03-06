#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
using namespace std;

class PhanSo
{
	public:
		PhanSo() :Tu(0), Mau(1) {}
		PhanSo(int a, int b = 1) :Tu(a), Mau(b) {}
		void operator =(PhanSo A);
		void operator =(int a);
		void operator =(double a);
		PhanSo operator +(PhanSo A);
		PhanSo operator -(PhanSo A);
		PhanSo operator *(PhanSo A);
		PhanSo operator /(PhanSo A);
		PhanSo operator +(int a);
		PhanSo operator -(int a);
		PhanSo operator *(int a);
		PhanSo operator /(int a);
		friend PhanSo operator +(int a, PhanSo A);
		friend PhanSo operator -(int a, PhanSo A);
		friend PhanSo operator *(int a, PhanSo A);
		friend PhanSo operator /(int a, PhanSo A);
		friend void operator +=(PhanSo &A, PhanSo B);
		friend void operator -=(PhanSo &A, PhanSo B);
		friend void operator *=(PhanSo &A, PhanSo B);
		friend void operator /=(PhanSo &A, PhanSo B);
		friend void operator +=(PhanSo &A, int a);
		friend void operator -=(PhanSo &A, int a);
		friend void operator *=(PhanSo &A, int a);
		friend void operator /=(PhanSo &A, int a);
		bool operator !=(PhanSo A);
		bool operator ==(PhanSo A);
		bool operator <(PhanSo A);
		bool operator >(PhanSo A);
		bool operator >=(PhanSo A);
		bool operator <=(PhanSo A);
		bool operator !=(int a);
		bool operator ==(int a);
		bool operator <(int a);
		bool operator >(int a);
		bool operator >=(int a);
		bool operator <=(int a);
		friend PhanSo operator -(PhanSo A) { return 0 - A; }
		friend wistream& operator >>(wistream &input, PhanSo &A);
		friend wostream& operator <<(wostream &output, PhanSo A);
		bool TestMau(PhanSo A); //Kiểm tra mẫu khác 1
		PhanSo BCNN(PhanSo &A, PhanSo B); //Cái này chỉ là không biết đặt tên là gì nên đặt là BCNN thôi, chứ làm éo gì có BCNN của phân số :)))
		friend PhanSo ToiGian(PhanSo A); //Tối giản phân số
		friend double PhanSo_double(PhanSo A) { return (double)A.Tu / A.Mau; }
		void inputManual(vector <vector <PhanSo> > &A, vector <PhanSo> &B); //Nhập dữ liệu thủ công
		void inputAuto(vector <vector <PhanSo> > &A, vector <PhanSo> &B); // Nhập dữ liệu tự động
		void Draw(vector <vector <PhanSo> > A, vector <PhanSo> B, int Choose); //Lựa chọn 2: Vẽ ma trận
		void Math(vector <vector <PhanSo> > &A, vector <PhanSo> &B, vector <vector <PhanSo> > D, vector <PhanSo> C, int Choose); //Lựa chọn 3: Tính toán
		friend void GiaiPhuongTrinh(vector <vector <PhanSo> > A, vector <PhanSo> B); //Giải hệ phương trình
		void output(vector <vector <PhanSo> > A, vector <PhanSo> B);
		friend void output_gpt(vector <vector <PhanSo> > _Temp, vector <PhanSo> _Temp1);
		friend void output_gpt(vector <vector <PhanSo> > _Temp, vector <PhanSo> _Temp1, vector <int> VT);
		~PhanSo() {}
	private:
		int Tu;
		int Mau;
};

bool inputChoose(wstring TempX, int &Choose); //Để kiểu nguyên khi bấm nhầm kí tự nó sẽ bị lỗi nên làm thành hàm chuyển string sang int luôn nà :v
bool inputData(wstring TempX, PhanSo &A); //Chuyển phân số, số thực, nguyên, vô hạn tuần hoàn về phân số
void CheoChinh(vector <vector <PhanSo> > A, vector <PhanSo> B); //Vẽ đường chéo chính
void CheoPhu(vector <vector <PhanSo> > A, vector <PhanSo> B); //Vê đường chéo phụ
void TamGiacTren(vector <vector <PhanSo> > A, vector <PhanSo> B); //Vẽ tam giác trên
void TamGiacDuoi(vector <vector <PhanSo> > A, vector <PhanSo> B); //Vẽ tâm giác dưới
void Cong(vector <vector <PhanSo> > &A, vector <PhanSo> &B, vector <vector <PhanSo> > D, vector <PhanSo> C); //Cộng 2 ma trận
void Tru(vector <vector <PhanSo> > &A, vector <PhanSo> &B, vector <vector <PhanSo> > D, vector <PhanSo> C); //Trừ 2 ma trận
void Nhan(vector <vector <PhanSo> > &A, vector <PhanSo> &B, vector <vector <PhanSo> > D, vector <PhanSo> C); //Nhân 2 ma trận
void Chia(vector <vector <PhanSo> > &A, vector <PhanSo> &B, vector <vector <PhanSo> > D, vector <PhanSo> C); //Chia 2 ma trận
void ChuyenVi(vector <vector <PhanSo> > &A, vector <PhanSo> &B);
void Gauss(vector <vector <PhanSo> > &A, vector <PhanSo> &B, PhanSo Det = 1); //Khử Gauss
void SwapRow(vector <vector <PhanSo> > &A, vector <PhanSo> &B, bool &While); //Đổi hàng để khử Gauss, trả về kết quả quá trình đổi
void SwapRow(vector <vector <PhanSo> > &A, vector <PhanSo> &B,int io=0); //Đổi hàng đểtính rank, giải hệ phương trình
void Hadamas(vector <vector <PhanSo> > &A, vector <PhanSo> &B, vector <vector <PhanSo> > D, vector <PhanSo> C); //Nhân 2 ma trận theo phương pháp Hadamas
void TichVoHuong(vector <vector <PhanSo> > A, vector <PhanSo> B, vector <vector <PhanSo> > D, vector <PhanSo> C); //Tích vô hướng của 2 ma trận
void Rank(vector <vector <PhanSo> > A, vector <PhanSo> B, int &rank,int io=0); //Tìm rank của ma trận
void Erase(vector <vector <PhanSo> > &A, vector <PhanSo> &B); //Xóa các hàng bằng 0 hoặc trùng nhau

#endif