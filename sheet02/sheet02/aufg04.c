/**
 * Prozedurale Programmierung
 *
 * Integer Arithmetik
 */

#include <stdio.h>
#include <stdint.h>

int main() {
  int16_t a_16, b_16, c_16; // short int
  int32_t a_32, b_32, c_32; // int
  uint16_t a_u16, b_u16, c_u16; // unsigned short int

  b_16 = a_16 = 22222;
  b_32 = a_32 = 22222;

  c_32 = a_32 + b_32;
  c_16 = a_16 + b_16;
  // Wie erwartet int, also 2^32, somit korrektes Ergebnis
  printf("a_32 + b_32 = %d + %d = %d \n\n", a_32, b_32, c_32);
  // wrap around da wieder mal 32767 limit aber 44444 Ergebnis
  printf("a_16 + b_16 = %hd + %hd = %hd\n\n", a_16, b_16, c_16);

  a_u16 = a_16 + c_32;
  // a_unsigned int 16 als Ergebnis: 66666 - 2^16(65536) = 1130
  printf("a_16 + c_32 = %hd + %d = %hu\n\n", a_16, c_32, a_u16);

  a_u16 = 2222;
  b_u16 = -222;
  c_u16 = a_u16 + b_u16;
  // b ist ein unsigned short int, somit 2^16, da nicht minus negativ wrap around und dann wieder 2000, da positiv wrap around
  printf("a_u16 + b_u16 = %hu(=%hd) + %hu(=%hd) = %hu(=%hd)\n\n", a_u16,
         a_u16, b_u16, b_u16, c_u16, c_u16);

  a_32 = 555;
  b_32 = 1001;
  c_16 = c_32 = a_32 * b_32;
  printf("c_16 = c_32 = a_32 * b_32\n");
  // Zuweisung des Wertes c_16 zu c_32, term bleibt unverändert
  printf("%hd = %d = %d * %d\n\n", c_16, c_32, a_32, b_32);
  c_32 = c_16 = a_32 * b_32;
  printf("c_32 = c_16 = a_32 * b_32\n");
  // siehe oben, da c_32 den wert von c_16 bekommen hat.
  printf("%d = %hd = %d * %d\n\n", c_32, c_16, a_32, b_32);

  return 0;
}
