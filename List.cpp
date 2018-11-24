//
// Created by vo phong on 06/10/2018.
//

#include <iostream>
#include "List.h"


List::List() {
	sizeList = 0;
	pSach = new Sach[sizeList];
}

List::List(List &list) {
	delete[] pSach;
	sizeList = list.sizeList;
	pSach = new Sach[sizeList];
	for (int i = 0; i < sizeList; i++) {
		*(pSach + i) = *(list.pSach + i);
	}
}

List::~List() {
	delete[] pSach;
}

void List::them(int index, Sach &sach) {
	if (index < 0 || index > sizeList) {
		cout << "khong the them" << endl;
	}
	else {
		if (timkiemtheomasach(sach.getMaSach()) != -1) {
			cout << "doi tuong da ton tai, tang so luong len" << endl;
			int vitri = timkiemtheomasach(sach.getMaSach());
			pSach[vitri].setSoQuyen(pSach[vitri].getSoQuyen() + sach.getSoQuyen());
		}
		else {
			sizeList++;
			Sach *a = new Sach[sizeList];
			for (int j = 0; j < index; j++) {
				a[j] = pSach[j];
			}
			a[index] = sach;
			for (int i = index + 1; i < sizeList; i++) {
				a[i] = pSach[i - 1];
			}

			delete[] pSach;
			pSach = a;

		}
	}
}

void List::capnhat(int index) {
	cout << "doi tuong ban muon cap nhat la : " << endl;
	cout << *(pSach + index);
	cout << "\n";
	cout << "Moi ban nhap doi tuong moi" << endl;
	cin >> *(pSach + index);
}

void List::xoa(int index) {
	if (index < 0 || index >= sizeList) {
		cout << "khong the xoa" << endl;
	}
	else {
		int soquyenhientai = (*(pSach + index)).getSoQuyen();
		if ((soquyenhientai - 1) > 0) {
			(*(pSach + index)).setSoQuyen(soquyenhientai - 1);
		}
		else {
			sizeList--;
			Sach *a = new Sach[sizeList];
			for (int j = 0; j < index; j++) {
				a[j] = pSach[j];
			}
			for (int i = index; i < sizeList; i++) {
				a[i] = pSach[i + 1];
			}

			delete[] pSach;
			pSach = a;
		}
	}

}

void List::SellSort(Sach a[], int length, bool(*thuoctinh)(string, string)) {
	Sach temp;

	for (int gap = length / 2; gap > 0; gap /= 2)
		for (int i = gap; i < length; i++)
			for (int j = i - gap; j >= 0 && thuoctinh(a[j].getMaSach(), a[j + gap].getMaSach()) > 0; j -= gap) {
				temp = a[j];
				a[j] = a[j + gap];
				a[j + gap] = temp;
			}
}

void List::sapxep(bool(*thuoctinh)(string, string)) {
	SellSort(pSach, sizeList, thuoctinh);
}

Sach *List::binarySearch(Sach arr[], int l, int r, string masach) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid].getMaSach() == masach) {
			int left_tam = mid, right_tam = mid;
			while (arr[left_tam].getMaSach() == masach && left_tam >= l) {
				if (left_tam == 0)
					break;
				else
					left_tam--;
			}
			if (left_tam != 0) left_tam++;
			while (arr[right_tam].getMaSach() == masach && right_tam <= r) {
				if (right_tam == r)
					break;
				else right_tam++;
			}
			if (right_tam != r)
				right_tam--;
			Sach *ptr = new Sach[right_tam - left_tam + 1];

			for (int i = 0; i < right_tam - left_tam + 1; i++) {
				*(ptr + i) = arr[i + left_tam];
				cout << "doi tuong " << i << ":  " << *(ptr + i) << endl; //in ra doi tuong
			}
			return ptr;
		}
		if (arr[mid].getMaSach() > masach)
			return binarySearch(arr, l, mid - 1, masach);
		if (arr[mid].getMaSach() < masach)
			return binarySearch(arr, mid + 1, r, masach);
	}

	return NULL;
}

Sach *List::timkiem(string masach) {
	List list;
	list.sizeList = sizeList;
	list.pSach = new Sach[list.sizeList];
	for (int i = 0; i < list.sizeList; i++) {
		*(list.pSach + i) = *(pSach + i);
	}          // sao chep them doi tuong tu doi tuong goc, tranh viec doi tuong goc bi sap xep .
	list.sapxep(tangdan);
	return  binarySearch(list.pSach, 0, list.sizeList - 1, masach);
}

ostream &operator<<(ostream &os, const List &list) {
	os << "size list = " << list.sizeList << endl;
	for (int i = 0; i < list.sizeList; i++) {
		os << "doi tuong " << i << ":   " << *(list.pSach + i) << endl;
	}
	return os;
}

Sach &List::operator[](int i) {
	return *(pSach + i);
}

void List::themdau(Sach &sach) {
	them(0, sach);
}

void List::themcuoi(Sach &sach) {
	them(sizeList, sach);
}

void List::xoadau() {
	xoa(0);
}

void List::xoacuoi() {
	xoa(sizeList - 1);
}

istream &operator>>(istream &is, List &list) {
	delete[] list.pSach;
	do {
		cout << "nhap sizelist (>0): ";
		is >> list.sizeList;
		if (list.sizeList < 0)
			cout << "size list phai >0" << endl;
	} while (list.sizeList < 0);
	list.pSach = new Sach[list.sizeList];
	for (int i = 0; i < list.sizeList; i++) {
		cout << "doi tuong " << i << ": " << endl;
		is >> *(list.pSach + i);
	}
	return is;
}

int List::getSizeList() const {
	return sizeList;
}

int List::timkiemtheomasach(const string &masach) {
	for (int i = 0; i < sizeList; i++) {
		if (pSach[i].getMaSach() == masach)
			return i;
	}
	return -1;
}

bool tangdan(string left, string right) {
	return left.compare(right) > 0;
}

bool giamdan(string left, string right) {
	return left.compare(right) < 0;
}




