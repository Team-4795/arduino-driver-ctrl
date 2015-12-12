package org.usfirst.frc.team4795.robot;

import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.buttons.*;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.Servo;
import edu.wpi.first.wpilibj.smartdashboard.*;

public class Robot extends IterativeRobot {
    
    //Initialize the joystick to USB port 0. Update in DriverStation if necessary  
    Joystick arduino = new Joystick(0);
    JoystickButton button9 = new JoystickButton(arduino, 9);
    JoystickButton button11 = new JoystickButton(arduino, 11);
    JoystickButton button12 = new JoystickButton(arduino, 12);
    JoystickButton button13 = new JoystickButton(arduino, 13);
    
    Servo servo = new Servo(0);
    Servo servoPot = new Servo(1);
    double servoPosition = 0;
    double potentiometer;

    public void teleopPeriodic() {
        SmartDashboard.putBoolean("Button 9", button9.get());
        SmartDashboard.putBoolean("Button 11", button11.get());
        SmartDashboard.putBoolean("Button 12", button12.get());
        SmartDashboard.putBoolean("Button 13", button13.get());
        
        //Potentiometer reads between -1 and 1, map to 0 and 1 for servo
        potentiometer = (arduino.getRawAxis(0) + 1.0) / 2.0;       
        SmartDashboard.putNumber("Potentiometer", potentiometer);
        
        if(button9.get()) {
        	servoPosition = 0;
        }
        
        if(button13.get()) {
        	servoPosition = 0.33;
        }
        
        if(button12.get()) {
        	servoPosition = 0.67;
        }
        
        if(button11.get()) {
        	servoPosition = 1;
        }
        
        servo.set(servoPosition);
        servoPot.set(potentiometer);
    }
}

