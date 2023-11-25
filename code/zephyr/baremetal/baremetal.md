# Baremetal Programming
## MCU
- [MCU Reference manual](https://www.st.com/resource/en/reference_manual/rm0444-stm32g0x1-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

## Nucleo board
- [Nucleo reference manual](https://www.st.com/resource/en/user_manual/dm00452640-stm32-nucleo-64-boards-with-stm32g07xrb-mcus-stmicroelectronics.pdf)

## Libraries
- [stm32g0xx_hal_driver](https://github.com/STMicroelectronics/stm32g0xx_hal_driver/tree/master/Src)
  - Contains HAL and LL drivers

## Peripherals
### LED
- LED LD4: PA5, active high
- ll means low level, like a HAL interface, but lower level

### Button
- User button B1: PC13, active low

### UCPD
7.3.1:
> Upon reset, the UCPD CCx lines present a pull-down resistor that can be disabled by
setting the UCPDx_STROBE bit of the SYSCFG_CFGR1 register.