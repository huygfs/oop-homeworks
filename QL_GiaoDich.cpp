#include "QL_GiaoDich.h"

QL_GiaoDich::QL_GiaoDich() :mDS(nullptr), mCnt(0)
{
}

QL_GiaoDich::QL_GiaoDich(const QL_GiaoDich& other)
{
	mCnt = other.mCnt;
	mDS = new GiaoDich * [mCnt];
	for (int i = 0; i < mCnt; i++)
		mDS[i] = other.mDS[i]->clone();
}

QL_GiaoDich::QL_GiaoDich(GiaoDich** ds, int cnt)
{
	mCnt = cnt;
	mDS = new GiaoDich * [mCnt];
	for (int i = 0; i < mCnt; i++)
		mDS[i] = ds[i]->clone();
}

QL_GiaoDich& QL_GiaoDich::operator=(const QL_GiaoDich& other)
{
	if (this == &other)
	{
		xoaDS(mCnt, mDS);
		mCnt = other.mCnt;
		mDS = new GiaoDich * [mCnt];
		for (int i = 0; i < mCnt; i++)
			mDS[i] = other.mDS[i]->clone();
	}
	return *this;
}

QL_GiaoDich::~QL_GiaoDich()
{
	if (!mDS || !mCnt)	xoaDS(mCnt, mDS);
}

void QL_GiaoDich::nhap()
{
	if (!mDS)
		xoaDS(mCnt, mDS);

	cout << "So luong: "; cin >> mCnt;
	mDS = new GiaoDich * [mCnt];
	GiaoDich* gd = nullptr;
	int c = -1;
	for (int i = 0; i < mCnt; i++)
	{
		cout << "Giao dich " << i + 1 << ":\n";
		cout << "Loai giao dich Vang(0) - TienTe(1) ?..."; cin >> c;
		while (c != 0 && c != 1)
		{
			cout << "khong ton tai loai giao dich da chon!\tNhap loai: "; cin >> c;
		}
		if (c == 0)	gd = new GD_Vang;
		else if (c == 1) gd = new GD_TienTe;
		gd->cleanInputStream();
		gd->nhap();
		mDS[i] = gd->clone();
	}
}

void QL_GiaoDich::xuat()
{
	if (!mCnt)
	{
		cout << "Danh sach rong!\n";
	}
	else if (!mDS)
	{
		cout << "Danh sach khong ton tai!\n";
	}
	else
	{
		equal();
		cout << "Danh sach gom co " << mCnt << " giao dich:\n";
		for (int i = 0; i < mCnt; i++)
		{
			line();
			mDS[i]->xuat();
		}
		equal();
	}
}

void QL_GiaoDich::thanhtienTB()
{
	float gd1 = 0, gd2 = 0, tmp = 0;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < mCnt; i++)
	{
		tmp = mDS[i]->thanhtien();
		if (mDS[i]->getLoai() == 0)
		{
			++c1;
			gd1 += tmp;
		}
		else
		{
			++c2;
			gd2 += tmp;
		}
	}
	cout << "Thanh tien trung binh moi loai giao dich:" << endl
		<< "Vang:          " << fixed << setprecision(2) << gd1 / (1.0 * c1) << endl
		<< "Tien te:       " << fixed << setprecision(2) << gd2 / (1.0 * c2) << endl;
}

void QL_GiaoDich::themgd()
{

	GiaoDich* gd;
	int c;
	cout << "Chon loai giao dich can them Vang(0) hay TienTe(1) ?..."; cin >> c;
	while (c != 0 && c != 1)
	{
		cout << "Khong ton tai loai giao dich da chon!\tNhap lai: "; cin >> c;
	}
	if (c == 0)
		gd = new GD_Vang;
	else
		gd = new GD_TienTe;

	gd->cleanInputStream();
	gd->nhap();

	them(gd);

	cout << "Them thanh cong!\n";
}

void QL_GiaoDich::xoaMa()
{
	char buff[maxchar];
	cout << "Nhap ma giao dich can xoa: ";
	cin.getline(buff, maxchar);
	cin.getline(buff, maxchar);
	assert(strlen(buff) == 6);

	int c = mCnt;

	for (int i = 0; i < mCnt; i++)
	{
		if (strcmp(buff, mDS[i]->getMa()) == 0)
			--c;
	}

	if (c == 0)
	{
		xoaDS(mCnt, mDS);
		return;
	}

	GiaoDich** ds = new GiaoDich * [c];
	for (int i = 0, k = 0; i < mCnt && k < c; i++)
	{
		if (strcmp(buff, mDS[i]->getMa()) == 0)
			continue;

		ds[k] = mDS[i]->clone();
		k++;
	}

	xoaDS(mCnt, mDS);
	mCnt = c;

	mDS = new GiaoDich * [mCnt];
	for (int i = 0; i < mCnt; i++)
		mDS[i] = ds[i]->clone();

	xoaDS(c, ds);
}

void QL_GiaoDich::them(GiaoDich* gd)
{
	if (mDS == nullptr)
	{
		mCnt = 1;
		mDS = new GiaoDich * [mCnt];
		mDS[0] = gd->clone();
		return;
	}

	char* t = gd->getMa();

	int i = 0;

	for (; i < mCnt; i++)
	{
		if (strcmp(mDS[i]->getMa(), t) > 0)	break;
	}

	if (i == mCnt)
	{
		int c1 = mCnt + 1;
		GiaoDich** ds1 = new GiaoDich * [c1];
		for (int k = 0; k < c1 - 1; k++)
			ds1[k] = mDS[k]->clone();
		ds1[c1 - 1] = gd->clone();

		xoaDS(mCnt, mDS);
		mCnt = c1;
		mDS = new GiaoDich * [mCnt];
		for (int j = 0; j < mCnt; j++)
			mDS[j] = ds1[j]->clone();

		xoaDS(c1, ds1);
		return;
	}

	int c1 = i + 1;
	GiaoDich** ds1 = new GiaoDich * [c1];
	int j = 0;
	for (; j < c1 - 1; j++)
		ds1[j] = mDS[j]->clone();
	ds1[j] = gd->clone();

	int c2 = mCnt - i;
	GiaoDich** ds2 = new GiaoDich * [c2];
	for (int k = 0; k < c2; k++, i++)
		ds2[k] = mDS[i]->clone();


	xoaDS(mCnt, mDS);

	mCnt = c1 + c2;
	mDS = new GiaoDich * [mCnt];
	int k = 0;
	for (; k < c1; k++)
		mDS[k] = ds1[k]->clone();
	for (int i = 0; i < c2; i++, k++)
		mDS[k] = ds2[i]->clone();

	xoaDS(c1, ds1);
	xoaDS(c2, ds2);
}

void QL_GiaoDich::GDVangLonNhatMoiQuanHCM()
{
	const char* hcm = "Ho Chi Minh";
	char* t = new char[strlen(hcm) + 1];
	strcpy_s(t, strlen(hcm) + 1, hcm);

	int c = 0;
	for (int i = 0; i < mCnt; i++)
	{
		if (mDS[i]->getLoai() == 0 && strcmp(mDS[i]->getTP(), t) == 0)	++c;
	}

	if (c == 0)
	{
		cout << "Khong ton tai giao dich vang o bat ky quan nao cua thanh pho HCM!\n";
		return;
	}

	GiaoDich** ds = new GiaoDich * [c];

	for (int i = 0, k = 0; k < c && i < mCnt; i++) {
		if (mDS[i]->getLoai() == 0 && strcmp(mDS[i]->getTP(), t) == 0)
		{
			ds[k] = mDS[i]->clone();
			k++;
		}
	}

	bool* v = new bool[c];
	for (int i = 0; i < c; i++)
		v[i] = false;

	for (int i = 0; i < c; i++)
	{
		if (v[i] == true)	continue;

		char* tmp = ds[i]->getQuan();
		float tien = ds[i]->thanhtien();
		int id = i;

		for (int j = i; j < c; j++)
		{
			if (mDS[i]->getLoai() == 0 && strcmp(mDS[i]->getTP(), t) == 0)
			{
				float tien2 = ds[j]->thanhtien();

				if (tien2 > tien)
				{
					tien = tien2;
					id = j;
				}
				v[j] = true;
			}
		}
		v[i] = true;
		line();
		cout << "Giao dich vang lon nhat o quan " << tmp << " la " << fixed << setprecision(2) << tien << endl;
		line();
		ds[id]->xuat();
	}

	delete[] v;
	xoaDS(c, ds);
}

void QL_GiaoDich::GDTienLonNhatTungLoai()
{
	int c = 0;
	for (int i = 0; i < mCnt; i++)
	{
		if (mDS[i]->getLoai() == 1)	++c;
	}

	if (c == 0)
	{
		cout << "Khong ton tai giao dich tien te nao!\n";
		return;
	}

	//cout << c << endl;

	GiaoDich** ds = new GiaoDich * [c];
	for (int i = 0, j = 0; i < mCnt && j < c; i++)
	{
		if (mDS[i]->getLoai() == 1)
		{
			ds[j] = mDS[i]->clone();
			j++;
		}
	}

	bool* v = new bool[c];

	for (int i = 0; i < c; i++)
	{
		v[i] = false;
	}

	for (int i = 0; i < c; i++)
	{
		if (v[i] == true)	continue;

		int id = i;
		GD_TienTe* t = dynamic_cast<GD_TienTe*>(ds[i]);
		int t1 = t->getTien();
		//cout << t1 << endl;
		int t2 = 0;
		float tien1 = t->thanhtien();
		float tien2 = 0;

		for (int j = i; j < c; j++)
		{
			t = dynamic_cast<GD_TienTe*>(ds[j]);
			t2 = t->getTien();
			tien2 = t->thanhtien();

			if (t2 == t1)
			{
				if (tien2 > tien1)
				{
					tien1 = tien2;
					id = j;
				}
				v[j] = true;
			}
		}

		cout << "Giao dich lon nhat tien te ";
		switch (t1)
		{
		case 1:
			cout << "VND:\n";
			break;
		case 2:
			cout << "USD:\n";
			break;
		case 3:
			cout << "EURO:\n";
			break;
		default:
			break;
		}
		ds[id]->xuat();
		cout << "Thanh tien: " << fixed << setprecision(2) << ds[id]->thanhtien() << endl;
		line();
	}
	delete[] v;
	xoaDS(c, ds);
}

void QL_GiaoDich::ghiTheoLoai()
{

	cout << "Chon loai giao dich muon ghi Vang(0) hay TienTe(1):...";
	int c = -1; cin >> c;
	while (c != 0 && c != 1)
	{
		cout << "Nhap sai!\tNhap lai:..."; cin >> c;
	}

	char tenFile[maxchar];

	switch (c)
	{
	case 0:
		strcpy_s(tenFile, maxchar, "ds_Vang.dat");
		break;
	case 1:
		strcpy_s(tenFile, maxchar, "ds_TienTe.dat");
		break;
	default:
		break;
	}

	fstream g;
	g.open(tenFile, ios::out | ios::binary | ios::trunc);

	if (!g)
	{
		cout << "loi mo file " << tenFile << " !\n";
		return;
	}

	int cnt = 0;
	for (int i = 0; i < mCnt; i++)
	{
		if (mDS[i]->getLoai() == c) ++cnt;
	}

	if (cnt == 0)
	{
		cout << "Khong ton tai giao dich ";
		switch (c)
		{
		case 0:
			cout << "vang";
			break;
		case 1:
			cout << "tien te";
			break;
		default:
			break;
		}
		return;
	}

	g.write((char*)&cnt, sizeof(int));
	for (int i = 0; i < mCnt; i++)
	{
		if (mDS[i]->getLoai() == c)
			mDS[i]->ghiObj(g);
	}

	g.close();
	cout << "Ghi file " << tenFile << " thanh cong !\n";
}

void QL_GiaoDich::docTheoLoai()
{
	cout << "Chon loai giao dich muon doc Vang(0) hay TienTe(1):...";
	int c=-1; cin >> c;
	while (c != 0 && c != 1)
	{
		cout << "Nhap sai!\tNhap lai:..."; cin >> c;
	}

	char tenFile[maxchar];

	switch (c)
	{
	case 0:
		strcpy_s(tenFile, maxchar, "ds_Vang.dat");
		break;
	case 1:
		strcpy_s(tenFile, maxchar, "ds_TienTe.dat");
		break;
	default:
		break;
	}

	fstream d;
	d.open(tenFile, ios::in | ios::binary);

	if (!d)
	{
		cout << "Loi mo file " << tenFile << " !\n";
		return;
	}

	int cnt = 0;
	d.read((char*)&cnt, sizeof(int));
	GiaoDich** ds = new GiaoDich * [cnt];
	GiaoDich* g = nullptr;
	for (int i = 0; i < cnt; i++)
	{
		switch (c)
		{
		case 0:
		{
			GD_Vang v;
			v.docObj(d);
			g = v.clone();
			break;
		}
		case 1:
		{
			GD_TienTe t;
			t.docObj(d);
			g = t.clone();
			break;
		}
		default:
			break;
		}

		if (!g) continue;

		ds[i] = g->clone();
	}

	d.close();
	cout << "Doc file " << tenFile << " thanh cong!\n";

	line();
	cout << "Danh sach gom co " << cnt << " giao dich:\n";
	for (int i = 0; i < cnt; i++)
	{
		line();
		ds[i]->xuat();
	}
	line();
	xoaDS(cnt, ds);
}

void QL_GiaoDich::line()
{
	cout << "--------------------------------------------\n";
}

void QL_GiaoDich::equal()
{
	cout << "============================================\n";
}

void QL_GiaoDich::xoaDS(int& cnt, GiaoDich**& ds)
{
	for (int i = 0; i < cnt; i++)
		delete ds[i];
	delete[] ds;
	cnt = 0;
	ds = nullptr;
}

void QL_GiaoDich::sinhngaunhien()
{
	GiaoDich* g1;
	GiaoDich* g2;
	GiaoDich* g3;
	GiaoDich* g4;
	GiaoDich* g5;
	GiaoDich* g6;
	GiaoDich* g7;
	GiaoDich* g8;
	GiaoDich* g9;
	GiaoDich* g10;


	GD_Vang v1;
	v1.setMa("000001");
	v1.setHT("Vang 1");
	v1.setDC(1, "Tran Phu", "Loc Tho", "3", "Nha Trang");
	v1.setNG(1, 1, 2001);
	v1.setSL(100);
	v1.setDG(100000);
	g1 = &v1;
	GD_Vang v2;
	v2.setMa("000002");
	v2.setHT("Vang 2");
	v2.setDC(2, "Tran Hung Dao", "Vinh Nguyen", "1", "Ho Chi Minh");
	v2.setNG(2, 2, 2002);
	v2.setSL(22);
	v2.setDG(200000);
	g2 = &v2;
	GD_Vang v3;
	v3.setMa("003003");
	v3.setHT("Vang 3");
	v3.setDC(4, "Tran Nhat Duat", "Vinh Trung", "3", "Quy Nhon");
	v3.setNG(3, 3, 2003);
	v3.setSL(3);
	v3.setDG(300000);
	g3 = &v3;
	GD_Vang v4;
	v4.setMa("000004");
	v4.setHT("Vang 4");
	v4.setDC(4, "Tran Dan", "Phan Dong", "1", "Ca li");
	v4.setNG(4, 4, 2004);
	v4.setSL(4);
	v4.setDG(400000);
	g4 = &v4;
	GD_Vang v5;
	v5.setMa("000105");
	v5.setHT("Vang 5");
	v5.setDC(5, "Tran Duc Bo", "LGBT", "3", "Ho Chi Minh");
	v5.setNG(5, 5, 2005);
	v5.setSL(5);
	v5.setDG(500000);
	g5 = &v5;

	GD_TienTe t6;
	GD_TienTe t7;
	GD_TienTe t8;
	GD_TienTe t9;
	GD_TienTe t10;

	t6.setMa("100006");
	t6.setHT("Tien Te 6");
	t6.setDC(1, "Nguyen Duc Canh", "Tan Lap", "6", "Nha Trang");
	t6.setNG(6, 6, 2006);
	t6.setSL(6);
	t6.setTien(1);
	t6.setTG(1);
	t6.setDG(1000);

	t7.setMa("110007");
	t7.setHT("Tien Te 7");
	t7.setDC(7, "Tran Duy Hung", "Vinh Xuan Quyen", "7", "Ha Loi");
	t7.setNG(7, 7, 2007);
	t7.setSL(7);
	t7.setTien(2);
	t7.setTG(23000);
	t7.setDG(70);

	t8.setMa("104008");
	t8.setHT("Tien Te 8");
	t8.setDC(8, "Ngo Duc Ke", "Linh Trung", "8", "Thu Duc");
	t8.setNG(8, 8, 2008);
	t8.setSL(8);
	t8.setTien(3);
	t8.setTG(25000);
	t8.setDG(80);

	t9.setMa("100069");
	t9.setHT("Tien Te 9");
	t9.setDC(4, "Ngo Quyen", "Xuong Huan", "9", "Nha Trang");
	t9.setNG(9, 9, 2009);
	t9.setSL(9);
	t9.setTien(1);
	t9.setTG(1);
	t9.setDG(500000);

	t10.setMa("000000");
	t10.setHT("Tien Te 10");
	t10.setDC(10, "Nguyen Trai", "Vinh Truong", "10", "Nha Trang");
	t10.setNG(10, 10, 2010);
	t10.setSL(10);
	t10.setTien(3);
	t10.setTG(25000);
	t10.setDG(100000);

	g6 = &t6;
	g7 = &t7;
	g8 = &t8;
	g9 = &t9;
	g10 = &t10;

	//xoaDS(mCnt, mDS);
	//mCnt = 10;
	//mDS = new GiaoDich * [mCnt];
	//mDS[0] = g1->clone();
	//mDS[1] = g2->clone();
	//mDS[2] = g3->clone();
	//mDS[3] = g4->clone();
	//mDS[4] = g5->clone();
	//mDS[5] = g6->clone();
	//mDS[6] = g7->clone();
	//mDS[7] = g8->clone();
	//mDS[8] = g9->clone();
	//mDS[9] = g10->clone();

	xoaDS(mCnt, mDS);

	them(g1);
	them(g2);
	them(g3);
	them(g4);
	them(g5);
	them(g6);
	them(g7);
	them(g8);
	them(g9);
	them(g10);
}

void QL_GiaoDich::ghids()
{
	fstream ghi;
	ghi.open("dsgd.dat", ios::out | ios::binary | ios::trunc);

	if (!ghi)
	{
		cout << "Loi mo file dsgd.dat\n";
		return;
	}

	ghi.write((char*)&mCnt, sizeof(int));
	for (int i = 0; i < mCnt; i++)
	{
		int l = mDS[i]->getLoai();
		ghi.write((char*)&l, sizeof(int));
		mDS[i]->ghiObj(ghi);
	}

	ghi.close();
	cout << "Ghi file dsgd.dat thanh cong!\n";
}

void QL_GiaoDich::docds()
{
	fstream doc;
	doc.open("dsgd.dat", ios::in | ios::binary);
	if (!doc)
	{
		cout << "Loi mo file dsgd.dat!\n";
		return;
	}

	xoaDS(mCnt, mDS);

	doc.seekg(0, ios::beg);
	doc.read((char*)&mCnt, sizeof(int));
	mDS = new GiaoDich * [mCnt];
	GiaoDich* g = nullptr;
	for (int i = 0; i < mCnt; i++)
	{
		int l;
		doc.read((char*)&l, sizeof(int));
		if (l == 0)
		{
			//g = new GD_Vang;
			GD_Vang v;
			v.docObj(doc);
			//*dynamic_cast<GD_Vang*>(g) = v;
			g = v.clone();
		}
		else
		{
			//g = new GD_TienTe;
			GD_TienTe t;
			t.docObj(doc);
			//*dynamic_cast<GD_TienTe*>(g) = t;
			g = t.clone();
		}

		if (!g)	continue;

		mDS[i] = g->clone();
	}
	doc.close();
	cout << "Doc file dsgd.dat thanh cong!\n";
}
