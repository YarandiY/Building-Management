/*
 * File: Slave0.c
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

#include "Slave0.h"

/* Named constants for Chart: '<S1>/Chart' */
#define IN_checkAddr                   ((uint8_T)1U)
#define IN_free                        ((uint8_T)2U)
#define IN_getCommand                  ((uint8_T)3U)
#define IN_sending                     ((uint8_T)4U)

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
void Slave0_step(void)
{
  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/command'
   */
  if (rtDW.is_active_c3_Slave0 == 0U) {
    rtDW.is_active_c3_Slave0 = 1U;

    /* Outport: '<Root>/bus_mode' */
    rtY.bus_mode = 0U;
    rtDW.is_c3_Slave0 = IN_free;
  } else {
    switch (rtDW.is_c3_Slave0) {
     case IN_checkAddr:
      if (rtU.command != rtDW.ID) {
        rtDW.is_c3_Slave0 = IN_free;
      } else {
        if (rtU.command == rtDW.ID) {
          /* Outport: '<Root>/bus_mode' */
          rtY.bus_mode = 1U;

          /* Outport: '<Root>/bus_data' incorporates:
           *  Inport: '<Root>/status'
           */
          rtY.bus_data = rtU.status;
          rtDW.is_c3_Slave0 = IN_sending;
        }
      }
      break;

     case IN_free:
      if (rtU.command == 1) {
        rtDW.is_c3_Slave0 = IN_checkAddr;
      }
      break;

     case IN_getCommand:
      if (rtU.command != 0) {
        /* Outport: '<Root>/bus_mode' */
        rtY.bus_mode = 1U;

        /* Outport: '<Root>/bus_data' incorporates:
         *  Inport: '<Root>/status'
         */
        rtY.bus_data = rtU.status;
        rtDW.is_c3_Slave0 = IN_sending;
      } else {
        if (rtU.command == 0) {
          rtDW.is_c3_Slave0 = IN_free;
        }
      }
      break;

     default:
      /* Outport: '<Root>/bus_mode' */
      /* case IN_sending: */
      rtY.bus_mode = 0U;
      rtDW.is_c3_Slave0 = IN_getCommand;
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */
}

/* Model initialize function */
void Slave0_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
