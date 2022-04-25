#pragma once
#include <string.h>
#include <cstring>
#include <ctime>
#include <vector>
#include <fstream>
#include <tuple>
#include <utility>

using namespace std;

class RandomIntegerGenerator
{
public:
    RandomIntegerGenerator();

public:
    static int next();
    static int next(int);
    static int next(int, int);
};

class Name
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _middleName;

public:
    string getFirstName()
    {
        return _firstName;
    }

    string getMiddleName()
    {
        return _middleName;
    }

    string getLastName()
    {
        return _lastName;
    }

    void setFirstName(string firstName)
    {
        _firstName = firstName;
    }

    void setLastName(string lastName)
    {
        _lastName = lastName;
    }

    void setMiddleName(string middleName)
    {
        _middleName = middleName;
    }

    Name() : _firstName(""), _lastName(""), _middleName(""){};
    Name(std::string lastName, std::string middleName, std::string firstName)
        : _lastName(lastName), _middleName(middleName), _firstName(firstName){};
};

class RandomNameListGenerator
{
private:
    vector<pair<string, float>> _sample_firstNames;
    vector<string> _sample_middleNames = {
        "Van",
        "Thi",
        "Tuong",
        "Phuc",
        "Hong",
        "Minh",
        "Hoang",
        "Viet",
        "Thuy",
        "Kieu",
        "Huy",
        "Lan",
        "Tuan",
        "Ngoc",
        "Phuong",
        "Anh",
        "Lam",
        "Thao",
        "Tan"};
    vector<pair<string, float>> _sample_lastNames;

    void getSampleFirstNames(const char *filename);
    void getSampleLastNames(const char *filename);

public:
    Name next();
    vector<Name> list_next();
};

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void setDay(int _day)
    {
        day = _day;
    }

    void setMonth(int _month)
    {
        month = _month;
    }

    void setYear(int _year)
    {
        year = _year;
    }

    Date(int day, int month, int year) : day(day), month(month), year(year){};
    Date() : day(1), month(1), year(1990){};

    Date getDate() const { return Date(day, month, year); }
};

class RandomDateListGenerator
{
public:
    Date next();
    vector<Date> list_next();
};

class Address
{
private:
    int house_number;
    std::string street;
    std::string ward;
    std::string district;

public:
    void setHouseNumber(int _house_number)
    {
        house_number = _house_number;
    }

    void setStreet(string _street)
    {
        street = _street;
    }

    void setWard(string _ward)
    {
        ward = _ward;
    }
    void setDistrict(string _district)
    {
        district = _district;
    }

    Address() : house_number(0), street(""), ward(""), district(""){};

    Address(int house_number, std::string street, std::string ward, std::string district)
        : house_number(house_number), street(street), ward(ward), district(district){};
};

class RandomAddressListGenerator
{
private:
    vector<int> _house_number;
    vector<string> _street;
    vector<string> _ward;
    vector<string> _district;

public:
    RandomAddressListGenerator();

    Address next();
    vector<Address> address_next();
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

    void setID(string id)
    {
        _id = id;
    }

    void setName(Name name)
    {
        _name = name;
    }

    void setGPA(double GPA)
    {
        _GPA = GPA;
    }
    void setTelephone(string telephone)
    {
        _telephone = telephone;
    }
    void setEmail(string email)
    {
        _email = email;
    }
    void setDOB(Date DOB)
    {
        _day_of_birth = DOB;
    }

    void setAddress(Address address)
    {
        _address = address;
    }
};

class StringHelper
{
    static vector<string> split(string source, string delimiter);
};

class MockStudentData
{
    // parse data from file to an array
public:
    static tuple<bool, int, string, vector<Student>> parse(const char *filename);

    // add n new random student to students list vector
    static bool createNewStudent(vector<Student> &students, int numberOfStudent);

    // write all student info to file
    static bool writeStudentInfo(string filename, vector<Student> &students);
};
