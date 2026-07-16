#include "ssd1306.h"

#include "driver/i2c_master.h"
#include "driver/gpio.h"

#include <stdint.h>

static i2c_master_bus_handle_t bus_handle = NULL;
static i2c_master_dev_handle_t oled_handle = NULL;

esp_err_t ssd1306_init(void)
{
}

static esp_err_t ssd1306_create_bus(void)
{
    i2c_master_bus_config_t bus_config = {
        .i2c_port = I2C_NUM_0,
        .sda_io_num = GPIO_NUM_21,
        .scl_io_num = GPIO_NUM_22,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    esp_err_t ret = i2c_new_master_bus(&bus_config, &bus_handle);

    if (ret != ESP_OK)
    {
        return ret;
    }
};

static esp_err_t ssd1306_create_device(void)
{
    i2c_device_config_t device_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = 0x3C,
        .scl_speed_hz = 100000,
    };

    i2c_master_bus_add_device(bus_handle, &device_config, &oled_handle);

    i2c_master_transmit(oled_handle, &ssd1306_write_command, 1, 1000);
}

esp_err_t ssd1306_write_command(uint8_t command)
{

    if (oled_handle == NULL)
    {
        return ESP_ERR_INVALID_STATE;
    }

    uint8_t buffer[] = {
        0x00,
        command};

    i2c_master_receive()
}
