#ifndef LR2_PERSON_H
#define LR2_PERSON_H
#include <string>
#include <algorithm>
#include <ostream>
struct Person {
    std::string name;
    std::string surname;
    int birthYear;
    float height;
    float weight;
    bool operator==(const Person& other) const {
        return name == other.name;
    }
    bool operator!=(const Person& other) const {
        return !(*this == other);
    }

    friend void swap(Person& first, Person& second) noexcept {
        using std::swap;
        swap(first.name, second.name);
        swap(first.surname, second.surname);
        swap(first.birthYear, second.birthYear);
        swap(first.height, second.height);
        swap(first.weight, second.weight);
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.name << " "
           << person.surname << " "
           << person.birthYear << " "
           << person.height << " "
           << person.weight;
        return os;
    }
};


#endif //LR2_PERSON_H

