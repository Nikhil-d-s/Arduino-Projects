// Constants
const int trigPin = 9;   // Trigger pin of ultrasonic sensor
const int echoPin = 10;  // Echo pin of ultrasonic sensor
const int buzzerPin = 8; // Pin for buzzer


// Variables
long duration;
float distance;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Clear the trigPin by setting it LOW for 2 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the ultrasonic burst by setting the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the echo (time it takes for the signal to return)
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (duration divided by 2 because it goes to the object and back, and then multiply by the speed of sound)
  distance = (duration * 0.0343) / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  int d= distance;
  if(distance<20){
  // Loop forever with intense, fast beeping
    for (d; d > 0; d -= 5) {  // When the delay reaches 50ms, reduce further by smaller increments
     digitalWrite(buzzerPin, HIGH);   // Turn buzzer on
     delay(d+20);                        // Short delay to intensify the beep
     digitalWrite(buzzerPin, LOW);    // Turn buzzer off
     delay(d+20);                        // Short delay between beeps
    }
  }
  
  // Short delay before the next loop iteration
  delay(100);
}
