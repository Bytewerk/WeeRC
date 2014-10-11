TEMPLATE = lib

TARGET = weerc

QT += network
CONFIG += staticlib debug

QMAKE_CXXFLAGS += -std=c++0x -O0
QMAKE_LFLAGS += -std=c++0x -O0

HEADERS += ./src/connection.h
HEADERS += ./src/messageparser.h
HEADERS += ./src/protocolhandler.h
HEADERS += ./src/WeechatObjects/wobjectfactory.h
HEADERS += ./src/WeechatObjects/winteger.h
HEADERS += ./src/WeechatObjects/wpointer.h
HEADERS += ./src/WeechatObjects/wstring.h
HEADERS += ./src/WeechatObjects/wobject.h
HEADERS += ./src/WeechatObjects/warray.h
HEADERS += ./src/WeechatObjects/wbuffer.h
HEADERS += ./src/WeechatObjects/wchar.h
HEADERS += ./src/WeechatObjects/whashtable.h
HEADERS += ./src/WeechatObjects/whdata.h
HEADERS += ./src/WeechatObjects/winfo.h
HEADERS += ./src/WeechatObjects/wlonginteger.h
HEADERS += ./src/WeechatObjects/wtime.h
HEADERS += ./src/WeechatObjects/wtype.h
HEADERS += ./src/WeechatMessages/wrelaymessagefactory.h
HEADERS += ./src/WeechatMessages/wrelaymessage.h
HEADERS += ./src/WeechatMessages/wbufferlistmessage.h
HEADERS += ./src/WeechatMessages/wobjectmessage.h
HEADERS += ./src/WeechatState/wstatemanager.h
HEADERS += ./src/WeechatState/wbufferstate.h

SOURCES += ./src/protocolhandler.cpp
SOURCES += ./src/connection.cpp
SOURCES += ./src/messageparser.cpp
SOURCES += ./src/WeechatObjects/wobject.cpp
SOURCES += ./src/WeechatObjects/wobjectfactory.cpp
SOURCES += ./src/WeechatObjects/warray.cpp
SOURCES += ./src/WeechatObjects/wbuffer.cpp
SOURCES += ./src/WeechatObjects/wchar.cpp
SOURCES += ./src/WeechatObjects/whashtable.cpp
SOURCES += ./src/WeechatObjects/whdata.cpp
SOURCES += ./src/WeechatObjects/winfo.cpp
SOURCES += ./src/WeechatObjects/winteger.cpp
SOURCES += ./src/WeechatObjects/wlonginteger.cpp
SOURCES += ./src/WeechatObjects/wpointer.cpp
SOURCES += ./src/WeechatObjects/wstring.cpp
SOURCES += ./src/WeechatObjects/wtime.cpp
SOURCES += ./src/WeechatObjects/wtype.cpp
SOURCES += ./src/WeechatMessages/wrelaymessage.cpp
SOURCES += ./src/WeechatMessages/wrelaymessagefactory.cpp
SOURCES += ./src/WeechatMessages/wbufferlistmessage.cpp
SOURCES += ./src/WeechatMessages/wobjectmessage.cpp
SOURCES += ./src/WeechatState/wstatemanager.cpp
SOURCES += ./src/WeechatState/wbufferstate.cpp
