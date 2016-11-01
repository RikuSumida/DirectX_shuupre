#ifndef _RENDERER_H_
#define _RENDERER_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
/*******************************************************************************
*
*	ライブラリのリンク
*
*******************************************************************************/
#pragma comment ( lib , "d3d9.lib" )
#pragma comment ( lib , "d3dx9.lib" )
#pragma comment ( lib , "dxguid.lib" )

/*******************************************************************************
*
*	マクロ定義
*
*******************************************************************************/
/*ウインドウの幅*/
#define SCREEN_WIDTH ( 1280 )
/*ウインドウの高さ*/
#define SCREEN_HEIGHT ( 720 )
/***********************頂点座標**********頂点カラー*****テクスチャ座標*/
#define FVF_VERTEX_2D ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 )

//3Dポリゴンの頂点フォーマット
#define FVF_VERTEX_3D ( D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 )


/*描画するポリゴン数*/
#define PRIMITIVE ( 2 )
//ポリゴンの数
#define POKYGON_MAX ( 1 )
//シーンの数
#define SCENE_NUM ( 3 )

/*******************************************************************************
*
*	構造体の定義
*
*******************************************************************************/
typedef struct 
{
	/*頂点座標*/
	D3DXVECTOR3 pos ;
	/*座標変換用係数*/
	float rhw ;
	/*頂点カラー*/
	D3DCOLOR col ;
	/*テクスチャ座標*/
	D3DXVECTOR2 tex ;
} VERTEX_2D ;
typedef struct
{
	D3DXVECTOR3 pos ;
	D3DXVECTOR3 nor ;
	D3DCOLOR col ;
	D3DXVECTOR2 tex ;
} VERTEX_3D ;

/*******************************************************************************
*
*	クラスの定義
*
*******************************************************************************/
//前方宣言
class CScene ;

class CRenderer
{
private:
	/*Direct3Dオブジェクトへのポインタ*/
	LPDIRECT3D9 m_pD3D  ;
	/*Direct3Dデバイスへのポインタ*/
	LPDIRECT3DDEVICE9  m_pD3DDevice ;
	//シーンクラス
	CScene *m_Scene[SCENE_NUM] ;

	//ワイヤーフレームのONOFF
	bool m_WireFrame; 



public :
	CRenderer();
	~CRenderer();
	HRESULT Init ( HINSTANCE hInstance , HWND hWnd , BOOL bWindow );
	void Uninit ( void );
	void Update ( void ) ;
	void Draw ( void ) ;
	void Begin ( void ) ;
	void End ( void ) ;
	LPDIRECT3DDEVICE9 GetDevice ( void );





};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif