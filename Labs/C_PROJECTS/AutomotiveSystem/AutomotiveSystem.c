#include <stdio.h>
#include "BIT_MATH.h"
#include "AutomotiveSystem.h"

static char Counter = 0 ;
static char Mode = InitialCondition ;
static char Option = InitialCondition ;
static char AC_Mode = AC_OFF ;
static char EngineTemperatureController_Mode = EngineTemperatureController_OFF ;
static signed char EngineTemperature = 0 , RoomTemperature = 0 , VehicleSpeed = 0 ;

void Display                (void)
{
    if ( Mode == TurnedOn )
    {
        printf ("Engine State is ON\n") ;
    }
    else
    {
        printf ("Engine State is OFF\n") ;
    }

    if ( AC_Mode == AC_ON )
    {
        printf("AC State is ON\n");
    }
    else
    {
        printf("AC State is OFF\n");
    }
    printf("Room Temperature is %d\n" , RoomTemperature) ;
    if ( EngineTemperatureController_Mode != EngineTemperatureController_OFF )
    {
        printf("Engine Temperature Controller State is ON\n");
    }
    else
    {
        printf("Engine Temperature Controller State is OFF\n");
    }
     printf( "Engine Temperature is %d\n" , EngineTemperature ) ;
}
void GeneralAction          (void)
{
    SET_BIT(Option,0);
    char RoomTemperatureSet = 0 , EngineTemperatureSet = 0  ;
    if ( VehicleSpeed == 30 )
    {
        if ( AC_Mode == AC_OFF )
        {
            AC_Mode = AC_ON ;
            RoomTemperatureSet = ( ( RoomTemperature * (5/4)) + 1 ) ;
        }
        if (  EngineTemperatureController_Mode == EngineTemperatureController_OFF  )
        {
            EngineTemperatureController_Mode = EngineTemperatureController_ON ;
            EngineTemperatureSet = ( ( EngineTemperature * (5/4)) + 1 ) ;
        }
    }
    else
    {
        // Do Nothing
    }
}
void EngineTemperatureFunc(void)
{
    SET_BIT(Option,1);
    signed char EngineTemperatureSelect = 0   ;
    system ("cls") ;
    printf("Please Enter Temperature :\n***********************************************************************\n");
    scanf("%d",&EngineTemperatureSelect) ;
    system("cls");
    if ( (EngineTemperatureSelect < 100 ) || ( EngineTemperatureSelect > 150 ) )
    {
        EngineTemperatureController_Mode = EngineTemperatureController_ON ;
        EngineTemperature = EngineTemperatureSelect ;
        //printf("Engine Temperature controller is Turned ON and Set to 125 C\n");
    }
    else
    {
        EngineTemperature = EngineTemperatureSelect ;
        EngineTemperatureController_Mode = EngineTemperatureController_OFF ;
        //printf("Engine Temperature controller is Turned OFF\n");
    }
}
void RoomTemperatureFunc(void)
{
    SET_BIT(Option,2);
    signed char RoomTemperatureSelect = 0   ;
    system ("cls") ;
    printf("Please Enter Temperature :\n***********************************************************************\n");
    scanf("%d",&RoomTemperatureSelect) ;
    system("cls");
    if ( (RoomTemperatureSelect < 10 ) || ( RoomTemperatureSelect > 30 ) )
    {
        AC_Mode = AC_ON ;
        RoomTemperature = RoomTemperatureSelect ;
        //printf("AC is Turned ON and Set to 20 C\n");
    }
    else
    {
        RoomTemperature = RoomTemperatureSelect ;
        AC_Mode = AC_OFF ;
       // printf("AC is Turned OFF\n");
    }
}
void TrafficLight       (void)
{
    SET_BIT(Option,3);
    char TrafficLightSelect = 0   ;
    system ("cls") ;
    printf("Please Select Traffic Light Option :\n\tOptions : 1- G \t 2- O \t 3- R \t4- E (To return to main menu)\n***********************************************************************\n");
    scanf(" %c",&TrafficLightSelect) ;
    switch ( TrafficLightSelect )
    {
    case 'G' : VehicleSpeed = 100 ; break ;
    case 'g' : VehicleSpeed = 100 ; break ;
    case 'O' : VehicleSpeed = 30 ;  break ;
    case 'o' : VehicleSpeed = 30 ;  break ;
    case 'R' : VehicleSpeed = 0 ;   break ;
    case 'r' : VehicleSpeed = 0 ;   break ;
    case 'E' : break ;
    case 'e' : break ;
    default : system("cls") ; printf("\t\tNot Valid Option\n**************************************\n"); TrafficLight () ; break ;
    }
    system("cls");
   /* if ( ( TrafficLightSelect != 'E' ) || ( TrafficLightSelect != 'e' ) )
    {
        printf("Selection is %c and Vehicle Speed = %d Km/h\n", TrafficLightSelect , VehicleSpeed ) ;
    }*/
}

void TurnOnSystem       (void)
{
    system ("cls") ;
    static int EngineOption = 0 ;
    Mode = TurnedOn ;
    printf("\t\tSystem is Turned ON \n************************************************************\n") ;
    while ( Mode == TurnedOn)
    {
        GeneralAction() ;
        if ( Option == 15 )
        {
            Display() ;
        }
        printf("\t\tPlease select one of these Sensors options \n\t\t********************************************* \n") ;
        printf("0-Turn Off Engine\n");
        printf("1-Set the traffic light color\n");
        printf("2-Set the room temperature\n");
        printf("3-Set the Engine temperature\n************************************************************\n");
        scanf("%d",&EngineOption) ;
        switch ( EngineOption )
        {
            case 0  : TurnOffSystem()       ; break ;
            case 1  : TrafficLight()        ; break ;
            case 2  : RoomTemperatureFunc() ; break ;
            case 3  : EngineTemperatureFunc();break ;
            default : printf("\n\t\tNot Valid Option\n") ; TurnOnSystem() ; break ;
        }
    }
}
void Design             (void)
{
    char SystemOption = 0 ;
    printf("************************************************************\n\t\tGOOD MORNING \n************************************************************\n") ;
    printf("\t\tPlease select one of these options \n\t\t********************************** \n") ;
    switch (Mode)
    {
        case InitialCondition   : printf("1-Turn On System\n");         break ;
        case TurnedOff          : printf("1-Turn On System\n");         break ;
        case TurnedOn           : printf("1-Turn Off System\n");        break ;
        default : system ("cls"); printf("ERROR IN System\n");          break ;
    }
    printf("0-Quit System \n************************************************************\n");
    scanf("%d",&SystemOption) ;
    switch ( SystemOption )
    {
        case 0  : system ("cls") ;   printf("\t\t System Closed GOOD BYE\n") ; break ;
        case 1  : system ("cls") ;
                switch ( Mode )
                {
                    case InitialCondition   :  TurnOnSystem() ;  break ;
                    case TurnedOff          :  TurnOnSystem() ;  break ;
                    case TurnedOn           : printf("\t\tSystem is Turned OFF \n************************************************************\n");  break ;
                    default : system ("cls"); printf("ERROR IN System\n"); break ;
                }
                break ;
        default : system ("cls") ;   printf("\n\t\tNot Valid Option\n") ; Design() ; break ;
    }
}
void TurnOffSystem      (void)
{
    Mode = TurnedOff ;
    system ("cls");
    RoomTemperature = 0 ;
    EngineTemperature = 0 ;
    VehicleSpeed = 0 ;
    Design();
}
