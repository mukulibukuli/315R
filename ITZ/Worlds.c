#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           mogo,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           dl,            tmotorVex393HighSpeed_MC29, openLoop, encoderPort, dgtl1)
#pragma config(Motor,  port4,           TL_BR_Arm,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           roller,        tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           TR_BL_Arm,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armBox,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           dr,            tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, dgtl3)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX)

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*               Desc: VEX 42627G Team Digital Minds Copyright               */
/*                    						  Credit:																	 */
/*                    Head Developers: Mukul Rao, Jeffrey Tu				         */
/*                                    									                     */
/*                    				                                               */
/*                                                                           */
/*                                                                           */
/*     Filter Function/deadzone filter credit: Kaushik from 315 Paradigm,    */
/*                        as well as some other ideas.                       */
/*---------------------------------------------------------------------------*/

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

const short RIGHT_BUTTON_LCD = 4;
const short CENTER_BUTTON_LCD = 2;
const short ZONE_20 = 20;
const short ZONE_10 = 10;
const short ZONE_5 = 5;

int autonomousOption = -1;

//Wait for Press----------------------------------------------
void waitForPress()
{
	while(true){
		if(nLCDButtons == RIGHT_BUTTON_LCD || nLCDButtons == CENTER_BUTTON_LCD) {
			break;
		}
	}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

void clearAndDisplayLCD(const char* str) {
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDCenteredString(0, str);
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton(){
	int currentOption = 0;
	// Enable LCD Display.
	bLCDBacklight = true;
	//clearing existing LCD text
	clearLCDLine(0);
	clearLCDLine(1);

	// By default disable auton.
	autonomousOption = 4;

	// Go into auton selection only if button 7R is held during boot.
	// This allows us to proceed to driver mode if Robot were to
	// get disconnected during a match.
	if(vexRT[Btn7R] == 1){
		bool optionSelected = false;
		while(!optionSelected){
			switch(currentOption){
			case 0:
				displayLCDCenteredString(0, "20 Left");
				displayLCDCenteredString(1, "Enter ==>");
				waitForPress();
				if(nLCDButtons == CENTER_BUTTON_LCD){
					waitForRelease();
					optionSelected = true;
					autonomousOption = 0;
					clearAndDisplayLCD("20 Left");
					} else if(nLCDButtons == RIGHT_BUTTON_LCD){
					waitForRelease();
					currentOption++;
				}
				break;
			case 1:
				displayLCDCenteredString(0, "20 Right");
				displayLCDCenteredString(1, "Enter ==>");
				waitForPress();
				if(nLCDButtons == CENTER_BUTTON_LCD){
					waitForRelease();
					optionSelected = true;
					autonomousOption = 1;
					clearAndDisplayLCD("20 Right");
					} else if(nLCDButtons == RIGHT_BUTTON_LCD){
					waitForRelease();
					currentOption++;
				}
				break;
			case 2:
				displayLCDCenteredString(0, "10 Left");
				displayLCDCenteredString(1, "Enter ==>");
				waitForPress();
				if(nLCDButtons == CENTER_BUTTON_LCD){
					waitForRelease();
					optionSelected = true;
					autonomousOption = 2;
					clearAndDisplayLCD("10 Left");
					} else if(nLCDButtons == RIGHT_BUTTON_LCD){
					waitForRelease();
					currentOption++;
				}
				break;
			case 3:
				displayLCDCenteredString(0, "10 Right");
				displayLCDCenteredString(1, "Enter ==>");
				waitForPress();
				if(nLCDButtons == CENTER_BUTTON_LCD){
					waitForRelease();
					optionSelected = true;
					autonomousOption = 3;
					clearAndDisplayLCD("10 Right");
					} else if(nLCDButtons == RIGHT_BUTTON_LCD){
					waitForRelease();
					currentOption++;
				}
				break;
			case 4:
				displayLCDCenteredString(0, "5 Left");
				displayLCDCenteredString(1, "Enter ==>");
				waitForPress();
				if(nLCDButtons == CENTER_BUTTON_LCD){
					waitForRelease();
					optionSelected = true;
					autonomousOption = 4;
					clearAndDisplayLCD("5 Left");
					} else if(nLCDButtons == RIGHT_BUTTON_LCD){
					waitForRelease();
					currentOption++;
				}
				break;
			case 5:
				displayLCDCenteredString(0, "5 Right");
				displayLCDCenteredString(1, "Enter ==>");
				waitForPress();
				if(nLCDButtons == CENTER_BUTTON_LCD){
					waitForRelease();
					optionSelected = true;
					autonomousOption = 5;
					clearAndDisplayLCD("5 Right");
					} else if(nLCDButtons == RIGHT_BUTTON_LCD){
					waitForRelease();
					currentOption++;
				}
				break;
			case 6:
				displayLCDCenteredString(0, "Static Auton");
				displayLCDCenteredString(1, "Enter ==>");
				waitForPress();
				if(nLCDButtons == CENTER_BUTTON_LCD){
					waitForRelease();
					optionSelected = true;
					autonomousOption = 6;
					clearAndDisplayLCD("Static Auton");
					} else if(nLCDButtons == RIGHT_BUTTON_LCD){
					waitForRelease();
					currentOption++;
				}
				break;
			case 7:
				displayLCDCenteredString(0, "Disable Auton");
				displayLCDCenteredString(1, "Enter ==>");
				waitForPress();
				if(nLCDButtons == CENTER_BUTTON_LCD){
					waitForRelease();
					optionSelected = true;
					autonomousOption = 7;
					clearAndDisplayLCD("Auton Disabled");
					} else if(nLCDButtons == RIGHT_BUTTON_LCD){
					waitForRelease();
					currentOption = 0;
				}
				break;
			}
		}
		} else {
		displayLCDCenteredString(0, "Auton Disabled");
	}

	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void stopAllMotorsAuton(){
	motor[dr] = 0;
	motor[dl] = 0;
	motor[armBox] = 0;
	motor[roller] = 0;
	motor[TL_BR_Arm] = 0;
	motor[mogo] = 0;
	motor[TR_BL_Arm] = 0;
}

void boxForward(int power){
	motor[armBox] = 1 * power;
}

void boxBackward(int power){
	motor[armBox] = -1 * power;
}

void dropCone(int power){
	motor[roller] = -1 * power;
	wait1Msec(100);
	motor[roller] = -10;
}

void armUp(int power, int duration){
	motor[TL_BR_Arm] = power;
	motor[TR_BL_Arm] = -power;
	wait1Msec(duration);
	motor[TL_BR_Arm] = 0;
	motor[TL_BR_Arm] = 0;
}

void armDown(int power, int duration){
	motor[TL_BR_Arm] = -power;
	motor[TR_BL_Arm] = power;
	wait1Msec(duration);
	motor[TL_BR_Arm] = 0;
	motor[TL_BR_Arm] = 0;
}



void moveForwardAuton(int power, int ticks){
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int encoderValue = 0;
	while (encoderValue <= ticks) {
		motor[dr] = power;
		motor[dl] = power;
		encoderValue = (abs(SensorValue[leftEncoder]) + abs(SensorValue[rightEncoder])) / 2;
	}
	// Break before stopping completely
	motor[dl] = -25;
	motor[dr] = -25;
	wait1Msec(50);
	motor[dl] = 0;
	motor[dr] = 0;
}

void moveBackwardAuton(int power, int ticks){
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int encoderValue = 0;
	while (encoderValue <= ticks) {
		motor[dr] = -power;
		motor[dl] = -power;
		encoderValue = (abs(SensorValue[leftEncoder]) + abs(SensorValue[rightEncoder])) / 2;
	}
	// Break before stopping completely
	motor[dl] = 25;
	motor[dr] = 25;
	wait1Msec(50);
	motor[dl] = 0;
	motor[dr] = 0;
}

void turnRightTicks(int power, int ticks){
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int encoderValue = 0;
	while (encoderValue <= ticks) {
		motor[dr] = -power;
		motor[dl] = power;
		encoderValue = (abs(SensorValue[leftEncoder]) + abs(SensorValue[rightEncoder])) / 2;
	}
	// Break before stopping completely
	motor[dr] = 25;
	motor[dl] = -25;
	wait1Msec(50);
	motor[dr] = 0;
	motor[dl] = 0;
}

void turnLeftTicks(int power, int ticks){
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int encoderValue = 0;
	while (encoderValue <= ticks) {
		motor[dr] = power;
		motor[dl] = -power;
		encoderValue = (abs(SensorValue[leftEncoder]) + abs(SensorValue[rightEncoder])) / 2;
	}
	// Break before stopping completely
	motor[dr] = -25;
	motor[dl] = 25;
	wait1Msec(50);
	motor[dl] = 0;
	motor[dr] = 0;
}



void staticGoalAuton(bool left){
	motor[roller] = 10;
	armUp(80, 300);
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int encoderValue = 0;
	while(encoderValue <= 240){
		motor[dl] = 80;
		motor[dr] = 80;
		encoderValue = (abs(SensorValue[leftEncoder]) + abs(SensorValue[rightEncoder])) / 2;
	}
	motor[dl] = 0;
	motor[dr] = 0;

	motor[armBox] = -127;
	wait1Msec(1300);
	motor[armBox] = 0;
	motor[roller] = 0;

	armDown(80, 100);
	wait1Msec(200);

	motor[roller] = -127;
	wait1Msec(100);
	motor[roller] = 0;
	armUp(80, 200);
	motor[roller] = -127;
	motor[armBox] = 127;
	wait1Msec(400);
	stopAllMotorsAuton();
	//armDown(127, 300);
	moveBackwardAuton(80, 90);

	if(left){
		turnLeftTicks(80, 200);
	} else{
		turnRightTicks(80, 200);
	}
	moveForwardAuton(127, 360);

}

void pickupMogoAndStackCone(){
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int encoderValue = 0;
	motor[TL_BR_Arm] = 50;
	motor[TR_BL_Arm] = -50;
	wait1Msec(200);
	motor[mogo] = 127;

	while (encoderValue <= 1400) {
		encoderValue = (abs(SensorValue[leftEncoder]) + abs(SensorValue[rightEncoder])) / 2;
		if(encoderValue >= 900){
			motor[mogo] = 0;
			motor[TL_BR_Arm] = 0;
			motor[TR_BL_Arm] = 0;
		}
		motor[dr] = 127;
		motor[dl] = 127;
	}
	// Break before stopping completely
	motor[dl] = -25;
	motor[dr] = -25;
	wait1Msec(50);
	motor[dl] = 0;
	motor[dr] = 0;
	wait1Msec(250);

	// Pickup mobile goal
	// Drop the yellow cone on mobile goal
	armUp(80, 100);
	motor[mogo] = -127;
	wait1Msec(1250);
	motor[mogo] = 0;

	armDown(80, 500);
	motor[roller] = -127;
	wait1Msec(200);
	armUp(50, 50);
	stopAllMotorsAuton();
}

void comeBackWithMogoAndTwoCones() {
	// Keep the roller rolling so that cone doesn't fall off.
	motor[roller] = 127;
	wait1Msec(200);
	motor[roller] = 10;
	pickupMogoAndStackCone();

	// Pick up and stack another cone

	// Go forward a short distance and bring the arm up, box forward and start roller
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int encoderValue = 0;
	while(encoderValue <= 100){
		motor[dr] = 80;
		motor[dl] = 80;
		encoderValue = (abs(SensorValue[leftEncoder]) + abs(SensorValue[rightEncoder])) / 2;
	}
	motor[dr] = 0;
	motor[dl] = 0;
	motor[TL_BR_Arm] = 50;
	motor[TR_BL_Arm] = -50;
	wait1Msec(500);
	motor[TL_BR_Arm] = 0;
	motor[TR_BL_Arm] = 0;

	// bring arm down, start roller and bring box down to grab cone
	motor[roller] = 127;
	motor[armBox] = -127;
	wait1Msec(1000);
	motor[armBox] = -15;
	armDown(50, 800);

	//raise arm and bringing box back
	armUp(127, 300);
	motor[roller] = 10;
	motor[armBox] = 127;
	wait1Msec(500);
	motor[armBox] = 0;

	// bring the arm down and stack cone
	armDown(80, 500);
	motor[roller] = -127;
	armUp(50, 50);
	wait1Msec(250);
	motor[roller] = 0;

	//come back straight
	moveBackwardAuton(127, 1375);
	stopAllMotorsAuton();
}

void dropInTwentyZone(bool left) {
	if(left){
		//turn left so that we are facing fence
		turnLeftTicks(80, 120);
	} else{
		turnRightTicks(80, 120);
	}
	// Move back so that robot is parallel to 10 point pipe
	moveBackwardAuton(127, 625);

	if(left){
		// Turn left so that robot is facing the drop zone
		turnLeftTicks(80, 230);
	} else{
		turnRightTicks(80, 230);
	}

	// Stop at the drop zone. Bring the mogo down while moving forward so that
	// we don't waste time.
	armUp(127, 150);
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int encoderValue = 0;
	motor[mogo] = 127;
	while(encoderValue <= 600){
		motor[dr] = 127;
		motor[dl] = 127;

		encoderValue = (abs(SensorValue[leftEncoder]) + abs(SensorValue[rightEncoder])) / 2;
	}
	// Keep constant power to drive so that we can stay close to 20 point zone while dropping the mogo
	motor[dr] = 50;
	motor[dl] = 50;

	wait1Msec(550);
	motor[dr] = 0;
	motor[dl] = 0;
	motor[mogo] = 0;

	// Come back a bit and bring the mogo up
	motor[mogo] = -80;
	moveBackwardAuton(50, 120);
	motor[mogo] = -80;
	wait1Msec(1000);
	motor[mogo] = 0;

	// Bring the arm down to avoid robot from tipping
	armDown(127, 200);
	moveBackwardAuton(80, 180);
	stopAllMotorsAuton();
}

void dropInTenZone(bool left) {
	if(left){
		// Turn right so that robot is facing the drop zone
		turnRightTicks(80, 675);
	} else{
		turnLeftTicks(80, 675);
	}
	// Prepare to drop.
	// Bring the arm up
	armUp(25, 50);
	//move forward while bringing mogo up
	/*
	motor[dl] = 127;
	motor[dr] = 127;
	motor[mogo] = 127;
	*/

	//stop at the drop zone
/*
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	int encoderValue = 0;
	while(encoderValue <= 180){
		motor[dr] = 127;
		motor[dl] = 127;
		encoderValue = (abs(SensorValue[leftEncoder]) + abs(SensorValue[rightEncoder])) / 2;
	}
	motor[dr] = 0;
	motor[dl] = 0;
*/
	motor[mogo] = 127;
	// Keep constant power to drive so that we can stay close to 20 point zone while dropping the mogo
	motor[dr] = 50;
	motor[dl] = 50;
	wait1Msec(1250);

	//drop mogo
	motor[mogo] = 0;
	wait1Msec(100);
	motor[dr] = 0;
	motor[dl] = 0;
	//moveBackwardAuton(80, 360);
	motor[mogo] = -127;
	wait1Msec(250);
	motor[mogo] = 0;

	// Bring the arm down to avoid robot from tipping
	armDown(127, 200);
	moveBackwardAuton(80, 360);
	stopAllMotorsAuton();
}

void dropInFiveZone(bool left) {
	if(left){
		// Turn right so that robot is facing the drop zone
		turnRightTicks(80, 675);
	} else{
		turnLeftTicks(80, 675);
	}
	moveBackwardAuton(127, 180);
	// Prepare to drop.
	// Bring the arm up
	armUp(80, 100);
	//drop mogo
	motor[mogo] = 127;
	// Keep constant power to drive so that we can stay close to 20 point zone while dropping the mogo
	wait1Msec(1250);

	motor[mogo] = 0;

	// Bring the arm down to avoid robot from tipping
	moveBackwardAuton(60, 220);
	motor[mogo] = -127;
	wait1Msec(1250);
	stopAllMotorsAuton();
}

void Left_OR_Right_Auton(bool left, short zone){
	//Needs to be redone to support new robot
	comeBackWithMogoAndTwoCones();
	switch(zone) {
	case ZONE_20:
		dropInTwentyZone(left);
		break;
	case ZONE_10:
		dropInTenZone(left);
		break;
	case ZONE_5:
		dropInFiveZone(left);
	default:
		break;
	};
}


task autonomous(){
	//Needs to be redone to support new robot
	switch(autonomousOption) {
	case 0:
		clearAndDisplayLCD("20 Left");
		Left_OR_Right_Auton(true /* Left is True */, ZONE_20);
		break;
	case 1:
		clearAndDisplayLCD("20 Right");
		Left_OR_Right_Auton(false /* Left is not True */, ZONE_20);
		break;
	case 2:
		clearAndDisplayLCD("10 Left");
		Left_OR_Right_Auton(true /* Left is True */, ZONE_10);
		break;
	case 3:
		clearAndDisplayLCD("10 Right");
		Left_OR_Right_Auton(false /* Left is not True */, ZONE_10);
		break;
	case 4:
		clearAndDisplayLCD("5 Left");
		Left_OR_Right_Auton(true /* Left is True */, ZONE_5);
		break;
	case 5:
		clearAndDisplayLCD("5 Right");
		Left_OR_Right_Auton(false /* Left is not True */, ZONE_5);
		break;
	case 6:
		clearAndDisplayLCD("Static Auton");
		staticGoalAuton(false);
		break;
	case 7:
		clearAndDisplayLCD("Disabled");
		// Disable auton, do nothing.
		break;
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task i s used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    User Control Drivetrain functions                      */
/*                                                                           */
/*   All functions for drive train for [Digitron]    Team 315R Paradigm      */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*------------------Dead zone filter------------------------*/
int filter(int input){
	if (input > 20 || input < -20){
		return input;
		} else {
		return 0;
	}
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*------------------------Drive-----------------------------*/
void driveRobot(int forward, int turn) {
	//Needs to be double checked to confirm new robot support
	motor[dr] = -(forward - turn);
	motor[dl] = (forward + turn);
}

task drive(){
	while (true){
		//forward backward
		int forward = filter(vexRT[Ch1]);
		//turning
		int turn = filter(vexRT[Ch3]);
		driveRobot(forward, turn);
	}
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

/*------------------Mobile Goal-----------------------------*/
task mogoLift() {
	while(true){
		//Needs to be double checked to confirm new robot support
		//assigning dropping the mobile goal to the upper 8-pad button
		if(vexRT[Btn8D] == 1){
			while(vexRT[Btn8D] == 1){
				motor[mogo] = 127;
			}
			motor[mogo] = 0;
		}
		//assigning lifting the mobile goal to the bottom 8-pad button
		if(vexRT[Btn8U] == 1){
			while(vexRT[Btn8U] == 1){
				motor[mogo] = -127;
			}
			motor[mogo] = -10;
		}
		//abort the constant power
		if(vexRT[Btn7L] == 1){
			motor[mogo] = 0;
		}
	}
}

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/



/*------------------Arm and claw and boxlift-----------------------------*/

task arm() {
	while(true){
		//Needs to be double checked to confirm new robot support
		//assigning lifting the arm to the upper 6-button pad.
		if(vexRT[Btn6U] == 1) {
			motor[TL_BR_Arm] = 127;
			motor[TR_BL_Arm] = -127;
			while(vexRT[Btn6U] == 1) {
			}
			motor[TL_BR_Arm] = 15;
			motor[TR_BL_Arm] = -15;
		}
		//assigning dropping the arm to the bottom 6-buttom pad.
		if(vexRT[Btn6D] == 1){
			motor[TL_BR_Arm] = -80;
			motor[TR_BL_Arm] = 80;
			while (vexRT[Btn6D] == 1){
			}
			motor[TL_BR_Arm] = 0;
			motor[TR_BL_Arm] = 0;
		}
	}
}

//----------------------Arm Box----------------

task box() {
	while(true){
		//box down
		while(vexRT[Btn5U] == 1){
			motor[armBox] = -127;
		}
		motor[armBox] = 0;

		//box up
		while(vexRT[Btn5D] == 1){
			motor[armBox] = 127;
		}
		motor[armBox] = 0;
	}
}

task coneIntakeDrop() {
	while(true){
		// roller intake cone
		if(vexRT[Btn8L] == 1){
			while (vexRT[Btn8L] == 1) {
				motor[roller] = 127;
			}
			motor[roller] = 10;
		}
		// roller drop cone
		if (vexRT[Btn8R] == 1) {
			while(vexRT[Btn8R] == 1) {
				motor[roller] = -127;
			}
			motor[roller] = 0;
		}

		// abort the constant power
		if(vexRT[Btn7D] == 1 || vexRT[Btn7DXmtr2] == 1){
			motor[roller] = 0;
		}
	}
}



/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

//This task drives everything.Don't mess with this unless debugging. Double check all function support with new robot.
task usercontrol() {
	startTask(drive);
	startTask(mogoLift);
	startTask(arm);
	startTask(box);
	startTask(coneIntakeDrop);
}
