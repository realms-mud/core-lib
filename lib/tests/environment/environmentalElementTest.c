//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Element;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    Dictionary->setYear(1);
    Dictionary->setDay(92);
    Dictionary->timeOfDay("noon");

    Element = clone_object("/lib/tests/support/environment/fakeFeature.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Element);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void DefaultDescriptionDisplaysCorrectly()
{
    ExpectEq("a stand of majestic oak trees with branches laden with acorns, noonishly glowing",
        Element->description("default", Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void DawnDescriptionShowsCorrectTimeOfDay()
{
    Dictionary->timeOfDay("dawn");
    ExpectEq("a stand of oak trees with branches laden with acorns that the faint dawn light is just beginning to illuminate",
        Element->description(0, Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void MorningDescriptionShowsCorrectTimeOfDayAndSeason()
{
    Dictionary->timeOfDay("morning");
    ExpectEq("a stand of majestic oak trees with branches laden with acorns",
        Element->description(0, Dictionary->ambientLight()));

    Dictionary->season("autumn");
    ExpectEq("a stand of majestic oak trees carpeting the ground in fallen leaves of red, yellow, and orange lit from a ray of sunshine piercing through the canopy",
        Element->description(0, Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void NoonDescriptionShowsCorrectTimeOfDay()
{
    Dictionary->timeOfDay("noon");
    ExpectEq("a stand of majestic oak trees with branches laden with acorns, noonishly glowing",
        Element->description(0, Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void WinterAfternoonDescriptionShowsCorrectTimeOfDayAndSeason()
{
    Dictionary->timeOfDay("afternoon");
    Dictionary->season("winter");
    ExpectEq("a stand of majestic oak trees covered with a thick layer of snow, afternooningly dreary",
        Element->description(0, Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void SpringEveningDescriptionShowsCorrectTimeOfDayAndSeason()
{
    Dictionary->timeOfDay("evening");
    Dictionary->season("spring");
    ExpectEq("a stand of majestic oak trees with leaves just beginning to bud, oppressive in its late-day glory",
        Element->description(0, Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void DuskDescriptionShowsCorrectTimeOfDay()
{
    Dictionary->timeOfDay("dusk");
    ExpectEq("a stand of oak trees with branches laden with acorns, the details of which the last failing light of the day barely show",
        Element->description(0, Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void NightDescriptionShowsCorrectTimeOfDay()
{
    Dictionary->timeOfDay("night");
    ExpectEq("the silhouette of deciduous trees outlined in the dark",
        Element->description(0, Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void MidnightDescriptionShowsCorrectTimeOfDayAndChangesForSeason()
{
    Dictionary->timeOfDay("midnight");
    Dictionary->setYear(1);
    Dictionary->season("spring");

    ExpectEq("a massive silhouette of trees outlined in eery black", 
        Element->description("default", Dictionary->ambientLight()), "spring");

    Dictionary->season("summer");
    ExpectEq("the silhouette of deciduous trees outlined in eery black", 
        Element->description("default", Dictionary->ambientLight()), "summer");

    Dictionary->season("autumn");
    ExpectEq("the silhouette of oak trees outlined in eery black. There is a creepy wisp of black energy here",
        Element->description("default", Dictionary->ambientLight()), "autumn");

    Dictionary->season("winter");
    ExpectEq("the silhouette of deciduous trees outlined in eery black", 
        Element->description("default", Dictionary->ambientLight()), "winter");
}

/////////////////////////////////////////////////////////////////////////////
void MidnightDescriptionShowsCorrectTimeOfDayAndChangesForMoonPhases()
{
    Dictionary->timeOfDay("midnight");

    Dictionary->setDay(0);
    ExpectEq("a massive silhouette of trees outlined in eery black",
        Element->description("default", Dictionary->ambientLight()), "new moon");

    Dictionary->setDay(6);
    ExpectEq("the silhouette of deciduous trees outlined in eery black",
        Element->description("default", Dictionary->ambientLight()), "crescent");

    Dictionary->setDay(13);
    ExpectEq("the silhouette of oak trees outlined in eery black",
        Element->description("default", Dictionary->ambientLight()), "full");
}

/////////////////////////////////////////////////////////////////////////////
void StateChangesUpdateDescription()
{
    Dictionary->timeOfDay("dawn");
    Dictionary->season("winter");
    ExpectEq("a stand of charred tree stumps covered with a murky mist that the sickly first rays barely illuminate",
        Element->description("deadified", Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void DefaultDescriptionUsedWhenStateDoesNotHaveDescription()
{
    Dictionary->timeOfDay("dawn");
    Dictionary->season("summer");
    ExpectEq("a stand of oak trees with branches laden with acorns that the faint dawn light is just beginning to illuminate",
        Element->description("blarg", Dictionary->ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void DefaultLongDisplaysCorrectly()
{
    ExpectEq("You see many majestic oaks with branches laden with acorns, noonishly glowing.\n",
        Element->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongForStateDisplaysCorrectly()
{
    Dictionary->timeOfDay("night");
    Dictionary->season("winter");

    Element->currentState("deadified");
    ExpectEq("You see many charred tree stumps covered with a murky mist "
        "outlined in the\ndark.\n",
        Element->long());
}

/////////////////////////////////////////////////////////////////////////////
void DefaultAliasesDisplayCorrectly()
{
    ExpectEq(({ "fake feature", "oak", "stand", "stand of oak trees" }),
        Element->aliases());
}

/////////////////////////////////////////////////////////////////////////////
void StateAliasesDisplayCorrectly()
{
    ExpectEq(({ "charred stumps", "fake feature", "stumps", "tree stumps" }),
        Element->aliases("deadified"));
}

/////////////////////////////////////////////////////////////////////////////
void SuppressEntryMessageSetsFlag()
{
    ExpectTrue(Element->displayActionText());
    Element->testSuppressEntryMessage();
    ExpectFalse(Element->displayActionText());
}

/////////////////////////////////////////////////////////////////////////////
void FullyRandomDescriptionsCanBeDisplayed()
{
    object randomTerrain = clone_object(
        "/lib/tests/support/environment/fakeRandomTerrain.c");

    ExpectEq("a cedar grotto", randomTerrain->description("default", 10));
    destruct(randomTerrain);
}

/////////////////////////////////////////////////////////////////////////////
void WhenMessagesAreSuppressedDescriptionCanBeNull()
{
    object itemWithoutDescription = clone_object(
        "/lib/tests/support/environment/itemWithoutDescription.c");

    ExpectFalse(itemWithoutDescription->description());
    destruct(itemWithoutDescription);
}

/////////////////////////////////////////////////////////////////////////////
void GetDescriptionFromSetReturnsCorrectItemDescription()
{
    destruct(Element);
    Element = clone_object("/lib/environment/items/camp-fire.c");

    ExpectEq("You see the area around the campfire has been cleared away "
        "to place a barrier\nbetween the fire and other combustible objects. "
        "There are charred cinders and\nthe ashen remains of a small campfire.\n",
        Element->long());

    Element->activateLightSource("default", this_object());
    ExpectEq("You see the area around the campfire has been cleared away to "
        "place a barrier\nbetween the fire and other combustible objects. "
        "Flickering tendrils of flame\nroil out from the newly-added logs of "
        "a small camp fire.\n",
        Element->long());

    Element->decayFire("default", this_object());
    Element->decayFire("default", this_object());
    Element->decayFire("default", this_object());
    Element->decayFire("default", this_object());
    Element->decayFire("default", this_object());
    Element->decayFire("default", this_object());
    ExpectEq(2, Element->isSourceOfLight("default", this_object()));
    ExpectEq("You see the area around the campfire has been cleared away to "
        "place a barrier\nbetween the fire and other combustible objects. "
        "Occasional flickers of red\nflame emanate from the faintly glowing "
        "red coals of a small camp fire.\n",
        Element->long());
}


/////////////////////////////////////////////////////////////////////////////
void HarvestableResourcesCorrectlySetUp()
{
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");
    player->Name("bob");
    player->addCommands();
    player->colorConfiguration("none");
    player->charsetConfiguration("ascii");

    object environment =
        clone_object("/lib/tests/support/environment/harvestRoom.c");
    move_object(player, environment);

    Element->reset();
    ExpectEq("Name: Oak\n"
        "Alias(es): deciduous tree, oak tree, tree\n"
        "This can only be harvested when the environment state is default.\n"
        "This can only be harvested when you're using: axe.\n"
        "This can only be harvested when your forestry skill is at least 5.\n"
        "\n"
        "Name: Acorn\n"
        "This can only be harvested when the season is summer.\n"
        "\n"
        "Name: Mana\n"
        "This can only be harvested when the environment state is deadified.\n"
        "This can only be harvested when you're using: rod, staff, or wand.\n"
        "This can only be harvested when the moon phase is full moon.\n"
        "This can only be harvested when the season is winter.\n"
        "This can only be harvested when your spellcraft skill is at least 5.\n"
        "This can only be harvested when the time of day is midnight.\n"
        "\n", 
        Element->getHarvestStatistics(player, environment));
}

/////////////////////////////////////////////////////////////////////////////
void HarvestableResourcesReturnsListOfResources()
{
    ExpectEq(({ "acorn", "deciduous tree", "mana", "oak", "oak tree", "tree" }), 
        Element->harvestableResources());
}

/////////////////////////////////////////////////////////////////////////////
void HarvestingUpdatesDescription()
{
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");
    player->Name("bob");
    player->addCommands();
    player->colorConfiguration("none");
    player->charsetConfiguration("ascii");

    player->addSkillPoints(20);
    player->advanceSkill("forestry", 5);

    object axe = clone_object("/lib/instances/items/weapons/axes/axe.c");
    move_object(axe, player);
    command("equip axe", player);

    object element = 
        load_object("/lib/tests/support/environment/fakeFeature.c");
    object environment =
        clone_object("/lib/tests/support/environment/harvestRoom.c");
    move_object(player, environment);

    ExpectEq("a stand of majestic oak trees with branches laden with "
        "acorns, noonishly glowing",
        element->description(0, Dictionary->ambientLight(), environment));

    element->harvestResource("oak", player, environment);

    ExpectEq("a heavily-forested stand of oak trees. Several trees "
        "remain with branches laden with acorns, noonishly glowing",
        element->description(0, Dictionary->ambientLight(), environment));
}
