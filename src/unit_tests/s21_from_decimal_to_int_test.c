#include "s21_decimal_test.h"

START_TEST(s21_from_decimal_to_int_1) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  s21_set_scale(&val, 5);
  int res = 1234;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  s21_set_bit(&val, 127, 1);
  s21_set_scale(&val, 5);
  int res = -1234;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  s21_decimal var = {{0, 0, 0, 0}};
  int value = 0;
  s21_from_int_to_decimal(5, &var);
  s21_from_decimal_to_int(var, &value);
  ck_assert_int_eq(5, value);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  int n = 666;
  s21_decimal var = {{0, 1, 0, 0}};
  int value = 0;
  s21_from_int_to_decimal(n, &var);
  s21_from_decimal_to_int(var, &value);
  ck_assert_float_eq_tol(n, value, 10);
}
END_TEST

START_TEST(s21_from_decimal_to_int_5) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_float_eq(number, 2147483647);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_6) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = 133141;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 133141);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_7) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 123451234;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -123451234);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_8) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 18;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -18);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_9) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = UINT_MAX;
  src.bits[1] = UINT_MAX;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0);
  ck_assert_int_eq(result, 1);
}
END_TEST

int check, result, code;

START_TEST(s21_from_decimal_to_int_10) {
  s21_decimal a = {{100, 0, 0, 0}};
  check = 100;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_11) {
  s21_decimal a = {{INT_MAX, 0, 0, 0}};
  check = INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_12) {
  s21_decimal a = {{INT_MAX, INT_MAX, INT_MAX, 0}};
  check = 0;

  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_13) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -3);
}
END_TEST

START_TEST(s21_from_decimal_to_int_14) {
  s21_decimal a = {{INT_MAX, INT_MAX, INT_MAX, INT_MAX}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_15) {
  int result = 0;
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_16) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_17) {
  s21_decimal a = {{INT_MAX, 0, 0, INT_MIN}};
  check = -INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_18) {
  s21_decimal a = {{INT_MAX, 0, 0, INT_MIN}};

  check = -INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_19) {
  s21_decimal a;
  a.bits[0] = 0b10000000000000000000000000000000;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000001;
  check = -2147483648;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_20) {
  s21_decimal a;
  a.bits[0] = 0b00000000000000000000000000000001;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000000;
  check = 1;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_21) {
  s21_decimal a;
  a.bits[0] = 0b10000000000000000000000000000001;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000000;
  check = -2147483647;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_22) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(s21_from_decimal_to_int_23) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_24) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(s21_from_decimal_to_int_25) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 4);
}
END_TEST

START_TEST(s21_from_decimal_to_int_26) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -4);
}
END_TEST

START_TEST(s21_from_decimal_to_int_27) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_28) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000000001111101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_29) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000000001111101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_30) {
  s21_decimal src1;

  src1.bits[0] = 0b00000000000000000000010011001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -12);
}
END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *s = suite_create("from_decimal_to_int");
  TCase *tc = tcase_create("case_from_decimal_to_int");

  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);
  tcase_add_test(tc, s21_from_decimal_to_int_3);
  tcase_add_test(tc, s21_from_decimal_to_int_4);
  tcase_add_test(tc, s21_from_decimal_to_int_5);
  tcase_add_test(tc, s21_from_decimal_to_int_6);
  tcase_add_test(tc, s21_from_decimal_to_int_7);
  tcase_add_test(tc, s21_from_decimal_to_int_8);
  tcase_add_test(tc, s21_from_decimal_to_int_9);
  tcase_add_test(tc, s21_from_decimal_to_int_10);
  tcase_add_test(tc, s21_from_decimal_to_int_11);
  tcase_add_test(tc, s21_from_decimal_to_int_12);
  tcase_add_test(tc, s21_from_decimal_to_int_13);
  tcase_add_test(tc, s21_from_decimal_to_int_14);
  tcase_add_test(tc, s21_from_decimal_to_int_15);
  tcase_add_test(tc, s21_from_decimal_to_int_16);
  tcase_add_test(tc, s21_from_decimal_to_int_17);
  tcase_add_test(tc, s21_from_decimal_to_int_18);
  tcase_add_test(tc, s21_from_decimal_to_int_19);
  tcase_add_test(tc, s21_from_decimal_to_int_20);
  tcase_add_test(tc, s21_from_decimal_to_int_21);
  tcase_add_test(tc, s21_from_decimal_to_int_22);
  tcase_add_test(tc, s21_from_decimal_to_int_23);
  tcase_add_test(tc, s21_from_decimal_to_int_24);
  tcase_add_test(tc, s21_from_decimal_to_int_25);
  tcase_add_test(tc, s21_from_decimal_to_int_26);
  tcase_add_test(tc, s21_from_decimal_to_int_27);
  tcase_add_test(tc, s21_from_decimal_to_int_28);
  tcase_add_test(tc, s21_from_decimal_to_int_29);
  tcase_add_test(tc, s21_from_decimal_to_int_30);
  suite_add_tcase(s, tc);
  return s;
}
