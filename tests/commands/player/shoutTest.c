//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Player->reset();
    Player->colorConfiguration("none");

    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target->Name("earl");
    Target->Race("human");
    Target->reset();
    Target->colorConfiguration("none");

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander->Name("frank");
    Bystander->Race("human");
    Bystander->reset();
    Bystander->colorConfiguration("none");

    setUsers(({ Player, Target, Bystander }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Target);
    destruct(Bystander);
}

/////////////////////////////////////////////////////////////////////////////
void ShoutSendsMessageToAllPeople()
{
    ExpectTrue(Player->executeCommand("shout Hello"));
    ExpectEq("You shout, `Hello'\n", Player->caughtMessage());
    ExpectEq("Bob shouts, `Hello'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShoutSendsToInitiatorEvenWhenEarmuffed()
{
    Player->executeCommand("set -p earmuffs -v on");
    ExpectTrue(Player->executeCommand("shout Hello"));
    ExpectEq("You shout, `Hello'\n", Player->caughtMessage());
    ExpectEq("Bob shouts, `Hello'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShoutDoesNotSendToEarmuffedUser()
{
    Target->executeCommand("set -p earmuffs -v on");
    Target->resetCatchList();
    ExpectTrue(Player->executeCommand("shout Hello"));
    ExpectEq("You shout, `Hello'\n", Player->caughtMessage());
    ExpectFalse(Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShoutHandlesTheAdverbFlag()
{
    ExpectTrue(Player->executeCommand("shout -a adroitly Hello"));
    ExpectEq("You adroitly shout, `Hello'\n", Player->caughtMessage());
    ExpectEq("Bob adroitly shouts, `Hello'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShoutHandlesTheVerbFlagWHereVerbShouldEndInS()
{
    ExpectTrue(Player->executeCommand("shout -v taunt Hello"));
    ExpectEq("You taunt, `Hello'\n", Player->caughtMessage());
    ExpectEq("Bob taunts, `Hello'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShoutHandlesTheVerbFlagWHereVerbShouldEndInEs()
{
    ExpectTrue(Player->executeCommand("shout -v decry Hello"));
    ExpectEq("You decry, `Hello'\n", Player->caughtMessage());
    ExpectEq("Bob decries, `Hello'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShoutHandlesTheLanguageFlag()
{
    ExpectTrue(Player->executeCommand("shout -v taunt Hello"));
    ExpectEq("You taunt, `Hello'\n", Player->caughtMessage());
    ExpectEq("Bob taunts, `Hello'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelZeroCorrectlyApplied()
{
    ExpectTrue(Player->executeCommand("shout -l elven This is a long message that will test how garbled stuff should get when a message is entered"));
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
    ExpectTrue(Player->executeCommand("shout -l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "gibberish with a hint of elven")));
    ExpectTrue(sizeof(regexp(({ Target->caughtMessage() }), "gibberish with a hint of elven")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelFiveCorrectlyApplied()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("elven", 5);
    ExpectTrue(Player->executeCommand("shout -l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "broken elven")));
    ExpectTrue(sizeof(regexp(({ Target->caughtMessage() }), "broken elven")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelEightCorrectlyApplied()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("elven", 8);
    ExpectTrue(Player->executeCommand("shout -l elven This is a long message that will test how garbled stuff should get when a message is entered"));
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
    ExpectTrue(Player->executeCommand("shout -l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectEq("You shout in elven, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Player->caughtMessage());
    ExpectNotEq("Bob shouts in elven, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Target->caughtMessage());
    ExpectTrue(sizeof(regexp(({ Target->caughtMessage() }), "This is a long")));
    ExpectNotEq("Bob shouts in elven, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelTenCorrectlyUnderstood()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("tirnosti", 10);
    Target->addSkillPoints(100);
    Target->advanceSkill("tirnosti", 10);
    ExpectTrue(Player->executeCommand("shout -l tirnosti This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectEq("You shout in tirnosti, `This is a long message that will test how garbled\nstuff should get when a message is entered'\n",
        Player->caughtMessage());
    ExpectEq("Bob shouts in tirnosti, `This is a long message that will test how garbled\nstuff should get when a message is entered'\n",
        Target->caughtMessage());
    ExpectNotEq("Bob shouts in tirnosti, `This is a long message that will test how garbled\nstuff should get when a message is entered'\n",
        Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageWithSpaceInNameCorrectlyParsed()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("high elven", 10);

    ExpectTrue(Player->executeCommand("shout -l high elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectEq("You shout in high elven, `This is a long message that will test how garbled\nstuff should get when a message is entered'\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoneColorIsSupported()
{
    Player->colorConfiguration("3-bit");
    ExpectTrue(Player->executeCommand("shout Hello"));
    ExpectEq("\x1b[0;35mYou shout, `Hello'\n\x1b[0m", Player->caughtMessage());
    ExpectEq("Bob shouts, `Hello'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThreeBitColorIsSupported()
{
    Target->colorConfiguration("3-bit");
    Player->colorConfiguration("3-bit");
    ExpectTrue(Player->executeCommand("shout Hello"));
    ExpectEq("\x1b[0;35mYou shout, `Hello'\n\x1b[0m", Player->caughtMessage());
    ExpectEq("\x1b[0;35mBob shouts, `Hello'\n\x1b[0m", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitColorIsSupported()
{
    Target->colorConfiguration("8-bit");
    Player->colorConfiguration("3-bit");
    ExpectTrue(Player->executeCommand("shout Hello"));
    ExpectEq("\x1b[0;35mYou shout, `Hello'\n\x1b[0m", Player->caughtMessage());
    ExpectEq("\x1b[0;38;5;112mBob shouts, `Hello'\n\x1b[0m", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorIsSupported()
{
    Target->colorConfiguration("24-bit");
    Player->colorConfiguration("3-bit");
    ExpectTrue(Player->executeCommand("shout Hello"));
    ExpectEq("\x1b[0;35mYou shout, `Hello'\n\x1b[0m", Player->caughtMessage());
    ExpectEq("\x1b[0;38;2;190;90;190mBob shouts, `Hello'\n\x1b[0m", Target->caughtMessage());
}
