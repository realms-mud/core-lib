//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Target;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.Race("human");
    Player.create();

    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target.Name("earl");
    Target.Race("human");
    Target.create();

    setUsers(({ Player, Target }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Target);
}

/////////////////////////////////////////////////////////////////////////////
void TellSendsCorrectMessageToCorrectPerson()
{
    ExpectTrue(Player.executeCommand("tell earl Hello"));
    ExpectSubStringMatch("You tell Earl, `Hello'\n", Player.caughtMessage());
    ExpectSubStringMatch("Bob tells you, `Hello'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TellWithoutMessageFails()
{
    ExpectFalse(Player.executeCommand("tell earl"));
    ExpectFalse(Player.caughtMessage());
    ExpectFalse(Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TellToNonexistantPersonFails()
{
    ExpectFalse(Player.executeCommand("tell fred Hi"));
    ExpectFalse(Player.caughtMessage());
    ExpectFalse(Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TellTForLongMessageCorrectlyFormatsText()
{
    ExpectTrue(Player.executeCommand("tell earl Hi. This is a really long message, Earl. I think that radishes are a bit too red and cabbage really doesn't exist. Just try to prove me wrong."));
    ExpectSubStringMatch("You tell Earl, `Hi. This is a really long message, Earl. I think that radishes\nare a bit too red and cabbage really doesn't exist. Just try to prove me\nwrong.'\n",
        Player.caughtMessage());
    ExpectSubStringMatch("Bob tells you, `Hi. This is a really long message, Earl. I think that radishes\nare a bit too red and cabbage really doesn't exist. Just try to prove me\nwrong.'\n",
        Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ReplyFailsIfNobodyToRespondTo()
{
    ExpectFalse(Player.executeCommand("reply I respond"));
    ExpectFalse(Player.caughtMessage());
    ExpectFalse(Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ReplyRespondsToPreviousTeller()
{
    ExpectTrue(Player.executeCommand("tell earl Hello"));
    ExpectTrue(Target.executeCommand("reply Hi"));
    ExpectSubStringMatch("Earl replies to you, `Hi'\n", Player.caughtMessage());
    ExpectSubStringMatch("You reply to Bob, `Hi'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TellBeforeResponseClearsReplyTo()
{
    ExpectTrue(Player.executeCommand("tell earl Hello"));
    ExpectTrue(Target.executeCommand("tell bob Hi"));
    ExpectFalse(Target.executeCommand("reply Hi"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSendTellWhenBlocked()
{
    ExpectTrue(Player.block("earl"));
    Player.resetCatchList();
    ExpectTrue(Target.executeCommand("tell bob Hello"));
    ExpectEq("\x1b[0;31;1mYour message was not sent. You have been blocked by Bob.\n\x1b[0m", Target.caughtMessage());
    ExpectFalse(Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSendTellWhenTargetBusy()
{
    Target.setBusy("on");
    Target.resetCatchList();
    ExpectTrue(Player.executeCommand("tell earl Hello"));
    ExpectEq("\x1b[0;31;1mYour message was not sent. Earl has its status set to busy.\n\x1b[0m", Player.caughtMessage());
    ExpectFalse(Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoneColorIsSupported()
{
    Target.colorConfiguration("none");
    ExpectTrue(Player.executeCommand("tell earl Hello"));
    ExpectEq("\x1b[0;35mYou tell Earl, `Hello'\n\x1b[0m", Player.caughtMessage());
    ExpectEq("Bob tells you, `Hello'\n", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThreeBitColorIsSupported()
{
    Target.colorConfiguration("3-bit");
    ExpectTrue(Player.executeCommand("tell earl Hello"));
    ExpectEq("\x1b[0;35mYou tell Earl, `Hello'\n\x1b[0m", Player.caughtMessage());
    ExpectEq("\x1b[0;35mBob tells you, `Hello'\n\x1b[0m", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitColorIsSupported()
{
    Target.colorConfiguration("8-bit");
    ExpectTrue(Player.executeCommand("tell earl Hello"));
    ExpectEq("\x1b[0;35mYou tell Earl, `Hello'\n\x1b[0m", Player.caughtMessage());
    ExpectEq("\x1b[0;38;5;112mBob tells you, `Hello'\n\x1b[0m", Target.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorIsSupported()
{
    Target.colorConfiguration("24-bit");
    ExpectTrue(Player.executeCommand("tell earl Hello"));
    ExpectEq("\x1b[0;35mYou tell Earl, `Hello'\n\x1b[0m", Player.caughtMessage());
    ExpectEq("\x1b[0;38;2;190;90;190mBob tells you, `Hello'\n\x1b[0m", Target.caughtMessage());
}
