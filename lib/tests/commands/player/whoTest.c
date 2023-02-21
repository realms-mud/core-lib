//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    int runningLevel = player.guildLevel(guild);
    while ((player.guildLevel(guild) < level) && player.memberOfGuild(guild))
    {
        player.addExperience(1000 * runningLevel);
        player.advanceLevel(guild);
        runningLevel = player.guildLevel(guild);
    }
    return runningLevel;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "AdvanceToLevel" });

    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("elder"));

    Wizard2 = clone_object("/lib/realizations/wizard.c");
    Wizard2.restore("earl");
    Wizard2.Title("the Doppleganger Not Really Named Earl");
    Wizard2.addCommands();

    dataAccess.savePlayerData(database.GetWizardOfLevel("admin"));

    destruct(dataAccess);
    destruct(database);

    load_object("/lib/tests/support/guilds/testGuild.c");
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Catch = clone_object("/lib/tests/support/services/catchShadow.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.addCommands();
    Catch.beginShadow(Wizard);

    Players = ({});

    int level = 1;
    foreach(string name in({ "fred", "george", "henrietta", "gertrude" }))
    {
        object player = clone_object("/lib/tests/support/services/mockPlayer.c");
        player.Name(name);
        player.joinGuild("test");
        AdvanceToLevel(player, level, "test");
        level++;
        Players += ({ player });
    }
    Players[0].Race("elf");
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
    ExpectFalse(Wizard.executeCommand("wwho"), "wwho");
    ExpectFalse(Wizard.executeCommand("whoo"), "whoo");
}

/////////////////////////////////////////////////////////////////////////////
void WhoDisplaysWhoListInCorrectOrder()
{
    ExpectTrue(Wizard.executeCommand("who"));

    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectSubStringMatch("Weasel Lord Earl the Doppleganger.*Elder Wizard", whoList[0]);
    ExpectSubStringMatch("Weasel Lord Earl the title-less.*Admin Wizard", whoList[1]);
    ExpectSubStringMatch("-=-=-=-=", whoList[2]);
    ExpectSubStringMatch("Gertrude.*Level 4", whoList[3]);
    ExpectSubStringMatch("Henrietta.*Level 3", whoList[4]);
    ExpectSubStringMatch("George.*Level 2", whoList[5]);
    ExpectSubStringMatch("Fred.*Level 1", whoList[6]);
}

/////////////////////////////////////////////////////////////////////////////
void WhoHandlesNullPlayers()
{
    Players += ({ clone_object("/lib/modules/secure/login.c") });
    setUsers(Players);
    ExpectTrue(Wizard.executeCommand("who"));

    ExpectSubStringMatch("Player logging in", Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WhoWithWizardFilterDisplaysCorrectList()
{
    ExpectTrue(Wizard.executeCommand("who -w"));

    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectEq(3, sizeof(whoList));
    ExpectSubStringMatch("Weasel Lord Earl the Doppleganger.*Elder Wizard", whoList[0]);
    ExpectSubStringMatch("Weasel Lord Earl the title-less.*Admin Wizard", whoList[1]);
}

/////////////////////////////////////////////////////////////////////////////
void WhoWithPlayerFilterDisplaysCorrectList()
{
    ExpectTrue(Wizard.executeCommand("who -p"));

    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectEq(5, sizeof(whoList));
    ExpectSubStringMatch("Gertrude.*Level 4", whoList[0]);
    ExpectSubStringMatch("Henrietta.*Level 3", whoList[1]);
    ExpectSubStringMatch("George.*Level 2", whoList[2]);
    ExpectSubStringMatch("Fred.*Level 1", whoList[3]);
}

/////////////////////////////////////////////////////////////////////////////
void WhoWithRaceFilterDisplaysCorrectList()
{
    ExpectTrue(Wizard.executeCommand("who -r elf"));

    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectEq(5, sizeof(whoList));
    ExpectSubStringMatch("Weasel Lord Earl the Doppleganger.*Elder Wizard", whoList[0]);
    ExpectSubStringMatch("Weasel Lord Earl the title-less.*Admin Wizard", whoList[1]);
    ExpectSubStringMatch("Fred.*Level 1", whoList[3]);
}

/////////////////////////////////////////////////////////////////////////////
void WhoWithRaceAndWizardFilterDisplaysCorrectList()
{
    ExpectTrue(Wizard.executeCommand("who -r elf -w"));

    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectEq(3, sizeof(whoList));
    ExpectSubStringMatch("Weasel Lord Earl the Doppleganger.*Elder Wizard", whoList[0]);
    ExpectSubStringMatch("Weasel Lord Earl the title-less.*Admin Wizard", whoList[1]);
}

/////////////////////////////////////////////////////////////////////////////
void WhoWithRaceAndPlayerFiltersDisplaysCorrectList()
{
    Wizard2.Race("high elf");
    Players[0].Race("high elf");
    ExpectTrue(Wizard.executeCommand("who -r high elf -p"));

    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectEq(2, sizeof(whoList));
    ExpectSubStringMatch("Fred.*Level 1", whoList[0]);
}

/////////////////////////////////////////////////////////////////////////////
void WhoWithGuildFilterDisplaysCorrectList()
{
    load_object("/lib/tests/support/guilds/mageGuild.c");
    Players[3].joinGuild("fake mage");
    ExpectTrue(Wizard.executeCommand("who -g fake mage"));

    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectEq(5, sizeof(whoList));
    ExpectSubStringMatch("Weasel Lord Earl the Doppleganger.*Elder Wizard", whoList[0]);
    ExpectSubStringMatch("Weasel Lord Earl the title-less.*Admin Wizard", whoList[1]);
    ExpectSubStringMatch("Gertrude.*Level 5", whoList[3]);
}

/////////////////////////////////////////////////////////////////////////////
void WhoWithGuildAndPlayerFilterDisplaysCorrectList()
{
    Players[3].leaveGuild("test");
    Players[0].leaveGuild("test");
    ExpectTrue(Wizard.executeCommand("who -p -g test"));

    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectEq(3, sizeof(whoList));
    ExpectSubStringMatch("Henrietta.*Level 3", whoList[0]);
    ExpectSubStringMatch("George.*Level 2", whoList[1]);
}

/////////////////////////////////////////////////////////////////////////////
void WhoWithGuildAndWizardFilterDisplaysCorrectList()
{
    load_object("/lib/tests/support/guilds/mageGuild.c");
    Wizard.leaveGuild("fake mage");

    ExpectTrue(Wizard.executeCommand("who -w -g fake mage"));
    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectEq(2, sizeof(whoList));
    ExpectSubStringMatch("Weasel Lord Earl the Doppleganger.*Elder Wizard", whoList[0]);
}

/////////////////////////////////////////////////////////////////////////////
void WhoWithRaceAndGuildFilterDisplaysCorrectList()
{
    ExpectTrue(Wizard.executeCommand("who -r elf -g test"));

    string *whoList = explode(Wizard.caughtMessage(), "\n");
    ExpectEq(2, sizeof(whoList));
    ExpectSubStringMatch("Fred.*Level 1", whoList[0]);
}
