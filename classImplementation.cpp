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
    _sample_streets = { "Alexandre de Rhodes", "Ba Le Chan", "Calmette", "Ben Chuong Duong", "Bui Thi Xuan", "Bui Vien", "Cach Mang Thang 8", "Cao Ba Nha", "Cao Ba Quat", "Cay Diep", "Chu Manh Chinh", "Co Bac", "Co Giang", "Cong Quynh", "Cong Truong Lam Son", "Cong Truong Me Linh", "Cong Truong Paris", "Dang Dung", "Dang Tat", "Dang Thi Nhu", "Dang Tran Con", "De Tham", "Dien Bien Phu", "Dinh Cong Tranh", "Dinh Tien Hoang", "Do Quang Dau", "Dong Du", "Dong Khoi", "Hai Ba Trung", "Hai Trieu", "Ham Nghi", "Han Thuyen", "Hoa My", "Hoang Sa", "Nguyen Du", "Nguyen Dinh Chieu", "Nguyen Cuu Van", "Nguyen Cu Trinh", "Nguyen Cong Tru", "Nguyen Canh Chan", "Nguyen Binh Khiem", "Nguyen An Ninh", "Ngo Van Nam", "Ngo Quyen", "Ngo Duc Ke", "Nam Quoc Cang", "Mai Thi Luu", "Mac Thi Buoi", "Mac Dinh Chi", "Ma Lo", "Ly Van Phuc", "Ly Thai To", "Ly Chien Thang", "Luu Van Lang", "Luong Huu Khanh", "Le Van Huu", "Le Thi Rieng", "Le Thi Hong Gam", "Le Thanh Ton", "Le Loi", "Le Lai", "Le Duan", "Le Cong Kieu", "Ky Con", "Le Anh Xuan", "Khanh Hoi", "Huynh Thuc Khang", "Huyen Quang ", "Nguyen Hau", "Nguyen Hue", "Nguyen Huu Canh", "Nguyen Huu Cau", "Nguyen Huy Tu", "Nguyen Khac Nhu", "Nguyen Phi Khanh", "Nguyen Sieu", "Nguyen Thai Binh", "Nguyen Thai Hoc" }
    _sample_wards = { "Ward An Khanh", "Ward An Loi Dong", "Ward An Phu", "Ward Binh Chieu", "Ward Binh Tho", "Ward Binh Trung Đong", "Ward Binh Trung Tay", "Ward Cat Lai", "Ward Hiep Binh Chanh", "Ward Ben Nghe", "Ward Cau Kho", "Ward Cau ong Lanh", "Ward Ben Thanh", "Ward Ca Giang", "Ward Da Kao", "Ward Nguyen Thai Binh", "Ward Pham Ngu Lao", "Ward Nguyen Cu Trinh", "Ward Tan Dinh", "Ward 1", "Ward 2", "Ward 3", "Ward 4", "Ward 5", "Ward Binh Thuan", "Ward Phu My", "Ward Phu Thuan", "Ward Tan Hung", "Ward Tan Kieng", "Ward An Phu Dong", "Ward Dong Hung Thuan", "Ward Hiep Thanh", "Ward Tan Chanh Hiep", "Ward Tan Hung Thuan", "Ward An Lac", "Ward Binh Hung Hoa", "Ward Binh Tri Dong", "Ward Phuong Hiep Tan", "Ward Hoa Thanh", "Ward Phu Thanh", "Ward Phu Tho Hoa", "Ward Phu Trung", "Ward Pham Van Hai", "Ward Binh Loi", "Ward An Thoi Dong", "Ward Binh Khanh", "Ward An Phu", "Ward An Nhon Tay", "Ward Dong Hanh", "Ward Nhi Binh", "Ward Tan Hung", "Ward My Luong" };
    _sample_districts = { "District Thu Duc", "District 1", "District 3", "District 4", "District 5", "District 6", "District 7", "District 8", "District 10", "District 11", "District 12", "District Binh Tan", "District Binh Thanh", "District Go Vap", "District Phu Nhuan", "District Tan Binh", "District Tan Phu", "District Binh Chanh", "District Can Gio", "District Cu Chi", "District Hoc Mon", "District Nha Be" };
}

Address RandomAddressGenerator::next()
{
    int index = RandomIntegerGenerator::instance()->next(_sample_district.size());
    string district = _sample_district[index];
    string ward = "";

    if (district == "District Thu Duc")
    {
        int index = RandomIntegerGenerator::instance()->next(0, 8);
        ward = _sample_ward[index];
    }
    else if (district == "District 1")
    {
        int index = RandomIntegerGenerator::instance()->next(9, 18);
        ward = _sample_ward[index];
    }
    else if (district == "District 3")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District 4")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District 5")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District 6")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District 7")
    {
        int index = RandomIntegerGenerator::instance()->next(24, 28);
        ward = _sample_ward[index];
    }
    else if (district == "District 8")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District 10")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District 11")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District 12")
    {
        int index = RandomIntegerGenerator::instance()->next(29, 33);
        ward = _sample_ward[index];
    }
    else if (district == "District Binh Tan")
    {
        int index = RandomIntegerGenerator::instance()->next(34, 36);
        ward = _sample_ward[index];
    }
    else if (district == "District Binh Thanh")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District Go Vap")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District Phu Nhuan")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District Tan Binh")
    {
        int index = RandomIntegerGenerator::instance()->next(19, 23);
        ward = _sample_ward[index];
    }
    else if (district == "District Tan Phu")
    {
        int index = RandomIntegerGenerator::instance()->next(37, 41);
        ward = _sample_ward[index];
    }
    else if (district == "District Binh Chanh")
    {
        int index = RandomIntegerGenerator::instance()->next(42, 43);
        ward = _sample_ward[index];
    }
    else if (district == "District Can Gio")
    {
        int index = RandomIntegerGenerator::instance()->next(44, 45);
        ward = _sample_ward[index];
    }
    else if (district == "District Cu Chi")
    {
        int index = RandomIntegerGenerator::instance()->next(46, 47);
        ward = _sample_ward[index];
    }
    else if (district == "District Hoc Mon")
    {
        int index = RandomIntegerGenerator::instance()->next(48, 49);
        ward = _sample_ward[index];
    }
    else if (district == "District Nha Be")
    {
        int index = RandomIntegerGenerator::instance()->next(50, 51);
        ward = _sample_ward[index];
    }

    index = RandomIntegerGenerator::instance()->next(1, 500);
    int house_number = index;

    index = RandomIntegerGenerator::instance()->next(_sample_street.size());
    string street = _sample_street[index];

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

tuple<bool, int, string, vector<Student>> MockStudentData::parse(const char* filename)
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

bool MockStudentData::createNewStudent(vector<Student>& students, int numberOfStudent)
{
    Student student;
    for (int i = 0; i < numberOfStudent; i++)
    {
        student.setID(RandomSimpleInfo::nextID());
        student.setName(RandomNameGenerator::next());
        student.setGPA(RandomSimpleInfo::nextGPA());
        student.setTelephone(RandomSimpleInfo::nextTelephoneNumber());
        student.setEmail(RandomSimpleInfo::nextEmail());
        student.setDOB(RandomDateGenerator::next());
        student.setAddress(RandomAddressGenerator::next());
        students.push_back(student);
    }

    return true;
}

bool MockStudentData::writeStudentInfo(string filename, vector<Student>& students)
{
    fstream f(filename, ios::out);
    for (int i = 0; i < students.size(); i++)
    {
        f << "Student: " << students[i].getID() << endl;
        Name name(students[i].getName());
        f << "    Name = " << name.getLastName() << " " << name.getMiddleName() << " " << name.getFirstName() << endl;  
        f << "    GPA = " << students[i].getGPA() << endl;
        f << "    Telephone = " << students[i].getTelephone() << endl;
        f << "    Email = " << students[i].getEmail() << endl;
        Date dateOfBirth(students[i].getDOB());
        f << "    DOB = " << dateOfBirth.getDay() << "/" << dateOfBirth.getMonth() << "/" << dateOfBirth.getYear() << endl;
        Address address(students[i].getAddress());
        f << "    Address = " << address.getHouseNumber() << " " << address.getStreet() << "," << address.getWard() << "," << address.getDistrict() << ", Ho Chi Minh city" << endl;

    }
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
        "Ha" };

    getSampleLastNames("top_lastname.txt");
    getSampleFirstNames("top_firstname.txt");
}

void RandomNameGenerator::getSampleLastNames(const char* filename)
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

void RandomNameGenerator::getSampleFirstNames(const char* filename)
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

