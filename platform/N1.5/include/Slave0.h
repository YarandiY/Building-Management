/*
 * File: Slave0.h
 *
 * Code generated for Simulink model 'Slave0'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Jan 21 20:12:39 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Slave0_h_
#define RTW_HEADER_Slave0_h_
#include <stddef.h>
#ifndef Slave0_COMMON_INCLUDES_
# define Slave0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Slave0_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define Slave0_M                       (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_Slave0;         /* '<S1>/Chart' */
  uint8_T is_c3_Slave0;                /* '<S1>/Chart' */
  uint8_T ID;                          /* '<S1>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T command;                     /* '<Root>/command' */
  uint8_T status;                      /* '<Root>/status' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T bus_data;                    /* '<Root>/bus_data' */
  uint8_T bus_mode;                    /* '<Root>/bus_mode' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Slave0_initialize(void);
extern void Slave0_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('slave/Slave')    - opens subsystem slave/Slave
 * hilite_system('slave/Slave/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'slave'
 * '<S1>'   : 'slave/Slave'
 * '<S2>'   : 'slave/Slave/Chart'
 */
#endif                                 /* RTW_HEADER_Slave0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
