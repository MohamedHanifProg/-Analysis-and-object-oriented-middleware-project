#include <iostream>
#include <string>

// Abstract Product A
class Item {
public:
    virtual void show() = 0;
};

class LostItem : public Item {
public:
    void show() override {
        std::cout << "This is a lost item." << std::endl;
    }
};

class FoundItem : public Item {
public:
    void show() override {
        std::cout << "This is a found item." << std::endl;
    }
};

// Abstract Product B
class User {
public:
    virtual void show() = 0;
};

class FinderUser : public User {
public:
    void show() override {
        std::cout << "This is a finder user." << std::endl;
    }
};

class OwnerUser : public User {
public:
    void show() override {
        std::cout << "This is an owner user." << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual Item* createItem() = 0;
    virtual User* createUser() = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    Item* createItem() override {
        return new LostItem();
    }
    User* createUser() override {
        return new FinderUser();
    }
};

int main() {
    AbstractFactory* factory = new ConcreteFactory1();
    Item* item = factory->createItem();
    User* user = factory->createUser();

    item->show();
    user->show();

    delete item;
    delete user;
    delete factory;
    return 0;
}
