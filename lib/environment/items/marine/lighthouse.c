//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lighthouse");
    addAdjectives(({ "tall", "stone", "beacon", "weathered", "guiding" }));

    addDescriptionTemplate("a ##Adjective## lighthouse rising above the rocky shore");

    addSourceOfLight(6);

    addTimeOfDayDescription("dawn", ({
        ". The lighthouse stands tall, its beacon dimming as the sun rises",
        ". At dawn, gulls wheel around the tower, calling over the waves",
        ". The stone walls glisten with dew in the early light"
        }));
    addTimeOfDayDescription("night", ({
        ". The lighthouse beacon sweeps across the dark water",
        ". The air is cool, and the light guides ships safely to harbor",
        ". The tower glows, a steadfast guardian through the night"
        }));
    addTimeOfDayDescription("evening", ({
        ". The lighthouse beacon is lit as dusk falls, shining far out to sea",
        ". The tower's windows glow warmly in the fading light",
        ". The air is filled with the scent of salt and distant storms"
        }));

    addSeasonDescription("spring", ({
        " with the beacon cleaned and ready for the new season",
        " as the lighthouse stands firm against spring storms",
        " with the air fresh and the stone walls gleaming"
        }));
    addSeasonDescription("summer", ({
        " with the beacon burning late into the warm night",
        " as seabirds nest on the rocky ledges",
        " with the air thick with the scent of salt and seaweed"
        }));
    addSeasonDescription("autumn", ({
        " with the beacon shining through drifting fog",
        " as the air turns crisp and the tower is checked for leaks",
        " with the lighthouse a welcome sight for late-season sailors"
        }));
    addSeasonDescription("winter", ({
        " with the beacon rimed with frost, flame flickering in the cold",
        " as only the hardiest keepers tend the light",
        " with the lighthouse burning through the long, dark nights"
        }));

    addNearDarkDescriptionTemplate(
        "a faintly glowing beacon shines from the top of a tall lighthouse"
    );
    addLowLightDescriptionTemplate(
        "a lighthouse casts a dim glow, its beacon sweeping the sea"
    );
    addDimLightDescriptionTemplate(
        "a tall lighthouse stands on the shore, its beacon steady in the wind"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept lighthouse burns brightly, guiding ships to safety"
    );
}
