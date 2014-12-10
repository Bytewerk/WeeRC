#include <QDebug>

#include "bufferlistmodel.h"


BufferListModel::BufferListModel(WStateManager *stateManager, QObject *parent)
	: QAbstractListModel(parent), m_stateManager(stateManager)
{
	connect(m_stateManager, SIGNAL(bufferListUpdated(const WBufferState::BufferInfoMap&)),
			this, SLOT(bufferListUpdated(const WBufferState::BufferInfoMap&)));
}

QVariant BufferListModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid()) {
		return QVariant();
	}

	if(role == Qt::DisplayRole) {
		WBufferState::BufferInfoMap::const_iterator iter =
			m_stateManager->getBufferState()->getBufferInfoMap().begin();

		QString bufferName = (iter + index.row())->get()->getBufferPointer()->fullName;

		qDebug() << "Entry" << index.row() << "resolves to" << bufferName;

		return bufferName;
	} else {
		return QVariant();
	}
}

int BufferListModel::rowCount(const QModelIndex &parent) const
{
	int count = m_stateManager->getBufferState()->getBufferInfoMap().size();
	qDebug() << "Model has" << count << "entries";
	return count;
}

QVariant BufferListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role == Qt::DisplayRole) {
		return QString("Buffer Name");
	} else {
		return QVariant();
	}
}

void BufferListModel::bufferListUpdated(const WBufferState::BufferInfoMap &bufferInfoMap)
{
	QModelIndex topLeft = createIndex(0, 0);
	QModelIndex bottomRight = createIndex(bufferInfoMap.size(), 0);
	emit dataChanged(topLeft, bottomRight);
}

WBufferInfoPtr BufferListModel::getBufferAtIndex(const QModelIndex &index) const
{
		WBufferState::BufferInfoMap::const_iterator iter =
			m_stateManager->getBufferState()->getBufferInfoMap().begin();

		return *(iter + index.row());
}
