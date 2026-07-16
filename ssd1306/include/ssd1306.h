#ifndef SSD1306_H //Esse arquivo já foi incluído? Header Guards.
#define SSD1306_H //Marca que esse arquivo já foi incluído. Header Guards.

#include "esp_err.h"
#include <stdint.h>

esp_err_t ssd1306_init(void); //Existe uma função com esse nome e essa assinatura.

esp_err_t ssd1306_write_command(uint8_t command)



#endif //Header Guards.