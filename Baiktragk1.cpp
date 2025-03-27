#include <iostream>
using namespace std;

struct Vdv {
  string tdv;
  float tt;
  Vdv* next;
};

Vdv* taovdv(string s, float t) {
    Vdv* newvdv = new Vdv();
    newvdv->tdv = s;
    newvdv->tt = t;
    newvdv->next = NULL;
    return newvdv;
}

void themvdv(Vdv* &vdv, string s, float t) {
    if(vdv == NULL) vdv = taovdv(s, t);
    else {
        Vdv* newvdv = taovdv(s, t);
        Vdv* tmp = vdv;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newvdv;
    }
}

void indsvdv(Vdv* vdv) {
	cout << "Danh sach cac van dong vien:" << endl;
	while(vdv != NULL) {
		cout << vdv->tdv << " " << vdv->tt << endl;
		vdv = vdv->next;
	}
	cout << endl;
}

void intthon10(Vdv* vdv) {
    cout << "Nhung van dong vien co thanh tich chay >= 10:" << endl;
    while(vdv != NULL) {
        if(vdv->tt >= 10) {
            cout << vdv->tdv << " " << vdv->tt << endl;
            vdv = vdv->next;
        }
        else vdv = vdv->next;
    }
    cout << endl;
}

void invdv(Vdv* vdv) {
    while(vdv != NULL) {
        cout << vdv->tdv << " " << vdv->tt << " " << endl;
        vdv = vdv->next;
    }
}

Vdv* timvdv(Vdv* vdv, string x) {
    while(vdv != NULL) {
        if(vdv->tdv == x) {
            return vdv;
        }
        else vdv = vdv->next;
    }
    return NULL;
}

Vdv* timtttotnhat(Vdv* vdv) {
	Vdv* result = vdv;
	while(vdv->next != NULL) {
		if(vdv->tt < vdv->next->tt) {
			result = vdv;
			vdv = vdv->next;
		}
		else vdv = vdv->next;
	}
	return result;
}

Vdv* vdvttbangkhong(Vdv* &vdv) {
	Vdv* result = NULL;
	Vdv* tmp = vdv;
	Vdv* tmp1 = NULL;
	if(vdv == NULL) return NULL;
	else {
		while(tmp != NULL) {
			if(tmp->tt == 0) {
				themvdv(result, tmp->tdv, tmp->tt);
				tmp = tmp->next;
			}
			else {
				if(tmp->tt > 0) {
					tmp = tmp->next;
				}
				else {
					tmp = tmp->next;
				}
			}
		}
	}
	return result;
}
int main()
{
    Vdv* vdv = NULL;
    themvdv(vdv, "Bui Ngoc Toan", 7.7);
    themvdv(vdv, "Le Quoc Cuong", 0);
    themvdv(vdv, "Tran Thanh Cuong", 0);
    themvdv(vdv, "Huynh Ngoc Khang", 11.7);
    themvdv(vdv, "Nguyen Khanh Duong", 5.2);
    themvdv(vdv, "Vo Nguyen Thanh Tin", 12.5);
    indsvdv(vdv);
    intthon10(vdv);
    Vdv* newvdv = timvdv(vdv, "Nguyen Van A");
    if(newvdv != NULL) {
        cout << newvdv-> tdv << " " << newvdv->tt;
    }
    else cout << "Khong tim thay van dong vien nao ten Nguyen Van A" << endl;
    cout << endl;
    Vdv* newvdv1 = timtttotnhat(vdv);
    if(newvdv1 != NULL) {
    	cout << "Van dong vien co thanh tich chay tot nhat: " << newvdv1->tdv << " " << newvdv1->tt << endl; 
	}
	else cout << "Khong tim thay thanh tich chay tot nha cua cac vdv" << endl;
	cout << "Day la danh sach vdv khi chua xoa vdv co thanh tich = 0" << endl;
	indsvdv(vdv);
	cout << "Day la danh sach vdv khi da xoa nhung vdv co thanh tich = 0" << endl;
	indsvdv(vdv);
	cout << "Day la danh sach cac vdv co thanh tich = 0:" << endl;
	Vdv* newvdv2 = vdvttbangkhong(vdv);
	if(newvdv2 != NULL) {
		while(newvdv2 != NULL) {
			cout << newvdv2->tdv << " " << newvdv2->tt << endl;
			newvdv2 = newvdv2->next;
		} 
	}
	else cout << "Khong co van dong vien nao co thanh tich bang 0";
    return 0;
}
