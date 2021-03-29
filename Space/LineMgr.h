#pragma once
class LineMgr
{
public:
	LPD3DXLINE m_pLine;
	Matrix m_wMat;
	D3DXCOLOR m_Color;

public:

	void Init(float width, bool an);
	void DrawLine(Vec2* vec, int size);

	void SetColor(D3DXCOLOR m_Color);

};