// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
static std::shared_ptr<spdlog::logger> m_log = spdlog::basic_logger_mt("ALAudio", "ALAudio.log", true);

// Stub functions for NONAME exports
extern "C" {

    __declspec(dllexport) void Noname_100() {}
    __declspec(dllexport) void Noname_101() {}
    __declspec(dllexport) void Noname_102() {}
    __declspec(dllexport) void Noname_103() {}
    __declspec(dllexport) void Noname_104() {}
    __declspec(dllexport) void Noname_105() {}
    __declspec(dllexport) void Noname_106() {}
    __declspec(dllexport) void Noname_107() {}
    __declspec(dllexport) void Noname_108() {}
    __declspec(dllexport) void Noname_109() {}
    __declspec(dllexport) void Noname_110() {}
    __declspec(dllexport) void Noname_111() {}
    __declspec(dllexport) void Noname_112() {}
    __declspec(dllexport) void Noname_113() {}
    __declspec(dllexport) void Noname_114() {}
    __declspec(dllexport) void Noname_115() {}
    __declspec(dllexport) void Noname_116() {}
    __declspec(dllexport) void Noname_117() {}
    __declspec(dllexport) void Noname_118() {}
    __declspec(dllexport) void Noname_119() {}
    __declspec(dllexport) void Noname_120() {}
    __declspec(dllexport) void Noname_121() {}
    __declspec(dllexport) void Noname_122() {}
    __declspec(dllexport) void Noname_123() {}
    __declspec(dllexport) void Noname_124() {}
    __declspec(dllexport) void Noname_125() {}
    __declspec(dllexport) void Noname_126() {}
    __declspec(dllexport) void Noname_127() {}
    __declspec(dllexport) void Noname_128() {}
    __declspec(dllexport) void Noname_129() {}
    __declspec(dllexport) void Noname_130() {}
    __declspec(dllexport) void Noname_131() {}
    __declspec(dllexport) void Noname_132() {}
    __declspec(dllexport) void Noname_133() {}
    __declspec(dllexport) void Noname_134() {}
    __declspec(dllexport) void Noname_135() {}
    __declspec(dllexport) void Noname_136() {}
    __declspec(dllexport) void Noname_137() {}
    __declspec(dllexport) void Noname_138() {}
    __declspec(dllexport) void Noname_139() {}
    __declspec(dllexport) void Noname_140() {}
    __declspec(dllexport) void Noname_141() {}
    __declspec(dllexport) void Noname_142() {}
    __declspec(dllexport) void Noname_143() {}
    __declspec(dllexport) void Noname_144() {}
    __declspec(dllexport) void Noname_145() {}
    __declspec(dllexport) void Noname_146() {}
    __declspec(dllexport) void Noname_147() {}
    __declspec(dllexport) void Noname_148() {}
    __declspec(dllexport) void Noname_149() {}
    __declspec(dllexport) void Noname_150() {}
    __declspec(dllexport) void Noname_151() {}
    __declspec(dllexport) void Noname_152() {}
    __declspec(dllexport) void Noname_153() {}
    __declspec(dllexport) void Noname_154() {}
    __declspec(dllexport) void Noname_155() {}
    __declspec(dllexport) void Noname_156() {}
    __declspec(dllexport) void Noname_200() {}
    __declspec(dllexport) void Noname_201() {}
    __declspec(dllexport) void Noname_202() {}
    __declspec(dllexport) void Noname_203() {}
    __declspec(dllexport) void Noname_204() {}
    __declspec(dllexport) void Noname_205() {}
    __declspec(dllexport) void Noname_300() {}
    __declspec(dllexport) void Noname_301() {}
    __declspec(dllexport) void Noname_302() {}
    __declspec(dllexport) void Noname_303() {}
    __declspec(dllexport) void Noname_304() {}
    __declspec(dllexport) void Noname_400() {}
    __declspec(dllexport) void Noname_401() {}
    __declspec(dllexport) void Noname_402() {}
    __declspec(dllexport) void Noname_403() {}
    __declspec(dllexport) void Noname_404() {}
    __declspec(dllexport) void Noname_405() {}
    __declspec(dllexport) void Noname_406() {}
    __declspec(dllexport) void Noname_500() {}
    __declspec(dllexport) void Noname_501() {}
    __declspec(dllexport) void Noname_502() {}
    __declspec(dllexport) void Noname_503() {}
    __declspec(dllexport) void Noname_504() {}
    __declspec(dllexport) void Noname_505() {}
    __declspec(dllexport) void Noname_506() {}
    __declspec(dllexport) void Noname_507() {}
    __declspec(dllexport) void Noname_508() {}
    __declspec(dllexport) void Noname_509() {}
    __declspec(dllexport) void Noname_510() {}
    __declspec(dllexport) void Noname_600() {}
    __declspec(dllexport) void Noname_601() {}
    __declspec(dllexport) void Noname_602() {}
    __declspec(dllexport) void Noname_603() {}
    __declspec(dllexport) void Noname_604() {}
    __declspec(dllexport) void Noname_700() {}
    __declspec(dllexport) void Noname_701() {}
    __declspec(dllexport) void Noname_702() {}

} // extern "C"

static bool IsGrandFantasiaProcessExist()
{
    char file_name[MAX_PATH];
    GetModuleFileName(nullptr, file_name, MAX_PATH);
    const char* base_name = strrchr(file_name, '\\');
    base_name = base_name ? base_name + 1 : file_name;
    return strcmp(base_name, "GrandFantasia.exe") == 0;
}

/// <summary>
/// Loads all ASI plugin libraries from the application's module directory and logs the process.
/// </summary>
static void LoadASILibrary()
{
    m_log->info("Loading ASI library...");

    try
    {
        std::filesystem::path modulePath;
        char buffer[MAX_PATH];
        if (GetModuleFileNameA(nullptr, buffer, MAX_PATH))
        {
            modulePath = std::filesystem::path(buffer).parent_path();
        }
        else
        {
            m_log->error("Failed to get module path.");
            return;
        }

        int loadedCount = 0;
        for (const auto& entry : std::filesystem::directory_iterator(modulePath))
        {
            if (entry.is_regular_file() && entry.path().extension() == ".asi")
            {
                m_log->info("Found ASI file: {}", entry.path().string());
                HMODULE hLib = LoadLibraryA(entry.path().string().c_str());
                if (hLib)
                {
                    m_log->info("Loaded ASI: {}", entry.path().filename().string());
                    loadedCount++;
                }
                else
                {
                    m_log->error("Failed to load ASI: {}", entry.path().filename().string());
                }
            }
        }

        if (loadedCount > 0)
        {
            m_log->info("Successfully loaded {} ASI libraries.", loadedCount);
        }
        else
        {
            m_log->info("No ASI libraries were found.");
		}
    }
    catch (const std::exception& ex)
    {
        m_log->error("Exception in LoadASILibrary: {}", ex.what());
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    DisableThreadLibraryCalls(hModule); // Disable thread notifications for performance
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
		m_log->info("DLL loaded.");
        if (IsGrandFantasiaProcessExist())
        {
			m_log->info("Grand Fantasia process detected.");
            LoadASILibrary();
        }
	}
    return TRUE;
}

