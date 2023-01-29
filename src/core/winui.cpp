#include "stdafx.h"

namespace local {
 Winui::Winui() {

 }
 Winui::~Winui() {

 }
 void Winui::Release() const {
  delete this;
 }



 extern Winui* __gpWinui = nullptr;
}///namespace local