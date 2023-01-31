#include "stdafx.h"

namespace local {
 Winui::Winui() {
  Init();
 }
 Winui::~Winui() {
  UnInit();
 }
 void Winui::Release() const {
  delete this;
 }
 void Winui::Init() {

 }
 void Winui::UnInit() {

 }
 IConfig* Winui::ConfigGet() const {
  std::lock_guard<std::mutex> lock{ *m_Mutex };
  return m_pConfig;
 }
 IWxui* Winui::CreateWxui() const {
  std::lock_guard<std::mutex> lock{ *m_Mutex };
  TypeIdentify identify = shared::Win::Time::TimeStamp<std::chrono::microseconds>();
  return new Wxui(identify);
 }
 extern Winui* __gpWinui = nullptr;
 extern HINSTANCE __gpHinstance = nullptr;
}///namespace local