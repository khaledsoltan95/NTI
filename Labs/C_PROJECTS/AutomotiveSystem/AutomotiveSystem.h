#ifndef 	AUTOMOTIVESYSTEM_H
#define 	AUTOMOTIVESYSTEM_H

#define     InitialCondition                0u
#define     TurnedOn                        1u
#define     TurnedOff                       2u
#define     AC_ON                           3u
#define     AC_OFF                          4u
#define     EngineTemperatureController_ON  5u
#define     EngineTemperatureController_OFF 6U

void GeneralAction          (void) ;
void EngineTemperatureFunc  (void) ;
void RoomTemperatureFunc    (void) ;
void TrafficLight           (void) ;
void TurnOnSystem           (void) ;
void Design                 (void) ;
void TurnOffSystem          (void) ;
void Display                (void) ;

#endif
