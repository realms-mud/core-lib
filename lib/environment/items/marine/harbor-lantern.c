//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("harbor lantern");
    addAdjectives(({ "sturdy", "glass-paned", "iron", "weathered", "guiding" }));

    addDescriptionTemplate("a ##Adjective## harbor lantern hanging from a post at the dock's edge");

    addSourceOfLight(5);

    addTimeOfDayDescription("dawn", ({
        ". The lantern glows faintly in the morning mist",
        ". At dawn, the lantern is extinguished as the sun rises",
        ". Dew beads on the glass, catching the first light of day"
        }));
    addTimeOfDayDescription("night", ({
        ". The lantern burns brightly, casting a warm glow on the dock",
        ". The air is cool, and the lantern's light guides sailors home",
        ". Shadows dance as the lantern sways in the night breeze"
        }));
    addTimeOfDayDescription("evening", ({
        ". The lantern is lit as dusk falls, its flame steady in the wind",
        ". The lantern's glow marks the edge of the dock",
        ". The air is filled with the scent of oil and salt"
        }));

    addSeasonDescription("spring", ({
        " with the lantern cleaned and filled for the new season",
        " as the lantern's light reflects off fresh rain on the dock",
        " with the air fresh and the lantern glass gleaming"
        }));
    addSeasonDescription("summer", ({
        " with the lantern burning late into the warm night",
        " as insects dance around the lantern's glow",
        " with the air thick with the scent of oil and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the lantern's light shining through drifting fog",
        " as the air turns crisp and the lantern is checked for oil",
        " with the dock quieter, but the lantern still burns bright"
        }));
    addSeasonDescription("winter", ({
        " with the lantern rimed with frost, flame flickering in the cold",
        " as only the hardiest sailors rely on its light",
        " with the lantern burning through the long, dark nights"
        }));

    addNearDarkDescriptionTemplate(
        "a faintly glowing lantern hangs from a post at the dock's edge"
    );
    addLowLightDescriptionTemplate(
        "a lantern casts a dim glow, barely illuminating the dock"
    );
    addDimLightDescriptionTemplate(
        "a sturdy lantern hangs from a post, its flame steady in the wind"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept lantern burns brightly, guiding sailors to shore"
    );
}
