#include <iostream>
#include <string>

class Person {
public:
    virtual const std::string& getName() const = 0;
    virtual int getAge() const = 0;
};

class Human : public Person {
protected:
    std::string name;
    int age;

public:
    Human(const std::string& name, int age) : name(name), age(age) {}

    const std::string& getName() const override {
        return name;
    }

    int getAge() const override {
        return age;
    }
};

class Student : public Human {
private:
    std::string university;

public:
    Student(const std::string& name, int age, const std::string& university)
        : Human(name, age), university(university) {}

    const std::string& getUniversity() const {
        return university;
    }
};

class Character : public Human {
private:
    std::string personality;

public:
    Character(const std::string& name, int age, const std::string& personality)
        : Human(name, age), personality(personality) {}

    const std::string& getPersonality() const {
        return personality;
    }
};

class Worker : public Human {
private:
    std::string occupation;

public:
    Worker(const std::string& name, int age, const std::string& occupation)
        : Human(name, age), occupation(occupation) {}

    const std::string& getOccupation() const {
        return occupation;
    }
};

class Athlete : public Worker, public Student {
private:
    std::string sport;

public:
    Athlete(const std::string& name, int age, const std::string& university,
            const std::string& occupation, const std::string& sport)
        : Worker(name, age, occupation), Student(name, age, university), sport(sport) {}

    const std::string& getSport() const {
        return sport;
    }
};

int main() {
    Human human("Иван", 30);
    Student student("Мария", 20, "Университет ДВФУ");
    Character character("Алексей", 25, "Добрый");
    Worker worker("Елена", 35, "Инженер");
    Athlete athlete("Дмитрий", 28, "Университет ДВФУ", "Спортсмен", "Бег");

    std::cout << "Имя студента: " << student.getName() << ", Возраст: " << student.getAge()
              << ", Университет: " << student.getUniversity() << std::endl;

    std::cout << "Характер человека: " << character.getName() << ", Возраст: " << character.getAge()
              << ", Характер: " << character.getPersonality() << std::endl;

    std::cout << "Профессия работника: " << worker.getName() << ", Возраст: " << worker.getAge()
              << ", Профессия: " << worker.getOccupation() << std::endl;

    std::cout << "Имя атлета: " << athlete.Student::getName() << ", Возраст: " << athlete.Student::getAge()
              << ", Университет: " << athlete.getUniversity()
              << ", Профессия: " << athlete.Worker::getOccupation() << ", Вид спорта: " << athlete.getSport() << std::endl;

    return 0;
}
