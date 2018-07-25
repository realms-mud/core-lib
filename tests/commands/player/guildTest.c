//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Bystander;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    move_object(Player, this_object());

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander->Name("frank");
    Bystander->addCommands();
    move_object(Bystander, this_object());

    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels->registerUser(Player);
    channels->registerUser(Bystander);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Bystander);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player->executeCommand("gguild"), "gguild");
    ExpectFalse(Player->executeCommand("guildd"), "guildd");
}

/////////////////////////////////////////////////////////////////////////////
void CanSendMessageOnGuildLine()
{
    ExpectTrue(Player->executeCommand("guild Hi"));
    ExpectSubStringMatch("Guildless Bob.*Hi", Player->caughtMessage());
    ExpectSubStringMatch("Guildless Bob.*Hi", Bystander->caughtMessage());

    ExpectTrue(Bystander->executeCommand("guild Yo"));
    ExpectSubStringMatch("Guildless Frank.*Yo", Player->caughtMessage());
    ExpectSubStringMatch("Guildless Frank.*Yo", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSendEmptyMessageOnGuildLine()
{
    ExpectFalse(Player->executeCommand("guild"));
    ExpectEq(0, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSeeOtherGuildMessages()
{
    object lowlyMage = clone_object("/lib/tests/support/services/mockPlayer.c");
    lowlyMage->Name("dwight");
    lowlyMage->addCommands();
    object guild = load_object("/lib/tests/support/guilds/mageGuild.c");
    guild->init();
    lowlyMage->joinGuild("mage");

    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels->registerUser(lowlyMage);

    ExpectTrue(Player->executeCommand("guild Dwight is an idiot!"));
    ExpectSubStringMatch("Dwight is an idiot", Player->caughtMessage());
    ExpectSubStringMatch("Dwight is an idiot", Bystander->caughtMessage());
    ExpectEq(0, lowlyMage->caughtMessage());
    destruct(lowlyMage);
}

/////////////////////////////////////////////////////////////////////////////
void GuildHelpIsDisplayed()
{
    ExpectTrue(Player->executeCommand("help guild"));
    ExpectSubStringMatch("Send a message to every logged-in player of your guild", 
        Player->caughtMessages()[0]);
}

/////////////////////////////////////////////////////////////////////////////
void CanSpecifyGuildToSendMessageTo()
{
    object lowlyMage = clone_object("/lib/tests/support/services/mockPlayer.c");
    lowlyMage->Name("dwight");
    lowlyMage->addCommands();
    object guild = load_object("/lib/tests/support/guilds/mageGuild.c");
    guild->init();
    lowlyMage->joinGuild("mage");

    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels->registerUser(lowlyMage);

    Player->joinGuild("mage");
    channels->registerUser(Player);

    ExpectTrue(Player->executeCommand("guild -g mage Frank is an idiot!"));
    ExpectSubStringMatch("Frank is an idiot", Player->caughtMessage());
    ExpectEq(0, Bystander->caughtMessage());
    ExpectSubStringMatch("Frank is an idiot", lowlyMage->caughtMessage());
    destruct(lowlyMage);
}

/////////////////////////////////////////////////////////////////////////////
void CanSpecifyLongGuildNameToSendMessageTo()
{
    object lowlyMage = clone_object("/lib/tests/support/services/mockPlayer.c");
    lowlyMage->Name("dwight");
    lowlyMage->addCommands();

    object guild = load_object("/lib/tests/support/guilds/longNameGuild.c");
    guild->init();
    lowlyMage->joinGuild("weaselhookens of yor");

    guild = load_object("/lib/tests/support/guilds/mageGuild.c");
    guild->init();
    lowlyMage->joinGuild("mage");

    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels->registerUser(lowlyMage);

    Player->joinGuild("weaselhookens of yor");
    channels->registerUser(Player);

    ExpectTrue(Player->executeCommand("guild -g weaselhookens of yor Frank is an idiot!"));
    ExpectSubStringMatch("Weaselhookens of yor.*Frank is an idiot", Player->caughtMessage());
    ExpectEq(0, Bystander->caughtMessage());
    ExpectSubStringMatch("Weaselhookens of yor.*Frank is an idiot", lowlyMage->caughtMessage());
    destruct(lowlyMage);
}
