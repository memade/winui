#include "stdafx.h"

namespace local {
 Wxui::Wxui(const TypeIdentify& identify) : m_Identify(identify) {

 }
 Wxui::~Wxui() {

 }
 void Wxui::Release() const {
  delete this;
 }
 bool Wxui::Start() {
  std::lock_guard<std::mutex> lock{ *m_Mutex };
  do {
#if 0
   INITCOMMONCONTROLSEX icc = { 0 };
   icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
   icc.dwICC = ICC_WIN95_CLASSES;
   if (FALSE == ::InitCommonControlsEx(&icc))
    break;
#endif
   if (m_IsOpenUI.load())
    break;
   if (!__gpHinstance)
    break;
   m_hUIMain = reinterpret_cast<HANDLE>(::_beginthreadex(NULL, 0,
    [](void* param)->UINT {
     Wxui* pThis = reinterpret_cast<Wxui*>(param);
     pThis->MainProcess();
     return 0;
    }, this, 0, NULL));
   ::WaitForSingleObject(m_hUIMainCreateEvent, INFINITE);
   m_IsOpenUI.store(true);
  } while (0);
  return m_IsOpenUI.load();
 }
 void Wxui::Stop() {
  std::lock_guard<std::mutex> lock{ *m_Mutex };
  do {
   if (!m_IsOpenUI.load())
    break;
   ::SendMessageW(shared::GlobalWindowConfigGet()->hMain, WM_CLOSE, 0, 0);
   ::WaitForSingleObject(m_hUIMain, INFINITE);
   m_IsOpenUI.store(false);
  } while (0);
 }
 const TypeIdentify& Wxui::Identify() const {
  std::lock_guard<std::mutex> lock{ *m_Mutex };
  return m_Identify;
 }
 void Wxui::MainProcess() {
  do {
   if (!__gpHinstance)
    break;
   wxDISABLE_DEBUG_SUPPORT();
   wxInitializer wxinit;
   if (!wxinit.IsOk())
    break;
   auto app = wxDynamicCast(wxApp::GetInstance(), shared::wx::IwxApp);
   app->RegisterAppCreateFrameEventCb(
    [&](wxFrame* frame) {
     frame->SetSize(100, 100);
   auto theFrame = wxDynamicCast(frame, shared::wx::IwxFrameSkin);

   auto theme0 = new shared::wx::Theme("0", R"(C:\Users\k34ub\Desktop\theme\2\shape.png)", R"(C:\Users\k34ub\Desktop\theme\2\bgk.png)");
   auto theme1 = new shared::wx::Theme("1", R"(C:\Users\k34ub\Desktop\theme\GodOfWealth.png)", R"(C:\Users\k34ub\Desktop\theme\GodOfWealth.png)");
   theFrame->AppendTheme(theme0);
   theFrame->AppendTheme(theme1);
   theFrame->SetTheme();
   theFrame->Center();
   //frame->SetBackgroundColour(wxColour(RGB(0, 0, 0)));
   NotifyMainCreateEvent();
    });
   auto frame = new shared::wx::IwxFrameSkin(nullptr);
   wxThreadEvent* event = new wxThreadEvent(wxEVT_THREAD, shared::wx::WX_CMD_ONAPPCREATEFRAME);
   event->SetEventObject(frame);
   event->SetString("Hello wxWidgets!");
   wxQueueEvent(wxApp::GetInstance(), event);
   wxEntry(__gpHinstance);
  } while (0);
 }
}///namespace local