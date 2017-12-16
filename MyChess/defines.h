#pragma once

enum ePiecesType {undef, 车, 马, 相, 士, 将, 炮, 卒};
enum ePlayer {undef, Red, Black};
/*棋子类*/
class Chesspieces
{
	ePlayer player;
	ePiecesType type;
};


