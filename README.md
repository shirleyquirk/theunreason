## to install:

install arduino-cli

from this directory:

`$ arduino-cli upload --input-dir bin/switchcase --fqbn arduino:avr:mega -p <port>`

where `<port>` is the device the arduino is on, like /dev/ACM0 or COM3
and `bin/switchcase` or `bin/anim_array` for code compiled with the first or second option.

## to create a new binary:

```
$ mkdir bin/<binary_name>
$ arduino-cli compile --fqbn arduino:avr:mega --output-dir bin/<binary_name> UNREASON_DODGEM_SIDE_RELAY_v3
```

## to backup:

maybe https://forum.arduino.cc/t/how-to-backup-the-flash-and-eeprom-of-a-mega2560/886107
untested.
