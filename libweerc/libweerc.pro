TEMPLATE = lib

TARGET = weerc

QT += network
CONFIG += staticlib debug

QMAKE_CXXFLAGS += -std=c++0x -O0
QMAKE_LFLAGS += -std=c++0x -O0

HEADERS += ./src/connection.h
HEADERS += ./src/messageparser.h
HEADERS += ./src/protocolhandler.h
HEADERS += ./src/weechat/warray.h
HEADERS += ./src/weechat/wbuffer.h
HEADERS += ./src/weechat/wchar.h
HEADERS += ./src/weechat/whashtable.h
HEADERS += ./src/weechat/whdata.h
HEADERS += ./src/weechat/winfo.h
HEADERS += ./src/weechat/winteger.h
HEADERS += ./src/weechat/wlonginteger.h
HEADERS += ./src/weechat/wobjectfactory.h
HEADERS += ./src/weechat/wobject.h
HEADERS += ./src/weechat/wpointer.h
HEADERS += ./src/weechat/wrelaymessage.h
HEADERS += ./src/weechat/wrelaymessagefactory.h
HEADERS += ./src/weechat/winfomessage.h
HEADERS += ./src/weechat/whdatamessage.h
HEADERS += ./src/weechat/wstring.h
HEADERS += ./src/weechat/wtime.h
HEADERS += ./src/weechat/wtype.h

SOURCES += ./src/connection.cpp
SOURCES += ./src/messageparser.cpp
SOURCES += ./src/protocolhandler.cpp
SOURCES += ./src/weechat/warray.cpp
SOURCES += ./src/weechat/wbuffer.cpp
SOURCES += ./src/weechat/wchar.cpp
SOURCES += ./src/weechat/whashtable.cpp
SOURCES += ./src/weechat/whdata.cpp
SOURCES += ./src/weechat/winfo.cpp
SOURCES += ./src/weechat/winteger.cpp
SOURCES += ./src/weechat/wlonginteger.cpp
SOURCES += ./src/weechat/wobject.cpp
SOURCES += ./src/weechat/wobjectfactory.cpp
SOURCES += ./src/weechat/wpointer.cpp
SOURCES += ./src/weechat/wrelaymessage.cpp
SOURCES += ./src/weechat/wrelaymessagefactory.cpp
SOURCES += ./src/weechat/winfomessage.cpp
SOURCES += ./src/weechat/whdatamessage.cpp
SOURCES += ./src/weechat/wstring.cpp
SOURCES += ./src/weechat/wtime.cpp
SOURCES += ./src/weechat/wtype.cpp
