#include "mbed.h"
#include "ble/BLE.h"

PwmOut r(p1);   //p1  rigado p16 beacon
PwmOut g(p25);   //p25 rigado p12 beacon
PwmOut b(p24);   //p24 rigado p15 beacon
uint16_t rgbUUID  = 0xA000;
uint16_t UUID     = 0xA001;

const static char DEVICE_NAME[] = "ISOLIGHT"; 

static uint8_t Value[10] = {0};
WriteOnlyArrayGattCharacteristic<uint8_t, sizeof(Value)> Char(UUID, Value);

BLEDevice ble;
GattCharacteristic *characteristics[] = {&Char};
GattService rgbService(rgbUUID, characteristics, sizeof(characteristics) / sizeof(GattCharacteristic *));

void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)//init connection with phone
{
    BLE &ble          = params->ble;
    ble_error_t error = params->error;
    
    if (error != BLE_ERROR_NONE) {
        return;
    }

    ble.init();
    ble.gap().onDisconnection(disconnectionCallback);
    ble.gattServer().onDataWritten(writeCharCallback); //connection recived for DATAAAA lol!

    /* Setup advertising */
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE); // BLE only, no classic BT
    // -------------------------------------- here's a fucken problem...
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

void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *)
{
    ble.gap().startAdvertising();
    r.write(0.0);   //(0.0) pour rigado (1.0) pour beacon
    g.write(0.0);   //(0.0) pour rigado (1.0) pour beacon
    b.write(0.0);   //(0.0) pour rigado (1.0) pour beacon
}

void changeLedRgbIndexValues(float red, float green, float blue){
	r = red/255.0f;
	g = green/255.0f;
	b = blue/255.0f;
}

void writeCharCallback(const GattWriteCallbackParams *params){
    if(params->handle == Char.getValueHandle()) {
            switch(*(params->data)){
		case 00:
                	changeLedRgbIndexValues(0,0,0);
            	break;
            	case 01:
			changeLedRgbIndexValues(255,255,255);
            	break;    
            	case 02: 
			changeLedRgbIndexValues(255,204,204);
            	break;
            	case 03: 
			changeLedRgbIndexValues(255,204,153);
            	break;
            	case 04: 
			changeLedRgbIndexValues(255,255,153);
            	break;   
            	case 05: 
			changeLedRgbIndexValues(153,255,153);
            	break;
            	case 06:
			changeLedRgbIndexValues(153,255,255);
            	break;
            	case 07: 
			changeLedRgbIndexValues(204,204,255);
            	break;   
            	case 38: //8 ne fonctionne pas, pourquoi?
			changeLedRgbIndexValues(255,153,255);
            	break
            	case 39:  //9 ne fonctionne pas, pourquoi?
			changeLedRgbIndexValues(255,102,102);
            	break;
            	case 10: 
			changeLedRgbIndexValues(255,153,102);
            	break;   
            	case 11:
			changeLedRgbIndexValues(255,255,102);
            	break;
            	case 12: 
			changeLedRgbIndexValues(255,255,51);
            	break;
           	case 13: 
			changeLedRgbIndexValues(51,255,51);
            	break;   
            	case 14:
			changeLedRgbIndexValues(0,255,255);
            	break;
            	case 15:
			changeLedRgbIndexValues(153,153,255);
            	break;
            	case 16:
			changeLedRgbIndexValues(255,0,255);
            	break;	
            	case 17:
			changeLedRgbIndexValues(255,0,0);
           	break;
            	case 18:
			changeLedRgbIndexValues(255,153,0);
            	break;
            	case 19:
			changeLedRgbIndexValues(255,255,0);
            	break;    
            	case 20:
			changeLedRgbIndexValues(0,255,0);
           	break;
            	case 21: 
			changeLedRgbIndexValues(51,102,255);
            	break;
            	case 22: 
			changeLedRgbIndexValues(102,102,204);
            	break;
            	case 23: 
			changeLedRgbIndexValues(204,102,204);
            	break;
            	case 24:
			changeLedRgbIndexValues(255,102,0);
            	break;
            	case 25: 
			changeLedRgbIndexValues(255,204,0);
            	break;
            	case 26: 
			changeLedRgbIndexValues(51,204,0);
            	break;
            	case 27:
			changeLedRgbIndexValues(0,204,204);
            	break;
            	case 28:
			changeLedRgbIndexValues(0,0,255);
            	break;
            	case 29: 
			changeLedRgbIndexValues(102,0,204);
            	break;
            	case 30: 
			changeLedRgbIndexValues(153,51,153);
            	break;
            	default:
			//create a log over here sigh!
		break;
            }
      }           
}



