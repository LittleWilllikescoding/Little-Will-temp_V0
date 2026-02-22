using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern controller Controller1;
extern motor Motor8;
extern motor Motor9;
extern inertial Inertial10;
extern digital_out DigitalOutA;
extern distance Distance15;
extern motor_group MotorGroup18;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
