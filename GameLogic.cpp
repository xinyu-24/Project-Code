#include <vector>
#include <cstdlib>
#include <ctime>

class Enemy {
public:
    int attack;
    int spellDamage;
    int magicResistance;
    int armor;
    int health;
    std::string type;

    Enemy(int atk, int sdm, int mr, int arm, int hp, std::string t)
        : attack(atk), spellDamage(sdm), magicResistance(mr), armor(arm), health(hp), type(t) {}
};

std::vector<Enemy> generateEnemies(int level) {
    std::vector<Enemy> enemies;
    srand(time(0));
    for (int i = 0; i < 2; ++i) {
        int type = rand() % 4;
        switch (type) {
            case 0:
                enemies.push_back(Enemy(10, 0, 0, 15, 100, "A"));
                break;
            case 1:
                enemies.push_back(Enemy(15, 0, 0, 0, 80, "B"));
                break;
            case 2:
                enemies.push_back(Enemy(5, 10, 15, 0, 90, "C"));
                break;
            case 3:
                enemies.push_back(Enemy(10, 10, 10, 10, 120, "D"));
                break;
        }
    }
    return enemies;
}

void battle(User* user, std::vector<Enemy>& enemies) {
    for (auto& enemy : enemies) {
        while (user->health > 0 && enemy.health > 0) {
            // Simple battle logic: user and enemy attack each other
            enemy.health -= user->attack;
            user->health -= enemy.attack;
            std::cout << "You attack the enemy. Enemy's remaining health: " << enemy.health << std::endl;
            std::cout << "Enemy attacks you. Your remaining health: " << user->health << std::endl;
        }
        if (user->health <= 0) {
            std::cout << "You have been defeated!" << std::endl;
            return;
        } else {
            std::cout << "You have defeated the enemy!" << std::endl;
            user->coins += 10; // Earn coins for defeating the enemy
        }
    }
    std::cout << "You cleared this level!" << std::endl;
}
