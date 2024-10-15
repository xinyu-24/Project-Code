#include <iostream>
#include <string>
#include <unordered_map>

class User {
public:
    std::string username;
    std::string password;
    // Player class and attributes
    std::string profession;
    int attack;
    int spellDamage;
    int magicResistance;
    int armor;
    int health;
    int coins;

    User(std::string uname, std::string pwd) : username(uname), password(pwd), coins(0) {}
};

std::unordered_map<std::string, User> users;

void registerUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (users.find(username) != users.end()) {
        std::cout << "Username already exists. Please try again." << std::endl;
    } else {
        users[username] = User(username, password);
        std::cout << "Registration successful!" << std::endl;
    }
}

User* loginUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (users.find(username) != users.end() && users[username].password == password) {
        std::cout << "Login successful!" << std::endl;
        return &users[username];
    } else {
        std::cout << "Incorrect username or password. Please try again." << std::endl;
        return nullptr;
    }
}
