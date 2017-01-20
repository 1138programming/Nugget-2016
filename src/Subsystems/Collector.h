#ifndef Collector_H
#define Collector_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Collector: public Subsystem
{
private:
	/*This subsystem comprises the a motor for each collector arm, and
	 * A single moter to run the roller.  There are also 2 limit switches that
	 * signal the upper and lower limit of collector arm travel.
	 */
	CANTalon* rightCollectorMotor;
	CANTalon* leftCollectorMotor;

	DigitalInput* collectorLowerLimit;
	DigitalInput* collectorUpperLimit;

public:
	//TODO add PID to collector motors
	//TODO figure out encoder values for the drive position and the collect position
	Collector();
	void InitDefaultCommand();
	void CollectorRunToLimitSwitch(float direction);
	void CollectorCollectPosition();
	void CollectorDrivePosition();
	void CollectorHighPosition();
	void CollectorRaiseBot();
	bool CollectorIsAtUpperLimit();
	bool CollectorIsAtLowerLimit();
	int CollectorLeftEncoderPosition();
	int CollectorRightEncoderPosition();
	void StopCollector();

	const int KCollectorMaster = 11;	//Talon number for the left collector motor
	const float KCollectorSpeed = 0.33; //We don't run the collector very fast
	const int KCollectorDrivePosition = 1000;
	const int KCollectorCollectPosition = 500;	//

};

#endif
