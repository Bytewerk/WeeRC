#ifndef WCHATBUFFER_H
#define WCHATBUFFER_H

#include "../WeechatObjects/wpointer.h"
#include "../WeechatObjects/whdata.h"

#include <memory>

/*
 * \brief A class containing information about a WChatBuffer.
 *
 * This class contains information about a buffer, such as:
 *   - pointer
 *   - number
 *   - full name
 *
 * All attributes are public, as this class is supposed to be used like a struct.
 */
class WChatBuffer
{
	public:
		WPointer::value_type pointer;
		QString              fullName;
		int                  number;


		explicit WChatBuffer();
		explicit WChatBuffer(const WChatBuffer &other);

		void fillFromHdataItem(const WHdata &hdata, const WHdata::HdataItem &item);
		void debugPrint(void);


		void copyFrom(const WChatBuffer &other);
		WChatBuffer& operator = (const WChatBuffer &other);
};

typedef std::shared_ptr<WChatBuffer> WChatBufferPtr;

#endif // WCHATBUFFER_H
