//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/colorSelector.c");
    Selector.init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void ColorCreationDisplaysCorrectMenu()
{

    Selector.initiateSelector(User);
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your color configuration\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mNo color support    \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m3-bit (8 colors)    \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32m8-bit (256 colors)  \x1b[0m\n"
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;32m24-bit (true color) \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mGrayscale (26 colors)\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 5.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') "
        "where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou can change this value after character creation using the 'set' command.\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoneDescriptionIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 1");
    ExpectEq("\x1b[0;36mThis option sends the user's client only simple text "
        "without ASNI colors via\nescape characters. It is useful if your "
        "client does not support colors or you\nare using a screen reader.\n"
        "\x1b[0m", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThreeBitDescriptionIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 2");
    ExpectEq("\x1b[0;36mThis option sends the user's client text "
        "with basic ASNI color support for\neight colors. Early "
        "clients often only supported these colors. \x1b[0;32mIf "
        "your client\nsupports this, you should see this message "
        "in green.\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitDescriptionIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 3");
    ExpectEq("\x1b[0;36mThis option sends the user's client text "
        "with basic ASNI color support for\n256 colors. Many "
        "modern clients support these colors. \x1b[0;38;5;30mIf "
        "your client supports\nthis, you should see this message "
        "in turquoise.\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitDescriptionIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 4");
    ExpectEq("\x1b[0;36mThis option sends the user's client text "
        "with basic ASNI color support for\n16,777,216 colors. Some "
        "modern clients support these colors, but many do not.\n"
        "\x1b[0;38;2;0;95;135mIf your client supports this, you "
        "should see this message in blue-green.\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrayscaleDescriptionIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 5");
    ExpectEq("\x1b[0;36mThis option sends the user's client text "
        "with basic ASNI color support for 26\ngrayscale colors. Some "
        "modern clients support these colors, but many do not.\n"
        "\x1b[0;38;5;240mIf your client supports this, you "
        "should see this message in medium gray.\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UserColorIsSetToNoneSelection()
{
    Selector.initiateSelector(User);
    Selector.applySelection("1");
    ExpectEq("none", User.colorConfiguration());
}

/////////////////////////////////////////////////////////////////////////////
void UserColorIsSetToThreeBitSelection()
{
    Selector.initiateSelector(User);
    Selector.applySelection("2");
    ExpectEq("3-bit", User.colorConfiguration());
}

/////////////////////////////////////////////////////////////////////////////
void UserColorIsSetToEightBitSelection()
{
    Selector.initiateSelector(User);
    Selector.applySelection("3");
    ExpectEq("8-bit", User.colorConfiguration());
}

/////////////////////////////////////////////////////////////////////////////
void UserColorIsSetToTwentyFourBitSelection()
{
    Selector.initiateSelector(User);
    Selector.applySelection("4");
    ExpectEq("24-bit", User.colorConfiguration());
}
