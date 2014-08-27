# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = WeeRC

CONFIG += sailfishapp

SOURCES += src/WeeRC.cpp \
    src/connection.cpp \
    src/relayanswer.cpp \
    src/weechat/wchar.cpp \
    src/weechat/wobject.cpp \
    src/weechat/winteger.cpp \
    src/weechat/wlonginteger.cpp \
    src/weechat/wstring.cpp \
    src/weechat/wbuffer.cpp \
    src/weechat/wpointer.cpp \
    src/weechat/wtime.cpp \
    src/weechat/whashtable.cpp \
    src/weechat/whdata.cpp \
    src/weechat/winfo.cpp \
    src/weechat/winfolist.cpp \
    src/weechat/warray.cpp \
    src/weechat/winfolistitem.cpp \
    src/weechat/winfolistitemelement.cpp \
    src/messageparser.cpp \
    src/weechat/wrelaymessage.cpp \
    src/weechat/wclientmessage.cpp

OTHER_FILES += qml/WeeRC.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/WeeRC.changes.in \
    rpm/WeeRC.spec \
    rpm/WeeRC.yaml \
    translations/*.ts \
    WeeRC.desktop

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/WeeRC-de.ts

HEADERS += \
    src/connection.h \
    src/relayanswer.h \
    src/weechat/wchar.h \
    src/weechat/wobject.h \
    src/weechat/winteger.h \
    src/weechat/wlonginteger.h \
    src/weechat/wstring.h \
    src/weechat/wbuffer.h \
    src/weechat/wpointer.h \
    src/weechat/wtime.h \
    src/weechat/whashtable.h \
    src/weechat/whdata.h \
    src/weechat/winfo.h \
    src/weechat/winfolist.h \
    src/weechat/warray.h \
    src/weechat/winfolistitem.h \
    src/weechat/winfolistitemelement.h \
    src/messageparser.h \
    src/weechat/wrelaymessage.h \
    src/weechat/wclientmessage.h

