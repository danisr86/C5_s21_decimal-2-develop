#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0, get = 0, sign_res = 0;
  s21_set_decimal_zero(result);
  if (s21_get_sign(value_1) && s21_get_sign(value_2)) {
    sign_res = 1;
  }
  if (s21_get_sign(value_1) != s21_get_sign(value_2)) {
    int sign = 0;
    sign = s21_get_sign(value_1);
    s21_set_bit(&value_1, 127, 0);
    s21_set_bit(&value_2, 127, 0);
    error = sign ? s21_sub(value_2, value_1, result)
                 : s21_sub(value_1, value_2, result);
  } else {
    s21_big_decimal v1 = {0}, v2 = {0}, r = {0};
    int scale = 0;
    s21_decimal_to_big_decimal(value_1, &v1);
    s21_decimal_to_big_decimal(value_2, &v2);
    int diff = s21_get_scale(value_1) - s21_get_scale(value_2);
    if (diff > 0) {
      get = s21_get_scale(value_1);
      s21_set_scale(&value_2, get);
    } else {
      get = s21_get_scale(value_2);
      s21_set_scale(&value_1, get);
    }
    s21_normalization(&v1, &v2, diff);
    s21_add_big_decimal(v1, v2, &r);
    scale = s21_post_normalization(&r, s21_get_scale(value_1));
    if (scale >= 0) {
      s21_big_decimal_to_decimal(result, r);
      s21_set_scale(result, scale);
    } else {
      error = 1;
    }
  }
  sign_res == 1 ? s21_set_sign(result) : 0;
  if (error == 1 && s21_get_sign(*result)) error = 2;
  if (error) s21_set_decimal_zero(result);
  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0, scale = 0, sign_res = 0;
  s21_set_decimal_zero(result);
  if (s21_get_sign(value_1) && s21_get_sign(value_2)) {
    s21_decimal temporary1 = value_1;
    value_1 = value_2;
    value_2 = temporary1;
    s21_set_bit(&value_1, 127, 0);
    s21_set_bit(&value_2, 127, 0);
  }
  if (s21_get_sign(value_1) != s21_get_sign(value_2)) {
    s21_get_sign(value_1) ? sign_res = 1 : 1;
    s21_set_bit(&value_1, 127, 0);
    s21_set_bit(&value_2, 127, 0);
    error = s21_add(value_1, value_2, result);
  } else {
    s21_big_decimal v1 = {0}, v2 = {0}, r = {0};
    s21_decimal_to_big_decimal(value_1, &v1);
    s21_decimal_to_big_decimal(value_2, &v2);
    int diff = s21_get_scale(value_1) - s21_get_scale(value_2);
    diff > 0 ? s21_set_scale(&value_2, s21_get_scale(value_2) + diff)
             : s21_set_scale(&value_1, s21_get_scale(value_1) - diff);
    s21_normalization(&v1, &v2, diff);
    if (s21_is_greater_big_decimal(v2, v1)) {
      s21_big_decimal temporary2 = v1;
      v1 = v2;
      v2 = temporary2;
      s21_set_sign(result);
    }
    s21_sub_big_decimal(v1, v2, &r);
    scale = s21_post_normalization(&r, s21_get_scale(value_1));
    if (scale >= 0) {
      s21_big_decimal_to_decimal(result, r);
      s21_set_scale(result, scale);
    } else {
      error = 1;
    }
  }
  sign_res == 1 ? s21_set_sign(result) : 0;

  if (error == 1 && s21_get_sign(*result)) error = 2;
  if (error) s21_set_decimal_zero(result);
  return error;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0, scale = 0;
  s21_big_decimal v1 = {0}, v2 = {0}, r = {0};
  s21_decimal_to_big_decimal(value_1, &v1);
  s21_decimal_to_big_decimal(value_2, &v2);
  if (s21_get_sign(value_1) != s21_get_sign(value_2)) s21_set_sign(result);
  scale = s21_get_scale(value_1) + s21_get_scale(value_2);
  error = s21_mul_big_decimal(v1, v2, &r);
  scale = s21_post_normalization(&r, scale);
  if (scale >= 0) {
    s21_set_scale(result, scale);
    s21_big_decimal_to_decimal(result, r);
  } else {
    error = 1;
  }
  if (error == 1 && s21_get_sign(*result)) error = 2;
  if (error) s21_set_decimal_zero(result);
  return error;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  if (s21_is_decimal_no_empty(value_2)) {
    int scale = 0, res_scale = 0;
    s21_big_decimal v1 = {0}, v2 = {0}, r = {0};
    s21_decimal_to_big_decimal(value_1, &v1);
    s21_decimal_to_big_decimal(value_2, &v2);
    if (s21_get_sign(value_1) != s21_get_sign(value_2)) s21_set_sign(result);
    scale = s21_div_big_decimal(v1, v2, &r);
    s21_set_scale(&value_1, s21_get_scale(value_1) + scale);
    res_scale = s21_get_scale(value_1) - s21_get_scale(value_2);
    if (res_scale > 0) {
      res_scale = s21_post_normalization(&r, res_scale);
    } else if (res_scale < 0) {
      s21_increase_scale_big_decimal(&r, abs(res_scale));
      res_scale = s21_post_normalization(&r, 0);
    }
    if (res_scale >= 0) {
      s21_big_decimal_to_decimal(result, r);
      s21_set_scale(result, res_scale);
    } else {
      error = 1;
    }
  } else {
    error = 3;
  }
  if (error == 1 && s21_get_sign(*result)) error = 2;
  if (error) s21_set_decimal_zero(result);
  return error;
}