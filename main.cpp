#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>

int main() {
    Assimp::Importer importer;
    Assimp::Exporter exporter;

    const auto *scene = importer.ReadFile("../AnimatedMorphCube.gltf", 0);

    if (!scene) {
        std::cout << importer.GetErrorString() << '\n';
        return -1;
    }

    std::cout << scene->mRootNode->mName.C_Str() << '\n';

    aiReturn rv = exporter.Export(scene, "gltf", "../out/AnimatedMorphCube.gltf");
    if (rv != aiReturn::aiReturn_SUCCESS) {
        std::cout << exporter.GetErrorString() << '\n';
        return -1;
    }

    return 0;
}
