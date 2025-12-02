//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sail bundle");
    addAdjectives(({ "heavy", "canvas", "rolled", "spare", "tightly-bound" }));

    addDescriptionTemplate("a ##Adjective## sail bundle lashed to the deck");

    addTimeOfDayDescription("dawn", ({
        ". The sail bundle is damp with dew, canvas cool to the touch",
        ". At dawn, sailors check the bundle for tears",
        ". The bundle rests in the shadow of the mast"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sail bundle is warm from the sun, canvas drying quickly",
        ". The deck bustles as the bundle is moved for repairs",
        ". The bundle is checked for wear and damage"
        }));
    addTimeOfDayDescription("night", ({
        ". The sail bundle is barely visible in the darkness",
        ". The air is cool, and the canvas is stiff with dew",
        ". Lanterns cast dim light on the bundle, shadows flickering"
        }));

    addSeasonDescription("spring", ({
        " with the sail bundle freshly mended for the new season",
        " as the canvas is checked after winter storms",
        " with the air fresh and the bundle ready for use"
        }));
    addSeasonDescription("summer", ({
        " with the sail bundle in constant use, drying quickly in the sun",
        " as the sun beats down, the bundle is a common sight",
        " with the air thick with the scent of canvas and tar"
        }));
    addSeasonDescription("autumn", ({
        " with the sail bundle checked for wear before winter",
        " as the air turns crisp and the canvas is retied",
        " with the deck quieter, but the bundle still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the sail bundle rimed with frost, canvas stiff with cold",
        " as only the hardiest sailors brave the chill to move it",
        " with the bundle covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a sail bundle is lashed to the deck, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a sail bundle glints in the faint light, canvas shining"
    );
    addDimLightDescriptionTemplate(
        "a heavy sail bundle is lashed to the deck, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept sail bundle is lashed to the deck, ready for repairs"
    );
}
