#include "s21_decimal.h"

int s21_get_sign(s21_decimal value) { return value.bits[3] >> 31; }

void s21_set_sign(s21_decimal *value) {
  value->bits[3] = value->bits[3] | 1u << 31;
}

int s21_get_scale(s21_decimal value) {
  int mask = 0b11111111 << 16;
  int scale = (value.bits[3] & mask) >> 16;
  return scale;
}

void s21_set_scale(s21_decimal *value, int scale) {
  value->bits[3] |= scale << 16;
}

int s21_get_bit(s21_decimal dst, int index) {
  int mask = 1u << (index % 32);
  return (dst.bits[index / 32] & mask) != 0;
}

void s21_set_bit(s21_decimal *value, int index, int bit) {
  int mask = 1u << (index % 32);
  if (bit == 0)
    value->bits[index / 32] = value->bits[index / 32] & ~mask;
  else
    value->bits[index / 32] = value->bits[index / 32] | mask;
}

int s21_get_bit_big(s21_big_decimal dst, int index) {
  int mask = 1u << (index % 32);
  return (dst.bits[index / 32] & mask) != 0;
}

void s21_set_bit_big(s21_big_decimal *dst, int index, int bit) {
  int mask = 1u << (index % 32);
  if (bit == 0)
    dst->bits[index / 32] = dst->bits[index / 32] & ~mask;
  else
    dst->bits[index / 32] = dst->bits[index / 32] | mask;
}

void s21_set_decimal_zero(s21_decimal *value) {
  value->bits[0] = 0;
  value->bits[1] = 0;
  value->bits[2] = 0;
  value->bits[3] = 0;
}

void s21_set_big_decimal_zero(s21_big_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
  dst->bits[4] = 0;
  dst->bits[5] = 0;
  dst->bits[6] = 0;
  dst->bits[7] = 0;
}