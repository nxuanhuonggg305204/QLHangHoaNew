#include "LinkedList.h"

class HangHoa
{
protected:
    string maHang, tenHang, noiSanXuat, mauSac, ngayNhapKho;
	int giaBan, soLuong;
public:
    string getMH();
    void setMH(string MH);
    string getTH();
    void setTH(string MH);
    string getNSX();
    void setMS(string MH);
    string getMS();
    void setNSX(string MH);
    int getGB();
    void setGB(int SL);
    string getNNK();
    void setNNK(string MH);
    int getSL();
    void setSL(int SL);
    friend istream& operator >> (istream& is, HangHoa& a);
    friend ostream& operator << (ostream& is, HangHoa a);
    void readListHH (LinkedList<HangHoa>& listHH);
    void delete1LineHH (LinkedList<HangHoa>& listHH, string maHH);
    void ofstreamListHH (ofstream file, LinkedList<HangHoa> listHH);
};