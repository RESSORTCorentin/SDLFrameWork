#ifndef H_TEXTURE
#define H_TEXTURE

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
private:
    std::map<std::string, SDL_Texture*> m_textureMap;
    static TextureManager* s_pInstance;
protected:
    TextureManager();
public:
    ~TextureManager();
    bool    load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    void    draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void    drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void    clearFromTextureMap(std::string str);
    static  TextureManager* Instance();
};

#endif
