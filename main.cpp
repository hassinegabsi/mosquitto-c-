#include <iostream>
#include "MQTT.h"
#include <sys/wait.h>
#include <unistd.h>



int main(int argc, char **argv)
{

	const char* host = "mosquitto.ac-video.com" ;
	int port = 1883;

	//MQTT mqtt_client;		//first constructor




	MQTT mqtt_client(host, port);		//second constructor

	//MQTT mqtt_client(host, port, 60);		//first constructor

    if (!mqtt_client.set_credentials("client10", "test"))
        std::cout << "Error setting credentials" << std::endl;
    else
        std::cout << "Success setting credentials" << std::endl;

char pcBuffer[100];

mqtt_client.mqtt_subscribe("topic");
while(1){
snprintf(pcBuffer,sizeof(pcBuffer)-1,"acd time = %d  pid = %d", time(NULL),getpid());
mqtt_client.mqtt_send_message("topic","acoba");
sleep(30);
//mqtt_client.mqtt_subscribe(pcCMDSystem);
}


        

	
    return 0;
}
