#include <QDebug>

#include "wtype.h"
#include "winteger.h"
#include "wobjectfactory.h"

#include "warray.h"

WArray::WArray()
    : WObject(WObject::Array)
{
}

int WArray::parse(const QByteArray &data, uint start)
{
	WType wtype;
	WInteger wint;

	int origStart = start;

	start += wtype.parse(data, start);
	m_dataType = wtype.getValue();

	qDebug() << "Data type:" << m_dataType;

	start += wint.parse(data, start);
	int numElements = wint.getValue();

	qDebug() << "Number of Elements:" << numElements;

	m_data.clear();
	for(int i = 0; i < numElements; i++) {
		WObjectPtr value = WObjectFactory::fromType(m_dataType);

		start += value->parse(data, start);

		m_data.append(value);
	}

	return start - origStart;
}
