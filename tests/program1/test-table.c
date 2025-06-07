#include "test.h"
#include "../../program1/common/model.h"

extern ExtU rtU;
extern ExtY rtY;
extern DW rtDW;

static void to_first(void) {
    model_initialize();
    rtU.speed = 0.0;
    rtU.throttle = 0.0;
    model_step();
}

static void to_second(void) {
    to_first();
    rtU.speed = 1.0;
    rtU.throttle = 0.0;
    for (int i = 0; i < 26; i++) model_step();
}
int main(void) {
describe("의사 결정 테이블 테스팅 (Decision Table Testing)", {
    test("R1: Gear 2, High Throttle > Upshift", {
        to_second();
        rtU.throttle = 95.0;
        rtU.speed = 71.0;

        for (int i = 0; i < 26; i++) {
            model_step();
        }
        expect(rtY.gear == gearType_third);
    });

    test("R2: Gear 2, High Throttle > Downshift", {
        to_second();
        rtU.throttle = 95.0;
        rtU.speed = 29.0;

        for (int i = 0; i < 26; i++) {
            model_step();
        }
        expect(rtY.gear == gearType_first);
    });

    test("R3: Gear 2, Low Throttle > Upshift", {
        to_second();
        rtU.throttle = 10.0;
        rtU.speed = 31.0;

        for (int i = 0; i < 26; i++) {
            model_step();
        }
        expect(rtY.gear == gearType_third);
    });
    
    test("R4: Gear 2, Low Throttle > Downshift", {
        to_second();
        rtU.throttle = 10.0;
        rtU.speed = 4.0;

        for (int i = 0; i < 26; i++) {
            model_step();
        }
        expect(rtY.gear == gearType_first);
    });

    test("R5: Gear 2, High Throttle > Maintain Gear", {
        to_second();
        rtU.throttle = 95.0;
        rtU.speed = 50.0;

        for (int i = 0; i < 26; i++) {
            model_step();
        }
        expect(rtY.gear == gearType_second);
    });
});

    printf("\nTest Results: Passed: %d, Failed: %d\n", stats.passed, stats.failed);
    return (stats.failed == 0) ? 0 : 1;
}
