#ifndef UTIL_H
#define UTIL_H

#define ALL_OK 0
#define UNUSED 1
#define GRAVITY 9.81


// water params
#define DEFAULT 0.0
#define PERFECT 100
#define BOD_DECAY_RATE 0.23
#define POLLUTANT_DECAY_RATE 0.1;
#define MIN_ALLOWABLE_PH 0.65
#define ROOM_TEMPERATURE 25.0
#define PH_NEUTRAL 7.0
#define WATER_DENSITY 1000      /* kg/m^3*/


// pipe
#define PIPE_AGE_MAX 25
#define CORROSION_RATE_MAX 1.0  /* rate of corrosion */
#define MATERIAL_COST_FACTOR_GENERIC 1.5    /* cost factor general */
#define MATERIAL_COST_FACTOR_PVC 1.0        /* cost factor PVC*/
#define REPAIR_FACTOR_CORRODED 2.0      /* repair factor for corroded component */
#define REPAIR_FACTOR_NON_CORRODED 1.0

#endif