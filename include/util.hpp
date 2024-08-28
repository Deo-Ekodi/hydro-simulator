#ifndef UTIL_H
#define UTIL_H

#define ALL_OK 0
#define UNUSED 1

// water quality
#define BOD_DECAY_RATE 0.23
#define MIN_ALLOWABLE_PH 0.65

// pipe
#define PIPE_AGE_MAX 25
#define CORROSION_RATE_MAX 1.0  /* rate of corrosion */
#define MATERIAL_COST_FACTOR_GENERIC 1.5    /* cost factor general */
#define MATERIAL_COST_FACTOR_PVC 1.0        /* cost factor PVC*/
#define REPAIR_FACTOR_CORRODED 2.0      /* repair factor for corroded component */
#define REPAIR_FACTOR_NON_CORRODED 1.0

#endif