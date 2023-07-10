#ifndef GD_VANG_H
#define GD_VANG_H

#include "GiaoDich.h"
class GD_Vang :
	public GiaoDich
{
private:
	float mDG;
public:
	GD_Vang();
	GD_Vang(char* ma, char* ht, diachi dc, ngaygd ng, float dg, int sl);
	GD_Vang(const GD_Vang& other);
	GD_Vang& operator=(const GD_Vang& other);
	~GD_Vang();

	void setDG(float dg);
	float getDG();

	void nhap();
	void xuat();
	GiaoDich* clone() const;
	float thanhtien();
	int getLoai() const;
	void ghiObj(fstream& g);
	void docObj(fstream& d);
};

#endif // GD_VANG_H
