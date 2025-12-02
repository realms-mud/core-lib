//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("birlinn");
    addAdjectives(({ "long", "clinker-built", "gaelic", "oared", "sturdy" }));

    addDescriptionTemplate("a ##Adjective## birlinn with a single mast and rows of oars");

    addTimeOfDayDescription("dawn", ({
        ". The birlinn is shrouded in mist, oars shipped and sail furled",
        ". At dawn, rowers gather on the benches, ready for the day's journey",
        ". The clinker-built hull glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The birlinn is launched into calm water, oars dipping in unison",
        ". Crewmen check the rigging and prepare the sail",
        ". The air is fresh, and the birlinn is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The birlinn glides across the sunlit bay, oars flashing in the light",
        ". The air is warm, and the ship is used for patrol and trade",
        ". Sailors gather at the birlinn, preparing for the afternoon tide"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh caulking for the season's first launches",
        " as the birlinn is busy with the first journeys of spring",
        " with the air fresh and the ship glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the birlinn in constant use, drying quickly in the sun",
        " as the sun warms the dock, the ship is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the birlinn packed for the last big journeys before winter",
        " as the air turns crisp and the ship is checked for leaks",
        " with the dock quieter, but the ship still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the birlinn rimed with frost, wood stiff with cold",
        " as only the hardiest rowers brave the chill to use the ship",
        " with the ship stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a birlinn is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a birlinn sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a long birlinn, oars shipped, glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made birlinn is tied to the dock, ready for use"
    );
}
