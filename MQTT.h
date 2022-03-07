#ifndef MQTT_H
#define MQTT_H 

#include <iostream>
#include "mosquittopp.h"
#include <vector>
#include <unistd.h>
#include <memory>


class MQTT : public mosqpp::mosquittopp
{
public:

	MQTT(const char * _host, int _port);
	MQTT(const char * _host, int _port,int _keepalive);
	MQTT();
	~MQTT();
	void stop();
        bool set_cafile(const std::string &cafile_path);
        bool set_credentials(const std::string &user, const std::string &password);
	void mqtt_send_message(std::string topic, std::string msg);
	void mqtt_subscribe(std::string _topic);


private:

	const char *host;
	std::vector<std::string> topics;
	int port, keepalive;
	bool reconnected=true;

	bool automatic=false;
	const char *auto_host = "mosquitto.ac-video.com";
	std::vector<std::string> auto_topics={"topic1", "topic2"};
	int auto_port=1883;
	int auto_keepalive=30;

        void on_connect(int rc);
	void on_disconnect(int rc);
	void on_subscribe(int mid, int qos_count, const int *granted_qos);
	void on_error();
	void on_message(const struct mosquitto_message *message);
	void resubscribe();

};


#endif
