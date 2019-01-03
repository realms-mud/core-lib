//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Element;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    Element = clone_object("/lib/tests/support/environment/testLightSource.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Element);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void DefaultIsNotLit()
{
    ExpectFalse(Element->isSourceOfLight());
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceWithOnlyMagnitudeSetsLightForAllStates()
{
    Element->testAddSourceOfLight(1);
    ExpectTrue(Element->isSourceOfLight());

    Dictionary->timeOfDay("dawn");
    Dictionary->season("winter");
    ExpectTrue(Element->isSourceOfLight());
    ExpectTrue(Element->isSourceOfLight("some state"));
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificStateDoesNotLightOtherStates()
{
    Element->testAddSourceOfLight(1, "some state");
    ExpectFalse(Element->isSourceOfLight());
    ExpectTrue(Element->isSourceOfLight("some state"));

    Dictionary->timeOfDay("dawn");
    Dictionary->season("winter");
    ExpectFalse(Element->isSourceOfLight());
    ExpectTrue(Element->isSourceOfLight("some state"));
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificTimeDoesNotLightOtherTimes()
{
    Element->testAddSourceOfLight(1, 0, "midnight");
    ExpectFalse(Element->isSourceOfLight());

    Dictionary->timeOfDay("midnight");
    ExpectTrue(Element->isSourceOfLight());
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificSeasonDoesNotLightOtherSeasons()
{
    Element->testAddSourceOfLight(1, 0, 0, "winter");
    ExpectFalse(Element->isSourceOfLight());

    Dictionary->season("winter");
    ExpectTrue(Element->isSourceOfLight());
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificTimeAndSeasonDoesNotLightOthers()
{
    Element->testAddSourceOfLight(1, 0, "midnight", "winter");
    ExpectFalse(Element->isSourceOfLight());

    Dictionary->season("winter");
    ExpectFalse(Element->isSourceOfLight());

    Dictionary->timeOfDay("midnight");
    ExpectTrue(Element->isSourceOfLight());

    Dictionary->season("spring");
    ExpectFalse(Element->isSourceOfLight());
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificTimeAndSeasonAndStateDoesNotLightOthers()
{
    Element->testAddSourceOfLight(1, "some state", "midnight", "winter");
    ExpectFalse(Element->isSourceOfLight());
    ExpectFalse(Element->isSourceOfLight("some state"));

    Dictionary->season("winter");
    ExpectFalse(Element->isSourceOfLight());
    ExpectFalse(Element->isSourceOfLight("some state"));

    Dictionary->timeOfDay("midnight");
    ExpectFalse(Element->isSourceOfLight());
    ExpectTrue(Element->isSourceOfLight("some state"));

    Dictionary->season("spring");
    ExpectFalse(Element->isSourceOfLight());
    ExpectFalse(Element->isSourceOfLight("some state"));
}
