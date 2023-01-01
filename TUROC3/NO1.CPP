// CPP consider a student database of SEIT class. Database contains different fields of every student like Roll No, name and SGPA (Array of structure) Using insertion sort and Binary Search

#include <iostream.h>
#include <conio.h>
const int N = 10;
struct Student
{
  int roll_no;
  char name[10];
  float sgpa;
};
compare(Student a, Student b)
{
  return a.sgpa > b.sgpa;
}

int main()
{
  clrscr();
  Student students[N];
  int n;
  cout << "Enter the number of students: ";
  cin >> n;
  cout << "Enter the student records:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Roll No: ";
    cin >> students[i].roll_no;
    cout << "Name: ";
    cin >> students[i].name;
    cout << "SGPA: ";
    cin >> students[i].sgpa;
  }
  for (int l = 1; l < n; l++)
  {
    Student key = students[l];
    int j = l - 1;
    while (j >= 0 && compare(key, students[j]))
    {
      students[j + 1] = students[j];
      j--;
    }
    students[j + 1] = key;
  }

  cout << "Enter the roll number of the student to search: ";
  int roll_no;
  cin >> roll_no;

  int left = 0, right = n - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (students[mid].roll_no == roll_no)
    {
      cout << "Student found!" << endl;
      cout << "Roll No: " << students[mid].roll_no << endl;
      cout << "Name: " << students[mid].name << endl;
      cout << "SGPA: " << students[mid].sgpa << endl;
      break;
    }
    else if (students[mid].roll_no < roll_no)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  if (left > right)
  {
    cout << "Student not found!" << endl;
  }
  getch();
  return 0;
}
