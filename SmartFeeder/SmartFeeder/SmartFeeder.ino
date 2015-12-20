#include <Servo.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "dlink";
const char* password = "";

//static const uint8_t D0   = 16;
//static const uint8_t D1   = 5;
//static const uint8_t D2   = 4;
//static const uint8_t D3   = 0;
//static const uint8_t D4   = 2;
//static const uint8_t D5   = 14;
//static const uint8_t D6   = 12;
//static const uint8_t D7   = 13;
//static const uint8_t D8   = 15;
//static const uint8_t D9   = 3;
//static const uint8_t D10  = 1;

short int motor_op = 16;
short int distance_senstor_ip = 5;
short int speaker_op = 4;
// twelve servo objects can be created on most boards

ESP8266WebServer server(80);
Servo myservo;  // create servo object to control a servo
int pos = 0;
const int led = 13;

void run_motor()
{
	//for (pos = 0; pos <= 180; pos += 1) 
	//{ // goes from 0 degrees to 180 degrees
	// in steps of 1 degree
	//for (pos = 0; pos <= 90; pos += 1) 
	{ // goes from 0 degrees to 180 degrees
	  // in steps of 1 degree
		myservo.write(0);              // tell servo to go to position in variable 'pos'
		delay(780);                       // waits 15ms for the servo to reach the position
	}
	myservo.write(93.5);
	delay(2000);
}

void hello_kitty()
{
	sing(1);
	sing(1);
	sing(2);
	// sing a sing a song
}

bool is_bowl_full()
{
	int kupichka = 0;
	kupichka = analogRead(distance_senstor_ip);
	Serial.print(kupichka);
	Serial.print("  ");
	if (kupichka > 500)
	{
		return false;
	}
	return true;
}

bool try_to_add_food(bool option)
{
	if (option == true || !is_bowl_full())
	{
		run_motor();
		return true;
	}
	return false;
}

void feed()
{
	digitalWrite(led, 1);

	if (try_to_add_food(false))
		server.send(200, "text/plain", "cat is no longer hungry!");
	else
	{
		delay(1000);
		hello_kitty();
		server.send(400, "text/plain", "cat is not eating very much");
	}

	digitalWrite(led, 0);
}

void handleNotFound()
{
	digitalWrite(led, 1);
	server.send(404, "text/plain");
	digitalWrite(led, 0);
}

void setup()
{
	pinMode(led, OUTPUT);
	digitalWrite(led, 0);
	Serial.begin(115200);
	WiFi.begin(ssid, password);
	Serial.println("");

	// Wait for connection
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.print("Connected to ");
	Serial.println(ssid);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());


	if (MDNS.begin("esp8266")) {
		Serial.println("MDNS responder started");
	}

	server.on("/feed", feed);
	server.onNotFound(handleNotFound);

	server.begin();
	Serial.println("HTTP server started");

	// Motor stuff below
	Serial.begin(9600);
	myservo.attach(motor_op);
	// attaches the servo on pin 9 to the servo object
	pinMode(distance_senstor_ip, INPUT);
	pinMode(speaker_op, OUTPUT);
	digitalWrite(led, 1);
}

void loop()
{
	server.handleClient();

	// distnace motor tests
	Serial.print((int)is_bowl_full());
	Serial.print("\n");

	// motort tests 1 oborot

	//run_motor();

	delay(1);
}

