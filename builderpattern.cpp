#include <iostream>
#include <string>

// Product
class LostFoundItem {
public:
    std::string itemName;
    std::string itemDescription;
    std::string itemLocation;
    std::string itemDate;
    std::string itemType;

    void show() {
        std::cout << "Item: " << itemName << "\nDescription: " << itemDescription
                  << "\nLocation: " << itemLocation << "\nDate: " << itemDate
                  << "\nType: " << itemType << std::endl;
    }
};

// Builder Interface
class IBuilder {
public:
    virtual void buildItemName(const std::string& name) = 0;
    virtual void buildItemDescription(const std::string& description) = 0;
    virtual void buildItemLocation(const std::string& location) = 0;
    virtual void buildItemDate(const std::string& date) = 0;
    virtual void buildItemType(const std::string& type) = 0;
    virtual LostFoundItem* getResult() = 0;
};

// Concrete Builder
class ItemBuilder : public IBuilder {
private:
    LostFoundItem* item;
public:
    ItemBuilder() { item = new LostFoundItem(); }

    void buildItemName(const std::string& name) override { item->itemName = name; }
    void buildItemDescription(const std::string& description) override { item->itemDescription = description; }
    void buildItemLocation(const std::string& location) override { item->itemLocation = location; }
    void buildItemDate(const std::string& date) override { item->itemDate = date; }
    void buildItemType(const std::string& type) override { item->itemType = type; }
    
    LostFoundItem* getResult() override { return item; }
};

// Director
class Director {
private:
    IBuilder* builder;
public:
    void setBuilder(IBuilder* b) { builder = b; }

    void constructItem(const std::string& name, const std::string& description, 
                       const std::string& location, const std::string& date, const std::string& type) {
        builder->buildItemName(name);
        builder->buildItemDescription(description);
        builder->buildItemLocation(location);
        builder->buildItemDate(date);
        builder->buildItemType(type);
    }
};

int main() {
    Director director;
    ItemBuilder builder;

    director.setBuilder(&builder);
    director.constructItem("Wallet", "Black leather wallet", "Central Park", "2024-07-01", "Lost");

    LostFoundItem* item = builder.getResult();
    item->show();

    delete item; // Clean up dynamically allocated memory
    return 0;
}
