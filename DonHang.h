#include "HangHoa.h"

class DonHang : public HangHoa
{
protected:
    string status = "dcb"; //dcb: đang chuẩn bị hàng
public:
    DonHang() {}
    void setStatus (string _status) { status = _status; }
    string getStatus () { return status; }
    void ofstreamFileDH (vector<DonHang>& listDH, ifstream fileIn, string line);
    vector<string> getAddressChar (string line );
    void changeListDHbyStr(vector<DonHang>& vecDH, string str, string choice);
    void changeListDHbyInt(vector<DonHang>& vecDH, string str, string choice);
    void delete1LineDH (vector<DonHang>& vecDH, string maHH, string choice);
    void ofstreamCompleteBillsDH(DonHang dh);
};

