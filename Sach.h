//
// Created by vo phong on 05/10/2018.
//
#include <ostream>

#ifndef UNTITLED_SACH_H
#define UNTITLED_SACH_H
using namespace std;
class Sach {
private:
	string maSach;
	string tenSach;
	int namXuatBan;
	int soQuyen;
	bool tinhtrang;
public:
	Sach();
	Sach(Sach&);
	Sach(const string &maSach, const string &tenSach, int namXuatBan, int soQuyen, bool tinhtrang);

	~Sach();

	const string &getTenSach() const;

	const string &getMaSach() const;

	void setMaSach(const string &maSach);

	void setTenSach(const string &tenSach);

	int getNamXuatBan() const;

	void setNamXuatBan(int namXuatBan);

	int getSoQuyen() const;

	void setSoQuyen(int soQuyen);

	bool isTinhtrang() const;

	void setTinhtrang(bool tinhtrang);

	friend ostream &operator<<(ostream &os, const Sach &sach);
	friend istream &operator>>(istream &is, Sach &sach);

};


#endif //UNTITLED_SACH_H
