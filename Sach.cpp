//
// Created by vo phong on 05/10/2018.
//

#include "Sach.h"
#include <iostream>
#include <string>

using namespace std;

Sach::Sach() {
	maSach = "111111111";
	tenSach = "mac dinh";
	namXuatBan = 1000;
	soQuyen = 0;
	tinhtrang = false;
}

Sach::Sach(Sach &sach) {
	maSach = sach.maSach;
	tenSach = sach.tenSach;
	namXuatBan = sach.namXuatBan;
	soQuyen = sach.soQuyen;
	tinhtrang = sach.tinhtrang;
}

Sach::Sach(const string &maSach, const string &tenSach, int namXuatBan, int soQuyen, bool tinhtrang) {
	if (maSach.size() != 9 || (maSach[0] - '0') <= 0 || (maSach[0] - '0') > 5
		|| namXuatBan < 1000 || namXuatBan > 9999 || soQuyen <= 0) {
		this->maSach = "111111111";
		this->tenSach = "mac dinh";
		this->namXuatBan = 1000;     // neu khong dung dinh dang tra ve du lieu mac dinh
		this->soQuyen = 0;
		this->tinhtrang = false;
	}
	else {
		this->maSach = maSach;
		this->tenSach = tenSach;
		this->namXuatBan = namXuatBan;
		this->soQuyen = soQuyen;
		this->tinhtrang = tinhtrang;
	}

}

ostream &operator<<(ostream &os, const Sach &sach) {
	string s = sach.tinhtrang ? "con" : "het";
	os << "maSach: " << sach.maSach << " | tenSach: " << sach.tenSach << " | namXuatBan: " << sach.namXuatBan
		<< " | soQuyen: " << sach.soQuyen << " | tinhtrang: " << s;
	return os;
}

istream &operator>>(istream &is, Sach &sach) {
	do {
		cout << "nhap ma sach (9 ki tu):";
		is >> sach.maSach;
		if (sach.maSach.size() != 9)
			cout << "ma sach phai co 9 ki tu" << endl;
		if ((sach.maSach[0] - '0') <= 0 || (sach.maSach[0] - '0') > 5)
			cout << "nhap lai so dau tu 1 -> 5" << endl;
	} while (sach.maSach.size() != 9 || (sach.maSach[0] - '0') <= 0 || (sach.maSach[0] - '0') > 5);
	cout << "nhap ten sach:";
	is.ignore();
	getline(is, sach.tenSach);
	do {
		cout << "nhap nam xuat ban (>0):";
		is >> sach.namXuatBan;
		if (sach.namXuatBan < 1000 || sach.namXuatBan > 9999)
			cout << "nam xuat ban tu 1000 -> 9999" << endl;
	} while (sach.namXuatBan > 9999 || sach.namXuatBan < 1000);
	do {
		cout << "nhap so quyen (>0):";
		is >> sach.soQuyen;
		if (sach.soQuyen <= 0)
			cout << "so quyen phai > 0" << endl;
	} while (sach.soQuyen <= 0);
	cout << "nhap tinh trang 1(con) hoac 0(het):";
	is >> sach.tinhtrang;
	return is;
}

const string &Sach::getTenSach() const {
	return tenSach;
}

Sach::~Sach() {

}

const string &Sach::getMaSach() const {
	return maSach;
}

void Sach::setMaSach(const string &maSach) {
	if (maSach.size() == 9 && (maSach[0] - '0') > 0 && (maSach[0] - '0') <= 5)
		this->maSach = maSach;

}

void Sach::setTenSach(const string &tenSach) {
	this->tenSach = tenSach;
}

int Sach::getNamXuatBan() const {
	return namXuatBan;
}

void Sach::setNamXuatBan(int namXuatBan) {
	if (namXuatBan >= 1000 && namXuatBan <= 9999)
		this->namXuatBan = namXuatBan;
}

int Sach::getSoQuyen() const {
	return soQuyen;
}

void Sach::setSoQuyen(int soQuyen) {
	if (soQuyen > 0)
		this->soQuyen = soQuyen;
}

bool Sach::isTinhtrang() const {
	return tinhtrang;
}

void Sach::setTinhtrang(bool tinhtrang) {
	this->tinhtrang = tinhtrang;
}
