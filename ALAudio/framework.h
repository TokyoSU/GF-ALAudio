#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files
#include <windows.h>
#include <filesystem>
namespace fs = std::filesystem;

#define FMT_UNICODE 0
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
