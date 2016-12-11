#include "stdafx.h"
#include "Start.h"
#include "Scene.h"

SC_Start::SC_Start()
{
	m_tex_num = NEWGAME;
}


SC_Start::~SC_Start()
{
}

void SC_Start::Start()
{
	m_continue_tex.Load("Assets/Sprite/Continue-1.png");
	m_newgame_tex.Load("Assets/Sprite/New Game-2.png");
	m_title_tex.Load("Assets/Sprite/Title-1.png");

	m_continue.Init(&m_continue_tex);
	m_newgame.Init(&m_newgame_tex);
	m_title.Init(&m_title_tex);

	m_continue.SetSize(CONTINUE_MAX_SIZE);
	m_newgame.SetSize(NEWGAME_MAX_SIZE);
	m_title.SetSize(TITLE_MAX_SIZE);

	m_continue.SetPivot({ 0.5f,0.5f });
	m_newgame.SetPivot({ 0.5f, 0.5f });
	m_title.SetPivot({ 0.5f,0.5f });

	m_continue.SetPosition(CONTINUE_POS);
	m_newgame.SetPosition(NEWGAME_POS);
	m_title.SetPosition(TITLE_POS);

	/*soundSource.Init("Assets/modelData/bgm_maoudamashii_piano25.wav");
	soundSource.Play(true);*/
}

void SC_Start::Update()
{
	/*soundSource.Update();*/
	SetTexSize();
	SetScene();
}

void SC_Start::SetTexSize()
{
	CVector2 NewGameSize = NEWGAME_MAX_SIZE;
	CVector2 ContinueSize = CONTINUE_MAX_SIZE;

	switch (m_tex_num)
	{
	case NEWGAME:
		NewGameSize.Scale(SIZE_SCALE);
		break;
	case CONTINUE:
		ContinueSize.Scale(SIZE_SCALE);
		break;
	default:
		break;
	}

	m_continue.SetSize(ContinueSize);
	m_newgame.SetSize(NewGameSize);
}

void SC_Start::SetScene()
{
	float move = KeyInput().GetPad(0).GetRStickYF();

	if (!GetAsyncKeyState(VK_RETURN))
	{
		return;
	}

	switch (m_tex_num)
	{
	case NEWGAME:
		g_scene->Change(Scene::Scenes::STAGE_HOUSE);
		break;
	case CONTINUE:
		g_scene->Change(Scene::Scenes::STAGE_HOUSE);
		break;
	default:
		break;
	}
}

void SC_Start::PostRender(CRenderContext& renderContext)
{
	m_continue.Draw(renderContext);
	m_newgame.Draw(renderContext);
	m_title.Draw(renderContext);
}

void SC_Start::Delete()
{
	DeleteGO(this);
}