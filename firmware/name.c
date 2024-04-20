#include <usb_names.h>

#define MANUFACTURER_NAME          \
	{                          \
		'T', 'H', 'E', '_', 'M', 'A', 'R', 'I', 'D', 'A', 'Y' \
	}
#define MANUFACTURER_NAME_LEN 11

#define PRODUCT_NAME                                                            \
	{                                                                       \
		'F', 'C', '_', 'M', 'E', 'G', 'A' \
	}
#define PRODUCT_NAME_LEN 7

#define SERIAL_NUMBER                                            \
	{                                                        \
		'F', 'C', 'M', '0', '0', '1' \
	}
#define SERIAL_NUMBER_LEN 6

struct usb_string_descriptor_struct usb_string_manufacturer_name = {
	2 + MANUFACTURER_NAME_LEN * 2,
	3,
	MANUFACTURER_NAME};

struct usb_string_descriptor_struct usb_string_product_name = {
	2 + PRODUCT_NAME_LEN * 2,
	3,
	PRODUCT_NAME};

struct usb_string_descriptor_struct usb_string_serial_number = {
	2 + SERIAL_NUMBER_LEN * 2,
	3,
	SERIAL_NUMBER};