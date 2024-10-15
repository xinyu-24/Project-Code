void testUserRegistration() {
    users.clear();
    registerUser("testUser", "testPassword");
    ASSERT_TRUE(users.find("testUser") != users.end());
    ASSERT_EQUAL("testPassword", users["testUser"].password);
}

void testUserLogin() {
    users.clear();
    registerUser("testUser", "testPassword");
    User* user = loginUser("testUser", "testPassword");
    ASSERT_TRUE(user != nullptr);
    ASSERT_EQUAL("testUser", user->username);
}

void runUserSystemTests() {
    testUserRegistration();
    testUserLogin();
}
