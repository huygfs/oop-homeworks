#include "GD_Vang.h"

GD_Vang::GD_Vang() :GiaoDich(), mDG(0)
{
}

GD_Vang::GD_Vang(char* ma, char* ht, diachi dc, ngaygd ng, float dg, int sl) :GiaoDich(ma, ht, dc, ng, sl), mDG(dg)
{
}

GD_Vang::GD_Vang(const GD_Vang& other) :GiaoDich(other), mDG(other.mDG)
{
}

GD_Vang& GD_Vang::operator=(const GD_Vang& other)
{
	if (this == &other)
	{
		GiaoDich::operator=(other);
		mDG = other.mDG;
	}

	return *this;
}

GD_Vang::~GD_Vang()
{
}

void GD_Vang::setDG(float dg)
{
	mDG = dg;
}

float GD_Vang::getDG()
{
	return mDG;
}

void GD_Vang::nhap()
{
	GiaoDich::nhap();
	cout << "Don gia: "; cin >> mDG;
}

void GD_Vang::xuat()
{
	GiaoDich::xuat();
	cout << "Don gia: " << mDG << endl;
}

GiaoDich* GD_Vang::clone() const
{
	return new GD_Vang(*this);
}

float GD_Vang::thanhtien()
{
	return 1.0f * mDG * getSL();
}

int GD_Vang::getLoai() const
{
	return 0;
}

void GD_Vang::ghiObj(fstream& g)
{
	GiaoDich::ghiObj(g);
	g.write((char*)&mDG, sizeof(float));
}

void GD_Vang::docObj(fstream& d)
{
	GiaoDich::docObj(d);
	d.read((char*)&mDG, sizeof(float));
}
