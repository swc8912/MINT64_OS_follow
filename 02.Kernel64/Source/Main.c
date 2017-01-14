#include "Types.h"
#include "Keyboard.h"

void kPrintString(int iX, int iY, const char* pcString);

void Main(void)
{
	char vcTemp[2] = { 0, };
	BYTE bFlags;
	BYTE bTemp;
	int i = 0;

	kPrintString(0, 10, "Switch To IA-32e Mode Success!!");
	kPrintString(0, 11, "IA-32e C Language Kernel Start..............[Pass]");
	kPrintString(0, 12, "Keyboard Activate...........................[    ]");

	// Ű���带 Ȱ��ȭ
	if(kActivateKeyboard() == TRUE)
	{
		kPrintString(45, 12, "Pass");
		kChangeKeyboardLED(FALSE, FALSE, FALSE);
	}
	else
	{
		kPrintString(45, 12, "Fail");
		while(1);
	}

	while(1)
	{
		// ��� ����(��Ʈ 0x60)�� �� ������ ��ĵ �ڵ带 ���� �� ����
		if(kIsOutputBufferFull() == TRUE)
		{
			// ��� ����(��Ʈ 0x60)���� ��ĵ �ڵ带 �о ����
			bTemp = kGetKeyboardScanCode();

			// ��ĵ �ڵ带 ASCII �ڵ�� ��ȯ�ϴ� �Լ��� ȣ���Ͽ� ASCII �ڵ�� ���� �Ǵ� ������ ������ ��ȯ
			if(kConvertScanCodeToASCIICode(bTemp, &(vcTemp[0]), &bFlags) == TRUE)
			{
				// Ű�� ���������� Ű�� ASCII �ڵ�  ���� ȭ�鿡  ���
				if(bFlags & KEY_FLAGS_DOWN)
				{
					kPrintString(i++, 13, vcTemp);
				}
			}
		}
	}
}

void kPrintString(int iX, int iY, const char* pcString)
{
	CHARACTER* pstScreen = (CHARACTER*) 0xB8000;
	int i;

	pstScreen += (iY * 80) + iX;
	for(i = 0; pcString[i] != 0; i++)
	{
		pstScreen[i].bCharactor = pcString[i];
	}
}