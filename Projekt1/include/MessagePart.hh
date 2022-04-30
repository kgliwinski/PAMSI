#ifndef MESSAGE_PART_HH
#define MESSAGE_PART_HH

#include <stdlib.h>
#include <string>

/*! \class MessagePart
 *  \brief Defines a class which represents 1 of n parts of message
 */
class MessagePart
{
	private:
	std::string text;
	unsigned int packetNumber;

	public:
	/// \brief Default constructor
	MessagePart() = default;
	/// \brief Parameter constructor
	MessagePart(std::string _text, unsigned int _packetNumber);
	/// \brief Returns the text of MessagePart
	std::string getText() const;
	/// \brief Returns the packetNumber of message
	unsigned int getPacketNumber() const;
};

#endif