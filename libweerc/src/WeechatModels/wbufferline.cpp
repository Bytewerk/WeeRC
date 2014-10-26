#include <QDebug>

#include "../WeechatObjects/wstring.h"
#include "../WeechatObjects/winteger.h"
#include "../WeechatObjects/wtime.h"
#include "../WeechatObjects/warray.h"
#include "../WeechatObjects/wchar.h"

#include "wbufferline.h"

WBufferLine::WBufferLine()
{
}

WBufferLine::WBufferLine(const WBufferLine &other)
{
	copyFrom(other);
}

WBufferLine& WBufferLine::operator = (const WBufferLine &other)
{
	copyFrom(other);
	return *this;
}

void WBufferLine::copyFrom(const WBufferLine &other)
{
	this->line_pointer   = other.line_pointer;
	this->buffer_pointer = other.buffer_pointer;
	this->date           = other.date;
	this->date_printed   = other.date_printed;
	this->displayed      = other.displayed;
	this->highlight      = other.highlight;
	this->tags_array     = other.tags_array;
	this->prefix         = other.prefix;
	this->message        = other.message;
}

void WBufferLine::fillFromHdataItem(const WHdata &hdata, const WHdata::HdataItem &item)
{
	line_pointer = dynamic_cast<const WPointer*>(item.ppath[0].get())->getValue();

	for(int j = 0; j < item.entries.size(); j++) {
		WObjectPtr obj = item.entries[j];
		QString key = hdata.getKeyTypes()[j].first;

		if(key == "buffer") {
			buffer_pointer = dynamic_cast<const WPointer*>(obj.get())->getValue();
		} else if(key == "date") {
			date = dynamic_cast<const WTime*>(obj.get())->getValue();
		} else if(key == "date_printed") {
			date_printed = dynamic_cast<const WTime*>(obj.get())->getValue();
		} else if(key == "displayed") {
			displayed = dynamic_cast<const WChar*>(obj.get())->getValue().unicode() != 0;
		} else if(key == "highlight") {
			highlight = dynamic_cast<const WChar*>(obj.get())->getValue().unicode() != 0;
		} else if(key == "prefix") {
			prefix = dynamic_cast<const WString*>(obj.get())->getValue();
		} else if(key == "message") {
			message = dynamic_cast<const WString*>(obj.get())->getValue();
		} else if(key == "tags_array") {
			const WArray::ObjectList &data = dynamic_cast<const WArray*>(obj.get())->getData();

			tags_array.clear();
			for(const WObjectPtr entry: data) {
				QString tag = dynamic_cast<const WString*>(entry.get())->getValue();
				tags_array.append(tag);
			}
		} else {
			qDebug() << "Unhandled key" << key;
		}
	}
}

void WBufferLine::debugPrint(void)
{
	qDebug() << "WBufferLine data:";
	qDebug() << "  line_pointer:  " << line_pointer;
	qDebug() << "  buffer_pointer:" << buffer_pointer;
	qDebug() << "  date:          " << date;
	qDebug() << "  date_printed:  " << date_printed;
	qDebug() << "  displayed:     " << displayed;
	qDebug() << "  highlight:     " << highlight;
	qDebug() << "  tags_array:    " << tags_array;
	qDebug() << "  prefix:        " << prefix;
	qDebug() << "  message:       " << message;
}
