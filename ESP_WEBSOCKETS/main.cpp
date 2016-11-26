#include "mbed.h"
#include "ESP8266Interface.h"
#include "TCPSocketConnection.h"
#include "TCPSocketServer.h"
#include "Websocket.h"



ESP8266Interface wifi(D1,D0,D10,"demossid","password",115200); // TX,RX,Reset,SSID,Password,Baud
 
int main() {
    wifi.init(); //Reset
    wifi.connect(); //Use DHCP
    printf("IP Address is %s\n", wifi.getIPAddress());
    
    Websocket ws("ws://192.168.1.20:8888/ws");
    
    //Check for successful socket connection
    if(!ws.connect())
        ws.close();
    else{
        char str[100];
        
        for(int i=0; i<0x7fffffff; ++i) {
            // string with a message
            sprintf(str, "%d WebSocket Hello World over wifi", i);
            printf("send: %s\n",str);
            ws.send(str);
        
            // clear the buffer and wait a sec...
            memset(str, 0, 100);
            wait(0.5f);
        
            // websocket server should echo whatever we sent it
            if (ws.read(str)) {
                printf("rcv'd: %s\n", str);
            }
        }
    }
    ws.close();
    
    while(true) {}
}
 