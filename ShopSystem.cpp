void shop(User* user) {
    char choice;
    std::cout << "Welcome to the shop! You have " << user->coins << " coins." << std::endl;
    std::cout << "1. Increase Attack (10 coins)\n2. Increase Spell Damage (10 coins)\n3. Increase Armor (10 coins)\n4. Increase Magic Resistance (10 coins)\n5. Increase Health (10 coins)\nChoose an attribute to buy: ";
    std::cin >> choice;

    if (user->coins >= 10) {
        switch (choice) {
            case '1':
                user->attack += 5;
                user->coins -= 10;
                break;
            case '2':
                user->spellDamage += 5;
                user->coins -= 10;
                break;
            case '3':
                user->armor += 5;
                user->coins -= 10;
                break;
            case '4':
                user->magicResistance += 5;
                user->coins -= 10;
                break;
            case '5':
                user->health += 20;
                user->coins -= 10;
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    } else {
        std::cout << "Not enough coins!" << std::endl;
    }
}
