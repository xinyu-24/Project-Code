void testShop() {
    User user("player", "password");
    user.coins = 20;

    shop(&user, '1');
    ASSERT_EQUAL(10, user.coins);
    ASSERT_EQUAL(5, user.attack);

    shop(&user, '5');
    ASSERT_EQUAL(0, user.coins);
    ASSERT_EQUAL(20, user.health);
}

void runShopSystemTests() {
    testShop();
}
