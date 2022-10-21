# [WIP] PORTENTA H7 Proting for Zephyr RTOS 

target zephyr version : v3.0.0

place board sources to zephyr board root
```bash
cd $ZEPHYR_BASE/boards/arm

git clone -b zephyr-v3.0.0 https://github.com/ys-oh/zephyr_portenta_h7.git
```

## Build Projects
<br>

### M7 Project
```bash
west build -b portenta_h7_m7 -s <app/path>
```

### M4 Project
```bash
west build -b portenta_h7_m4 -p <app/path>
```
<br>

## Flashing

### install dependency
```
# macos
brew install dfu-util

# debian
sudo apt install dfu-util
```

### upload M7, M4 firmware
```bash
west flash
```
<br>

## TODO

- [X] bootable application
- [X] boot m7 
- [X] boot m4
- [X] dfu flash
- [X] uart console
- [ ] power mangement
- [X] memory controller
- [X] external flash memory 
- [X] led driver
- [ ] charger driver
- [ ] wifi / ble
- [ ] cryto driver
- [ ] display interface
- [ ] camera interface
- [X] USB FS driver
- [ ] USB HS driver
- [X] USB Console driver

<br>
