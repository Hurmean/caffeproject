INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2  \
                /usr/local/caffe-master/include \
                /usr/local/caffe-master/build/src \
                /usr/local/lib \
                /usr/lib/x86_64-linux-gnu \
		/opt/intel/compilers_and_libraries_2016.2.181/linux/mkl/include
LIBS += -L/usr/local/lib  -L/usr/local/caffe-master/build/lib \
        -lopencv_highgui -lopencv_core -lopencv_imgproc \
        -lswscale -lboost_system -lboost_thread -lglog -lgomp -lpthread -lcaffe
