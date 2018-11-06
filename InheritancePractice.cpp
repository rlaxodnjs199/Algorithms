#include <iostream>
#include <string>
class Person {
  public:
    virtual std::string GetName() { return "Reo"; }
};
class Player : public Person {
  private:
    std::string m_Name;
  public:
    Player (std::string s) : m_Name(s) {}
    std::string GetName() override { return m_Name; }
};

int main() {
  Person* p1 = new Person();
  std::cout << p1->GetName() << std::endl;
  Player* p2 = new Player("KTW");
  std::cout << p2->GetName() << std::endl;
}