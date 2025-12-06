#include <Wire.h>
#include <PAJ7620.h>

/* Motor pins */
#define ENA 5
#define IN1 6
#define IN2 7
#define ENB 9
#define IN3 10
#define IN4 11

void setup() {
    Serial.begin(9600);
    Wire.begin();

    if (paj7620Init()) {
        Serial.println("PAJ7620 initialization failed");
        while (1);
    }
    Serial.println("Gesture Sensor Ready");

    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    stopRover();
}

/* MOTOR CONTROL FUNCTIONS */

void forward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 200);
    analogWrite(ENB, 200);
}

void backward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 200);
    analogWrite(ENB, 200);
}

void left() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void right() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void stopRover() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void loop() {
    uint8_t gesture;

    if (paj7620ReadReg(0x43, 1, &gesture)) {
        return;
    }

    switch (gesture) {

        case GES_RIGHT_FLAG:
            Serial.println("Gesture: RIGHT");
            right();
            delay(300);
            stopRover();
            break;

        case GES_LEFT_FLAG:
            Serial.println("Gesture: LEFT");
            left();
            delay(300);
            stopRover();
            break;

        case GES_UP_FLAG:
            Serial.println("Gesture: FORWARD");
            forward();
            delay(400);
            stopRover();
            break;

        case GES_DOWN_FLAG:
            Serial.println("Gesture: BACKWARD");
            backward();
            delay(400);
            stopRover();
            break;

        case GES_FORWARD_FLAG:
            Serial.println("Gesture: STOP");
            stopRover();
            break;

        default:
            break;
    }
}
