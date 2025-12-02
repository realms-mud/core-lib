//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("trireme");
    addAdjectives(({ "ancient", "sleek", "triple-banked", "oared", "war" }));

    addDescriptionTemplate("a ##Adjective## trireme with three rows of oars and a bronze ram");

    addTimeOfDayDescription("dawn", ({
        ". The trireme is shrouded in mist, its oars shipped and sail furled",
        ". At dawn, rowers gather on the benches, ready for the day's journey",
        ". The triple-banked hull glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The trireme is launched into calm water, oars dipping in unison",
        ". Crewmen check the rigging and prepare the sail",
        ". The air is fresh, and the trireme is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The trireme glides across the sunlit bay, oars flashing in the light",
        ". The air is warm, and the ship is used for patrol and battle drills",
        ". Sailors gather at the trireme, preparing for the afternoon tide"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh caulking for the season's first launches",
        " as the trireme is busy with the first patrols of spring",
        " with the air fresh and the ship glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the trireme in constant use, drying quickly in the sun",
        " as the sun warms the dock, the ship is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the trireme packed for the last big patrols before winter",
        " as the air turns crisp and the ship is checked for leaks",
        " with the dock quieter, but the ship still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the trireme rimed with frost, wood stiff with cold",
        " as only the hardiest rowers brave the chill to use the ship",
        " with the ship stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a trireme is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a trireme sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a long trireme, oars shipped, glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made trireme is tied to the dock, ready for use"
    );
}
