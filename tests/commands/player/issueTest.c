//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    destruct(load_object("/lib/tests/support/environment/fakeEnvironment.c"));

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

    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels->registerUser(Wizard);
    channels->registerUser(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Catch);
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void CanLogIssue()
{
    command("issue", Player);

    ExpectEq("\x1b[0;32;1mYour issue details have been logged.\n\x1b[0m",
        Player->caughtMessage());
    ExpectSubStringMatch("A new issue has been logged:.*Affected Object: "
        "lib/tests/support/environment/fakeEnvironment.c.*"
        "Location: lib/tests/support/environment/fakeEnvironment.c.*"
        "Details: issue.*"
        "Current trace data:.*",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanLogIssueWithComment()
{
    command("issue -c I feel lonely. Talk to me.", Player);

    ExpectEq("\x1b[0;32;1mYour issue details have been logged.\n\x1b[0m",
        Player->caughtMessage());
    ExpectSubStringMatch("A new issue has been logged:.*Affected Object: "
        "lib/tests/support/environment/fakeEnvironment.c.*"
        "Location: lib/tests/support/environment/fakeEnvironment.c.*"
        "Details: I feel lonely. Talk to me.*"
        "Current trace data:.*",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanLogIssueOnTarget()
{
    catch (load_object("this/will/throw/an/error"));

    object stuff = 
        clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(stuff, Player);

    command("issue -t sword -c I feel lonely. Talk to me.", Player);

    ExpectEq("\x1b[0;32;1mYour issue details have been logged.\n\x1b[0m",
        Player->caughtMessage());
    ExpectSubStringMatch("A new issue has been logged:.*Affected Object: "
        "lib/instances/items/weapons/swords/long-sword.c.*"
        "Location: lib/tests/support/environment/fakeEnvironment.c.*"
        "Details: I feel lonely. Talk to me.*"
        "Current trace data:.*'CanLogIssueOnTarget' in "
        "'lib/tests/commands/player/issueTest.*",
        Wizard->caughtMessage());

    destruct(stuff);
}

/////////////////////////////////////////////////////////////////////////////
void CanLogIssueWithTeleport()
{
    ExpectEq(load_object("/lib/tests/support/environment/fakeEnvironment.c"),
        environment(Player));

    command("issue -teleport -c I feel lonely. Talk to me.", Player);

    ExpectEq(load_object("/room/city/central_park.c"),
        environment(Player));

    ExpectEq("\x1b[0;32;1mYour issue details have been logged.\n\x1b[0m",
        Player->caughtMessage());
    ExpectSubStringMatch("A new issue has been logged:.*Affected Object: "
        "lib/tests/support/environment/fakeEnvironment.c.*"
        "Location: lib/tests/support/environment/fakeEnvironment.c.*"
        "Details: I feel lonely. Talk to me.*"
        "NOTE: Bob used teleport to safety.*",
        Wizard->caughtMessage());
}
