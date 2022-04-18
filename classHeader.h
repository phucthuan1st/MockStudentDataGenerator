#pragma once
#include <string>
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
    Name() : _firstName(""), _lastName(""), _middleName(""){};
    Name(std::string lastName, std::string middleName, std::string firstName)
        : _lastName(lastName), _middleName(middleName), _firstName(firstName){};
};

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year) : day(day), month(month), year(year){};
    Date() : day(1), month(1), year(1990){};
};

class Address
{
private:
    int house_number;
    std::string street;
    std::string ward;
    std::string district;

public:
    Address() : house_number(0), street(""), ward(""), district(""){};

    Address(int house_number, std::string street, std::string ward, std::string district)
        : house_number(house_number), street(street), ward(ward), district(district){};
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
};

class MockStudentData
{
    // parse data from file to an array
    static tuple<bool, int, string, vector<Student>> parse(const char *filename)
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
                string temp;
                getline(file, temp);
            }
        }

        auto result = make_tuple(successful, errorCode, message, students);
        return result;
    }
};
