/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.h
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

#ifndef RTW_HEADER_model_h_
#define RTW_HEADER_model_h_
#include "rtwtypes.h"
#ifndef model_COMMON_INCLUDES_
# define model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* model_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_gearType_
#define DEFINED_TYPEDEF_FOR_gearType_

typedef enum {
  gearType_None = 0,                   /* Default value */
  gearType_first,
  gearType_second,
  gearType_third,
  gearType_fourth
} gearType;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T down_threshold;               /* '<Root>/Gear_logic' */
  real_T up_threshold;                 /* '<Root>/Gear_logic' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/Gear_logic' */
  int32_T durationLastReferenceTick_3; /* '<Root>/Gear_logic' */
  int32_T durationLastReferenceTick_4; /* '<Root>/Gear_logic' */
  uint8_T is_active_c1_model;          /* '<Root>/Gear_logic' */
  boolean_T condWasTrueAtLastTimeStep_3;/* '<Root>/Gear_logic' */
  boolean_T condWasTrueAtLastTimeStep_4;/* '<Root>/Gear_logic' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: downtab
   * Referenced by: '<S2>/interp_down'
   */
  real_T interp_down_tableData[24];

  /* Expression: downth
   * Referenced by: '<S2>/interp_down'
   */
  real_T interp_down_bp01Data[6];

  /* Pooled Parameter (Expression: [1:4])
   * Referenced by:
   *   '<S2>/interp_down'
   *   '<S2>/interp_up'
   */
  real_T pooled1[4];

  /* Expression: uptab
   * Referenced by: '<S2>/interp_up'
   */
  real_T interp_up_tableData[24];

  /* Expression: upth
   * Referenced by: '<S2>/interp_up'
   */
  real_T interp_up_bp01Data[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/interp_down'
   *   '<S2>/interp_up'
   */
  uint32_T pooled2[2];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T throttle;                     /* '<Root>/throttle' */
  real_T speed;                        /* '<Root>/speed' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  gearType gear;                       /* '<Root>/gear' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void model_initialize(void);
extern void model_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'model'
 * '<S1>'   : 'model/Gear_logic'
 * '<S2>'   : 'model/Gear_logic/calculate_thresholds'
 * '<S3>'   : 'model/Gear_logic/calculate_thresholds/Look-Up'
 */
#endif                                 /* RTW_HEADER_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
