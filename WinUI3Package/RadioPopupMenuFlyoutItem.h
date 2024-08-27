﻿#pragma once

#include "PopupMenuFlyoutItem.h"
#include "RadioPopupMenuFlyoutItem.g.h"

namespace winrt::WinUI3Package::implementation
{
    struct RadioPopupMenuFlyoutItem : RadioPopupMenuFlyoutItemT<RadioPopupMenuFlyoutItem, PopupMenuFlyoutItem>
    {
        RadioPopupMenuFlyoutItem() = default;

#pragma region Inheirted from PopupMenuFlyoutItemBase
        winrt::WinUI3Package::PopupMenuFlyoutItemType Type();
#pragma endregion

        bool IsChecked();
        void IsChecked(bool value);
        static winrt::Microsoft::UI::Xaml::DependencyProperty IsCheckedProperty();

        winrt::hstring GroupName();
        void GroupName(winrt::hstring const& value);
        static winrt::Microsoft::UI::Xaml::DependencyProperty GroupNameProperty();
    private:
        static winrt::Microsoft::UI::Xaml::DependencyProperty s_isCheckedProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty s_groupNameProperty;
    };
}

namespace winrt::WinUI3Package::factory_implementation
{
    struct RadioPopupMenuFlyoutItem : RadioPopupMenuFlyoutItemT<RadioPopupMenuFlyoutItem, implementation::RadioPopupMenuFlyoutItem>
    {
    };
}