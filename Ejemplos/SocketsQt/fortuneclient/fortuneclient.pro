QT += network widgets

HEADERS       = client.h
SOURCES       = client.cpp \
                main.cpp \
    client_extra.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneclient
INSTALLS += target
