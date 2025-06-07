#include "test.h"
#include "../../program1/common/model.h"

extern ExtU rtU;
extern ExtY rtY;

static void to_first(void) {
    // gearType_None
    model_initialize();
    // speed = 0.0 이므로 None > first
    rtU.speed    = 0.0;
    rtU.throttle = 0.0;
    // rtY.gear == gearType_first
    model_step();  
}

static void to_second(void) {
    to_first();
    // upshift(p2)를 발생 : speed >= up_threshold 조건을 26회 동안 유지
    rtU.speed    = 1.0;
    rtU.throttle = 0.0;
    for (int i = 0; i < 26; i++) {
        model_step();  // 26회 후 rtY.gear == gearType_second
    }
}

static void to_third(void) {
    to_second();
    // upshift(p3)를 발생 : speed >= up_threshold 조건을 26회 동안 유지
    rtU.speed    = 1.0;
    rtU.throttle = 0.0;
    for (int i = 0; i < 26; i++) {
        model_step();  // 26회 후 rtY.gear == gearType_third
    }
}

static void to_fourth(void) {
    to_third();
    // upshift(p5)를 발생 : speed >= up_threshold 조건을 26회 동안 유지
    rtU.speed    = 1.0;
    rtU.throttle = 0.0;
    for (int i = 0; i < 26; i++) {
        model_step();  // 26회 후 rtY.gear == gearType_fourth
    }
}

int main() {
    describe("Transition Coverage 테스트", {

        test("p2: first > second", {
            to_first();
            rtU.speed    = 1.0;
            rtU.throttle = 0.0;
            for (int i = 0; i < 26; i++) {
                model_step();
            }
            expect(rtY.gear == gearType_second);
        });

        test("p3: second > third", {
            to_second();
            rtU.speed    = 1.0;
            rtU.throttle = 0.0;
            for (int i = 0; i < 26; i++) {
                model_step();
            }
            expect(rtY.gear == gearType_third);
        });

        test("p5: third > fourth", {
            to_third();
            rtU.speed    = 1.0;
            rtU.throttle = 0.0;
            for (int i = 0; i < 26; i++) {
                model_step();
            }
            expect(rtY.gear == gearType_fourth);
        });

        test("p1: fourth > third", {
            to_fourth();
            rtU.speed    = -1.0;
            rtU.throttle = 0.0;
            for (int i = 0; i < 26; i++) {
                model_step();
            }
            expect(rtY.gear == gearType_third);
        });

        test("p6: third > second", {
            to_third();
            rtU.speed    = -1.0;
            rtU.throttle = 0.0;
            for (int i = 0; i < 26; i++) {
                model_step();
            }
            expect(rtY.gear == gearType_second);
        });

        test("p4: second > first", {
            to_second();
            rtU.speed    = -1.0;
            rtU.throttle = 0.0;
            model_step();
            expect(rtY.gear == gearType_first);
        });

        test("p0: first > first", {
            to_first();
            rtU.speed    = 0.0;
            rtU.throttle = 0.0;
            model_step();
            expect(rtY.gear == gearType_first);
        });

        test("p7: second > second", {
            to_second();
            rtU.speed    = 0.0;
            rtU.throttle = 0.0;
            model_step();
            expect(rtY.gear == gearType_second);
        });

        test("p8: third > third", {
            to_third();
            rtU.speed    = 0.0;
            rtU.throttle = 0.0;
            model_step();
            expect(rtY.gear == gearType_third);
        });

        test("p9: fourth > fourth", {
            to_fourth();
            rtU.speed    = 0.0;
            rtU.throttle = 0.0;
            model_step();
            expect(rtY.gear == gearType_fourth);
        });
    });

    printf("\nTest Results: Passed: %d, Failed: %d\n", stats.passed, stats.failed);
    return (stats.failed == 0) ? 0 : 1;
}
