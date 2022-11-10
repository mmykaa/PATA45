#include "Animation.h"
#include "TextureManager.h"

Animation::Animation()
{

}

Animation::~Animation()
{

}


void Animation::SetProperties(std::string textureID, int spriteRow, int startingFrame, int frameCount, int animSpeed, SDL_RendererFlip flip /*= SDL_FLIP_NONE*/)
{
	m_TextureID = textureID;
	m_SpriteRow = spriteRow;
	m_FrameCount = frameCount;
	m_StartingFrame = startingFrame;
	m_AnimSpeed = animSpeed;
	m_Flip = flip;
}


void Animation::Update()
{
	m_SpriteFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}

void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
	TextureManager::GetInstance()->DrawFrame(m_TextureID, x, y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}