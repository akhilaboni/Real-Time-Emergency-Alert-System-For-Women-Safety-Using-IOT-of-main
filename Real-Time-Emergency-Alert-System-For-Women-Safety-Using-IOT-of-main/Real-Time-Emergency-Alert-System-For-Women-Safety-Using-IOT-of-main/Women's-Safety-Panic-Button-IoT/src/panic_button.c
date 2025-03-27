#include <stdio.h>
#include "panic_button.h"

int panic_button_pressed() {
    // Simulating panic button press detection
    // You would connect a physical button to a GPIO pin here
    return digitalRead(0);  // 1 if button pressed, 0 if not
}
