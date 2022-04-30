#ifndef MESSAGE_HH
#define MESSAGE_HH

#include <fstream>
#include <iostream>

#include "MessagePart.hh"
#include "PriorityQueue.hh"

/*! \class Message
 *  \brief Defines a message handling class
 */
class Message
{
	private:
	stringPriorityQueue messageParts;

	public:
	/// \brief Default constructor
	Message() = default;
	/// \brief Decode message
	bool decode(std::string Part, MessagePart &res) const;
	/// \brief Read messageParts from a txt file
	bool readFromFile(const std::string fileName);
    /// \brief Print read message
	friend std::ostream &operator<<(std::ostream &out, const Message &message);
};
    
    std::ostream &operator<<(std::ostream &out, const Message &message);

#endif