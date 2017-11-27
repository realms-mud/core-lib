//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Element;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
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
        Element->description());
}

/////////////////////////////////////////////////////////////////////////////
void DawnDescriptionShowsCorrectTimeOfDay()
{
    Dictionary->timeOfDay("dawn");
    ExpectEq("a stand of majestic oak trees with branches laden with acorns that the faint dawn light is just beginning to illuminate",
        Element->description());
}

/////////////////////////////////////////////////////////////////////////////
void MorningDescriptionShowsCorrectTimeOfDayAndSeason()
{
    Dictionary->timeOfDay("morning");
    ExpectEq("a stand of majestic oak trees with branches laden with acorns",
        Element->description());

    Dictionary->season("autumn");
    ExpectEq("a stand of majestic oak trees carpeting the ground in fallen leaves of red, yellow, and orange lit from a ray of sunshine piercing through the canopy",
        Element->description());
}

/////////////////////////////////////////////////////////////////////////////
void NoonDescriptionShowsCorrectTimeOfDay()
{
    Dictionary->timeOfDay("noon");
    ExpectEq("a stand of majestic oak trees with branches laden with acorns, noonishly glowing",
        Element->description());
}

/////////////////////////////////////////////////////////////////////////////
void WinterAfternoonDescriptionShowsCorrectTimeOfDayAndSeason()
{
    Dictionary->timeOfDay("afternoon");
    Dictionary->season("winter");
    ExpectEq("a stand of majestic oak trees covered with a thick layer of snow, afternooningly dreary",
        Element->description());
}

/////////////////////////////////////////////////////////////////////////////
void SpringEveningDescriptionShowsCorrectTimeOfDayAndSeason()
{
    Dictionary->timeOfDay("evening");
    Dictionary->season("spring");
    ExpectEq("a stand of majestic oak trees with leaves just beginning to bud, oppressive in its late-day glory",
        Element->description());
}

/////////////////////////////////////////////////////////////////////////////
void DuskDescriptionShowsCorrectTimeOfDay()
{
    Dictionary->timeOfDay("dusk");
    ExpectEq("a stand of majestic oak trees with branches laden with acorns, the details of which the last failing light of the day barely show",
        Element->description());
}

/////////////////////////////////////////////////////////////////////////////
void NightDescriptionShowsCorrectTimeOfDay()
{
    Dictionary->timeOfDay("night");
    ExpectEq("a stand of oak trees outlined in the dark",
        Element->description());
}

/////////////////////////////////////////////////////////////////////////////
void MidnightDescriptionShowsCorrectTimeOfDayAndChangesForSeason()
{
    Dictionary->timeOfDay("midnight");

    Dictionary->season("spring");
    ExpectEq("a stand of oak trees outlined in eery black", Element->description());

    Dictionary->season("summer");
    ExpectEq("a stand of oak trees outlined in eery black", Element->description());

    Dictionary->season("autumn");
    ExpectEq("a stand of oak trees outlined in eery black. There is a creepy wisp of black energy here",
        Element->description());

    Dictionary->season("winter");
    ExpectEq("a stand of oak trees outlined in eery black", Element->description());
}

/////////////////////////////////////////////////////////////////////////////
void StateChangesUpdateDescription()
{
    Dictionary->timeOfDay("dawn");
    Dictionary->season("winter");
    ExpectEq("a stand of charred tree stumps covered with a murky mist that the sickly first rays barely illuminate",
        Element->description("deadified"));
}

/////////////////////////////////////////////////////////////////////////////
void DefaultDescriptionUsedWhenStateDoesNotHaveDescription()
{
    Dictionary->timeOfDay("dawn");
    Dictionary->season("summer");
    ExpectEq("a stand of majestic oak trees with branches laden with acorns that the faint dawn light is just beginning to illuminate",
        Element->description("blarg"));
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
    ExpectEq("You see many charred tree stumps outlined in the dark.\n",
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
