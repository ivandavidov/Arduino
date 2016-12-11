/*
Arduino example which demonstrates how to communicate
with Arduino board via serial connection direclty from
Linux terminal. The assumtion is that the Arduino serial
console is attached to this terminal:

/dev/ttyACM0

You also need two separate terminals. The first one is
where we listen for events and we specify what to do when
new line arrives. We use the second terminal to send our
communication as string literals. Example:

# terminal 1

tail -fn 0 /dev/ttyACM0 | while read c; do echo "$c"; done

# terminal 2

odroid@odroid64:~$ echo "sample text here" > /dev/ttyACM0
odroid@odroid64:~$ echo "" > /dev/ttyACM0

Currently we need to send additional empty string literal
in order to force Arduino to send us its last buffered
output message. I have no proper solution for this but
there are several workaround including the one which I
suggest with this example.
*/

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
}

void loop()
{
  if (Serial.available() > 0) {
    // Just write what we read.
    Serial.write(Serial.read());
  }
}
