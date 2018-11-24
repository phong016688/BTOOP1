//
// Created by vo phong on 06/10/2018.
//
#include <ostream>
#include "Sach.h"

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H


class List {
private:
	int sizeList;
	Sach *pSach;
	int timkiemtheomasach(const string& masach);
public:
	List();

	List(List &list);

	~List();

	void them(int index, Sach &sach);

	void themdau(Sach &sach);

	void themcuoi(Sach &sach);

	void capnhat(int index);

	int getSizeList() const;

	void xoa(int index);

	void xoadau();

	void xoacuoi();

	void SellSort(Sach a[], int length, bool(*thuoctinh)(string, string));

	void sapxep(bool(*thuoctinh)(string, string)); // sap xep theo thuoc tinh ma sach thuat toan Sell Sort


	Sach* binarySearch(Sach arr[], int l, int r, string masach);

	Sach* timkiem(string masach);

	friend ostream &operator<<(ostream &os, const List &list);

	Sach& operator [] (int i);

	friend istream& operator>>(istream& is, List& list);
};
bool tangdan(string left, string right);
bool giamdan(string left, string right);


#endif //UNTITLED_LIST_H
