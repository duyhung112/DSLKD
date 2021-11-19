#include<iostream>
using namespace std;

struct NodeInt
{
	int data;
	NodeInt* next;
};

struct SLList // Single Linked List
{
	NodeInt *head, *tail;
};

NodeInt* CreateNodeInt(int x);
void ShowNodeInt(NodeInt *p);
void XuLy_BtMau();
void Giai_Phong_SLList(SLList &list);
// ============================ Bai 1 ============================
void XuLy_Bai1();
void CreateSLList(SLList &list);
void AddHeadSLList(SLList &list, NodeInt* them);
//a
void AddTailSLList(SLList &list, NodeInt* them);
//b chèn x vào trước phần tử giá trị y
void Chen_X_Truoc_Y(SLList &list, NodeInt* x, int y);
//c xóa các phần tử lớn hơn x trong list
void Xoa_Node_Lon_Hon_X(SLList &list, int x);
//d xóa các phần tử chẵn
void Xoa_Node_Chan(SLList &list);
//e sắp xếp list tăng dần
void Swap_Int(int &x, int &y);
void Sap_SLList_Tang(SLList &list);
// f đếm số nguyên tố trong danh sách
int Kiem_Tra_SNT(int x);
int Dem_SNT_SLList(SLList list);
// g tính tổng các số chính phương
int Kiem_Tra_SCP(int x);
int Tinh_Tong_SCP_SLList(SLList list);
//h tìm phần tử nhỏ nhất
int Tim_Min_SLList(SLList list);
//i đếm phần tử lớn hơn gấp đôi phần tử phía sau
int Dem_Node_Lon_Gap_Doi_NodeSau(SLList list);
//j từ sl tạo 2 danh sách mới : sl1 chứa các số chẵn,sl2 chứa các số lẻ
void Chia_SLList(SLList list);
// ============================ Bai 2 ============================
void XuLy_Bai2();
//a
struct PhanSo
{
	int TuSo, MauSo;
};
struct NodePS
{
	PhanSo data;
	NodePS* next;
};
struct SLListPS
{
	NodePS *head, *tail;
};
NodePS* Create_PS(PhanSo x);
void Create_SLListPS(SLListPS &list);
void Giai_Phong_SLListPS(SLListPS &list);
//b
void AddHeadSLListPS(SLListPS &list, NodePS* them);
void AddTailSLListPS(SLListPS &list, NodePS* them);
void Nhap_1_PS(PhanSo &x);
void Xuat_1_PS(PhanSo x);
//c
int UCLN(int x, int y);
void Toi_Gian_SLListPS(SLListPS &list);
//d
PhanSo Tinh_Tong_SLListPS(SLListPS list);
PhanSo Tinh_Tich_SLListPS(SLListPS list);
//e
PhanSo Tim_PS_Min(SLListPS list);
PhanSo Tim_PS_Max(SLListPS list);
//f
void Tang_Moi_NodePS_1Dv(SLListPS &list);



int main()
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t ==================== MENU ====================";
		cout << "\n\t\t 1. Bai 1.";
		cout << "\n\t\t 2. Bai 2.";
		cout << "\n\t\t 3. Bai mau.";
		cout << "\n\t\t 0. Thoat.";
		cout << "\n\t\t\t ==================== END  ====================";
		cout << "\n\tNhap lua chon :";
		cin >> luachon;

		if (luachon == 1)
		{
			XuLy_Bai1();
		}
		else if (luachon == 2)
		{
			XuLy_Bai2();
		}
		else if (luachon == 3)
		{
			XuLy_BtMau();
		}
		else if (luachon == 0)
		{
			break;
		}
		else
		{
			cout << "\nVui long nhap cho chinh xac!\n";
			system("pause");
		}
	}
	return 0;
}

// ============================ Bai 2 ============================
void XuLy_Bai2()
{
	bool kt_vong_lap = true;
	int luachon;
	SLListPS list;
	Create_SLListPS(list);
	while (kt_vong_lap == true)
	{
		system("cls");
		cout << "\n\t\t\t ==================== MENU ====================";
		cout << "\n\t\t 1. Nhap n phan so."; // b
		cout << "\n\t\t 2. Xuat danh sach phan so.";//b
		cout << "\n\t\t 3. Toi gian cac phan so.";//c
		cout << "\n\t\t 4. Tinh tong va tich.";//d
		cout << "\n\t\t 5. Tim phan so lon va nho nhat";//e
		cout << "\n\t\t 0. Thoat.";
		cout << "\n\t\t\t ==================== END  ====================";
		cout << "\n\tNhap lua chon :";
		cin >> luachon;

		if (luachon == 1)
		{
			int n;
			do
			{
				cout << "\nNhap so luong phan so muon nhap :";
				cin >> n;
				if (n <= 0)
				{
					cout << "\nVui long nhap so luong nguyen duong!\n";
					system("pause");
				}
			} while (n <= 0);
			for (int i = 0; i < n; i++)
			{
				cout << "\t NHAP PHAN SO THU " << i + 1 << endl;
				PhanSo x;
				Nhap_1_PS(x);
				NodePS* p = Create_PS(x);
				AddTailSLListPS(list, p);
			}
		}
		else if (luachon == 2)
		{
			for (NodePS* k = list.head; k != NULL; k = k->next)
			{
				//cout << "\t" << k->data.TuSo << "/" << k->data.MauSo;
				Xuat_1_PS(k->data);
			}
			cout << endl;
			system("pause");
		}
		else if (luachon == 3)
		{
			if (list.head != NULL)
			{
				Toi_Gian_SLListPS(list);
				cout << "\nToi gian thanh cong.\n";
			}
			else cout << "\nDanh sach rong!\n";
			system("pause");
		}
		else if (luachon == 4)
		{
			if (list.head != NULL)
			{
				PhanSo kq = Tinh_Tong_SLListPS(list);
				cout << "\nTong cac phan so la " << kq.TuSo << "/" << kq.MauSo << endl;
				kq = Tinh_Tich_SLListPS(list);
				cout << "\nTich cac phan so la " << kq.TuSo << "/" << kq.MauSo << endl;
			}
			else cout << "\nDanh sach rong!\n";
			system("pause");
		}
		else if (luachon == 5)
		{
			if (list.head != NULL)
			{
				PhanSo kq = Tim_PS_Min(list);
				cout << "\nMin la " << kq.TuSo << "/" << kq.MauSo;
				kq = Tim_PS_Max(list);
				cout << "\nMax la " << kq.TuSo << "/" << kq.MauSo << endl;
			}
			else cout << "\nDanh sach rong!\n";
			system("pause");
		}
		else if (luachon == 0)
		{
			kt_vong_lap = false;
			Giai_Phong_SLListPS(list);
			break;
		}
		else
		{
			cout << "\nVui long nhap lua chon cho chinh xac!" << endl;
			system("pause");
		}

	}
}
//a
NodePS* Create_PS(PhanSo x)
{
	NodePS* p = new NodePS;
	p->next = NULL;
	p->data.TuSo = x.TuSo;
	p->data.MauSo = x.MauSo;
	return p;
}
void Create_SLListPS(SLListPS &list)
{
	list.head = NULL;
	list.tail = NULL;
}
void Giai_Phong_SLListPS(SLListPS &list)
{
	NodePS* node = list.head;
	while (node != NULL)
	{
		NodePS* p = node;
		node = node->next;
		delete p;
	}
}
//b
void AddHeadSLListPS(SLListPS &list, NodePS* them)
{
	if (them == NULL)
		return;
	if (list.head == NULL)
	{
		list.head = list.tail = them;
	}
	else
	{
		them->next = list.head;
		list.head = them;
	}
}
void AddTailSLListPS(SLListPS &list, NodePS* them)
{
	if (list.head == NULL)
	{
		list.head = list.tail = them;
	}
	else
	{
		list.tail->next = them;
		list.tail = them;
	}
}
void Nhap_1_PS(PhanSo &x)
{
	cout << "\nNhap tu so :";
	cin >> x.TuSo;
	do
	{
		cout << "\nNhap mau so :";
		cin >> x.MauSo;
		if (x.MauSo == 0)
		{
			cout << "\nVui long nhap mau so khac 0!\n";
			system("pause");
		}
	} while (x.MauSo == 0);
}
void Xuat_1_PS(PhanSo x)
{
	cout << "\t" << x.TuSo << "/" << x.MauSo;
}
//c
int UCLN(int x, int y)
{
	int a = abs(x);
	int b = abs(y);
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else if (a < b)
		{
			b -= a;
		}
	}
	return a;
}
void Toi_Gian_SLListPS(SLListPS &list)
{
	for (NodePS* k = list.head; k != NULL; k = k->next)
	{
		int uc = UCLN(k->data.TuSo, k->data.MauSo);
		k->data.TuSo /= uc;
		k->data.MauSo /= uc;
	}
}
//d
PhanSo Tinh_Tong_SLListPS(SLListPS list)
{
	PhanSo tong;
	tong.TuSo = 0;
	tong.MauSo = 1;
	for (NodePS* k = list.head; k != NULL; k = k->next)
	{
		tong.TuSo = (tong.TuSo*k->data.MauSo) + (k->data.TuSo*tong.MauSo);
		tong.MauSo = tong.MauSo*k->data.MauSo;
		int uc = UCLN(tong.MauSo, tong.TuSo);
		tong.TuSo /= uc;
		tong.MauSo /= uc;
	}
	return tong;
}
PhanSo Tinh_Tich_SLListPS(SLListPS list)
{
	PhanSo tich;
	tich.TuSo = 1;
	tich.MauSo = 1;
	for (NodePS* k = list.head; k != NULL; k = k->next)
	{
		tich.TuSo *= k->data.TuSo;
		tich.MauSo *= k->data.MauSo;
		int uc = UCLN(tich.TuSo, tich.MauSo);
		tich.TuSo /= uc;
		tich.MauSo /= uc;
	}
	return tich;
}
//e
PhanSo Tim_PS_Min(SLListPS list)
{
	PhanSo min = list.head->data;
	for (NodePS* k = list.head->next; k != NULL; k = k->next)
	{
		if ((min.TuSo * k->data.MauSo) > (k->data.TuSo * min.MauSo))
			min = k->data;
	}
	return min;
}
PhanSo Tim_PS_Max(SLListPS list)
{
	PhanSo max = list.head->data;
	for (NodePS* k = list.head->next; k != NULL; k = k->next)
	{
		if ((max.TuSo * k->data.MauSo) < (k->data.TuSo * max.MauSo))
			max = k->data;
	}
	return max;
}
//f
void Tang_Moi_NodePS_1Dv(SLListPS &list);






// ============================ Bai 1 ============================
void XuLy_Bai1()
{
	bool kt_vong_lap = true;
	int luachon;
	SLList list;
	CreateSLList(list);
	while (kt_vong_lap == true)
	{
		system("cls");
		cout << "\n\t\t\t ==================== MENU ====================";
		cout << "\n\t\t 1. Them 1 node."; // a
		cout << "\n\t\t 2. Xuat danh sach.";
		cout << "\n\t\t 3. Chen gia tri x vao truoc gia tri y.";//b
		cout << "\n\t\t 4. Xoa cac phan tu lon hon x.";//c
		cout << "\n\t\t 5. Xoa cac phan tu co gia tri chan.";//d
		cout << "\n\t\t 6. Sap danh sach tang dan.";//e
		cout << "\n\t\t 7. Dem so nguyen to trong danh sach.";//f
		cout << "\n\t\t 8. Tinh tong cac so chinh phuong.";//g
		cout << "\n\t\t 9. Tim min.";//h
		cout << "\n\t\t 10. Dem node lon hon gap doi node sau.";//i
		cout << "\n\t\t 11. Tao 2 danh sach moi sl1 va sl2.";//j
		cout << "\n\t\t 0. Thoat.";
		cout << "\n\t\t\t ==================== END  ====================";
		cout << "\n\tNhap lua chon :";
		cin >> luachon;

		if (luachon == 1)
		{
			int data;
			cout << "\nNhap gia tri muon tao :";
			cin >> data;
			NodeInt* p = CreateNodeInt(data);
			if (p != NULL)
			{
				AddTailSLList(list, p);
				cout << "\n\tThem node thanh cong." << endl;
			}
			else cout << "\n\tThem node khong thanh cong!" << endl;
			system("pause");
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t\t DANH SACH LIEN KET DON HIEN TAI\n";
			for (NodeInt* k = list.head; k != NULL; k = k->next)
				ShowNodeInt(k);
			cout << endl;
			system("pause");
		}
		else if (luachon == 3)
		{
			int data;
			cout << "\nNhap gia tri x :";
			cin >> data;
			NodeInt* p = CreateNodeInt(data);
			if (p != NULL)
			{
				int y;
				cout << "\nNhap gia tri y :";
				cin >> y;
				Chen_X_Truoc_Y(list, p, y);
			}
		}
		else if (luachon == 4)
		{
			int x;
			cout << "\nNhap gia tri x :";
			cin >> x;
			Xoa_Node_Lon_Hon_X(list, x);
		}
		else if (luachon == 5)
		{
			Xoa_Node_Chan(list);
		}
		else if (luachon == 6)
		{
			if (list.head != NULL)
			{
				Sap_SLList_Tang(list);
				cout << "\n\t\t DANH SACH LIEN KET DON SAU KHI SAP TANG DAN\n";
				for (NodeInt* k = list.head; k != NULL; k = k->next)
					ShowNodeInt(k);
				cout << endl;
			}
			else cout << "\nDanh sach rong!\n";
			system("pause");
		}
		else if (luachon == 7)
		{
			int kq = Dem_SNT_SLList(list);
			if (kq == 0)
			{
				cout << "\nDanh sach khong co phan tu!\n";
			}
			else cout << "\nDanh sach co " << kq << " SNT\n";
			system("pause");
		}
		else if (luachon == 8)
		{
			int kq = Tinh_Tong_SCP_SLList(list);
			cout << "\nTong so chinh phuong la " << kq << endl;
			system("pause");
		}
		else if (luachon == 9)
		{
			if (list.head != NULL)
			{
				int kq = Tim_Min_SLList(list);
				cout << "\nMin co gia tri la " << kq << endl;
			}
			else cout << "\nDanh sach dang rong!\n";
			system("pause");
		}
		else if (luachon == 10)
		{
			int kq = Dem_Node_Lon_Gap_Doi_NodeSau(list);
			if (kq == 0)
			{
				cout << "\nDanh sach khong co node lon hon gap doi node sau!\n";
			}
			else cout << "\nDanh sach co " << kq << " node lon hon gap doi node sau.\n";
			system("pause");
		}
		else if (luachon == 11)
		{
			Chia_SLList(list);
		}
		else if (luachon == 0)
		{
			kt_vong_lap = false;
			Giai_Phong_SLList(list);
			break;
		}
		else
		{
			cout << "\nVui long nhap lua chon cho chinh xac!" << endl;
			system("pause");
		}

	}
}
void CreateSLList(SLList &list)
{
	list.head = NULL;
	list.tail = NULL;
}
void AddHeadSLList(SLList &list, NodeInt* them)
{
	if (them == NULL)
		return;
	if (list.head == NULL)
	{
		list.head = list.tail = them;
	}
	else
	{
		them->next = list.head;
		list.head = them;
	}
}
//a
void AddTailSLList(SLList &list, NodeInt* them)
{
	if (list.head == NULL)
	{
		list.head = list.tail = them;
	}
	else
	{
		list.tail->next = them;
		list.tail = them;
	}
}
//b chèn x vào trước phần tử giá trị y
void Chen_X_Truoc_Y(SLList &list, NodeInt* x, int y)
{
	if (list.head->data == y)
	{
		/*x->next = list.head;
		list.head = x;*/
		AddHeadSLList(list, x);
	}
	else
	{
		NodeInt* tam = list.head;
		for (NodeInt* k = list.head; k != NULL; k = k->next)
		{
			if (k->data == y)
			{
				tam->next = x;
				x->next = k;
				return;
			}
			tam = k;
		}
	}
}
//c xóa các phần tử lớn hơn x trong list
void Xoa_Node_Lon_Hon_X(SLList &list, int x)
{
	while (list.head != NULL)
	{
		if (list.head->data > x)
		{
			NodeInt* p = list.head;
			list.head = list.head->next;
			delete p;
		}
		else break;
	}
	NodeInt* tam = list.head;
	for (NodeInt* k = list.head; k != NULL; k = k->next)
	{
		if (k->data > x)
		{
			NodeInt* p = k;
			tam->next = k->next;
			delete p;
			k = tam;
		}
		tam = k;
	}
}
//d xóa phần tử chẵn
void Xoa_Node_Chan(SLList &list)
{
	while (list.head != NULL)
	{
		if (list.head->data % 2 == 0)
		{
			NodeInt* p = list.head;
			list.head = list.head->next;
			delete p;
		}
		else break;
	}
	NodeInt* tam = list.head;
	for (NodeInt* k = list.head; k != NULL; k = k->next)
	{
		if (k->data % 2 == 0)
		{
			NodeInt* p = k;
			tam->next = k->next;
			delete p;
			k = tam;
		}
		tam = k;
	}
}
//e sắp xếp list tăng dần
void Swap_Int(int &x, int &y)
{
	int tam = x;
	x = y;
	y = tam;
}
void Sap_SLList_Tang(SLList &list)
{
	for (NodeInt* k = list.head; k != NULL; k = k->next)
	{
		for (NodeInt* h = k->next; h != NULL; h = h->next)
		{
			if (k->data > h->data)
			{
				Swap_Int(k->data, h->data);
			}
		}
	}
}
// f đếm số nguyên tố trong danh sách
int Kiem_Tra_SNT(int x)
{
	if (x < 2)
		return 0;
	for (int i = 2; i <= (int)sqrt((float)x); i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}
int Dem_SNT_SLList(SLList list)
{
	int dem = 0;
	for (NodeInt* k = list.head; k != NULL; k = k->next)
	{
		if (Kiem_Tra_SNT(k->data) == 1)
			dem++;
	}
	return dem;
}
// g tính tổng các số chính phương
int Kiem_Tra_SCP(int x)
{
	float tam = sqrt((float)x);
	if (tam == (int)tam)
		return 1;
	return 0;
}
int Tinh_Tong_SCP_SLList(SLList list)
{
	int tong = 0;
	for (NodeInt* k = list.head; k != NULL; k = k->next)
	{
		if (Kiem_Tra_SCP(k->data) == 1)
			tong += k->data;
	}
	return tong;
}
//h tìm phần tử nhỏ nhất
int Tim_Min_SLList(SLList list)
{
	int min = list.head->data;
	for (NodeInt* k = list.head->next; k != NULL; k = k->next)
	{
		if (min > k->data)
			min = k->data;
	}
	return min;
}
//i đếm phần tử lớn hơn gấp đôi phần tử phía sau
int Dem_Node_Lon_Gap_Doi_NodeSau(SLList list)
{
	int dem = 0;
	for (NodeInt* k = list.head; k != list.tail; k = k->next)
	{
		if (k->next != NULL)
		{
			int tam = k->next->data;
			if (k->data > (2 * tam))
				dem++;
		}
	}
	return dem;
}
//j từ sl tạo 2 danh sách mới : sl1 chứa các số chẵn,sl2 chứa các số lẻ
void Chia_SLList(SLList list)
{
	if (list.head == NULL)
		return;
	SLList sl1, sl2;
	CreateSLList(sl1);
	CreateSLList(sl2);
	for (NodeInt* k = list.head; k != NULL; k = k->next)
	{
		NodeInt* tam = CreateNodeInt(k->data);
		if (k->data % 2 == 0)
		{
			AddTailSLList(sl1, tam);
		}
		else if (k->data % 2 != 0)
		{
			AddTailSLList(sl2, tam);
		}
	}
	if (sl1.head != NULL)
	{
		cout << "\n\t\t DANH SACH NODE CHAN\n";
		for (NodeInt* k = sl1.head; k != NULL; k = k->next)
		{
			cout << "\t" << k->data;
		}
	}
	else cout << "\nKhong co phan tu chan!\n";
	if (sl2.head != NULL)
	{
		cout << "\n\t\t DANH SACH NODE LE\n";
		for (NodeInt* k = sl2.head; k != NULL; k = k->next)
		{
			cout << "\t" << k->data;
		}
	}
	else cout << "\nKhong co phan tu le!\n";
	cout << endl;
	system("pause");
}





//====================================================
void XuLy_BtMau()
{
	bool kt_vong_lap = true;
	int luachon;
	NodeInt* p = new NodeInt;
	while (kt_vong_lap == true)
	{
		system("cls");
		cout << "\n\t\t\t ==================== MENU ====================";
		cout << "\n\t\t 1. Tao 1 node";
		cout << "\n\t\t 2. Hien thi 1 node";
		cout << "\n\t\t 0. Thoat.";
		cout << "\n\t\t\t ==================== END  ====================";
		cout << "\n\tNhap lua chon :";
		cin >> luachon;

		if (luachon == 1)
		{
			int data;
			cout << "\nNhap gia tri muon tao :";
			cin >> data;
			p = CreateNodeInt(data);
			if (p != NULL)
				cout << "\n\tTao node thanh cong." << endl;
			else cout << "\n\tTao node khong thanh cong!" << endl;
			system("pause");
		}
		else if (luachon == 2)
		{
			ShowNodeInt(p);

			system("pause");
		}
		else if (luachon == 0)
		{
			kt_vong_lap = false;
			break;
		}
		else
		{
			cout << "\nVui long nhap lua chon cho chinh xac!" << endl;
			system("pause");
		}

	}
}
void Giai_Phong_SLList(SLList &list)
{
	NodeInt* node = list.head;
	while (node != NULL)
	{
		NodeInt* p = node;
		node = node->next;
		delete p;
	}
}

NodeInt* CreateNodeInt(int x)
{
	NodeInt* p = new NodeInt;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!" << endl;
		system("pause");
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void ShowNodeInt(NodeInt *p)
{
	cout << "\t" << p->data;
}

