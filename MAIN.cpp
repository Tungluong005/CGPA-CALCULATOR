#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<map>
#include<algorithm>
#include<fstream>
#include<cmath>
#include<sstream>
#include<ctime>
 using namespace std;
 class semester;
// xay dung phan mon hoc
class subject{
  string name;
  int credits;
  float diem;
 float grade_points;
  string diem_chu;
public:
   void input();
   void output();
   friend class semester;
   friend void tong_GPA(semester &a);
};

void subject :: input(){ 
   cout << "Nhap ten mon hoc:";
   cin.ignore();
   getline(cin, name);
   cout << "Nhap so tin chi :";
   cin >> credits;
   cout << "Nhap diem la:";
   cin >> diem;
   if(diem >= 8.5 && diem <= 10){
      grade_points = 4;
      diem_chu = "A";
   }
   else if(diem >= 8 && diem <= 8.4){
      grade_points = 3.5;
      diem_chu = "B+";
   }
   else if(diem >=7.0 && diem <= 7.9){
       grade_points = 3.0;
       diem_chu = "B";
   }
   else if(diem >= 6.5 && diem <= 6.9){
      grade_points = 2.5;
      diem_chu = "C+";
   }
   else if(diem >= 5.5 && diem <= 5.9){
      grade_points = 2;
      diem_chu = "C";
   }
   else if(diem >= 5.0 && diem <= 5.4){
      grade_points = 1.5;
      diem_chu = "D+";
   }
   else if(diem >4.0 && diem <= 4.9){
      grade_points = 1;
      diem_chu = "D";
   }
    else{
      diem_chu = "F";
    }
}

void subject :: output(){
 cout << setw(15) << name << setw(15) << credits << setw(15) << diem << setw(15) << grade_points;
 cout << setw(15) << diem_chu << endl;
}

// Lop semester
class semester{
  subject *z;
  int n;
public:
   void nhap();
   void xuat();
   friend void tong_GPA(semester &a);
};

void semester :: nhap(){
   cout << "Nhap n la:";
   cin >> n;
   z = new subject[n];
   // Nhap so mon hoc trong 1 ky
   for(int i = 0; i < n; ++i){
     z[i].input();
   }
}

void semester :: xuat(){
  // in mon hoc ra man hinh
  for(int i = 0; i < n; ++i){
     z[i].output();
  }
}
// tinh diem GPA/Ky
void tong_GPA(semester &a){
 int sum = 0, S = 0;
 // Tinh tong tinh chi va tong diem 1 tinh chi 1 mon hoc
  for(int i = 0; i < a.n; ++i){
     sum += a.z[i].credits * a.z[i].grade_points;
     S += a.z[i].credits;
  }
float tb = (float)sum / S;
cout << setw(20) << "Diem GPA la:" << tb << endl;
}
int main(){
 string ten;
 cout << "Nhap ten la: ";
 getline(cin, ten);
semester Ky;
cout << "Nhap thong tin ky nay la:" << endl;
Ky.nhap();
cout << "\n";
cout << "\t\t" << "Bang diem Hoc ky: " << endl;
cout << setw(15) << "Mon hoc" << setw(15) << "So tin chi" << setw(15) << "Diem thi";
cout << setw(15) << "He 4" << setw(15) << "He chu " << endl;
Ky.xuat();
tong_GPA(Ky);



















   return 0;
}



 

