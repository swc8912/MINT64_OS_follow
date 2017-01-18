#include "RTC.h"

// CMOS �޸𸮿��� RTC ��Ʈ�ѷ��� ������ ���� �ð��� ����
void kReadRTCTime(BYTE* pbHour, BYTE* pbMinute, BYTE* pbSecond)
{
	BYTE bData;

	// CMOS �޸� ��巹�� ��������(��Ʈ 0x70)�� �ð��� �����ϴ� �������� ����
	kOutPortByte(RTC_CMOSADDRESS, RTC_ADDRESS_HOUR);
	// CMOS ������  ��������(��Ʈ 0x71)���� �ð��� ����
	bData = kInPortByte(RTC_CMOSDATA);
	*pbHour = RTC_BCDTOBINARY(bData);

	// CMOS �޸� ��巹�� ��������(��Ʈ 0x70)�� ���� �����ϴ� �������� ����
	kOutPortByte(RTC_CMOSADDRESS, RTC_ADDRESS_MINUTE);
	// CMOS ������  ��������(��Ʈ 0x71)���� ���� ����
	bData = kInPortByte(RTC_CMOSDATA);
	*pbMinute = RTC_BCDTOBINARY(bData);

	// CMOS �޸� ��巹�� ��������(��Ʈ 0x70)�� ���� �����ϴ� �������� ����
	kOutPortByte(RTC_CMOSADDRESS, RTC_ADDRESS_SECOND);
	// CMOS ������  ��������(��Ʈ 0x71)���� ���� ����
	bData = kInPortByte(RTC_CMOSDATA);
	*pbSecond = RTC_BCDTOBINARY(bData);
}

// CMOS �޸𸮿��� RTC ��Ʈ�ѷ��� ������ ���� ���ڸ� ����
void kReadRTCDate(WORD* pwYear, BYTE* pbMonth, BYTE* pbDatOfMonth, BYTE* pbDayOfWeek)
{
	BYTE bData;

	// CMOS �޸� ��巹�� ��������(��Ʈ 0x70)�� ������ �����ϴ� �������� ����
	kOutPortByte(RTC_CMOSADDRESS, RTC_ADDRESS_YEAR);
	// CMOS ������  ��������(��Ʈ 0x71)���� ������ ����
	bData = kInPortByte(RTC_CMOSDATA);
	*pwYear = RTC_BCDTOBINARY(bData) + 2000;

	// CMOS �޸� ��巹�� ��������(��Ʈ 0x70)�� ���� �����ϴ� �������� ����
	kOutPortByte(RTC_CMOSADDRESS, RTC_ADDRESS_MONTH);
	// CMOS ������  ��������(��Ʈ 0x71)���� ���� ����
	bData = kInPortByte(RTC_CMOSDATA);
	*pbMonth = RTC_BCDTOBINARY(bData);

	// CMOS �޸� ��巹�� ��������(��Ʈ 0x70)�� ���� �����ϴ� �������� ����
	kOutPortByte(RTC_CMOSADDRESS, RTC_ADDRESS_DAYOFMONTH);
	// CMOS ������  ��������(��Ʈ 0x71)���� ���� ����
	bData = kInPortByte(RTC_CMOSDATA);
	*pbDatOfMonth = RTC_BCDTOBINARY(bData);

	// CMOS �޸� ��巹�� ��������(��Ʈ 0x70)�� ������ �����ϴ� �������� ����
	kOutPortByte(RTC_CMOSADDRESS, RTC_ADDRESS_DAYOFWEEK);
	// CMOS ������  ��������(��Ʈ 0x71)���� ������ ����
	bData = kInPortByte(RTC_CMOSDATA);
	*pbDayOfWeek = RTC_BCDTOBINARY(bData);
}

// ���� ���� �̿��ؼ� �ش� ������ ���ڿ��� ��ȯ
char* kConvertDayOfWeekToString(BYTE bDayOfWeek)
{
	static char* vpcDayOfWeekString[8] = { "Error", "Sunday", "Monday", "Tuesday",
			"Wednesday", "Thursday", "Friday", "Saturday" };

	// ���� ������ �Ѿ�� ������ ��ȯ
	if(bDayOfWeek >= 8)
	{
		return vpcDayOfWeekString[0];
	}

	// ������ ��ȯ
	return vpcDayOfWeekString[bDayOfWeek];
}
