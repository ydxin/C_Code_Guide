#include "chapter11.h"
void PrintDefineInfo()
{
	printf("��ǰ�кţ� %d\n", __LINE__);
	printf("��ǰ������ %s\n", __FUNCTION__);
	printf("��ǰ������ %s\n", __func__);
	printf("��ǰ�ļ��� %s\n", __FILE__);
	printf("����ʱ�䣺 %s\n", __TIME__);
	printf("�������ڣ� %s\n", __DATE__);
}

void PrintDataTime()
{
	printf("һ����%d��", DAYS_PER_YEAR* HOURS_PER_DAY* MINS_PER_HOUR* SECONDS_PER_MIN);
}