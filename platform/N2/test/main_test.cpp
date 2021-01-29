#include <Master0.c>
#include <unity.h>

void test_start(void){
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_free);
    TEST_ASSERT_EQUAL(rtY.bus_mode, 1);
}

void test_s00(void){
    rtDW.ChartMode = ChartModeType_free;
    rtU.device_select = 0;
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_free);
}

void test_s01(void){
    rtDW.ChartMode = ChartModeType_free;
    rtU.device_select = 1;
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_startSending);
}

void test_s02(void){
    rtDW.ChartMode = ChartModeType_free;
    rtU.device_select = 1;
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_startSending);
}


void test_s10(void){
    rtDW.ChartMode = ChartModeType_startSending;
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_sendAddr);
}


void test_s20(void){
    rtDW.ChartMode = ChartModeType_sendAddr;
    rtDW.address = 9;
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_monitor);
    TEST_ASSERT_EQUAL(rtY.bus_mode, 0);
}

void test_s30(void){
    rtDW.ChartMode = ChartModeType_monitor;
    rtU.input = 2;
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_sendCommand);
    TEST_ASSERT_EQUAL(rtY.bus_mode, 1);
}

void test_s40(void){
    rtDW.ChartMode = ChartModeType_sendCommand;
    rtU.device_select = 2;
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_free);
    TEST_ASSERT_EQUAL(rtY.bus_mode, 1);
}

void test_s41(void){
    rtDW.ChartMode = ChartModeType_sendCommand;
    rtU.device_select = 1;
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_free);
    TEST_ASSERT_EQUAL(rtY.bus_mode, 1);
}

void test_s42(void){
    rtDW.ChartMode = ChartModeType_sendCommand;
    rtU.device_select = 0;
    Master0_step();
    TEST_ASSERT_EQUAL(rtDW.ChartMode, ChartModeType_monitor);
    TEST_ASSERT_EQUAL(rtY.bus_mode, 0);
}

int main(int argc, char **argv){
    Master0_initialize();
    UNITY_BEGIN();
    RUN_TEST(test_start);
    RUN_TEST(test_s00);
    RUN_TEST(test_s01);
    RUN_TEST(test_s02);
    RUN_TEST(test_s10);
    RUN_TEST(test_s20);
    RUN_TEST(test_s30);
    RUN_TEST(test_s40);
    RUN_TEST(test_s41);
    RUN_TEST(test_s42);
    return 0;
}