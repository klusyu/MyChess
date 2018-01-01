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
	m_Board[0][0] = �쳵;
	m_Board[0][1] = ����;
	m_Board[0][2] = ����;
	m_Board[0][3] = ��ʿ;
	m_Board[0][4] = ��˧;
	m_Board[0][8] = �쳵;
	m_Board[0][7] = ����;
	m_Board[0][6] = ����;
	m_Board[0][5] = ��ʿ;
	m_Board[2][1] = ����;
	m_Board[2][7] = ����;
	m_Board[3][0] = ���;
	m_Board[3][2] = ���;
	m_Board[3][4] = ���;
	m_Board[3][6] = ���;
	m_Board[3][8] = ���;
	
	m_Board[9][0] = �ڳ�;
	m_Board[9][1] = ����;
	m_Board[9][2] = ����;
	m_Board[9][3] = ��ʿ;
	m_Board[9][4] = ��˧;
	m_Board[9][8] = �ڳ�;
	m_Board[9][7] = ����;
	m_Board[9][6] = ����;
	m_Board[9][5] = ��ʿ;
	m_Board[7][1] = ����;
	m_Board[7][7] = ����;
	m_Board[6][0] = �ڱ�;
	m_Board[6][2] = �ڱ�;
	m_Board[6][4] = �ڱ�;
	m_Board[6][6] = �ڱ�;
	m_Board[6][8] = �ڱ�;
	return true;
}

CDuiString CChineseChess::GetPieceBkimgName(PieceType type)
{
	CDuiString name;
	switch (type)
	{
	case CChineseChess::�쳵:
		return _T("rr.png");
	case CChineseChess::����:
		return _T("rn.png");
	case CChineseChess::����:
		return _T("rb.png");
	case CChineseChess::��ʿ:
		return _T("ra.png");
	case CChineseChess::��˧:
		return _T("rk.png");
	case CChineseChess::���:
		return _T("rp.png");
	case CChineseChess::����:
		return _T("rc.png");
	case CChineseChess::�ڳ�:
		return _T("br.png");
	case CChineseChess::����:
		return _T("bn.png");
	case CChineseChess::����:
		return _T("bb.png");
	case CChineseChess::��ʿ:
		return _T("ba.png");
	case CChineseChess::��˧:
		return _T("bk.png");
	case CChineseChess::�ڱ�:
		return _T("bp.png");
	case CChineseChess::����:
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
	case ���:
	{
		if (y < CCC_ROW && m_Board[x][y + 1] > ����) {

		}
		break;
	}
	case �ڱ�:

		break;
	default:
		break;
	}

	return path;
}

BOOL CChineseChess::DrawBoardPieces(CPaintManagerUI &PaintManager)
{
	//���Ͻ���ʼ����
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
