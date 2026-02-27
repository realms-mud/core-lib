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

    Element = clone_object("/lib/tests/support/environment/testLightSource.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Element);
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void DefaultIsNotLit()
{
    ExpectFalse(Element.isSourceOfLight());
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceWithOnlyMagnitudeSetsLightForAllStates()
{
    Element.testAddSourceOfLight(1);
    ExpectTrue(Element.isSourceOfLight());

    Service.timeOfDay("dawn");
    Service.season("winter");
    ExpectTrue(Element.isSourceOfLight());
    ExpectTrue(Element.isSourceOfLight("some state"));
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificStateDoesNotLightOtherStates()
{
    Element.testAddSourceOfLight(1, "some state");
    ExpectFalse(Element.isSourceOfLight());
    ExpectTrue(Element.isSourceOfLight("some state"));

    Service.timeOfDay("dawn");
    Service.season("winter");
    ExpectFalse(Element.isSourceOfLight());
    ExpectTrue(Element.isSourceOfLight("some state"));
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificTimeDoesNotLightOtherTimes()
{
    Element.testAddSourceOfLight(1, 0, "midnight");
    ExpectFalse(Element.isSourceOfLight());

    Service.timeOfDay("midnight");
    ExpectTrue(Element.isSourceOfLight());
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificSeasonDoesNotLightOtherSeasons()
{
    Element.testAddSourceOfLight(1, 0, 0, "winter");
    ExpectFalse(Element.isSourceOfLight());

    Service.season("winter");
    ExpectTrue(Element.isSourceOfLight());
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificTimeAndSeasonDoesNotLightOthers()
{
    Element.testAddSourceOfLight(1, 0, "midnight", "winter");
    ExpectFalse(Element.isSourceOfLight());

    Service.season("winter");
    ExpectFalse(Element.isSourceOfLight());

    Service.timeOfDay("midnight");
    ExpectTrue(Element.isSourceOfLight());

    Service.season("spring");
    ExpectFalse(Element.isSourceOfLight());
}

/////////////////////////////////////////////////////////////////////////////
void AddSourceForSpecificTimeAndSeasonAndStateDoesNotLightOthers()
{
    Element.testAddSourceOfLight(1, "some state", "midnight", "winter");
    ExpectFalse(Element.isSourceOfLight());
    ExpectFalse(Element.isSourceOfLight("some state"));

    Service.season("winter");
    ExpectFalse(Element.isSourceOfLight());
    ExpectFalse(Element.isSourceOfLight("some state"));

    Service.timeOfDay("midnight");
    ExpectFalse(Element.isSourceOfLight());
    ExpectTrue(Element.isSourceOfLight("some state"));

    Service.season("spring");
    ExpectFalse(Element.isSourceOfLight());
    ExpectFalse(Element.isSourceOfLight("some state"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSetActiveLighting()
{
    Element.testAddActiveSourceOfLight(8, "a light");

    ExpectEq("an extinguished light", Element.description("default", 1,
        this_object()));

    Element.activateLightSource("default", this_object());

    ExpectEq("a light", Element.description("default", 1,
        this_object()));
    ExpectEq(8, Element.lightSourceIsActive("default", this_object()));
    ExpectEq(8, Element.isSourceOfLight("default", this_object()));
}

/////////////////////////////////////////////////////////////////////////////
void CanDeactivateLighting()
{
    Element.testAddActiveSourceOfLight(8, "a light");

    Element.activateLightSource("default", this_object());

    ExpectEq("a light", Element.description("default", 1,
        this_object()));

    Element.deactivateLightSource("default", this_object());

    ExpectEq("an extinguished light", Element.description("default", 1,
        this_object()));
    ExpectEq(0, Element.lightSourceIsActive("default", this_object()));
    ExpectEq(0, Element.isSourceOfLight("default", this_object()));
}

/////////////////////////////////////////////////////////////////////////////
void ActiveAndInactiveLightSourcesCorrectlyDisplayed()
{
    Element.testAddSourceOfLight(5);
    Element.testAddActiveSourceOfLight(8, "a light");

    ExpectEq("an extinguished light", Element.description("default", 1,
        this_object()));
    ExpectEq(0, Element.lightSourceIsActive("default", this_object()));
    ExpectEq(5, Element.isSourceOfLight("default", this_object()));

    Element.activateLightSource("default", this_object());
    ExpectEq("a light", Element.description("default", 1,
        this_object()));
    ExpectEq(8, Element.lightSourceIsActive("default", this_object()));
    ExpectEq(8, Element.isSourceOfLight("default", this_object()));

    Element.deactivateLightSource("default", this_object());
    ExpectEq("an extinguished light", Element.description("default", 1,
        this_object()));
    ExpectEq(0, Element.lightSourceIsActive("default", this_object()));
    ExpectEq(5, Element.isSourceOfLight("default", this_object()));
}

/////////////////////////////////////////////////////////////////////////////
void CanSetActiveDecayingLighting()
{
    destruct(Element);
    Element = clone_object("/lib/environment/items/lighting/camp-fire.c");

    ExpectEq("there are charred cinders and the ashen remains of a small "
        "campfire", 
        Element.description("default", 1, this_object()));

    Element.activateLightSource("default", this_object());

    ExpectEq("flickering tendrils of flame roil out from the newly-added "
        "logs of a small camp fire", 
        Element.description("default", 1, this_object()));
    ExpectEq(8, Element.lightSourceIsActive("default", this_object()));
    ExpectEq(8, Element.isSourceOfLight("default", this_object()));

    Element.decayFire("default", this_object());
    ExpectEq("flickering tendrils of flame roil out from the slightly-"
        "charred logs of a small camp fire",
        Element.description("default", 1, this_object()));
    ExpectEq(7, Element.lightSourceIsActive("default", this_object()));
    ExpectEq(7, Element.isSourceOfLight("default", this_object()));
}

/////////////////////////////////////////////////////////////////////////////
void ActiveDecayingLightingWillResetToNoLight()
{
    destruct(Element);
    Element = clone_object("/lib/environment/items/lighting/camp-fire.c");

    ExpectEq("there are charred cinders and the ashen remains of a small "
        "campfire",
        Element.description("default", 1, this_object()));

    Element.activateLightSource("default", this_object());
    ExpectEq(8, Element.isSourceOfLight("default", this_object()));

    Element.decayFire("default", this_object());
    ExpectEq(7, Element.isSourceOfLight("default", this_object()));

    Element.decayFire("default", this_object());
    ExpectEq(6, Element.isSourceOfLight("default", this_object()));

    Element.decayFire("default", this_object());
    ExpectEq(5, Element.isSourceOfLight("default", this_object()));

    Element.decayFire("default", this_object());
    ExpectEq(4, Element.isSourceOfLight("default", this_object()));

    Element.decayFire("default", this_object());
    ExpectEq(3, Element.isSourceOfLight("default", this_object()));

    Element.decayFire("default", this_object());
    ExpectEq(2, Element.isSourceOfLight("default", this_object()));
    ExpectEq("occasional flickers of red flame emanate from the faintly "
        "glowing red coals of a small camp fire",
        Element.description("default", 1, this_object()));

    Element.decayFire("default", this_object());
    ExpectEq(1, Element.isSourceOfLight("default", this_object()));

    Element.decayFire("default", this_object());
    ExpectEq(0, Element.isSourceOfLight("default", this_object()));
}
