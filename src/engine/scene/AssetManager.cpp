//
// Created by david on 2026-07-08.
//

#include "AssetManager.h"
#include "Logger.h"

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
    if (auto it = loadedTextures.find(type); it != loadedTextures.end())
    {
        LOG_WARNING("Asset already loaded.");
        return &it->second;
    }

    LOG_INFO("Loading asset.");

    Texture2D texture = LoadTexture(assets.at(type));

    if (!IsTextureValid(texture))
    {
        LOG_ERROR("Failed to load texture.");
        return nullptr;
    }

    auto [it, inserted] = loadedTextures.emplace(type, texture);

    return &it->second;
}

void AssetManager::unloadAssets()
{
    LOG_INFO("Unloading " + std::to_string(loadedTextures.size()) + " assets.");
    for (const auto [fst, snd] : loadedTextures)
    {
        UnloadTexture(snd);
    }
    loadedTextures.clear();
}
