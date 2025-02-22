#include "circularbuffer.hpp"
#include <gtest/gtest.h>

TEST(CircularBufferTest, Initialization1) {
    CircularBuffer<int> buffer(5);
    EXPECT_EQ(buffer.size(), 0);
    EXPECT_EQ(buffer.capacity(), 5);
}

TEST(CircularBufferTest, Initialization2) {
    CircularBuffer<int> buffer(5, 0);
    EXPECT_EQ(buffer.size(), 5);
    EXPECT_EQ(buffer.capacity(), 5);
    EXPECT_EQ(buffer.front(), 0);
    EXPECT_EQ(buffer.back(), 0);
    for (size_t i = 0; i < 5; i++) {
        EXPECT_EQ(buffer[i], 0);
    }
}

TEST(CircularBufferTest, Initialization3) {
    CircularBuffer<int> buffer1(5, 1);
    CircularBuffer<int> buffer2(buffer1);
    EXPECT_EQ(buffer2.size(), 5);
    EXPECT_EQ(buffer2.capacity(), 5);
    EXPECT_EQ(buffer2.front(), 1);
    EXPECT_EQ(buffer2.back(), 1);
    for (size_t i = 0; i < 5; i++) {
        EXPECT_EQ(buffer2[i], 1);
    }
}

TEST(CircularBufferTest, Initialization4) {
    CircularBuffer<int> buffer;
    EXPECT_EQ(buffer.size(), 0);
    EXPECT_EQ(buffer.capacity(), 0);
}

TEST(CircularBufferTest, PushBack) {
    CircularBuffer<int> buffer(3);
    buffer.pushBack(1);
    buffer.pushBack(2);
    buffer.pushBack(3);
    
    std::cout << "Buffer1 info: " << std::endl;

    for (size_t i = 0; i < buffer.size(); i++) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;
    EXPECT_EQ(buffer.size(), 3);
    EXPECT_EQ(buffer.front(), 1);
    EXPECT_EQ(buffer.back(), 3);
}

TEST(CircularBufferTest, PopFront) {
    CircularBuffer<int> buffer(3);
    buffer.pushBack(1);
    buffer.pushBack(2);
    buffer.pushBack(3);
    buffer.popFront();
    EXPECT_EQ(buffer.size(), 2);
    EXPECT_EQ(buffer.front(), 2);
}

TEST(CircularBufferTest, WrapAround) {
    CircularBuffer<int> buffer(3);
    buffer.pushBack(1);
    buffer.pushBack(2);
    buffer.pushBack(3);
    buffer.popFront();
    buffer.pushBack(4);

    EXPECT_EQ(buffer.size(), 3);
    EXPECT_EQ(buffer.front(), 2);
    EXPECT_EQ(buffer.back(), 4);
}

TEST(CircularBufferTest, IsEmpty) {
    CircularBuffer<int> buffer(3);
    EXPECT_TRUE(buffer.empty());
    buffer.pushBack(1);
    EXPECT_FALSE(buffer.empty());
}

TEST(CircularBufferTest, IsFull) {
    CircularBuffer<int> buffer(3);
    buffer.pushBack(1);
    buffer.pushBack(2);
    buffer.pushBack(3);
    EXPECT_TRUE(buffer.full());
    buffer.popFront();
    EXPECT_FALSE(buffer.full());
}

TEST(CircularBufferTest, Clear) {
    CircularBuffer<int> buffer(3);
    buffer.pushBack(1);
    buffer.pushBack(2);
    buffer.pushBack(3);
    buffer.clear();
    EXPECT_EQ(buffer.size(), 0);
    EXPECT_TRUE(buffer.empty());
}

TEST(CircularBufferTest, ExceptionOnEmptyPop) {
    CircularBuffer<int> buffer(3);
    EXPECT_THROW(buffer.popFront(), CircularBufferException);
}

TEST(CircularBufferTest, ExceptionOnEmptyFront) {
    CircularBuffer<int> buffer(3);
    EXPECT_THROW(buffer.front(), CircularBufferException);
}

TEST(CircularBufferTest, ExceptionOnEmptyBack) {
    CircularBuffer<int> buffer(3);
    EXPECT_THROW(buffer.back(), CircularBufferException);
}

TEST(CircularBufferTest, PushFront) {
    CircularBuffer<int> buffer(3);
    buffer.pushFront(1);
    buffer.pushFront(2);
    buffer.pushFront(3);
    EXPECT_EQ(buffer[0], 3);
    EXPECT_EQ(buffer[1], 2);
    EXPECT_EQ(buffer[2], 1);
}

TEST(CircularBufferTest, PopBack) {
    CircularBuffer<int> buffer(3);
    buffer.pushBack(1);
    buffer.pushBack(2);
    buffer.pushBack(3);
    buffer.popBack();
    EXPECT_EQ(buffer.size(), 2);
    EXPECT_EQ(buffer[0], 1);
    EXPECT_EQ(buffer[1], 2);
}

TEST(CircularBufferTest, Insert) {
    CircularBuffer<int> buffer(3);
    buffer.pushBack(1);
    buffer.pushBack(3);
    buffer.insert(1, 2);
    EXPECT_EQ(buffer[0], 1);
    EXPECT_EQ(buffer[1], 2);
    EXPECT_EQ(buffer[2], 3);
}

TEST(CircularBufferTest, Erase) {
    CircularBuffer<int> buffer(3);
    buffer.pushBack(1);
    buffer.pushBack(2);
    buffer.pushBack(3);
    buffer.erase(1, 2);
    EXPECT_EQ(buffer.size(), 2);
    EXPECT_EQ(buffer[0], 1);
    EXPECT_EQ(buffer[1], 3);
}

TEST(CircularBufferTest, ExceptionOnEmptyPopBack) {
    CircularBuffer<int> buffer(3);
    EXPECT_THROW(buffer.popBack(), CircularBufferException);
}

TEST(CircularBufferTest, ExceptionOnEmptyPopFront) {
    CircularBuffer<int> buffer(3);
    EXPECT_THROW(buffer.popFront(), CircularBufferException);
}

TEST(CircularBufferTest, Swap) {
    CircularBuffer<int> buffer1(3);
    CircularBuffer<int> buffer2(3);
    buffer1.pushBack(1);
    buffer1.pushBack(2);
    buffer1.pushBack(3);
    buffer2.pushBack(4);
    buffer2.pushBack(5);
    buffer2.pushBack(6);
    buffer1.swap(buffer2);
    EXPECT_EQ(buffer1.size(), 3);
    EXPECT_EQ(buffer2.size(), 3);
    EXPECT_EQ(buffer1[0], 4);
    EXPECT_EQ(buffer1[1], 5);
    EXPECT_EQ(buffer1[2], 6);
    EXPECT_EQ(buffer2[0], 1);
    EXPECT_EQ(buffer2[1], 2);
    EXPECT_EQ(buffer2[2], 3);
}

TEST(CircularBufferTest, EqualityOperator) {
    CircularBuffer<int> buffer1(3);
    CircularBuffer<int> buffer2(3);
    buffer1.pushBack(1);
    buffer1.pushBack(2);
    buffer1.pushBack(3);
    buffer2.pushBack(1);
    buffer2.pushBack(2);
    buffer2.pushBack(3);
    EXPECT_TRUE(buffer1 == buffer2);
}

TEST(CircularBufferTest, InequalityOperator) {
    CircularBuffer<int> buffer1(3);
    CircularBuffer<int> buffer2(3);
    buffer1.pushBack(1);
    buffer1.pushBack(2);
    buffer1.pushBack(3);
    buffer2.pushBack(4);
    buffer2.pushBack(5);
    buffer2.pushBack(6);
    EXPECT_TRUE(buffer1 != buffer2);
}