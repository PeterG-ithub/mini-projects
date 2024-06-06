# Inverse Kinematics Project

This project demonstrates a simple implementation of inverse kinematics using SFML (Simple and Fast Multimedia Library) in C++. Inverse kinematics is a method used to calculate the joint angles of a robotic arm or leg in order to achieve a desired end effector position.

## Description

The project consists of several classes:

- `Body`: Represents the main body of the robot.
- `Leg`: Represents a single leg of the robot.
- `Environment`: Represents the environment in which the robot operates.
- `Calc`: Contains helper functions for calculations.

The `main()` function initializes an SFML window and sets up the robot's body, legs, and the environment. It then continuously updates the position of the legs based on the target position, demonstrating the inverse kinematics principle.