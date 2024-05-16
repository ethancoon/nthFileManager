#include <node_api.h>
#include <filesystem>
#include <string>
#include <vector>

std::vector<std::string> listFiles(const std::filesystem::path& directoryPath) {
    std::vector<std::string> files;

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        files.push_back(entry.path().filename().string());
    }

    return files;
}

napi_value ListFilesWrapper(napi_env env, napi_callback_info args) {
    size_t argc = 1;
    napi_value argv[1];
    napi_value result;
    napi_status status;

    // Parse arguments
    status = napi_get_cb_info(env, args, &argc, argv, nullptr, nullptr);
    if (status != napi_ok || argc < 1) {
        napi_throw_error(env, nullptr, "Invalid arguments");
        return nullptr;
    }

    // Get directory path argument
    char directoryPath[256];
    size_t length;
    status = napi_get_value_string_utf8(env, argv[0], directoryPath, 256, &length);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to get directory path");
        return nullptr;
    }

    // Call listFiles function
    std::vector<std::string> files = listFiles(directoryPath);

    // Convert C++ vector to JavaScript array
    status = napi_create_array(env, &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to create array");
        return nullptr;
    }
    for (size_t i = 0; i < files.size(); ++i) {
        napi_value fileName;
        status = napi_create_string_utf8(env, files[i].c_str(), NAPI_AUTO_LENGTH, &fileName);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Failed to create string");
            return nullptr;
        }
        status = napi_set_element(env, result, i, fileName);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Failed to set array element");
            return nullptr;
        }
    }

    return result;
}

napi_value Init(napi_env env, napi_value exports) {
    napi_status status;
    napi_value fn;

    status = napi_create_function(env, nullptr, 0, ListFilesWrapper, nullptr, &fn);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to create function");
        return nullptr;
    }

    status = napi_set_named_property(env, exports, "listFiles", fn);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to set named property");
        return nullptr;
    }

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
