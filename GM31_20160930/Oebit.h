#pragma once
#ifndef _OEBIT_H_
#define _OEBIT_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
/*******************************************************************************
*
*	�N���X�̒�`
*
*******************************************************************************/
class Orbit :public CScene3D
{
protected:

public:
public:
	Orbit(int Prioriry = 1);
	~Orbit();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static Orbit* Create(void);

};
#endif
