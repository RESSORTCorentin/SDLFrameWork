#include "../../inc/GameGest/TextureManager.h"

TextureManager* TextureManager::s_pInstance = nullptr;

TextureManager::TextureManager()
{

}
TextureManager::~TextureManager(){}

bool    TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if (!(pTempSurface))
    {
        return (false);
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if (pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return (true);
    }
    return (false);
}

void    TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;

    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0,0, flip);
}

void    TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = dstRect.w  = width;
    srcRect.h  = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}

TextureManager  *TextureManager::Instance()
{
    if (s_pInstance == 0)
    {
        s_pInstance = new TextureManager();
        return (s_pInstance);
    }
    return (s_pInstance);
}

void TextureManager::clearFromTextureMap(std::string str)
{
    m_textureMap.erase(str);
}