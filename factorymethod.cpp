#include <iostream>
#include <memory>
#include "prototype.cpp"
class ItemFactory {
public:
    virtual std::shared_ptr<Item> createItem(std::string name, std::string description) const = 0;
    virtual ~ItemFactory() = default;
};

class LostItemFactory : public ItemFactory {
public:
    std::shared_ptr<Item> createItem(std::string name, std::string description) const override {
        return std::make_shared<LostItem>(name, description);
    }
};

class FoundItemFactory : public ItemFactory {
public:
    std::shared_ptr<Item> createItem(std::string name, std::string description) const override {
        return std::make_shared<FoundItem>(name, description);
    }
};
