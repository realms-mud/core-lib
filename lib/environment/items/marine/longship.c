//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("longship");
    addAdjectives(({ "sleek", "narrow", "viking", "dragon-prowed", "oared" }));

    addDescriptionTemplate("a ##Adjective## longship with a dragon-headed prow and rows of shields");

    addTimeOfDayDescription("dawn", ({
        ". The longship is shrouded in mist, dragon prow looming over the water",
        ". At dawn, warriors gather, checking shields and oars",
        ". The sleek hull glistens as the sun rises over the fjord"
        }));
    addTimeOfDayDescription("morning", ({
        ". The longship is launched into calm water, oars dipping in unison",
        ". Crewmen check the rigging and prepare the sail",
        ". The air is fresh, and the longship is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The longship glides across the sunlit bay, oars flashing in the light",
        ". The air is warm, and the ship is used for patrol and raids",
        ". Warriors gather at the longship, preparing for the afternoon tide"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh caulking for the season's first raids",
        " as the longship is busy with the first journeys of spring",
        " with the air fresh and the ship glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the longship in constant use, drying quickly in the sun",
        " as the sun warms the dock, the ship is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the longship packed for the last big raids before winter",
        " as the air turns crisp and the ship is checked for leaks",
        " with the dock quieter, but the ship still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the longship rimed with frost, wood stiff with cold",
        " as only the hardiest warriors brave the chill to use the ship",
        " with the ship stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a longship is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a longship sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a long, narrow longship, shields hung along the rails"
    );
    addSomeLightDescriptionTemplate(
        "a well-made longship is tied to the dock, ready for use"
    );
}
