<div align="center">
  <p>
      <img width="20%" src="https://i.imgur.com/6O7Y8jn.png">
  </p>
  <b><h3> Traffic Signal System </h3></b>
  <p> A Mini-Project using <a href="https://www.arduino.cc"> Arduino </a></p>
</div>
<br>

# Smart Traffic Signal System with Vehicle Detection using Arduino UNO


This project implements a smart traffic signal system using Arduino UNO, ultrasonic distance sensors, and LED signals. The system controls traffic signals at a junction by dynamically adjusting the signal timing based on the presence of vehicles detected by the ultrasonic sensors.

## Components Used

- 2 x Arduino UNO R3
- 4 x Red LEDs
- 4 x Yellow LEDs
- 4 x Green LEDs
- 1 x 1 kΩ Resistor
- 4 x Ultrasonic Distance Sensors (HC-SR04)
- Jumper wires
- Breadboard

## Transmitter (Vehicle Detector)

### Components Used
- Arduino UNO
- Ultrasonic Distance Sensors (4x HC-SR04)
- SoftwareSerial Library

### Code Explanation (`transmitter_vehicle_detector.ino`)

1. **Initialization:**
   - Initializes ultrasonic sensor pins, serial communication, and other required variables.

2. **Ultrasonic Sensor Readings:**
   - Reads distance values from four ultrasonic sensors placed on each road.
   - Calculates distance in centimeters and adjusts for sensor offset.

3. **Vehicle Detection and Signal Transmission:**
   - If a vehicle is detected within 80 cm range on a road, the Arduino sends a corresponding signal (1 to 4) to the receiver.
   - If no vehicle is detected on any road, it sends a signal (5) indicating no vehicles.

4. **Serial Communication:**
   - Prints distance values and transmits signals to the Serial Monitor for debugging.
   - Utilizes SoftwareSerial library for communication on custom RX and TX pins.

## Receiver (Traffic Signal Output)

### Components Used
- Arduino UNO
- LEDs (12x: 4 Red, 4 Yellow, 4 Green)
- SoftwareSerial Library

### Code Explanation (`receiver_traffic_signal_output.ino`)

1. **Initialization:**
   - Initializes LED pins, serial communication, and other required variables.

2. **Signal Reception:**
   - Listens for signals received from the transmitter via SoftwareSerial.
   - Determines the state of the traffic signal based on the received signal.

3. **Traffic Signal Control:**
   - Dynamically adjusts traffic signals based on the received signal:
     - Signals 1 and 4 activate the first set of signals.
     - Signals 2 and 3 activate the second set of signals.
     - Signal 5 turns off all signals, indicating no vehicles.

4. **Signal Timing Simulation:**
   - Simulates the passage of time with a seconds counter to control the signal transition.

5. **Serial Communication:**
   - Prints received signals and corresponding actions to the Serial Monitor for debugging.

## Installation

1. **Clone the repository:**

    ```bash
    git clone https://github.com/your-username/traffic-signal-system.git
    ```

2. **Download and upload the code to an Arduino Uno if you have a physical microcontroller. Otherwise, you can use an online simulation tool such as Tinkercad.**


    ```bash
    # For physical Arduino boards
    open Arduino IDE
    ```

    ```bash
    # For Tinkercad simulation
    open Tinkercad and import the Arduino code.
    ```
    <a href="https://www.tinkercad.com/things/2oWKlB6sfYq-traffic-signal-system-20"> Live Preview (Tinkercad) </a>


## Usage

1. Upload the `transmitter_vehicle_detector.ino` code to one Arduino UNO board.
2. Upload the `receiver_traffic_signal_output.ino` code to the other Arduino UNO board.
3. Power on both Arduino boards.
4. Monitor the Serial Monitor for debugging information.



## Screenshots

![App Screenshot](https://i.imgur.com/XppJJYJ.png)

## Contributing

Feel free to contribute to the project by opening issues or submitting pull requests. Your feedback and contributions are highly appreciated.

## Support

For support, discord me - `#_wikkie_`.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

