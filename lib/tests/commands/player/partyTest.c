//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Bystander;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/partyDictionary.c");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    move_object(Player, "/lib/tests/support/environment/fakeEnvironment.c");

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander.Name("frank");
    Bystander.addCommands();
    move_object(Bystander, this_object());

    setUsers(({ Player, Bystander }));

    command("create party Weasels", Player);
    command("add party member frank", Player);
    command("accept party invite", Bystander);

    Player.resetCatchList();
    Bystander.resetCatchList();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Bystander);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player.executeCommand("gparty"), "gparty");
    ExpectFalse(Player.executeCommand("partyd"), "partyd");
}

/////////////////////////////////////////////////////////////////////////////
void CanSendMessageOnGuildLine()
{
    ExpectTrue(Player.executeCommand("party Hi"));
    ExpectSubStringMatch("Weasels Bob.*Hi", Player.caughtMessage());
    ExpectSubStringMatch("Weasels Bob.*Hi", Bystander.caughtMessage());

    ExpectTrue(Bystander.executeCommand("party Yo"));
    ExpectSubStringMatch("Weasels Frank.*Yo", Player.caughtMessage());
    ExpectSubStringMatch("Weasels Frank.*Yo", Bystander.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSendEmptyMessageOnGuildLine()
{
    ExpectFalse(Player.executeCommand("party"));
    ExpectEq(0, Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSeeOtherPartyMessages()
{
    object lowlyMage = clone_object("/lib/tests/support/services/mockPlayer.c");
    lowlyMage.Name("dwight");
    lowlyMage.addCommands();
    command("create party Weasels", lowlyMage);
    lowlyMage.resetCatchList();

    ExpectTrue(Player.executeCommand("party Dwight is an idiot!"));
    ExpectSubStringMatch("Dwight is an idiot", Player.caughtMessage());
    ExpectSubStringMatch("Dwight is an idiot", Bystander.caughtMessage());
    ExpectEq(0, lowlyMage.caughtMessage());

    command("leave party", lowlyMage);
    destruct(lowlyMage);
}

/////////////////////////////////////////////////////////////////////////////
void GuildHelpIsDisplayed()
{
    ExpectTrue(Player.executeCommand("help party"));
    ExpectSubStringMatch("Send a message to every member of your party.*"
        "Instead of displaying a message, this option will display", 
        Player.caughtMessages()[0]);
}

/////////////////////////////////////////////////////////////////////////////
void PartyInfoDisplaysFailureMessageWhenNotInParty()
{
    command("leave party", Player);
    command("party -i", Player);
    ExpectEq("You are not currently in a party.\n", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PartyInfoDoesNotSendMessageToWholeParty()
{
    Player.colorConfiguration("none");
    ExpectTrue(Player.executeCommand("party -i"));
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=+ Members of 'Weasels' Party +-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Name               | Location           | Following          | Exp Earned   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Frank              | Unknown            | Nobody             |           0  |\n"
        "| Bob                | fakeEnvironment    | Nobody             |           0  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n", 
        Player.caughtMessage());
    ExpectEq(0, Bystander.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PartyInfoSortsByExperienceDistribution()
{
    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    dict.resetCache();
    load_object("/lib/tests/support/guilds/testGuild.c");

    Player.joinGuild("test");
    Player.addExperience(2000);
    Player.advanceLevel("test");
    Player.addExperience(100);

    Player.colorConfiguration("none");
    ExpectTrue(Player.executeCommand("party -info"));
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=+ Members of 'Weasels' Party +-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Name               | Location           | Following          | Exp Earned   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Bob                | fakeEnvironment    | Nobody             |        1067  |\n"
        "| Frank              | Unknown            | Nobody             |        1034  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PartyShowsDefunctMembers()
{
    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    dict.resetCache();
    load_object("/lib/tests/support/guilds/testGuild.c");

    Player.joinGuild("test");
    Player.addExperience(2000);

    command("leave party", Bystander);

    Player.advanceLevel("test");
    Player.addExperience(100);

    Player.colorConfiguration("none");
    ExpectTrue(Player.executeCommand("party -info"));
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=+ Members of 'Weasels' Party +-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Name               | Location           | Following          | Exp Earned   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Bob                | fakeEnvironment    | Nobody             |        1101  |\n"
        "| Frank              | No longer in party | Nobody             |        1001  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PartyShowsDefunctMembersWhoLogOffOrGoLinkDead()
{
    destruct(Bystander);
    Player.addExperience(1);
    Player.colorConfiguration("none");
    ExpectTrue(Player.executeCommand("party -i"));
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=+ Members of 'Weasels' Party +-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Name               | Location           | Following          | Exp Earned   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Bob                | fakeEnvironment    | Nobody             |           1  |\n"
        "| Frank              | No longer in party | Nobody             |           0  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PartyShowsThreeBitColorsCorrectly()
{
    destruct(Bystander);
    Player.addExperience(500);

    object dwight = clone_object("/lib/tests/support/services/mockPlayer.c");
    dwight.Name("dwight");
    dwight.addCommands();

    setUsers(({ Player, dwight }));
    command("add party member dwight", Player);
    command("accept party invite", dwight);
    Player.addExperience(1000);

    ExpectTrue(Player.executeCommand("party -i"));
    ExpectSubStringMatch("33;1mBob.*33mDwight.*31mFrank",
        Player.caughtMessage());

    command("leave party", dwight);
    destruct(dwight);
}

/////////////////////////////////////////////////////////////////////////////
void PartyShowsEightBitColorsCorrectly()
{
    Player.colorConfiguration("8-bit");

    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    dict.resetCache();
    load_object("/lib/tests/support/guilds/testGuild.c");

    destruct(Bystander);
    Player.addExperience(500);

    object dwight = clone_object("/lib/tests/support/services/mockPlayer.c");
    dwight.Name("dwight");
    dwight.addCommands();

    setUsers(({ Player, dwight }));
    command("add party member dwight", Player);
    command("accept party invite", dwight);
    Player.addExperience(1000);

    ExpectTrue(Player.executeCommand("party -i"));
    ExpectSubStringMatch("38;5;190;1mBob.*38;5;190mDwight.*38;5;9mFrank",
        Player.caughtMessage());

    command("leave party", dwight);
    destruct(dwight);
}

/////////////////////////////////////////////////////////////////////////////
void PartyShowsTwentyFourBitColorsCorrectly()
{
    Player.colorConfiguration("24-bit");

    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    dict.resetCache();
    load_object("/lib/tests/support/guilds/testGuild.c");

    destruct(Bystander);
    Player.addExperience(500);

    object dwight = clone_object("/lib/tests/support/services/mockPlayer.c");
    dwight.Name("dwight");
    dwight.addCommands();

    setUsers(({ Player, dwight }));
    command("add party member dwight", Player);
    command("accept party invite", dwight);
    Player.addExperience(1000);

    ExpectTrue(Player.executeCommand("party -i"));
    ExpectSubStringMatch("38;2;200;200;0;1mBob.*38;2;200;200;0mDwight.*38;2;200;0;0mFrank",
        Player.caughtMessage());

    command("leave party", dwight);
    destruct(dwight);
}

/////////////////////////////////////////////////////////////////////////////
void PartyShowsUnicodeCorrectly()
{
    Player.charsetConfiguration("unicode");

    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    dict.resetCache();
    load_object("/lib/tests/support/guilds/testGuild.c");

    destruct(Bystander);
    Player.addExperience(500);

    object dwight = clone_object("/lib/tests/support/services/mockPlayer.c");
    dwight.Name("dwight");
    dwight.addCommands();

    setUsers(({ Player, dwight }));
    command("add party member dwight", Player);
    command("accept party invite", dwight);
    Player.addExperience(1000);

    ExpectTrue(Player.executeCommand("party -i"));
    ExpectSubStringMatch("\u2554",
        Player.caughtMessage());

    command("leave party", dwight);
    destruct(dwight);
}

/////////////////////////////////////////////////////////////////////////////
void PartyShowsNPCsAndHenchmen()
{
    destruct(Bystander);
    Player.addExperience(1);

    object npc =
        clone_object("/areas/tol-dhurath/characters/galadhel/galadhel.c");
    npc.setLeader(Player);

    object companion = clone_object("/lib/realizations/companion.c");
    companion.Name("Earl");
    companion.setLeader(Player);

    object henchman = clone_object("/lib/realizations/henchman.c");
    henchman.Name("Ralph");
    henchman.setLeader(Player);

    Player.colorConfiguration("none");
    ExpectTrue(Player.executeCommand("party -i"));
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=+ Members of 'Weasels' Party +-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Name               | Location           | Following          | Exp Earned   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Bob                | fakeEnvironment    | Nobody             |           1  |\n"
        "| Frank              | No longer in party | Nobody             |           0  |\n"
        "| Earl               | Nowhere            | Bob                |         N/A  |\n"
        "| Galadhel           | Nowhere            | Bob                |         N/A  |\n"
        "| Ralph              | Nowhere            | Bob                |         N/A  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n",
        Player.caughtMessage());
}
