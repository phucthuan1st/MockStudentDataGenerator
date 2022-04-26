#pragma once
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
#include <tuple>
#include <utility>
#include <memory>

using namespace std;

class RandomIntegerGenerator
{
private:
    static shared_ptr<RandomIntegerGenerator> _instance;

public:
    RandomIntegerGenerator();
    static int next();
    static int next(int);
    static int next(int, int);

    static shared_ptr<RandomIntegerGenerator> instance();
};

class Name
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _middleName;

public:
    string getFirstName() { return _firstName; }

    string getMiddleName() { return _middleName; }

    string getLastName() { return _lastName; }

    void setFirstName(string firstName) { _firstName = firstName; };

    void setLastName(string lastName) { _lastName = lastName; }

    void setMiddleName(string middleName) { _middleName = middleName; }

    Name() : _firstName(""), _lastName(""), _middleName(""){};
    Name(std::string lastName, std::string middleName, std::string firstName)
        : _lastName(lastName), _middleName(middleName), _firstName(firstName){};
};

class RandomNameGenerator
{
private:
    static vector<pair<string, int>> _sample_firstNames;
    static vector<string> _sample_middleNames;
    static vector<pair<string, int>> _sample_lastNames;

    static void getSampleFirstNames(string filename);
    static void getSampleLastNames(string filename);

    static shared_ptr<RandomNameGenerator> _instance;

public:
    RandomNameGenerator();
    static shared_ptr<RandomNameGenerator> instance();
    static Name next();
};

class Date
{
private:
    int _day;
    int _month;
    int _year;

public:
    void setDay(int _day) { _day = _day; }

    void setMonth(int _month) { _month = _month; }

    void setYear(int _year) { _year = _year; }

    Date(int day, int month, int year) : _day(day), _month(month), _year(year){};
    Date() : _day(1), _month(1), _year(1990){};

    int day() const { return _day; }
    int month() const { return _month; }
    int year() const { return _year; }
};

class RandomDateGenerator
{
public:
    static Date next();
};

class Address
{
private:
    int house_number;
    std::string street;
    std::string ward;
    std::string district;

public:
    void setHouseNumber(int _house_number) { house_number = _house_number; }

    void setStreet(string _street) { street = _street; }

    void setWard(string _ward) { ward = _ward; }
    void setDistrict(string _district) { district = _district; }

    Address() : house_number(0), street(""), ward(""), district(""){};

    Address(int house_number, std::string street, std::string ward, std::string district)
        : house_number(house_number), street(street), ward(ward), district(district){};

    string Street() { return street; }
    string Ward() { return ward; }
    string District() { return district; }
    int houseNumber() { return house_number; }
};

class RandomAddressGenerator
{
private:
    static vector<int> _house_number;
    static vector<string> _sample_street;
    static vector<string> _sample_ward;
    static vector<string> _sample_district;

    RandomAddressGenerator();

public:
    static Address next();
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

    void setID(string id) { _id = id; }

    void setName(Name name) { _name = name; }

    void setGPA(double GPA) { _GPA = GPA; }

    void setTelephone(string telephone) { _telephone = telephone; }

    void setEmail(string email) { _email = email; }

    void setDOB(Date DOB) { _day_of_birth = DOB; }

    void setAddress(Address address) { _address = address; }

    string id() { return _id; }
    Name name() { return _name; }
    double gpa() { return _GPA; }
    string telephone() { return _telephone; }
    string email() { return _email; }
    Date dateOfBirth() { return _day_of_birth; }
    Address address() { return _address; }
};

class StringUtils
{
public:
    static vector<string> split(string source, string delimiter);
    static string to_String(Name name);
    static string to_String(Date date);
    static string to_String(Address address);
};

class RandomSimpleInfo
{
public:
    static string nextTelephoneNumber();
    static double nextGPA();
    static string nextEmail(Name);
    static string nextID();
};

class MockStudentData
{
public:
    // parse data from file to an array
    static vector<Student> parse(string filename);

    // add n new random student to students list vector
    static bool createNewStudent(vector<Student> &students, int numberOfStudent);

    // write all student info to file
    static bool writeStudentInfo(string filename, vector<Student> &students);
};

class StudentProcessor
{
public:
    static double averageGPA(vector<Student> &students);
    static vector<Student> findAboveAverageStudent(vector<Student> &students);
    static void printStudentList(vector<Student> &students);
};

class ProgramExecution
{
public:
    static int main();

private:
    static void option_one(vector<Student> &);
    static void option_two(vector<Student> &);
    static void option_three(vector<Student> &);
};
