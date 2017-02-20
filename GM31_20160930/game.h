#ifndef _GAME_H_
#define _GAME_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "manager.h"



/*******************************************************************************
*
*	構造体の定義
*
*******************************************************************************/
/*******************************************************************************
*
*	クラスの定義
*
*******************************************************************************/
class CScene ;
class CCamera;
class CLight ;
class CMeshfield;
class CSceneX;
class CBillbord;
class CEnemy;
class CGate;
class CGame : public CMode
{
protected:
	CCamera *m_Camera;
	CLight *m_Light;

	CMeshfield *m_Mesh;

	CSceneX* m_Player;
	CBillbord* m_Billbord;
	CEnemy* m_Enemy[ENEMY_MAX];
	CGate* m_Gate;

public :
	CGame();
	~CGame();

	void Init ( void )  ;
	void Uninit ( void ) ;
	void Update ( void)  ;
	void Draw ( void )  ;

	CMeshfield *GetMeshField (void);
	CCamera* GetCamera(void);
	CSceneX* GetPlayer (void);
	CBillbord* GetBillbord (void);
	CEnemy* GetEnemy(int id);
	CGate* GetGate(void);




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif