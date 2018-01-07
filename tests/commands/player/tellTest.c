//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Target;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Race("human");
    Player->reset();

    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target->Name("earl");
    Target->Race("human");
    Target->reset();

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
    ExpectTrue(Player->executeCommand("tell earl Hello"));
    ExpectEq("You tell Earl, `Hello'\n", Player->caughtMessage());
    ExpectEq("Bob tells you, `Hello'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TellWithoutMessageFails()
{
    ExpectFalse(Player->executeCommand("tell earl"));
    ExpectFalse(Player->caughtMessage());
    ExpectFalse(Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TellToNonexistantPersonFails()
{
    ExpectFalse(Player->executeCommand("tell fred Hi"));
    ExpectFalse(Player->caughtMessage());
    ExpectFalse(Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TellTForLongMessageCorrectlyFormatsText()
{
    ExpectTrue(Player->executeCommand("tell earl Hi. This is a really long message, Earl. I think that radishes are a bit too red and cabbage really doesn't exist. Just try to prove me wrong."));
    ExpectEq("You tell Earl, `Hi. This is a really long message, Earl. I think that radishes\nare a bit too red and cabbage really doesn't exist. Just try to prove me\nwrong.'\n",
        Player->caughtMessage());
    ExpectEq("Bob tells you, `Hi. This is a really long message, Earl. I think that radishes\nare a bit too red and cabbage really doesn't exist. Just try to prove me\nwrong.'\n",
        Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ReplyFailsIfNobodyToRespondTo()
{
    ExpectFalse(Player->executeCommand("reply I respond"));
    ExpectFalse(Player->caughtMessage());
    ExpectFalse(Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ReplyRespondsToPreviousTeller()
{
    ExpectTrue(Player->executeCommand("tell earl Hello"));
    ExpectTrue(Target->executeCommand("reply Hi"));
    ExpectEq("Earl replies to you, `Hi'\n", Player->caughtMessage());
    ExpectEq("You reply to Bob, `Hi'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TellBeforeResponseClearsReplyTo()
{
    ExpectTrue(Player->executeCommand("tell earl Hello"));
    ExpectTrue(Target->executeCommand("tell bob Hi"));
    ExpectFalse(Target->executeCommand("reply Hi"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSendTellWhenBlocked()
{
    Target->toggleBlockPlayer();
    ExpectTrue(Player->executeCommand("tell earl Hello"));
    ExpectEq("Your message was not sent. You have been blocked by Earl.\n", Player->caughtMessage());
    ExpectFalse(Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSendTellWhenTargetBusy()
{
    Target->toggleBusy();
    ExpectTrue(Player->executeCommand("tell earl Hello"));
    ExpectEq("Your message was not sent. Earl is busy.\n", Player->caughtMessage());
    ExpectFalse(Target->caughtMessage());
}