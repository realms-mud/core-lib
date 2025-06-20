//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cargo hold hatch");
    addAdjectives(({ "heavy", "iron-bound", "wooden", "rectangular", "deck" }));

    addDescriptionTemplate("a ##Adjective## cargo hold hatch set into the deck");

    addTimeOfDayDescription("dawn", ({
        ". The hatch is slick with dew, iron bands glinting in the light",
        ". At dawn, dockhands check the hatch for leaks",
        ". The wood is cool to the touch as the sun rises"
        }));
    addTimeOfDayDescription("noon", ({
        ". The hatch is warm from the sun, wood drying quickly",
        ". The deck bustles as the hatch is opened for loading",
        ". The hatch creaks as it is lifted"
        }));
    addTimeOfDayDescription("night", ({
        ". The hatch is closed and locked, only faintly lit by lanterns",
        ". The air is cool, and the hatch stands silent",
        ". Shadows flicker across the hatch in the night breeze"
        }));

    addSeasonDescription("spring", ({
        " with the hatch freshly oiled for the new season",
        " as the hatch is checked after winter storms",
        " with the air fresh and the hatch ready for cargo"
        }));
    addSeasonDescription("summer", ({
        " with the hatch in constant use, warm from the sun",
        " as the sun beats down, the hatch is a focal point on deck",
        " with the air thick with the scent of tar and wood"
        }));
    addSeasonDescription("autumn", ({
        " with the hatch polished for the last voyages before winter",
        " as the air turns crisp and the hatch is checked for wear",
        " with the deck quieter, but the hatch still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the hatch rimed with frost, wood stiff with cold",
        " as only the hardiest sailors brave the chill to open it",
        " with the hatch covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a cargo hold hatch is set into the deck, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a cargo hold hatch glints in the faint light, iron bands shining"
    );
    addDimLightDescriptionTemplate(
        "a sturdy cargo hold hatch is set into the deck, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept cargo hold hatch is set into the deck"
    );
}
