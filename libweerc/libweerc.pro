TEMPLATE = lib

TARGET = weerc

QT += network
CONFIG += staticlib

HEADERS = ./src/connection.h ./src/weechat/wtime.h ./src/weechat/winfolistitemelement.h ./src/weechat/wobject.h ./src/weechat/wstring.h ./src/weechat/winfolistitem.h ./src/weechat/whashtable.h ./src/weechat/wlonginteger.h ./src/weechat/wpointer.h ./src/weechat/whdata.h ./src/weechat/wbuffer.h ./src/weechat/wclientmessage.h ./src/weechat/warray.h ./src/weechat/wchar.h ./src/weechat/winteger.h ./src/weechat/winfolist.h ./src/weechat/winfo.h ./src/weechat/wrelaymessage.h ./src/relayanswer.h ./src/messageparser.h
SOURCES = ./src/weechat/whdata.cpp ./src/weechat/winfolistitemelement.cpp ./src/weechat/wstring.cpp ./src/weechat/wobject.cpp ./src/weechat/wtime.cpp ./src/weechat/winfo.cpp ./src/weechat/warray.cpp ./src/weechat/wchar.cpp ./src/weechat/whashtable.cpp ./src/weechat/wrelaymessage.cpp ./src/weechat/wclientmessage.cpp ./src/weechat/wpointer.cpp ./src/weechat/wlonginteger.cpp ./src/weechat/wbuffer.cpp ./src/weechat/winfolistitem.cpp ./src/weechat/winteger.cpp ./src/weechat/winfolist.cpp ./src/connection.cpp ./src/relayanswer.cpp ./src/messageparser.cpp
