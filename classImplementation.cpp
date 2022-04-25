#include "classHeader.h"

shared_ptr<RandomIntegerGenerator> RandomIntegerGenerator::_instance = nullptr;

RandomIntegerGenerator::RandomIntegerGenerator()
{
    srand(time(NULL));
}

shared_ptr<RandomIntegerGenerator> RandomIntegerGenerator::instance()
{
    if (_instance == nullptr)
    {
        _instance = make_shared<RandomIntegerGenerator>();
    }

    return _instance;
}

int RandomIntegerGenerator::next()
{
    int result = rand();
    return result;
}

int RandomIntegerGenerator::next(int ceiling)
{
    int result = rand() % ceiling;
    return result;
}

int RandomIntegerGenerator::next(int left, int right)
{
    int result = rand() % (left - right + 1) + left;
    return result;
}

RandomAddressGenerator::RandomAddressGenerator()
{
    _ward = {"An Khanh", "An Loi Dong", "An Phu", "Binh Chieu", "Binh Tho", "Binh Trung Đong", "Binh Trung Tay", "Cat Lai", "Hiep Binh Chanh", "Ben Nghe", "Cau Kho", "Cau ong Lanh", "Ben Thanh", "Ca Giang", "Da Kao", "Nguyen Thai Binh", "Pham Ngu Lao", "Nguyen Cu Trinh", "Tan Dinh", "Phuong 1", "Phuong 2", "Phuong 3", "Phuong 4", "Phuong 5", "Phuong Binh Thuan", "Phuong Phu My", "Phuong Phu Thuan", "Phuong Tan Hung", "Phuong Tan Kieng", "An Phu Dong", "Dong Hung Thuan", "Hiep Thanh", "Tan Chanh Hiep", "Tan Hung Thuan", "An Lac", "Binh Hung Hoa", "Binh Tri Dong", "Phuong Hiep Tan", "Phuong Hoa Thanh", "Phuong Phu Thanh", "Phuong Phu Tho Hoa", "Phuong Phu Trung", "Xa Pham Van Hai", "Xa Binh Loi", "Xa An Thoi Dong", "Xa Binh Khanh", "Xa An Phu", "Xa An Nhon Tay", "Xa Dong Hanh", "Xa Nhi Binh", "Xa Tan Hung", "Xa My Luong"};
    _district = {"Thanh pho Thu Duc", "Quan 1", "Quan 3", "Quan 4", "Quan 5", "Quan 6", "Quan 7", "Quan 8", "Quan 10", "Quan 11", "Quan 12", "Quan Binh Tan", "Quan Binh Thanh", "Quan Go Vap", "Quan Phu Nhuan", "Quận Tan Binh", "Quan Tan Phu", "Huyen Binh Chanh", "Huyen Can Gio", "Huyen Cu Chi", "Huyen Hoc Mon", "Huyen Nha Be"};
}

Address RandomAddressGenerator::next()
{
    int index = RandomIntegerGenerator::instance()->next(_district.size());
    string district = _district[index];
    string ward = "";

    if (district == "Thanh pho Thu Duc")
    {
        int index = RandomIntegerGenerator::instance()->next(0, 8);
        ward = _ward[index];
    }
    else if (district == "Quan 1")
    {
        int index = RandomIntegerGenerator::instance()->next(9, 18);
        ward = _ward[index];
    }
    else if (district == "Quan 3")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 4")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 5")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 6")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 7")
    {
        int index = RandomIntegerGenerator::instance()->next(24, 28);
        ward = _ward[index];
    }
    else if (district == "Quan 8")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 10")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 11")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan 12")
    {
        int index = RandomIntegerGenerator::instance()->next(29, 33);
        ward = _ward[index];
    }
    else if (district == "Quan Binh Tan")
    {
        int index = RandomIntegerGenerator::instance()->next(34, 36);
        ward = _ward[index];
    }
    else if (district == "Quan Binh Thanh")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan Go Vap")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan Phu Nhuan")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan Tan Binh")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _ward[index];
    }
    else if (district == "Quan Tan Phu")
    {
        int index = RandomIntegerGenerator::instance()->next(37, 41);
        ward = _ward[index];
    }
    else if (district == "Quan Binh Chanh")
    {
        int index = RandomIntegerGenerator::instance()->next(42, 43);
        ward = _ward[index];
    }
    else if (district == "Quan Can Gio")
    {
        int index = RandomIntegerGenerator::instance()->next(44, 45);
        ward = _ward[index];
    }
    else if (district == "Quan Cu Chi")
    {
        int index = RandomIntegerGenerator::instance()->next(46, 47);
        ward = _ward[index];
    }
    else if (district == "Quan Hoc Mon")
    {
        int index = RandomIntegerGenerator::instance()->next(48, 49);
        ward = _ward[index];
    }
    else if (district == "Quan Nha Be")
    {
        int index = RandomIntegerGenerator::instance()->next(50, 51);
        ward = _ward[index];
    }

    index = RandomIntegerGenerator::instance()->next(1, 500);
    int house_number = index;

    index = RandomIntegerGenerator::instance()->next(1, 500);
    string street = "Duong so " + to_string(index);

    Address result(house_number, street, ward, district);
    return result;
}

Date RandomDateGenerator::next()
{

    int month = RandomIntegerGenerator::instance()->next(1, 12);

    int day = 31;

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        day = RandomIntegerGenerator::instance()->next(1, 30);
    }

    if (month == 2)
    {
        while (day == 31 || day == 30)
        {
            day = RandomIntegerGenerator::instance()->next(1, 28);
        }
    }

    int year = RandomIntegerGenerator::instance()->next(1990, 2022);

    Date result(day, month, year);
    return result;
}

tuple<bool, int, string, vector<Student>> MockStudentData::parse(const char *filename)
{

    bool successful = true;
    int errorCode = 0;
    string message = "";
    vector<Student> students;

    fstream file(filename, ios::in | ios::out);

    if (!file.is_open())
    {
        errorCode = 1;
        successful = false;
        message = "Read failed: cannot open " + string(filename);
    }
    else
    {
        while (!file.eof())
        {
            Student student;

            string temp_str;
            int id_size = 8;
            // get ID of student
            getline(file, temp_str);
            vector<string> token = StringHelper::split(temp_str, " ");
            student.setID(token[1]);

            // get Name
            getline(file, temp_str);
            token = StringHelper::split(temp_str, " = ");

            string name = token[1];
            vector<string> names = StringHelper::split(name, " ");
            student.setName(Name(names[0], names[1], names[2]));

            // get GPA
            getline(file, temp_str);
            token = StringHelper::split(temp_str, " = ");
            student.setGPA(stod(token[1]));

            // get Telephone
            getline(file, temp_str);
            token = StringHelper::split(temp_str, " = ");
            student.setTelephone(token[1]);

            // get Email
            getline(file, temp_str);
            token = StringHelper::split(temp_str, " = ");
            student.setEmail(token[1]);

            // get DOB
            getline(file, temp_str);
            token = StringHelper::split(temp_str, " = ");

            string date = token[1];
            token = StringHelper::split(temp_str, "/");
            Date DOB(stoi(token[0]), stoi(token[1]), stoi(token[2]));
            student.setDOB(DOB);

            // get Address
            getline(file, temp_str);
            token = StringHelper::split(temp_str, " = ");

            token = StringHelper::split(token[1], ", ");

            string num_street = token[0];
            string num = num_street.substr(0, num_street.find(" "));
            string street = num_street.substr(num_street.find(" ") + 1, num_street.length() - num_street.find(" "));
            string ward = token[1];
            string district = token[2];

            student.setAddress(Address(stoi(num), street, ward, district));
        }
    }

    auto result = make_tuple(successful, errorCode, message, students);
    return result;
}

bool MockStudentData::createNewStudent(vector<Student> &students, int numberOfStudent)
{
    return true;
}

bool MockStudentData::writeStudentInfo(string filename, vector<Student> &students)
{
    fstream f(filename, ios::out);

    return true;
}

vector<string> StringHelper::split(string source, string delimiter)
{
    vector<string> result;
    int start = 0;
    int end = source.find(delimiter);

    while (end != string::npos)
    {
        string token = source.substr(start, end - start);
        result.push_back(token);
        start = end + delimiter.length();
        end = source.find(delimiter);
    }

    result.push_back(source.substr(start, end - start));

    return result;
}

RandomNameGenerator::RandomNameGenerator()
{
    _sample_middleNames = {
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
        "Tan",
        "Tu",
        "Ha"};

    getSampleLastNames("top_lastname.txt");
    getSampleFirstNames("top_firstname.txt");
}

void RandomNameGenerator::getSampleLastNames(const char *filename)
{
    fstream file(filename, ios::in);
    while (!file.eof())
    {
        string temp_str;
        getline(file, temp_str);
        vector<string> token = StringHelper::split(temp_str, "\t");

        pair<string, double> lastName = make_pair(token[0], stoi(token[1]));
        _sample_lastNames.push_back(lastName);
    }
}

void RandomNameGenerator::getSampleFirstNames(const char *filename)
{
    fstream file(filename, ios::in);
    while (!file.eof())
    {
        string temp_str;
        getline(file, temp_str);
        vector<string> token = StringHelper::split(temp_str, "\t");

        pair<string, double> firstName = make_pair(token[0], stoi(token[1]));
        _sample_firstNames.push_back(firstName);
    }
}

Name RandomNameGenerator::next()
{
    Name result;
    // get random first name
    int totalrate = 0;
    int rate = RandomIntegerGenerator::instance()->next(2000000);
    for (auto it : _sample_firstNames)
    {
        totalrate += it.second;
        if (rate < totalrate)
        {
            result.setFirstName(it.first);
        }
    }

    // get random middle name
    int index = RandomIntegerGenerator::instance()->next(_sample_middleNames.size());
    result.setMiddleName(_sample_middleNames[index]);

    // get random last name
    totalrate = 0;
    rate = RandomIntegerGenerator::instance()->next(1000000);
    for (auto it : _sample_lastNames)
    {
        totalrate += it.second;
        if (rate < totalrate)
        {
            result.setLastName(it.first);
        }
    }
}

string RandomSimpleInfo::nextEmail(Name name)
{
    string result = "";

    string lastName = name.getLastName();
    string firstName = name.getFirstName();
    string middleName = name.getMiddleName();

    result += lastName[0] + middleName[0] + firstName[0] + "@student.hcmus.edu.vn";

    return result;
}

double RandomSimpleInfo::nextGPA()
{
    double result;

    result = static_cast<double>(RandomIntegerGenerator::instance()->next(100)) / 100;

    return result;
}

string RandomSimpleInfo::nextTelephoneNumber()
{
    string result = "0";

    for (int i = 1; i <= 10; i++)
    {
        if (i != 5 && i != 9)
            result += to_string(RandomIntegerGenerator::instance()->next(9));
        else
            result += "-";
    }

    return result;
}

string RandomSimpleInfo::nextID()
{
    string result = "";

    // year
    int year = RandomIntegerGenerator::instance()->next(15, 25);
    result += to_string(year);

    // major
    int major = RandomIntegerGenerator::instance()->next(10, 25);
    result += to_string(major);

    // id
    int id = RandomIntegerGenerator::instance()->next(9999);
    result += to_string(id);
}
