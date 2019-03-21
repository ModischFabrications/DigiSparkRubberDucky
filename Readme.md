# Usage
Plugging the device into a USB-Port will:
1: Connect for programming, waiting 6 seconds
2: Disconnect
3: Connect with user program running

# Installation:
1. Install PlatformIO as usual
2. Select "digispark (USB)" as platform
3. Install drivers to upload programs (https://github.com/micronucleus/micronucleus)

# Programming
1. Pull-out device, start upload, insert again

# Hotfix for Library:
(https://github.com/platformio/platform-atmelavr/issues/113)
`DigiKeyboard.h`:
Change from
```
const PROGMEM char usbHidReportDescriptor[USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH] = { /* USB report descriptor */
  0x05, 0x01,                    // USAGE_PAGE (Generic Desktop) 
  0x09, 0x06,                    // USAGE (Keyboard) 
  0xa1, 0x01,                    // COLLECTION (Application) 
  0x05, 0x07,                    //   USAGE_PAGE (Keyboard) 
  0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl) 
  0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI) 
  0x15, 0x00,                    //   LOGICAL_MINIMUM (0) 
  0x25, 0x01,                    //   LOGICAL_MAXIMUM (1) 
  0x75, 0x01,                    //   REPORT_SIZE (1) 
  0x95, 0x08,                    //   REPORT_COUNT (8) 
  0x81, 0x02,                    //   INPUT (Data,Var,Abs) 
  0x95, 0x01,                    //   REPORT_COUNT (simultaneous keystrokes) 
  0x75, 0x08,                    //   REPORT_SIZE (8) 
  0x25, 0x65,                    //   LOGICAL_MAXIMUM (101) 
  0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated)) 
  0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application) 
  0x81, 0x00,                    //   INPUT (Data,Ary,Abs) 
  0xc0                           // END_COLLECTION 
};
```
to
```
const PROGMEM char usbHidReportDescriptor[USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH] = { /* USB report descriptor */
  (char)0x05, (char)0x01,                    // USAGE_PAGE (Generic Desktop) 
  (char)0x09, (char)0x06,                    // USAGE (Keyboard) 
  (char)0xa1, (char)0x01,                    // COLLECTION (Application) 
  (char)0x05, (char)0x07,                    //   USAGE_PAGE (Keyboard) 
  (char)0x19, (char)0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl) 
  (char)0x29, (char)0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI) 
  (char)0x15, (char)0x00,                    //   LOGICAL_MINIMUM (0) 
  (char)0x25, (char)0x01,                    //   LOGICAL_MAXIMUM (1) 
  (char)0x75, (char)0x01,                    //   REPORT_SIZE (1) 
  (char)0x95, (char)0x08,                    //   REPORT_COUNT (8) 
  (char)0x81, (char)0x02,                    //   INPUT (Data,Var,Abs) 
  (char)0x95, (char)0x01,                    //   REPORT_COUNT (simultaneous keystrokes) 
  (char)0x75, (char)0x08,                    //   REPORT_SIZE (8) 
  (char)0x25, (char)0x65,                    //   LOGICAL_MAXIMUM (101) 
  (char)0x19, (char)0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated)) 
  (char)0x29, (char)0x65,                    //   USAGE_MAXIMUM (Keyboard Application) 
  (char)0x81, (char)0x00,                    //   INPUT (Data,Ary,Abs) 
  (char)0xc0                                 // END_COLLECTION 
};
```
