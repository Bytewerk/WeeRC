#ifndef WHDATA_H
#define WHDATA_H

#include "wobject.h"

#include <QPair>
#include <QList>
#include <QStringList>

class WHdata : public WObject
{
public:
	typedef QPair<QString, WObject::ObjectType> KeyTypePair;
	typedef QList<KeyTypePair> KeyTypeList;

	// data types for storing items: each item is composed of a number of entries
	// as defined by the "keys" string
	typedef QList<WObjectPtr> ItemEntryList;
	typedef QList<WObjectPtr> ItemPtrList;

	struct HdataItem {
		ItemPtrList   ppath;
		ItemEntryList entries;
	};

	typedef QList<HdataItem> ItemList;

private:
	KeyTypeList m_keyTypes;
	ItemList    m_items;

	QStringList m_hdataPath;

public:
	WHdata();

	virtual int parse(const QByteArray& data, uint start);

	const KeyTypeList& getKeyTypes(void) const { return m_keyTypes; }
	const ItemList& getItems(void) const { return m_items; }
	const QStringList& getHdataPath(void) const { return m_hdataPath; }

	virtual QString repr(void) const;
};

#endif // WHDATA_H
