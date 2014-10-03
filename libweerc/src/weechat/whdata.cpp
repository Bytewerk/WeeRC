#include <QDebug>

#include "wbuffer.h"
#include "wstring.h"
#include "winteger.h"
#include "wpointer.h"
#include "wobjectfactory.h"

#include "whdata.h"

WHdata::WHdata()
	: WObject(WObject::Hdata)
{
}

int WHdata::parse(const QByteArray &data, uint start)
{
	WBuffer wbuf;
	WString wstr;
	WInteger wint;

	int origStart = start;

	// h-path
	start += wbuf.parse(data, start);
	m_hdataPath = QString::fromAscii(wbuf.getValue()).split("/");

	// keys
	start += wstr.parse(data, start);
	QString keyString = wstr.getValue();

	// parse the key->type mappings
	m_keyTypes.clear();

	for(const QString &keyTypeStr: keyString.split(",")) {
		QStringList keyTypeParts = keyTypeStr.split(":");

		QString key = keyTypeParts[0];
		WObject::ObjectType type = WObject::typeFromStr(keyTypeParts[1]);

		m_keyTypes.append(KeyTypePair(key, type));
	}

	// read number of elements
	start += wint.parse(data, start);
	int numElements = wint.getValue();

	// parse the items
	m_items.clear();
	for(int i = 0; i < numElements; i++) {
		HdataItem item;

		// p-path
		for(int ppathIdx = 0; ppathIdx < m_hdataPath.size(); ppathIdx++) {
			WObjectPtr ptr(new WPointer());

			start += ptr->parse(data, start);
			item.ppath.append(ptr);
		}

		// item data
		for(const KeyTypePair &ktp: m_keyTypes) {
			WObject::ObjectType type = ktp.second;

			WObjectPtr object = WObjectFactory::fromType(type);
			start += object->parse(data, start);

			item.entries.append(object);
		}

		m_items.append(item);
	}

	return start - origStart;
}

QString WHdata::repr(void) const
{
	QString description;

	QStringList strlist;

	strlist.clear();
	for(const KeyTypePair &ktp: m_keyTypes) {
		QString key = ktp.first;
		WObject::ObjectType type = ktp.second;

		strlist.append(QString("%1: %2").arg(key).arg(WObject::typeToStr(type)));
	}

	description += "keys: {" + strlist.join(", ") + "}\n";
	description += "h-path: [" + m_hdataPath.join(", ") + "]\n";

	for(int i = 0; i < m_items.size(); i++) {
		const HdataItem &item = m_items[i];

		description += QString("Item %1:\n").arg(i);

		strlist.clear();
		for(WObjectPtr ptr: item.ppath) {
			strlist.append(ptr->repr());
		}

		description += "  p-path: [" + strlist.join(", ") + "]\n";

		for(int j = 0; j < item.entries.size(); j++) {
			WObjectPtr obj = item.entries[j];
			QString key = m_keyTypes[j].first;

			description += "  " + key + ": " + obj->repr() + "\n";
		}
	}

	return "[" + WObject::typeToStr(m_objectType) + ":\n"
		+ description + "]";
}
