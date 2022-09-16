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

private:
    string Name;
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
    }
};

// Inheritance
class Developer : Employee
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
        std::cout << getName() << " Please fix your bug" << std::endl;
    }
};

int main()
{
    Employee emp1("Devid", "Edgerunner", 18);
    emp1.introduce();
    Employee emp2("Lucy", "Netrunner", 18);
    emp2.introduce();
    emp2.askForPromotion();
    Developer dev1 = Developer("Mike",23,"nano bot", "C++");
    dev1.fixBug();
    return 0;
}