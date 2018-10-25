//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Wizard2;
object *Players;
object Catch;

/////////////////////////////////////////////////////////////////////////////
int AdvanceToLevel(object player, int level, string guild)
{
    int runningLevel = player->guildLevel(guild);
    while ((player->guildLevel(guild) < level) && player->memberOfGuild(guild))
    {
        player->addExperience(1000 * runningLevel);
        player->advanceLevel(guild);
        runningLevel = player->guildLevel(guild);
    }
    return runningLevel;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "AdvanceToLevel" });

    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("elder"));

    Wizard2 = clone_object("/lib/realizations/wizard.c");
    Wizard2->restore("earl");
    Wizard2->Title("the Doppleganger Not Really Named Earl");
    Wizard2->addCommands();

    dataAccess->savePlayerData(database->GetWizardOfLevel("admin"));

    destruct(dataAccess);
    destruct(database);

    load_object("/lib/tests/support/guilds/testGuild.c");
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Catch = clone_object("/lib/tests/support/services/catchShadow.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();
    Catch->beginShadow(Wizard);

    Players = ({});

    int level = 1;
    foreach(string name in({ "fred", "george", "henrietta", "gertrude" }))
    {
        object player = clone_object("/lib/tests/support/services/mockPlayer.c");
        player->Name(name);
        player->joinGuild("test");
        AdvanceToLevel(player, level, "test");
        level++;
        Players += ({ player });
    }
    Players[0]->Race("elf");
    setUsers(Players + ({ Wizard, Wizard2 }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("wpeople"), "wpeople");
    ExpectFalse(Wizard->executeCommand("peopleo"), "peopleo");
}

/////////////////////////////////////////////////////////////////////////////
void PeopleDisplaysPeopleListInCorrectOrder()
{
    ExpectTrue(Wizard->executeCommand("people"));

    string *peopleList = explode(Wizard->caughtMessage(), "\n");
    ExpectEq("There are 6 players (6 active)", peopleList[0]);
    ExpectEq("IP Address      Player Name         Level        Location", peopleList[1]);
    ExpectSubStringMatch("Earl.*Elder", peopleList[2]);
    ExpectSubStringMatch("Earl.*Admin", peopleList[3]);
    ExpectSubStringMatch("Gertrude.*4", peopleList[4]);
    ExpectSubStringMatch("Henrietta.*3", peopleList[5]);
    ExpectSubStringMatch("George.*2", peopleList[6]);
    ExpectSubStringMatch("Fred.*1", peopleList[7]);
}

/////////////////////////////////////////////////////////////////////////////
void PeopleWithWizardFilterDisplaysCorrectList()
{
    ExpectTrue(Wizard->executeCommand("people -w"));

    string *peopleList = explode(Wizard->caughtMessage(), "\n");
    ExpectEq(5, sizeof(peopleList));
    ExpectSubStringMatch("Earl.*Elder", peopleList[2]);
    ExpectSubStringMatch("Earl.*Admin", peopleList[3]);
}

/////////////////////////////////////////////////////////////////////////////
void PeopleWithPlayerFilterDisplaysCorrectList()
{
    ExpectTrue(Wizard->executeCommand("people -p"));

    string *peopleList = explode(Wizard->caughtMessage(), "\n");
    ExpectEq(7, sizeof(peopleList));
    ExpectSubStringMatch("Gertrude.*4", peopleList[2]);
    ExpectSubStringMatch("Henrietta.*3", peopleList[3]);
    ExpectSubStringMatch("George.*2", peopleList[4]);
    ExpectSubStringMatch("Fred.*1", peopleList[5]);
}

/////////////////////////////////////////////////////////////////////////////
void PeopleDisplaysCorrectLocation()
{
    move_object(Wizard, "/lib/environment/environment.c");
    ExpectTrue(Wizard->executeCommand("people"));

    string *peopleList = explode(Wizard->caughtMessage(), "\n");
    ExpectSubStringMatch("Earl.*Admin.*lib/environment/environment", peopleList[3]);
}
