CC=gcc -O4 -std=gnu99
LINKOPTIONS= -lm -g

#CC=icc -O3 -std=c99
#LINKOPTIONS=-ipp -DIPP -DCILK -lm -g

CFLAGS = -c -Wall

INCLUDES = -I ./includes/
TARGET_DIR = bin
SRC_DIR = src
TEST_DIR = test

SRCOBJS = bin/approx_frequent.o\
	bin/assign_I4.o \
	bin/assign_I1.o \
	bin/mmap.o \
	bin/qsort_asc_I4.o \
	bin/sorted_array_to_id_freq.o \
	bin/update_counter.o


all: testApproxFrequent

$(TARGET_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $< $(LINKOPTIONS) -o $@

$(TARGET_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC)  $(CFLAGS) $(INCLUDES) $< $(LINKOPTIONS) -o $@

testApproxFrequent: $(SRCOBJS) bin/testApproxFrequent.o
	$(CC)  $(SRCOBJS) bin/testApproxFrequent.o $(LINKOPTIONS) -o testApproxFrequent.exe




