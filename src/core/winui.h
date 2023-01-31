#if !defined(__23837356_F734_4CA6_B497_4A4ADE27CEEF__)
#define __23837356_F734_4CA6_B497_4A4ADE27CEEF__

namespace local {

 class Winui final : public IWinui {
  std::shared_ptr<std::mutex> m_Mutex = std::make_shared<std::mutex>();
 public:
  Winui();
  virtual ~Winui();
 private:
  void Init();
  void UnInit();
 public:
  void Release() const override final;
  IConfig* ConfigGet() const override final;
  IWxui* CreateWxui() const override final;
 private:
  Config* m_pConfig = nullptr;
  IWxui* m_pWxui = nullptr;
 };



 extern Winui* __gpWinui;
 extern HINSTANCE __gpHinstance;
}///namespace local

/// /*_ Memade®（新生™） _**/
/// /*_ Sun, 29 Jan 2023 14:55:39 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__23837356_F734_4CA6_B497_4A4ADE27CEEF__