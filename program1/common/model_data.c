/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model_data.c
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

#include "../common/model.h"

/* Constant parameters (default storage) */
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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
