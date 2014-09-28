#include <QDebug>

#include "wtype.h"
#include "winteger.h"

#include "wobjectfactory.h"

#include "whashtable.h"

WHashTable::WHashTable()
    : WObject(WObject::HashTable)
{
}

int WHashTable::parse(const QByteArray &data, uint start)
{
	WType wtype;
	WInteger wint;

	uint origStart = start;

	// parse key type string
	start += wtype.parse(data, start);
	m_keysType = wtype.getValue();

	// parse value type string
	start += wtype.parse(data, start);
	m_valuesType = wtype.getValue();

	// parse number of elements
	start += wint.parse(data, start);
	int numElements = wint.getValue();

	m_hashtable.clear();
	for(int i = 0; i < numElements; i++) {
		WObjectPtr key   = WObjectFactory::fromType(m_keysType);
		WObjectPtr value = WObjectFactory::fromType(m_valuesType);

		start += key->parse(data, start);
		start += value->parse(data, start);

		qDebug() << key->repr();
		qDebug() << value->repr();

		m_hashtable.insert(key, value);
	}

	return start - origStart;
}

QString WHashTable::repr(void)
{
	QString dataStr;

	bool first = true;
	for(WObjectPtr key: m_hashtable.keys()) {
		WObjectPtr value = m_hashtable.value(key);

		dataStr += (first ? "(" : ", (") + key->repr() + " -> " + value->repr() + ")";
	}

	return "[" + WObject::typeToStr(m_objectType) + "(" + WObject::typeToStr(m_keysType) + ", " + WObject::typeToStr(m_valuesType) + "): "
		+ dataStr + "]";
}
