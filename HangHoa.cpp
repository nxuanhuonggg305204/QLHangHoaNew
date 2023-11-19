#include"HangHoa.h"

string HangHoa::getMH() { return maHang; }
void HangHoa::setMH(string MH) { maHang = MH; }

string HangHoa::getTH() { return tenHang; }
void HangHoa::setTH(string MH) { tenHang = MH; }

string HangHoa::getNSX() { return noiSanXuat; }
void HangHoa::setNSX(string MH) { noiSanXuat = MH; }

string HangHoa::getMS() { return mauSac; }
void HangHoa::setMS(string MH) { mauSac = MH; }

void HangHoa::setGB(int SL) { giaBan = SL; }
int HangHoa::getGB() { return giaBan; }

string HangHoa::getNNK() { return ngayNhapKho; }
void HangHoa::setNNK(string MH) { ngayNhapKho = MH; }

void HangHoa::setSL(int SL) { soLuong = SL; }
int HangHoa::getSL() { return soLuong; }

istream& operator >> (istream& is, HangHoa& a) 
{
	ofstream out("hanghoa.txt", ios::app);
    LinkedList<HangHoa> HHList;
	cout << "Nhap ma hang, ten hang, mau sac, gia ban, so luong\n";

	is >> a.maHang >> a.tenHang >> a.noiSanXuat >> a.mauSac >> a.giaBan >> a.ngayNhapKho >> a.soLuong;

	out << '\n' << a.maHang << '*' << a.tenHang << '*' << a.noiSanXuat
		<< '*' << a.mauSac << '*' << a.giaBan << '*'
		<< a.ngayNhapKho << '*' << a.soLuong;
	return is;
}

ostream& operator << (ostream& os, HangHoa a)
{
    os << a.getMH() << setw(5) << a.getTH() << setw(5) << a.getNSX() << setw(5) 
        << a.getMS() << setw(5) << a.getGB() << setw(5) << a.getNNK() << setw(5) 
        << a.getSL() << setw(5) << endl;
    return os;
}

void HangHoa::readListHH (LinkedList<HangHoa>& listHH)
{
    ifstream in("hanghoa.txt");
    HangHoa hh;
    string str;
    while (getline(in, str))
    {
        stringstream ss(str);
        getline(ss, str, '*'); hh.maHang = str;
        getline(ss, str, '*'); hh.tenHang = str;
        getline(ss, str, '*'); hh.noiSanXuat = str;
        getline(ss, str, '*'); hh.mauSac = str;
        getline(ss, str, '*'); hh.giaBan = stoi(str);
        getline(ss, str, '*'); hh.ngayNhapKho = str;
        getline(ss, str, '*'); hh.soLuong = stoi(str);
    }
}

void HangHoa::ofstreamListHH (ofstream file, LinkedList<HangHoa> listHH)
{
    Node<HangHoa>* p;
    for (p = listHH.getHead(); p != listHH.getTail(); p = p->getpNext())
        cout << p->getData() << endl;
}

void HangHoa::delete1LineHH (LinkedList<HangHoa>& listHH, string maHH)
{
    readListHH (listHH);
    Node<HangHoa>* p;
    ofstream out("temp.txt",ios_base::out);
    for (p = listHH.getHead(); p != listHH.getTail(); p = p->getpNext())
    {
        if (p->getData().maHang == maHH)
            listHH.searchDataAndRemove(p->getData());
    }
}