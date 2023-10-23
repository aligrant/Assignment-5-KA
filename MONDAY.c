/*
 Insert Robot number and group member names here
*/

void configureAllSensors(); //configures all sensors to standard configuration
void drive(int motor_power); //powers both drive motors with the same power
void driveBoth (int motor_power_A, int motor_power_D); //powers both motors independently
void waitButton(TEV3Buttons button_name);  // wait for push and release of specified button

/*
Replace this comment text with a description of the improvements made
on the rotateRobot function and reasoning behind them.
*/
void rotateRobot(int angle) //rotates robot in place to given angle then stops. Positive angles are clockwise when viewed from above
{
	resetGyro(S4);

	if (angle>0)
	{
		driveBoth(-10,10);
	}
	else
	{
		driveBoth(10,-10);
	}

	while (abs(getGyroDegrees(S4))<abs(angle))
	{}

	drive(0);
}


/*
Replace this comment text with a description of the improvements made
on the driveDistance function and reasoning behind them.
- slow down the motor power to reduce effect of momentum
- right now code uses abs of each angle so it always turns clockwise
*/

//Drives robot straight for given distance based on motor encoders and
//nominal wheel diameter. Positive distance is forwardvoid driveDistance(int distance).
void driveDistance (int distance)
{

	nMotorEncoder[motorA]=0;
	const float CM_TO_DEG = 180/(2.75*PI);
	if (distance>0)
	{
		drive(50);
	}
	else
	{
		drive(-50);
	}

	while (abs(nMotorEncoder[motorA])<abs(distance*CM_TO_DEG)&&!getButtonPress(buttonEnter)&&SensorValue[S1]== 0)
	{}
int enc_limit= nMotorEncoder(motorA);
if(SensorValue[S1]!=0){
	ANGLE_CORNER*=-1;
			rotateRobot(180);
			wait1Msec(500);
			while(nMotorEncoder(motorA) > enc_limit)
			{
			motor[motorA] = motor[motorD] = 10;
		}
}

	drive(0);

	wait1Msec(2000);
}



task main()
{
	/*const int NUM_SIDES = 4;*/
	const int SIDE_LENGTH = 50;
	int ANGLE_CORNER = 90;
	//changed to int so can be modified
	configureAllSensors();
	waitButton(buttonEnter);
int enc_limit=0;
int a=2;
while(a==2){
	while(SensorValue[S1]== 0){
		driveDistance(SIDE_LENGTH);
		wait1Msec(500);
		rotateRobot(ANGLE_CORNER);
	}
	}
	wait1Msec(1000);
	/*
	while(){
		rotateRobot(-ANGLE_CORNER);
		wait1Msec(500);
		driveDistance(-SIDE_LENGTH);
	}
	*/
}
/* ------------------------------------------------------------ */
/* --- Do Not Modify the code below.                        --- */
/* ------------------------------------------------------------ */
void configureAllSensors()
{
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Ultrasonic;
	SensorType[S3] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Color_Color;
	wait1Msec(50);

	SensorType[S4] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[S4] = modeEV3Gyro_Calibration;
	wait1Msec(100);
	SensorMode[S4] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
}
/* DNM: Do Not Modify the code below. */
//powers both drive motors with the same power
void drive(int motor_power)
{
	motor[motorA] = motor[motorD] = motor_power;
}
/* DNM: Do Not Modify the code below. */
//powers both motors independently
void driveBoth(int motor_power_A, int motor_power_D)
{
	motor[motorA] = motor_power_A;
	motor[motorD] = motor_power_D;
}
/* DNM: Do Not Modify the code below. */
void waitButton(TEV3Buttons button_name)
{
	while(!getButtonPress(button_name))
	{}
	while(getButtonPress(button_name))
	{}
}
/* ------------------------------------------------------------ */
