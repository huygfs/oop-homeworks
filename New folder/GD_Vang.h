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

	virtual void nhap();
	virtual void xuat();
	virtual GiaoDich* clone() const;
	virtual float thanhtien();
	virtual int getLoai() const;
	virtual void ghiObj(fstream& g);
	virtual void docObj(fstream& d);
};

#endif // GD_VANG_H
