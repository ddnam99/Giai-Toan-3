#include "pch.h"

/*

				Bài code chưa được tối ưu nên nhiều chỗ viết gà lắm :v
						Class và hàm ở trong pch.h nhé :)))

																						*/

int main() 
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleTitleW(L"Toán 3 </> Copyright by Double D");
	HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX consoleFont;
	consoleFont.cbSize = sizeof(consoleFont);
	GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
	memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
	SetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);

	int Choose, _tempX, tempTitle;
	wstring Title; PhanSo Admin;
	vector <PhanSo> Temp;
	vector <vector <PhanSo> > Data(0, Temp);

	while (1)
	{
		wcout << L"\tMenu:\n"
			<< L"1. Nhập ma trận\n"
			<< L"2. Vẽ (Ma trận vuông)\n"
			<< L"3. Tính toán(Beta)\n"
			<< L"4. Hiển thị ma trận\n"
			<< L"5. Xóa màn hình\n"
			<< L"6. Reset ma trận\n"
			<< L"7. Other\n"
			<< L"0. Thoát\n";
		while (1)
		{
			wstring TempChoose;
			wcout << L"\nLựa chọn: ";
			getline(wcin, TempChoose);
			if (inputChoose(TempChoose, Choose))
				if (Choose >= 0 and Choose <= 7) break;
				else wcout << L"\n\t\tError: Chỉ được chọn từ 0 -> 7 ! ! !\n";
			wcout << "\t---------------------------------------------------\n";
		}
		switch (Choose)
		{
			case 0: 
				system("cls");
				wcout << "\n\t\t\twhile (alive) {\n\t\t\t\teat();\n\t\t\t\t//sleep();\n\t\t\t\tcode();\n\t\t\t     }\n"
					<< L"\n\t\tToán 3 </> Copyright by Double D\n"
					<< "\t------------------------------------------------\n";
				exit(0);
			case 1:
				if (Data.size() == 0)
				{
				inputData:;
					wcout << L"\nNhập phần tử cho ma trận: \n"
						<< L"1. Nhập thủ công\n"
						<< L"2. Nhập tự động\n";
					while (1)
					{
						wstring TempChoose;
						wcout << L"\nLựa chọn: ";
						getline(wcin, TempChoose);
						if (inputChoose(TempChoose, _tempX))
							if (_tempX > 0 and _tempX < 3) break;
							else wcout << L"\n\t\tError: Chỉ được chọn từ 1 hoặc 2 ! ! !\n";
						wcout << "\t----------------------------------------------------\n";
					}
					int col, row;
					wcout << L"Nhập kích thước ma trận: \n";
					while (1)
					{
						wstring TempChoose;
						wcout << L"Số hàng: ";
						getline(wcin, TempChoose);
						if (inputChoose(TempChoose, row))
							if (row <= 0)
							{
								wcout << L"\n\t\tError: Số hàng phải > 0 ! ! !\n"
									<< "\t---------------------------------------------\n\n";
								continue;
							}
							else;
						else
						{
							wcout << "\t---------------------------------------------\n\n";
							continue;
						}
					inputCol:;
						wcout << L"Số cột: ";
						getline(wcin, TempChoose);
						if (inputChoose(TempChoose, col))
							if (col <= 0)
							{
								wcout << L"\n\t\tError: Số cột phải > 0 ! ! !\n"
									<< "\t---------------------------------------------\n\n";
								goto inputCol;
							}
							else break;
						else
						{
							wcout << "\t---------------------------------------------\n\n";
							goto inputCol;
						}
					}
					Temp.resize(col);
					Data.resize(row, Temp);
					if (_tempX == 1) Admin.inputManual(Data, Temp);
					else Admin.inputAuto(Data, Temp);
					wcout << L"\n\t\tĐã nhập thành công ma trận " << row << "x" << col << " ! ! !\n";
					if (Choose == 20) /*Lựa chọn trong phần 3 (Tính Toán) mục "Reset & nhập lại ma trận"*/
					{
						wcout << "\t----------------------------------------------------\n";
						goto Math;
					}
					Choose = 1;
				}
				else wcout << L"\n\t    Đề nghị reset ma trận trước khi nhập mới ! ! !\n"; break;
			case 2: 
				if (Data.size() == 0) wcout << L"\n\t\tError: Không có dữ liệu ma trận ! ! !\n";
				else
					if (Data.size() == Temp.size())
					{
						while (1)
						{
							wcout << L"\n\tVẽ:\n"
								<< L"1. Đường chéo chính\n"
								<< L"2. Đường chéo phụ\n"
								<< L"3. Tam giác trên\n"
								<< L"4. Tam giác dưới\n"
								<< "0. Thoát\n";
							while (1)
							{
								wstring TempChoose;
								wcout << L"\nLựa chọn: ";
								getline(wcin, TempChoose);
								if (inputChoose(TempChoose, Choose))
									if (Choose >= 0 and Choose < 5) break;
									else wcout << L"\n\t\tError: Chỉ được chọn từ 0 -> 4 ! ! !\n";
								wcout << "\t----------------------------------------------------\n";
							}
							if (Choose == 0) break;
							else Admin.Draw(Data, Temp, Choose);
						}
						Choose = 2;
					}
					else wcout << L"\n\t      Error: Chỉ áp dụng với ma trận vuông ! ! !\n"; break;
			case 3: 
				if (Data.size() == 0) wcout << L"\n\t\tError: Không có dữ liệu ma trận ! ! !\n";
				else
				{
					while (1)
					{
					Math:;
						wcout << endl << setw(35) << right << L"\tTính Toán:\n"
							<< setw(35) << left << L"1. Cộng 2 ma trận"
							<< L"11. Tính trực giao(Beta)\n"
							<< setw(35) << L"2. Trừ 2 ma trận"
							<< L"12. Tích vô hướng(2 ma trận cùng cỡ)\n"
							<< setw(35) << L"3. Nhân 2 ma trận"
							<< L"13. Phép chiếu(Beta)\n"
							<< setw(35) << L"4. Chia 2 ma trận(Beta)"
							<< L"14. Vector riêng, giá trị riêng(Beta)\n"
							<< setw(35) << L"5. Chuyển vị"
							<< L"15. Biến đổi tuyến tính(Beta)\n"
							<< setw(35) << L"6. Khử Gauss(Ma trận vuông)"
							<< L"16. Giả nghịch đảo(Beta)\n"
							<< setw(35) << L"7. Nhân Hadamas(2 Ma trận cùng cỡ)"
							<< L"17. Hệ trực chuẩn(Beta)\n"
							<< setw(35) << L"8. Phần phụ đại số(Beta)"
							<< L"18. Hiển thị ma trận\n"
							<< setw(35) << L"9. Rank"
							<< L"19. Xóa màn hình\n"
							<< setw(35) << L"10. Giải hệ phương trình"
							<< L"20. Reset & nhập lại ma trận\n"
							<< setw(35) << " " << L"0. Thoát\n";
						while (1)
						{
							wstring TempChoose;
							wcout << L"\nLựa chọn: ";
							getline(wcin, TempChoose);
							if (inputChoose(TempChoose, Choose))
								if (Choose >= 0 and Choose < 21) break;
								else wcout << L"\n\t\tError: Chỉ được chọn từ 0 -> 20 ! ! !\n";
							wcout << "\t----------------------------------------------------\n";
						}
						if (Choose >= 13 and Choose <= 17 or Choose == 8 or Choose == 11)
						{
							wcout << "\n\t\t\twhile (alive) {\n\t\t\t\teat();\n\t\t\t\t//sleep();\n\t\t\t\tcode();\n\t\t\t     }\n"
								<< L"\n\t\tPhần này mình quên mất kiến thức rồi :v\n"
								<< "\t-------------------------------------------------------\n";
							continue;
						}
						if (Choose == 0) break;
						if (Choose == 18)
						{
							Title.clear();
							Title = L"Ma trận " + to_wstring(Data.size()) + L'x' + to_wstring(Temp.size()) + L':';
							tempTitle = PhanSo_double(PhanSo(Temp.size() * 6 - Title.size())) / 2 - 0.5;
							wcout << endl << setw(tempTitle >= 0 ? tempTitle : 0) << "" << Title << endl;
							Admin.output(Data, Temp);
						}
						else
							if (Choose > 0 and Choose <= 7 or Choose == 12 or Choose == 10 or Choose == 9)
							{
								if (Choose == 6)
									if (Data.size() != Temp.size())
									{
										wcout << L"\n\t      Error: Chỉ áp dụng với ma trận vuông ! ! !\n";
										goto Math;
									}
								vector <PhanSo> _Temp1;
								vector <vector <PhanSo> > _Temp(0, _Temp1);
								_Temp.clear();
								if (Choose >= 1 and Choose <= 4 or Choose == 7 or Choose == 12)
								{
									if (Choose == 1 or Choose == 2 or Choose == 7 or Choose == 12)
									{
										_Temp1.resize(Temp.size());
										_Temp.resize(Data.size(), _Temp1);
									}
									if (Choose == 3 or Choose == 4)
									{
										while (1)
										{
											wstring TempChoose;
											wcout << L"Nhập kích thước ma trận: " << Temp.size() << "x";
											getline(wcin, TempChoose);
											if (inputChoose(TempChoose, _tempX))
												if (_tempX <= 0)
												{
													wcout << L"\n\t\tError: Số cột phải > 0 ! ! !\n"
														<< "\t---------------------------------------------\n\n";
												}
												else break;
										}
										_Temp1.resize(_tempX);
										_Temp.resize(Temp.size(), _Temp1);
									}
									wcout << L"\nNhập phần tử cho ma trận thứ 2: \n"
										<< L"1. Nhập thủ công\n"
										<< L"2.Nhập tự động\n";
									while (1)
									{
										wstring TempChoose;
										wcout << L"\nLựa chọn: ";
										getline(wcin, TempChoose);
										if (inputChoose(TempChoose, _tempX))
											if (_tempX > 0 and _tempX < 3) break;
											else wcout << L"\n\t\tError: Chỉ được chọn từ 1 hoặc 2 ! ! !\n";
										wcout << "\t----------------------------------------------------\n";
									}
									if (_tempX == 1) Admin.inputManual(_Temp, _Temp1);
									else Admin.inputAuto(_Temp, _Temp1);
									Title.clear();
									Title = L"Ma trận gốc " + to_wstring(Data.size()) + L'x' + to_wstring(Temp.size()) + L':';
									tempTitle = PhanSo_double(PhanSo(Temp.size() * 6 - Title.size())) / 2 - 0.5;
									wcout << endl << setw(tempTitle >= 0 ? tempTitle : 0) << "" << Title << endl;
									Admin.output(Data, Temp);
									wcout << "\t----------------------------------------------------\n";
									Title.clear();
									Title = L"Ma trận thứ 2 " + to_wstring(_Temp.size()) + L'x' + to_wstring(_Temp1.size()) + L':';
									wcout << endl << setw(tempTitle >= 0 ? tempTitle : 0) << "" << Title << endl;
									Admin.output(_Temp, _Temp1);
								}
								Admin.Math(Data, Temp, _Temp, _Temp1, Choose);
								if (Choose != 12 and Choose != 9 and Choose != 10)
								{
									wcout << "\t----------------------------------------------------\n";
									Title.clear();
									Title = L"Kết quả:";
									tempTitle = PhanSo_double(PhanSo(Temp.size() * 6 - Title.size())) / 2 - 0.5;
									wcout << endl << setw(tempTitle >= 0 ? tempTitle : 0) << "" << Title << endl;
									Admin.output(Data, Temp);
								}
								if (Choose == 5) wcout << L"\n\t\tĐã chuyển vị thành công ma trận ! ! !\n";
								if (Choose == 9)
								{
									int rank;
									Rank(Data, Temp, rank,1);
									wcout << "=> Rank= " << rank << endl;
								}
							}
						if (Choose == 19) system("cls");
						if (Choose == 20)
						{
							Temp.clear();
							Data.clear();
							wcout << L"\n\t\t   Đã reset ma trận thành công ! ! !\n"
								<< L"\t-----------------------------------------------------\n\n";
							goto inputData;
						}
						wcout << "\t----------------------------------------------------\n";
					}
					Choose = 3;
				} break;
			case 4: 
				if (Data.size() == 0) wcout << L"\n\t\tError: Không có dữ liệu ma trận ! ! !\n";
				else
				{
					Title.clear();
					Title = L"Ma trận " + to_wstring(Data.size()) + L'x' + to_wstring(Temp.size()) + L':';
					tempTitle = PhanSo_double(PhanSo(Temp.size() * 6 - Title.size())) / 2 - 0.5;
					wcout << endl << setw(tempTitle >= 0 ? tempTitle : 0) << "" << Title << endl;
					Admin.output(Data, Temp);
				} break;
			case 5: system("cls"); break;
			case 6:
				Temp.clear();
				Data.clear();
				wcout << L"\n\t\t   Đã reset ma trận thành công ! ! !\n"; break;
			case 7:
				system("cls");
				wcout << "\n\t -------------------------------------------------------------------------------\n"
					<< L"\t|\tNếu có thắc mắc/hoặc đơn giản là bug hãy nhắn tin cho tôi;)\t\t|\n"
					<< L"\t| Dương Đức Nam (facebook.com/nampt1999) | #It's not a bug, it's a feature :))) |\n"
					<< "\t -------------------------------------------------------------------------------\n\n\n";
				Sleep(1000); system("pause"); system("start https://facebook.com/nampt1999"); system("cls");
				continue;
		}
		wcout << L"\t-----------------------------------------------------\n\n";
	}
	return 0;
}