# Load Switch

Power dissipation:
- P = I^2 * R
- For 5A, Rdson = 30 mOhm, P = 0.75 W, say 1 W

- Digikey search [link](https://www.digikey.com/en/products/filter/single-fets-mosfets/278?s=N4IgjCBcoGwAwyqAxlAZgQwDYGcCmANCAPZQDaIAzABwCsYclIAukQA4AuUIAyhwE4BLAHYBzEAF8iMMACYkIVJEy5CJcuAAsCWQHYQRWnE2yY86QE5aMuAZD0TtJkVlxZeiETC7KcBHc1aal1NfS9dCzBNRBc4akc7VwtKTWcQWUoo2nN0ylkLC01Eyl83RJgYCzNyyuo000qLMJBKuFpIxPpaXRzZLp9OsG6il36LQaDbUb7KWk7M43mwMGpO7Sq10Jj02k1Q8dG96m3ZagZtRLPjA-Sr7MuGJweEKZBNCzbdV9Nk33Lf%2BqVEpzFyVGBBRJfGCBSEIeiwiq9XTeM6QlHNfKBCqJQrWDG43T4wJ1S6zWgg26zcGXbTUlzxOBfGmMimnPYwVb0owwZq%2BbL3FxVOr4jk0Oy6ajxSg3fI%2BCyc9JNbTfJUrcUVGis%2BXs8XSspEOVtXWREYgOUyOzgyKeN7da2WmS6bbUOBDG0uoY3D3VIgewri6yUZq6XbJBVO10Up3uV7RjJ2YIpNKJzQKxM%2BkCJ%2BXqipwL1gaXu7yyd0xnIcpx0OwWDK7au1ik1qn1ygWojvFIXIhNga%2B4JNBORVyDqI5JqMZrjzQ2qeNr7UG7j-3dr7Zld5xcpF3V1vdHcRBUMPLL8CMPKHs8lHM0bYVm92BjUU5pR8pG7nK4P4xnF9yPbNZZZCxB8wDMEwQLMAVwFA-JD1A0pr2CECrBrZCZHfMAqhLHN4EPVIkwffCYS8VJpxyKIUncQjKNNCiEhIyiANIlIHxoJpyPeU5XlAuR4S8GQ%2Bm2HjTHIgToQfGQ%2BQfQpKgxbwrBOdxMJyehPhtDI6g2FwaG0dSdKNbT4mWRJp1FEynSZUYQlOcpfFA8pAgiSFCxtCI82sZymnqCVHktAoCjSJ0Cn8QUmlRA0Vkw8UFzVX1pydBNpyfBNujrX1UuaOgJTTO00g%2BORJwLBdq2iGA8uiCUSo5GdoirLxXXBG1HhrWjlicci2pYrwskJEDdio9sPm6JrIo%2BECziscbXA6p9-FYEBOG4PghDESQvAKIpoEUdBsHwIhSEgCh3HyRJXQxPYIHmxbIF4AQRHECQpHSDQ2AAAmQAALDBhGEPAsBYaQFEEAATbgAFoGBya6QDsDgAE82DwbhgZwVBHqAA)
- [AONR21321](https://aosmd.com/res/data_sheets/AONS21321.pdf)
  - -25 Vgsmax (no zenner needed)
  - 10 amps
  - $ 0.16 on JLCPCB C541711 (but only 260 available)
  - > 3W power dissipation
- [DMP3013](https://www.diodes.com/assets/Datasheets/DMP3013SFV.pdf)
  - -25 Vgsmax (no zenner needed)
  - 10 amps
  - $ 0.33 on JLCPCB (~ 3k available)
  - Only 900 mW of power dissipation?
- [Si7149ADP](https://www.vishay.com/docs/62839/si7149adp.pdf)
  - -25 Vgsmax (no zenner needed)
  - > 3W power dissipation
  - $ 1.30 on JLCPCB (only ~140 available)
- [AON6407](https://aosmd.com/res/data_sheets/AON6407.pdf)
  - -25 Vgsmax (no zenner needed)
  - Very low Rdson ~ 6 mOhm
  - Bigger footprint?
  - 85 A lol -- overkill? But does it matter? Downside: almost double footprint than AONR21321, but still small for us
  - 5W power dissipation
  - $ 0.5 on JLCPCB (7k available) C13899
  - Good choice
- [AO4407A](https://aosmd.com/res/data_sheets/AO4407A.pdf)
  - -25 Vgsmax (no zenner needed)
  - RDs ~ 20 mOhm @ 5 V
  - 12 A
  - > 2W power dissipation
  - $ 0.15 on JLCPCB (10k+ available) C16072
  - SOP-8 package, with the leads it's as big as the AO6407A above...
  - Good choice

## Bidirectional switch
- [Digikey search](https://www.digikey.ch/en/products/filter/fet-mosfet-arrays/289?s=N4IgjCBcoGwAwHYqgMZQGYEMA2BnApgDQgD2UA2uACwDMAHHDSMWAKwCcATFUi3VRzrMQnNjTithnegnpTa7VjCmsEMKp2Ex2MTuxABdYgAcALlBABlUwCcAlgDsA5iAC%2BxeEOgg0kLHiJSChEeBDhlYmk4OjA4KXEGIUiaMBoEfWSwdgl4zjoYXhEaKjgwKniqKiypGF06JJFa8XLI2s4YCEjWcJhJLs44KgiRVj0ClRK2CYQq6ZKpBjCG9vq6TVbVuMiwqqZtwc51kQQwWS2RdjTRqUuEbgX6DWFm7L6QNVrEZ8HLjJBmujsP5jVisFogfJ0BCFGApdJvMoDbLCMAdMCnFF0Gjdc5gLGjXFYqiXFS1dGGEzmSBWWyOFzuEAAWk03l8tgAroEyJBKJIDK4GSzKAATdk4AAExnFKAAFpgHA58NgKSBlN47MKLIzYkczBZhKYAJ7GfAWYW4NACoA)
- [DMP3098LSD-13](https://jlcpcb.com/partdetail/DiodesIncorporated-DMP3098LSD13/C531177)
  - The one Phil uses
  - Dual P-channel MOSFET
  - Vgsmax = 20 V
  - Vds = -30 V
  - But Id is low: 3.3 A
- [AO4805](https://jlcpcb.com/parts/componentSearch?searchTxt=AO4805)
  - Good choice
  - 25 mOhm (kinda good for 2 MOSFETs)
- [DMP3028LSD-13](https://jlcpcb.com/partdetail/DiodesIncorporated-DMP3028LSD13/C397949)
  - Also good choice
  - Not as many available on JLCPCB

Use a BJT to drive the MOSFET gate?
- Inverts the signal (NOT gate)
- [DDTC1](https://datasheet.lcsc.com/lcsc/2304140030_Diodes-Incorporated-DDTC114EUA-7-F_C177021.pdf)
  - Self-biased (includes base and base-emitter resistors)
  - If we drive with 3.3V,
-

## Design
- [TI's bidirectional design with P-channel MOSFETs](https://www.ti.com/lit/an/slva948/slva948.pdf)
- [nxp load switch basics](https://www.nxp.com/docs/en/white-paper/NXP_Load_Switch_Basics.pdf)


## PWM drivers
Low side switching fine?
No need for high Vgsmax (we only switch between 0 and 3.3V).

- [AO3400A](https://aosmd.com/sites/default/files/res/data_sheets/AO3400A.pdf)
  - 5A
  - ~ 1W power dissipation
- [AON7410](https://datasheet.lcsc.com/lcsc/1808280434_Alpha---Omega-Semicon-AON7410_C269266.pdf)
  - 2W power dissipation
  -