#include <iostream>
#include <string>
class Toy {
  protected:
    std::string name;
    float price;
  public:
    virtual void prepareParts() = 0;
    virtual void combineParts() = 0;
};

class Car : public Toy {
  public:
    void prepareParts() {std::cout << "Prepare car";}
    void combineParts() {std::cout << "Combine car";}
};

class ToyFactory {
  public:
    static Toy* createToy(int type) {
      Toy* toy = NULL;
      if (type == 1) {
        toy = new Car;
        toy->prepareParts();
        toy->combineParts();
      }
      return toy;
    }
};

int main() {
  int type = 1;
  Toy* t = ToyFactory::createToy(type);
}