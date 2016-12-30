#include "biz.h"
#include "log.h"

int main()
{
	Log log;
	Biz biz;
	
	QObject::connect(&biz,SIGNAL(siglog()),&log,SLOT(log()));

	biz.biz();
}
