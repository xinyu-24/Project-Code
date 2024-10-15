int main() {
    int choice;
    User* loggedInUser = nullptr;

    while (true) {
        std::cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loggedInUser = loginUser();
                if (loggedInUser) {
                    for (int level = 1; level <= 6; ++level) {
                        std::vector<Enemy> enemies = generateEnemies(level);
                        battle(loggedInUser, enemies);
                        if (level % 2 == 0) {
                            shop(loggedInUser);
                        }
                        if (loggedInUser->health <= 0) {
                            std::cout << "Game over!" << std::endl;
                            break;
                        }
                    }
                }
                break;
            case 3:
                std::cout << "Exiting game." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    }

    return 0;
}
