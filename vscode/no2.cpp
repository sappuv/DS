//CPP consider a student database of SEIT class. Database contains different fields of every student like Roll No, name and SGPA (Array of structure) Using bubble sort and linear Search

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10; 
struct Student {
  int roll_no;
  string name;
  float sgpa;
};

int main() {
  Student students[N];
  int n;
  cout << "Enter the number of students: ";
  cin >> n;
  cout << "Enter the student records:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Roll No: ";
    cin >> students[i].roll_no;
    cout << "Name: ";
    cin >> students[i].name;
    cout << "SGPA: ";
    cin >> students[i].sgpa;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (students[j].roll_no > students[j + 1].roll_no) {
        swap(students[j], students[j + 1]);
      }
    }
  }
  
  cout << "Enter the roll number of the student to search: ";
  int roll_no;
  cin >> roll_no;
  
  for (int i = 0; i < n; i++) {
    if (students[i].roll_no == roll_no) {
      cout << "Student found!" << endl;
      cout << "Roll No: " << students[i].roll_no << endl;
      cout << "Name: " << students[i].name << endl;
      cout << "SGPA: " << students[i].sgpa << endl;
      break;
    }
  }
  cout << "Student not found!" << endl;
  return 0;
}
