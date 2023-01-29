/*===- libcurlpp.hpp - Wrapper for 'extern "C"' ---------------*- C -*-=======*\
|*                                                                                                                        *|
|* Part of the Winui® Project, under the Apache License v2.0 with Winui®          *|
|* Exceptions.                                                                                                      *|
|* See http://skstu.com/winui/LICENSE.txt for license information.                 *|
|* SPDX-License-Identifier: Apache-2.0 WITH WINUI-exception                     *|
|*                                                                                                                        *|
|*===----------------------------------------------------------------------====== *|
|*                                                                                                                        *|
|* This file is a summary of the interface for this project.                                      *|
|*                                                                                                                        *|
\*===----------------------------------------------------------------------======*/
#if !defined(__1E13B074_45D5_49FC_9B06_E6172BC6956A__)
#define __1E13B074_45D5_49FC_9B06_E6172BC6956A__

#include <dllinterface.h>

namespace winui {

 class IWinui : public shared::InterfaceDll<IWinui> {
 public:
  virtual void Release() const = 0;
 };









}///namespace winui

/// /*_ Memade®（新生™） _**/
/// /*_ Sun, 29 Jan 2023 14:51:08 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__1E13B074_45D5_49FC_9B06_E6172BC6956A__
