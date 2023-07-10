#include "GiaoDich.h"

GiaoDich::GiaoDich() :mMa(nullptr), mHT(nullptr), mSL(0)
{
	mDC.so = 0;
	mDC.duong = nullptr;
	mDC.phuong = nullptr;
	mDC.quan = nullptr;
	mDC.tp = nullptr;
	mNG.d = 0;
	mNG.m = 0;
	mNG.y = 0;
}

GiaoDich::GiaoDich(const GiaoDich& other)
{
	assert(strlen(other.mMa) == 6);
	mMa = new char[strlen(other.mMa) + 1];
	strcpy_s(mMa, strlen(other.mMa) + 1, other.mMa);
	mHT = new char[strlen(other.mHT) + 1];
	strcpy_s(mHT, strlen(other.mHT) + 1, other.mHT);
	setDC(other.mDC);
	setNG(other.mNG);
	mSL = other.mSL;
}

GiaoDich::GiaoDich(char* ma, char* ht, diachi dc, ngaygd ng, int sl)
{
	assert(strlen(ma) == 6);
	for (int i = 0; ma[i] != '\0'; i++)
		assert(isalnum(ma[i]));

	mMa = new char[strlen(ma) + 1];
	strcpy_s(mMa, strlen(ma) + 1, ma);
	mHT = new char[strlen(ht) + 1];
	strcpy_s(mHT, strlen(ht) + 1, ht);
	setDC(dc);
	setNG(ng);
	mSL = sl;
}

GiaoDich::~GiaoDich()
{
	if (this != nullptr)	xoaGD(*this);
}

GiaoDich& GiaoDich::operator=(const GiaoDich& other)
{
	if (this == &other)
	{
		xoaGD(*this);
		assert(strlen(other.mMa) == 6);
		mMa = new char[strlen(other.mMa) + 1];
		mHT = new char[strlen(other.mHT) + 1];
	}

	strcpy_s(mMa, strlen(other.mMa) + 1, other.mMa);
	strcpy_s(mHT, strlen(other.mHT) + 1, other.mHT);
	setDC(other.mDC);
	setNG(other.mNG);
	mSL = other.mSL;

	return *this;
}

void GiaoDich::setDC(diachi dc)
{
	xoaDC(mDC);

	mDC.so = dc.so;

	mDC.duong = new char[strlen(dc.duong) + 1];
	strcpy_s(mDC.duong, strlen(dc.duong) + 1, dc.duong);

	mDC.phuong = new char[strlen(dc.phuong) + 1];
	strcpy_s(mDC.phuong, strlen(dc.phuong) + 1, dc.phuong);

	mDC.quan = new char[strlen(dc.quan) + 1];
	strcpy_s(mDC.quan, strlen(dc.quan) + 1, dc.quan);

	mDC.tp = new char[strlen(dc.tp) + 1];
	strcpy_s(mDC.tp, strlen(dc.tp) + 1, dc.tp);
}

void GiaoDich::setDC(int so, const char* d, const char* p, const char* q, const char* tp)
{
	xoaDC(mDC);
	mDC.so = so;
	mDC.duong = new char[strlen(d) + 1];
	strcpy_s(mDC.duong, strlen(d) + 1, d);

	mDC.phuong = new char[strlen(p) + 1];
	strcpy_s(mDC.phuong, strlen(p) + 1, p);

	mDC.quan = new char[strlen(q) + 1];
	strcpy_s(mDC.quan, strlen(q) + 1, q);

	mDC.tp = new char[strlen(tp) + 1];
	strcpy_s(mDC.tp, strlen(tp) + 1, tp);
}

void GiaoDich::setNG(ngaygd ng)
{
	//xoaNG(mNG);
	mNG.d = ng.d;
	mNG.m = ng.m;
	mNG.y = ng.y;
}

void GiaoDich::setNG(int d, int m, int y)
{
	assert(0 < y);
	assert(0 < m && m <= 12);
	assert(0 < d && d <= 31);
	mNG.d = d;
	mNG.m = m;
	mNG.y = y;
}

void GiaoDich::setMa(const char* ma)
{
	assert(strlen(ma) == 6);
	for (int i = 0; ma[i] != '\0'; i++)
		assert(ma[i]);

	if (!mMa) delete[] mMa;
	mMa = new char[strlen(ma) + 1];
	strcpy_s(mMa, strlen(ma) + 1, ma);
}

void GiaoDich::setHT(const char* ht)
{
	if (!mHT) delete[] mHT;

	mHT = new char[strlen(ht) + 1];

	strcpy_s(mHT, strlen(ht) + 1, ht);
}

void GiaoDich::setSL(int sl)
{
	mSL = sl;
}

int GiaoDich::getSL()
{
	return mSL;
}

char* GiaoDich::getMa()
{
	return mMa;
}

char* GiaoDich::getQuan()
{
	return mDC.quan;
}

char* GiaoDich::getTP()
{
	return mDC.tp;
}

void GiaoDich::nhap()
{
	char buff[maxchar];

	cout << "Ma: ";
	cin.getline(buff, maxchar);
	setMa(buff);

	cout << "Ho ten: ";
	cin.getline(buff, maxchar);
	setHT(buff);

	cout << "Dia chi (so, duong, phuong ,quan, thanh pho):\n";
	diachi dc;

	cout << "so: "; cin >> dc.so;

	cout << "duong: "; cin.getline(buff, maxchar);
	dc.duong = new char[strlen(buff) + 1];
	strcpy_s(dc.duong, strlen(buff) + 1, buff);

	cout << "phuong: "; cin.getline(buff, maxchar);
	dc.phuong = new char[strlen(buff) + 1];
	strcpy_s(dc.phuong, strlen(buff) + 1, buff);

	cout << "quan: "; cin.getline(buff, maxchar);
	dc.quan = new char[strlen(buff) + 1];
	strcpy_s(dc.quan, strlen(buff) + 1, buff);

	cout << "thanh pho: "; cin.getline(buff, maxchar);
	dc.tp = new char[strlen(buff) + 1];
	strcpy_s(dc.tp, strlen(buff) + 1, buff);

	setDC(dc);

	cout << "Ngay(d/m/y):\n";
	ngaygd ng;

	cout << "d: "; cin >> ng.d;
	cout << "m: "; cin >> ng.m;
	cout << "y: "; cin >> ng.y;
	setNG(ng);

	cout << "So luong: "; cin >> mSL;

	delete[] dc.duong;
	delete[] dc.phuong;
	delete[] dc.quan;
	delete[] dc.tp;
}

void GiaoDich::xuat()
{
	cout << "Ma: " << mMa << endl
		<< "Ho ten: " << mHT << endl
		<< "Dia chi: " << mDC.so << " " << mDC.duong << ", phuong " << mDC.phuong << ", quan " << mDC.quan << ",tp. " << mDC.tp << endl
		<< "Ngay: " << mNG.d << "-" << mNG.m << "-" << mNG.y << endl
		<< "So luong: " << mSL << endl;
}

void GiaoDich::ghiObj(fstream& g)
{
	int l = strlen(mMa) + 1;
	g.write((char*)&l, sizeof(int));
	g.write(mMa, l);

	l = strlen(mHT) + 1;
	g.write((char*)&l, sizeof(int));
	g.write(mHT, l);


	g.write((char*)&mDC.so, sizeof(int));
	
	l = strlen(mDC.duong) + 1;
	g.write((char*)&l, sizeof(int));
	g.write(mDC.duong, l);

	l = strlen(mDC.phuong) + 1;
	g.write((char*)&l, sizeof(int));
	g.write(mDC.phuong, l);

	l = strlen(mDC.quan) + 1;
	g.write((char*)&l, sizeof(int));
	g.write(mDC.quan, l);

	l = strlen(mDC.tp) + 1;
	g.write((char*)&l, sizeof(int));
	g.write(mDC.tp, l);

	g.write((char*)&mNG.d, sizeof(int));
	g.write((char*)&mNG.m, sizeof(int));
	g.write((char*)&mNG.y, sizeof(int));

	g.write((char*)&mSL, sizeof(int));
}

void GiaoDich::docObj(fstream& d)
{
	xoaGD(*this);

	int l = 0;

	d.read((char*)&l, sizeof(int));
	mMa = new char[l];
	d.read(mMa, l);
	cout << mMa << endl;

	d.read((char*)&l, sizeof(int));
	mHT = new char[l];
	d.read(mHT, l);
	cout << mHT << endl;

	d.read((char*)&mDC.so, sizeof(int));

	d.read((char*)&l, sizeof(int));
	mDC.duong = new char[l];
	d.read(mDC.duong, l);
	cout << mDC.duong << endl;

	d.read((char*)&l, sizeof(int));
	mDC.phuong = new char[l];
	d.read(mDC.phuong, l);
	cout << mDC.phuong << endl;

	d.read((char*)&l, sizeof(int));
	mDC.quan = new char[l];
	d.read(mDC.quan, l);
	cout << mDC.quan << endl;

	d.read((char*)&l, sizeof(int));
	mDC.tp = new char[l];
	d.read(mDC.tp, l);
	cout << mDC.tp << endl;

	d.read((char*)&mNG.d, sizeof(int));
	d.read((char*)&mNG.m, sizeof(int));
	d.read((char*)&mNG.y, sizeof(int));

	d.read((char*)&mSL, sizeof(int));
}

void GiaoDich::xoaGD(GiaoDich& gd)
{
	if (gd.mMa != nullptr)	delete[] gd.mMa;
	if (gd.mHT != nullptr) delete[] gd.mHT;
	if (gd.mDC.so != 0)
	{
		gd.mDC.so = 0;
		if (gd.mDC.duong != nullptr)	delete[] gd.mDC.duong;
		if (gd.mDC.phuong != nullptr)	delete[] gd.mDC.phuong;
		if (gd.mDC.quan != nullptr)	delete[] gd.mDC.quan;
		if (gd.mDC.tp != nullptr) delete[] gd.mDC.tp;
	}
	gd.mNG.d = gd.mNG.m = gd.mNG.y = 0;
	gd.mSL = 0;
}

void GiaoDich::xoaDC(diachi& dc)
{
	if (dc.so > 0)
	{
		dc.so = 0;
		if (!dc.duong)	delete[] dc.duong;
		if (!dc.phuong) delete[] dc.phuong;
		if (!dc.quan) delete[] dc.quan;
		if (!dc.tp) delete[] dc.tp;
	}
}

void GiaoDich::xoaNG(ngaygd& ng)
{
	ng.d = ng.m = ng.y = 0;
}
//
//void GiaoDich::inputDC(diachi& dc, int so, const char* d, const char* p, const char* q, const char* tp)
//{
//	xoaDC(dc);
//
//	dc.so = so;
//	dc.duong = new char[strlen(d) + 1];
//	strcpy_s(dc.duong, d);
//	dc.phuong = new char[strlen(p) + 1];
//	strcpy_s(dc.phuong, p);
//	dc.quan = new char[strlen(q) + 1];
//	strcpy_s(dc.quan, q);
//	dc.tp = new char[strlen(tp) + 1];
//	strcpy_s(dc.tp, tp);
//}
//
//void GiaoDich::outputDC(diachi& dc)
//{
//	if (dc.so == 0)
//	{
//		cout << "khong co dia chi!\n";
//		return;
//	}
//
//	cout << dc.so << " " << dc.duong << ", p." << dc.phuong << ", q." << dc.quan << ", tp." << dc.tp;
//}

void GiaoDich::cleanInputStream()
{
	char trash[maxchar];
	cin.getline(trash, maxchar);
}
