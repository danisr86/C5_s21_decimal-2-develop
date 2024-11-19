#ifndef _SRC_S21_DECIMAL_H_
#define _SRC_S21_DECIMAL_H_

// #define MAX_DEC powf(2.0f, 96.0f) - 1.0
// #define MIN_DEC -powf(2.0f, 96.0f) + 1.0

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned bits[8];
} s21_big_decimal;

typedef union {
  int ui;
  float fl;
} floatbits;

// s21_arithmetic

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// s21_comparison

void s21_copy_decimal(s21_decimal *d1, s21_decimal d2);
void s21_normalize_scale_upper(s21_decimal *d, int norm);
void s21_normalize(s21_decimal *d1, s21_decimal *d2);
void s21_comparison_reverse(int *flag);
int s21_comparison_bits(s21_decimal d1, s21_decimal d2);
int s21_greater_num(int a, int b);
int s21_comparison(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal d1, s21_decimal d2);
int s21_is_less_or_equal(s21_decimal d1, s21_decimal d2);
int s21_is_greater(s21_decimal d1, s21_decimal d2);
int s21_is_greater_or_equal(s21_decimal d1, s21_decimal d2);
int s21_is_equal(s21_decimal d1, s21_decimal d2);
int s21_is_not_equal(s21_decimal d1, s21_decimal d2);

// s21_converters

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// s21_another_functions

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal dec, s21_decimal *result);
int s21_from_decimal_to_double(s21_decimal src, long double *dst);

// s21_arithmetic_big

void s21_add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result);
void s21_sub_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result);
int s21_div_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);
int s21_mul_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);

// print

void print_binary(int num);
void print_decimal(s21_decimal value);
void print_big_decimal(s21_big_decimal value);

// get - set

int s21_get_sign(s21_decimal value);
void s21_set_sign(s21_decimal *value);
int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal *value, int scale);
void s21_set_bit(s21_decimal *value, int index, int bit);
int s21_get_bit(s21_decimal dst, int index);
int s21_get_bit_big(s21_big_decimal dst, int index);
void s21_set_bit_big(s21_big_decimal *dst, int index, int bit);
void s21_set_decimal_zero(s21_decimal *value);
void s21_set_big_decimal_zero(s21_big_decimal *dst);

// other

void s21_decimal_to_big_decimal(s21_decimal value_1, s21_big_decimal *value_2);
void s21_big_decimal_to_decimal(s21_decimal *value_1, s21_big_decimal value_2);
int s21_is_decimal_no_empty(s21_decimal dst);
int s21_is_big_decimal_not_empty(s21_big_decimal dst);
void s21_normalization(s21_big_decimal *value_1, s21_big_decimal *value_2,
                       int diff);
void s21_increase_scale_big_decimal(s21_big_decimal *value, int diff);
void s21_decreace_scale_big_decimal(s21_big_decimal *dst, int n);
int s21_post_normalization(s21_big_decimal *result, int scale);
int s21_shift_big_dec_left(s21_big_decimal *dst, int num);
void s21_shift_big_dec_right(s21_big_decimal *dst, int num);
void s21_find_highest_bit_big_decimal(s21_big_decimal v1, s21_big_decimal v2,
                                      int *bit_1, int *bit_2);
int s21_equation_bits_big_decimal(s21_big_decimal *value_1,
                                  s21_big_decimal *value_2);
int s21_is_greater_big_decimal(s21_big_decimal value_1,
                               s21_big_decimal value_2);
int s21_is_greater_or_equal_big_decimal(s21_big_decimal value_1,
                                        s21_big_decimal value_2);

#endif  // _SRC_S21_DECIMAL_H_