//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Player;
object Catch;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("creator"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Catch = clone_object("/lib/tests/support/services/catchShadow.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();
    Catch->beginShadow(Wizard);

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Gender(1);
    Player->addCommands();

    move_object(Wizard, "/lib/tests/support/environment/fakeEnvironment.c");
    move_object(Player, "/lib/tests/support/environment/fakeEnvironment.c");

    setUsers(({ Wizard, Player }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Catch);
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("sset"), "sset");
    ExpectFalse(Wizard->executeCommand("sett"), "sett");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMessageInWithMessageIn()
{
    ExpectTrue(Wizard->executeCommand("set -p message in -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageIn());
    ExpectEq("You have set your 'message in' to 'transblargifies'.\n", 
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotCanSetMessageInWithMessageIn()
{
    ExpectFalse(Player->executeCommand("set -p message in -v transblargifies"));
    ExpectEq("##Infinitive::arrive##", Player->MessageIn());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMessageInWithMsgIn()
{
    ExpectTrue(Wizard->executeCommand("set -p msgin -v blah"));
    ExpectEq("blah", Wizard->MessageIn());
    ExpectEq("You have set your 'msgin' to 'blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMessageOutWithMessageOut()
{
    ExpectTrue(Wizard->executeCommand("set -p message out -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageOut());
    ExpectEq("You have set your 'message out' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMessageOutWithMsgOut()
{
    ExpectTrue(Wizard->executeCommand("set -p msgout -v blah"));
    ExpectEq("blah", Wizard->MessageOut());
    ExpectEq("You have set your 'msgout' to 'blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMagicalMessageInWithMagicalMessageIn()
{
    ExpectTrue(Wizard->executeCommand("set -p magical message in -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MagicalMessageIn());
    ExpectEq("You have set your 'magical message in' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMagicalMessageInWithMMsgIn()
{
    ExpectTrue(Wizard->executeCommand("set -p mmsgin -v blah"));
    ExpectEq("blah", Wizard->MagicalMessageIn());
    ExpectEq("You have set your 'mmsgin' to 'blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMagicalMessageOutWithMagicalMessageOut()
{
    ExpectTrue(Wizard->executeCommand("set -p magical message out -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MagicalMessageOut());
    ExpectEq("You have set your 'magical message out' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMagicalMessageOutWithMMsgOut()
{
    ExpectTrue(Wizard->executeCommand("set -p mmsgout -v blah"));
    ExpectEq("blah", Wizard->MagicalMessageOut());
    ExpectEq("You have set your 'mmsgout' to 'blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetHomeWithMessageHome()
{
    ExpectTrue(Wizard->executeCommand("set -p message home -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageHome());
    ExpectEq("You have set your 'message home' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetHomeWithHomeMessage()
{
    ExpectTrue(Wizard->executeCommand("set -p home message -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageHome());
    ExpectEq("You have set your 'home message' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetCloneWithMessageClone()
{
    ExpectTrue(Wizard->executeCommand("set -p message clone -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageClone());
    ExpectEq("You have set your 'message clone' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetCloneWithCloneMessage()
{
    ExpectTrue(Wizard->executeCommand("set -p clone message -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageClone());
    ExpectEq("You have set your 'clone message' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetTitle()
{
    ExpectTrue(Wizard->executeCommand("set -p title -v transblargifying"));
    ExpectEq("transblargifying", Wizard->Title());
    ExpectEq("You have set your 'title' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetPretitle()
{
    ExpectTrue(Wizard->executeCommand("set -p pretitle -v transblargifying"));
    ExpectEq("transblargifying", Wizard->Pretitle());
    ExpectEq("You have set your 'pretitle' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetShort()
{
    ExpectTrue(Wizard->executeCommand("set -p short -v transblargifying"));
    ExpectEq("transblargifying", Wizard->short());
    ExpectEq("You have set your 'short' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetShortDescription()
{
    ExpectTrue(Wizard->executeCommand("set -p short description -v transblargifying"));
    ExpectEq("transblargifying", Wizard->short());
    ExpectEq("You have set your 'short description' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLongDescription()
{
    ExpectTrue(Wizard->executeCommand("set -p long description -v transblargifying"));
    ExpectEq("transblargifying", Wizard->description());
    ExpectEq("You have set your 'long description' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSetNonWizardParameters()
{
    ExpectTrue(Player->executeCommand("set -p long description -v transblargifying"));
    ExpectEq("transblargifying", Player->description());
    ExpectEq("You have set your 'long description' to 'transblargifying'.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetDescription()
{
    ExpectTrue(Wizard->executeCommand("set -p description -v transblargifying"));
    ExpectEq("transblargifying", Wizard->description());
    ExpectEq("You have set your 'description' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSetInvalidParameter()
{
    ExpectFalse(Wizard->executeCommand("set -p blarg -v transblargifying"));
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSetWithoutValue()
{
    ExpectFalse(Wizard->executeCommand("set -p blarg"));
}

/////////////////////////////////////////////////////////////////////////////
void CanReverseParameters()
{
    ExpectTrue(Wizard->executeCommand("set -v transblargifying -p description"));
    ExpectEq("transblargifying", Wizard->description());
    ExpectEq("You have set your 'description' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanUseDashesWhenParametersReversed()
{
    ExpectTrue(Wizard->executeCommand("set -v transblargifying-blah and blah -p description"));
    ExpectEq("transblargifying-blah and blah", Wizard->description());
    ExpectEq("You have set your 'description' to 'transblargifying-blah and blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanUseDashesInValue()
{
    ExpectTrue(Wizard->executeCommand("set -p description -v transblargifying-blah and blah"));
    ExpectEq("transblargifying-blah and blah", Wizard->description());
    ExpectEq("You have set your 'description' to 'transblargifying-blah and blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSendTellWhenBlocked()
{
    Player->executeCommand("set -p block player -v earl");
    ExpectEq("You are now blocking Earl. You will no longer see communication (say, tell,\n"
        "shout, channels, emotes, or soul actions) from this person. All attempted\n"
        "interactions by them will be logged in the event you need to escalate a\n"
        "harassment claim.\n", Player->caughtMessages()[0]);

    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("tell bob Hello"));
    ExpectEq("\x1b[0;31;1mYour message was not sent. You have been blocked by Bob.\n\x1b[0m", Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSeeGuildMessageOfBlockedPlayer()
{
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    load_object("/lib/tests/support/guilds/mageGuild.c");
    Player->joinGuild("fake mage");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));

    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels->registerUser(Player);
    channels->registerUser(Wizard);

    ExpectTrue(Wizard->executeCommand("guild Hi"));
    ExpectSubStringMatch("Hi", Player->caughtMessage());
    Player->executeCommand("set -p block player -v earl");

    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("guild I am green"));
    ExpectSubStringMatch("I am green", Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotUseSoulOnBlockedPlayer()
{
    ExpectTrue(Wizard->executeCommand("punch bob"));
    ExpectSubStringMatch("Earl punches you!", Player->caughtMessage());
    ExpectSubStringMatch("You punch Bob!", Wizard->caughtMessage());

    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();

    ExpectTrue(Wizard->executeCommand("kiss bob"));
    ExpectEq("\x1b[0;31;1mCommand failed: You have been blocked by Bob "
        "and cannot target him.\n\x1b[0m", Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSeeEmoteOfBlockedPlayer()
{
    ExpectTrue(Wizard->executeCommand("emote thinks Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl thinks Bob is a big snot-goblin...", Player->caughtMessage());
    ExpectSubStringMatch("Earl thinks Bob is a big snot-goblin...", Wizard->caughtMessage());

    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();

    ExpectTrue(Wizard->executeCommand("emote thinks Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl thinks Bob is a big snot-goblin...",
        Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSeeSayFromBlockedPlayer()
{
    ExpectTrue(Wizard->executeCommand("say Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl says, `Bob is a big snot-goblin...'", Player->caughtMessage());
    ExpectSubStringMatch("You say, `Bob is a big snot-goblin...'", Wizard->caughtMessage());

    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();

    ExpectTrue(Wizard->executeCommand("say Bob is a big snot-goblin..."));
    ExpectSubStringMatch("You say, `Bob is a big snot-goblin...'",
        Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSeeShoutFromBlockedPlayer()
{
    ExpectTrue(Wizard->executeCommand("shout Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl shouts, `Bob is a big snot-goblin...'", Player->caughtMessage());
    ExpectSubStringMatch("You shout, `Bob is a big snot-goblin...'", Wizard->caughtMessage());

    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();

    ExpectTrue(Wizard->executeCommand("shout Bob is a big snot-goblin..."));
    ExpectSubStringMatch("You shout, `Bob is a big snot-goblin...'",
        Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSendTellWhenWizardBusy()
{
    Player->executeCommand("set -p busy -v on");
    ExpectSubStringMatch("You have set your busy flag to 'on'.", Player->caughtMessage());

    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("tell bob Hello"));
    ExpectEq("\x1b[0;31;1mYour message was not sent. Bob has his status set to busy.\n\x1b[0m",
        Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSendTellWhenUnblocked()
{
    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("tell bob Hello"));
    ExpectEq("\x1b[0;31;1mYour message was not sent. You have been blocked by Bob.\n\x1b[0m", Wizard->caughtMessage());
    ExpectEq(Player->caughtMessage());

    Player->executeCommand("set -p unblock player -v earl");
    ExpectEq("You are no longer blocking Earl.\n", Player->caughtMessages()[0]);

    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("tell bob Hi"));
    ExpectSubStringMatch("You tell Bob, `Hi'", Wizard->caughtMessage());
    ExpectSubStringMatch("Earl tells you, `Hi'", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSeeGuildMessageOfUnblockedPlayer()
{
    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    load_object("/lib/tests/support/guilds/mageGuild.c");
    Player->joinGuild("fake mage");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));
    Player->resetCatchList();

    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels->registerUser(Player);
    channels->registerUser(Wizard);

    ExpectTrue(Wizard->executeCommand("guild I am green"));
    ExpectSubStringMatch("I am green", Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("set -p unblock player -v earl");

    ExpectTrue(Wizard->executeCommand("guild I am not green"));
    ExpectSubStringMatch("I am not green", Wizard->caughtMessage());
    ExpectSubStringMatch("I am not green", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanUseSoulOnUnblockedPlayer()
{
    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("kiss bob"));
    ExpectEq("\x1b[0;31;1mCommand failed: You have been blocked by Bob "
        "and cannot target him.\n\x1b[0m", Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("set -p unblock player -v earl");
    Player->resetCatchList();

    ExpectTrue(Wizard->executeCommand("punch bob"));
    ExpectSubStringMatch("Earl punches you!", Player->caughtMessage());
    ExpectSubStringMatch("You punch Bob!", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSeeEmoteOfUnblockedPlayer()
{
    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("emote thinks Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl thinks Bob is a big snot-goblin...",
        Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("set -p unblock player -v earl");
    Player->resetCatchList();

    ExpectTrue(Wizard->executeCommand("emote thinks Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl thinks Bob is a big snot-goblin...", Player->caughtMessage());
    ExpectSubStringMatch("Earl thinks Bob is a big snot-goblin...", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSeeSayFromUnblockedPlayer()
{
    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("say Bob is a big snot-goblin..."));
    ExpectSubStringMatch("You say, `Bob is a big snot-goblin...'",
        Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("set -p unblock player -v earl");
    Player->resetCatchList();

    ExpectTrue(Wizard->executeCommand("say Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl says, `Bob is a big snot-goblin...'", Player->caughtMessage());
    ExpectSubStringMatch("You say, `Bob is a big snot-goblin...'", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSeeShoutFromUnblockedPlayer()
{
    Player->executeCommand("set -p block player -v earl");
    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("shout Bob is a big snot-goblin..."));
    ExpectSubStringMatch("You shout, `Bob is a big snot-goblin...'",
        Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("set -p unblock player -v earl");
    Player->resetCatchList();

    ExpectTrue(Wizard->executeCommand("shout Bob is a big snot-goblin..."));
    ExpectSubStringMatch("Earl shouts, `Bob is a big snot-goblin...'", Player->caughtMessage());
    ExpectSubStringMatch("You shout, `Bob is a big snot-goblin...'", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSendTellWhenWizardUnsetsBusy()
{
    Player->executeCommand("set -p busy -v on");
    ExpectSubStringMatch("You have set your busy flag to 'on'", Player->caughtMessage());

    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("tell bob Hello"));
    ExpectEq("\x1b[0;31;1mYour message was not sent. Bob has his status set to busy.\n\x1b[0m",
        Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("set -p busy -v off");
    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("tell bob Hi"));
    ExpectSubStringMatch("You tell Bob, `Hi'", Wizard->caughtMessage());
    ExpectSubStringMatch("Earl tells you, `Hi'", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotHearShoutWhenEarmuffed()
{
    Player->executeCommand("set -p earmuffs -v on");
    ExpectSubStringMatch("You have set your earmuffs to 'on'.", Player->caughtMessage());

    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("shout Hello"));
    ExpectSubStringMatch("You shout, `Hello'", Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanHearShoutWhenEarmuffsTurnedOff()
{
    Player->executeCommand("set -p earmuffs -v on");
    ExpectSubStringMatch("You have set your earmuffs to 'on'.", Player->caughtMessage());

    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("shout Hello"));
    ExpectSubStringMatch("You shout, `Hello'", Wizard->caughtMessage());
    ExpectFalse(Player->caughtMessage());

    Player->executeCommand("set -p earmuffs -v off");
    Player->resetCatchList();
    ExpectTrue(Wizard->executeCommand("shout Hello"));
    ExpectSubStringMatch("You shout, `Hello'", Wizard->caughtMessage());
    ExpectSubStringMatch("Earl shouts, `Hello'", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSetPageSize()
{
    ExpectEq(20, Player->pageSize());
    Player->executeCommand("set -p page size -v 10");
    ExpectSubStringMatch("You have set your page size to 10.", Player->caughtMessage());
    ExpectEq(10, Player->pageSize());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSetColorToNone()
{
    Player->executeCommand("set -p color -v none");
    ExpectSubStringMatch("You have set your color to 'none'.", Player->caughtMessage());
    ExpectEq("none", Player->colorConfiguration());
    Player->executeCommand("shout Hi!");
    ExpectEq("You shout, `Hi!'\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSetColorToThreeBit()
{
    Player->executeCommand("set -p color -v 3-bit");
    ExpectSubStringMatch("You have set your color to '3-bit'.", Player->caughtMessage());
    ExpectEq("3-bit", Player->colorConfiguration());
    Player->executeCommand("shout Hi!");
    ExpectEq("\x1b[0;35mYou shout, `Hi!'\n\x1b[0m", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSetColorToEightBit()
{
    Player->executeCommand("set -p color -v 8-bit");
    ExpectSubStringMatch("You have set your color to '8-bit'.", Player->caughtMessage());
    ExpectEq("8-bit", Player->colorConfiguration());
    Player->executeCommand("shout Hi!");
    ExpectEq("\x1b[0;38;5;112mYou shout, `Hi!'\n\x1b[0m", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSetColorToTwentyFourBit()
{
    Player->executeCommand("set -p color -v 24-bit");
    ExpectSubStringMatch("You have set your color to '24-bit'.", Player->caughtMessage());
    ExpectEq("24-bit", Player->colorConfiguration());
    Player->executeCommand("shout Hi!");
    ExpectEq("\x1b[0;38;2;190;90;190mYou shout, `Hi!'\n\x1b[0m", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSetInvalidColor()
{
    Player->executeCommand("set -p color -v fred");
    ExpectEq("3-bit", Player->colorConfiguration());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSetCharsetToASCII()
{
    Player->executeCommand("set -p charset -v ascii");
    ExpectSubStringMatch("You have set your character set to 'ascii'.", Player->caughtMessage());
    ExpectEq("ascii", Player->charsetConfiguration());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSetCharsetToUnicode()
{
    Player->executeCommand("set -p charset -v unicode");
    ExpectSubStringMatch("You have set your character set to 'unicode'.", Player->caughtMessage());
    ExpectEq("unicode", Player->charsetConfiguration());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSetInvalidCharset()
{
    Player->executeCommand("set -p charset -v weasel");
    ExpectEq("ascii", Player->charsetConfiguration());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerHelpDisplaysCorrectly()
{
    Player->pageSize(1000);
    command("help set", Player);
    ExpectEq("\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Help for Set +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;36;1mSynopsis\n"
        "\x1b[0m\x1b[0;36m\tset - Set various player-controlled game parameters.\n"
        "\x1b[0m\x1b[0;36;1m\nSyntax\n"
        "\x1b[0m\t\x1b[0;36mset [-p \x1b[0m\x1b[0;33m<Value>\x1b[0m\x1b[0;36m] [-v \x1b[0m\x1b[0;36m\x1b[0m\x1b[0;33m<Value>\x1b[0m\x1b[0;36m]\n"
        "\t\t\x1b[0m\n"
        "\x1b[0;36;1mDescription\n"
        "\x1b[0m\x1b[0;36mSet allows a player to set various configuration parameters for their\n"
        "character. This includes color support, unicode support, and descriptions. It\n"
        "also allows a player to block messages coming from individuals, channels, or\n"
        "shout and can be used to  set a 'busy' flag - a temporary block of directed\n"
        "(tell) messages.\n"
        "\x1b[0m\x1b[0;36;1m\nOptions\n"
        "\x1b[0m\n    \x1b[0;36;1m-p \x1b[0m\x1b[0;33m<Value>\x1b[0m\x1b[0;36;1m\x1b[0m\n"
        "\t\x1b[0;36mThis flag allows a user to specify the parameter they wish to set.\n"
        "\tIt must be used in conjunction with the -v flag. Possible parameters\n\tare:\n"
        "\t\n"
        "\tblock player         - This parameter will allow you to block all\n"
        "\t                       communication from the specified user. They\n"
        "\t                       will not be able to 'tell' to you nor will\n"
        "\t                       they be able to execute a soul command on\n"
        "\t                       you. You will not see their say, emote,\n"
        "\t                       undirected soul commands, shouts, poses, or\n"
        "\t                       channel (guild, race, etc) messages either.\n"
        "\t                       You will, however, see when they arrive,\n"
        "\t                       leave, and all combat messages.\n"
        "\t                       \n"
        "\tbusy                 - Sets the user's 'busy' flag. When this is\n"
        "\t                       set, you will not receive directed messages\n"
        "\t                       (tells) from other players.\n"
        "\t                       Possible values are: on, off\n"
        "\t                       \n"
        "\tcharset              - Sets the user's character set configuration.\n"
        "\t                       This can be:\n"
        "\t                       ascii - Use this option for standard ASCII\n"
        "\t                       unicode - Use this option for unicode\n"
        "\t                       \n" +
        "\t                       Be sure that your terminal / mud client\n"
        "\t                       supports the selected character set option\n"
        "\t                       to ensure proper display.\n"
        "\t                       \n"
        "\tcolor                - Sets the user's color configuration. This\n"
        "\t                       can be:\n"
        "\t                       none - Use this option for no color support\n"
        "\t                       3-bit - Use this option for basic 3-bit\n"
        "\t                               (8 color) support\n"
        "\t                       8-bit - Use this option for 8-bit (256\n"
        "\t                               color) support\n"
        "\t                       24-bit - Use this option for true color\n"
        "\t                               (16,777,216 color) support\n"
        "\t                       \n" +
        "\t                       Be sure that your terminal / mud client\n"
        "\t                       supports the selected color option to ensure\n"
        "\t                       proper display.\n"
        "\t                       \n"
        "\tdescription          - Sets the user's detailed character\n"
        "\t                       description\n"
        "\t                       \n"
        "\tdisplay map          - Toggles whether or not the user will see the\n"
        "\t                       mini map when it's available.\n"
        "\t                       Possible values are: on, off\n"
        "\t                       \n"
        "\tearmuffs             - Sets the user's earmuffs. When this is set,\n"
        "\t                       you will not receive shouts or poses from\n"
        "\t                       other players.\n"
        "\t                       Possible values are: on, off\n"
        "\t                       \n"
        "\tlong description     - Sets the user's detailed character\n"
        "\t                       description\n"
        "\t                       \n"
        "\tpage size            - Sets the number of lines the pager will\n"
        "\t                       display at a time\n"
        "\t                       \n"
        "\tprimary guild        - Sets the primary / shown guild for a player\n"
        "\t                       in lists and other commands that identify\n"
        "\t                       the player with 'what they do'\n"
        "\t                       \n"
        "\tpvp                  - This parameter will allow you to attack and\n"
        "\t                       be attacked by other players. Once this flag\n"
        "\t                       is set, it cannot be unset!\n"
        "\t                       \n"
        "\tsilence              - This parameter will allow you 'turn off' the\n"
        "\t                       specified channel. For example, if your\n"
        "\t                       fighter guild is too chatty for your tastes\n"
        "\t                       \t\tset -p silence -v fighter\n"
        "\t                       and you won't hear from them until you\n"
        "\t                       unsilence. You cannot silence the 'system'\n"
        "\t                       channel.\n"
        "\t                       \n"
        "\tunblock player       - This parameter will allow you to unblock a\n"
        "\t                       previously-blocked player.\n"
        "\t                       \n"
        "\tunsafe faction interactions - This parameter will allow you to attack\n"
        "\t                       characters that belong to factions you are\n"
        "\t                       either a member of or friendly towards. Be\n"
        "\t                       warned - killing members of these factions\n"
        "\t                       will have negative effects!\n"
        "\t                       \n"
        "\tunsilence            - This parameter will allow you unsilence a\n"
        "\t                       previously-silenced channel\n"
        "\t                       \n"
        "\t\x1b[0m\n"
        "    \x1b[0;36;1m-v \x1b[0m\x1b[0;33m<Value>\x1b[0m\x1b[0;36;1m\x1b[0m\n"
        "\t\x1b[0;36mThis option will set the value for the specified parameter.\n"
        "\tIt must be used in conjunction with the -p flag.\n"
        "\t\x1b[0m\n"
        "\x1b[0;36;1mNotes\n"
        "\t\x1b[0m\x1b[0;36mSee also: tell, reply, guild, and shout\x1b[0m"
        "\x1b[0;36;1m\n\nCopyright\n"
        "\x1b[0m\x1b[0;36m\tCopyright (C) 1991-2019 Allen Cummings. For additional licensing\n"
        "\tinformation, see \x1b[0m\x1b[0;36mhttp://realmsmud.org/license/\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WizardHelpDisplaysCorrectly()
{
    Wizard->pageSize(1000);
    command("help set", Wizard);
    ExpectEq("\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Help for Set +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;36;1mSynopsis\n"
        "\x1b[0m\x1b[0;36m\tset - Set various player-controlled game parameters.\n"
        "\x1b[0m\x1b[0;36;1m\nSyntax\n"
        "\x1b[0m\t\x1b[0;36mset [-p \x1b[0m\x1b[0;33m<Value>\x1b[0m\x1b[0;36m] [-v \x1b[0m\x1b[0;36m\x1b[0m\x1b[0;33m<Value>\x1b[0m\x1b[0;36m]\n"
        "\t\t\x1b[0m\n"
        "\x1b[0;36;1mDescription\n"
        "\x1b[0m\x1b[0;36mSet allows a player to set various configuration parameters for their\n"
        "character. This includes color support, unicode support, and descriptions. It\n"
        "also allows a player to block messages coming from individuals, channels, or\n"
        "shout and can be used to  set a 'busy' flag - a temporary block of directed\n"
        "(tell) messages.\n"
        "\x1b[0m\x1b[0;36;1m\nOptions\n"
        "\x1b[0m\n    \x1b[0;36;1m-p \x1b[0m\x1b[0;33m<Value>\x1b[0m\x1b[0;36;1m\x1b[0m\n"
        "\t\x1b[0;36mThis flag allows a user to specify the parameter they wish to set.\n"
        "\tIt must be used in conjunction with the -v flag. Possible parameters\n\tare:\n"
        "\t\n"
        "\tblock player         - This parameter will allow you to block all\n"
        "\t                       communication from the specified user. They\n"
        "\t                       will not be able to 'tell' to you nor will\n"
        "\t                       they be able to execute a soul command on\n"
        "\t                       you. You will not see their say, emote,\n"
        "\t                       undirected soul commands, shouts, poses, or\n"
        "\t                       channel (guild, race, etc) messages either.\n"
        "\t                       You will, however, see when they arrive,\n"
        "\t                       leave, and all combat messages.\n"
        "\t                       \n"
        "\tbusy                 - Sets the user's 'busy' flag. When this is\n"
        "\t                       set, you will not receive directed messages\n"
        "\t                       (tells) from other players.\n"
        "\t                       Possible values are: on, off\n"
        "\t                       \n"
        "\tcharset              - Sets the user's character set configuration.\n"
        "\t                       This can be:\n"
        "\t                       ascii - Use this option for standard ASCII\n"
        "\t                       unicode - Use this option for unicode\n"
        "\t                       \n" +
        "\t                       Be sure that your terminal / mud client\n"
        "\t                       supports the selected character set option\n"
        "\t                       to ensure proper display.\n"
        "\t                       \n"
        "\tclone message        - The message displayed when cloning an object\n"
        "\t                       \n"
        "\tcolor                - Sets the user's color configuration. This\n"
        "\t                       can be:\n"
        "\t                       none - Use this option for no color support\n"
        "\t                       3-bit - Use this option for basic 3-bit\n"
        "\t                               (8 color) support\n"
        "\t                       8-bit - Use this option for 8-bit (256\n"
        "\t                               color) support\n"
        "\t                       24-bit - Use this option for true color\n"
        "\t                               (16,777,216 color) support\n"
        "\t                       \n"
        "\t                       Be sure that your terminal / mud client\n"
        "\t                       supports the selected color option to ensure\n"
        "\t                       proper display.\n"
        "\t                       \n"
        "\tdescription          - Sets the user's detailed character\n"
        "\t                       description\n"
        "\t                       \n"
        "\tdisplay map          - Toggles whether or not the user will see the\n"
        "\t                       mini map when it's available.\n"
        "\t                       Possible values are: on, off\n"
        "\t                       \n"
        "\tearmuffs             - Sets the user's earmuffs. When this is set,\n"
        "\t                       you will not receive shouts or poses from\n"
        "\t                       other players.\n"
        "\t                       Possible values are: on, off\n"
        "\t                       \n"
        "\thome location        - Sets the location the user goes to when\n"
        "\t                       using the 'home' command\n"
        "\t                       \n"
        "\thome message         - The message displayed when executing the\n"
        "\t                       'home' command\n"
        "\t                       \n"
        "\tlong description     - Sets the user's detailed character\n"
        "\t                       description\n"
        "\t                       \n"
        "\tmagical message in   - The message displayed when entering an\n"
        "\t                       environment without a direct movement action\n"
        "\t                       \n"
        "\tmagical message out  - The message displayed when leaving an\n"
        "\t                       environment without a direct movement action\n"
        "\t                       \n"
        "\tmessage clone        - The message displayed when cloning an object\n"
        "\t                       \n"
        "\tmessage home         - The message displayed when executing the\n"
        "\t                       'home' command\n"
        "\t                       \n"
        "\tmessage in           - The message displayed when entering an\n"
        "\t                       environment\n"
        "\t                       \n" +
        "\tmessage out          - The message displayed when leaving an\n"
        "\t                       environment\n"
        "\t                       \n"
        "\tmmsgin               - The message displayed when entering an\n"
        "\t                       environment without a direct movement action\n"
        "\t                       \n"
        "\tmmsgout              - The message displayed when leaving an\n"
        "\t                       environment without a direct movement action\n"
        "\t                       \n"
        "\tmsgin                - The message displayed when entering an\n"
        "\t                       environment\n"
        "\t                       \n"
        "\tmsgout               - The message displayed when leaving an\n"
        "\t                       environment\n"
        "\t                       \n"
        "\tpage size            - Sets the number of lines the pager will\n"
        "\t                       display at a time\n"
        "\t                       \n"
        "\tpretitle             - Sets the user's pretitle\n"
        "\t                       \n"
        "\tprimary guild        - Sets the primary / shown guild for a player\n"
        "\t                       in lists and other commands that identify\n"
        "\t                       the player with 'what they do'\n"
        "\t                       \n"
        "\tpvp                  - This parameter will allow you to attack and\n"
        "\t                       be attacked by other players. Once this flag\n"
        "\t                       is set, it cannot be unset!\n"
        "\t                       \n"
        "\tshort                - Sets the user's short description\n"
        "\t                       \n"
        "\tshort description    - Sets the user's short description\n"
        "\t                       \n"
        "\tsilence              - This parameter will allow you 'turn off' the\n"
        "\t                       specified channel. For example, if your\n"
        "\t                       fighter guild is too chatty for your tastes\n"
        "\t                       \t\tset -p silence -v fighter\n"
        "\t                       and you won't hear from them until you\n"
        "\t                       unsilence. You cannot silence the 'system'\n"
        "\t                       channel.\n"
        "\t                       \n"
        "\tstarting location    - Sets the location the user goes to upon\n"
        "\t                       login\n"
        "\t                       \n"
        "\ttitle                - Sets the user's title\n"
        "\t                       \n"
        "\tunblock player       - This parameter will allow you to unblock a\n"
        "\t                       previously-blocked player.\n"
        "\t                       \n"
        "\tunsafe faction interactions - This parameter will allow you to attack\n"
        "\t                       characters that belong to factions you are\n"
        "\t                       either a member of or friendly towards. Be\n"
        "\t                       warned - killing members of these factions\n"
        "\t                       will have negative effects!\n"
        "\t                       \n"
        "\tunsilence            - This parameter will allow you unsilence a\n"
        "\t                       previously-silenced channel\n"
        "\t                       \n"
        "\t\x1b[0m\n"
        "    \x1b[0;36;1m-v \x1b[0m\x1b[0;33m<Value>\x1b[0m\x1b[0;36;1m\x1b[0m\n"
        "\t\x1b[0;36mThis option will set the value for the specified parameter.\n"
        "\tIt must be used in conjunction with the -p flag.\n"
        "\t\x1b[0m\n"
        "\x1b[0;36;1mNotes\n"
        "\t\x1b[0m\x1b[0;36mSee also: tell, reply, guild, and shout\x1b[0m"
        "\x1b[0;36;1m\n\nCopyright\n"
        "\x1b[0m\x1b[0;36m\tCopyright (C) 1991-2019 Allen Cummings. For additional licensing\n"
        "\tinformation, see \x1b[0m\x1b[0;36mhttp://realmsmud.org/license/\n\x1b[0m", 
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSetPrimaryGuild()
{
    load_object("/lib/dictionaries/guildsDictionary.c");
    load_object("/lib/tests/support/guilds/fighterGuild.c");
    load_object("/lib/tests/support/guilds/mageGuild.c");
    Player->joinGuild("fake fighter");
    Player->joinGuild("fake mage");

    ExpectEq("fake mage", Player->primaryGuild());

    Player->executeCommand("set -p primary guild -v fake fighter");
    ExpectSubStringMatch("You have set your primary guild to 'fake fighter'", 
        Player->caughtMessage());
    ExpectEq("fake fighter", Player->primaryGuild());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCannotSetPrimaryGuildIfNotMember()
{
    Player->executeCommand("set -p primary guild -v weasels");
    ExpectSubStringMatch("You can only set your primary guild to a guild to which "
        "you belong",
        Player->caughtMessage());
    ExpectEq("guildless", Player->primaryGuild());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetPVPFlagOnlyOnce()
{
    ExpectEq("0", Player->onKillList());
    ExpectTrue(Player->executeCommand("set -p pvp -v 1"));
    ExpectEq("1", Player->onKillList());
    ExpectEq("You can now engage in player vs. player combat outside of the arena.\n",
        Player->caughtMessage());
    ExpectTrue(Player->executeCommand("set -p pvp -v 1"));
    ExpectEq("1", Player->onKillList());
    ExpectEq("You can not remove yourself from the player vs. player kill list.\n",
        Player->caughtMessage());
}
