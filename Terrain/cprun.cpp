//20190822 ���Down_threshold������ʵ�ֽضϽ�λ//
//ת����Ϣ���� ����ѡ��������ϵ���ֱ��ʣ��Ƿ�λ��ǰ��������ִ��ת�����������һ������ִ�н�λ����//
#include "cprun.h"
#include"omp.h"
#include"qmessagebox.h"
#include"QCoreApplication"
#include"QProcess"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

CPRun::CPRun(QWidget *parent) : QThread(parent)
{
	cmd.clear();
}
void  CPRun::setData(QString mycmd)
{
	cmd = mycmd;
}
void CPRun::run()
{
	if (!cmd.isEmpty())
	{
		QProcess process;
		process.execute(cmd);
		//WinExec(cmd.toLocal8Bit().data(), SW_HIDE);
		//system(cmd.toLocal8Bit().data());
		currentProgress();
		this->quit();
	}
}
void CPRun::work()
{

}
