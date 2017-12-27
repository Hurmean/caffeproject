QT += core
QT -= gui

CONFIG += c++11

TARGET = caffeproject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    MTCNN.cpp

HEADERS += \
    MTCNN.h

#opencv
INCLUDEPATH +=  /usr/local/include  \
                /usr/local/include/opencv \
                /usr/local/include/opencv2
LIBS += -L /usr/local/lib/libopencv_*.so

# other dependencies  -lcbla  -llmdb -lleveldb -lstdc++ -lcudnn
LIBS += -lglog -lgflags -lprotobuf -lboost_system -lboost_thread


## cuda
#INCLUDEPATH += /usr/local/cuda/include
#LIBS += -L/usr/local/cuda/lib64
#LIBS += -lcudart -lcublas -lcurand

## caffe
INCLUDEPATH += /home/hfx/caffe/include \
               /home/hfx/caffe/build/src
#LIBS += -L /home/hfx/caffe/build/lib/lib_*.so
#LIBS += -lcaffe
LIBS += -L/home/hfx/caffe/build/lib -lcaffe
