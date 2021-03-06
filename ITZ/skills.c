#pragma config(Motor,  port2,           driveLeft,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           driveRight,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           mogo,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightArm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armClaw,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armBox,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void boxForward(int power){
	motor[armBox] = 1 * power;
}

void openClaw(int power){
	motor[armClaw] = -1 * power;
	//wait1Msec(750);
	wait1Msec(400);
	motor[armClaw] = 0;
}

void armUp(int power){
	motor[leftArm] = power;
	motor[rightArm] = -1 * power;
}

void armDown(int power){
	motor[leftArm] = -1 * power;
	motor[rightArm] = power;
}

void moveForwardAuton(int power){
	motor[driveLeft] = power;
	motor[driveRight] = -1 * power;
}

void moveBackwardAuton(int power){
	motor[driveLeft] = -1 * power;
	motor[driveRight] = power;
}

void turnRightAuton(int power){
	motor[driveRight] = power;
	motor[driveLeft] = power;
}

void turnLeftAuton(int power){
	motor[driveRight] = -1 * power;
	motor[driveLeft] = -1 * power;
}

void stopAllMotorsAuton(){
	motor[driveRight] = 0;
	motor[driveLeft] = 0;
	motor[armBox] = 0;
	motor[armClaw] = 0;
	motor[leftArm] = 0;
	motor[mogo] = 0;
	motor[rightArm] = 0;
}

void mogoDownAuton(){
	motor[mogo] = -127;
	wait1Msec(1200);
	motor[mogo] = 0;
}

void mogoUpAuton(){
	motor[mogo] = 127;
	wait1Msec(1200);
	motor[mogo] = 0;
}

void Skills() {
	// Lift arm
	// Bring the mogo down
	// Move forward to the mobile goal
	armUp(50);
	wait1Msec(250);
	mogoDownAuton();
	// mogoDown waits, no need to add additional wait here
	moveForwardAuton(127);
	wait1Msec(1600);
	stopAllMotorsAuton();

	// Pickup mobile goal
	// Drop the yellow cone on mobile goal
	mogoUpAuton();
	// mogoUp waits, no need to add additional wait here
	armDown(80);
	wait1Msec(1000);
	stopAllMotorsAuton();
	openClaw(40);
	armUp(80);
	wait1Msec(250);
	stopAllMotorsAuton();

	//continue normal routine
	moveBackwardAuton(127);
	wait1Msec(1600);
	stopAllMotorsAuton();
	wait1Msec(100);

	turnRightAuton(80);
	wait1Msec(825);
	stopAllMotorsAuton();

	moveForwardAuton(127);
	wait1Msec(400);
	stopAllMotorsAuton();

	turnRightAuton(80);
	wait1Msec(700);
	stopAllMotorsAuton();

	// Lift the arm up
	// Move forward so that robot's front is well within 10 point zone
	// Drop the mobile goal in 20 point zone
	// Drive back a bit
	armUp(80);
	wait1Msec(400);
	stopAllMotorsAuton();
	moveForwardAuton(127);
	wait1Msec(2000);
	stopAllMotorsAuton();
	mogoDownAuton();
	moveBackwardAuton(127);
	wait1Msec(150);
	stopAllMotorsAuton();
	mogoUpAuton();
	armDown(80);
	wait1Msec(600);
	stopAllMotorsAuton();
	moveBackwardAuton(127);
	wait1Msec(800);
	stopAllMotorsAuton();
	wait1Msec(500);

	// Autonomous for picking up Right Red Goal.
	moveForwardAuton(127);
	wait1Msec(200);
	stopAllMotorsAuton();
	// Turn right
	turnRightAuton(80);
	wait1Msec(750);
	stopAllMotorsAuton();
	//go back and use fence to align for the right side mobile goal
	moveBackwardAuton(50);
	wait1Msec(1850);
	stopAllMotorsAuton();

	moveForwardAuton(50);
	wait1Msec(400);
	stopAllMotorsAuton();

	turnRightAuton(50);
	wait1Msec(400);
	stopAllMotorsAuton();

	// Bring the arm up and mogo down while moving forward to pick up the red goal.
	armUp(80);
	wait1Msec(400);
	stopAllMotorsAuton();
	mogoDownAuton();
	moveForwardAuton(80);
	wait1Msec(750);
	stopAllMotorsAuton();
	mogoUpAuton();

	moveBackwardAuton(80);
	wait1Msec(650);
	stopAllMotorsAuton();

	turnLeftAuton(80);
	wait1Msec(850);
	stopAllMotorsAuton();

	moveForwardAuton(80);
	wait1Msec(500);
	stopAllMotorsAuton();
	mogoDownAuton();

	moveBackwardAuton(127);
	wait1Msec(500);
	stopAllMotorsAuton();







	// Go forward and turn Right again so that we can be facing Red Mobile Goal.
	/*moveForwardAuton(127);
	wait1Msec(500);
	stopAllMotorsAuton();
	turnRightAuton(80);
	wait1Msec(625);
	stopAllMotorsAuton();
	// Bring the arm up and mogo down while moving forward to pick up the red goal.
	armUp(80);
	wait1Msec(400);
	stopAllMotorsAuton();
	mogoDownAuton();
	moveForwardAuton(127);
	wait1Msec(1000);
	stopAllMotorsAuton();
	mogoUpAuton();

	// Time to get the red goal to the 10 point zone.
	turnLeftAuton(80);
	wait1Msec(1350);
	stopAllMotorsAuton();
	moveForwardAuton(127);
	wait1Msec(950);
	stopAllMotorsAuton();
	mogoDownAuton();
	moveBackwardAuton(127);
	wait1Msec(500);
	stopAllMotorsAuton();
	*/
}

task main(){
	Skills();
}
