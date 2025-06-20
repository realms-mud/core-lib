//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("buoy");
    addAdjectives(({ "bright", "painted", "floating", "harbor", "marker" }));

    addDescriptionTemplate("a ##Adjective## buoy bobbing in the harbor");

    addTimeOfDayDescription("dawn", ({
        ". The buoy bobs gently in the morning mist",
        ". At dawn, gulls perch atop the buoy, calling over the water",
        ". The buoy's paint glistens with dew in the early light"
        }));
    addTimeOfDayDescription("night", ({
        ". The buoy's lantern glows softly, marking safe passage",
        ". The air is cool, and the buoy rocks in the gentle swell",
        ". The buoy's bell rings faintly in the darkness"
        }));
    addTimeOfDayDescription("evening", ({
        ". The buoy is lit as dusk falls, its lantern shining over the waves",
        ". The buoy's bell rings as the tide turns",
        ". The air is filled with the scent of salt and seaweed"
        }));

    addSeasonDescription("spring", ({
        " with the buoy freshly painted for the new season",
        " as the buoy marks the channel through spring storms",
        " with the air fresh and the buoy bobbing in the swell"
        }));
    addSeasonDescription("summer", ({
        " with the buoy in constant use, marking safe passage",
        " as the sun warms the water, the buoy is a common sight",
        " with the air thick with the scent of salt and seaweed"
        }));
    addSeasonDescription("autumn", ({
        " with the buoy shining through drifting fog",
        " as the air turns crisp and the buoy is checked for wear",
        " with the buoy a welcome sight for late-season sailors"
        }));
    addSeasonDescription("winter", ({
        " with the buoy rimed with frost, bell muffled by ice",
        " as only the hardiest sailors pass by in the cold",
        " with the buoy bobbing through the long, dark nights"
        }));

    addNearDarkDescriptionTemplate(
        "a faintly glowing buoy bobs in the harbor"
    );
    addLowLightDescriptionTemplate(
        "a buoy casts a dim glow, its bell ringing softly"
    );
    addDimLightDescriptionTemplate(
        "a sturdy buoy bobs in the water, its paint bright in the gloom"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept buoy marks the channel, guiding ships to safety"
    );
}
