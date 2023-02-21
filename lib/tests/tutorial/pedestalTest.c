//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Pedestal;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("Gorthaur");
    Player.addCommands();

    Pedestal = clone_object("/tutorial/temple/objects/pedestal.c");
    move_object(Player, this_object());
    move_object(Pedestal, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Pedestal);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void NothingHappensWhenPlatePressedAndNoTestActive()
{
    command("press envy", Player);
    ExpectSubStringMatch("Nothing happens", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanPressPlateWhenTestActive()
{
    Pedestal.startFirstTest();
    command("press envy", Player);
    ExpectSubStringMatch("The orbs of energy atop the pedestals swirl", 
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanResetPlates()
{
    Pedestal.startFirstTest();
    command("press envy", Player);

    string platePressed = Player.caughtMessage();

    command("press death", Player);
    ExpectNotEq(platePressed, Player.caughtMessage());
    ExpectSubStringMatch("@.*@.*@.*@", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCompleteFirstTest()
{
    Pedestal.startFirstTest();
    command("press envy", Player);
    ExpectSubStringMatch("B.*B.*B.*@", Player.caughtMessage());

    command("press envy", Player);
    ExpectSubStringMatch("G.*G.*G.*@", Player.caughtMessage());

    command("press envy", Player);
    ExpectSubStringMatch("R.*R.*R.*@", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("R.*W.*W.*B", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("R.*B.*B.*G", Player.caughtMessage());

    command("press wrath", Player);
    ExpectSubStringMatch("W.*G.*B.*R", 
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);

    ExpectSubStringMatch("The liquid surrounding the passage way widens, allowing safe passage",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCompleteSecondTest()
{
    Pedestal.startSecondTest();
    command("press envy", Player);
    ExpectSubStringMatch("B.*B.*B.*@", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("B.*G.*G.*B", Player.caughtMessage());

    command("press sorrow", Player);
    ExpectSubStringMatch("G.*G.*R.*G", Player.caughtMessage());

    command("press wrath", Player);
    ExpectSubStringMatch("R.*R.*R.*R",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);

    ExpectSubStringMatch("The liquid surrounding the passage way widens, allowing safe passage",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCompleteThirdTest()
{
    Pedestal.startThirdTest();
    command("press envy", Player);
    ExpectSubStringMatch("B.*B.*B.*@", Player.caughtMessage());

    command("press envy", Player);
    ExpectSubStringMatch("G.*G.*G.*@", Player.caughtMessage());

    command("press envy", Player);
    ExpectSubStringMatch("R.*R.*R.*@", Player.caughtMessage());

    command("press envy", Player);
    ExpectSubStringMatch("W.*W.*W.*@", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("W.*B.*B.*B", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("W.*G.*G.*G", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("W.*R.*R.*R", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("W.*W.*W.*W",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);

    ExpectSubStringMatch("The liquid surrounding the passage way widens, allowing safe passage",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCompleteFourthTest()
{
    Pedestal.startFourthTest();
    command("press envy", Player);
    ExpectSubStringMatch("B.*B.*B.*@", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("B.*G.*G.*B", Player.caughtMessage());

    command("press sorrow", Player);
    ExpectSubStringMatch("G.*G.*R.*G", Player.caughtMessage());

    command("press wrath", Player);
    ExpectSubStringMatch("R.*R.*R.*R", Player.caughtMessage());

    command("press envy", Player);
    ExpectSubStringMatch("W.*W.*W.*R", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("W.*B.*B.*W", Player.caughtMessage());

    command("press sorrow", Player);
    ExpectSubStringMatch("B.*B.*G.*B", Player.caughtMessage());

    command("press wrath", Player);
    ExpectSubStringMatch("G.*G.*G.*G",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);

    ExpectSubStringMatch("The liquid surrounding the passage way widens, allowing safe passage",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCompleteFifthTest()
{
    Pedestal.startFifthTest();
    command("press sorrow", Player);
    ExpectSubStringMatch("B.*@.*B.*B", Player.caughtMessage());

    command("press wrath", Player);
    ExpectSubStringMatch("G.*B.*B.*G",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);

    ExpectSubStringMatch("The liquid surrounding the passage way widens, allowing safe passage",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCompleteSixthTest()
{
    Pedestal.startSixthTest();
    command("press envy", Player);
    ExpectSubStringMatch("B.*B.*B.*@", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("B.*G.*G.*B",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);

    ExpectSubStringMatch("The liquid surrounding the passage way widens, allowing safe passage",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCompleteSeventhTest()
{
    Pedestal.startSeventhTest();
    command("press fear", Player);
    ExpectSubStringMatch("@.*B.*B.*B", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("@.*G.*G.*G", Player.caughtMessage());

    command("press fear", Player);
    ExpectSubStringMatch("@.*R.*R.*R", Player.caughtMessage());

    command("press wrath", Player);
    ExpectSubStringMatch("B.*W.*R.*W", Player.caughtMessage());

    command("press wrath", Player);
    ExpectSubStringMatch("G.*B.*R.*B", Player.caughtMessage());

    command("press envy", Player);
    ExpectSubStringMatch("R.*G.*W.*B",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);

    ExpectSubStringMatch("The liquid surrounding the passage way widens, allowing safe passage",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeUnicodeCharacters()
{
    Player.charsetConfiguration("unicode");
    Pedestal.startFirstTest();
    command("press envy", Player);
    ExpectSubStringMatch("\u229b.*\u229b.*\u229b.*\u229b", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeNoColors()
{
    Player.colorConfiguration("none");
    Pedestal.startFirstTest();
    command("press envy", Player);
    ExpectSubStringMatch("[ \t\n]+B[ \t\n]+B[ \t\n]+B[ \t\n]+@", 
        Player.caughtMessage());

    command("press envy", Player);
    command("press envy", Player);
    command("press fear", Player);
    command("press fear", Player);

    command("press wrath", Player);
    ExpectSubStringMatch("[ \t\n]+W[ \t\n]+G[ \t\n]+B[ \t\n]+R",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeThreeBitColors()
{
    Player.colorConfiguration("3-bit");
    Pedestal.startFirstTest();
    command("press envy", Player);
    ExpectSubStringMatch("0;34;1mB.*0;34;1mB.*0;34;1mB.*0;35;6m@", 
        Player.caughtMessage());

    command("press envy", Player);
    command("press envy", Player);
    command("press fear", Player);
    command("press fear", Player);

    command("press wrath", Player);
    ExpectSubStringMatch("0;37;1mW.*0;32;1mG.*0;34;1mB.*0;31;1mR",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeEightBitColors()
{
    Player.colorConfiguration("8-bit");
    Pedestal.startFirstTest();
    command("press envy", Player);
    ExpectSubStringMatch("0;38;5;20;1mB.*0;38;5;20;1mB.*0;38;5;20;1mB.*0;38;5;244;1m@",
        Player.caughtMessage());

    command("press envy", Player);
    command("press envy", Player);
    command("press fear", Player);
    command("press fear", Player);

    command("press wrath", Player);
    ExpectSubStringMatch("0;38;5;15;1mW.*0;38;5;28;1mG.*0;38;5;20;1mB.*0;38;5;124;1mR",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeTwentyFourBitColors()
{
    Player.colorConfiguration("24-bit");
    Pedestal.startFirstTest();
    command("press envy", Player);
    ExpectSubStringMatch("0;38;2;0;0;220;1mB.*0;38;2;0;0;220;1mB.*"
        "0;38;2;0;0;220;1mB.*0;38;2;120;120;120;1m@",
        Player.caughtMessage());

    command("press envy", Player);
    command("press envy", Player);
    command("press fear", Player);
    command("press fear", Player);

    command("press wrath", Player);
    ExpectSubStringMatch("0;38;2;255;255;255;1mW.*0;38;2;0;180;0;1mG.*"
        "0;38;2;0;0;220;1mB.*0;38;2;180;0;0;1mR",
        Player.caughtMessages()[sizeof(Player.caughtMessages()) - 2]);
}
