CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=IEncryptor
DEPENDENCY2=encryptionFactory
DEPENDENCY3=messenger
DEPENDENCY4=senderFactory
DEPENDENCY5=messengerFactory
DEPENDENCY6=sourceFactory
DEPENDENCY7=IStream
DEPENDENCY8=configuration
DEPENDENCY9=messengerProtocol
DEPENDENCY10=Socket
DEPENDENCY11=TCPClientSocket
DEPENDENCY12=TCPSocketExceptions
DEPENDENCY13=ISender

CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

LDFLAGS+= -pthread

SRC_DIR = ../../src/
INC_DIR = ../../inc/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o ${SRC_DIR}${DEPENDENCY3}.o \
				${SRC_DIR}${DEPENDENCY4}.o ${SRC_DIR}${DEPENDENCY5}.o ${SRC_DIR}${DEPENDENCY6}.o ${SRC_DIR}${DEPENDENCY7}.o \
				${SRC_DIR}${DEPENDENCY8}.o ${SRC_DIR}${DEPENDENCY9}.o ${SRC_DIR}${DEPENDENCY10}.o ${SRC_DIR}${DEPENDENCY11}.o \
				${SRC_DIR}${DEPENDENCY12}.o ${SRC_DIR}${DEPENDENCY13}.o

OBJSD = ${SRC_DIR}${DEPENDENCY1}.d ${SRC_DIR}${DEPENDENCY2}.d ${SRC_DIR}${DEPENDENCY3}.d \
		${SRC_DIR}${DEPENDENCY4}.d ${SRC_DIR}${DEPENDENCY5}.d ${SRC_DIR}${DEPENDENCY6}.d \
		${SRC_DIR}${DEPENDENCY7}.d ${SRC_DIR}${DEPENDENCY8}.d ${SRC_DIR}${DEPENDENCY9}.d

all: $(TARGET)

$(TARGET): $(OBJS)

check: CPPFLAGS += -DTHE_TEST
check: $(TARGET)
	./$(TARGET) -v

run: $(TARGET)
	./$(TARGET) stdin stdout upper

vala: all
	${VALG} ./$(TARGET)

utest.o: utest.cpp

clean:
	@$(RM) $(TARGET) $(OBJS) $(OBJSD)

.PHONY: all check clean

DEPENDS = $(OBJS:%.o=%.d)

-include ${DEPENDS}