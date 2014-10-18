#include <QDebug>

#include "../WeechatObjects/wstring.h"
#include "../WeechatObjects/winteger.h"

#include "wchatbuffer.h"

WChatBuffer::WChatBuffer()
{
}

WChatBuffer::WChatBuffer(const WChatBuffer &other)
{
	copyFrom(other);
}

WChatBuffer& WChatBuffer::operator = (const WChatBuffer &other)
{
	copyFrom(other);
	return *this;
}

void WChatBuffer::copyFrom(const WChatBuffer &other)
{
	this->pointer  = other.pointer;
	this->fullName = other.fullName;
	this->number   = other.number;
}

void WChatBuffer::fillFromHdataItem(const WHdata &hdata, const WHdata::HdataItem &item)
{
	pointer = dynamic_cast<const WPointer*>(item.ppath[0].get())->getValue();

	for(int j = 0; j < item.entries.size(); j++) {
		WObjectPtr obj = item.entries[j];
		QString key = hdata.getKeyTypes()[j].first;

		if(key == "number") {
			number = dynamic_cast<const WInteger*>(obj.get())->getValue();
		} else if(key == "full_name") {
			fullName = dynamic_cast<const WString*>(obj.get())->getValue();
		} else {
			qDebug() << "Unhandled key" << key;
		}
	}
}

void WChatBuffer::debugPrint(void)
{
	qDebug() << "WChatBuffer data:";
	qDebug() << "  pointer:  " << pointer;
	qDebug() << "  full_name:" << fullName;
	qDebug() << "  number:   " << number;
}
