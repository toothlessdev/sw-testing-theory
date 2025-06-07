#include "test.h"
#include "../../program2/common/model.h"

extern void ModeManager(const RadioRequestMode *RadioReq_prev);

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
describe("ModeManager (Decision + MC/DC Coverage)", {
    test("DiscEject == true 경로", {
        reset_all();
        rtDW.is_ModeManager = IN_ON;
        rtU.DiscEject = true;
        ModeManager(&rtDW.RadioReq_start);
        expect(rtY.MechCmd == EJECT);
        expect(rtDW.is_c1_model == IN_Eject);
    });
    test("RadioReq == OFF 경로", {
        reset_all();
        rtDW.is_ModeManager = IN_ON;
        rtU.RadioReq = OFF;
        ModeManager(&rtDW.RadioReq_start);
        expect(rtY.CurrentRadioMode == OFF);
        expect(rtY.MechCmd == STOP);
    });
    test("OFF > CD 전환 경로", {
        reset_all();
        rtDW.is_ModeManager = IN_ON;
        rtDW.RadioReq_start = OFF;
        rtU.RadioReq = CD;
        rtU.DiscPresent = false;
        ModeManager(&rtDW.RadioReq_start);
        expect(rtY.CurrentRadioMode == CD);
        expect(rtY.MechCmd == STOP);
    });
    test("OFF > FM 전환 경로", {
        reset_all();
        rtDW.is_ModeManager = IN_ON;
        rtDW.RadioReq_start = OFF;
        rtU.RadioReq = FM;
        ModeManager(&rtDW.RadioReq_start);
        // **FM 분기에서 할당문 스킵 버그가 있으면 이 기대가 FAIL 됩니다**
        expect(rtY.CurrentRadioMode == FM);
        expect(rtY.MechCmd          == STOP);
    });
    test("ON 유지 상태에서 CdReq 변화", {
        reset_all();
        // 이미 CD 모드 진입 후_play 상태
        rtDW.is_ModeManager = IN_ON;
        rtU.RadioReq = CD;
        ModeManager(&rtDW.RadioReq_start);
        reset_all();
        rtDW.is_ModeManager = IN_ON;
        rtDW.is_ON          = IN_CDMode;
        rtDW.is_CDMode      = IN_Play;
        rtU.CdReq = PLAY;
        ModeManager(&rtDW.RadioReq_start);
        expect(rtY.MechCmd == PLAY);
    });
});

    return 0;
}