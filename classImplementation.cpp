#include "classHeader.h"

// integer randomizer implementation
shared_ptr<RandomIntegerGenerator> RandomIntegerGenerator::_instance = nullptr;

shared_ptr<RandomIntegerGenerator> RandomIntegerGenerator::instance()
{
    if (_instance == nullptr)
    {
        _instance = make_shared<RandomIntegerGenerator>();
    }

    return _instance;
}

RandomIntegerGenerator::RandomIntegerGenerator()
{
    srand(time(NULL));
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
//--------------------------------------------------------------------//

// address a randomizer
RandomAddressGenerator::RandomAddressGenerator()
{
    _sample_street = {"Alexandre de Rhodes", "Ba Le Chan", "Calmette", "Ben Chuong Duong", "Bui Thi Xuan", "Bui Vien", "Cach Mang Thang 8", "Cao Ba Nha", "Cao Ba Quat", "Cay Diep", "Chu Manh Chinh", "Co Bac", "Co Giang", "Cong Quynh", "Cong Truong Lam Son", "Cong Truong Me Linh", "Cong Truong Paris", "Dang Dung", "Dang Tat", "Dang Thi Nhu", "Dang Tran Con", "De Tham", "Dien Bien Phu", "Dinh Cong Tranh", "Dinh Tien Hoang", "Do Quang Dau", "Dong Du", "Dong Khoi", "Hai Ba Trung", "Hai Trieu", "Ham Nghi", "Han Thuyen", "Hoa My", "Hoang Sa", "Nguyen Du", "Nguyen Dinh Chieu", "Nguyen Cuu Van", "Nguyen Cu Trinh", "Nguyen Cong Tru", "Nguyen Canh Chan", "Nguyen Binh Khiem", "Nguyen An Ninh", "Ngo Van Nam", "Ngo Quyen", "Ngo Duc Ke", "Nam Quoc Cang", "Mai Thi Luu", "Mac Thi Buoi", "Mac Dinh Chi", "Ma Lo", "Ly Van Phuc", "Ly Thai To", "Ly Chien Thang", "Luu Van Lang", "Luong Huu Khanh", "Le Van Huu", "Le Thi Rieng", "Le Thi Hong Gam", "Le Thanh Ton", "Le Loi", "Le Lai", "Le Duan", "Le Cong Kieu", "Ky Con", "Le Anh Xuan", "Khanh Hoi", "Huynh Thuc Khang", "Huyen Quang ", "Nguyen Hau", "Nguyen Hue", "Nguyen Huu Canh", "Nguyen Huu Cau", "Nguyen Huy Tu", "Nguyen Khac Nhu", "Nguyen Phi Khanh", "Nguyen Sieu", "Nguyen Thai Binh", "Nguyen Thai Hoc"};
    _sample_ward = {"Ward An Khanh", "Ward An Loi Dong", "Ward An Phu", "Ward Binh Chieu", "Ward Binh Tho", "Ward Binh Trung Đong", "Ward Binh Trung Tay", "Ward Cat Lai", "Ward Hiep Binh Chanh", "Ward Ben Nghe", "Ward Cau Kho", "Ward Cau ong Lanh", "Ward Ben Thanh", "Ward Ca Giang", "Ward Da Kao", "Ward Nguyen Thai Binh", "Ward Pham Ngu Lao", "Ward Nguyen Cu Trinh", "Ward Tan Dinh", "Ward 1", "Ward 2", "Ward 3", "Ward 4", "Ward 5", "Ward Binh Thuan", "Ward Phu My", "Ward Phu Thuan", "Ward Tan Hung", "Ward Tan Kieng", "Ward An Phu Dong", "Ward Dong Hung Thuan", "Ward Hiep Thanh", "Ward Tan Chanh Hiep", "Ward Tan Hung Thuan", "Ward An Lac", "Ward Binh Hung Hoa", "Ward Binh Tri Dong", "Ward Phuong Hiep Tan", "Ward Hoa Thanh", "Ward Phu Thanh", "Ward Phu Tho Hoa", "Ward Phu Trung", "Ward Pham Van Hai", "Ward Binh Loi", "Ward An Thoi Dong", "Ward Binh Khanh", "Ward An Phu", "Ward An Nhon Tay", "Ward Dong Hanh", "Ward Nhi Binh", "Ward Tan Hung", "Ward My Luong"};
    _sample_district = {"District Thu Duc", "District 1", "District 3", "District 4", "District 5", "District 6", "District 7", "District 8", "District 10", "District 11", "District 12", "District Binh Tan", "District Binh Thanh", "District Go Vap", "District Phu Nhuan", "District Tan Binh", "District Tan Phu", "District Binh Chanh", "District Can Gio", "District Cu Chi", "District Hoc Mon", "District Nha Be"};
}

vector<int> RandomAddressGenerator::_house_number = {};
vector<string> RandomAddressGenerator::_sample_street = {};
vector<string> RandomAddressGenerator::_sample_ward = {};
vector<string> RandomAddressGenerator::_sample_district = {};

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
//-------------------------------------------------------------------//

// date randomizer
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
//-------------------------------------------------------------------//

// name randomizer
shared_ptr<RandomNameGenerator> RandomNameGenerator::_instance = nullptr;

shared_ptr<RandomNameGenerator> RandomNameGenerator::instance()
{
    if (_instance == nullptr)
    {
        _instance = make_shared<RandomNameGenerator>();
        getSampleLastNames("top_lastname.txt");
        getSampleFirstNames("top_firstname.txt");
    }

    return _instance;
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
}

vector<pair<string, int>> RandomNameGenerator::_sample_firstNames = {};
vector<string> RandomNameGenerator::_sample_middleNames = {};
vector<pair<string, int>> RandomNameGenerator::_sample_lastNames = {};

void RandomNameGenerator::getSampleLastNames(string filename)
{
    fstream file(filename, ios::in);
    while (!file.eof())
    {
        string temp_str;
        getline(file, temp_str);
        vector<string> token = StringUtils::split(temp_str, "\t");

        pair<string, int> lastName = make_pair(token[0], stoi(token[1]));
        _sample_lastNames.push_back(lastName);
    }

    file.close();
}

void RandomNameGenerator::getSampleFirstNames(string filename)
{
    fstream file(filename, ios::in);
    while (!file.eof())
    {
        string temp_str;
        getline(file, temp_str);
        vector<string> token = StringUtils::split(temp_str, "\t");

        pair<string, int> firstName = make_pair(token[0], stoi(token[1]));
        _sample_firstNames.push_back(firstName);
    }

    file.close();
}

Name RandomNameGenerator::next()
{

    Name result;
    // get random first name
    int totalrate = 0;
    int rate = RandomIntegerGenerator::instance()->next(2000000);
    for (auto &it : RandomNameGenerator::_sample_firstNames)
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
    for (auto &it : _sample_lastNames)
    {
        totalrate += it.second;
        if (rate < totalrate)
        {
            result.setLastName(it.first);
        }
    }

    return result;
}
//-------------------------------------------------------------------//

// other info randomizer
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

    return result;
}
//------------------------------------------------------------------//

// mock up data method implementation
vector<Student> MockStudentData::parse(string filename)
{
    vector<Student> students = {};

    fstream file(filename, ios::in);

    if (!file.is_open())
    {
        cout << "Read failed: cannot open " + string(filename) << endl;
    }
    else
    {
        while (!file.eof())
        {
            Student student;

            string temp_str;

            // get ID of student
            getline(file, temp_str);
            vector<string> token = StringUtils::split(temp_str, " ");
            student.setID(token[1]);

            // get Name
            getline(file, temp_str);
            token = StringUtils::split(temp_str, " = ");

            string name = token[1];
            vector<string> names = StringUtils::split(name, " ");
            student.setName(Name(names[0], names[1], names[2]));

            // get GPA
            getline(file, temp_str);
            token = StringUtils::split(temp_str, " = ");
            student.setGPA(stod(token[1]));

            // get Telephone
            getline(file, temp_str);
            token = StringUtils::split(temp_str, " = ");
            student.setTelephone(token[1]);

            // get Email
            getline(file, temp_str);
            token = StringUtils::split(temp_str, " = ");
            student.setEmail(token[1]);

            // get DOB
            getline(file, temp_str);
            token = StringUtils::split(temp_str, " = ");

            string date = token[1];
            token = StringUtils::split(date, "/");
            Date DOB(stoi(token[0]), stoi(token[1]), stoi(token[2]));
            student.setDOB(DOB);

            // get Address
            getline(file, temp_str);
            token = StringUtils::split(temp_str, " = ");

            token = StringUtils::split(token[1], ", ");

            string num_street = token[0];
            string num = num_street.substr(0, num_street.find(" "));
            string street = num_street.substr(num_street.find(" ") + 1, num_street.length() - num_street.find(" "));
            string ward = token[1];
            string district = token[2];

            student.setAddress(Address(stoi(num), street, ward, district));

            students.push_back(student);
        }
    }

    file.close();

    return students;
}

bool MockStudentData::createNewStudent(vector<Student> &students, int numberOfStudent)
{
    for (int i = 0; i < numberOfStudent; i++)
    {
        string id = RandomSimpleInfo::nextID();
        Name name = RandomNameGenerator::instance()->next();
        double GPA = RandomSimpleInfo::nextGPA();
        string telephone = RandomSimpleInfo::nextTelephoneNumber();
        string email = RandomSimpleInfo::nextEmail(name);
        Date dob = RandomDateGenerator::next();
        Address address = RandomAddressGenerator::next();

        Student student(id, name, GPA, telephone, email, dob, address);

        students.push_back(student);
    }

    return true;
}

bool MockStudentData::writeStudentInfo(string filename, vector<Student> &students)
{
    fstream f(filename, ios::out);
    bool successful = true;

    if (!f.is_open())
    {
        cout << "Error: " << filename << " cannot be written" << endl;
        successful = false;
    }
    else
    {
        for (auto &st : students)
        {
            f << "Student: " << st.id() << endl;
            f << "\tName: " << StringUtils::to_String(st.name()) << endl;
            f << "\tGPA: " << st.gpa() << endl;
            f << "\tTelephone: " << st.telephone() << endl;
            f << "\tEmail: " << st.email() << endl;
            f << "\tDOB: " << StringUtils::to_String(st.dateOfBirth()) << endl;
            f << "\tAddress: " << StringUtils::to_String(st.address()) << endl;
        }
    }

    f.close();
    return successful;
}
//------------------------------------------------------------------//

vector<string> StringUtils::split(string source, string delimiter)
{
    vector<string> result;
    int start = 0;
    int end = source.find(delimiter);

    while (end != string::npos)
    {
        string token = source.substr(start, end - start);
        result.push_back(token);
        start = end + delimiter.length();
        end = source.find(delimiter, start);
    }

    result.push_back(source.substr(start, end - start));

    return result;
}

string StringUtils::to_String(Name name)
{
    string result;

    result += name.getLastName() + " " + name.getMiddleName() + " " + name.getFirstName();

    return result;
}

string StringUtils::to_String(Date date)
{
    string result;

    result += to_string(date.day()) + "/" + to_string(date.month()) + "/" + to_string(date.year());

    return result;
}

string StringUtils::to_String(Address address)
{
    string result;

    result += to_string(address.houseNumber()) + " " + address.Street() + ", " + address.Ward() + ", " + address.District();
    result += ", Ho Chi Minh City";

    return result;
}

// student processing data
double StudentProcessor::averageGPA(vector<Student> &students)
{
    double GPA = 0.0;
    int num = students.size();

    for (auto &st : students)
    {
        GPA += st.gpa() / num;
    }

    return GPA;
}

vector<Student> StudentProcessor::findAboveAverageStudent(vector<Student> &students)
{
    vector<Student> result;

    double avg = StudentProcessor::averageGPA(students);

    for (auto &student : students)
    {
        if (student.gpa() > avg)
            result.push_back(student);
    }

    return result;
}

void StudentProcessor::printStudentList(vector<Student> &students)
{
    for (auto &st : students)
    {
        cout << "Student: " << st.id() << endl;
        cout << "\tName: " << StringUtils::to_String(st.name()) << endl;
        cout << "\tGPA: " << st.gpa() << endl;
        cout << "\tTelephone: " << st.telephone() << endl;
        cout << "\tEmail: " << st.email() << endl;
        cout << "\tDOB: " << StringUtils::to_String(st.dateOfBirth()) << endl;
        cout << "\tAddress: " << StringUtils::to_String(st.address()) << endl;
    }
}

// program execution
void ProgramExecution::option_one(vector<Student> &students)
{
    int num;

    cout << "How many students that you want to add: ";
    cin >> num;

    bool successful = MockStudentData::createNewStudent(students, num);

    if (successful)
        cout << "Adding students successfully" << endl;
    else
        cout << "Failed to create new students" << endl;
}

void ProgramExecution::option_two(vector<Student> &students)
{
    double averageGPA = StudentProcessor::averageGPA(students);

    cout << "Average GPA: " << averageGPA << endl;
}

void ProgramExecution::option_three(vector<Student> &students)
{
    vector<Student> studentsAboveAverageGPA = StudentProcessor::findAboveAverageStudent(students);

    StudentProcessor::printStudentList(students);
}

int ProgramExecution::main()
{
    string filename = "students.txt";
    vector<Student> students = MockStudentData::parse(filename);

    bool will_continue = true;

    while (will_continue)
    {
        system("cls");
        int choice = -1;
        cout << "1. Add n mock up data and overwrite file" << endl;
        cout << "2. Print out the average GPA of students" << endl;
        cout << "3. Print out all of above average students" << endl;
        cout << "0. Exit" << endl;
        cout << "---------------------\nYour choice: ";
        cin >> choice;

        if (choice == 1)
        {
            option_one(students);
        }
        else if (choice == 2)
        {
            option_two(students);
        }
        else if (choice == 3)
        {
            option_three(students);
        }
        else if (choice == 0)
        {
            will_continue = false;
        }
        else
        {
            cout << "ERROR: Unknown choice" << endl;
        }

        system("pause");
    }

    return 0;
}
