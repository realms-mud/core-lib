//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    ExpectNotEq("Bob says in tirnosti, `This is a long message that will test how garbled stuff\nshould get when a message is entered'\n",
        Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageWithSpaceInNameCorrectlyParsed()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("high elven", 10);

    ExpectTrue(Player->executeCommand("'-l high elven This is a long message that will test how garbled stuff should get when a message is entered"));
    ExpectEq("You say in high elven, `This is a long message that will test how garbled\nstuff should get when a message is entered'\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HelpForSayDisplaysProperInfo()
{
    Player->pageSize(200);
    ExpectTrue(Player->executeCommand("help say"));
    ExpectEq("[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Help for Say +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;36;1mSynopsis\n"
        "[0;36m	say - Send a message to everyone in your environment\n"
        "[0m\n"
        "[0;36;1mSyntax\n"
        "[0m	[0;36msay [-v(erb) [0;33m<Verb>[0m[0;36m] [-a(dverb) [0;33m<Adverb>[0m[0;36m] [-l(anguage) [0;33m<Language>[0m[0;36m]\n"
        "		[-t(arget) [0;33m<Target>[0m[0;36m] [0;31;1m<Message to speak>\n"
        "		[0m[0m\n"
        "	[0;36m' [-v(erb) [0;33m<Verb>[0m[0;36m] [-a(dverb) [0;33m<Adverb>[0m[0;36m] [-l(anguage) [0;33m<Language>[0m[0;36m]\n"
        "		[-t(arget) [0;33m<Target>[0m[0;36m] [0;31;1m<Message to speak>\n"
        "		[0m[0m\n"
        "[0m[0;36;1mDescription\n"
        "[0;36mSay allows a player to display a message to all players located in the "
        "same\nroom where he or she is standing. The character ' can be used as an\n"
        "abbreviation for say to save time.\n\n"
        "[0m\n"
        "[0;36;1mOptions\n"
        "[0m    [0;36;1m-v [0;33m<Verb>[0m[0m, [0;36;1m-verb [0;33m<Verb>[0m\n"
        "[0m[0;36m	This option will replace the verb displayed as part of the 'say'\n"
        "	message. For example:\n"
        "		[0;37m> say -v grumble I'm grumpy!\n"
        "		[0;32mYou grumble, `I'm grumpy!'[0m\n"
        "	[0;36mOthers users would then see:\n"
        "		[0;32mBob grumbles, `I'm grumpy!'[0m\n"
        "	[0m\n"
        "    [0;36;1m-a [0;33m<Adverb>[0m[0m, [0;36;1m-adverb [0;33m<Adverb>[0m\n"
        "[0m[0;36m	This option will add an adverb to the 'say' message. For example:\n"
        "		[0;37m> say -a sarcastically You're my hero!\n"
        "		[0;32mYou sarcastically say, `You're my hero!'[0m\n"
        "	[0;36mOthers users would then see:\n"
        "		[0;32mBob sarcastically says, `You're my hero!'[0m\n"
        "	[0m\n"
        "    [0;36;1m-l [0;33m<Language>[0m[0m, [0;36;1m-language [0;33m<Language>[0m\n"
        "[0m[0;36m	This option will translate the message you wish to say into the given\n"
        "	language - or at least attempt to do so. Your skill in the target\n"
        "	language will determine whether or not it is translated appropriately or\n"
        "	becomes gibberish. Those in the environment will then use their skill to\n"
        "	translate the message back to English. For example if you have no skill\n"
        "	in a language, you might see:\n"
        "		[0;37m> say -l orcish I should say something nice.\n"
        "		[0;32mYou say in complete gibberish, `Blarg nukuleve zog forgla bup'\n"
        "	[0;36mOthers users would see:\n"
        "		[0;32mBob says in complete gibberish, `Blarg nukuleve zog forgla bup'\n"
        "	[0;36mMeanwhile, if you do know a language you might see:\n"
        "		[0;37m> say -l elven I should say something nice.\n"
        "		[0;32mYou say in elven, `I should say something nice.'\n"
        "	[0;36mOthers users that have a high skill in elven would see:\n"
        "		[0;32mBob says in elven, `I should say something nice.'\n"
        "	[0;36mOthers users that have no skill in elven would see:\n"
        "		[0;32mBob says in elven, `Naur wu simildin welana loomen'\n"
        "	[0;36mIt is important to note that knowledge of a language is a range\n"
        "	and, so too, is one's ability to speak and translate it. You will go\n"
        "	from being able to speak/understand nothing to brokenly speaking or\n"
        "	partially understanding all the way through being completely\n"
        "	fluent.[0;36m\n"
        "	[0m\n"
        "    [0;36;1m-t [0;33m<Target>[0m[0m, [0;36;1m-target [0;33m<Target>[0m\n"
        "[0m[0;36m	This option will allow you to speak a message to a specific target. For\n"
        "	example:\n"
        "		[0;37m> say -t Fred Hi Fred!\n"
        "		[0;32mYou say to Fred, `Hi Fred!'[0m\n"
        "	[0;36mFred would then see:\n"
        "		[0;32mBob says to you, `Hi Fred!'[0m\n"
        "	[0;36mOthers users would then see:\n"
        "		[0;32mBob says to Fred, `Hi Fred!'[0m\n"
        "	[0m\n"
        "[0;36;1mNotes\n"
        "[0;36m	See also: tell, whisper, reply, and shout\n"
        "[0m\n"
        "[0;36;1mCopyright\n"
        "[0;36m	Copyright (C) 1991-2018 Allen Cummings. For additional licensing\n"
        "	information, see http://realmsmud.org/license/ [0m\n",
        Player->caughtMessage());
}
