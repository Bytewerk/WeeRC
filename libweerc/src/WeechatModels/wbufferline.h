#ifndef WBUFFERLINE_H
#define WBUFFERLINE_H

#include "../WeechatObjects/wpointer.h"
#include "../WeechatObjects/whdata.h"

#include <memory>

/*
 * \brief A class containing information about a WBufferLine.
 *
 * This class contains information about a buffer line, such as:
 *   - line pointer
 *   - buffer pointer
 *   - date
 *   - date printed
 *   - displayed
 *   - highlight
 *   - (tags array)
 *   - prefix
 *   - message
 *
 * All attributes are public, as this class is supposed to be used like a struct.
 */
class WBufferLine
{
	public:
		typedef QList<QString> TagList;

		WPointer::value_type line_pointer;
		WPointer::value_type buffer_pointer;
		qint64               date;
		qint64               date_printed;
		bool                 displayed;
		bool                 highlight;
		TagList              tags_array;
		QString              prefix;
		QString              message;


		explicit WBufferLine();
		explicit WBufferLine(const WBufferLine &other);

		void fillFromHdataItem(const WHdata &hdata, const WHdata::HdataItem &item);
		void debugPrint(void);


		void copyFrom(const WBufferLine &other);
		WBufferLine& operator = (const WBufferLine &other);
};

typedef std::shared_ptr<WBufferLine> WBufferLinePtr;

#endif // WBUFFERLINE_H
