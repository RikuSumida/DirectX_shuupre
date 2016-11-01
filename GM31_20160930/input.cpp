/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"

/*******************************************************************************
*
*	マクロ定義
*
*******************************************************************************/
/*******************************************************************************
*
*	グローバル変数
*
*******************************************************************************/
BYTE CInput::m_aKeyState[ 256 ]; //キーボードの入力情報ワーク
BYTE CInput::m_aKeyStateTrigger[ 256 ]; //トリガー情報
BYTE CInput::m_aKeyStateRelease[ 256 ]; //リリース情報
BYTE CInput::m_aKeyStateRepeat[ 256 ]; //キーリピート情報
int CInput::m_aKeyStateRepeatCount[ 256 ]; //キーリピートカウント

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
//コンストラクタ
CInput::CInput()
{
	m_pInput = NULL;
	m_pDevKeyboard = NULL ;

}
//デストラクタ
CInput::~CInput()
{
}


/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CInput :: Init ( HINSTANCE hInstance , HWND hWnd ) 
{

	if( m_pInput == NULL )
	{
		//DirectInputオブジェクトの生成
		if( FAILED( DirectInput8Create( hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, ( void** )&m_pInput, NULL ) ) )
		{
			return E_FAIL;
		}
	}

	if( FAILED( m_pInput -> CreateDevice( GUID_SysKeyboard, &m_pDevKeyboard, NULL ) ) )
	{
		return E_FAIL;
	}
	if( FAILED( m_pDevKeyboard -> SetDataFormat( &c_dfDIKeyboard ) ) ) //データフォーマットの設定
	{
		return E_FAIL;
	}
	if( FAILED( m_pDevKeyboard -> SetCooperativeLevel( hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE ) ) ) //協調モードの設定
	{
		return E_FAIL;
	}
	m_pDevKeyboard -> Acquire( ); //アクセス権を取得


	return S_OK ;

}
/*******************************************************************************
*
*	終了
*
*
*******************************************************************************/
/*******************************************************************************
*
*	終了処理関数
*	引数 : 無し
*	戻り値 : 無し
*******************************************************************************/
void CInput::Uninit(void)
{
	if( m_pDevKeyboard != NULL )
	{	
		m_pDevKeyboard -> Unacquire( ); //アクセス権を解放
		m_pDevKeyboard -> Release( ); //キーボードへのポインタの解放
		m_pDevKeyboard = NULL;
	}


	if( m_pInput != NULL )
	{
		m_pInput -> Release( ); //デバイスの解放
		m_pInput = NULL;
	}

}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CInput::Update(void)
{
	BYTE aKeyState[ 256 ];

	if( SUCCEEDED( m_pDevKeyboard -> GetDeviceState( sizeof( aKeyState ), &aKeyState[ 0 ] ) ) )
	{
		for( int nCntKey = 0; nCntKey < 256 ; nCntKey++ )
		{
			//トリガーキーの処理
			m_aKeyStateTrigger[ nCntKey ] = ( m_aKeyState[ nCntKey ] | aKeyState[ nCntKey ] ) ^ m_aKeyState[ nCntKey ];

			//リリースキーの処理
			m_aKeyStateRelease[ nCntKey ] = ( m_aKeyState[ nCntKey ] | aKeyState[ nCntKey ] ) ^ aKeyState[ nCntKey ];

			//リピートキーの処理
			if( m_aKeyStateRepeatCount[ nCntKey ] <= REPEAT_INTERVAL )
			{
				m_aKeyStateRepeat[ nCntKey ] = ( m_aKeyState[ nCntKey ] | aKeyState[ nCntKey ] ) ^ m_aKeyState[ nCntKey ];
				m_aKeyStateRepeatCount[ nCntKey ]++;
			}
			if( m_aKeyStateRepeatCount[ nCntKey ] >= REPEAT_INTERVAL )
			{
				m_aKeyStateRepeat[ nCntKey ] = m_aKeyState[ nCntKey ];
			}
			if( m_aKeyStateRelease[ nCntKey ] == m_aKeyState[ nCntKey ] )
			{
				m_aKeyStateRepeatCount[ nCntKey ] = 0;
			}

			//プレスキーの処理
			m_aKeyState[ nCntKey ] = aKeyState[ nCntKey ];
		}
	}
	else
	{
		m_pDevKeyboard -> Acquire( );
	}
}

/*******************************************************************************
* 関数名: bool GetKeyboardPress( int nKey )
*		  (関数の概要)
* 引数:   void 引数なし
* 戻り値: int nKey
* 説明:   プレスキーの取得
*******************************************************************************/
bool CInput::GetKeyboardPress( int nKey )
{
	return ( m_aKeyState[ nKey ]&0x80 )? true : false;
}
/*******************************************************************************
* 関数名: bool GetKeyboardTrigger( int nKey )
*		  (関数の概要)
* 引数:   void 引数なし
* 戻り値: int nKey
* 説明:   トリガーキーの取得
*******************************************************************************/
bool CInput::GetKeyboardTrigger( int nKey )
{
	return ( m_aKeyStateTrigger[ nKey ]&0x80 )? true : false;
}
/*******************************************************************************
* 関数名: bool GetKeyboardRelease( int nKey )
*		  (関数の概要)
* 引数:   void 引数なし
* 戻り値: int nKey
* 説明:   リリースキーの取得
*******************************************************************************/
bool CInput::GetKeyboardRelease( int nKey )
{
	return ( m_aKeyStateRelease[ nKey ]&0x80 )? true : false;
}
/*******************************************************************************
* 関数名: bool GetKeyboardRepeat( int nKey )
*		  (関数の概要)
* 引数:   void 引数なし
* 戻り値: int nKey
* 説明:   リピートキーの取得
*******************************************************************************/
bool CInput::GetKeyboardRepeat( int nKey )
{
	return ( m_aKeyStateRepeat[ nKey ]&0x80 )? true : false;
}
