#pragma once

#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"

#include "boost/serialization/vector.hpp"

class TestClass
{
	friend class boost::serialization::access;
};
class TestSerialization
{
	friend class boost::serialization::access;

	template <class Archive>
	void serialize(Archive ar, const unsigned int version)
	{
		   
	}
};

