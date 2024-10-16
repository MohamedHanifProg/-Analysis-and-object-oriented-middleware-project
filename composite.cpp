#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include "factorymethod.cpp"


// Composite Pattern
class ItemComponent {
public:
    virtual void add(std::shared_ptr<ItemComponent> component) {}
    virtual void remove(std::shared_ptr<ItemComponent> component) {}
    virtual std::vector<std::shared_ptr<ItemComponent>> search(const std::string& query) const {
        return {};
    }
    virtual void getDetails() const = 0;
    virtual ~ItemComponent() = default;
};

class ItemLeaf : public ItemComponent {
public:
    ItemLeaf(std::string name, std::string description, std::string status)
        : name_(name), description_(description), status_(status) {}

    void getDetails() const override {
        std::cout << "Item: " << name_ << ", " << description_ << ", Status: " << status_ << std::endl;
    }

    std::vector<std::shared_ptr<ItemComponent>> search(const std::string& query) const override {
        if (name_.find(query) != std::string::npos || description_.find(query) != std::string::npos) {
            std::cout << "[Composite] ItemLeaf found matching query: " << name_ << std::endl;
            return {std::make_shared<ItemLeaf>(*this)};
        }
        return {};
    }

private:
    std::string name_;
    std::string description_;
    std::string status_;
};

class ItemComposite : public ItemComponent {
public:
    ItemComposite(std::string name, std::string type)
        : name_(name), type_(type) {}

    void add(std::shared_ptr<ItemComponent> component) override {
        std::cout << "[Composite] Adding component to " << type_ << ": " << name_ << std::endl;
        components_.push_back(component);
    }

    void remove(std::shared_ptr<ItemComponent> component) override {
        std::cout << "[Composite] Removing component from " << type_ << ": " << name_ << std::endl;
        components_.erase(std::remove(components_.begin(), components_.end(), component), components_.end());
    }

    void getDetails() const override {
        std::cout << type_ << ": " << name_ << std::endl;
        for (const auto& component : components_) {
            component->getDetails();
        }
    }

    std::vector<std::shared_ptr<ItemComponent>> search(const std::string& query) const override {
        std::vector<std::shared_ptr<ItemComponent>> results;
        for (const auto& component : components_) {
            auto sub_results = component->search(query);
            results.insert(results.end(), sub_results.begin(), sub_results.end());
        }
        return results;
    }

private:
    std::string name_;
    std::string type_;
    std::vector<std::shared_ptr<ItemComponent>> components_;
};
