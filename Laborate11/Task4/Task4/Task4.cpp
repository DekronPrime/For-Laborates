#include <iostream>
#include <list>
#include <Windows.h>
using namespace std;

class Student {
private:
    string lname;
    string name;
    string fname;
    int age;
    unsigned int phoneNumber;
public:
    Student(){
        this->lname = "";
        this->name = "";
        this->fname = "";
        this->age = 0;
        this->phoneNumber = 0;
    }
    ~Student() {}
    void setLname(string lname) {
        this->lname = lname;
    }
    void setName(string name) {
        this->name = name;
    }
    void setFname(string fname) {
        this->fname = fname;
    }
    void setPhoneNumber(int number) {
        this->phoneNumber = number;
    }
    void setAge(int age) {
        this->age = age;
    }

    string getLname() const {
        return this->lname;
    }
    string getName() const {
        return this->name;
    }
    string getFname() const {
        return this->fname;
    }
    unsigned int getPhoneNumber() const {
        return this->phoneNumber;
    }
    int getAge() const {
        return this->age;
    }

    friend ostream& operator <<(ostream& os, const Student obj) {
        os << "Прізвище: " << obj.lname << endl;
        os << "Ім'я: " << obj.name << endl;
        os << "По батькові: " << obj.fname << endl;
        os << "Вік: " << obj.age << endl;
        os << "Тел: +(380)" << obj.phoneNumber << endl;
        return os;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list<Student> stud;
    Student st;
    st.setLname("Пастернак");
    st.setName("Микола");
    st.setFname("Якович");
    st.setPhoneNumber(950670680);
    st.setAge(38);

    stud.push_back(st);

    st.setLname("Коваленко");
    st.setName("Віктор");
    st.setFname("Петрович");
    st.setPhoneNumber(725368469);
    st.setAge(21);

    stud.push_back(st);

    for (auto it = stud.cbegin(); it != stud.cend(); ++it) {
        cout << *it << endl;
    }
}
