/*
 * File: Master0.h
 *
 * Code generated for Simulink model 'Master0'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Jan 21 20:09:08 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Master0_h_
#define RTW_HEADER_Master0_h_
#include "rtwtypes.h"
#include <stddef.h>
#ifndef Master0_COMMON_INCLUDES_
# define Master0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Master0_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define Master0_M                      (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_ChartModeType_
#define DEFINED_TYPEDEF_FOR_ChartModeType_

typedef enum {
  ChartModeType_None = 0,              /* Default value */
  ChartModeType_free,
  ChartModeType_startSending,
  ChartModeType_sendAddr,
  ChartModeType_monitor,
  ChartModeType_sendCommand
} ChartModeType;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  ChartModeType ChartMode;             /* '<S1>/Chart' */
  uint8_T is_active_c3_Master0;        /* '<S1>/Chart' */
  uint8_T address;                     /* '<S1>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T device_select;               /* '<Root>/device_select' */
  uint8_T input;                       /* '<Root>/input' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T bus_mode;                    /* '<Root>/bus_mode' */
  uint8_T bus_data;                    /* '<Root>/bus_data' */
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
extern void Master0_initialize(void);
extern void Master0_step(void);

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
 * hilite_system('master/Master')    - opens subsystem master/Master
 * hilite_system('master/Master/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'master'
 * '<S1>'   : 'master/Master'
 * '<S2>'   : 'master/Master/Chart'
 */
#endif                                 /* RTW_HEADER_Master0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
