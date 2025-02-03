#include <iostream>

#define CGLTF_IMPLEMENTATION
#define CGLTF_WRITE_IMPLEMENTATION
#include "cgltf_write.h"

int main () {
    cgltf_data *data = NULL;

    {
        cgltf_options options = {};
        cgltf_result result =
            cgltf_parse_file(&options, "../AnimatedMorphCube.gltf", &data);
        if (result != cgltf_result_success) {
            std::cout << "Could not parse file.\n";
            return -1;
        }
    }

    {
        cgltf_options options = {};
        cgltf_result result =
            cgltf_write_file(&options, "../out/AnimatedMorphCube.gltf", data);
        if (result != cgltf_result_success) {
            std::cout << "Could not write file.\n";
            return -1;
        }
    }

    cgltf_free(data);

    return 0;
}
