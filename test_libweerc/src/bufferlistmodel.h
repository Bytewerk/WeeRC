#ifndef BUFFERLISTMODEL_H
#define BUFFERLISTMODEL_H

#include <QAbstractListModel>

#include "../../libweerc/src/WeechatState/wstatemanager.h"

class BufferListModel : public QAbstractListModel
{
	Q_OBJECT
	
	private:
		WStateManager *m_stateManager;

	public:
		BufferListModel(WStateManager *stateManager, QObject *parent = 0);

		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		int rowCount(const QModelIndex &parent) const;
		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

		WBufferInfoPtr getBufferAtIndex(const QModelIndex &index) const;

	private slots:
		void bufferListUpdated(const WBufferState::BufferInfoMap &bufferInfoMap);
};

#endif // BUFFERLISTMODEL_H
