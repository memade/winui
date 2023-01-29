#include <win.h>
#include <winui.hpp>

int main(int argc, char** argv) {
#if defined(_DEBUG)
 ::_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
 //::_CrtSetBreakAlloc(3709);
#endif

 auto pWinui = winui::IWinui::CreateInterface(R"(D:\__Github__\Windows\projects\winui\bin\x64\Debug\winui.dll)");



 shared::Win::MainProcess(
  [&](const std::string& input, bool& exit) {

   if (input == "q") {
    winui::IWinui::DestoryInterface(pWinui);
    exit = true;
   }
  });

 return 0;
}
