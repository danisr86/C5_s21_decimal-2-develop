#include "s21_decimal_test.h"

START_TEST(float_to_decimal_1) {
  float a = 1234567890123456789012345678.0;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_2) {
  float a = 123456789012345678901234567.8;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_3) {
  float a = 12345678901234567890123456.78;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_4) {
  float a = 1234567890123456789012345.678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_5) {
  float a = 123456789012345678901234.5678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_6) {
  float a = 12345678901234567890123.45678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_7) {
  float a = 1234567890123456789012.345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_8) {
  float a = 123456789012345678901.2345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_9) {
  float a = 12345678901234567890.12345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_10) {
  float a = 1234567890123456789.012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_11) {
  float a = 123456789012345678.9012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_12) {
  float a = 12345678901234567.89012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_13) {
  float a = 1234567890123456.7890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_14) {
  float a = 123456789012345.67890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_15) {
  float a = 12345678901234.56789012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_16) {
  float a = 1234567890123.4567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_17) {
  float a = 123456789012.34567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_18) {
  float a = 12345678901.234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_19) {
  float a = 1234567890.1234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_20) {
  float a = 123456789.01234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_21) {
  float a = 12345678.901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_22) {
  float a = 1234567.8901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_23) {
  float a = 123456.78901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_24) {
  float a = 12345.678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_25) {
  float a = 1234.5678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_26) {
  float a = 123.45678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_27) {
  float a = 12.345678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_28) {
  float a = 1.2345678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_29) {
  float a = 0.12345678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_30) {
  float a = 1.2e-27;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

Suite *suite_float_to_decimal(void) {
  Suite *s = suite_create("suite_float_to_decimal");
  TCase *tc = tcase_create("s21_tests");

  tcase_add_test(tc, float_to_decimal_1);
  tcase_add_test(tc, float_to_decimal_2);
  tcase_add_test(tc, float_to_decimal_3);
  tcase_add_test(tc, float_to_decimal_4);
  tcase_add_test(tc, float_to_decimal_5);
  tcase_add_test(tc, float_to_decimal_6);
  tcase_add_test(tc, float_to_decimal_7);
  tcase_add_test(tc, float_to_decimal_8);
  tcase_add_test(tc, float_to_decimal_9);
  tcase_add_test(tc, float_to_decimal_10);
  tcase_add_test(tc, float_to_decimal_11);
  tcase_add_test(tc, float_to_decimal_12);
  tcase_add_test(tc, float_to_decimal_13);
  tcase_add_test(tc, float_to_decimal_14);
  tcase_add_test(tc, float_to_decimal_15);
  tcase_add_test(tc, float_to_decimal_16);
  tcase_add_test(tc, float_to_decimal_17);
  tcase_add_test(tc, float_to_decimal_18);
  tcase_add_test(tc, float_to_decimal_19);
  tcase_add_test(tc, float_to_decimal_20);
  tcase_add_test(tc, float_to_decimal_21);
  tcase_add_test(tc, float_to_decimal_22);
  tcase_add_test(tc, float_to_decimal_23);
  tcase_add_test(tc, float_to_decimal_24);
  tcase_add_test(tc, float_to_decimal_25);
  tcase_add_test(tc, float_to_decimal_26);
  tcase_add_test(tc, float_to_decimal_27);
  tcase_add_test(tc, float_to_decimal_28);
  tcase_add_test(tc, float_to_decimal_29);
  tcase_add_test(tc, float_to_decimal_30);

  suite_add_tcase(s, tc);
  return s;
}