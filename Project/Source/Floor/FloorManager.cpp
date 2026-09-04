#include "FloorManager.h"
#include "Floor.h"

FloorManager* FloorManager::m_Instance = nullptr;

FloorManager::FloorManager()
{
    m_Floor = nullptr;
}

FloorManager::~FloorManager()
{
    Fin();
}

void FloorManager::CreateFloor()
{
    if (!m_Floor)
        m_Floor = new Floor();
}

void FloorManager::Init()
{
    if (m_Floor)
        m_Floor->Init();
}

void FloorManager::Load()
{
    if (m_Floor)
        m_Floor->Load();
}

void FloorManager::Start()
{
    if (m_Floor)
        m_Floor->Start();
}

void FloorManager::Step()
{
    if (m_Floor)
        m_Floor->Step();
}

void FloorManager::Update()
{
    if (m_Floor)
        m_Floor->Update();
}

void FloorManager::Draw()
{
    if (m_Floor)
        m_Floor->Draw();
}

void FloorManager::Fin()
{
    if (m_Floor)
    {
        m_Floor->Fin();
        delete m_Floor;
        m_Floor = nullptr;
    }
}
