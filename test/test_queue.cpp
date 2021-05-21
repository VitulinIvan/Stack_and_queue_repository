#include "Queue.h"

#include <gtest.h>
#include <sstream>

TEST(TQueue, create_queue)
{
	TQueue<int> Q(3);
	EXPECT_NO_THROW();
}

TEST(TQueue, throw_create_negative_size_queue)
{
	
	EXPECT_ANY_THROW(TQueue<int> Q(-3));
}

TEST(TQueue, pushing_any_elements)
{
	TQueue<int> Q(4);
	Q.Push(1);
	Q.Push(2);
	EXPECT_EQ(1, Q.Get());
}

TEST(TQueue, pop_any_elements)
{
	TQueue<int> Q(4);
	Q.Push(1);
	Q.Push(2);
	Q.Push(3);
	Q.Push(4);
	Q.Pop();
	Q.Pop();
	Q.Push(5);
	Q.Pop();
	EXPECT_EQ(4, Q.Get());
}

TEST(TQueue, find_max_element)
{
	TQueue<int> Q(4);
	Q.Push(1);
	Q.Push(5);
	Q.Push(-3);
	EXPECT_EQ(5, Q.GetMaxElement());
}

TEST(TQueue, find_min_element)
{
	TQueue<int> Q(4);
	Q.Push(1);
	Q.Push(5);
	Q.Push(-3);
	EXPECT_EQ(-3, Q.GetMinElement());
}

TEST(TQueue, write_queue_to_file)
{
	const int size = 9;
	TQueue<int> Q(size);
	for (int i = 0; i < size / 2; i++)
		Q.Push(i);
	Q.WriteToFile("QueueOI.txt");
	string ExpString = "0123";
	string QueueString = "";
	ifstream fin("QueueOI.txt");
	fin >> QueueString;
	fin.close();
	EXPECT_EQ(ExpString, QueueString);
}