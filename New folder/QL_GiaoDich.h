#ifndef QL_GIAODICH_H
#define QL_GIAODICH_H

#include<iomanip>
#include"GD_Vang.h"
#include"GD_TienTe.h"

class QL_GiaoDich
{
private:
	GiaoDich** mDS;
	int mCnt;
public:
	QL_GiaoDich();
	QL_GiaoDich(const QL_GiaoDich& other);
	QL_GiaoDich(GiaoDich** ds, int cnt);
	QL_GiaoDich& operator=(const QL_GiaoDich& other);
	~QL_GiaoDich();

	void nhap();
	void xuat();
	void thanhtienTB();
	void themgd();
	void xoaMa();
	void them(GiaoDich* gd);
	void GDVangLonNhatMoiQuanHCM();
	void GDTienLonNhatTungLoai();
	void ghiTheoLoai();
	void docTheoLoai();

	void line();
	void equal();
	void xoaDS(int& cnt, GiaoDich**& ds);
	void sinhngaunhien();
	void ghids();
	void docds();
};

#endif // !QL_GIAODICH_H
