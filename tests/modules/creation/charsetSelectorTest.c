//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/charsetSelector.c");
    Selector->init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
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

    Selector->initiateSelector(User);
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your character set configuration\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mASCII-only          \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mUnicode             \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 2.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') "
        "where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou can change this value after character creation using the 'set' command.\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ASCIIDescriptionIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 1");
    ExpectEq("\x1b[0;36mThis option sends the user's client only "
        "simple 7-bit ASCII text. It is useful\nif your client "
        "does not support unicode or you are using a screen "
        "reader.\n\x1b[0m", 
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UnicodeDescriptionIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 2");
    ExpectEq("\x1b[0;36mThis option sends the user's client text "
        "with unicode support. Early clients\noften do not "
        "support these characters. If your client supports "
        "this, you\nshould see a skull and crossbones here -> "
        "\xe2\x98\xa0\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UserCharsetIsSetToASCIISelection()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("ascii", User->charsetConfiguration());
}

/////////////////////////////////////////////////////////////////////////////
void UserCharsetIsSetToUnicodeSelection()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("unicode", User->charsetConfiguration());
}
