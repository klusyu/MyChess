#include "stdafx.h"
#include "CChineseChess.h"


CChineseChess::CChineseChess()
{
	InitBoard();
}


CChineseChess::~CChineseChess()
{
}

BOOL CChineseChess::InitBoard()
{
	for (size_t i = 0; i < CCC_ROW; i++)
	{
		for (size_t j = 0; j < CCC_COL; j++)
		{
			m_Board[i][j] = NONE;
		}
	}
	m_Board[0][0] = ºì³µ;
	m_Board[0][1] = ºìÂí;
	m_Board[0][2] = ºìÏà;
	m_Board[0][3] = ºìÊ¿;
	m_Board[0][4] = ºìË§;
	m_Board[0][8] = ºì³µ;
	m_Board[0][7] = ºìÂí;
	m_Board[0][6] = ºìÏà;
	m_Board[0][5] = ºìÊ¿;
	m_Board[2][1] = ºìÅÚ;
	m_Board[2][7] = ºìÅÚ;
	m_Board[3][0] = ºì±ø;
	m_Board[3][2] = ºì±ø;
	m_Board[3][4] = ºì±ø;
	m_Board[3][6] = ºì±ø;
	m_Board[3][8] = ºì±ø;
	
	m_Board[9][0] = ºÚ³µ;
	m_Board[9][1] = ºÚÂí;
	m_Board[9][2] = ºÚÏà;
	m_Board[9][3] = ºÚÊ¿;
	m_Board[9][4] = ºÚË§;
	m_Board[9][8] = ºÚ³µ;
	m_Board[9][7] = ºÚÂí;
	m_Board[9][6] = ºÚÏà;
	m_Board[9][5] = ºÚÊ¿;
	m_Board[7][1] = ºÚÅÚ;
	m_Board[7][7] = ºÚÅÚ;
	m_Board[6][0] = ºÚ±ø;
	m_Board[6][2] = ºÚ±ø;
	m_Board[6][4] = ºÚ±ø;
	m_Board[6][6] = ºÚ±ø;
	m_Board[6][8] = ºÚ±ø;
	return true;
}

CDuiString CChineseChess::GetPieceBkimgName(PieceType type)
{
	CDuiString name;
	switch (type)
	{
	case CChineseChess::ºì³µ:
		return _T("rr.png");
	case CChineseChess::ºìÂí:
		return _T("rn.png");
	case CChineseChess::ºìÏà:
		return _T("rb.png");
	case CChineseChess::ºìÊ¿:
		return _T("ra.png");
	case CChineseChess::ºìË§:
		return _T("rk.png");
	case CChineseChess::ºì±ø:
		return _T("rp.png");
	case CChineseChess::ºìÅÚ:
		return _T("rc.png");
	case CChineseChess::ºÚ³µ:
		return _T("br.png");
	case CChineseChess::ºÚÂí:
		return _T("bn.png");
	case CChineseChess::ºÚÏà:
		return _T("bb.png");
	case CChineseChess::ºÚÊ¿:
		return _T("ba.png");
	case CChineseChess::ºÚË§:
		return _T("bk.png");
	case CChineseChess::ºÚ±ø:
		return _T("bp.png");
	case CChineseChess::ºÚÅÚ:
		return _T("bc.png");
	default:
		break;
	}
	return name;
}

BOOL CChineseChess::PathJudge(int x, int y)
{

	return 0;
}

int CChineseChess::GetRow()
{
	return CCC_ROW;
}

int CChineseChess::GetCol()
{
	return CCC_COL;
}

std::vector<CChineseChess::POS> CChineseChess::GetPieceAvailablePath(SelectPiece pie)
{
	PieceType ty = (PieceType)pie.type;
	std::vector<POS> path;
	int x = pie.pos.x, y = pie.pos.y;
	switch (ty)
	{
	case ºì±ø:
	{
		if (y < CCC_ROW && m_Board[x][y + 1] > ºìÅÚ) {

		}
		break;
	}
	case ºÚ±ø:

		break;
	default:
		break;
	}

	return path;
}

BOOL CChineseChess::DrawBoardPieces(CPaintManagerUI &PaintManager)
{
	//×óÉÏ½ÇÆðÊ¼×ø±ê
	int sX = 64;
	int sY = 64;
	int nWidth = 75;
	SIZE leftTop = { sX, sY };

	CContainerUI* p = static_cast<CContainerUI*> (PaintManager.GetRoot());

	//CButtonUI pBtns[64];// = new CButtonUI();
	for (size_t j = 0; j < CCC_ROW; j++)
	{
		for (size_t i = 0; i < CCC_COL; i++)
		{
			CButtonUI *pBtn = new CButtonUI();
			CDuiString text;
			text.Format(_T("PicBtn%d,%d"), j, i);
			pBtn->SetFloat();
			pBtn->SetName(text);
			pBtn->SetFixedXY(leftTop);
			pBtn->SetFixedWidth(nWidth);
			pBtn->SetBkImage(GetPieceBkimgName((PieceType)m_Board[j][i]));
			pBtn->SetFixedHeight(nWidth);
			leftTop.cx += nWidth;
			m_Piceses.push_back(pBtn);
			p->Add(pBtn);
		}
		leftTop.cx = sX;
		leftTop.cy += nWidth;
	}
	return 0;
}
