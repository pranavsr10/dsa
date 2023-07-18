#include <iostream>
#include <vector>

class Person {
private:
    int id;

public:
    Person(int personId) : id(personId) {}

    int getId() const {
        return id;
    }
};

class Building {
private:
    int levels;
    std::vector<std::vector<Person>> floors;

public:
    Building(int numLevels) : levels(numLevels) {
        floors.resize(levels);
    }

    void addPerson(int level, const Person& person) {
        floors[level].push_back(person);
    }

    void listExitingOrder() {
        std::vector<int> exitingOrder;
        for (int i = levels - 1; i >= 0; --i) {
            for (const auto& person : floors[i]) {
                exitingOrder.push_back(person.getId());
            }
        }

        std::cout << "Order of meeting while exiting:\n";
        for (const auto& id : exitingOrder) {
            std::cout << id << " ";
        }
        std::cout << std::endl;
    }

    void listEnteringOrder() {
        std::vector<int> enteringOrder;
        for (int i = 0; i < levels; ++i) {
            for (const auto& person : floors[i]) {
                enteringOrder.push_back(person.getId());
            }
        }

        std::cout << "Order of meeting while entering:\n";
        for (const auto& id : enteringOrder) {
            std::cout << id << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int levels;
    std::cout << "Enter the number of levels in the building: ";
    std::cin >> levels;

    Building building(levels);

    int totalPeople = (1 << levels) - 1; // 2^levels - 1

    for (int i = 0; i < totalPeople; ++i) {
        Person person(i + 1);
        int level = 0;

        while ((i & (1 << level)) != 0) {
            ++level;
        }

        building.addPerson(level, person);
    }

    building.listExitingOrder();
    building.listEnteringOrder();

    return 0;
}
