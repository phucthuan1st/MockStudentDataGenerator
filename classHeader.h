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

    Date(int day, int month, int year) : day(day), month(month), year(year) {};
    Date() : day(1), month(1), year(1990) {};

    
};

class RandomIntegerGenerator {
public:
    RandomIntegerGenerator();
public:
    int next();
    int next(int);
    int next(int, int);
};

RandomIntegerGenerator::RandomIntegerGenerator() {
    srand(time(NULL));
}

int RandomIntegerGenerator::next() {
    int result = rand();
    return result;
}

int RandomIntegerGenerator::next(int ceiling) {
    int result = rand() % ceiling;
    return result;
}

int RandomIntegerGenerator::next(int left, int right) {
    int result = rand() % (left - right + 1) + left;
    return result;
}

class RandomDateListGenerator
{
private:
    vector<string> _days;
    vector<string> _months;
    vector<string> _years;
    RandomIntegerGenerator _rdg;

public:
    

    Date next();
};

Date RandomDateListGenerator::next() {

    int month = _rdg.next(1, 12);

    int day = 31;



    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        day = _rdg.next(1, 30);
    }

    if (month == 2)
    {
        while (day == 31 || day == 30) {
            day = _rdg.next(1, 28);
        }
    }


    int year = _rdg.next(1990,2022);

    Date result(day, month, year);
    return result;
}

class Address
{
private:
    int house_number;
    std::string street;
    std::string ward;
    std::string district;

public:

    void setHouseNumber(int _house_number) {
        house_number = _house_number;
    }

    void setStreet(string _street) {
        street = _street;
    }

    void setWard(string _ward) {
        ward = _ward;
    }
    void setDistrict(string _district) {
        district = _district;
    }

    Address() : house_number(0), street(""), ward(""), district("") {};

    Address(int house_number, std::string street, std::string ward, std::string district)
        : house_number(house_number), street(street), ward(ward), district(district) {};
};

class RandomAddressListGenerator
{
private:
    vector<int> _house_number;
    vector<string> _street;
    vector<string> _ward;
    vector<string> _district;

    RandomIntegerGenerator _rdg;

public:
    RandomAddressListGenerator();

    Address next();
};

RandomAddressListGenerator::RandomAddressListGenerator()
{
    _ward = { "An Khanh","An Loi Dong","An Phu","Binh Chieu","Binh Tho","Binh Trung Đong","Binh Trung Tay","Cat Lai","Hiep Binh Chanh","Ben Nghe", "Cau Kho", "Cau ong Lanh", "Ben Thanh", "Ca Giang", "Da Kao", "Nguyen Thai Binh", "Pham Ngu Lao", "Nguyen Cu Trinh", "Tan Dinh", "Phuong 1", "Phuong 2", "Phuong 3", "Phuong 4", "Phuong 5", "Phuong Binh Thuan", "Phuong Phu My", "Phuong Phu Thuan", "Phuong Tan Hung", "Phuong Tan Kieng", "An Phu Dong", "Dong Hung Thuan", "Hiep Thanh", "Tan Chanh Hiep", "Tan Hung Thuan", "An Lac", "Binh Hung Hoa", "Binh Tri Dong", "Phuong Hiep Tan", "Phuong Hoa Thanh", "Phuong Phu Thanh", "Phuong Phu Tho Hoa", "Phuong Phu Trung", "Xa Pham Van Hai", "Xa Binh Loi", "Xa An Thoi Dong", "Xa Binh Khanh", "Xa An Phu", "Xa An Nhon Tay", "Xa Dong Hanh", "Xa Nhi Binh", "Xa Tan Hung","Xa My Luong"};
    _district = {"Thanh pho Thu Duc", "Quan 1", "Quan 3", "Quan 4", "Quan 5", "Quan 6", "Quan 7", "Quan 8", "Quan 10", "Quan 11", "Quan 12", "Quan Binh Tan", "Quan Binh Thanh", "Quan Go Vap", "Quan Phu Nhuan", "Quận Tan Binh", "Quan Tan Phu", "Huyen Binh Chanh", "Huyen Can Gio", "Huyen Cu Chi", "Huyen Hoc Mon", "Huyen Nha Be"};
}

Address RandomAddressListGenerator::next() {

    int index = _rdg.next(_district.size());
    string district = _district[index];
    string ward = "";


    if (district == "Thanh pho Thu Duc")
    {
        int index = _rdg.next(0, 8);
        ward = _ward[index];
    }
    else if (district == "Quan 1")
    {
        int index = _rdg.next(9, 18);
        ward = _ward[index];
    }
    else if (district == "Quan 3")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 4")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 5")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 6")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 7")
    {
        int index = _rdg.next(24, 28);
        ward = _ward[index];
    }
    else if (district == "Quan 8")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 10")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 11")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 12")
    {
        int index = _rdg.next(29, 33);
        ward = _ward[index];
    }
    else if (district == "Quan Binh Tan")
    {
        int index = _rdg.next(34, 36);
        ward = _ward[index];
    }
    else if (district == "Quan Binh Thanh")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan Go Vap")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan Phu Nhuan")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan Tan Binh")
    {
        int index = _rdg.next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan Tan Phu")
    {
        int index = _rdg.next(37, 41);
        ward = _ward[index];
    }
    else if (district == "Quan Binh Chanh")
    {
        int index = _rdg.next(42, 43);
        ward = _ward[index];
    }
    else if (district == "Quan Can Gio")
    {
        int index = _rdg.next(44, 45);
        ward = _ward[index];
    }
    else if (district == "Quan Cu Chi")
    {
        int index = _rdg.next(46, 47);
        ward = _ward[index];
    }
    else if (district == "Quan Hoc Mon")
    {
        int index = _rdg.next(48, 49);
        ward = _ward[index];
    }
    else if (district == "Quan Nha Be")
    {
        int index = _rdg.next(50, 51);
        ward = _ward[index];
    }


    index = _rdg.next(1, 500);
    int house_number = index;

    index = _rdg.next(1, 500);
    string street = "Duong so " + to_string(index);

    Address result(house_number, street, ward, district);
    return result;
}

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

    void setGPA(double GPA )
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
public:
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
                Name name;
                Student student;
                for (int i = 0; i < 7; i++)
                {
                    string temp;
                    getline(file, temp);
                    if (i == 0)
                    {
                        student.setID(temp.substr(9, temp.length()));
                    }
                    if (i == 1)
                    {
                        string temp1;
                        temp1 = temp.substr(11, temp.length() - 11);
                        temp1 = strtok(strdup(temp1.c_str()), " ");
                        name.setLastName(temp1);
                        temp1 = strtok(NULL, " ");
                        name.setMiddleName(temp1);
                        temp1 = strtok(NULL, " ");
                        name.setFirstName(temp1);
                        student.setName(name);
                    }
                    if (i == 2)
                    {
                        student.setGPA(stod(temp.substr(10, temp.length()-10)));
                    }
                    if (i == 3)
                    {
                        student.setTelephone(temp.substr(16, temp.length()-16));
                    }
                    if (i == 4)
                    {
                        student.setEmail(temp.substr(12, temp.length()-12));
                    }
                    if (i == 5)
                    {
                        Date date;
                        string temp1;
                        temp1 = temp.substr(10, temp.length()-10);
                        temp1 = strtok(strdup(temp1.c_str()), "/");
                        date.setDay(stoi(temp1));
                        temp1 = strtok(NULL, "/");
                        date.setMonth(stoi(temp1));
                        temp1 = strtok(NULL, "/");
                        date.setYear(stoi(temp1));
                        student.setDOB(date);
                    }
                    if (i == 6)
                    {
                        Address address;
                        string temp1;
                        temp1 = temp.substr(14, temp.length()-14);
                        temp1 = strtok(strdup(temp1.c_str()), " ");
                        address.setHouseNumber(stoi(temp1));
                        temp1 = strtok(NULL, ",");
                        address.setStreet(temp1);
                        temp1 = strtok(NULL, ",");
                        address.setWard(temp1);
                        temp1 = strtok(NULL, ",");
                        address.setDistrict(temp1);
                        student.setAddress(address);
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
