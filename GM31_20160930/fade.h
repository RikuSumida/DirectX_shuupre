#ifndef _FADE_H_
#define _FADE_H_
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
typedef enum FADE
{
	FADE_IN,
	FADE_OUT,
	FADE_NONE
};
/*******************************************************************************
*
*	�N���X�̒�`
*
*******************************************************************************/
class CScene2D;
class CFade 
{
protected:
	/*�e�N�X�`���ւ̃|�C���^*/
	LPDIRECT3DTEXTURE9 m_pTexturePolygon ;
	/*���_�o�b�t�@�ւ̃|�C���^*/
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
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif