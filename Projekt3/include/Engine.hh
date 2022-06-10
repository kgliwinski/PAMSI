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
	static void init();
	static void changeBoardSize(const size_t &newSize);
	static size_t getBoardSize();
	static void setDepth(const unsigned int & newDepth);
	[[nodiscard]] static unsigned int getDepth();
	[[nodiscard]] static bool makeAIMove();
	[[nodiscard]] static bool makePlayerMove(const Move &move);
};

#endif