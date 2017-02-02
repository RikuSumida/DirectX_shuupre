#pragma once
#ifndef _3DOBJECT_H_
#define _3DOBJECT_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/

//�}�N����`

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
class CSceneObject : public CSceneX
{
protected:

	/*���b�V�����*/
	LPD3DXMESH m_pMesh;

	/*�}�e���A�����*/
	LPD3DXBUFFER m_pBuffMat;

	/*�}�e���A���̐�*/
	DWORD m_numMat;

	/*���[���h�}�g���N�X*/
	D3DXMATRIX m_mtxWorld;

	D3DMATERIAL9		*m_pMeshMat;
	LPDIRECT3DTEXTURE9	*m_pMeshTex;









public:
	CSceneObject(int Prioriry = 1);
	~CSceneObject();
	HRESULT Init(const char *filename);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CSceneObject* Create(const char *filename);
	//D3DXVECTOR3 GetPosition ( void );
	void  SetPosition(D3DXVECTOR3 Pos);






};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif
