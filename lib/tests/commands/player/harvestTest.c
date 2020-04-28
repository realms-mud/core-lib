//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "statusMessage" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("ralph");
    Player->Race("elf");
    Player->colorConfiguration("none");
    Player->addCommands();

    move_object(Player, "/lib/tests/support/environment/harvestRoom.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
private string statusMessage()
{
    return "Name: Acorn\n"
        "There are 25 acorn available for harvest.\n"
        "This can only be harvested when the season is summer.\n"
        "\n"
        "Name: Alder\n"
        "Alias(es): deciduous tree, alder tree, tree\n"
        "There are 25 alder available for harvest.\n"
        "This can only be harvested when you're using: axe.\n"
        "\n"
        "Name: Alder Catkin\n"
        "There are 25 alder catkin available for harvest.\n"
        "This can only be harvested when the season is summer.\n"
        "\n"
        "Name: Mana\n"
        "There are 5 mana available for harvest.\n"
        "This can only be harvested when the environment state is deadified.\n"
        "This can only be harvested when you're using: rod, staff, or wand.\n"
        "This can only be harvested when the moon phase is full moon.\n"
        "This can only be harvested when the season is winter.\n"
        "This can only be harvested when your spellcraft skill is at least 5.\n"
        "This can only be harvested when the time of day is midnight.\n"
        "\n"
        "Name: Oak\n"
        "Alias(es): deciduous tree, oak tree, tree\n"
        "There are 25 oak available for harvest.\n"
        "This can only be harvested when the environment state is default.\n"
        "This can only be harvested when you're using: axe.\n"
        "This can only be harvested when your forestry skill is at least 5.\n\n";
}

/////////////////////////////////////////////////////////////////////////////
void HarvestWithNoArgumentsReturnsStatus()
{
    command("harvest", Player);

    ExpectEq(statusMessage(), Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HarvestWithStatusFlagReturnsStatus()
{
    command("harvest -s", Player);
    ExpectEq(statusMessage(), Player->caughtMessage());

    command("harvest -status", Player);
    ExpectEq(statusMessage(), Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HarvestWithStatusFlagForSingleItemReturnsSpecificStatus()
{
    command("harvest -s oak", Player);
    ExpectEq("Name: Oak\n"
        "Alias(es): deciduous tree, oak tree, tree\n"
        "There are 25 oak available for harvest.\n"
        "This can only be harvested when the environment state is default.\n"
        "This can only be harvested when you're using: axe.\n"
        "This can only be harvested when your forestry skill is at least 5.\n\n", 
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HarvestFailsIfPrerequisitesNotMet()
{
    Player->resetCatchList();
    command("harvest oak", Player);

    ExpectEq(({
        "You cannot harvest oak.\n",
        "You must be using the proper equipment for that (axe).\n",
        "You need a minimum of 5 in forestry to do that.\n"
        }),
        Player->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void HarvestFailsIfOnlySomePrerequisitesNotMet()
{

    object axe = clone_object("/lib/instances/items/weapons/axes/axe.c");
    move_object(axe, Player);
    command("wield axe", Player);
    Player->resetCatchList();

    command("harvest oak", Player);

    ExpectEq(({
        "You cannot harvest oak.\n",
        "You need a minimum of 5 in forestry to do that.\n"
        }),
        Player->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void HarvestSucceedsIfLimitersAllMet()
{

    object axe = clone_object("/lib/instances/items/weapons/axes/axe.c");
    move_object(axe, Player);
    command("wield axe", Player);
    Player->resetCatchList();

    Player->addSkillPoints(20);
    Player->advanceSkill("forestry", 5);

    ExpectFalse(present("oak", Player));
    command("harvest oak", Player);
    ExpectTrue(present("oak", Player));

    ExpectEq("You harvest some oak.\n", Player->caughtMessage());
}
