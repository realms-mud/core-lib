//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Target;
object Bystander;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Race("human");
    Player->addCommands();
    move_object(Player, this_object());

    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target->Name("earl");
    Target->Race("human");
    Target->addCommands();
    move_object(Target, this_object());

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander->Name("frank");
    Bystander->Race("human");
    Bystander->addCommands();
    move_object(Bystander, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Target);
    destruct(Bystander);
}

/////////////////////////////////////////////////////////////////////////////
void InvalidFlagsDoNotParse()
{
    ExpectTrue(Player->executeCommand("say -ve blah Hi!"));
    ExpectEq("Command failed: The '-ve' flag is not valid.\n",
        Player->caughtMessage());

    ExpectTrue(Player->executeCommand("say -adverbiage blah Hi!"));
    ExpectEq("Command failed: The '-adverbiage' flag is not valid.\n",
        Player->caughtMessage());

    ExpectTrue(Player->executeCommand("say -lan blah Hi!"));
    ExpectEq("Command failed: The '-lan' flag is not valid.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SayWithoutFlagsDisplaysCorrectMessage()
{
    ExpectTrue(Player->executeCommand("say Hi!"));

    ExpectEq("You say, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob says, `Hi!'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SayWithCustomVerbSecondPersonEndingWithSDisplaysCorrectly()
{
    ExpectTrue(Player->executeCommand("say -v growl Hi!"));
    ExpectEq("You growl, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob growls, `Hi!'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SayWithCustomVerbSecondPersonEndingWithEsDisplaysCorrectly()
{
    ExpectTrue(Player->executeCommand("say -v voice Hi!"));
    ExpectEq("You voice, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob voices, `Hi!'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("say -verb profess Hi!"));
    ExpectEq("You profess, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob professes, `Hi!'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SayWithCustomVerbSecondPersonEndingWithYDisplaysCorrectly()
{
    ExpectTrue(Player->executeCommand("say -v imply Hi!"));
    ExpectEq("You imply, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob implies, `Hi!'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("' -v convey Hi!"));
    ExpectEq("You convey, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob conveys, `Hi!'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UsingSingleQuoteWithoutASpaceCorrectlyExecutesCommand()
{
    ExpectTrue(Player->executeCommand("'Hi!"));
    ExpectEq("You say, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob says, `Hi!'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("'-v snort -a derisively Hi!"));
    ExpectEq("You derisively snort, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob derisively snorts, `Hi!'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TargetFlagCorrectlyAppliesTarget()
{
    ExpectTrue(Player->executeCommand("'-t earl Hi!"));
    ExpectEq("You say to Earl, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob says to you, `Hi!'\n", Target->caughtMessage());
    ExpectEq("Bob says to Earl, `Hi!'\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TargetFlagCorrectlyAppliesTargetWhenNoTargetFound()
{
    ExpectTrue(Player->executeCommand("'-t 'the voices' Hi!"));
    ExpectEq("You say to the voices, `Hi!'\n", Player->caughtMessage());
    ExpectEq("Bob says to the voices, `Hi!'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelZeroCorrectlyApplied()
{
    ExpectTrue(Player->executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectFalse(sizeof(regexp(({ Player->caughtMessage() }),
        "This is a long message that will test how garbled stuff should get when a message is entered")));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "complete gibberish")));
    ExpectTrue(sizeof(regexp(({ Target->caughtMessage() }), "complete gibberish")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelTwoCorrectlyApplied()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("elven", 2);
    ExpectTrue(Player->executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "gibberish with a hint of elven")));
    ExpectTrue(sizeof(regexp(({ Target->caughtMessage() }), "gibberish with a hint of elven")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelFiveCorrectlyApplied()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("elven", 5);
    ExpectTrue(Player->executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "broken elven")));
    ExpectTrue(sizeof(regexp(({ Target->caughtMessage() }), "broken elven")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelEightCorrectlyApplied()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("elven", 8);
    ExpectTrue(Player->executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "slightly broken elven")));
    ExpectTrue(sizeof(regexp(({ Target->caughtMessage() }), "slightly broken elven")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelTenCorrectlyApplied()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("elven", 10);
    Target->addSkillPoints(100);
    Target->advanceSkill("elven", 4);
    ExpectTrue(Player->executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectEq("You say in elven, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n", 
        Player->caughtMessage());
    ExpectNotEq("Bob says in elven, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n", 
        Target->caughtMessage());
    ExpectTrue(sizeof(regexp(({ Target->caughtMessage() }), "This is a long")));
    ExpectNotEq("Bob says in elven, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelTenCorrectlyUnderstood()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("tirnosti", 10);
    Target->addSkillPoints(100);
    Target->advanceSkill("tirnosti", 10);
    ExpectTrue(Player->executeCommand("'-l tirnosti This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectEq("You say in tirnosti, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Player->caughtMessage());
    ExpectEq("Bob says in tirnosti, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Target->caughtMessage());
    ExpectNotEq("Bob says in tirnosti, `This is a long message that will test how garbled stuff\n should get when a message is entered'\n",
        Bystander->caughtMessage());
}