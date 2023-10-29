#include <iostream>
#include <map>
#include <string>

int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    std::map<std::string, std::pair<int, int>> studentMap;

    for (int i = 0; i < numStudents; i++) {
        std::string name;
        int midterm, final;
        std::cin.ignore(); // Remove newline character from previous input
        std::cout << "Enter student name: ";
        std::getline(std::cin, name);
        std::cout << "Enter midterm score for " << name << ": ";
        std::cin >> midterm;
        std::cout << "Enter final score for " << name << ": ";
        std::cin >> final;

        studentMap[name] = std::make_pair(midterm, final);
    }

    std::cout << "\nStudent Information:\n";
    for (const auto& student : studentMap) {
        const std::string& name = student.first;
        int midterm = student.second.first;
        int final = student.second.second;
        std::cout << "Name: " << name << ", Midterm: " << midterm << ", Final: " << final << "\n";
    }

    return 0;
}
