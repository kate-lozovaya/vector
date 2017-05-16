#include <vector.hpp>
#include <catch.hpp>

SCENARIO("default constructor") 
{
	vector_t vector;
	REQUIRE(vector.size() == 0);
	REQUIRE(vector.capacity() == 0);
}

SCENARIO("constructor with params") 
{
	vector_t vector(1);
	REQUIRE(vector.size() == 1);
	REQUIRE(vector.capacity() == 1);
	REQUIRE(vector[0] == 0);
}

SCENARIO("copy constructor") 
{
	vector_t vector1(1);
	vector_t vector2(vector1);
	REQUIRE(vector1.size() == vector2.size());
	REQUIRE(vector1.capacity() == vector2.capacity());
	REQUIRE(vector1[0] == vector2[0]);
}

SCENARIO("=") 
{
	vector_t vector1(1);
	vector_t vector2 = vector1;
	REQUIRE(vector1.size() == vector2.size());
	REQUIRE(vector1.capacity() == vector2.capacity());
	REQUIRE(vector1[0] == vector2[0]);
}

SCENARIO("push")
{
	vector_t vector(1);
	vector.push_back(2);
	vector.push_back(3);
	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 4);
	REQUIRE(vector[0] == 0);
	REQUIRE(vector[1] == 2);
	REQUIRE(vector[2] == 3);
}

SCENARIO("del")
{
	vector_t vector(1);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	REQUIRE(vector.size() == 4);
	REQUIRE(vector.capacity() == 4);
	REQUIRE(vector[0] == 0);
	REQUIRE(vector[1] == 1);
	REQUIRE(vector[2] == 2);
	REQUIRE(vector[3] == 3);
	vector.del();
	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 4);
	REQUIRE(vector[0] == 0);
	REQUIRE(vector[1] == 1);
	REQUIRE(vector[2] == 2);
	vector.del();
	REQUIRE(vector.size() == 2);
	REQUIRE(vector.capacity() == 2);
	REQUIRE(vector[0] == 0);
	REQUIRE(vector[1] == 1);
}

SCENARIO("[]")
{
	vector_t vector(2);
	int a = vector[1];
	REQUIRE(vector.size() == 2);
	REQUIRE(vector.capacity() == 2);
	REQUIRE(vector[0] == 0);
	REQUIRE(vector[1] == 0);
	REQUIRE(a == 0);
}
