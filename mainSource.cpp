//#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "HangHoa.h"

int main()
{
    system('cls');
    HangHoa hh;
    
    setColor(12);
	cout << "\n\n\n\n";
	cout << "\t\t\t*************************************************************************";
	cout << "\n\t\t\t*\t\t\t\t\t\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\tQUAN LY BAN HANG ONLINE\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\t\t\t\t\t\t\t*";
	cout << "\n\t\t\t*************************************************************************";
	cout << "\n\t\t\t*\t\t\t1. Hien thi thong tin don hang\t\t\t*";
	cout << "\n\t\t\t*\t\t\t2. Tim kiem thong tin don hang\t\t\t*";
	cout << "\n\t\t\t*\t\t\t3. Dat hang\t\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\t4. Dang nhap\t\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\t0. Exit\t\t\t\t\t\t*";
	cout << "\n\t\t\t*************************************************************************\n\n\n";
	setColor(9);
    
    cout << "Nhap lua chon cua ban: \n";
    char lc, c; //lc: lua chon
    string tkiem;
    
    int a;
    cin>>a;
    cout << a;
    return 0;
}
