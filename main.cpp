#include"QL_GiaoDich.h"
#include<typeinfo>


void menu();
void test();

int main()
{
	test();
	cout<<"code nhu trau ma diem van thap!";
	cout<<"do ban code ngu qua do! co gi dau ma bat ngo";
	return 0;
}



void menu() {
	cout
		<< "\n-----------------------------------------------------------------------"
		<< "\n\t1.Nhap danh sach giao dich"
		<< "\n\t2.Xuat danh sach giao dich"
		<< "\n\t3.Ghi danh sach ra file dsgd.dat"
		<< "\n\t4.Doc danh sach tu file dsgd.dat"
		<< "\n\t5.Tinh trung binh thanh tien moi loai giao dich"
		<< "\n\t6.Them giao dich moi"
		<< "\n\t7.Xoa giao dich theo ma"
		<< "\n\t8.Tim giao dich vang co so tien lon nhat moi quan cua tp.HCM"
		<< "\n\t9.Tim giao dich tien te lon nhat cua tung loai tien"
		<< "\n\t10.Ghi danh sach giao dich theo loai"
		<< "\n\t11.Doc danh sach giao dich theo loai"
		<< "\n\t12.Tao danh sach giao dich ngau nhien"
		<< "\n\t0.Ket thuc"
		<< "\n-----------------------------------------------------------------------"
		<< "\nChon chuc nang...";
}

void test() {
	QL_GiaoDich ql;

	int c = -1;
	while (c != 0)
	{
		menu();
		cin >> c;
		switch (c)
		{
		case 1:
			ql.nhap();
			break;
		case 2:
			ql.xuat();
			break;
		case 3:
			ql.ghids();
			break;
		case 4:
			ql.docds();
			break;
		case 5:
			ql.thanhtienTB();
			break;
		case 6:
			ql.themgd();
			break;
		case 7:
			ql.xoaMa();
			break;
		case 8:
			ql.GDVangLonNhatMoiQuanHCM();
			break;
		case 9:
			ql.GDTienLonNhatTungLoai();
			break;
		case 10:
			ql.ghiTheoLoai();
			break;
		case 11:
			ql.docTheoLoai();
			break;
		case 12:
			ql.sinhngaunhien();
			break;
		case 0:
			cout << "Ket thuc!\nCam on!\n";
			break;
		default:
			cout << "Khong ton tai chuc nang da chon!\nNhap lai!\n";
			break;
		}
	}
}
