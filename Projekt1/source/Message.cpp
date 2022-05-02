#include "../include/Message.hh"

Message::Message(std::string _fileName) : fileName(_fileName) {}

bool Message::decode(std::string messPart, MessagePart &res) const
{
	std::string temp = messPart.substr(0, 3);
	unsigned int key;
	if (temp != "PI;")
	{
		return 0;
	}
	messPart.erase(0, 3);
	temp = messPart.substr(0, 2);
	if (!(temp.at(0) >= 48))
	{
		return 0;
	}
	key = (unsigned int)temp.at(0) - 48;
	if (temp.at(1) != ';')
	{
		return 0;
	}
	messPart.erase(0, 2);
	if (messPart.at(messPart.length() - 1) != ';')
	{
		return 0;
	}
	messPart.erase(messPart.length() - 1, messPart.length());
	res = MessagePart(messPart, key);
	return 1;
}

bool Message::readFromFile()
{
	std::string lines;
	MessagePart temp;
	// unsigned int n;
	std::ifstream readFile;

	readFile.open(fileName, std::ios::in);
    if(readFile.fail())
    {
        return 0;
    }

	for (std::string lines; std::getline(readFile, lines);)
	{
		if (!this->decode(lines, temp))
		{
			return 0;
		}
		messageParts.insert(temp.getText(), temp.getPacketNumber());
	}
	readFile.close();
	return 1;
}

std::string Message::returnPrint()
{
    std::string out = "";
     while(!this->messageParts.isEmpty())
     {
         out += this->messageParts.min();
         this->messageParts.removeMin();
     }
     
     return out;
}

std::ostream &operator<<(std::ostream &out, const Message &message)
{
	Message temp = message;
	out << temp.messageParts;

	return out;
}