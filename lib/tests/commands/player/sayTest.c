//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Player.Name("bob");
    Player.Race("human");
    Player.addCommands();
    Player.colorConfiguration("none");
    move_object(Player, this_object());

    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target.Name("earl");
    Target.Race("human");
    Target.addCommands();
    Target.colorConfiguration("none");
    move_object(Target, this_object());

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander.Name("frank");
    Bystander.Race("human");
    Bystander.addCommands();
    Bystander.colorConfiguration("none");
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
    ExpectTrue(Player.executeCommand("say -ve blah Hi!"));
    ExpectEq("Command failed: The '-ve' flag is not valid.\n",
        Player.caughtMessage());

    ExpectTrue(Player.executeCommand("say -adverbiage blah Hi!"));
    ExpectEq("Command failed: The '-adverbiage' flag is not valid.\n",
        Player.caughtMessage());

    ExpectTrue(Player.executeCommand("say -lan blah Hi!"));
    ExpectEq("Command failed: The '-lan' flag is not valid.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SayWithoutFlagsDisplaysCorrectMessage()
{
    ExpectTrue(Player.executeCommand("say Hi!"));

    ExpectEq("You say, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob says, `Hi!'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SayWithCustomVerbSecondPersonEndingWithSDisplaysCorrectly()
{
    ExpectTrue(Player.executeCommand("say -v growl Hi!"));
    ExpectEq("You growl, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob growls, `Hi!'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SayWithCustomVerbSecondPersonEndingWithEsDisplaysCorrectly()
{
    ExpectTrue(Player.executeCommand("say -v voice Hi!"));
    ExpectEq("You voice, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob voices, `Hi!'\n", Target.caughtMessage());

    ExpectTrue(Player.executeCommand("say -verb profess Hi!"));
    ExpectEq("You profess, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob professes, `Hi!'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SayWithCustomVerbSecondPersonEndingWithYDisplaysCorrectly()
{
    ExpectTrue(Player.executeCommand("say -v imply Hi!"));
    ExpectEq("You imply, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob implies, `Hi!'\n", Target.caughtMessage());

    ExpectTrue(Player.executeCommand("' -v convey Hi!"));
    ExpectEq("You convey, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob conveys, `Hi!'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UsingSingleQuoteWithoutASpaceCorrectlyExecutesCommand()
{
    ExpectTrue(Player.executeCommand("'Hi!"));
    ExpectEq("You say, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob says, `Hi!'\n", Target.caughtMessage());

    ExpectTrue(Player.executeCommand("'-v snort -a derisively Hi!"));
    ExpectEq("You derisively snort, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob derisively snorts, `Hi!'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TargetFlagCorrectlyAppliesTarget()
{
    ExpectTrue(Player.executeCommand("'-t earl Hi!"));
    ExpectEq("You say to Earl, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob says to you, `Hi!'\n", Target.caughtMessage());
    ExpectEq("Bob says to Earl, `Hi!'\n", Bystander.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TargetFlagCorrectlyAppliesTargetWhenNoTargetFound()
{
    ExpectTrue(Player.executeCommand("'-t 'the voices' Hi!"));
    ExpectEq("You say to the voices, `Hi!'\n", Player.caughtMessage());
    ExpectEq("Bob says to the voices, `Hi!'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelZeroCorrectlyApplied()
{
    ExpectTrue(Player.executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectFalse(sizeof(regexp(({ Player.caughtMessage() }),
        "This is a long message that will test how garbled stuff should get when a message is entered")));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }), "complete gibberish")));
    ExpectTrue(sizeof(regexp(({ Target.caughtMessage() }), "complete gibberish")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelTwoCorrectlyApplied()
{
    Player.addSkillPoints(100);
    Player.advanceSkill("elven", 2);
    ExpectTrue(Player.executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }), "gibberish with a hint of elven")));
    ExpectTrue(sizeof(regexp(({ Target.caughtMessage() }), "gibberish with a hint of elven")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelFiveCorrectlyApplied()
{
    Player.addSkillPoints(100);
    Player.advanceSkill("elven", 5);
    ExpectTrue(Player.executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }), "broken elven")));
    ExpectTrue(sizeof(regexp(({ Target.caughtMessage() }), "broken elven")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelEightCorrectlyApplied()
{
    Player.addSkillPoints(100);
    Player.advanceSkill("elven", 8);
    ExpectTrue(Player.executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }), "slightly broken elven")));
    ExpectTrue(sizeof(regexp(({ Target.caughtMessage() }), "slightly broken elven")));
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelTenCorrectlyApplied()
{
    Player.addSkillPoints(100);
    Player.advanceSkill("elven", 10);
    Target.addSkillPoints(100);
    Target.advanceSkill("elven", 4);
    ExpectTrue(Player.executeCommand("'-l elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectEq("You say in elven, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n", 
        Player.caughtMessage());
    ExpectNotEq("Bob says in elven, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n", 
        Target.caughtMessage());
    ExpectTrue(sizeof(regexp(({ Target.caughtMessage() }), "This is a long")));
    ExpectNotEq("Bob says in elven, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Bystander.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageLevelTenCorrectlyUnderstood()
{
    Player.addSkillPoints(100);
    Player.advanceSkill("tirnosti", 10);
    Target.addSkillPoints(100);
    Target.advanceSkill("tirnosti", 10);
    ExpectTrue(Player.executeCommand("'-l tirnosti This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectEq("You say in tirnosti, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Player.caughtMessage());
    ExpectEq("Bob says in tirnosti, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Target.caughtMessage());
    ExpectNotEq("Bob says in tirnosti, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Bystander.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageWithSpaceInNameCorrectlyParsed()
{
    Player.addSkillPoints(100);
    Player.advanceSkill("high elven", 10);

    ExpectTrue(Player.executeCommand("'-l high elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectEq("You say in high elven, `This is a long message that will test how garbled\nstuff should get when a message is entered'\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HelpForSayDisplaysProperInfo()
{
    Player.pageSize(200);
    Player.colorConfiguration("3-bit");

    ExpectTrue(Player.executeCommand("help say"));

    ExpectEq("\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Help for Say +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;36;1mSynopsis\n"
        "\x1b[0m\x1b[0;36m\tsay - Send a message to everyone in your environment\n"
        "\x1b[0m\x1b[0;36;1m\n"
        "Syntax\n"
        "\x1b[0m\t\x1b[0;36msay [-v(erb) \x1b[0m\x1b[0;33m<Verb>\x1b[0m\x1b[0;36m] [-a(dverb) \x1b[0m\x1b[0;36m\x1b[0m\x1b[0;33m<Adverb>\x1b[0m\x1b[0;36m] [-l(anguage)\n"
        "\t\t\x1b[0m\x1b[0;36m\x1b[0m\x1b[0;33m<Language>\x1b[0m\x1b[0;36m] [-t(arget) \x1b[0m\x1b[0;36m\x1b[0m\x1b[0;33m<Target>\x1b[0m\x1b[0;36m] \x1b[0;31;1m<Message to speak>\x1b[0m\n"
        "\t\t\x1b[0m\n"
        "\t\x1b[0;36m' [-v(erb) \x1b[0m\x1b[0;33m<Verb>\x1b[0m\x1b[0;36m] [-a(dverb) \x1b[0m\x1b[0;36m\x1b[0m\x1b[0;33m<Adverb>\x1b[0m\x1b[0;36m] [-l(anguage)\n"
        "\t\t\x1b[0m\x1b[0;36m\x1b[0m\x1b[0;33m<Language>\x1b[0m\x1b[0;36m] [-t(arget) \x1b[0m\x1b[0;36m\x1b[0m\x1b[0;33m<Target>\x1b[0m\x1b[0;36m] \x1b[0;31;1m<Message to speak>\x1b[0m\n"
        "\t\t\x1b[0m\n"
        "\x1b[0;36;1mDescription\n"
        "\x1b[0m\x1b[0;36mSay allows a player to display a message to all players located in the same\n"
        "room where he or she is standing. The character ' can be used as an\n"
        "abbreviation for say to save time. Interactions with players can be blocked\n"
        "using the 'block player' setting.\n"
        "\x1b[0m\x1b[0;36;1m\n"
        "Options\n"
        "\x1b[0m\n"
        "    \x1b[0;36;1m-v \x1b[0m\x1b[0;33m<Verb>\x1b[0m\x1b[0;36;1m\x1b[0m, \x1b[0;36;1m-verb \x1b[0m\x1b[0;33m<Verb>\x1b[0m\x1b[0;36;1m\x1b[0m\n"
        "\t\x1b[0;36mThis option will replace the verb displayed as part of the 'say'\n"
        "\tmessage. For example:\n"
        "\t\t\x1b[0;37m> say -v grumble I'm grumpy!\n"
        "\t\x1b[0m\x1b[0;32m\tYou grumble, `I'm grumpy!'\n"
        "\t\x1b[0m\x1b[0;36mOther users would then see:\n"
        "\t\x1b[0m\x1b[0;32m\tBob grumbles, `I'm grumpy!'\n"
        "\t\x1b[0m\n\t\x1b[0m\n"
        "    \x1b[0;36;1m-a \x1b[0m\x1b[0;33m<Adverb>\x1b[0m\x1b[0;36;1m\x1b[0m, \x1b[0;36;1m-adverb \x1b[0m\x1b[0;33m<Adverb>\x1b[0m\x1b[0;36;1m\x1b[0m\n"
        "\t\x1b[0;36mThis option will add an adverb to the 'say' message. For example:\n"
        "\t\t\x1b[0;37m> say -a sarcastically You're my hero!\n"
        "\t\x1b[0m\x1b[0;32m\tYou sarcastically say, `You're my hero!'\n"
        "\t\x1b[0m\x1b[0;36mOther users would then see:\n"
        "\t\x1b[0m\x1b[0;32m\tBob sarcastically says, `You're my hero!'\n"
        "\t\x1b[0m\n\t\x1b[0m\n"
        "    \x1b[0;36;1m-l \x1b[0m\x1b[0;33m<Language>\x1b[0m\x1b[0;36;1m\x1b[0m, \x1b[0;36;1m-language \x1b[0m\x1b[0;33m<Language>\x1b[0m\x1b[0;36;1m\x1b[0m\n"
        "\t\x1b[0;36mThis option will translate the message you wish to say into the given\n"
        "\tlanguage - or at least attempt to do so. Your skill in the target\n"
        "\tlanguage will determine whether or not it is translated appropriately\n\tor "
        "becomes gibberish. Those in the environment will then use their\n\tskill to "
        "translate the message back to English. For example if you have\n\tno skill "
        "in a language, you might see:\n"
        "\t\t\x1b[0;37m> say -l orcish I should say something nice.\n"
        "\t\x1b[0m\x1b[0;32m\tYou say in complete gibberish, `Blarg nukuleve zog forgla bup'\n"
        "\t\x1b[0m\x1b[0;36mOther users would then see:\n"
        "\t\x1b[0m\x1b[0;32m\tBob says in complete gibberish, `Blarg nukuleve zog forgla bup'\n"
        "\t\x1b[0m\x1b[0;36mMeanwhile, if you do know a language you might see:\n"
        "\t\x1b[0m\x1b[0;37m> say -l elven I should say something nice.\n"
        "\t\x1b[0m\x1b[0;32m\tYou say in elven, `I should say something nice.'\n"
        "\t\x1b[0m\x1b[0;36mOther users that have a high skill in elven would see:\n"
        "\t\x1b[0m\x1b[0;32m\tBob says in elven, `I should say something nice.'\n"
        "\t\x1b[0m\x1b[0;36mOther users that have no skill in elven would see:\n"
        "\t\x1b[0m\x1b[0;32m\tBob says in elven, `Naur wu simildin welana loomen'\n"
        "\t\x1b[0m\x1b[0;36mIt is important to note that knowledge of a language is a "
        "range and, so\n\ttoo, is one's ability to speak and translate it. You will "
        "go from being\n\table to speak/understand nothing to brokenly speaking or "
        "partially\n\tunderstanding all the way through being completely fluent.\n"
        "\t\x1b[0m\n\t\x1b[0m\n"
        "    \x1b[0;36;1m-t \x1b[0m\x1b[0;33m<Target>\x1b[0m\x1b[0;36;1m\x1b[0m, \x1b[0;36;1m-target \x1b[0m\x1b[0;33m<Target>\x1b[0m\x1b[0;36;1m\x1b[0m\n"
        "\t\x1b[0;36mThis option will allow you to speak a message to a specific target. For\n"
        "\texample:\n"
        "\t\t\x1b[0;37m> say -t Fred Hi Fred!\n"
        "\t\x1b[0m\x1b[0;32m\tYou say to Fred, `Hi Fred!'\n"
        "\t\x1b[0m\x1b[0;36mFred would then see:\n"
        "\t\x1b[0m\x1b[0;32m\tBob says to you, `Hi Fred!'\n"
        "\t\x1b[0m\x1b[0;36mOther users would then see:\n"
        "\t\x1b[0m\x1b[0;32m\tBob says to Fred, `Hi Fred!'\n"
        "\t\x1b[0m\n\t\x1b[0m\n"
        "\x1b[0;36;1mNotes\n"
        "\t\x1b[0m\x1b[0;36mSee also: tell, whisper, reply, shout, and set\x1b[0m\x1b[0;36;1m\n"
        "\n"
        "Copyright\n"
        "\x1b[0m\x1b[0;36m\tCopyright (C) 1991-2025 Allen Cummings. For additional licensing\n"
        "\tinformation, see \x1b[0m\x1b[0;36mhttp://realmsmud.org/license/\n"
        "\x1b[0m",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoneColorIsSupported()
{
    Player.colorConfiguration("3-bit");
    ExpectTrue(Player.executeCommand("say Hi!"));

    ExpectEq("\x1b[0;37mYou say, `Hi!'\n\x1b[0m", Player.caughtMessage());
    ExpectEq("Bob says, `Hi!'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThreeBitColorIsSupported()
{
    Target.colorConfiguration("3-bit");
    Player.colorConfiguration("3-bit");
    ExpectTrue(Player.executeCommand("say Hi!"));

    ExpectEq("\x1b[0;37mYou say, `Hi!'\n\x1b[0m", Player.caughtMessage());
    ExpectEq("\x1b[0;37mBob says, `Hi!'\n\x1b[0m", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitColorIsSupported()
{
    Target.colorConfiguration("8-bit");
    Player.colorConfiguration("3-bit");
    ExpectTrue(Player.executeCommand("say Hi!"));

    ExpectEq("\x1b[0;37mYou say, `Hi!'\n\x1b[0m", Player.caughtMessage());
    ExpectEq("\x1b[0;38;5;15mBob says, `Hi!'\n\x1b[0m", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorIsSupported()
{
    Target.colorConfiguration("24-bit");
    Player.colorConfiguration("3-bit");
    ExpectTrue(Player.executeCommand("say Hi!"));

    ExpectEq("\x1b[0;37mYou say, `Hi!'\n\x1b[0m", Player.caughtMessage());
    ExpectEq("\x1b[0;38;2;255;255;255mBob says, `Hi!'\n\x1b[0m", Target.caughtMessage());
}
