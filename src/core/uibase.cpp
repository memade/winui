#include "stdafx.h"

namespace local {

 UIBase::UIBase() {

 }

 UIBase::~UIBase() {

 }
 void UIBase::MainProcess() {
  return;
 }
 bool UIBase::NotifyMainCreateEvent() {
  bool result = false;
  /*std::lock_guard<std::mutex> lock{ *m_Mutex };*/
  do {
   if (!m_hUIMainCreateEvent)
    break;
   if (FALSE == ::SetEvent(m_hUIMainCreateEvent))
    break;
   SK_CLOSE_HANDLE(m_hUIMainCreateEvent);
   result = true;
  } while (0);
  return result;
 }

}///namespace local