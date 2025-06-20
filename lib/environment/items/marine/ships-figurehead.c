//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ship's figurehead");
    addAdjectives(({ "carved", "ornate", "painted", "mythical", "prow" }));

    addDescriptionTemplate("a ##Adjective## ship's figurehead mounted at the prow");

    addTimeOfDayDescription("dawn", ({
        ". The figurehead is slick with dew, paint glistening in the light",
        ". At dawn, the figurehead faces the rising sun",
        ". The wood is cool to the touch as the ship rocks gently"
        }));
    addTimeOfDayDescription("noon", ({
        ". The figurehead gleams in the midday sun, colors vivid",
        ". The deck bustles as sailors pass beneath the figurehead",
        ". The figurehead's features are sharply defined in the light"
        }));
    addTimeOfDayDescription("night", ({
        ". The figurehead is barely visible in the darkness",
        ". The air is cool, and the paint is damp with dew",
        ". Lanterns cast dim light on the figurehead, shadows flickering"
        }));

    addSeasonDescription("spring", ({
        " with the figurehead freshly painted for the new season",
        " as the wood is checked after winter storms",
        " with the air fresh and the figurehead gleaming"
        }));
    addSeasonDescription("summer", ({
        " with the figurehead in constant use, colors bright in the sun",
        " as the sun beats down, the figurehead is a proud sight",
        " with the air thick with the scent of paint and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the figurehead checked for wear before winter",
        " as the air turns crisp and the paint is retouched",
        " with the deck quieter, but the figurehead still stands proud"
        }));
    addSeasonDescription("winter", ({
        " with the figurehead rimed with frost, paint stiff with cold",
        " as only the hardiest sailors brave the chill to touch it",
        " with the figurehead covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a ship's figurehead juts from the prow, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a figurehead glints in the faint light, colors muted"
    );
    addDimLightDescriptionTemplate(
        "a carved figurehead juts from the prow, ready to face the sea"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept figurehead stands at the prow, colors bright"
    );
}
