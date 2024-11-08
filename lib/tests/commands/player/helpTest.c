//*****************************************************************************
// Copyright (c) 2024 -Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.Race("human");
    Player.Gender("male");
    Player.pageSize(200);
    Player.addCommands();
    move_object(Player, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void HelpAsPlayerDisplaysMainHelpMenuWithoutWizardCommands()
{
    ExpectTrue(Player.executeCommand("help"));
    command(" ", Player);
    ExpectSubStringMatch("zing.*General.*save.*Interactions", 
        Player.caughtMessage());
    ExpectFalse(sizeof(regexp(({ Player.caughtMessage() }), "Wizard")));
}

/////////////////////////////////////////////////////////////////////////////
void PagingDisplaysBreakRequiringInput()
{
    Player.pageSize(20);
    ExpectTrue(Player.executeCommand("help"));
    ExpectEq("\x1b[0;35;1m\nMore? [q to quit]\n\x1b[0m", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HelpForSpecificCommandDisplaysCommandInfo()
{
    ExpectTrue(Player.executeCommand("help say"));
    ExpectSubStringMatch("Synopsis.*Syntax.*Description.*Options.*.*Notes", 
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HelpForInvalidCommandReturnsErrorMessageInfo()
{
    ExpectTrue(Player.executeCommand("help this does not exist"));
    ExpectSubStringMatch("No help could be found for 'this does not exist'",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HelpForSpecificCommandAsPlayerDoesNotSHowWizardCommandInfo()
{
    ExpectTrue(Player.executeCommand("help patch"));
    ExpectSubStringMatch("No help could be found for 'patch'",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HelpAsWizardDisplaysMainHelpMenuWithWizardCommands()
{
    object wizard = clone_object("/lib/tests/support/services/mockWizard.c");
    wizard.Name("bob");
    wizard.Race("human");
    wizard.Gender("male");
    wizard.pageSize(200);
    wizard.addCommands();
    move_object(wizard, this_object());

    ExpectTrue(wizard.executeCommand("help"));
    command(" ", wizard);
    ExpectSubStringMatch("zing.*General.*save.*Interactions",
        wizard.caughtMessage());
    ExpectTrue(sizeof(regexp(({ wizard.caughtMessage() }), "Wizard")));

    destruct(wizard);
}

/////////////////////////////////////////////////////////////////////////////
void HelpAsWizardDisplaysSpecificHelpForWizardCommands()
{
    object wizard = clone_object("/lib/tests/support/services/mockWizard.c");
    wizard.Name("bob");
    wizard.Race("human");
    wizard.Gender("male");
    wizard.pageSize(200);
    wizard.addCommands();
    move_object(wizard, this_object());

    ExpectTrue(wizard.executeCommand("help patch"));
    command(" ", wizard);
    ExpectSubStringMatch("Synopsis.*Syntax.*Description.*Options.*.*Notes",
        wizard.caughtMessage());

    destruct(wizard);
}

/////////////////////////////////////////////////////////////////////////////
void HelpCorrectlySpacesTitleDecorator()
{
    Player.colorConfiguration("none");
    ExpectTrue(Player.executeCommand("help"));
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    command(" ", Player);
    ExpectSubStringMatch("| '              guild          party          race           repeat          |\n"
        "| reply          say            shout          talk           talk to         |\n"
        "| tell                                                                        |\n",
        Player.caughtMessage());
}
