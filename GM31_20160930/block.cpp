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
CBlock::CBlock(int Priority):CScene3D(Priority)
{
	m_pointCnt = 0;
	m_indexCnt = 0;

	m_FaceCnt = 0;

	m_Block_x =0;
	m_Block_z =0;
	/*�e�N�X�`���ւ̃|�C���^*/
	m_pTexturePolygon = NULL ;
	//�C���f�b�N�X�o�b�t�@

	m_pIdxBuffField = NULL ;
	
	m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	//m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Scl = D3DXVECTOR3 ( 1 , 1 , 1 ) ;
	m_HitFlg = false;

}
//�f�X�g���N�^
CBlock::~CBlock()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CBlock:: Init ( void )
{
	VERTEX_3D *pVtx ;
	WORD * pIdx ;
	CGame* game = (CGame*)GetManager()->GetMode();

	CSceneX *Player;
	D3DXVECTOR3 PlayerPos;	
	Player = game->GetPlayer();
	PlayerPos = Player->GetPosition();
	//�J�����擾
	CCamera *pCamera;
	CAMERA Camera;
	pCamera = game->GetCamera();
	Camera = pCamera->m_Camera;

	m_Position = D3DXVECTOR3 ( PlayerPos.x  , PlayerPos.y , PlayerPos.z ) ;

	m_Shot = true;



	//D3DXVECTOR3 v[4],v1,v2;
	//D3DXVECTOR3 crossv[4],cross;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	/*���b�V���p�ϐ�*/
	int tmp1 ;
	int tmp2 ;
	bool plus ;
	plus = false ;

	m_Block_x = BLOCK_X_SKY ;
	m_Block_z = BLOCK_Z_SKY ;
	/*���b�V���ݒ�*/
	m_pointCnt = ( m_Block_x + 1 ) * ( m_Block_z + 1 ) ;

	m_indexCnt = m_pointCnt + ( ( m_Block_x + 1 ) + 2 ) * ( m_Block_z -1 ) ;


	m_FaceCnt = ( ( m_Block_x * m_Block_z ) * 2 + ( m_Block_z- 1 ) * 4 );

	tmp3 = m_Block_x+1;

	tmp1 = ( m_Block_x + 1 ) * 2 ;

	tmp2  = tmp1 + 2 ;





	/*�e�N�X�`���̓ǂݍ���*/
	//D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/skybox002.png" , & m_pTexturePolygon ) ;

	for ( int i = 0 ; i < BOX_MAX ; i ++ )
	{
		/*���_�o�b�t�@�̐���*                        �m�ۂ���o�b�t�@�T�C�Y                         �g�p���钸�_�t�H�[�}�b�g*/
		if ( FAILED ( pDevice ->CreateVertexBuffer ( sizeof ( VERTEX_3D ) * m_pointCnt , D3DUSAGE_WRITEONLY , FVF_VERTEX_3D , D3DPOOL_MANAGED , & m_pVtxBuffSky[i]  , NULL ) ) )
		{
			return E_FAIL ;
		}



		/*�������m��*/
		m_pVtxBuffSky[i]  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;






		//*�@��*/
		for ( int i =0 ; i<m_pointCnt ; i++ )
		{

			pVtx [ i ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
			pVtx [ i ].col = D3DXCOLOR ( 0.1f , 0.5f , 1.0f , 0.5f ) ;
		}



		/*�e�N�X�`�����W*******************   U     V   */
		for( int nCnt = 0, divideX = 0, divideY = 0; nCnt < m_pointCnt; nCnt++ ) //���_�ԍ�, ��, ���s
		{
			if( nCnt != 0 )
			{
				divideX = nCnt % ( (int)m_Block_x + 1 );
				divideY = nCnt / ( m_Block_x + 1 );
			}
			switch (i)
			{
			case 0:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) ,0, ( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO) );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , (2.0f/3.0f)  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , (2.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , 1  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , 1  );

				break;
			case 1:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) ,BLOCK_SIZE_BLO, ( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO) );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , 0  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , 0  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , 1.0f/3.0f  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , 1.0f/3.0f  );

				break;
			case 2:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) ,( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO), 0 );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , (1.0f/3.0f)  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , (1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) ,  2.0f/3.0f  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) ,  2.0f/3.0f  );

				break;
			case 3:
				pVtx [ nCnt ] .pos = D3DXVECTOR3(BLOCK_SIZE_BLO ,( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO), (((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , (1.0f/3.0f)  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) , (1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) ,  2.0f/3.0f  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,  2.0f/3.0f  );
															  
				break;
			case 4:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) ,( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO), BLOCK_SIZE_BLO );
				//pVtx[ 0 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,(1.0f/3.0f) );
				//pVtx[ 1 ].tex = D3DXVECTOR2(            1 ,(1.0f/3.0f)  );
				//pVtx[ 2 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,(2.0f/3.0f)  );
				//pVtx[ 3 ].tex = D3DXVECTOR2(            1 ,(2.0f/3.0f)  );
				pVtx[ 0 ].tex = D3DXVECTOR2(			1 ,(1.0f/3.0f) );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,(1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2(			1 ,(2.0f/3.0f)  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,(2.0f/3.0f)  );

				break;
			case 5:
				pVtx [ nCnt ] .pos = D3DXVECTOR3(0 ,( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO), (((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) );
				//pVtx[ 0 ].tex = D3DXVECTOR2(               0 ,(1.0f/3.0f) );
				//pVtx[ 1 ].tex = D3DXVECTOR2(     (1.0f/4.0f) , (1.0f/3.0f)  );
				//pVtx[ 2 ].tex = D3DXVECTOR2(               0 ,(2.0f/3.0f)  );
				//pVtx[ 3 ].tex = D3DXVECTOR2(     (1.0f/4.0f) ,(2.0f/3.0f)  );
				pVtx[ 0 ].tex = D3DXVECTOR2(               (1.0f/4.0f) ,(1.0f/3.0f) );
				pVtx[ 1 ].tex = D3DXVECTOR2(     0 , (1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2(               (1.0f/4.0f) ,(2.0f/3.0f)  );
				pVtx[ 3 ].tex = D3DXVECTOR2(     0 ,(2.0f/3.0f)  );

				break;

			}
			//pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_SKY / m_Block_x ) * divideX )) ,0, ( (((float)-BLOCK_SIZE_SKY / m_Block_z ) * divideY)+(float)BLOCK_SIZE_SKY) );
			//pVtx[ nCnt ].tex = D3DXVECTOR2( ( ( 1.0f / m_Block_x ) * divideX ) , ( ( 1.0f / m_Block_z ) * divideY )  );
			//pVtx [ nCnt ] .pos = D3DXVECTOR3(( ( -BLOCK_SIZE_SKY / m_Block_x ) * divideX ) ,0, ( ( BLOCK_SIZE_SKY / m_Block_z ) * divideY ) );


		}



		/*�C���f�b�N�X�o�b�t�@�̊m��*/
		pDevice -> CreateIndexBuffer ( sizeof ( WORD ) * m_indexCnt , D3DUSAGE_WRITEONLY , D3DFMT_INDEX16 , D3DPOOL_MANAGED , & m_pIdxBuffField , NULL ) ;

		m_pIdxBuffField ->Lock ( 0 , 0, ( void ** ) & pIdx , 0 ) ;


		for( int IndexCnt = 0, DegeneracyNum = 0, Degeneracy = ( ( m_Block_x + 1 ) * 2 - 1 ); IndexCnt < m_indexCnt/2 ; IndexCnt++ ) //�C���f�b�N�X�l, �k�މ�, �k�ޏꏊ
		{ 
			pIdx[ IndexCnt * 2 ] = ( IndexCnt + ( m_Block_x + 1 ) ) - DegeneracyNum;
			pIdx[ IndexCnt * 2 + 1 ] = ( IndexCnt - DegeneracyNum );
			if( ( IndexCnt * 2 ) + 1 == Degeneracy && IndexCnt < m_indexCnt / 2 - 1 )
			{
				Degeneracy += ( m_Block_x + 2 ) * 2;
				IndexCnt++;
				pIdx[ IndexCnt * 2 ] = IndexCnt - ( 1 + DegeneracyNum );
				pIdx[ IndexCnt * 2 + 1 ] = ( IndexCnt + ( m_Block_x + 1 ) ) - DegeneracyNum;
				DegeneracyNum += 1;
			}
		}





	




		/*���*/
		m_pIdxBuffField ->Unlock ( ) ;
		/*���*/
		m_pVtxBuffSky[i]  ->Unlock ( ) ;

	}
	Time =0;

	return S_OK ;

}
//����
CBlock* CBlock::Create(void)
{
	CBlock *Block;
	Block = new CBlock ;
	Block ->Init();

	return Block;

}
bool CBlock::Use ( void)
{
	return m_HitFlg;
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
void CBlock::Uninit(void)
{


	for ( int nCnt = 0 ; nCnt < BOX_MAX ; nCnt ++ )
	{
		/*���_�o�b�t�@�̉��*/
		if ( m_pVtxBuffSky[nCnt]  != NULL )
		{
			m_pVtxBuffSky[nCnt] ->Release ( ) ;
			m_pVtxBuffPolygon  = NULL ;
		}

		/*���_�o�b�t�@�̉��*/
		if ( m_pTexturePolygon  != NULL )
		{
			m_pTexturePolygon ->Release ( ) ;
			m_pTexturePolygon  = NULL ;
		}

		/*���_�o�b�t�@�̉��*/
		if ( m_pIdxBuffField  != NULL )
		{
			m_pIdxBuffField ->Release ( ) ;
			m_pIdxBuffField  = NULL ;
		}

	}




}

/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CBlock::Update(void)
{
	CGame* game = (CGame*)GetManager()->GetMode();
	//�v���C���[�擾
	CSceneX *Player;
	D3DXVECTOR3 PlayerPos;	
	Player = game->GetPlayer();
	PlayerPos = Player->GetPosition();
	//�J�����擾
	CCamera *pCamera;
	CAMERA Camera;
	pCamera = game->GetCamera();
	Camera = pCamera->m_Camera;

	CBillbord* Enemy;
	D3DXVECTOR3 EnemyPos;
	Enemy = game->GetBillbord();

	EnemyPos = Enemy->GetPosition();

	Time ++;


	

	if ( m_Position.x < EnemyPos.x + 30 &&m_Position.x >EnemyPos.x - 30 && m_Position.z < EnemyPos.z +30 && m_Position.z > EnemyPos.z -30 && m_HitFlg == false )
	{
		m_Scl *= 2;
		m_HitFlg = true;
		CFade::Start(new CResult);
	}
	if ( m_HitFlg == false )
	{
		if (m_Shot == true)
		{
			m_work = Camera.rot.y;
			m_Shot = false;
		}
		m_Position.x += sinf(m_work) * 7;
		m_Position.z += cosf(m_work) * 7;

		m_Rotation.y += 0.1;
		m_Rotation.z += 0.1;

		if ( Time > 300 )
		{
			Uninit();
			Release(1);
		}
	}




}
/*******************************************************************************
*
*	�`��
*
*
*******************************************************************************/
/*******************************************************************************
*
*	�`�揈���֐�
*	���� : ����
*	�߂�l : ����
*******************************************************************************/

void CBlock:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();



	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;

	pDevice -> LightEnable ( 0 , TRUE ) ;

	for ( int nCnt = 0 ;nCnt<BOX_MAX;nCnt++)
	{





		/*���[���h�}�g���N�X�̏�����*/
		D3DXMatrixIdentity ( & m_mtxWorld ) ;

		/*�X�P�[���𔽉f*/
		D3DXMatrixScaling ( & mtxScl , m_Scl.x , m_Scl.y , m_Scl.z) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxScl ) ;

		///*�ړ��𔽉f*/
		D3DXMatrixTranslation ( & mtxTrans ,  0 ,  -(BLOCK_SIZE_BLO/2) , 0) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;


		///*�ړ��𔽉f*/
		D3DXMatrixTranslation ( & mtxTrans ,  -(BLOCK_SIZE_BLO/2) ,  0 , -(BLOCK_SIZE_BLO/2)) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;

	
		/*��]�𔽉f*/
		D3DXMatrixRotationYawPitchRoll ( & mtxRot , m_Rotation .y , m_Rotation .x , m_Rotation .z ) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxRot ) ;
	
		///*�ړ��𔽉f*/
		D3DXMatrixTranslation ( & mtxTrans ,  0 ,  (BLOCK_SIZE_BLO/2) , 0) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;

		/*�ړ��𔽉f*/
		D3DXMatrixTranslation ( & mtxTrans , m_Position . x  , m_Position . y , m_Position . z ) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;
		
		/*���[���h�}�g���N�X�̐ݒ�*/
		
		pDevice -> SetTransform ( D3DTS_WORLD , & m_mtxWorld ) ;



		/*���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h*/
		pDevice  ->SetStreamSource ( 0 , m_pVtxBuffSky[nCnt] , 0 , sizeof ( VERTEX_3D ) ) ;

		/*�C���f�b�N�X�o�b�t�@���o�C���h*/
		pDevice ->SetIndices ( m_pIdxBuffField ) ;

		/*�|���S���`��*/
		/*���_�t�H�[�}�b�g�̐ݒ�*/
		pDevice ->SetFVF ( FVF_VERTEX_3D ) ;
		/*�e�N�X�`���̐ݒ�*/
		pDevice  ->SetTexture ( 0 , m_pTexturePolygon ) ;

		//pDevice -> SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

		//pDevice ->SetRenderState ( D3DRS_ALPHABLENDENABLE , TRUE ) ;
		//pDevice ->SetRenderState ( D3DRS_SRCBLEND , D3DBLEND_SRCALPHA ) ;
		//pDevice ->SetRenderState ( D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA ) ;

		//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAOP , D3DTOP_MODULATE ) ;
		//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAARG1 , D3DTA_TEXTURE ) ;
		//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAARG2 , D3DTA_CURRENT ) ;


		/*�|���S���`��*/
		/******************************�|���S���̎��****�`�悷��v���~�e�B�u��**�f�[�^�̐擪�A�h���X**�f�[�^�Ԋu*/
		/*************************�v���~�e�B�u�̎��*******************���_��*****�`�悷��v���~�e�B�u��*/
		pDevice ->DrawIndexedPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , 0 , m_pointCnt , 0, m_FaceCnt ) ;
	}
	/*���C�g��L���ɂ���*/
	//pDevice -> LightEnable ( 0 , TRUE ) ;
	//pDevice ->SetTextureStageState(1, D3DTSS_COLOROP,   D3DTOP_DISABLE);
	//pDevice ->SetTextureStageState(1, D3DTSS_ALPHAOP,   D3DTOP_DISABLE);
	//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAOP , D3DTOP_SELECTARG1 ) ;
	

	//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAOP , D3DTOP_MODULATE ) ;

}
