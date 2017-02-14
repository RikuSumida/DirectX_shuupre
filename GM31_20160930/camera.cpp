/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
/*******************************************************************************
*
*	�}�N����`
*
*******************************************************************************/
/*******************************************************************************
*
*	�O���[�o���ϐ�
*
*******************************************************************************/
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CCamera::CCamera()
{

}
//�f�X�g���N�^
CCamera::~CCamera()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
void CCamera:: Init ( void )
{
	VERTEX_3D *pVtx ;
	D3DXVECTOR3 vecDir ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	//�J�����ݒ�
	m_Camera . posV = D3DXVECTOR3 ( 750.0f , 700.0f , -400.0f ) ;
	m_Camera . posR = D3DXVECTOR3 ( 750.0f , 0.0f , 1000.0f ) ;
	m_Camera . vecU = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	m_Camera . fDistance = sqrtf ( ( m_Camera . posV . x * m_Camera . posV . x ) +  ( m_Camera . posV . z * m_Camera . posV . z ) ) ;
	m_Camera . rot = D3DXVECTOR3 ( 0.0f , 0.0f , 0.0f ) ;





}


/*******************************************************************************
*
*	�I��
*
*
*******************************************************************************/
/*******************************************************************************
*
*	�I�������֐�
*	���� : ����
*	�߂�l : ����
*******************************************************************************/
void CCamera::Uninit(void)
{

}
/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CCamera::Update(void)
{
	//CGame* game = (CGame*)GetManager()->GetMode();
	//�v���C���[�擾
	//CSceneX *Player;
	//D3DXVECTOR3 PlayerPos;	
	//Player = game->GetPlayer();
	//PlayerPos = Player->GetPosition();


	//CInput *Input;
	//Input = GetManager()->GetInput();


	//m_Camera . posR .x = PlayerPos.x;
	//m_Camera . posR .y = PlayerPos.y+70;
	//m_Camera . posR .z = PlayerPos.z;

	//m_Camera.posV.y = PlayerPos.y + 100;
	//m_Camera.posV.z = PlayerPos.z + 100;
	/*******�J�����ړ�����******/
	//if ( Input->GetKeyboardPress ( DIK_UP ) )
	//{
	//	/*���_�𓮂���*/
	//	m_Camera . posV .x += sinf ( m_Camera . rot . y )  ;
	//	m_Camera . posV .z += cosf ( m_Camera . rot . y )  ;
	//	/*�����_�𓮂���*/
	//	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//}
	//if ( Input->GetKeyboardPress ( DIK_DOWN ) )
	//{
	//	/*���_�𓮂���*/
	//	m_Camera . posV .x -= sinf ( m_Camera . rot . y ) ;
	//	m_Camera . posV .z -= cosf ( m_Camera . rot . y ) ;
	//	/*�����_�𓮂���*/
	//	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//}
	//if ( Input->GetKeyboardPress ( DIK_LEFT ) )
	//{
	//	/*�΂߈ړ�*/
	//	if ( Input->GetKeyboardPress ( DIK_UP ) )
	//	{
	//		/*���_�𓮂���*/
	//		m_Camera . posV .x -= sinf ( ( D3DX_PI * ( 0.75 ) ) + m_Camera . rot . y ) ;
	//		m_Camera . posV .z += cosf ( ( D3DX_PI * ( 0.75 ) ) + m_Camera . rot . y ) ;
	//		/*�����_�𓮂���*/
	//		m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//		m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//	}
	//	/*�΂߈ړ�*/
	//	if ( Input->GetKeyboardPress ( DIK_DOWN ) )
	//	{
	//		/*���_�𓮂���*/
	//		m_Camera . posV .x -= sinf ( ( D3DX_PI * ( 0.25 ) ) + m_Camera . rot . y ) ;
	//		m_Camera . posV .z += cosf ( ( D3DX_PI * ( 0.25 ) ) + m_Camera . rot . y ) ;
	//		/*�����_�𓮂���*/
	//		m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//		m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//	}
	//	/*���_�𓮂���*/
	//	m_Camera . posV .x -= cosf ( -m_Camera . rot . y ) ;
	//	m_Camera . posV .z -= sinf ( -m_Camera . rot . y ) ;
	//	/*�����_�𓮂���*/
	//	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;


	//}
	//if ( Input->GetKeyboardPress ( DIK_RIGHT ) )
	//{
	//	/*�΂߈ړ�*/
	//	if ( Input->GetKeyboardPress ( DIK_UP ) )
	//	{
	//		/*���_�𓮂���*/
	//		m_Camera . posV .x -= sinf ( ( -D3DX_PI * ( 0.75 ) ) + m_Camera . rot . y ) ;
	//		m_Camera . posV .z += cosf ( ( -D3DX_PI * ( 0.75 ) ) + m_Camera . rot . y ) ;
	//		/*�����_�𓮂���*/
	//		m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//		m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//	}
	//	/*�΂߈ړ�*/
	//	if ( Input->GetKeyboardPress ( DIK_DOWN ) )
	//	{
	//		/*���_�𓮂���*/
	//		m_Camera . posV .x -= sinf ( ( -D3DX_PI * ( 0.25 ) ) + m_Camera . rot . y ) ;
	//		m_Camera . posV .z += cosf ( ( -D3DX_PI * ( 0.25 ) ) + m_Camera . rot . y ) ;
	//		/*�����_�𓮂���*/
	//		m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//		m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//	}
	//	/*���_�𓮂���*/
	//	m_Camera . posV .x += cosf ( -m_Camera . rot . y ) ;
	//	m_Camera . posV .z += sinf ( -m_Camera . rot . y ) ;
	//	/*�����_�𓮂���*/
	//	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;


	//}


	///*******�J�����̏�ʂł̑���********/
	///*���_����*/
	//if ( Input->GetKeyboardPress ( DIK_U ) )
	//{
	//	m_Camera . rot . y -= 0.05 ;
	//}

	//if ( Input->GetKeyboardPress ( DIK_O ) )
	//{
	//	m_Camera . rot . y += 0.05 ;
	//}
	////m_Camera . posV .x = m_Camera . posR .x - sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	////m_Camera . posV .z = m_Camera . posR .z - cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	///*�����_����*/
	//if ( Input->GetKeyboardPress ( DIK_J ) )
	//{
	//	m_Camera . rot . y += 0.01 ;
	//}

	//if ( Input->GetKeyboardPress ( DIK_L ) )
	//{
	//	m_Camera . rot . y -= 0.01 ;
	//}
	//if ( Input->GetKeyboardPress ( DIK_Y ) )
	//{
	//	m_Camera . posR .y+=3;
	//}
	//if ( Input->GetKeyboardPress ( DIK_N ) )
	//{
	//	m_Camera . posR .y-=3;
	//}
	//if ( Input->GetKeyboardPress ( DIK_T ) )
	//{
	//	m_Camera . posV .y+=3;
	//}
	//if ( Input->GetKeyboardPress ( DIK_B ) )
	//{
	//	m_Camera . posV .y-=3;
	//}

	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	PrintDebugProc("�J�������_X���W�F%f  Y���W:%f  Z���W%f\n",m_Camera . posV .x,m_Camera . posV .y,m_Camera . posV .z);
}
/*******************************************************************************
*
*	�`��
*
*
*******************************************************************************/
/*******************************************************************************
*
*	�J�����ݒ�
*	���� : ����
*	�߂�l : ����
*******************************************************************************/

void CCamera:: SetCamera ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;


	//�J�����ݒ�
	/*�v���W�F�N�V�����}�g���N�X�̏�����*/
	D3DXMatrixIdentity ( & m_Camera . mtxProjection ) ;
	
	/*�v���W�F�N�V�����}�g���N�X�̍쐬*/
	D3DXMatrixPerspectiveFovLH ( & m_Camera . mtxProjection , ( D3DX_PI / 4 ) , ( float ) SCREEN_WIDTH / SCREEN_HEIGHT , NEARZ , FARZ ) ;

	/*�v���W�F�N�V�����}�g���N�X�̐ݒ�*/
	pDevice -> SetTransform ( D3DTS_PROJECTION , & m_Camera . mtxProjection ) ;

	/*�r���[�}�g���N�X�̏�����*/
	D3DXMatrixIdentity ( & m_Camera . mtxView ) ;
	
	/*�r���[�}�g���N�X�̍쐬*/
	D3DXMatrixLookAtLH ( & m_Camera . mtxView , & m_Camera . posV , & m_Camera . posR , & m_Camera . vecU ) ;
	
	pDevice -> SetTransform ( D3DTS_VIEW , & m_Camera . mtxView ) ;







}


