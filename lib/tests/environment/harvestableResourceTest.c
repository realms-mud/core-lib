//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Resource;
object Player;
object Environment;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("none");
    Player->charsetConfiguration("ascii");

    Environment = clone_object("/lib/tests/support/environment/harvestRoom.c");
    move_object(Player, Environment);

    Resource = clone_object("/lib/environment/harvestableResource.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Resource);
    destruct(Player);
    destruct(Environment);
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidResourceFileThrowsError()
{
    string error = catch (Resource->setup("alder", 25, 
        "/lib/environment/environment.c", "description", ({ "tree" })));

    ExpectEq("*EnvironmentalElement: The resource "
        "\"/lib/environment/environment.c\" must exist and be clonable.\n", 
        error);
}

/////////////////////////////////////////////////////////////////////////////
void CanSetUpHarvestableResource()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->resetQuantity(Environment);
    ExpectEq("Name: Yew\n"
        "There are 25 yew available for harvest.\n", 
        Resource->getHarvestStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitHarvestableResourceBySeason()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->limitHarvestBySeason("autumn");

    Resource->resetQuantity(Environment);
    ExpectEq("Name: Yew\n"
        "There are 25 yew available for harvest.\n"
        "This can only be harvested when the season is autumn.\n",
        Resource->getHarvestStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitHarvestableResourceByMoonPhase()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->limitHarvestByMoonPhase("new moon");
    Resource->limitHarvestByMoonPhase("waxing crescent");
    Resource->limitHarvestByMoonPhase("waning crescent");

    Resource->resetQuantity(Environment);
    ExpectEq("Name: Yew\n"
        "There are 25 yew available for harvest.\n"
        "This can only be harvested when the moon phase is one of new moon, "
        "waning\ncrescent, or waxing crescent.\n",
        Resource->getHarvestStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitHarvestableResourceByTimeOfDay()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->limitHarvestByTimeOfDay("noon");

    Resource->resetQuantity(Environment);
    ExpectEq("Name: Yew\n"
        "There are 25 yew available for harvest.\n"
        "This can only be harvested when the time of day is noon.\n",
        Resource->getHarvestStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitHarvestableResourceByState()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->limitHarvestByState("exploited");

    Resource->resetQuantity(Environment);
    ExpectEq("Name: Yew\n"
        "There are 25 yew available for harvest.\n"
        "This can only be harvested when the environment state is exploited.\n",
        Resource->getHarvestStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitHarvestableResourceBySkills()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->limitHarvestBySkill("forestry", 5);
    Resource->limitHarvestBySkill("agriculture", 3);

    Resource->resetQuantity(Environment);
    ExpectEq("Name: Yew\n"
        "There are 25 yew available for harvest.\n"
        "This can only be harvested when your agriculture skill is at least 3.\n"
        "This can only be harvested when your forestry skill is at least 5.\n",
        Resource->getHarvestStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitHarvestableResourceByTool()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->limitHarvestByTool("axe");

    Resource->resetQuantity(Environment);
    ExpectEq("Name: Yew\n"
        "There are 25 yew available for harvest.\n"
        "This can only be harvested when you're using: axe.\n",
        Resource->getHarvestStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitHarvestableResourceByOneOfTools()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->limitHarvestByOneOfTools(({ "axe", "sword", "pole-arm" }));

    Resource->resetQuantity(Environment);
    ExpectEq("Name: Yew\n"
        "There are 25 yew available for harvest.\n"
        "This can only be harvested when you're using: axe, sword, or pole-arm.\n",
        Resource->getHarvestStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void IsHarvestableResourceReturnsCorrectly()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    ExpectFalse(Resource->isHarvestableResource("yew", Player, Environment));
    ExpectFalse(Resource->isHarvestableResource("conifer", Player, Environment));
    ExpectFalse(Resource->isHarvestableResource("evergreen", Player, Environment));
    ExpectFalse(Resource->isHarvestableResource("yew tree", Player, Environment));
    ExpectFalse(Resource->isHarvestableResource("tree", Player, Environment));

    Resource->resetQuantity(Environment);

    ExpectTrue(Resource->isHarvestableResource("yew", Player, Environment));
    ExpectTrue(Resource->isHarvestableResource("conifer", Player, Environment));
    ExpectTrue(Resource->isHarvestableResource("evergreen", Player, Environment));
    ExpectTrue(Resource->isHarvestableResource("yew tree", Player, Environment));
    ExpectTrue(Resource->isHarvestableResource("tree", Player, Environment));
    ExpectFalse(Resource->isHarvestableResource("weasel", Player, Environment));
}

/////////////////////////////////////////////////////////////////////////////
void IsHarvestableResourceReturnsCorrectlyWhenStateSet()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->resetQuantity(Environment);
    Resource->limitHarvestByState("exploited");

    ExpectFalse(Resource->isHarvestableResource("yew", Player, Environment));

    Environment->currentState("exploited");
    ExpectTrue(Resource->isHarvestableResource("yew", Player, Environment));
}

/////////////////////////////////////////////////////////////////////////////
void IsHarvestableResourceReturnsCorrectlyWhenMoonPhaseSet()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->resetQuantity(Environment);
    Resource->limitHarvestByMoonPhase("waxing crescent");

    ExpectFalse(Resource->isHarvestableResource("yew", Player, Environment));

    object dictionary = getDictionary("environment");
    dictionary->setDay(2);

    ExpectTrue(Resource->isHarvestableResource("yew", Player, Environment));

    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void IsHarvestableResourceReturnsCorrectlyWhenTimeOfDaySet()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->resetQuantity(Environment);
    Resource->limitHarvestByTimeOfDay("noon");

    object dictionary = getDictionary("environment");
    dictionary->timeOfDay("morning");

    ExpectFalse(Resource->isHarvestableResource("yew", Player, Environment));

    dictionary->timeOfDay("noon");
    ExpectTrue(Resource->isHarvestableResource("yew", Player, Environment));

    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void IsHarvestableResourceReturnsCorrectlyWhenSeasonSet()
{
    Resource->setup("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain",
        ({ "conifer", "evergreen", "yew tree", "tree" }));

    Resource->resetQuantity(Environment);
    Resource->limitHarvestBySeason("autumn");

    object dictionary = getDictionary("environment");
    dictionary->setDay(20);

    ExpectFalse(Resource->isHarvestableResource("yew", Player, Environment));

    dictionary->setDay(260);
    ExpectTrue(Resource->isHarvestableResource("yew", Player, Environment));

    destruct(dictionary);
}
