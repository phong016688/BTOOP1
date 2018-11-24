#include <iostream>
#include "Sach.h"
#include "List.h"
#include <string>

using namespace std;


int main() {
	List list;
	int luachon;
	while (true) {
		cout <<"|----------------------------------------|" << endl
			<< "|   1:  Hien thi danh sach doi tuong     |" << endl
			<< "|   2:  Them doi tuong dau danh sach     |" << endl
			<< "|   3:  Them doi tuong cuoi danh sach    |" << endl
			<< "|   4:  Them doi tuong vi tri k          |" << endl
			<< "|   5:  Xoa doi tuong dau danh sach      |" << endl
			<< "|   6:  Xoa doi tuong cuoi danh sach     |" << endl
			<< "|   7:  Xoa doi tuong tai vi tri k       |" << endl
			<< "|   8:  Sap xep tang dan                 |" << endl
			<< "|   9:  Sap xep giam dan                 |" << endl
			<< "|   10: Nhap moi danh sach               |" << endl
			<< "|   11: Tim kiem theo thuoc tinh ma sach |" << endl
			<< "|   0:  Thoat                            |" << endl
			<< "|----------------------------------------|" << endl;
		do {
			cout << "nhap lua chon: ";
			cin >> luachon;
			if (luachon < 0 || luachon > 11)
				cout << " nhap lai lua chon" << endl;
		} while (luachon < 0 || luachon > 11);
		switch (luachon) {
		case 0:
			return 0;
		case 1:
			cout << "-----------danh sach doi tuong--------------" << endl;
			cout << list << endl;
			break;
		case 2: {
			cout << "-----------danh sach doi tuong sau khi them dau--------------" << endl;
			Sach sach_dau;
			cin >> sach_dau;
			list.themdau(sach_dau);
			cout << "-----------danh sach doi tuong sau khi them o vi tri k--------------" << endl;
			cout << list << endl;
			break;
		}
		case 3: {
			cout << "-----------danh sach doi tuong sau khi them cuoi--------------" << endl;
			cout << "nhap doi tuong muon them:" << endl;
			Sach sach_cuoi;
			cin >> sach_cuoi;
			list.themcuoi(sach_cuoi);
			cout << "-----------danh sach doi tuong sau khi them o vi tri k--------------" << endl;
			cout << list << endl;
			break;
		}
		case 4: {
			int k;
			Sach sach_k;
			do {
				cout << "nhap vi tri muon them:";
				cin >> k;
				if (k < 0 || k > list.getSizeList())
					cout << "vi tri phai >= 0 va <= " << list.getSizeList() << endl;
			} while (k < 0 || k > list.getSizeList());
			cout << "nhap doi tuong muon them:" << endl;
			cin >> sach_k;
			list.them(k, sach_k);
			cout << "-----------danh sach doi tuong sau khi them o vi tri k--------------" << endl;
			cout << list << endl;
			break;
		}
		case 5: {
			cout << "-----------danh sach doi tuong sau khi xoa dau--------------" << endl;
			list.xoadau();
			cout << list << endl;
			break;
		}
		case 6: {
			cout << "-----------danh sach doi tuong sau khi xoa cuoi--------------" << endl;
			list.xoacuoi();
			cout << list;
			break;
		}
		case 7: {
			int k;
			cout << "nhap vi tri muon xoa: ";
			cin >> k;
			list.xoa(k);
			cout << "-----------danh sach doi tuong sau khi xoa o vi tri k--------------" << endl;
			cout << list;
			break;
		}
		case 8: {
			list.sapxep(tangdan);
			cout << "-----------danh sach doi tuong sau khi sap xep--------------" << endl;
			cout << list;
			break;
		}
		case 9: {
			list.sapxep(giamdan);
			cout << "-----------danh sach doi tuong sau khi sap xep--------------" << endl;
			cout << list;
			break;
		}
		case 10: {
			cin >> list;
			cout << "-----------danh sach doi tuong sau khi sap nhap--------------" << endl;
			cout << list;
			break;
		}
		case 11: {
			Sach* ptr_sach ;
			string masach_timkiem;
			do {
				cout << "nhap vao ma sach ban muon tim kiem (9 ki tu):";
				cin >> masach_timkiem;
				if (masach_timkiem.size() != 9)
					cout << "ma sach phai co 9 ki tu" << endl;
				if ((masach_timkiem[0] - '0') <= 0 || (masach_timkiem[0] - '0') > 5)
					cout << "nhap lai so dau tu 1 -> 5" << endl;
			} while (masach_timkiem.size() != 9 || (masach_timkiem[0] - '0') <= 0 || (masach_timkiem[0] - '0') > 5);

			cout << "danh sach doi tuong co ma sach vua nhap la: " << endl;
			ptr_sach = list.timkiem(masach_timkiem); // con tro tro den mang doi tuong tim kiem dc
			if (ptr_sach == NULL) 
				cout << "khong co" << endl;
			break;
		}

		}
	}
}