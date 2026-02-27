//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Element;
object Service;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = getService("environment");
    Service.setYear(1);
    Service.setDay(92);
    Service.timeOfDay("noon");

    Element = clone_object("/lib/tests/support/environment/fakeFeature.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Element);
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void DefaultDescriptionDisplaysCorrectly()
{
    ExpectEq("a stand of majestic oak trees with branches laden with acorns, noonishly glowing",
        Element.description("default", Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void AdjectivesPrecededByAAreProperlyExpandedToAn()
{
    object adjectiveTest = clone_object("/lib/tests/support/environment/adjectiveTest.c");

    ExpectEq("an old oak tree",
        adjectiveTest.description("default", Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void DawnDescriptionShowsCorrectTimeOfDay()
{
    Service.timeOfDay("dawn");
    ExpectEq("a stand of oak trees with branches laden with acorns that the faint dawn light is just beginning to illuminate",
        Element.description(0, Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void MorningDescriptionShowsCorrectTimeOfDayAndSeason()
{
    Service.timeOfDay("morning");
    ExpectEq("a stand of majestic oak trees with branches laden with acorns",
        Element.description(0, Service.ambientLight()));

    Service.season("autumn");
    ExpectEq("a stand of majestic oak trees carpeting the ground in fallen leaves of red, yellow, and orange lit from a ray of sunshine piercing through the canopy",
        Element.description(0, Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void NoonDescriptionShowsCorrectTimeOfDay()
{
    Service.timeOfDay("noon");
    ExpectEq("a stand of majestic oak trees with branches laden with acorns, noonishly glowing",
        Element.description(0, Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void WinterAfternoonDescriptionShowsCorrectTimeOfDayAndSeason()
{
    Service.timeOfDay("afternoon");
    Service.season("winter");
    ExpectEq("a stand of majestic oak trees covered with a thick layer of snow, afternooningly dreary",
        Element.description(0, Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void SpringEveningDescriptionShowsCorrectTimeOfDayAndSeason()
{
    Service.timeOfDay("evening");
    Service.season("spring");
    ExpectEq("a stand of majestic oak trees with leaves just beginning to bud, oppressive in its late-day glory",
        Element.description(0, Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void DuskDescriptionShowsCorrectTimeOfDay()
{
    Service.timeOfDay("dusk");
    ExpectEq("a stand of oak trees with branches laden with acorns, the details of which the last failing light of the day barely show",
        Element.description(0, Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void NightDescriptionShowsCorrectTimeOfDay()
{
    Service.timeOfDay("night");
    ExpectEq("the silhouette of deciduous trees outlined in the dark",
        Element.description(0, Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void MidnightDescriptionShowsCorrectTimeOfDayAndChangesForSeason()
{
    Service.timeOfDay("midnight");
    Service.setYear(1);
    Service.season("spring");

    ExpectEq("a massive silhouette of trees outlined in eery black", 
        Element.description("default", Service.ambientLight()), "spring");

    Service.season("summer");
    ExpectEq("the silhouette of deciduous trees outlined in eery black", 
        Element.description("default", Service.ambientLight()), "summer");

    Service.season("autumn");
    ExpectEq("the silhouette of oak trees outlined in eery black. There is a creepy wisp of black energy here",
        Element.description("default", Service.ambientLight()), "autumn");

    Service.season("winter");
    ExpectEq("the silhouette of deciduous trees outlined in eery black", 
        Element.description("default", Service.ambientLight()), "winter");
}

/////////////////////////////////////////////////////////////////////////////
void MidnightDescriptionShowsCorrectTimeOfDayAndChangesForMoonPhases()
{
    Service.timeOfDay("midnight");

    Service.setDay(0);
    ExpectEq("a massive silhouette of trees outlined in eery black",
        Element.description("default", Service.ambientLight()), "new moon");

    Service.setDay(6);
    ExpectEq("the silhouette of deciduous trees outlined in eery black",
        Element.description("default", Service.ambientLight()), "crescent");

    Service.setDay(13);
    ExpectEq("the silhouette of oak trees outlined in eery black",
        Element.description("default", Service.ambientLight()), "full");
}

/////////////////////////////////////////////////////////////////////////////
void StateChangesUpdateDescription()
{
    Service.timeOfDay("dawn");
    Service.season("winter");
    ExpectEq("a stand of charred tree stumps covered with a murky mist that the sickly first rays barely illuminate",
        Element.description("deadified", Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void DefaultDescriptionUsedWhenStateDoesNotHaveDescription()
{
    Service.timeOfDay("dawn");
    Service.season("summer");
    ExpectEq("a stand of oak trees with branches laden with acorns that the faint dawn light is just beginning to illuminate",
        Element.description("blarg", Service.ambientLight()));
}

/////////////////////////////////////////////////////////////////////////////
void DefaultLongDisplaysCorrectly()
{
    ExpectEq("You see many majestic oaks with branches laden with acorns, noonishly glowing.\n",
        Element.long());
}

/////////////////////////////////////////////////////////////////////////////
void LongForStateDisplaysCorrectly()
{
    Service.timeOfDay("night");
    Service.season("winter");

    Element.currentState("deadified");
    ExpectEq("You see many charred tree stumps covered with a murky mist "
        "outlined in the\ndark.\n",
        Element.long());
}

/////////////////////////////////////////////////////////////////////////////
void DefaultAliasesDisplayCorrectly()
{
    ExpectEq(({ "fake feature", "oak", "stand", "stand of oak trees" }),
        Element.aliases());
}

/////////////////////////////////////////////////////////////////////////////
void StateAliasesDisplayCorrectly()
{
    ExpectEq(({ "charred stumps", "fake feature", "stumps", "tree stumps" }),
        Element.aliases("deadified"));
}

/////////////////////////////////////////////////////////////////////////////
void SuppressEntryMessageSetsFlag()
{
    ExpectTrue(Element.displayActionText());
    Element.testSuppressEntryMessage();
    ExpectFalse(Element.displayActionText());
}

/////////////////////////////////////////////////////////////////////////////
void FullyRandomDescriptionsCanBeDisplayed()
{
    object randomTerrain = clone_object(
        "/lib/tests/support/environment/fakeRandomTerrain.c");

    ExpectEq("a cedar grotto", randomTerrain.description("default", 10));
    destruct(randomTerrain);
}

/////////////////////////////////////////////////////////////////////////////
void WhenMessagesAreSuppressedDescriptionCanBeNull()
{
    object itemWithoutDescription = clone_object(
        "/lib/tests/support/environment/itemWithoutDescription.c");

    ExpectFalse(itemWithoutDescription.description());
    destruct(itemWithoutDescription);
}

/////////////////////////////////////////////////////////////////////////////
void GetDescriptionFromSetReturnsCorrectItemDescription()
{
    destruct(Element);
    Element = clone_object("/lib/environment/items/lighting/camp-fire.c");

    ExpectEq("You see the area around the campfire has been cleared away "
        "to place a barrier\nbetween the fire and other combustible objects. "
        "There are charred cinders and\nthe ashen remains of a small campfire.\n",
        Element.long());

    Element.activateLightSource("default", this_object());
    ExpectEq("You see the area around the campfire has been cleared away to "
        "place a barrier\nbetween the fire and other combustible objects. "
        "Flickering tendrils of flame\nroil out from the newly-added logs of "
        "a small camp fire.\n",
        Element.long());

    Element.decayFire("default", this_object());
    Element.decayFire("default", this_object());
    Element.decayFire("default", this_object());
    Element.decayFire("default", this_object());
    Element.decayFire("default", this_object());
    Element.decayFire("default", this_object());
    ExpectEq(2, Element.isSourceOfLight("default", this_object()));
    ExpectEq("You see the area around the campfire has been cleared away to "
        "place a barrier\nbetween the fire and other combustible objects. "
        "Occasional flickers of red\nflame emanate from the faintly glowing "
        "red coals of a small camp fire.\n",
        Element.long());
}

/////////////////////////////////////////////////////////////////////////////
void HarvestableResourcesCorrectlySetUp()
{
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");
    player.Name("bob");
    player.addCommands();
    player.colorConfiguration("none");
    player.charsetConfiguration("ascii");

    object environment =
        clone_object("/lib/tests/support/environment/harvestRoom.c");
    move_object(player, environment);

    Element.create();
    ExpectEq("Name: Acorn\n"
        "This can only be harvested when the season is summer.\n"
        "\n"
        "Name: Mana\n"
        "This can only be harvested when the environment state is deadified.\n"
        "This can only be harvested when you're using: rod, staff, or wand.\n"
        "This can only be harvested when the moon phase is full moon.\n"
        "This can only be harvested when the season is winter.\n"
        "This can only be harvested when your spellcraft skill is at least 5.\n"
        "This can only be harvested when the time of day is midnight.\n"
        "\n"
        "Name: Oak\n"
        "Alias(es): deciduous tree, oak tree, tree\n"
        "This can only be harvested when the environment state is default.\n"
        "This can only be harvested when you're using: axe.\n"
        "This can only be harvested when your forestry skill is at least 5.\n"
        "\n", 
        Element.getHarvestStatistics(player, environment));
}

/////////////////////////////////////////////////////////////////////////////
void HarvestableResourcesReturnsListOfResources()
{
    ExpectEq(({ "acorn", "deciduous tree", "mana", "oak", "oak tree", "tree" }), 
        Element.harvestableResources());
}

/////////////////////////////////////////////////////////////////////////////
void HarvestingUpdatesDescription()
{
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");
    player.Name("bob");
    player.addCommands();
    player.colorConfiguration("none");
    player.charsetConfiguration("ascii");

    player.addSkillPoints(20);
    player.advanceSkill("forestry", 5);

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
        element.description(0, Service.ambientLight(), environment));

    element.harvestResource("oak", player, environment);

    ExpectEq("a heavily-forested stand of oak trees. Several trees "
        "remain with branches laden with acorns, noonishly glowing",
        element.description(0, Service.ambientLight(), environment));
}

/////////////////////////////////////////////////////////////////////////////
void EnvironmentalBonusCorrectlySetUp()
{
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");
    player.Name("bob");
    player.addCommands();
    player.colorConfiguration("none");
    player.charsetConfiguration("ascii");

    object environment =
        clone_object("/lib/tests/support/environment/bonusRoom.c");
    move_object(player, environment);

    Element.create();
    ExpectEq("Name: Hit Points\n"
        "There is a -3 penalty to hit points active.\n"
        "This is only applied when the environment state is deadified.\n"
        "This is only applied when you're using: axe, rod, or wand.\n"
        "This is only applied when the moon phase is full moon.\n"
        "This is only applied when the season is winter.\n"
        "This is only applied when your spellcraft skill is at least 5.\n"
        "This is only applied when the time of day is midnight.\n"
        "\n"
        "Name: Strength\n"
        "There is a +4 bonus to strength active.\n"
        "This is only applied when the season is autumn.\n"
        "This is only applied when the time of day is noon.\n",
        Element.getBonusDescriptions(environment, player));
}
