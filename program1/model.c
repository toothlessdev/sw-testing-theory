/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.c
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.178
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Aug 16 22:40:40 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Mac OS X)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */
#include<stdio.h>
#include "common/model.h"

const ConstP rtConstP = {
  /* Expression: downtab
   * Referenced by: '<S2>/interp_down'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 30.0, 30.0, 20.0, 20.0,
    25.0, 30.0, 50.0, 50.0, 35.0, 35.0, 40.0, 50.0, 80.0, 80.0 },

  /* Expression: downth
   * Referenced by: '<S2>/interp_down'
   */
  { 0.0, 5.0, 40.0, 50.0, 90.0, 100.0 },

  /* Pooled Parameter (Expression: [1:4])
   * Referenced by:
   *   '<S2>/interp_down'
   *   '<S2>/interp_up'
   */
  { 1.0, 2.0, 3.0, 4.0 },

  /* Expression: uptab
   * Referenced by: '<S2>/interp_up'
   */
  { 10.0, 10.0, 15.0, 23.0, 40.0, 40.0, 30.0, 30.0, 30.0, 41.0, 70.0, 70.0, 50.0,
    50.0, 50.0, 60.0, 100.0, 100.0, 1.0E+6, 1.0E+6, 1.0E+6, 1.0E+6, 1.0E+6,
    1.0E+6 },

  /* Expression: upth
   * Referenced by: '<S2>/interp_up'
   */
  { 0.0, 25.0, 35.0, 50.0, 90.0, 100.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/interp_down'
   *   '<S2>/interp_up'
   */
  { 5U, 3U }
};

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static real_T look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
static void calculate_thresholds(gearType rtu_gear, real_T rtu_throttle, real_T *
  rty_down_th, real_T *rty_up_th);
static real_T look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  real_T yL_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx]) -
          yL_1d) * frac + yL_1d;
}

/* Output and update for function-call system: '<S1>/calculate_thresholds' */
static void calculate_thresholds(gearType rtu_gear, real_T rtu_throttle, real_T *
  rty_down_th, real_T *rty_up_th)
{
  int32_T rtb_out;

  /* MATLAB Function: '<S2>/Look-Up' */
  switch (rtu_gear) {
   case gearType_fourth:
    rtb_out = 4;
    break;

   case gearType_third:
    rtb_out = 3;
    break;

   case gearType_second:
    rtb_out = 2;
    break;

   default:
    rtb_out = 1;
    break;
  }

  /* End of MATLAB Function: '<S2>/Look-Up' */

  /* Lookup_n-D: '<S2>/interp_down' */
  *rty_down_th = look2_binlx(rtu_throttle, rtb_out,
    rtConstP.interp_down_bp01Data, rtConstP.pooled1,
    rtConstP.interp_down_tableData, rtConstP.pooled2, 6U);

  /* Lookup_n-D: '<S2>/interp_up' */
  *rty_up_th = look2_binlx(rtu_throttle, rtb_out, rtConstP.interp_up_bp01Data,
    rtConstP.pooled1, rtConstP.interp_up_tableData, rtConstP.pooled2, 6U);
}

char* state_str[] = {"gearType_None","gearType_first","gearType_second","gearType_third","gearType_fourth"};
#define TWAIT ((uint8_T) 25)

/* Model step function */
void model_step(void)
{
  // printf("%s ", state_str[rtY.gear]);

  boolean_T down;

  /* Chart: '<Root>/Gear_logic' incorporates:
   *  Inport: '<Root>/speed'
   *  Inport: '<Root>/throttle'
   *  Outport: '<Root>/gear'
   */
  rtDW.chartAbsoluteTimeCounter++;
  down = (rtU.speed >= rtDW.up_threshold);
  if ((!down) || (!rtDW.condWasTrueAtLastTimeStep_3)) {
    rtDW.durationLastReferenceTick_3 = rtDW.chartAbsoluteTimeCounter;
  }

  rtDW.condWasTrueAtLastTimeStep_3 = down;
  down = (rtU.speed <= rtDW.down_threshold);
  if ((!down) || (!rtDW.condWasTrueAtLastTimeStep_4)) {
    rtDW.durationLastReferenceTick_4 = rtDW.chartAbsoluteTimeCounter;
  }

  rtDW.condWasTrueAtLastTimeStep_4 = down;
  if (rtDW.is_active_c1_model == 0U) {
    rtDW.chartAbsoluteTimeCounter = 0;
    rtDW.is_active_c1_model = 1U;
    rtDW.condWasTrueAtLastTimeStep_4 = false;
    rtDW.durationLastReferenceTick_4 = rtDW.chartAbsoluteTimeCounter;
    rtDW.condWasTrueAtLastTimeStep_3 = false;
    rtDW.durationLastReferenceTick_3 = rtDW.chartAbsoluteTimeCounter;

    /* Outputs for Function Call SubSystem: '<S1>/calculate_thresholds' */
    // calculate_thresholds(rtY.gear, rtU.throttle, &rtDW.down_threshold,
                         // &rtDW.up_threshold);

    /* End of Outputs for SubSystem: '<S1>/calculate_thresholds' */
    down = (rtU.speed <= rtDW.down_threshold);
    if ((!down) || (!rtDW.condWasTrueAtLastTimeStep_4)) {
      rtDW.durationLastReferenceTick_4 = rtDW.chartAbsoluteTimeCounter;
    }

    rtDW.condWasTrueAtLastTimeStep_4 = down;
    down = (rtU.speed >= rtDW.up_threshold);
    if ((!down) || (!rtDW.condWasTrueAtLastTimeStep_3)) {
      rtDW.durationLastReferenceTick_3 = rtDW.chartAbsoluteTimeCounter;
    }

    rtDW.condWasTrueAtLastTimeStep_3 = down;
    down = (rtU.speed >= rtDW.up_threshold);
    if ((!down) || (!rtDW.condWasTrueAtLastTimeStep_3)) {
      rtDW.durationLastReferenceTick_3 = rtDW.chartAbsoluteTimeCounter;
    }

    rtDW.condWasTrueAtLastTimeStep_3 = down;
    down = (rtU.speed <= rtDW.down_threshold);
    if ((!down) || (!rtDW.condWasTrueAtLastTimeStep_4)) {
      rtDW.durationLastReferenceTick_4 = rtDW.chartAbsoluteTimeCounter;
    }

    rtDW.condWasTrueAtLastTimeStep_4 = down;

    /* Outport: '<Root>/gear' incorporates:
     *  Inport: '<Root>/throttle'
     */
    rtY.gear = gearType_first;
  } else {
    /* Outputs for Function Call SubSystem: '<S1>/calculate_thresholds' */
    // calculate_thresholds(rtY.gear, rtU.throttle, &rtDW.down_threshold,
    //                      &rtDW.up_threshold);

    /* End of Outputs for SubSystem: '<S1>/calculate_thresholds' */
    down = (rtU.speed <= rtDW.down_threshold);
    if ((!down) || (!rtDW.condWasTrueAtLastTimeStep_4)) {
      rtDW.durationLastReferenceTick_4 = rtDW.chartAbsoluteTimeCounter;
    }

    rtDW.condWasTrueAtLastTimeStep_4 = down;
    down = (rtU.speed >= rtDW.up_threshold);
    if ((!down) || (!rtDW.condWasTrueAtLastTimeStep_3)) {
      rtDW.durationLastReferenceTick_3 = rtDW.chartAbsoluteTimeCounter;
    }

    rtDW.condWasTrueAtLastTimeStep_3 = down;
    down = (rtU.speed <= rtDW.down_threshold);
    if ((!down) || (!rtDW.condWasTrueAtLastTimeStep_4)) {
      rtDW.durationLastReferenceTick_4 = rtDW.chartAbsoluteTimeCounter;
    }

    rtDW.condWasTrueAtLastTimeStep_4 = down;
    down = (rtDW.chartAbsoluteTimeCounter / rtDW.durationLastReferenceTick_4 >
            25);
    switch (rtY.gear) {
     case gearType_first:
      if (rtDW.chartAbsoluteTimeCounter - rtDW.durationLastReferenceTick_3 > 25)
      {
        rtY.gear = gearType_second;
      }
      break;

     case gearType_second:
      if (rtDW.chartAbsoluteTimeCounter - rtDW.durationLastReferenceTick_3 > 25)
      {
        rtY.gear = gearType_third;
      } else {
        if (down) {
          rtY.gear = gearType_first;
        }
      }
      break;

     case gearType_third:
      if (rtDW.chartAbsoluteTimeCounter - rtDW.durationLastReferenceTick_3 > 25)
      {
        rtY.gear = gearType_fourth;
      } else {
        if (down) {
          rtY.gear = gearType_second;
        }
      }
      break;

     default:
      if (down) {
        rtY.gear = gearType_third;
      }
      break;
    }
  }

  // printf("%d %d %d %d\n", rtDW.chartAbsoluteTimeCounter, 
  //   rtDW.durationLastReferenceTick_3, 
  //   rtDW.durationLastReferenceTick_4, TWAIT);

  /* End of Chart: '<Root>/Gear_logic' */
}

/* Model initialize function */
void model_initialize(void)
{
  /* SystemInitialize for Outport: '<Root>/gear' incorporates:
   *  Chart: '<Root>/Gear_logic'
   */
  rtY.gear = gearType_None;

  //nat
  rtDW.is_active_c1_model = 0;
  rtDW.chartAbsoluteTimeCounter = 0;
  rtDW.durationLastReferenceTick_3 = 0;
  rtDW.durationLastReferenceTick_4 = 0;
  //nat
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
