#include "composite.cpp"
int main() {
    std::cout << "\n--- Factory Method and Prototype Pattern ---\n" << std::endl;

    // Factory Method and Prototype
    LostItemFactory lostFactory;
    FoundItemFactory foundFactory;

    auto lostItem1 = lostFactory.createItem("Wallet", "Black leather wallet");
    auto foundItem1 = foundFactory.createItem("Phone", "White iPhone");

    lostItem1->getDetails();
    foundItem1->getDetails();

    auto lostItemClone = lostItem1->clone();
    auto foundItemClone = foundItem1->clone();

    lostItemClone->getDetails();
    foundItemClone->getDetails();

    std::cout << "\n--- Composite Pattern ---\n" << std::endl;

    // Composite Pattern
    auto wallet = std::make_shared<ItemLeaf>("Wallet", "Black leather wallet", "Lost");
    auto phone = std::make_shared<ItemLeaf>("Phone", "White iPhone", "Lost");
    auto keys = std::make_shared<ItemLeaf>("Keys", "House and car keys", "Lost");

    auto electronics = std::make_shared<ItemComposite>("Electronics", "Category");
    auto clothing = std::make_shared<ItemComposite>("Clothing", "Category");
    auto documents = std::make_shared<ItemComposite>("Documents", "Category");

    electronics->add(phone);
    clothing->add(wallet);
    documents->add(keys);

    auto lostItems = std::make_shared<ItemComposite>("Lost Items", "Status");
    lostItems->add(electronics);
    lostItems->add(clothing);
    lostItems->add(documents);

    std::cout << "\nLost Items Details:" << std::endl;
    lostItems->getDetails();

    // Search within categories
    std::cout << "\n=== Searching for 'Phone' ===" << std::endl;
    auto searchResults = lostItems->search("Phone");
    for (const auto& result : searchResults) {
        result->getDetails();
    }

    return 0;
}
