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
    Player->Gender(1);
    Player->reset();

    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target->Name("earl");
    Target->Race("human");
    Target->Gender(1);
    Target->reset();

    setUsers(({ Player, Target }));
    move_object(Player, this_object());
    move_object(Target, this_object());

    Player->executeCommand("mute earl");
    Player->resetCatchList();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Target);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSendTellWhenUnblocked()
{
    ExpectTrue(Target->executeCommand("tell bob Hello"));
    ExpectEq("\x1b[0;31;1mYour message was not sent. You have been blocked by Bob.\n\x1b[0m", Target->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("unmute earl");
    ExpectEq("You are no longer blocking Earl.\n", Player->caughtMessage());

    Player->resetCatchList();
    ExpectTrue(Target->executeCommand("tell bob Hi"));
    ExpectSubStringMatch("You tell Bob, `Hi'", Target->caughtMessage());
    ExpectSubStringMatch("Earl tells you, `Hi'", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSeeGuildMessageOfBlockedPlayer()
{
    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels->registerUser(Player);
    channels->registerUser(Target);

    ExpectTrue(Target->executeCommand("guild I am green"));
    ExpectSubStringMatch("I am green", Target->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("unmute earl");

    ExpectTrue(Target->executeCommand("guild I am not green"));
    ExpectSubStringMatch("I am not green", Target->caughtMessage());
    ExpectSubStringMatch("I am not green", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotUseSoulOnBlockedPlayer()
{
    ExpectTrue(Target->executeCommand("kiss bob"));
    ExpectEq("\x1b[0;31;1mCommand failed: You have been blocked by Bob "
        "and cannot target him.\n\x1b[0m", Target->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("unmute earl");
    Player->resetCatchList();

    ExpectTrue(Target->executeCommand("punch bob"));
    ExpectSubStringMatch("Earl punches you!", Player->caughtMessage());
    ExpectSubStringMatch("You punch Bob!", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSeeEmoteOfBlockedPlayer()
{
    ExpectTrue(Target->executeCommand("emote thinks Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl thinks Bob is a big snot-goblin...",
        Target->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("unmute earl");
    Player->resetCatchList();

    ExpectTrue(Target->executeCommand("emote thinks Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl thinks Bob is a big snot-goblin...", Player->caughtMessage());
    ExpectSubStringMatch("Earl thinks Bob is a big snot-goblin...", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSeeSayFromBlockedPlayer()
{
    ExpectTrue(Target->executeCommand("say Bob is a big snot-goblin..."));
    ExpectSubStringMatch("You say, `Bob is a big snot-goblin...'",
        Target->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("unmute earl");
    Player->resetCatchList();

    ExpectTrue(Target->executeCommand("say Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl says, `Bob is a big snot-goblin...'", Player->caughtMessage());
    ExpectSubStringMatch("You say, `Bob is a big snot-goblin...'", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSeeShoutFromBlockedPlayer()
{
    ExpectTrue(Target->executeCommand("shout Bob is a big snot-goblin..."));
    ExpectSubStringMatch("You shout, `Bob is a big snot-goblin...'",
        Target->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("unmute earl");
    Player->resetCatchList();

    ExpectTrue(Target->executeCommand("shout Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl shouts, `Bob is a big snot-goblin...'", Player->caughtMessage());
    ExpectSubStringMatch("You shout, `Bob is a big snot-goblin...'", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSendTellWhenTargetBusy()
{
    Player->executeCommand("unmute earl");
    Player->executeCommand("set busy on");
    ExpectSubStringMatch("You have set your status to busy.", Player->caughtMessage());

    Player->resetCatchList();
    ExpectTrue(Target->executeCommand("tell bob Hello"));
    ExpectEq("\x1b[0;31;1mYour message was not sent. Bob has his status set to busy.\n\x1b[0m",
        Target->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("set busy off");
    Player->resetCatchList();
    ExpectTrue(Target->executeCommand("tell bob Hi"));
    ExpectSubStringMatch("You tell Bob, `Hi'", Target->caughtMessage());
    ExpectSubStringMatch("Earl tells you, `Hi'", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSendTellWhenMuteWithBSet()
{
    Player->executeCommand("unmute earl");
    Player->executeCommand("mute -b");
    ExpectSubStringMatch("You have set your status to busy.", Player->caughtMessage());
    Player->resetCatchList();
    ExpectTrue(Target->executeCommand("tell bob Hello"));
    ExpectEq("\x1b[0;31;1mYour message was not sent. Bob has his status set to busy.\n\x1b[0m",
        Target->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("unmute -b");
    Player->resetCatchList();
    ExpectTrue(Target->executeCommand("tell bob Hi"));
    ExpectSubStringMatch("You tell Bob, `Hi'", Target->caughtMessage());
    ExpectSubStringMatch("Earl tells you, `Hi'", Player->caughtMessage());
}
