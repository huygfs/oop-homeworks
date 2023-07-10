#ifndef GD_TIENTE_H
#define GD_TIENTE_H
#include "GiaoDich.h"

#define vn 9
class GD_TienTe :
	public GiaoDich
{
private:
	float mDG;
	float mTG;
	int mTien;
public:
	GD_TienTe();
	GD_TienTe(char* ma, char* ht, diachi dc, ngaygd ng, float dg, int sl, float tg, int loai);
	GD_TienTe(const GD_TienTe& other);
	~GD_TienTe();
	GD_TienTe& operator=(const GD_TienTe& other);

	void setDG(float dg);
	void setTG(float tg);
	void setTien(int l);
	float getDG();
	float getTG();
	int getTien();

	virtual void xuat();
	virtual void nhap();
	virtual GiaoDich* clone() const;
	virtual float thanhtien();
	virtual int getLoai() const;
	virtual void ghiObj(fstream& g);
	virtual void docObj(fstream& d);

};
#endif // !GD_TIENTE_H

