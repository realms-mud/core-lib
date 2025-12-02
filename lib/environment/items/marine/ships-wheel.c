//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ship's wheel");
    addAdjectives(({ "polished", "brass-bound", "weathered", "large", "spoked" }));

    addDescriptionTemplate("a ##Adjective## ship's wheel mounted on a sturdy pedestal");

    addTimeOfDayDescription("dawn", ({
        ". The wheel is slick with dew, brass fittings glinting in the light",
        ". At dawn, the wheel stands ready for the day's voyage",
        ". The wood is cool to the touch as the sun rises"
        }));
    addTimeOfDayDescription("noon", ({
        ". The wheel is warm from the midday sun, wood gleaming",
        ". The deck bustles around the wheel as the ship is steered",
        ". The wheel creaks as it turns, guiding the ship"
        }));
    addTimeOfDayDescription("night", ({
        ". The wheel is dimly lit by lanterns, shadows flickering on the deck",
        ". The air is cool, and the wheel stands silent",
        ". Only the helmsman remains at the wheel through the night"
        }));

    addSeasonDescription("spring", ({
        " with the wheel freshly oiled for the new season",
        " as the wheel is checked after winter storms",
        " with the air fresh and the wheel ready for travel"
        }));
    addSeasonDescription("summer", ({
        " with the wheel in constant use, warm from the sun",
        " as the sun beats down, the wheel is a focal point on deck",
        " with the air thick with the scent of salt and varnish"
        }));
    addSeasonDescription("autumn", ({
        " with the wheel polished for the last voyages before winter",
        " as the air turns crisp and the wheel is checked for wear",
        " with the deck quieter, but the wheel still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the wheel rimed with frost, wood stiff with cold",
        " as only the hardiest sailors brave the chill to steer",
        " with the wheel covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a ship's wheel stands at the stern, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a ship's wheel glints in the faint light, brass fittings shining"
    );
    addDimLightDescriptionTemplate(
        "a sturdy ship's wheel is mounted on a pedestal, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept ship's wheel stands at the helm, ready to steer the ship"
    );
}
