//
// author: jjuiddong
//  2015-04-04
//
// CSerial Ŭ������ ��� �޾�, ReadStringUntil() �Լ��� ������ Ŭ������.
// Ư�� ���� (���๮��) ������ ������ �о� �� ��, �������� �����ϴ� CSerial Ŭ������
// ������� ����, ���۸� ȿ�������� �����ϸ鼭, ���ϴ� ����� �����ϴ� ������ �Ѵ�.
//
// �����۷� �����Ǿ, ���� ���Ҵ�, ���簡 �Ͼ�� �ʰ� �ߴ�.
//
// �� Ŭ������ ����� ���, ReadData()�Լ� ���, ReadStringUntil() �Լ��� ��� �Ѵ�.
//
//
// 2015-08-25
// ���� �ð� �̻󵿾� ch���ڰ� ������ ������, ���۸� �����Ѵ�.
//
#pragma once
#include "Serial.h"


namespace common
{

	class CBufferedSerial : public CSerial
	{
	public:
		CBufferedSerial();
		virtual ~CBufferedSerial();

		//bool ReadStringUntil(const char ch, OUT string &out);
		bool ReadStringUntil(const char ch, OUT char *out, OUT int &outLen, const int maxSize);
		void SetMaxWaitTime(const int milliseconds);
		void ClearBuffer();


	protected:
		enum { MAX_BUFFERSIZE = 2048 };

		char m_ringBuffer[MAX_BUFFERSIZE];
		// ������ head ���� tail �� ����ȴ�. ���� ���� ������ tail ���� ����ȴ�.
		// headIndex == tailIndex ������ �����ϸ�, ���۰� ����ٴ� ���̴�.
		int m_headIndex = 0;  // ����� ������ ���۵Ǵ� index�� ����Ų��.
		int m_tailIndex = 0; // ������ ���� ������ index�� ����Ų��.
		int m_checkIndex = 0; // Ư�����ڸ� ã�� �����ϴ� index�� ����Ų��.
		int m_maxWaitTime; // default = 500
		int m_lastReturnTime; // m_maxWaitTime �ð��� �������� ���� ch�� ���� �ʴ´ٸ�, �����Ѵ�.
	};

}
