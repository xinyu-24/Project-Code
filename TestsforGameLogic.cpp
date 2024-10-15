void testGenerateEnemies() {
    std::vector<Enemy> enemies = generateEnemies(1);
    ASSERT_EQUAL(2, enemies.size());
}

void testBattle() {
    User user("player", "password");
    user.attack = 10;
    user.health = 100;
    std::vector<Enemy> enemies = {Enemy(5, 0, 0, 0, 50, "Test Enemy")};

    battle(&user, enemies);
    ASSERT_TRUE(user.health > 0);
    ASSERT_TRUE(enemies[0].health <= 0);
    ASSERT_EQUAL(10, user.coins);
}

void runGameLogicTests() {
    testGenerateEnemies();
    testBattle();
}
