CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=socket
DEPENDENCY2=TCPServerSocket
DEPENDENCY3=TCPClientSocket
DEPENDENCY4=messengerProtocol

CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

SRC_DIR = ../src/
INC_DIR = ../inc/

LDFLAGS+= -lws2_32

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o \
				${SRC_DIR}${DEPENDENCY3}.o ${SRC_DIR}${DEPENDENCY4}.o

OBJSD = ${SRC_DIR}${DEPENDENCY1}.d ${SRC_DIR}${DEPENDENCY2}.d \
		 ${SRC_DIR}${DEPENDENCY3}.d ${SRC_DIR}${DEPENDENCY4}.d

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) $(LDFLAGS)

check: $(TARGET)
	./a.exe

vala: all
	${VALG} ./$(TARGET)

utest.o: utest.cpp

clean:
	@$(RM) $(TARGET) $(OBJS) $(OBJSD)

.PHONY: all check clean

DEPENDS = $(OBJS:%.o=%.d)

-include ${DEPENDS}