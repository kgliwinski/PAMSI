#ifndef ENGINE_HH
#define ENGINE_HH

#include "Board.hh"


class Engine
{
	protected:
	Engine() {}
	virtual ~Engine() = default;
	static Board board;
	static unsigned int depth;

	public:
	Engine(Engine const &) = delete;
	void operator=(Engine const &) = delete;
	static void changeBoardSize(const size_t &newSize);
	static size_t getBoardSize();
	static void setDepth();
	[[nodiscard]] static unsigned int getDepth();
};

#endif