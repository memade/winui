#if !defined(__FCE0DC7C_E36A_4F5B_B03E_880301C87C4A__)
#define __FCE0DC7C_E36A_4F5B_B03E_880301C87C4A__

#include <wxskin.h>

namespace local {

 class Wxui final : public IWxui , public UIBase {
 public:
  Wxui(const TypeIdentify&);
  virtual ~Wxui();
 public:
  const TypeIdentify& Identify() const override final;
  bool Start() override final;
  void Stop() override final;
  void Release() const override final;
 protected:
  void MainProcess() override final;
 protected:
  TypeIdentify m_Identify = 0;
 private:
  shared::wx::Theme* m_pTheme1 = nullptr;
  shared::wx::Theme* m_pTheme2 = nullptr;
 };

}///namespace local

/// /*_ Memade®（新生™） _**/
/// /*_ Mon, 30 Jan 2023 04:19:24 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__FCE0DC7C_E36A_4F5B_B03E_880301C87C4A__

