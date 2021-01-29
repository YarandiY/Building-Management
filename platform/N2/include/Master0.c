/*
 * File: Master0.c
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

#include "Master0.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Master0_step(void)
{
  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/device_select'
   */
  if (rtDW.is_active_c3_Master0 == 0U) {
    rtDW.is_active_c3_Master0 = 1U;

    /* Outport: '<Root>/bus_mode' */
    rtY.bus_mode = 1U;
    rtDW.ChartMode = ChartModeType_free;
  } else {
    switch (rtDW.ChartMode) {
     case ChartModeType_free:
      if ((rtU.device_select == 1) || (rtU.device_select == 2)) {
        /* Outport: '<Root>/bus_data' */
        rtY.bus_data = 1U;
        rtDW.ChartMode = ChartModeType_startSending;
      }
      break;

     case ChartModeType_startSending:
      /* Outport: '<Root>/bus_data' */
      rtY.bus_data = rtDW.address;
      rtDW.ChartMode = ChartModeType_sendAddr;
      break;

     case ChartModeType_sendAddr:
      /* Outport: '<Root>/bus_mode' */
      rtY.bus_mode = 0U;
      rtDW.ChartMode = ChartModeType_monitor;
      break;

     case ChartModeType_monitor:
      /* Outport: '<Root>/bus_mode' */
      rtY.bus_mode = 1U;

      /* Outport: '<Root>/bus_data' incorporates:
       *  Inport: '<Root>/input'
       */
      rtY.bus_data = rtU.input;
      rtDW.ChartMode = ChartModeType_sendCommand;
      break;

     default:
      /* State sendCommand */
      if ((rtU.device_select != 1) && (rtU.device_select != 2)) {
        /* Outport: '<Root>/bus_mode' */
        rtY.bus_mode = 0U;
        rtDW.ChartMode = ChartModeType_monitor;
      } else {
        if ((rtU.device_select == 1) || (rtU.device_select == 2)) {
          /* Outport: '<Root>/bus_data' */
          rtY.bus_data = 0U;
          rtDW.ChartMode = ChartModeType_free;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */
}

/* Model initialize function */
void Master0_initialize(void)
{
  /* SystemInitialize for Chart: '<S1>/Chart' */
  rtDW.ChartMode = ChartModeType_None;
  rtY.bus_mode = 1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
