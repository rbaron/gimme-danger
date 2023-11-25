#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

#define SLEEP_TIME_MS 250
// PA5. User LED LD4 on nucleo_g071rb.
#define LED_PIN 5

// GPIO port A.
#define IOPORT_BASE (0x50000000UL)
#define GPIOA_BASE (IOPORT_BASE + 0x00000000UL)
#define GPIOA_MODER (GPIOA_BASE + 0x00UL)
#define GPIOA_ODR (GPIOA_BASE + 0x14UL)
#define GPIOA_BSRR (GPIOA_BASE + 0x18UL)

// Clock.
#define PERIPH_BASE (0x40000000UL) /*!< Peripheral base address */
#define AHBPERIPH_BASE (PERIPH_BASE + 0x00020000UL)
#define RCC_BASE (AHBPERIPH_BASE + 0x00001000UL)
#define RCC_IOPENR (RCC_BASE + 0x34UL)

int main(void) {
  // Enable clock on A port.
  *(volatile uint32_t *)RCC_IOPENR |= (0x1 << 0);

  // Set as output -- Write 01 to MODER[11:10].
  *(volatile uint32_t *)GPIOA_MODER &= ~(0x1 << (2 * LED_PIN + 1));
  *(volatile uint32_t *)GPIOA_MODER |= (0x1 << (2 * LED_PIN));

  while (1) {
    // // Write low.
    // *(volatile uint32_t *)GPIOA_ODR |= (0x1 << LED_PIN);
    // k_msleep(SLEEP_TIME_MS);

    // // Write high.
    // *(volatile uint32_t *)GPIOA_ODR &= ~(0x1 << LED_PIN);
    // k_msleep(SLEEP_TIME_MS);

    // Or we can use BSRR.
    // Write high.
    *(volatile uint32_t *)GPIOA_BSRR |= (0x1 << LED_PIN);
    k_msleep(SLEEP_TIME_MS);
    // Write low.
    *(volatile uint32_t *)GPIOA_BSRR |= (0x1 << (LED_PIN + 16));
    k_msleep(SLEEP_TIME_MS);
  }
  return 0;
}
