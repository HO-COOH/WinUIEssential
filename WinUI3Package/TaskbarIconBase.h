#pragma once
#include "NotifyIconData.h"
#include <string_view>
#include <functional>
#include "PopupMenu.h"
#include "MenuFlyoutWrapper.h"
#include <variant>
#include <optional>
#include <winrt/Microsoft.UI.Xaml.Controls.Primitives.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include "TaskbarIconMessageWindow.h"

struct TaskbarIconXamlEvents;
struct TaskbarIconEvents;

class TaskbarIconBase
{
protected:
	NotifyIconData m_iconData;
	std::variant<std::monostate, MenuFlyoutWrapper, PopupMenu> m_menu;
	TaskbarIconMessageWindow m_messageWindow;
	winrt::Microsoft::UI::Xaml::ElementTheme m_theme{ winrt::Microsoft::UI::Xaml::ElementTheme::Default };
	TaskbarIconXamlEvents* m_ptrXamlEvents{ nullptr };
	TaskbarIconEvents* m_ptrEvents{ nullptr };
	PopupMenu& getPopupMenu();
public:
	TaskbarIconBase();

	constexpr static UINT CallbackMessage = 0x1001;

	TaskbarIconBase& ToolTip(std::wstring_view value);
	
	void Show();
	void Remove();

	void SetMenu(winrt::Microsoft::UI::Xaml::Controls::Primitives::FlyoutBase const& xamlMenu);

	void SetEvents(TaskbarIconXamlEvents& events);

	void SetTheme(winrt::Microsoft::UI::Xaml::ElementTheme theme);

	void OnWM_CONTEXTMENU(WPARAM wparam, LPARAM lparam);
	void OnWM_COMMAND(WPARAM wparam, LPARAM lparam);
	
	~TaskbarIconBase();

	friend class TaskbarIconMessageWindow;
};
