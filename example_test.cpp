#include <gtest/gtest.h>
#include "bmstu_stroka.h"

TEST(GoogleTestCi, Foo) {
    ASSERT_TRUE(true);
}

TEST(ExampleTest, DmitriiLeonidovich) {
    std::string dml = "DmitriiLeonidovich";
    const char *dml_c = "DmitriiLeonidovich";
    ASSERT_STREQ(dml.c_str(), dml_c);
}

TEST(Empty, empty_raw) {
    bmstu::string stroka("");
    ASSERT_STREQ(stroka.c_str(), "");
}

TEST(Сonstructor, raw) {
    bmstu::string stroka("Boost");
    ASSERT_STREQ(stroka.c_str(), "Boost");
}

TEST(Сonstructor, Constr_cstrrus) {
    bmstu::wstring stroka(L"дота");
    ASSERT_STREQ(stroka.c_str(), L"дота");
}


TEST(Copy, copy_raw) {
    bmstu::string const stroka("Boost");
    bmstu::string stroka2(stroka);
    ASSERT_STREQ(stroka2.c_str(), "Boost");
}

TEST(Copy, copy_empty_raw) {
    bmstu::string stroka("");
    bmstu::string stroka2(stroka);
    ASSERT_STREQ(stroka2.c_str(), "");
}

TEST(Moving, move_raw) {
    bmstu::string stroka("Boost");
    bmstu::string stroka2(std::move(stroka));
    ASSERT_STREQ(stroka2.c_str(), "Boost");
}

TEST(Moving, move_empty_raw) {
    bmstu::string stroka("");
    bmstu::string stroka2(std::move(stroka));
    ASSERT_STREQ(stroka2.c_str(), "");
}

TEST(Size, raws_size) {
    bmstu::string stroka("Boost");
    ASSERT_EQ(stroka.size(), 5);
}

TEST(Size, raws_size_2bytes) {
    bmstu::wstring stroka(L"дота");
    ASSERT_EQ(stroka.size(), 4);
}

TEST(Size, raws_size_nmbrs) {
    bmstu::wstring stroka(L"123456");
    ASSERT_EQ(stroka.size(), 6);
}

TEST(Size, raws_size_2bytes_and_nmbrs) {
    bmstu::wstring stroka(L"дота2");
    ASSERT_EQ(stroka.size(), 5);
}

TEST(Getter, getter_empty) {
    bmstu::string stroka("");
    ASSERT_EQ(stroka.size(), 0);

}

TEST(Copy, operator_copy) {
    bmstu::string stroka("Boost");
    bmstu::string stroka2("Air");
    stroka = stroka2;
    ASSERT_STREQ(stroka.c_str(), "Air");

}

TEST(Copy, from_full_to_empty) {
    bmstu::string stroka("Boost");
    bmstu::string stroka2("");
    stroka = stroka2;
    ASSERT_STREQ(stroka.c_str(), "");
}

TEST(Copy, from_empty_to_full) {
    bmstu::string stroka("");
    bmstu::string stroka2("Air");
    stroka = stroka2;
    ASSERT_STREQ(stroka.c_str(), "Air");
}

TEST(Copy, operator_copy_in) {
    bmstu::string stroka("Boost");
    stroka = stroka;
    ASSERT_STREQ(stroka.c_str(), "Boost");
}

TEST(Replace, Operator_replace) {
    bmstu::string stroka("Boost");
    bmstu::string stroka2("Air");
    stroka = std::move(stroka2);
    ASSERT_STREQ(stroka.c_str(), "Air");
}

TEST(Replace, replace_from_empty_to_full) {
    bmstu::string stroka("");
    bmstu::string stroka2("Air");
    stroka = std::move(stroka2);
    ASSERT_STREQ(stroka.c_str(), "Air");
}

TEST(Replace, replace_from_full_to_empty) {
    bmstu::string stroka("Boost");
    bmstu::string stroka2("");
    stroka = std::move(stroka2);
    ASSERT_STREQ(stroka.c_str(), "");
}

TEST(Replace, repalace) {
    bmstu::string stroka("Boost");
    stroka = std::move(stroka);
    ASSERT_STREQ(stroka.c_str(), "Boost");
}

TEST(Replace, replace_c) {
    bmstu::string stroka("Boost");
    stroka = "Air";
    ASSERT_STREQ(stroka.c_str(), "Air");
}

TEST(Replace, replace_empty_c) {
    bmstu::string stroka("");
    stroka = "Air";
    ASSERT_STREQ(stroka.c_str(), "Air");
}

TEST(Replace, replace_full_c) {
    bmstu::string stroka("Boost");
    stroka = "";
    ASSERT_STREQ(stroka.c_str(), "");
}

TEST(Replace, put_smth_into_c) {
    bmstu::string stroka;
    stroka = "Boost";
    ASSERT_STREQ(stroka.c_str(), "Boost");
}

TEST(Concatination, concatination) {
    bmstu::string stroka("Boost");
    bmstu::string stroka2("Air");
    stroka += stroka2;
    ASSERT_STREQ(stroka.c_str(), "BoostAir");
}

TEST(Concatination, concatination_with_full) {
    bmstu::string stroka("");
    bmstu::string stroka2("Air");
    stroka += stroka2;
    ASSERT_STREQ(stroka.c_str(), "Air");
}

TEST(Concatination, concatination_with_full_2) {
    bmstu::string stroka("Boost");
    bmstu::string stroka2("");
    stroka += stroka2;
    ASSERT_STREQ(stroka.c_str(), "Boost");
}

TEST(Concatination, concatination_with_full_3) {
    bmstu::string stroka("");
    bmstu::string stroka2("");
    stroka += stroka2;
    ASSERT_STREQ(stroka.c_str(), "");
}

TEST(Concatination, concatination_2bytes) {
    bmstu::string stroka("Boost");
    bmstu::string stroka2("дота");
    stroka += stroka2;
    ASSERT_STREQ(stroka.c_str(), "Boostдота");
}

TEST(Concatination, concatination_with_1_symbol) {
    bmstu::string stroka("Boost");
    stroka += 'a';
    ASSERT_STREQ(stroka.c_str(), "Boosta");
}

TEST(Concatination, concatination_with_null) {
    bmstu::string stroka("Boost");
    stroka += '\0';
    ASSERT_STREQ(stroka.c_str(), "Boost");
}

TEST(Concatination, concatination_with_empty) {
    bmstu::string stroka("");
    stroka += '\0';
    ASSERT_STREQ(stroka.c_str(), "");
}

TEST(Concatination, concatination_with_empty_2) {
    bmstu::string stroka("");
    stroka += 'a';
    ASSERT_STREQ(stroka.c_str(), "a");
}

TEST(Concatination, different_concatination) {
    bmstu::string stroka("Boost");
    bmstu::string stroka2("Air");
    bmstu::string super_stroka = stroka + stroka2;
    ASSERT_STREQ(super_stroka.c_str(), "BoostAir");
}

TEST(Concatination, different_concatination_with_empty) {
    bmstu::string stroka("");
    bmstu::string stroka2("Air");
    bmstu::string super_stroka = stroka + stroka2;
    ASSERT_STREQ(super_stroka.c_str(), "Air");
}

TEST(Concatination, different_concatination_with_2bytes) {
    bmstu::string stroka("дота");
    bmstu::string stroka2("Minecraft");
    bmstu::string super_stroka = stroka + stroka2;
    ASSERT_STREQ(super_stroka.c_str(), "дотаMinecraft");
}


TEST(ExactSymbol, 1_symbol) {
    bmstu::string stroka("Boost");
    ASSERT_EQ(stroka.c_str()[0], 'B');
}

TEST(ExactSymbol, 4_symbol) {
    bmstu::string stroka("Boost");
    ASSERT_EQ(stroka.c_str()[3], 's');
}

TEST(Put, put) {
    std::stringstream stroka;
    stroka.str("BoostAir\n");
    bmstu::string stroka2("Air");
    stroka << stroka2;
    ASSERT_STREQ(stroka.str().c_str(), "AirstAir\n");
}

TEST(Put, put_nmbrs) {
    std::stringstream stroka;
    stroka.str("Boost\n");
    bmstu::string stroka2("123");
    stroka << stroka2;
    ASSERT_STREQ(stroka.str().c_str(), "123st\n");
}