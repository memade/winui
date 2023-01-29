#include "stdafx.h"
#include "export.h"

__shared_api_ void* __stdcall api_object_init(const void*, unsigned long) {
 void* result = nullptr;
 do {
  local::__gpWinui = new local::Winui();
  if (!local::__gpWinui)
   break;
  result = local::__gpWinui;
 } while (0);
 return result;
}

__shared_api_ void __stdcall api_object_uninit() {
 if (local::__gpWinui)
  local::__gpWinui->Release();
 local::__gpWinui = nullptr;
}

