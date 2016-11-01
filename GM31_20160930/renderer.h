#ifndef _RENDERER_H_
#define _RENDERER_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
/*******************************************************************************
*
*	���C�u�����̃����N
*
*******************************************************************************/
#pragma comment ( lib , "d3d9.lib" )
#pragma comment ( lib , "d3dx9.lib" )
#pragma comment ( lib , "dxguid.lib" )

/*******************************************************************************
*
*	�}�N����`
*
*******************************************************************************/
/*�E�C���h�E�̕�*/
#define SCREEN_WIDTH ( 1280 )
/*�E�C���h�E�̍���*/
#define SCREEN_HEIGHT ( 720 )
/***********************���_���W**********���_�J���[*****�e�N�X�`�����W*/
#define FVF_VERTEX_2D ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 )

//3D�|���S���̒��_�t�H�[�}�b�g
#define FVF_VERTEX_3D ( D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 )


/*�`�悷��|���S����*/
#define PRIMITIVE ( 2 )
//�|���S���̐�
#define POKYGON_MAX ( 1 )
//�V�[���̐�
#define SCENE_NUM ( 3 )

/*******************************************************************************
*
*	�\���̂̒�`
*
*******************************************************************************/
typedef struct 
{
	/*���_���W*/
	D3DXVECTOR3 pos ;
	/*���W�ϊ��p�W��*/
	float rhw ;
	/*���_�J���[*/
	D3DCOLOR col ;
	/*�e�N�X�`�����W*/
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
*	�N���X�̒�`
*
*******************************************************************************/
//�O���錾
class CScene ;

class CRenderer
{
private:
	/*Direct3D�I�u�W�F�N�g�ւ̃|�C���^*/
	LPDIRECT3D9 m_pD3D  ;
	/*Direct3D�f�o�C�X�ւ̃|�C���^*/
	LPDIRECT3DDEVICE9  m_pD3DDevice ;
	//�V�[���N���X
	CScene *m_Scene[SCENE_NUM] ;

	//���C���[�t���[����ONOFF
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
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif