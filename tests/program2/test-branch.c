#include "test.h"
#include "../../program2/common/model.h"

extern void exit_internal_ON(void);

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


static void reset_all(void) {
    rtDW.is_active_c1_model = 0;
    rtDW.is_c1_model       = 0;
    rtDW.is_active_c4_model = 0;
    rtDW.is_c4_model       = 0;
    rtDW.temporalCounter_i1 = 0;
    rtDW.is_ON             = 0;
    rtDW.was_ON            = 0;
    rtDW.is_ModeManager    = 0;
    rtDW.was_ModeManager   = 0;
    rtDW.RadioReq_start    = OFF;

    rtU.DiscEject   = false;
    rtU.RadioReq    = OFF;
    rtU.DiscPresent = false;
    rtU.DiscInsert  = false;
    rtU.CdReq       = EMPTY;

    rtY.CurrentRadioMode = OFF;
    rtY.MechCmd          = EMPTY;
    rtY.CdStatus         = EMPTY;
    rtY.outDiscPresent   = false;
}

int main() {
    describe("exit_internal_ON (Branch Coverage)", {
        test("is_ON == IN_CDMode 분기", {
            reset_all();
            rtDW.is_ON = IN_CDMode;
            exit_internal_ON();
            expect(rtY.MechCmd == STOP);
            expect(rtDW.is_ON == IN_NO_ACTIVE_CHILD);
        });
        test("is_ON != IN_CDMode 분기", {
            reset_all();
            rtDW.is_ON = IN_AMMode;
            exit_internal_ON();
            // MechCmd는 변경되지 않음(기본 EMPTY)
            expect(rtY.MechCmd == EMPTY);
            expect(rtDW.is_ON == IN_NO_ACTIVE_CHILD);
        });
    });
}