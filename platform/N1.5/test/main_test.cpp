#include <Slave0.c>
#include <unity.h>

void test_start(void){
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_free);
    TEST_ASSERT_EQUAL(rtY.bus_mode, 0);
}

void test_s00(void){
    rtDW.is_c3_Slave0 = IN_free;
    rtU.command = 0;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_free);
}

void test_s01(void){
    rtDW.is_c3_Slave0 = IN_free;
    rtU.command = 1;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_checkAddr);
}

void test_s02(void){
    rtDW.is_c3_Slave0 = IN_free;
    rtU.command = 2;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_free);
}

void test_s10(void){
    rtDW.is_c3_Slave0 = IN_checkAddr;
    rtU.command = 9;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_free);
}

void test_s11(void){
    rtDW.is_c3_Slave0 = IN_checkAddr;
    rtU.command = rtDW.ID;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_sending);
}

void test_s20(void){
    rtDW.is_c3_Slave0 = IN_sending;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_getCommand);
}

void test_s30(void){
    rtDW.is_c3_Slave0 = IN_getCommand;
    rtU.command = 2;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_sending);
}

void test_s31(void){
    rtDW.is_c3_Slave0 = IN_getCommand;
    rtU.command = 3;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_sending);
}

void test_s32(void){
    rtDW.is_c3_Slave0 = IN_getCommand;
    rtU.command = 4;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_sending);
    Slave0_step();
    rtU.command = 0;
    Slave0_step();
    TEST_ASSERT_EQUAL(rtDW.is_c3_Slave0, IN_free);

}

int main(int argc, char **argv){
    Slave0_initialize();
    rtDW.ID = 8;
    UNITY_BEGIN();
    RUN_TEST(test_start);
    RUN_TEST(test_s00);
    RUN_TEST(test_s01);
    RUN_TEST(test_s02);
    RUN_TEST(test_s10);
    RUN_TEST(test_s11);
    RUN_TEST(test_s20);
    RUN_TEST(test_s30);
    RUN_TEST(test_s31);
    RUN_TEST(test_s32);
    return 0;
}