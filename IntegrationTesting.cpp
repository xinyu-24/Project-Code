void testGameFlow() {
    users.clear();
    registerUser("player", "password");
    User* user = loginUser("player", "password");

    for (int level = 1; level <= 6; ++level) {
        std::vector<Enemy> enemies = generateEnemies(level);
        battle(user, enemies);

        if (user->health <= 0) {
            ASSERT_FALSE(user->health > 0);
            break;
        }

        if (level % 2 == 0) {
            user->coins = 10; // Ensure user can shop
            shop(user);
        }
    }

    ASSERT_TRUE(user->health > 0);
}

void runIntegrationTests() {
    testGameFlow();
}
