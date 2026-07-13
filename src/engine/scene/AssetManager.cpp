//
// Created by david on 2026-07-08.
//

#include "AssetManager.h"

AssetManager::AssetManager()
{
    assets = {
        {AssetType::Test1, "../assets/test.png"}
    };
}

AssetManager::~AssetManager()
{
    unloadAssets();
}

Texture2D* AssetManager::loadAsset(AssetType type)
{
    auto [it, inserted] = loadedTextures.emplace(type, LoadTexture(assets.at(type)));

    return &it->second;
}

void AssetManager::unloadAssets()
{
    for (const auto [fst, snd] : loadedTextures)
    {
        UnloadTexture(snd);
    }
    loadedTextures.clear();
}
