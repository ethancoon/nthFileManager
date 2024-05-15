#include <filesystem>
#include <string>
#include <vector>
#include <node_api.h>

int main(){

    return 0;
}

std::vector<std::string> listFiles(const std::filesystem::path& directoryPath) {
    std::vector<std::string> files;

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
//        std::string filename = entry.path().filename().string();
//        std::string extension = entry.path().extension().string();
        files.push_back(entry.path().filename().string());
    }

    return files;
}

namespace demo {

    napi_value Method(napi_env env, napi_callback_info args) {
        napi_value greeting;
        napi_status status;

        status = napi_create_string_utf8(env, "world", NAPI_AUTO_LENGTH, &greeting);
        if (status != napi_ok) return nullptr;
        return greeting;
    }

    napi_value init(napi_env env, napi_value exports) {
        napi_status status;
        napi_value fn;

        status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
        if (status != napi_ok) return nullptr;

        status = napi_set_named_property(env, exports, "hello", fn);
        if (status != napi_ok) return nullptr;
        return exports;
    }

    NAPI_MODULE(addon, init)

}