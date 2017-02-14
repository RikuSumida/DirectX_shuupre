/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"
#include "al.h"
#include "alut.h"


ALuint CSoundGL::m_buffer[SOUND_NUM], CSoundGL::m_source[SOURCE_NUM];

//コンストラクタ
CSoundGL::CSoundGL()
{
}
//デストラクタ
CSoundGL::~CSoundGL()
{
}

//初期化
void CSoundGL::Init(void)
{
    alutInit(NULL, NULL);

}
//読み込み
void CSoundGL::Load(void)
{
	alGenBuffers( SOUND_NUM, m_buffer );
	alGenSources( SOURCE_NUM, m_source );
	//m_buffer[0] = alutCreateBufferHelloWorld(); 

	m_buffer[0] = alutCreateBufferFromFile("data/BGM/game.wav");
	m_buffer[1] = alutCreateBufferFromFile("data/SE/Enemycapture.wav");
	m_buffer[2] = alutCreateBufferFromFile("data/SE/fue.wav");
	m_buffer[3] = alutCreateBufferFromFile("data/SE/enter.wav");
	m_buffer[4] = alutCreateBufferFromFile("data/SE/sheep-cry1.wav");

}
//再生
void CSoundGL::Start(SOUND_LABEL label, bool Loop)
{
	int i;
	// 状態変数
	ALint state[SOURCE_NUM];

	for ( i = 0 ; i<SOURCE_NUM;i++)
	{
		// ソースの状態を取得
		alGetSourcei(m_source[i], AL_SOURCE_STATE, &state[i]);

		//使えるソースか?
		if ( state[i] != AL_PLAYING )
		{
			alSourcei(m_source[i], AL_BUFFER, m_buffer[label]); // 音データのバッファを指定
			if (Loop==true)
			{
				alSourcei(m_source[i], AL_LOOPING, AL_TRUE); // ループの設定

			}
			else
			{
				alSourcei(m_source[i], AL_LOOPING, AL_FALSE); // ループの設定
			}

			alSourcePlay(m_source[i]);
			break;

		}
	}
 
 

 	//alSourcei(m_source[i], AL_LOOPING, AL_FALSE); // ループの設定
 

}
//終了
void CSoundGL::Uninit(void)
{
	alDeleteBuffers(SOUND_NUM,&m_buffer[0]);
	alDeleteSources(SOURCE_NUM,&m_source[0]);
	alutExit();
}
