#ifndef GIAODICH_H
#define GIAODICH_H

//#define _CRT_SECURE_NO_WARNINGS

#define maxchar 255

#include<iostream>
#include<cassert>
#include<cstring>
#include<fstream>

using namespace std;

struct diachi {
	int so;
	char* duong;
	char* phuong;
	char* quan;
	char* tp;
};

struct ngaygd {
	int d;
	int m;
	int y;
};

class GiaoDich
{
private:
	char* mMa;
	char* mHT;
	diachi mDC;
	ngaygd mNG;
	int mSL;
public:
	GiaoDich();
	GiaoDich(const GiaoDich& other);
	GiaoDich(char* ma, char* ht, diachi dc, ngaygd ng, int sl);
	~GiaoDich();
	GiaoDich& operator=(const GiaoDich& other);

	void setDC(diachi dc);
	void setDC(int so, const char* d, const char* p, const char* q, const char* tp);
	void setNG(ngaygd ng);
	void setNG(int d, int m, int y);
	void setMa(const char* ma);
	void setHT(const char* ht);
	void setSL(int sl);
	int getSL();
	char* getMa();
	char* getQuan();
	char* getTP();

	virtual void nhap();
	virtual void xuat();
	virtual float thanhtien() = 0;
	virtual GiaoDich* clone() const = 0;
	virtual int getLoai() const = 0;
	virtual void ghiObj(fstream& g);
	virtual void docObj(fstream& d);

	void xoaGD(GiaoDich& gd);
	void xoaDC(diachi& dc);
	void xoaNG(ngaygd& ng);
	//void inputDC(diachi& dc, int so, const char* d, const char* p, const char* q, const char* tp);
	//void outputDC(diachi& dc);
	void cleanInputStream();
};

#endif // !GIAODICH_H


