#pragma once
class CChess
{
public:
	struct POS {
		int x;
		int y;
	};
	struct SelectPiece
	{
		DWORD type;
		POS pos;
	};

	CChess();
	virtual ~CChess();
public:
	virtual BOOL ChoosePiece(CDuiString btnName);
public:
	virtual BOOL DrawBoardPieces(CPaintManagerUI &pPaintManager) = 0;
	virtual BOOL PathJudge(int x, int y) = 0;
	//virtual std::vector<POS> GetPieceAvailablePath(DWORD type) = 0;
	virtual int GetRow() = 0;
	virtual int GetCol() = 0;
protected:
	SelectPiece m_selPiece;
	bool m_bChoose;
	DWORD **m_Board;
	std::vector<CButtonUI*> m_Piceses;
};

