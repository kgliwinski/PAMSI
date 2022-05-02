#ifndef MESSAGE_HH
#define MESSAGE_HH

#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "MessagePart.hh"
#include "PriorityQueue.hh"

/*! \class Message
 *  \brief Defines a message handling class
 */
class Message
{
	private:
	stringPriorityQueue messageParts;
	std::string fileName;
	public:
	/// \brief Default constructor
	Message(std::string _fileName);
	/// \brief Decode message
	bool decode(std::string Part, MessagePart &res) const;
	/// \brief Read messageParts from a txt file
	bool readFromFile();
	/// \brief Returns the message and clears messageParts queue
	std::string returnPrint();
    /// \brief Print read message
	friend std::ostream &operator<<(std::ostream &out, const Message &message);
};
    
    std::ostream &operator<<(std::ostream &out, const Message &message);

#endif