#include "test.h"
#include "../../program1/common/model.h"

extern ExtU rtU;
extern ExtY rtY;

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

static void to_third(void) {
    to_second();
    rtU.speed = 1.0;
    rtU.throttle = 0.0;
    for (int i = 0; i < 26; i++) model_step();
}

static void to_fourth(void) {
    to_third();
    rtU.speed = 1.0;
    rtU.throttle = 0.0;
    for (int i = 0; i < 26; i++) model_step();
}

int main(void) {
    describe("25 TWAIT 경계값 (Boundary Value Testing)", {

        test("p2: first > second", {
            to_first();            
            rtU.speed = 1.0;      
            rtU.throttle = 0.0;
            
            printf("25 회 전까지는 first 상태 유지 : ");
            for (int i = 0; i < 25; i++) model_step();
            expect(rtY.gear == gearType_first);

            
            printf("26 회 부터 first > second 전이 : ");
            model_step();
            expect(rtY.gear == gearType_second);

            printf("27 회에도 second 상태 유지 : ");
            model_step();
            expect(rtY.gear == gearType_second);
        });

        test("p3: second > third", {
            to_second();           
            rtU.speed = 1.0;      
            rtU.throttle = 0.0;
            
            printf("25 회 전까지는 second 상태 유지 : ");
            for (int i = 0; i < 25; i++) model_step();
            expect(rtY.gear == gearType_second);

            printf("26 회 부터 second > third 전이 : ");
            model_step();
            expect(rtY.gear == gearType_third);

            printf("27 회에도 third 상태 유지 : ");
            model_step();
            expect(rtY.gear == gearType_third);
        });

        test("p5: third > fourth", {
            to_third();            
            rtU.speed = 1.0;      
            rtU.throttle = 0.0;
            
            printf("25 회 전까지는 third 상태 유지 : ");
            for (int i = 0; i < 25; i++) model_step();
            expect(rtY.gear == gearType_third);

            printf("26 회 부터 third > fourth 전이 : ");
            model_step();
            expect(rtY.gear == gearType_fourth);

            printf("27 회에도 fourth 상태 유지 : ");
            model_step();
            expect(rtY.gear == gearType_fourth);
        });

        test("p1: fourth > third", {
            to_fourth();           
            rtU.speed = -1.0;     
            rtU.throttle = 0.0;
            
            printf("25 회 전까지는 fourth 상태 유지 : ");
            for (int i = 0; i < 25; i++) model_step();
            expect(rtY.gear == gearType_fourth);

            printf("26 회 부터 fourth > third 전이 : ");
            model_step();
            expect(rtY.gear == gearType_third);

            printf("27 회에도 third 상태 유지 : ");
            model_step();
            expect(rtY.gear == gearType_third);
        });

        test("p6: third > second", {
            to_third();            
            rtU.speed = -1.0;     
            rtU.throttle = 0.0;
            
            printf("25 회 전까지는 third 상태 유지 : ");
            for (int i = 0; i < 25; i++) model_step();
            expect(rtY.gear == gearType_third);

            printf("26 회 부터 third > second 전이 : ");
            model_step();
            expect(rtY.gear == gearType_second);

            printf("27 회에도 second 상태 유지 : ");
            model_step();
            expect(rtY.gear == gearType_second);
        });

        test("p4: second > first", {
            to_second();           
            rtU.speed = -1.0;     
            rtU.throttle = 0.0;
            
            printf("25 회 전까지는 second 상태 유지 : ");
            for (int i = 0; i < 25; i++) model_step();
            expect(rtY.gear == gearType_second);

            printf("26 회 부터 second > first 전이 : ");
            model_step();
            expect(rtY.gear == gearType_first);

            printf("27 회에도 first 상태 유지 : ");
            model_step();
            expect(rtY.gear == gearType_first);
        });

        test("p0: first > first", {
            to_first();            
            rtU.speed = 0.0;      
            rtU.throttle = 0.0;
            
            printf("25 회 전까지는 first 상태 유지 : ");
            for (int i = 0; i < 25; i++) model_step();
            expect(rtY.gear == gearType_first);
        });

        test("p7: second > second", {
            to_second();           
            rtU.speed = 0.0;      
            rtU.throttle = 0.0;
            
            printf("25 회 전까지는 second 상태 유지 : ");
            for (int i = 0; i < 25; i++) model_step();
            expect(rtY.gear == gearType_second);
        });

    });

    printf("\nTest Results: Passed: %d, Failed: %d\n", stats.passed, stats.failed);
    return (stats.failed == 0) ? 0 : 1;
}

