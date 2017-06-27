/** ATtiny841 test
 *
 * Author: Michael Shimniok (www.bot-thoughts.com)
 * Description: Sequentially turns on one pin at a time, back and forth
 *   like a Cylon or like Knight Rider from Glenn A. Larson TV shows.)
 *   Skip the RESET pin. For example, with 5 pins, we start at pin 0,
 *   then 1, 2, 3, 4, 3, 2, 1, 0, 1, ... forever.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DELAY 300

/*
 * Define a sequence of PORTB pins to turn on one at a time.
 */
#define MAX_PINS 5
uint8_t pins[MAX_PINS] = { PB0, PB1, PB2, PB3, PB4 };

int main()
{
  int i;

  /*
   * Portable, but not efficient, we enable each of the pins as output.
   */
  for (i = 0; i < MAX_PINS; i++) {
    DDRB |= (1<<pins[i]);
  }

  /*
   * Now we loop turning on the pins, back and forth, forever
   */
  while (1) {

    /* We start at pin 0, and stop at the 2nd-to-last pin */
    for (i = 0; i < MAX_PINS-1; i++) {
      PORTB = (1 << pins[i]);
      _delay_ms(DELAY);
    }

    /* We continue with the last pin, and stop at the 0th */
    for (i = MAX_PINS-1; i > 0; i--) {
      PORTB = (1 << pins[i]);
      _delay_ms(DELAY);
    }

  }

}
