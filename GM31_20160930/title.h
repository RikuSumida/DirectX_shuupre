#ifndef _TITLE_H_
#define _TITLE_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "manager.h"




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
class CScene;
class CCamera;
class CLight;
class CMeshfield;
class CSceneX;
class CBillbord;
class CTitleSheep;
class CGate;

class CTitle : public CMode
{
protected:
	int m_Cnt;
	CCamera *m_Camera;
	CLight *m_Light;

	CMeshfield *m_Mesh;

	//CGate* m_Gate;
	CTitleSheep* m_Enemy[ENEMY_MAX];


public :

	CTitle();
	~CTitle();
	void Init ( void )  ;
	void Uninit ( void ) ;
	void Update ( void)  ;
	void Draw ( void )  ;

	CMeshfield *GetMeshField(void);
	CCamera* GetCamera(void);
	CTitleSheep* GetEnemy(int id);
	//CGate* GetGate(void);





};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif