/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.c
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.352
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 18 20:36:58 2021
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

/* Named constants for Chart: '<Root>/CdPlayerBehaviorModel' */
#define IN_DiscPresent                 ((uint8_T)1U)
#define IN_Ejecting                    ((uint8_T)2U)
#define IN_Empty                       ((uint8_T)3U)
#define IN_FF                          ((uint8_T)1U)
#define IN_Inserting                   ((uint8_T)4U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_PLAY                        ((uint8_T)2U)
#define IN_REW                         ((uint8_T)3U)
#define IN_STOP                        ((uint8_T)4U)

/* Named constants for Chart: '<Root>/CdPlayerModeManager' */
#define IN_AMMode                      ((uint8_T)1U)
#define IN_CDMode                      ((uint8_T)2U)
#define IN_Eject                       ((uint8_T)1U)
#define IN_FMMode                      ((uint8_T)3U)
#define IN_FastForward                 ((uint8_T)1U)
#define IN_ModeManager                 ((uint8_T)2U)
#define IN_Normal                      ((uint8_T)2U)
#define IN_ON                          ((uint8_T)1U)
#define IN_Play                        ((uint8_T)1U)
#define IN_Rew                         ((uint8_T)3U)
#define IN_Standby                     ((uint8_T)2U)
#define IN_Stop                        ((uint8_T)2U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void exit_internal_ON(void);
static void ModeManager(const RadioRequestMode *RadioReq_prev);
static void enter_internal_ModeManager(void);

/* Function for Chart: '<Root>/CdPlayerModeManager' */
static void exit_internal_ON(void)
{
  if (rtDW.is_ON == IN_CDMode) {
    rtDW.is_Play = IN_NO_ACTIVE_CHILD;
    rtDW.is_CDMode = IN_NO_ACTIVE_CHILD;

    /* Outport: '<Root>/MechCmd' */
    rtY.MechCmd = STOP;
    rtDW.is_ON = IN_NO_ACTIVE_CHILD;
  } else {
    rtDW.is_ON = IN_NO_ACTIVE_CHILD;
  }
}

/* Function for Chart: '<Root>/CdPlayerModeManager' */
static void ModeManager(const RadioRequestMode *RadioReq_prev)
{
  /* Inport: '<Root>/DiscEject' */
  if (rtU.DiscEject != 0.0) {
    if (rtDW.is_ModeManager == IN_ON) {
      exit_internal_ON();
      rtDW.is_ModeManager = IN_NO_ACTIVE_CHILD;
    } else {
      rtDW.is_ModeManager = IN_NO_ACTIVE_CHILD;
    }

    rtDW.is_c1_model = IN_Eject;

    /* Outport: '<Root>/MechCmd' */
    rtY.MechCmd = EJECT;
  } else if (rtDW.is_ModeManager == IN_ON) {
    /* Inport: '<Root>/RadioReq' */
    if (rtU.RadioReq == OFF) {
      exit_internal_ON();
      rtDW.is_ModeManager = IN_Standby;
      rtDW.was_ModeManager = IN_Standby;

      /* Outport: '<Root>/CurrentRadioMode' */
      rtY.CurrentRadioMode = OFF;

      /* Outport: '<Root>/MechCmd' */
      rtY.MechCmd = STOP;
    } else if (*RadioReq_prev != rtDW.RadioReq_start) {
      if (rtU.RadioReq == CD) {
        exit_internal_ON();
        rtDW.is_ON = IN_CDMode;
        rtDW.was_ON = IN_CDMode;

        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = CD;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;

        /* Inport: '<Root>/DiscPresent' */
        if (rtU.DiscPresent) {
          rtDW.is_CDMode = IN_Play;
          rtDW.is_Play = IN_Normal;

          /* Outport: '<Root>/MechCmd' */
          rtY.MechCmd = PLAY;
        } else {
          rtDW.is_CDMode = IN_Stop;

          /* Outport: '<Root>/MechCmd' */
          rtY.MechCmd = STOP;
        }
      } else if (rtU.RadioReq == AM) {
        exit_internal_ON();
        rtDW.is_ON = IN_AMMode;
        rtDW.was_ON = IN_AMMode;

        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = AM;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;
      } else {
        /* RadioReq==FM */
        exit_internal_ON();
        rtDW.is_ON = IN_FMMode;
        rtDW.was_ON = IN_FMMode;

        /* Outport: '<Root>/CurrentRadioMode' */
        ;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;
      }
    } else {
      switch (rtDW.is_ON) {
       case IN_AMMode:
        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = AM;
        break;

       case IN_CDMode:
        /* Outport: '<Root>/CurrentRadioMode' */
        /* Inport: '<Root>/CdReq' incorporates:
         *  Inport: '<Root>/DiscPresent'
         */
        rtY.CurrentRadioMode = CD;
        if (rtDW.is_CDMode == IN_Play) {
          /* Inport: '<Root>/CdReq' */
          if (rtU.CdReq < STOP) {
            rtDW.is_Play = IN_NO_ACTIVE_CHILD;
            rtDW.is_CDMode = IN_Stop;

            /* Outport: '<Root>/MechCmd' */
            rtY.MechCmd = STOP;
          } else if ((rtU.CdReq == FF) && (rtDW.is_Play != IN_FastForward)) {
            rtDW.is_Play = IN_FastForward;

            /* Outport: '<Root>/MechCmd' */
            rtY.MechCmd = FF;
          } else if ((rtU.CdReq == REW) && (rtDW.is_Play != IN_Rew)) {
            rtDW.is_Play = IN_Rew;

            /* Outport: '<Root>/MechCmd' */
            rtY.MechCmd = REW;
          } else {
            if ((rtU.CdReq == PLAY) && (rtDW.is_Play != IN_Normal)) {
              rtDW.is_Play = IN_Normal;

              /* Outport: '<Root>/MechCmd' */
              rtY.MechCmd = PLAY;
            }
          }
        } else {
          if (rtU.DiscPresent && (rtU.CdReq == PLAY)) {
            rtDW.is_CDMode = IN_Play;
            rtDW.is_Play = IN_Normal;

            /* Outport: '<Root>/MechCmd' */
            rtY.MechCmd = PLAY;
          }
        }
        break;

       default:
        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = FM;
        break;
      }
    }
  } else {
    /* Outport: '<Root>/CurrentRadioMode' */
    rtY.CurrentRadioMode = OFF;

    /* Inport: '<Root>/RadioReq' */
    if (rtU.RadioReq != OFF) {
      if (rtU.RadioReq == CD) {
        rtDW.is_ModeManager = IN_ON;
        rtDW.was_ModeManager = IN_ON;
        rtDW.is_ON = IN_CDMode;
        rtDW.was_ON = IN_CDMode;

        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = CD;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;

        /* Inport: '<Root>/DiscPresent' */
        if (rtU.DiscPresent) {
          rtDW.is_CDMode = IN_Play;
          rtDW.is_Play = IN_Normal;

          /* Outport: '<Root>/MechCmd' */
          rtY.MechCmd = PLAY;
        } else {
          rtDW.is_CDMode = IN_Stop;

          /* Outport: '<Root>/MechCmd' */
          rtY.MechCmd = STOP;
        }
      } else if (rtU.RadioReq == AM) {
        rtDW.is_ModeManager = IN_ON;
        rtDW.was_ModeManager = IN_ON;
        rtDW.is_ON = IN_AMMode;
        rtDW.was_ON = IN_AMMode;

        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = AM;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;
      } else {
        /* RadioReq==FM */
        rtDW.is_ModeManager = IN_ON;
        rtDW.was_ModeManager = IN_ON;
        rtDW.is_ON = IN_FMMode;
        rtDW.was_ON = IN_FMMode;

        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = FM;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;
      }
    }
  }

  /* End of Inport: '<Root>/DiscEject' */
}

/* Function for Chart: '<Root>/CdPlayerModeManager' */
static void enter_internal_ModeManager(void)
{
  switch (rtDW.was_ModeManager) {
   case IN_ON:
    rtDW.is_ModeManager = IN_ON;
    rtDW.was_ModeManager = IN_ON;
    switch (rtDW.was_ON) {
     case IN_AMMode:
      rtDW.is_ON = IN_AMMode;
      rtDW.was_ON = IN_AMMode;

      /* Outport: '<Root>/CurrentRadioMode' */
      rtY.CurrentRadioMode = AM;

      /* Outport: '<Root>/MechCmd' */
      rtY.MechCmd = STOP;
      break;

     case IN_CDMode:
      rtDW.is_ON = IN_CDMode;
      rtDW.was_ON = IN_CDMode;

      /* Outport: '<Root>/CurrentRadioMode' */
      rtY.CurrentRadioMode = CD;

      /* Outport: '<Root>/MechCmd' */
      rtY.MechCmd = STOP;

      /* Inport: '<Root>/DiscPresent' */
      if (rtU.DiscPresent) {
        rtDW.is_CDMode = IN_Play;
        rtDW.is_Play = IN_Normal;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = PLAY;
      } else {
        rtDW.is_CDMode = IN_Stop;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;
      }
      break;

     case IN_FMMode:
      rtDW.is_ON = IN_FMMode;
      rtDW.was_ON = IN_FMMode;

      /* Outport: '<Root>/CurrentRadioMode' */
      rtY.CurrentRadioMode = FM;

      /* Outport: '<Root>/MechCmd' */
      rtY.MechCmd = STOP;
      break;

     default:
      /* Inport: '<Root>/RadioReq' */
      if (rtU.RadioReq == CD) {
        rtDW.is_ON = IN_CDMode;
        rtDW.was_ON = IN_CDMode;

        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = CD;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;

        /* Inport: '<Root>/DiscPresent' */
        if (rtU.DiscPresent) {
          rtDW.is_CDMode = IN_Play;
          rtDW.is_Play = IN_Normal;

          /* Outport: '<Root>/MechCmd' */
          rtY.MechCmd = PLAY;
        } else {
          rtDW.is_CDMode = IN_Stop;

          /* Outport: '<Root>/MechCmd' */
          rtY.MechCmd = STOP;
        }
      } else if (rtU.RadioReq == AM) {
        rtDW.is_ON = IN_AMMode;
        rtDW.was_ON = IN_AMMode;

        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = AM;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;
      } else {
        /* RadioReq==FM */
        rtDW.is_ON = IN_FMMode;
        rtDW.was_ON = IN_FMMode;

        /* Outport: '<Root>/CurrentRadioMode' */
        rtY.CurrentRadioMode = FM;

        /* Outport: '<Root>/MechCmd' */
        rtY.MechCmd = STOP;
      }

      /* End of Inport: '<Root>/RadioReq' */
      break;
    }
    break;

   case IN_Standby:
    rtDW.is_ModeManager = IN_Standby;
    rtDW.was_ModeManager = IN_Standby;

    /* Outport: '<Root>/CurrentRadioMode' */
    rtY.CurrentRadioMode = OFF;

    /* Outport: '<Root>/MechCmd' */
    rtY.MechCmd = STOP;
    break;

   default:
    rtDW.is_ModeManager = IN_Standby;
    rtDW.was_ModeManager = IN_Standby;

    /* Outport: '<Root>/CurrentRadioMode' */
    rtY.CurrentRadioMode = OFF;

    /* Outport: '<Root>/MechCmd' */
    rtY.MechCmd = STOP;
    break;
  }
}

char* disc_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_FF","IN_PLAY","IN_REW","IN_STOP"};
char* beh_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_DiscPresent","IN_Ejecting","IN_Empty","IN_Inserting"};
char* playermode_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_Eject","IN_ModeManager"};
char* mode_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_ON","IN_Standby"};
char* on_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_AMMode","IN_CDMode","IN_FMMode"};
char* MechCmd_str[] = {"EMPTY","DISCINSERT","STOP","PLAY","","REW","FF","EJECT"};
char* RadioReq_str[] = {"OFF","CD","FM","AM"};
char* bool_str[] = {"false","true"};

/* Model step function */
void model_step(void)
{
  printf("%s %s %s %s %s %s %s %d %s %s %s %s ", disc_state_str[rtDW.is_DiscPresent],
    beh_state_str[rtDW.is_c4_model],
    playermode_state_str[rtDW.is_c1_model],
    mode_state_str[rtDW.is_ModeManager],
    mode_state_str[rtDW.was_ModeManager],
    on_state_str[rtDW.is_ON],
    on_state_str[rtDW.was_ON],
    rtDW.temporalCounter_i1,
    RadioReq_str[rtDW.RadioReq_start],
    bool_str[rtU.DiscInsert], RadioReq_str[rtU.RadioReq],
    bool_str[rtU.DiscEject]);

  RadioRequestMode RadioReq_prev;

  /* Chart: '<Root>/CdPlayerModeManager' incorporates:
   *  Inport: '<Root>/RadioReq'
   */
  RadioReq_prev = rtDW.RadioReq_start;
  rtDW.RadioReq_start = rtU.RadioReq;
  if (rtDW.is_active_c1_model == 0U) {
    rtDW.is_active_c1_model = 1U;
    rtDW.is_c1_model = IN_ModeManager;
    enter_internal_ModeManager();
  } else if (rtDW.is_c1_model == IN_Eject) {
    rtDW.is_c1_model = IN_ModeManager;
    enter_internal_ModeManager();
  } else {
    ModeManager(&RadioReq_prev);
  }

  /* End of Chart: '<Root>/CdPlayerModeManager' */

  /* Chart: '<Root>/CdPlayerBehaviorModel' incorporates:
   *  Inport: '<Root>/DiscInsert'
   *  Outport: '<Root>/MechCmd'
   */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c4_model == 0U) {
    rtDW.is_active_c4_model = 1U;
    rtDW.is_c4_model = IN_Empty;

    /* Outport: '<Root>/CdStatus' */
    rtY.CdStatus = EMPTY;
  } else {
    switch (rtDW.is_c4_model) {
     case IN_DiscPresent:
      if (rtY.MechCmd == EJECT) {
        rtDW.is_DiscPresent = IN_NO_ACTIVE_CHILD;

        /* Outport: '<Root>/outDiscPresent' */
        rtY.outDiscPresent = false;
        rtDW.is_c4_model = IN_Ejecting;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/CdStatus' */
        rtY.CdStatus = EJECT;
      } else if (rtY.MechCmd == STOP) {
        rtDW.is_DiscPresent = IN_STOP;

        /* Outport: '<Root>/CdStatus' */
        rtY.CdStatus = STOP;
      } else if (rtY.MechCmd != PLAY) {
        rtDW.is_DiscPresent = IN_PLAY;

        /* Outport: '<Root>/CdStatus' */
        rtY.CdStatus = PLAY;
      } else if (rtY.MechCmd == REW) {
        rtDW.is_DiscPresent = IN_REW;

        /* Outport: '<Root>/CdStatus' */
        rtY.CdStatus = REW;
      } else if (rtY.MechCmd >= FF) {
        rtDW.is_DiscPresent = IN_FF;

        /* Outport: '<Root>/CdStatus' */
        rtY.CdStatus = FF;
      } else {
        switch (rtDW.is_DiscPresent) {
         case IN_FF:
          /* Outport: '<Root>/CdStatus' */
          rtY.CdStatus = FF;
          break;

         case IN_PLAY:
          /* Outport: '<Root>/CdStatus' */
          rtY.CdStatus = PLAY;
          break;

         case IN_REW:
          /* Outport: '<Root>/CdStatus' */
          rtY.CdStatus = REW;
          break;

         default:
          /* Outport: '<Root>/CdStatus' */
          rtY.CdStatus = STOP;
          break;
        }
      }
      break;

     case IN_Ejecting:
      /* Outport: '<Root>/CdStatus' */
      rtY.CdStatus = EJECT;
      if (rtDW.temporalCounter_i1 >= 100U) {
        rtDW.is_c4_model = IN_Empty;

        /* Outport: '<Root>/CdStatus' */
        rtY.CdStatus = EMPTY;
      }
      break;

     case IN_Empty:
      /* Outport: '<Root>/CdStatus' */
      rtY.CdStatus = EMPTY;
      if (rtU.DiscInsert) {
        rtDW.is_c4_model = IN_Inserting;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/CdStatus' */
        rtY.CdStatus = DISCINSERT;
      }
      break;

     default:
      /* Outport: '<Root>/CdStatus' */
      rtY.CdStatus = DISCINSERT;
      if (rtDW.temporalCounter_i1 >= 100U) {
        rtDW.is_c4_model = IN_DiscPresent;

        /* Outport: '<Root>/outDiscPresent' */
        rtY.outDiscPresent = true;
        rtDW.is_DiscPresent = IN_STOP;

        /* Outport: '<Root>/CdStatus' */
        rtY.CdStatus = STOP;
      }
      break;
    }
  }

  printf("%s\n", MechCmd_str[rtY.MechCmd+2]);

  /* End of Chart: '<Root>/CdPlayerBehaviorModel' */
}

/* Model initialize function */
void model_initialize(void)
{
  /* Registration code */

  /* external inputs */
  rtU.CdReq = EMPTY;

  /* external outputs */
  rtY.MechCmd = EMPTY;
  rtY.CdStatus = EMPTY;

  /* SystemInitialize for Outport: '<Root>/CurrentRadioMode' incorporates:
   *  Chart: '<Root>/CdPlayerModeManager'
   */
  rtY.CurrentRadioMode = OFF;

  /* SystemInitialize for Outport: '<Root>/MechCmd' incorporates:
   *  Chart: '<Root>/CdPlayerModeManager'
   */
  rtY.MechCmd = EMPTY;

  //nat
  rtDW.is_active_c4_model = 0;
  rtDW.is_c4_model = 0;
  rtDW.is_active_c1_model = 0;
  rtDW.is_c1_model = 0;
  rtDW.temporalCounter_i1 = 0;
  //nat
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
