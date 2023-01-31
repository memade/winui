#if !defined(__03177C9B_846F_4140_BB17_694246088FF9__)
#define __03177C9B_846F_4140_BB17_694246088FF9__

namespace local {

 class UIBase {
 public:
  UIBase();
  virtual ~UIBase();
 protected:
  virtual void MainProcess();
  virtual bool NotifyMainCreateEvent();
 protected:
  std::atomic_bool m_IsOpenUI = false;
  HANDLE m_hUIMain = nullptr;
  HANDLE m_hUIMainCreateEvent = nullptr;
  std::shared_ptr<std::mutex> m_Mutex = std::make_shared<std::mutex>();
 };

}///namespace local

/// /*_ Memade®（新生™） _**/
/// /*_ Tue, 31 Jan 2023 02:08:18 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__03177C9B_846F_4140_BB17_694246088FF9__

