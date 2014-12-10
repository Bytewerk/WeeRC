#ifndef BUFFERLINESMODEL_H
#define BUFFERLINESMODEL_H

#include <QAbstractTableModel>

#include "../../libweerc/src/WeechatState/wstatemanager.h"

class BufferLinesModel : public QAbstractTableModel
{
	Q_OBJECT
	
	private:
		WStateManager *m_stateManager;
		WBufferInfoPtr m_bufferInfo;

	public:
		BufferLinesModel(WStateManager *stateManager, QObject *parent = 0);

		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		int rowCount(const QModelIndex &parent) const;
		int columnCount(const QModelIndex &parent) const;
		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

		void setAssociatedBuffer(WPointer::value_type bufPtr);

		WBufferInfoPtr getAssociatedBufferInfo(void) { return m_bufferInfo; };

	private slots:
		void bufferLinesUpdated(const WBufferInfoPtr &bufferInfo);
};

#endif // BUFFERLINESMODEL_H
