#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;

struct Student
{
    char*name;
    int age;
    char*id;
    double gpa;
};
void addStudent(vector<Student>&student, const Student& sv)
{
    student.push_back(sv);
}
void displayStudent(const vector<Student>& student)
{
    for(const auto&sv : student)
    {
        cout << "Name: " << sv.name << ", Age: "
            << sv.age << ", ID: " << sv.id
            << ", GPA: " << sv.gpa << endl;
    }
}
Student* findStudent(vector<Student> &student,const char*id)
{
    for(auto&sv:student)
    {
        if(strcmp(sv.id, id)==0)
        {
            return &sv;
        }
    }
    return NULL;
}
void sortStudentbyGPA(vector<Student>&student)
{
    size_t n= student.size();
    for(size_t i=0; i<n-1; i ++)
    {
        for(size_t j=0; j<n-i-1; j++)
        {
            if(student[j].gpa<student[j+1].gpa)
            {
                swap(student[j], student[j+1]);
            }
        }
    }
}
