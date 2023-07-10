#include "GD_TienTe.h"

GD_TienTe::GD_TienTe() :GiaoDich(), mDG(0), mTG(0), mTien(0)
{
}

GD_TienTe::GD_TienTe(char* ma, char* ht, diachi dc, ngaygd ng, float dg, int sl, float tg, int loai) :GiaoDich(ma, ht, dc, ng, sl)
{
	if (mTien == 1)
	{
		float dgArr[vn] = { 1000,2000,5000,10000,20000,50000,100000,200000,500000 };

		mTG = 1;
		while (true)
		{
			int i = 0;
			for (; i < vn; i++)
			{
				if (dg == dgArr[i])
				{
					mDG = dg;
					return;
				}
			}
			if (i == vn)
			{
				cout << "Don gia VN khong hop le! Nhap lai";
				cin >> dg;
			}
		}
	}
	else
	{
		mTG = tg;
		mDG = dg;
	}
}

GD_TienTe::GD_TienTe(const GD_TienTe& other) :GiaoDich(other), mDG(other.mDG), mTG(other.mTG), mTien(other.mTien)
{
}

GD_TienTe::~GD_TienTe()
{
}

GD_TienTe& GD_TienTe::operator=(const GD_TienTe& other)
{
	if (this == &other)
	{
		GiaoDich::operator=(other);
		mDG = other.mDG;
		mTG = other.mTG;
		mTien = other.mTien;
	}

	return *this;
}

void GD_TienTe::setDG(float dg)
{
	if (mTien == 1)
	{
		float dgArr[vn] = { 1000,2000,5000,10000,20000,50000,100000,200000,500000 };

		while (true)
		{
			int i = 0;
			for (; i < vn; i++)
			{
				if (dg == dgArr[i])
				{
					mDG = dg;
					return;
				}
			}
			if (i == vn)
			{
				cout << "Don gia VN khong hop le! Nhap lai";
				cin >> dg;
			}
		}
	}
	else
		mDG = dg;
}

void GD_TienTe::setTG(float tg)
{
	mTG = (mTien == 1) ? 1 : tg;
}

void GD_TienTe::setTien(int l)
{
	mTien = l;
}

float GD_TienTe::getDG()
{
	return mDG;
}

float GD_TienTe::getTG()
{
	return mTG;
}

int GD_TienTe::getTien()
{
	return mTien;
}

void GD_TienTe::xuat()
{
	GiaoDich::xuat();
	cout << "Loai: ";
	switch (mTien)
	{
	case 1:
		cout << "VND\n";
		break;
	case 2:
		cout << "USD\n";
		break;
	case 3:
		cout << "EURO\n";
		break;
	default:
		break;
	}
	cout << "Ti gia: " << mTG << endl
		<< "Don gia: " << mDG << endl;
}

void GD_TienTe::nhap()
{
	GiaoDich::nhap();
	mTien = 0;
	cout << "Loai:\nVND\t(1)\nUSD\t(2)\nEuro\t(3)\n..."; cin >> mTien;
	while (mTien != 1 && mTien != 2 && mTien != 3)
	{
		cout << "Khong ton tai loai tien te da nhap!\tNhap lai: "; cin >> mTien;
	}
	cout << "Don gia: "; cin >> mDG;
	if (mTien == 1)
	{
		float dgArr[vn] = { 1000,2000,5000,10000,20000,50000,100000,200000,500000 };

		int c = 0;
		while (c == 0)
		{
			int i = 0;
			for (; i < vn; i++)
			{
				if (mDG == dgArr[i])
				{
					c = 1;
					break;
				}
			}
			if (i == vn)
			{
				cout << "Don gia VN khong hop le! Nhap lai";
				cin >> mDG;
			}
		}
	}
	cout << "Ti gia: "; cin >> mTG;
	if (mTien == 1)
		mTG = 1.0;
}

GiaoDich* GD_TienTe::clone() const
{
	return new GD_TienTe(*this);
}

float GD_TienTe::thanhtien()
{
	return 1.0f * mDG * mTG * getSL();
}

int GD_TienTe::getLoai() const
{
	return 1;
}

void GD_TienTe::ghiObj(fstream& g)
{
	GiaoDich::ghiObj(g);
	g.write((char*)&mTien, sizeof(int));
	g.write((char*)&mTG, sizeof(float));
	g.write((char*)&mDG, sizeof(float));
}

void GD_TienTe::docObj(fstream& d)
{
	GiaoDich::docObj(d);
	d.read((char*)&mTien, sizeof(int));
	d.read((char*)&mTG, sizeof(float));
	d.read((char*)&mDG, sizeof(float));
}
