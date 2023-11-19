
#include "DonHang.h"

void DonHang::ofstreamFileDH(vector<DonHang>& listDH, ifstream fileIn, string line)
{
    ofstream out("donhang.txt", ios_base::app);
    DonHang dh;
    string str;
    while(getline(fileIn, str))
    {
        stringstream ss1(str);
        getline(ss1, str, '*'); dh.maHang = str;
        stringstream ss2(line);
        while (ss2 >> str)
        {
            if (str == dh.maHang)
            {
                getline(ss1, str, '*'); dh.tenHang = str;
                getline(ss1, str, '*'); dh.noiSanXuat = str;
                getline(ss1, str, '*'); dh.mauSac = str;
                getline(ss1, str, '*'); dh.giaBan = stoi(str);
                getline(ss1, str, '*'); dh.ngayNhapKho = str;
                getline(ss1, str, '*'); dh.maHang = stoi(str);
                listDH.push_back(dh);
            }
        }
    }
    for (auto x : listDH)
    {
        out << x.maHang << "*" << x.tenHang << "*" << x.noiSanXuat << "*" 
            << x.mauSac << "*" << x.giaBan << "*" << x.ngayNhapKho << "*" 
            << x.soLuong << "*" << x.status << endl;
    }
}

vector<string> DonHang::getAddressChar(string line)
{
    vector<string> vecAddress;
    for (int i=0; i<line.length(); i++)
        if (line[i] == '*')
            vecAddress.push_back(&line[i]);
}

//choice: maHH or giaBan or status
void DonHang::changeListDHbyStr(vector<DonHang>& vecDH, string str, string choice)
{
    if (choice == "maHH")
    {
        cout << "Nhap ma hang moi: ";
        string _newData; cin >> _newData;
        for (auto x : vecDH)
            if (x.maHang == str)
            {
                x.maHang = _newData;
                break;
            }
        cout << "Da thay doi ma hang thanh cong";
    }
    else if (choice == "tenHH")
    {
        cout << "Nhap ten hang moi: ";
        string _newData; cin >> _newData;
        for (auto x : vecDH)
            if (x.maHang == str)
            {
                x.tenHang = _newData;
                break;
            }
        cout << "Da thay doi ten hang thanh cong";
    }
    else if (choice == "mauSac")
    {
        cout << "Thay doi mau sac mat hang thanh: ";
        string _newData; cin >> _newData;
        for (auto x : vecDH)
            if (x.maHang == str)
            {
                x.mauSac = _newData;
                break;
            }
        cout << "Da thay doi mau sac mat hang thanh cong";
    }
    else if (choice == "status")
    {
        cout << "Cap nhat tinh trang don hang: ";
        string _newData; cin >> _newData;
        for (auto x : vecDH)
            if (x.maHang == str)
            {
                x.status = _newData;
                break;
            }
        cout << "Da cap nhat tinh trang thanh cong";
    }
}

//choice: soLuong or giaBan
void DonHang::changeListDHbyInt(vector<DonHang>& vecDH, string str, string choice)
{
    if (choice == "soLuong")
    {
        cout << ""
    }
}

void DonHang::ofstreamCompleteBillsDH(DonHang dh)
{
    ofstream out("completed.txt", ios_base::app);
    out << dh << endl;
    out.close();
}

void DonHang::delete1LineDH (vector<DonHang>& vecDH, string maHH, string choice)
{
    vector<DonHang>::iterator it;
    for (it = vecDH.begin(); it != vecDH.end(); ++it)
        if (it->maHang == maHH)
            break;
    if (choice == "ht") // ht: hoàn thành
        ofstreamCompleteBillsDH(*it);
    vecDH.erase (remove(vecDH.begin(), vecDH.end(), *it));
    ofstream newFileOut("temp.txt", ios_base::app);
    for (auto x : vecDH)
        newFileOut << x << endl;
    rename("temp.txt", "donhang.txt");
    newFileOut.close();
}

