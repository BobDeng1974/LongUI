﻿#pragma once
/**
* Copyright (c) 2014-2018 dustpg   mailto:dustpg@gmail.com
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use,
* copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following
* conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/

#include "ui_boxlayout.h"
#include "../core/ui_core_type.h"

// ui namespace
namespace LongUI {
    // menu popup
    class UIMenuPopup;
    // button
    class UIButton : public UIBoxLayout {
        // super class
        using Super = UIBoxLayout;
        // private impl
        struct Private;
    public:
        // min button width
        //enum { MIN_BUTTON_WIDTH = 175 };
        // button type
        enum ButtonType : uint8_t {
            Type_Normal = 0,    // normal type
            Type_Checkbox,      // toggle button
            Type_Radio,         // radio-like button
            Type_Menu,          // menu
        };
        // class meta
        static const  MetaControl   s_meta;
        // dtor
        ~UIButton() noexcept;
        // ctor
        UIButton(UIControl* parent = nullptr) noexcept : UIButton(parent, UIButton::s_meta) {}
    protected:
        // ctor
        UIButton(UIControl* parent, const MetaControl&) noexcept;
    public:
        // on commnad event
        static constexpr auto _onCommand() noexcept { return GuiEvent::Event_OnCommand; }
        // clicked event
        //static inline constexpr auto _clicked() noexcept { return GuiEvent::Event_Click; }
        // checked change event
        //static inline constexpr auto _checkedChanged() noexcept { return GuiEvent::Event_Change; }
    public:
        // click this
        void Click() noexcept;
        // set image source
        void SetImageSource(U8View src) noexcept;
        // get text
        auto GetText() const noexcept ->const char16_t*;
        // get text- string object
        auto GetTextString() const noexcept -> const CUIString&;
        // set text
        void SetText(const CUIString& text) noexcept;
        // set text
        void SetText(CUIString&& text) noexcept;
        // set text
        void SetText(U16View text) noexcept;
        // is checked?
        auto IsChecked() const noexcept { return m_oStyle.state.checked; }
    public:
        // do event
        auto DoEvent(UIControl * sender, const EventArg & e) noexcept->EventAccept override;
        // render
        //void Render() const noexcept override;
        // mouse event
        auto DoMouseEvent(const MouseEventArg& e) noexcept->EventAccept override;
        // input event
        auto DoInputEvent(InputEventArg e) noexcept->EventAccept override;
    protected:
        // add attribute
        void add_attribute(uint32_t key, U8View value) noexcept override;
        // set label flex
        void set_label_flex(float f) noexcept;
        // add private child
        void add_private_child() noexcept;
#ifdef LUI_ACCESSIBLE
    protected:
        // accessible event
        auto accessible(const AccessibleEventArg&) noexcept->EventAccept override;
#endif
        // parse button type
        static auto parse_button_type(U8View) noexcept->ButtonType;
    private:
        // private data
        Private*            m_private = nullptr;
        // group id
        const char*         m_pGroup = nullptr;
    protected:
        // menupopup
        UIMenuPopup*        m_pMenuPopup = nullptr;
        // button type
        ButtonType          m_type = Type_Normal;
        // toolbar button   :<UIToolBarButton>
        bool                m_bToolBar = false;
        // menu button      :<UIMenu>
        bool                m_bMenuBar = false;
        // popup shown
        bool                m_bPopupShown = false;
    };
    // get meta info for UIButton
    LUI_DECLARE_METAINFO(UIButton);
}