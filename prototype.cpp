#include <iostream>
#include <string>
#include <memory>

// Prototype Pattern
class Item {
public:
    virtual std::shared_ptr<Item> clone() const = 0;
    virtual void getDetails() const = 0;
    virtual ~Item() = default;
};

class LostItem : public Item {
public:
    LostItem(std::string name, std::string description)
        : name_(name), description_(description) {}

    std::shared_ptr<Item> clone() const override {
        return std::make_shared<LostItem>(*this);
    }

    void getDetails() const override {
        std::cout << "Lost Item: " << name_ << ", " << description_ << std::endl;
    }

private:
    std::string name_;
    std::string description_;
};

class FoundItem : public Item {
public:
    FoundItem(std::string name, std::string description)
        : name_(name), description_(description) {}

    std::shared_ptr<Item> clone() const override {
        return std::make_shared<FoundItem>(*this);
    }

    void getDetails() const override {
        std::cout << "Found Item: " << name_ << ", " << description_ << std::endl;
    }

private:
    std::string name_;
    std::string description_;
};
