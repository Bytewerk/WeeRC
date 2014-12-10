#include <QDebug>

#include "bufferlinesmodel.h"


BufferLinesModel::BufferLinesModel(WStateManager *stateManager, QObject *parent)
	: QAbstractTableModel(parent), m_stateManager(stateManager)
{
	connect(m_stateManager, SIGNAL(bufferLinesUpdated(const WBufferInfoPtr&)),
	        this, SLOT(bufferLinesUpdated(const WBufferInfoPtr&)));
}

QVariant BufferLinesModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid()) {
		return QVariant();
	}

	qDebug() << "BufferLinesModel returning data for coords" << index.row() << index.column();

	if(!m_bufferInfo) {
		return QString("Row %1, Col %2").arg(index.row()).arg(index.column());
	}

	if(role == Qt::DisplayRole) {
		WPointer::value_type linePtr = m_bufferInfo->getLineOrder()[ index.row() ];

		const WBufferLinePtr line = m_bufferInfo->getLine(linePtr);

		switch(index.column()) {
			case 0:  return QString("Time"); break;
			case 1:  return line->prefix; break;
			case 2:  return line->message; break;
			default: return QVariant();
		}
	} else {
		return QVariant();
	}
}

int BufferLinesModel::rowCount(const QModelIndex &parent) const
{
	if(parent.isValid()) {
		return 0;
	}

	if(!m_bufferInfo) {
		qDebug() << "BufferLinesModel not initialized yet.";
		return 3;
	}

	int count = m_bufferInfo->getLineOrder().size();
	qDebug() << "BufferLinesModel has" << count << "rows";
	return count;
}

int BufferLinesModel::columnCount(const QModelIndex &parent) const
{
	qDebug() << "BufferLinesModel has" << 3 << "columns";
	return 3;
}

QVariant BufferLinesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role == Qt::DisplayRole) {
		if(orientation == Qt::Horizontal) {
			switch(section) {
				case 0:  return QString("Time"); break;
				case 1:  return QString("Tag"); break;
				case 2:  return QString("Message"); break;
				default: return QVariant();
			}
		}
	}

	return QVariant();
}

void BufferLinesModel::setAssociatedBuffer(WPointer::value_type bufPtr)
{
	m_bufferInfo = m_stateManager->getBufferState()->getBufferInfo(bufPtr);
	qDebug() << "BufferLinesModel is now associated with" << m_bufferInfo->getBufferPointer()->fullName;

	emit layoutChanged();
}

void BufferLinesModel::bufferLinesUpdated(const WBufferInfoPtr &bufferInfo)
{
	// only react to the currently associated buffer
	if(bufferInfo->getBufferPointer()->pointer == m_bufferInfo->getBufferPointer()->pointer) {
		emit layoutChanged();
	}
}

