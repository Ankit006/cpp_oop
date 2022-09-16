#include <iostream>

using std::cout;
using std::endl;
using std::string;

class abstractEmployee
{
    virtual void askForPromotion() = 0; // Pure virtual function
};

class Employee : abstractEmployee
{
protected:
    string Name;

private:
    string Company;
    int Age;

public:
    Employee(string name, string company, int age)
    {
        Name = name;
        Age = age;
        Company = company;
    };
    void setName(string name)
    {
        Name = name;
    };
    string getName()
    {
        return Name;
    };
    void setAge(int age)
    {
        Age = age;
    };
    int getAge()
    {
        return Age;
    };
    void setCompany(string company)
    {
        Company = company;
    };
    string getCompany()
    {
        return Company;
    };
    void introduce()
    {
        cout << "Hello I am " << Name << ". I am " << Age << " years old and I work as " << Company << endl;
    };
    void askForPromotion()
    {
        if (Age > 30)
        {
            std::cout << Name << "Got promoted" << std::endl;
        }
        else
        {
            std::cout << Name << " sorry no promotion for u" << std::endl;
        }
    };
    virtual void work(){
        cout << Name << " is checking email, task backlog" << endl;
    }
};

// Inheritance
// Inheritance is private by default, that's why we are adding public keyword
class Developer : public Employee
{
public:
    string FavoriteProgrammingLanguage;
    Developer(string name, int age, string company, string favoriteProgrammingLanguage)
        : Employee(name, company, age)
    {
        FavoriteProgrammingLanguage = favoriteProgrammingLanguage;
    }
    void fixBug()
    {
        std::cout << Name << " Please fix your bug" << std::endl;
    }
    void work(){
        cout << Name << " is fixing the bugs" << endl;
    }
};

class Teacher : public Employee
{
public:
    string Subject;
    Teacher(string name, int age, string company, string subject) : Employee(name, company, age)
    {
        Subject = subject;
    }
    void prepareLesson()
    {
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    };
    void work(){
        cout << Name << " is teaching student" << endl;
    }

};

int
main()
{
    Employee emp1("Devid", "Edgerunner", 18);
    emp1.introduce();
    Employee emp2("Lucy", "Netrunner", 18);
    emp2.introduce();
    emp2.askForPromotion();
    Developer dev1 = Developer("Mike", 23, "nano bot", "C++");
    dev1.fixBug();
    dev1.askForPromotion();
    Teacher t = Teacher("Jack",23,"Code school", "History");
    t.prepareLesson();
    dev1.work();

    // Polymorphism 
    // It is nothing but accessing methods and properties of child class using parents 
    // with the use of pointer.
    Employee *e = &dev1;
    Teacher *e1 = &t;
    e->work();
    e1->work();
    return 0;
}