#ifndef _TITLE_H_
#define _TITLE_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/





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
class CEnemy;
class CGate;

class CTitle : public CMode
{
protected:
	int m_Cnt;
	CCamera *m_Camera;
	CLight *m_Light;

	CMeshfield *m_Mesh;

	CEnemy* m_Enemy[30];
	CGate* m_Gate;


public :

	CTitle();
	~CTitle();
	void Init ( void )  ;
	void Uninit ( void ) ;
	void Update ( void)  ;
	void Draw ( void )  ;

	CMeshfield *GetMeshField(void);
	CCamera* GetCamera(void);
	CEnemy* GetEnemy(int id);
	CGate* GetGate(void);





};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif