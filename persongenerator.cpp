#include "persongenerator.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>
PersonGenerator::PersonGenerator(QWidget *parent) : QWidget(parent) {
    QPushButton *button = new QPushButton("Generate Random Person", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button);
    setLayout(layout);
    connect(button, &QPushButton::clicked, this, &PersonGenerator::onGenerateRandomPerson);
}

void PersonGenerator::onGenerateRandomPerson() {
    MutableArraySequence<Person> *seq = new MutableArraySequence<Person>();
    generateRandomPerson(seq, 1);
}

std::string PersonGenerator::generateRandomString(size_t length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string result;
    std::uniform_int_distribution<size_t> dist(0, characters.size() - 1);
    std::default_random_engine engine(std::random_device{}());
    for (size_t i = 0; i < length; ++i) {
        result += characters[dist(engine)];
    }
    return result;
}

void PersonGenerator::generateRandomPerson(Sequence<Person> *seq, int count) {
    std::uniform_int_distribution<int> birthYearDist(1924, 2010);
    std::uniform_real_distribution<float> heightDist(1.50, 2.00);
    std::uniform_real_distribution<float> weightDist(50.0, 100.0);
    std::default_random_engine engine(std::random_device{}());
    for (int i = 0; i < count; i++) {
        Person person;
        person.surname = generateRandomString(8);
        person.name = generateRandomString(5);
        person.birthYear = birthYearDist(engine);
        person.height = heightDist(engine);
        person.weight = weightDist(engine);
        seq->append(person);
    }
}
MutableArraySequence<Person> PersonGenerator::loadPeopleFromFile(const std::string& filename) {
    MutableArraySequence<Person> people;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return people;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Person person;

        if (iss >> person.name >> person.surname >> person.birthYear >> person.height >> person.weight) {
            people.push_back(person);
        } else {
            std::cerr << "Error reading line: " << line << std::endl;
        }
    }
    file.close();
    return people;
}
