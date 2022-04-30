#include "../include/MessagePart.hh"

MessagePart::MessagePart(std::string _text, unsigned int _packetNumber) :
    text(_text), packetNumber(_packetNumber) {}


std::string MessagePart::getText() const
{
    return this->text;
}

unsigned int MessagePart::getPacketNumber() const
{
    return this->packetNumber;
}

