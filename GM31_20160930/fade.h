#ifndef _FADE_H_
#define _FADE_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/





/*******************************************************************************
*
*	構造体の定義
*
*******************************************************************************/
typedef enum FADE
{
	FADE_IN,
	FADE_OUT,
	FADE_NONE
};
/*******************************************************************************
*
*	クラスの定義
*
*******************************************************************************/
class CScene2D;
class CFade 
{
protected:
	/*テクスチャへのポインタ*/
	LPDIRECT3DTEXTURE9 m_pTexturePolygon ;
	/*頂点バッファへのポインタ*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffPolygon;

	int m_Alpha;
	static CMode* m_NextMode;
	static FADE m_State;
	static int m_Count;
public :
	CFade();
	~CFade();
	HRESULT Init ( void ) ;
	void Uninit ( void ) ;
	void Update ( void)  ;
	void Draw ( void )  ;
	static void Start ( CMode* NextMode);
	static CFade* Create(void);




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif