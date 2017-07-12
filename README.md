## ISOLight Hardware
collection charleen's projects

### TODO
* Auto-connect BT (directed)
* Create a log for eventual error 
* Refactoring of the hole code
* WhiteList (remember old devices)
* Set a max connection to the board
* Set a update manager

#### Bluetooth Scheme
![GitHub Logo](http://static.thegeekstuff.com/wp-content/uploads/2014/07/ti-ble-profile.png)

###General Documentation 
#### rgb service (write)
this service is used to send data to phone device by using BLEDevice object Id
#### UUID (read) socketID integer
unique ID to let the phone identify the bluetooth device
####BLEDevice ble device (phone)
this is the object that contain all the information from the phone device
####PwmOut pin board LED
this object is used to define pin on the motherboard
