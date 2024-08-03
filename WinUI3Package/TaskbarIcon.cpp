﻿#include "pch.h"
#include "TaskbarIcon.h"
#if __has_include("TaskbarIcon.g.cpp")
#include "TaskbarIcon.g.cpp"
#endif
#include "IconUtils.h"

namespace winrt::WinUI3Package::implementation
{
	WinUI3Package::GeneratedIconSource TaskbarIcon::IconSource()
	{
		return m_iconSource;
	}
	void TaskbarIcon::IconSource(WinUI3Package::GeneratedIconSource value)
	{
		m_iconSource = value;
	}
	void TaskbarIcon::Icon(winrt::Windows::Foundation::Uri value)
	{
		setIconFromUri(value, [this](std::wstring_view path) {getNormalIcon().Icon(Utils::GetHIcon(path)); });
	}
	void TaskbarIcon::IconFile(winrt::hstring const& value)
	{
		getNormalIcon().Icon(Utils::GetHIcon(value));
	}
	WinUI3Package::GeneratedIconSource TaskbarIcon::LightThemeIconSource()
	{
		return WinUI3Package::GeneratedIconSource();
	}
	void TaskbarIcon::LightThemeIconSource(WinUI3Package::GeneratedIconSource value)
	{
	}
	winrt::Windows::Foundation::Uri TaskbarIcon::LightThemeIcon()
	{
		return winrt::Windows::Foundation::Uri(nullptr);
	}
	void TaskbarIcon::LightThemeIcon(winrt::Windows::Foundation::Uri value)
	{
	}
	void TaskbarIcon::LightThemeIconFile(winrt::hstring const& value)
	{
		getThemeAdaptiveIcon().IconLight(Utils::GetHIcon(value));
	}
	WinUI3Package::GeneratedIconSource TaskbarIcon::DarkThemeIconSource()
	{
		return WinUI3Package::GeneratedIconSource();
	}
	void TaskbarIcon::DarkThemeIconSource(WinUI3Package::GeneratedIconSource value)
	{
	}
	winrt::Windows::Foundation::Uri TaskbarIcon::DarkThemeIcon()
	{
		return winrt::Windows::Foundation::Uri(nullptr);
	}
	void TaskbarIcon::DarkThemeIcon(winrt::Windows::Foundation::Uri value)
	{
	}

	void TaskbarIcon::DarkThemeIconFile(winrt::hstring const& value)
	{
		getThemeAdaptiveIcon().IconDark(Utils::GetHIcon(value));
	}

	void TaskbarIcon::Show()
	{
		std::visit([](auto&& arg)
		{
			using IconType = std::remove_reference_t<decltype(arg)>;
			if constexpr (!std::is_same_v<IconType, std::monostate>)
			{
				arg.Show();
			}
		}, m_icon);
	}

	void TaskbarIcon::Remove()
	{
		m_icon.emplace<0>();
	}
	ThemeAdaptiveIcon& TaskbarIcon::getThemeAdaptiveIcon()
	{
		if (m_icon.index() == 0)
			m_icon.emplace<1>();
		return std::get<1>(m_icon);
	}
	NormalTaskbarIcon& TaskbarIcon::getNormalIcon()
	{
		if (m_icon.index() == 0)
			m_icon.emplace<2>();
		return std::get<2>(m_icon);
	}
}
