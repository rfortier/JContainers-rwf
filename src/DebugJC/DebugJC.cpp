#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int main (int argc, const char* argv[])
{
    if (argc != 2)
        return 1;
    auto h = LoadLibraryA (argv[1]);
    if (!h)
        return 2;
    try 
    {
        typedef bool (__cdecl *entry_t) (int, const char**);
        auto entry = (entry_t) GetProcAddress (h, "JC_runTests");
        if (!entry)
            return 4;
        int rc = entry (argc, argv);
        FreeLibrary (h);
        return rc;
    }
    catch (...)
    {
        FreeLibrary (h);
        return 3;
    }
    return 0;
}

