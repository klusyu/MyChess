#pragma once
#include "CChess.h"
#include <vector>

class CChineseChess : public CChess
{
#define PIECES_COUNT 90
#define CCC_ROW 10
#define CCC_COL 9
	enum PieceType
	{
		NONE,ºì³µ,ºìÂí,ºìÏà,ºìÊ¿,ºìË§,ºì±ø,ºìÅÚ,
		ºÚ³µ,ºÚÂí,ºÚÏà,ºÚÊ¿,ºÚË§,ºÚ±ø,ºÚÅÚ
	};
public:
	CChineseChess();
	~CChineseChess();
	BOOL DrawBoardPieces(CPaintManagerUI &PaintManager) override;
	BOOL InitBoard();
	CDuiString GetPieceBkimgName(PieceType type);
	BOOL PathJudge(int x, int y);
	int GetRow();
	int GetCol();
	std::vector<POS> GetPieceAvailablePath(SelectPiece pie);
private:
	DWORD m_Board[CCC_ROW][CCC_COL];
};

