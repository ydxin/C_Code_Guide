#include "chapter11.h"
void PrintDefineInfo()
{
	printf("当前行号： %d\n", __LINE__);
	printf("当前函数： %s\n", __FUNCTION__);
	printf("当前函数： %s\n", __func__);
	printf("当前文件： %s\n", __FILE__);
	printf("创建时间： %s\n", __TIME__);
	printf("创建日期： %s\n", __DATE__);
}

void PrintDataTime()
{
	printf("一年有%d秒", DAYS_PER_YEAR* HOURS_PER_DAY* MINS_PER_HOUR* SECONDS_PER_MIN);
}