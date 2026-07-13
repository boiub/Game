//
// Created by david on 2026-07-08.
//

#ifndef GAME_ASSETMANAGER_H
#define GAME_ASSETMANAGER_H

#include <unordered_map>

#include "raylib.h"

enum class AssetType
{
    Test1
};


class AssetManager {
public:
    AssetManager();
    ~AssetManager();

    Texture2D* loadAsset(AssetType type);
    void unloadAssets();
private:
    std::unordered_map<AssetType, const char*> assets;
    std::unordered_map<AssetType, Texture2D> loadedTextures;
};


#endif //GAME_ASSETMANAGER_H