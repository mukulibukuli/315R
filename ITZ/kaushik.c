#pragma config(Sensor, in4,    potFlipFlop,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           mogoL,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           flipflop,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           armL,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           armR,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           chump,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightBack,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          mogoR,         tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)


#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)


#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//#define FLIPFLOPDOWN 1120
//#define FLIPFLOPUP 3650

int filter(int input){
	if (input > 20 || input < -20){
		return input;
	}
	else {
		return 0;
	}
}

task drive(){
	while (true){
		int forward = filter(vexRT[Ch3] + vexRT[Ch3Xmtr2]);
		int turn = filter(vexRT[Ch1] + vexRT[Ch1Xmtr2]);

		motor[df] = forward + turn;
		motor[db] = forward + turn;
		motor[pf] = forward - turn;
		motor[pb] = forward - turn;
	}
}

/*
void assignArmMotors(int power){
	motor[armL] = power;
	motor[armR] = power;
}

task arm(){
	while(true){
		if(vexRT[Btn6U] == 1 || vexRT[Btn5UXmtr2] == 1){
			assignArmMotors(127);
			while(vexRT[Btn6U] == 1 || vexRT[Btn5UXmtr2] == 1)
			{

			}
			assignArmMotors(10);
		}
		if(vexRT[Btn6D] == 1 || vexRT[Btn5DXmtr2] == 1){
			assignArmMotors(0);
			assignArmMotors(-90);
			while(vexRT[Btn6D] == 1 || vexRT[Btn5DXmtr2] == 1)
			{

			}
			assignArmMotors(10);
		}
	}
}


void assignMogoMotors(int power){
	motor[mogoL] = power;
	motor[mogoR] = -power;
}

task mogo(){
	while(true){
		if(vexRT[Btn8U]){
			assignMogoMotors(127);
			while(vexRT[Btn8U] == 1)
			{

			}
			assignMogoMotors(0);
		}
		if(vexRT[Btn8D]){
			assignMogoMotors(-127);
			while(vexRT[Btn8D] == 1)
			{

			}
			assignMogoMotors(0);
		}
		if (vexRT[Btn8R]){
			assignMogoMotors(-127);
			wait1Msec(600);
			assignMogoMotors(-70);
			wait1Msec(800);
			assignMogoMotors(-10);
			wait1Msec(400);
			assignMogoMotors(10);
			wait1Msec(300);
			assignMogoMotors(40);
			wait1Msec(300);
			assignMogoMotors(0);
		}
	}
}

task flipfloptask {
	while (true) {
		if (vexRT[Btn5U] == 1){
			motor[flipflop] = 127;
			while (vexRT[Btn5U] == 1){

			}
			motor[flipflop] = 0;
		}
		if (vexRT[Btn5D] == 1){
			motor[flipflop] = -127;
			while (vexRT[Btn5D] == 1){
				if (SensorValue[potFlipFlop] < FLIPFLOPDOWN && abs(SensorValue[potFlipFlop] - 256) > 10){
					motor[flipflop] = 10;
					break;
				}
			}
			motor[flipflop] = 10;
		}
		if (vexRT[Btn7R] == 1){
			motor[flipflop] = -127;
			while (SensorValue[potFlipFlop] > FLIPFLOPDOWN){

			}
			motor[flipflop] = 30;
			wait1Msec(100);
			motor[flipflop] = 0;
		}
		if (vexRT[Btn7L] == 1){
			motor[flipflop] = 127;
			while (SensorValue[potFlipFlop] < FLIPFLOPUP){

			}
			motor[flipflop] = 0;
		}
	}
}

task chumptask {
	while (true) {
		if (vexRT[Btn7UXmtr2] || vexRT[Btn7U] == 1){
			while (vexRT[Btn7UXmtr2] == 1 || vexRT[Btn7U] == 1){
				motor[chump] = 50;
			}
			motor[chump] = 29;
		}
		if (vexRT[Btn7DXmtr2] == 1|| vexRT[Btn7D] == 1){
			while (vexRT[Btn7DXmtr2] == 1|| vexRT[Btn7D] == 1){
				motor[chump] = -30;
			}
			motor[chump] = 0;
		}
	}
}

void pre_auton(){

}

task autonomous(){

}
*/

task usercontrol(){
	startTask(drive);
	//startTask(arm);
	//startTask(chumptask);
	//startTask(flipfloptask);
	//startTask(mogo);
}
