//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("capstan");
    addAdjectives(({ "sturdy", "wooden", "iron-banded", "massive", "deck" }));

    addDescriptionTemplate("a ##Adjective## capstan for raising anchors and heavy cargo");

    addTimeOfDayDescription("dawn", ({
        ". The capstan is slick with dew, wood glistening in the light",
        ". At dawn, sailors check the capstan for wear",
        ". The iron bands are cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The capstan is warm from the sun, wood drying quickly",
        ". The deck bustles as the capstan is turned by strong arms",
        ". The capstan creaks as it raises the anchor"
        }));
    addTimeOfDayDescription("night", ({
        ". The capstan is silent, only faintly lit by lanterns",
        ". The air is cool, and the capstan stands ready for use",
        ". Shadows flicker across the capstan in the night breeze"
        }));

    addSeasonDescription("spring", ({
        " with the capstan freshly oiled for the new season",
        " as the capstan is checked after winter storms",
        " with the air fresh and the capstan ready for work"
        }));
    addSeasonDescription("summer", ({
        " with the capstan in constant use, warm from the sun",
        " as the sun beats down, the capstan is a focal point on deck",
        " with the air thick with the scent of tar and wood"
        }));
    addSeasonDescription("autumn", ({
        " with the capstan polished for the last voyages before winter",
        " as the air turns crisp and the capstan is checked for wear",
        " with the deck quieter, but the capstan still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the capstan rimed with frost, wood stiff with cold",
        " as only the hardiest sailors brave the chill to use it",
        " with the capstan covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a capstan stands on the deck, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a capstan glints in the faint light, iron bands shining"
    );
    addDimLightDescriptionTemplate(
        "a sturdy capstan stands on the deck, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept capstan stands at the center of the deck"
    );
}
