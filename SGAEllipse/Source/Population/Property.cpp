#include "Property.h"
#include <sstream>


Property::Property()
{
	decimalValue = 0;
	binaryValue = std::vector<int>();
}


Property::Property(int decimalValue, const std::vector<int>& binaryValue): decimalValue(decimalValue), binaryValue(binaryValue)
{

}


std::string Property::BinaryString() const
{
	std::ostringstream ostringstream;

	for (int number : binaryValue)
		ostringstream << number;

	return ostringstream.str();
}
