#include "s21_decimal_test.h"

START_TEST(is_less_or_equal_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit(&val1, 127, 1);
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_9) {
  float a = -25.158531;
  float b = -39.425785;

  s21_decimal _a = {{0}};
  s21_decimal _b = {{0}};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_less_or_equal(_a, _b), a <= b);
}
END_TEST

START_TEST(is_less_or_equal_10) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_11) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_or_equal_12) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_2);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_13) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_2);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_or_equal_14) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1);
  s21_set_sign(&value_2);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_15) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_scale(&value_2, 2);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_or_equal_16) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_or_equal_17) {
  float num1 = 1.375342323523;
  float num2 = 1.39;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal_18) {
  float num1 = 1.39;
  float num2 = 1.39;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal_19) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_less_or_equal_20) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal_21) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal_22) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal_23) {
  float num1 = -3453434.232446543232446543;
  float num2 = -3.232323233232323233;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal_24) {
  float num1 = -34534553434.232446543232446543;
  float num2 = 34534553434.232446543232446543;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal_25) {
  float num1 = 1.78;
  float num2 = 1.39;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_less_or_equal_26) {
  float num1 = -3453453452.0;
  float num2 = -34.0;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal_27) {
  float num1 = 104235454634.34534534;
  float num2 = 1042354546.34534534;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_less_or_equal_28) {
  float num1 = 1042354546.34534534;
  float num2 = 104235454634.345345;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_less_or_equal_29) {
  float num1 = 1042.5667777;
  float num2 = 1042.345345;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

Suite *suite_is_less_or_equal(void) {
  Suite *s = suite_create("suite_is_less_or_equal");
  TCase *tc = tcase_create("case_is_less_or_equal");
  tcase_add_test(tc, is_less_or_equal_1);
  tcase_add_test(tc, is_less_or_equal_2);
  tcase_add_test(tc, is_less_or_equal_3);
  tcase_add_test(tc, is_less_or_equal_4);
  tcase_add_test(tc, is_less_or_equal_5);
  tcase_add_test(tc, is_less_or_equal_6);
  tcase_add_test(tc, is_less_or_equal_7);
  tcase_add_test(tc, is_less_or_equal_8);
  tcase_add_test(tc, is_less_or_equal_9);
  tcase_add_test(tc, is_less_or_equal_10);
  tcase_add_test(tc, is_less_or_equal_11);
  tcase_add_test(tc, is_less_or_equal_12);
  tcase_add_test(tc, is_less_or_equal_13);
  tcase_add_test(tc, is_less_or_equal_14);
  tcase_add_test(tc, is_less_or_equal_15);
  tcase_add_test(tc, is_less_or_equal_16);
  tcase_add_test(tc, is_less_or_equal_17);
  tcase_add_test(tc, is_less_or_equal_18);
  tcase_add_test(tc, is_less_or_equal_19);
  tcase_add_test(tc, is_less_or_equal_20);
  tcase_add_test(tc, is_less_or_equal_21);
  tcase_add_test(tc, is_less_or_equal_22);
  tcase_add_test(tc, is_less_or_equal_23);
  tcase_add_test(tc, is_less_or_equal_24);
  tcase_add_test(tc, is_less_or_equal_25);
  tcase_add_test(tc, is_less_or_equal_26);
  tcase_add_test(tc, is_less_or_equal_27);
  tcase_add_test(tc, is_less_or_equal_28);
  tcase_add_test(tc, is_less_or_equal_29);

  suite_add_tcase(s, tc);
  return s;
}