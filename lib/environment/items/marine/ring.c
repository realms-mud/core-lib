//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mooring ring");
    addAdjectives(({ "heavy", "iron", "worn", "sturdy", "dockside" }));

    addDescriptionTemplate("a ##Adjective## mooring ring set into the dock");

    addTimeOfDayDescription("dawn", ({
        ". The mooring ring is slick with dew, iron glinting in the early light",
        ". At dawn, ropes are looped through the ring as boats arrive",
        ". The ring casts a long shadow across the dock"
        }));
    addTimeOfDayDescription("night", ({
        ". The mooring ring is barely visible in the darkness",
        ". The air is cool, and the ring is cold to the touch",
        ". Lanterns cast dim light on the ring, its shape easy to spot"
        }));
    addTimeOfDayDescription("evening", ({
        ". The mooring ring is checked as dusk falls, ready for use",
        ". The iron glows faintly in the fading light",
        ". The air is filled with the scent of salt and tar"
        }));

    addSeasonDescription("spring", ({
        " with the ring freshly cleaned for the new season",
        " as the iron is checked after winter storms",
        " with the air fresh and the ring gleaming in the sun"
        }));
    addSeasonDescription("summer", ({
        " with the ring in constant use, ropes looped through it all day",
        " as the sun warms the dock, the ring is a common sight",
        " with the air thick with the scent of salt and tar"
        }));
    addSeasonDescription("autumn", ({
        " with the ring shining through drifting fog",
        " as the air turns crisp and the iron is checked for rust",
        " with the dock quieter, but the ring still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the ring rimed with frost, iron stiff with cold",
        " as only the hardiest workers brave the chill to use the ring",
        " with the ring gleaming through the long, dark nights"
        }));

    addNearDarkDescriptionTemplate(
        "a mooring ring is set into the dock, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a mooring ring glints in the faint light, rope looped through it"
    );
    addDimLightDescriptionTemplate(
        "a sturdy iron ring is set into the dock, ready for mooring"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept mooring ring is set into the dock, rope looped through it"
    );
}
