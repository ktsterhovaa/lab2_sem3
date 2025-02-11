#ifndef PERSONGENERATOR_H
#define PERSONGENERATOR_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <random>
#include <string>
#include "Person.h"
#include "MutableArraySequence.h"

class PersonGenerator : public QWidget {
    Q_OBJECT

public:
    PersonGenerator(QWidget *parent = nullptr);
    void generateRandomPerson(Sequence<Person> *seq, int count);
    MutableArraySequence<Person> loadPeopleFromFile(const std::string& filename);

private slots:
    void onGenerateRandomPerson();

private:
    std::string generateRandomString(size_t length);

};

#endif // PERSONGENERATOR_H

