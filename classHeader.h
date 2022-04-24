#pragma once
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include <fstream>
#include <tuple>

using namespace std;

class Name
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _middleName;

public:
    Name() : _firstName(""), _lastName(""), _middleName("") {};
    Name(std::string lastName, std::string middleName, std::string firstName)
        : _lastName(lastName), _middleName(middleName), _firstName(firstName) {};
};

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {};
    Date() : day(1), month(1), year(1990) {};
};

class Address
{
private:
    int house_number;
    std::string street;
    std::string ward;
    std::string district;

public:
    Address() : house_number(0), street(""), ward(""), district("") {};

    Address(int house_number, std::string street, std::string ward, std::string district)
        : house_number(house_number), street(street), ward(ward), district(district) {};
};

class Student
{
private:
    std::string _id;
    Name _name;
    double _GPA;
    std::string _telephone;
    std::string _email;
    Date _day_of_birth;
    Address _address;

public:
    Student() : _id(""), _name(Name()), _GPA(0), _telephone(""), _email(""), _day_of_birth(Date()), _address(Address()) {}
    Student(std::string id, Name name, double GPA, std::string telephone, std::string email, Date DOB, Address address)
    {
        _id = id;
        _name = name;
        _GPA = GPA;
        _telephone = telephone;
        _email = email;
        _day_of_birth = DOB;
        _address = address;
    }
};

class RandomNumber
{
    RandomNumber() { srand(time(0)); }
    static int random() { return rand(); }
    static int random(int max) { return rand() % max; }
    static int random(int min, int max) { return min + rand() % (max - min + 1); }
};

class StringHelper
{
    static vector<string> split(string source, string delimiter)
    {
        vector<string> result;
        int start = source.find(delimiter);

        while (start != string::npos)
        {
        }
    }
};

class MockStudentData
{
    // parse data from file to an array
    static tuple<bool, int, string, vector<Student>> parse(const char* filename)
    {

        /*errorCode:
        - 0: success
        - 1: file not exist or missing
        - 2 :
        */

        bool successful = true;
        int errorCode = 0;
        string message = "";
        vector<Student> students;

        fstream file(filename, ios::in | ios::out);

        if (!file.is_open())
        {
            errorCode = 1;
            message = "Read failed: cannot open " + string(filename);
        }
        else
        {
            while (!file.eof())
            {
                Student student;
                for (int i = 0; i < 7; i++)
                {
                    string temp;
                    getline(file, temp);
                    if (i == 0)
                    {
                        student._id = temp.substr(9, temp.length())
                    }
                    if (i == 1)
                    {
                        string temp1;
                        temp1 = temp.substr(7, temp.length());
                        temp1 = strtok(strdup(temp.c_str()), " ");
                        student._name._lastName = temp1;
                        temp1 = strtok(NULL, " ");
                        student._name._middleName = temp1;
                        temp1 = strtok(NULL, " ");
                        student._name._firstName = temp1;
                    }
                    if (i == 2)
                    {
                        student._GPA = temp.substr(6, temp.length())
                    }
                    if (i == 3)
                    {
                        student._telephone = temp.substr(12, temp.length())
                    }
                    if (i == 4)
                    {
                        student._email = temp.substr(8, temp.length())
                    }
                    if (i == 5)
                    {
                        string temp1;
                        temp1 = temp.substr(6, temp.length());
                        temp1 = strtok(strdup(temp.c_str()), "/");
                        student._day_of_birth.day = stoi(temp1);
                        temp1 = strtok(NULL, "/");
                        student._day_of_birth.month = stoi(temp1);
                        temp1 = strtok(NULL, "/");
                        student._day_of_birth.year = stoi(temp1);
                    }
                    if (i == 6)
                    {
                        string temp1;
                        temp1 = temp.substr(10, temp.length());
                        temp1 = strtok(strdup(temp.c_str()), " ");
                        student._day_of_birth.day = temp1;
                        temp1 = strtok(NULL, ",");
                        student._day_of_birth.month = temp1;
                        temp1 = strtok(NULL, ",");
                        student._day_of_birth.year = temp1;
                    }
                }

                students.push_back(student);
                // get
            }
        }

        auto result = make_tuple(successful, errorCode, message, students);
        return result;
    }

    // add n new random student to students list vector
    static bool createNewStudent(vector<Student>& students, int numberOfStudent)
    {
        return true;
    }

    // write all student info to file
    static bool writeStudentInfo(string filename, vector<Student>& students)
    {
        fstream f(filename, ios::out);

        return true;
    }
};
