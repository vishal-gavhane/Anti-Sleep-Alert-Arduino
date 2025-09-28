

📌 Overview

This project is a basic anti-sleep alert system built using Arduino. It is not intended as a new innovation — better systems already exist. The goal was to practice core electronics and embedded systems skills by building a simple working prototype.

The system detects eye closure using an IR sensor mounted on safety glasses. If the eyes stay closed for more than 3 seconds, the Arduino triggers a buzzer alarm and a blinking red LED. Additionally, it supports Serial Monitor debugging and cloud-based alerts.


---

🔧 Hardware Used

Arduino UNO

IR Sensor Module (eye detection)

Safety Glasses (sensor mount)

Buzzer

Red LED + Resistor

Jumper Wires & Breadboard



---

🛠️ Skills Applied

Arduino programming (logic, timers, digital I/O)

Sensor integration & calibration

Electronics prototyping (buzzer + LED alerts)

Serial Monitor debugging

Cloud alert integration

System design thinking (sensing → decision → action flow)



---

⚡ How It Works

1. IR sensor detects whether the eye is open or closed.


2. If the eye remains closed continuously for 3 seconds, the Arduino triggers:

🔊 Buzzer

🔴 Blinking LED



3. Alerts are also logged on the Serial Monitor.


4. A cloud alert can be sent (optional).




---

📜 Circuit Diagram

(Insert image of your circuit here once uploaded)


---

💻 Code

The Arduino code is available in AntiSleepAlert.ino.


---

🚀 Future Improvements

Use camera-based drowsiness detection (computer vision).

Integrate with IoT dashboard for real-time monitoring.

Add vibration motor for physical feedback.

Improve ergonomics of sensor mounting.



---

🤝 Connect

This project is a small step toward strengthening my foundation in electronics and embedded systems.
If you’re into prototyping or want to collaborate, feel free to connect with me

