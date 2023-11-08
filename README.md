# Traffic Light Control System using ATmega32

## Overview
This project demonstrates a simple traffic light control system using an ATmega32 microcontroller. The system controls a traffic light with red, yellow, and green signals and utilizes a seven-segment display to show countdowns for each signal phase.

## Components
- ATmega32 Microcontroller
- Seven-Segment Display
- LEDs

## Project Structure

### MCAL Layer
- **DIO Driver**: Driver for configuring digital input/output pins.

### HAL 
- **Seven Segment Driver**: Implementation functions to initialize the seven-segment display, display numbers, and control it.

### LIB
- **Bit_Math**: Implementation functions to control and manipulate bits
- **types**:    defining types to be used

### APP 
- **main.c**: The main application file that controls the traffic light system. It uses functions from the MCAL and HAL layers to manage the traffic light and countdown display.

## Traffic Light Control Logic
- The system operates in a cycle of 15 seconds for the green light, 3 seconds for the yellow light, and 15 seconds for the red light.
- The countdown for each phase is displayed on the seven-segment display.

## Usage
1. Set up the hardware components as per wiring diagram.
2. Compile and flash the code onto the ATmega32 microcontroller.
3. Run the system, and the traffic light will start operating based on the predefined timing.

## Simulation 
proteus file that contains the simulation for the traffic light
