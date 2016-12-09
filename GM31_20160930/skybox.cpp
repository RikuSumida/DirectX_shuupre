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
CSky::CSky(int Priority):CScene3D(Priority)
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
	
	m_Position = D3DXVECTOR3 ( -25000 , -25000 , -25000 ) ;
	//m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;

}
//�f�X�g���N�^
CSky::~CSky()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CSky:: Init ( void )
{
	VERTEX_3D *pVtx ;
	WORD * pIdx ;

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
	D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/skybox002.png" , & m_pTexturePolygon ) ;

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
			pVtx [ i ].col = D3DXCOLOR ( 1.0f , 1.0f , 1.0f , 1.0f ) ;
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
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_SKY / m_Block_x ) * divideX )) ,0, ( (((float)-BLOCK_SIZE_SKY / m_Block_z ) * divideY)+(float)BLOCK_SIZE_SKY) );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , (2.0f/3.0f)  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , (2.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , 1  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , 1  );

				break;
			case 1:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_SKY / m_Block_x ) * divideX )) ,BLOCK_SIZE_SKY, ( (((float)-BLOCK_SIZE_SKY / m_Block_z ) * divideY)+(float)BLOCK_SIZE_SKY) );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , 0  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , 0  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , 1.0f/3.0f  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , 1.0f/3.0f  );

				break;
			case 2:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_SKY / m_Block_x ) * divideX )) ,( (((float)-BLOCK_SIZE_SKY / m_Block_z ) * divideY)+(float)BLOCK_SIZE_SKY), 0 );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , (1.0f/3.0f)  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , (1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) ,  2.0f/3.0f  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) ,  2.0f/3.0f  );

				break;
			case 3:
				pVtx [ nCnt ] .pos = D3DXVECTOR3(BLOCK_SIZE_SKY ,( (((float)-BLOCK_SIZE_SKY / m_Block_z ) * divideY)+(float)BLOCK_SIZE_SKY), (((  (float)BLOCK_SIZE_SKY / m_Block_x ) * divideX )) );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , (1.0f/3.0f)  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) , (1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) ,  2.0f/3.0f  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,  2.0f/3.0f  );
															  
				break;
			case 4:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_SKY / m_Block_x ) * divideX )) ,( (((float)-BLOCK_SIZE_SKY / m_Block_z ) * divideY)+(float)BLOCK_SIZE_SKY), BLOCK_SIZE_SKY );
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
				pVtx [ nCnt ] .pos = D3DXVECTOR3(0 ,( (((float)-BLOCK_SIZE_SKY / m_Block_z ) * divideY)+(float)BLOCK_SIZE_SKY), (((  (float)BLOCK_SIZE_SKY / m_Block_x ) * divideX )) );
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








		//�@�������߂�
		D3DXVECTOR3 Nor0, Vec1, Vec2;	//�v�Z�̌��ʂ��ꎞ�I�Ɋi�[
	
		//for( int IndexCnt = 0, PolygonCnt = 0; IndexCnt < m_MeshNor.WorkIndexMax; IndexCnt += 3, PolygonCnt++ ) //�C���f�b�N�X�l, �k�މ�, �k�ޏꏊ
		//{
		//	��̃x�N�g���̍��������߂�
		//	Vec1 = pVtx[ m_MeshNor.WorkIndex[ IndexCnt + 1 ] ].pos - pVtx[ m_MeshNor.WorkIndex[ IndexCnt ] ].pos;
		//	Vec2 = pVtx[ m_MeshNor.WorkIndex[ IndexCnt + 2 ] ].pos - pVtx[ m_MeshNor.WorkIndex[ IndexCnt ] ].pos;
		//	D3DXVec3Cross( &Nor0, &Vec1, &Vec2 );	//�x�N�g���̊O��
		//	D3DXVec3Normalize( &Nor0, &Nor0 );		//�x�N�g���̐��K��

		//	m_MeshNor.PolygonNor[ PolygonCnt ] = Nor0;
		//	m_MeshNor.nor[ m_MeshNor.WorkIndex[ IndexCnt ] ] += Nor0;				//�@���̊i�[
		//	m_MeshNor.nor[ m_MeshNor.WorkIndex[ IndexCnt + 1 ] ] += Nor0;			//�@���̊i�[
		//	m_MeshNor.nor[ m_MeshNor.WorkIndex[ IndexCnt + 2 ] ] += Nor0;			//�@���̊i�[
		//	m_MeshNor.Number[ m_MeshNor.WorkIndex[ IndexCnt ] ]++;
		//	m_MeshNor.Number[ m_MeshNor.WorkIndex[ IndexCnt + 1 ] ]++;
		//	m_MeshNor.Number[ m_MeshNor.WorkIndex[ IndexCnt + 2 ] ]++;
		//}
		//for( int nCnt = 0; nCnt < m_pointCnt; nCnt++ ) //���_�ԍ�, ��, ���s
		//{
		//	Nor0 = m_MeshNor.nor[ nCnt ] / m_MeshNor.Number[ nCnt ];
		//	D3DXVec3Normalize( &Nor0, &Nor0 );	//�x�N�g���̐��K��
		//	pVtx[ nCnt ].nor = Nor0;
		//}
		//D3DXVECTOR3 Vec[6],Nor[6];
		//int Old = 0;

		//for ( int i = 0 ; i<m_pointCnt; i++)
		//{
		//	if ( pVtx[i].pos.y >= 10)
		//	{
		//		Vec[0] = pVtx[i-1].pos - pVtx[i].pos;
		//		Vec[1] = pVtx[i-tmp3-1].pos - pVtx[i].pos;
		//		Vec[2] = pVtx[i-tmp3].pos - pVtx[i].pos;
		//		Vec[3] = pVtx[i+1].pos - pVtx[i].pos;
		//		Vec[4] = pVtx[i+tmp3+1].pos - pVtx[i].pos;
		//		Vec[5] = pVtx[i+tmp3].pos - pVtx[i].pos;



		//		D3DXVec3Cross(&Nor[0],&Vec[0],&Vec[1]);
		//		D3DXVec3Normalize(&Nor[0],&Nor[0]);
		//		D3DXVec3Cross(&Nor[1],&Vec[1],&Vec[2]);
		//		D3DXVec3Normalize(&Nor[1],&Nor[1]);
		//		D3DXVec3Cross(&Nor[2],&Vec[2],&Vec[3]);
		//		D3DXVec3Normalize(&Nor[2],&Nor[2]);
		//		D3DXVec3Cross(&Nor[3],&Vec[3],&Vec[4]);
		//		D3DXVec3Normalize(&Nor[3],&Nor[3]);
		//		D3DXVec3Cross(&Nor[4],&Vec[4],&Vec[5]);
		//		D3DXVec3Normalize(&Nor[4],&Nor[4]);
		//		D3DXVec3Cross(&Nor[5],&Vec[5],&Vec[0]);
		//		D3DXVec3Normalize(&Nor[5],&Nor[5]);

		//		D3DXVec3Normalize(&pVtx[i].nor,&(Nor[0]+Nor[1]+Nor[2]+Nor[3]+Nor[4]+Nor[5]));

		//		Old = 0;

		//	}
		//}




		/*���*/
		m_pIdxBuffField ->Unlock ( ) ;
		/*���*/
		m_pVtxBuffSky[i]  ->Unlock ( ) ;

	}


	return S_OK ;

}
//����
CSky* CSky::Create(void)
{
	CSky *Sky;
	Sky = new CSky ;
	Sky ->Init();

	return Sky;

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
void CSky::Uninit(void)
{


	for ( int nCnt = 0 ; nCnt < BOX_MAX ; nCnt ++ )
	{
		/*���_�o�b�t�@�̉��*/
		if ( m_pVtxBuffSky[nCnt]  != NULL )
		{
			m_pVtxBuffSky[nCnt] ->Release ( ) ;
			//m_pVtxBuffPolygon  = NULL ;
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
void CSky::Update(void)
{

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

void CSky:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;

	//pDevice -> SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	pDevice -> LightEnable ( 0 , TRUE ) ;

	for ( int nCnt = 0 ;nCnt<BOX_MAX;nCnt++)
	{





		/*���[���h�}�g���N�X�̏�����*/
		D3DXMatrixIdentity ( & m_mtxWorld ) ;

		/*�X�P�[���𔽉f*/
		D3DXMatrixScaling ( & mtxScl , 1.0f , 1.0f , 1.0f) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxScl ) ;
		
		/*��]�𔽉f*/
		D3DXMatrixRotationYawPitchRoll ( & mtxRot , m_Rotation .y , m_Rotation .x , m_Rotation .z ) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxRot ) ;
		
		/*�ړ��𔽉f*/
		D3DXMatrixTranslation ( & mtxTrans , m_Position . x , m_Position . y , m_Position . z ) ;
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

		pDevice -> SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		/*�|���S���`��*/
		/******************************�|���S���̎��****�`�悷��v���~�e�B�u��**�f�[�^�̐擪�A�h���X**�f�[�^�Ԋu*/
		/*************************�v���~�e�B�u�̎��*******************���_��*****�`�悷��v���~�e�B�u��*/
		pDevice ->DrawIndexedPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , 0 , m_pointCnt , 0, m_FaceCnt ) ;
		pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	}
	/*���C�g��L���ɂ���*/
	pDevice -> LightEnable ( 0 , TRUE ) ;


}
