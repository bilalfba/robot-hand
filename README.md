# IoT Motion Controlled Servo Arm with Flex Sensors & Accelerometer (MPU6050)

## Click here to view the [Presentation Slides](https://docs.google.com/presentation/d/1cGwpPb_68qubtf4eO3SImKOUNmSCgJCFti__APxQyGQ/edit?usp=sharing) which has the required circuit diagram and component pin diagrams

1. The glove is connected with an MPU6050 Accelerometer & 2 Flex Sensors [Glove Code](glove.ino)

2. Motion data is received from the glove and sent over to the internet - This is the server [Internet for Glove](server.py)

3. The data is received by the client. It is then passed over to the Robot [Internet for Robotic Arm](client.py)

4. The motors are attached to the robot and it accepts the values it receives over Wifi [Robotic Arm Code](robotArm.ino)

