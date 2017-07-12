#include "mbed.h"
#include "ble/BLE.h"

PwmOut r(p1);   //p1  rigado p16 beacon
PwmOut g(p25);   //p25 rigado p12 beacon
PwmOut b(p24);   //p24 rigado p15 beacon
uint16_t rgbUUID  = 0xA000;
uint16_t UUID     = 0xA001;

const static char     DEVICE_NAME[]        = "ISOLIGHT"; 


static uint8_t Value[10] = {0};
WriteOnlyArrayGattCharacteristic<uint8_t, sizeof(Value)> Char(UUID, Value);


BLEDevice           ble;
GattCharacteristic *characteristics[] = {&Char};
GattService        rgbService(rgbUUID, characteristics, sizeof(characteristics) / sizeof(GattCharacteristic *));


void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *)
{
    ble.gap().startAdvertising();
    r.write(0.0);   //(0.0) pour rigado (1.0) pour beacon
    g.write(0.0);   //(0.0) pour rigado (1.0) pour beacon
    b.write(0.0);   //(0.0) pour rigado (1.0) pour beacon
}


void writeCharCallback(const GattWriteCallbackParams *params){
    if(params->handle == Char.getValueHandle()) {
            if ( *(params->data) == 00 ){
                r = 0/255.0f;
                g = 0/255.0f;
                b = 0/255.0f;
            }
            else if ( *(params->data) == 01 ){
                r = 255/255.0f;
                g = 255/255.0f;
                b = 255/255.0f;
            }               
            else if ( *(params->data) == 02 ){
                r = 255/255.0f;
                g = 204/255.0f;
                b = 204/255.0f;
            }
            else if ( *(params->data) == 03 ){
                r = 255/255.0f;
                g = 204/255.0f;
                b = 153/255.0f;
            } 
            else if ( *(params->data) == 04 ){
                r = 255/255.0f;
                g = 255/255.0f;
                b = 153/255.0f;
            }               
            else if ( *(params->data) == 05 ){
                r = 153/255.0f;
                g = 255/255.0f;
                b = 153/255.0f;
            }
            else if ( *(params->data) == 06 ){
                r = 153/255.0f;
                g = 255/255.0f;
                b = 255/255.0f;
            } 
            else if ( *(params->data) == 07 ){
                r = 204/255.0f;
                g = 204/255.0f;
                b = 255/255.0f;
            }               
            else if ( *(params->data) == 38 ){ //8 ne fonctionne pas, pourquoi?
                r = 255/255.0f;
                g = 153/255.0f;
                b = 255/255.0f;
            }
            else if ( *(params->data) == 39 ){ //9 ne fonctionne pas, pourquoi?
                r = 255/255.0f;
                g = 102/255.0f;
                b = 102/255.0f;
            } 
            else if ( *(params->data) == 10 ){
                r = 255/255.0f;
                g = 153/255.0f;
                b = 102/255.0f;
            }               
            else if ( *(params->data) == 11 ){
                r = 255/255.0f;
                g = 255/255.0f;
                b = 102/255.0f;
            }
            else if ( *(params->data) == 12 ){
                r = 255/255.0f;
                g = 255/255.0f;
                b = 51/255.0f;
            } 
            else if ( *(params->data) == 13 ){
                r = 51/255.0f;
                g = 255/255.0f;
                b = 51/255.0f;
            }               
            else if ( *(params->data) == 14 ){
                r = 0/255.0f;
                g = 255/255.0f;
                b = 255/255.0f;
            }
            else if ( *(params->data) == 15 ){
                r = 153/255.0f;
                g = 153/255.0f;
                b = 255/255.0f;
            } 
            else if ( *(params->data) == 16 ){
                r = 255/255.0f;
                g = 0/255.0f;
                b = 255/255.0f;
            }               
            else if ( *(params->data) == 17 ){
                r = 255/255.0f;
                g = 0/255.0f;
                b = 0/255.0f;
            }
            else if ( *(params->data) == 18 ){
                r = 255/255.0f;
                g = 153/255.0f;
                b = 0/255.0f;
            } 
            else if ( *(params->data) == 19 ){
                r = 255/255.0f;
                g = 255/255.0f;
                b = 0/255.0f;
            }               
            else if ( *(params->data) == 20 ){
                r = 0/255.0f;
                g = 255/255.0f;
                b = 0/255.0f;
            }
            else if ( *(params->data) == 21 ){
                r = 51/255.0f;
                g = 102/255.0f;
                b = 255/255.0f;
            } 
            else if ( *(params->data) == 22 ){
                r = 102/255.0f;
                g = 102/255.0f;
                b = 204/255.0f;
            }
            else if ( *(params->data) == 23 ){
                r = 204/255.0f;
                g = 102/255.0f;
                b = 204/255.0f;
            } 
            else if ( *(params->data) == 24 ){
                r = 255/255.0f;
                g = 102/255.0f;
                b = 0/255.0f;
            }
            else if ( *(params->data) == 25 ){
                r = 255/255.0f;
                g = 204/255.0f;
                b = 0/255.0f;
            } 
            else if ( *(params->data) == 26 ){
                r = 51/255.0f;
                g = 204/255.0f;
                b = 0/255.0f;
            }
            else if ( *(params->data) == 27 ){
                r = 0/255.0f;
                g = 204/255.0f;
                b = 204/255.0f;
            } 
            else if ( *(params->data) == 28 ){
                r = 0/255.0f;
                g = 0/255.0f;
                b = 255/255.0f;
            }
            else if ( *(params->data) == 29 ){
                r = 102/255.0f;
                g = 0/255.0f;
                b = 204/255.0f;
            } 
            else if ( *(params->data) == 30 ){
                r = 153/255.0f;
                g = 51/255.0f;
                b = 153/255.0f;
            } 
            else{
                r = 0/255.0f;
                g = 0/255.0f;
                b = 0/255.0f;
            }
      }           
}


void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
{
    BLE &ble          = params->ble;
    ble_error_t error = params->error;
    
    if (error != BLE_ERROR_NONE) {
        return;
    }



    ble.init();
    ble.gap().onDisconnection(disconnectionCallback);
    ble.gattServer().onDataWritten(writeCharCallback);

    /* Setup advertising */
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE); // BLE only, no classic BT
    ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_DIRECTED); // advertising type
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME)); 
    ble.gap().setAdvertisingInterval(0); 

    /* Add our custom service */
    ble.addService(rgbService);

    /* Start advertising */
    ble.gap().startAdvertising();

}    
int main(void)
{
    
    BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
    ble.init(bleInitComplete);
    
    /* SpinWait for initialization to complete. This is necessary because the
     * BLE object is used in the main loop below. */
    while (ble.hasInitialized()  == false) { /* spin loop */ }

    /* Infinite loop waiting for BLE interrupt events */
    while (true) {
        ble.waitForEvent();
    }
}
