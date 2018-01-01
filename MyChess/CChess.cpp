#include "stdafx.h"
#include "CChess.h"


CChess::CChess():m_bChoose(false)
{
}


CChess::~CChess()
{
}

BOOL CChess::ChoosePiece(CDuiString btnName)
{
	int x = -1, y = -1;
	swscanf_s(btnName, _T("PicBtn%d,%d"), &x, &y);
	if (!m_bChoose) {
		if (m_Board[x][y] != NULL) {
			m_bChoose = true;
			m_selPiece.type = m_Board[x][y];
			m_selPiece.pos.x = x;
			m_selPiece.pos.y = y;
			m_Piceses[m_selPiece.pos.x * GetCol() + m_selPiece.pos.y]->SetBorderSize(2);
			m_Piceses[m_selPiece.pos.x * GetCol() + m_selPiece.pos.y]->SetBorderColor(RGB(255, 0, 0));
		}
	}
	else {
		if (PathJudge(x, y)) {
			m_Board[m_selPiece.pos.x][m_selPiece.pos.y] = NULL;
			m_Board[x][y] = m_selPiece.type;
		}
		else {
			m_bChoose = false;
			m_Piceses[m_selPiece.pos.x * GetCol() + m_selPiece.pos.y]->SetBorderSize(0);
			m_Piceses[m_selPiece.pos.x * GetCol() + m_selPiece.pos.y]->SetBorderColor(RGB(0, 0, 0));
		}
	}
	return 0;
}
