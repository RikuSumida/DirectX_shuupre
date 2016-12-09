#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/


/*�|���S���̕��̔���*/
#define POLYGON_WIDTH ( 20 / 2 )
/*�|���S���̍����̔���*/
#define POLYGON_HEIGHT ( 50 / 2 )
/*�X�R�A�̌���*/
#define SCORE_NUM ( 2 )


/*******************************************************************************
*
*	�\���̂̒�`
*
*******************************************************************************/
/*******************************************************************************
*
*	�N���X�̒�`
*
*******************************************************************************/
class CScore : public CTime
{
protected:

	/*���_�o�b�t�@�ւ̃|�C���^*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffPolygon[SCORE_NUM];
	//�X�R�A
	int m_Score;
	//�ʒu
	D3DXVECTOR3 m_posTime[SCORE_NUM];
	/*�A�j���[�V�����p�^�[��NO*/
	float m_nPatternAnimTime[SCORE_NUM];

	/*�X�R�A*/
	float m_TimeNum[SCORE_NUM];



public:
	CScore(int Prioriry = 2);
	~CScore();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CScore* Create(D3DXVECTOR3 Pos1, D3DXVECTOR3 Pos2,int Number);



};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif
