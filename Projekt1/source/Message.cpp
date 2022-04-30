#include "../include/Message.hh"

bool Message::decode(std::string messPart, MessagePart &res) const
{
    std::string temp = messPart.substr(0,3);
    unsigned int key;
    if(temp!="PI;")
    {
        return 0;
    }
    messPart.erase(0,3);
    temp = messPart.substr(0,2);
    if(!(temp.at(0) >= 48))
    {
        return 0;
    }
    key = (unsigned int)temp.at(0) - 48;
    if(temp.at(1) != ';')
    {
        return 0;
    }
    messPart.erase(0,2);
    if(messPart.at(messPart.length() - 1) != ';')
    {
        return 0;
    }
    messPart.erase(messPart.length() - 1, messPart.length());
    res = MessagePart(messPart, key);
    return 1;
}

bool Message::readFromFile(const std::string fileName)
{
    std::string lines;
    MessagePart temp;
    // unsigned int n;
	std::ifstream readFile;
	try
	{
		readFile.open(fileName);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
    for(std::string lines; std::getline(readFile, lines); )
    {   
        if(!this->decode(lines, temp))
        {
            return 0;
        }
        messageParts.insert(temp.getText(), temp.getPacketNumber());
    }

    readFile.close();
    return 1;
}

 std::ostream &operator<<(std::ostream &out, const Message &message)
 {
     Message temp = message;
     while(!temp.messageParts.isEmpty())
     {
         out << temp.messageParts.min();
         temp.messageParts.removeMin();
     }
     
     return out;
 }