//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("aquamancer guild");
    InteriorType("coral-domed sanctuary");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The surface of the reflecting pool glows with soft hues of rose and blue, and a light mist drifts from the dome"
        }));
    addTimeOfDayDescription("morning", ({
        ". Cascading waterfalls along the walls shimmer in the morning light, and gentle waves ripple across the entrance fountain"
        }));
    addTimeOfDayDescription("noon", ({
        ". Sunlight streams through crystal skylights, refracting into dancing patterns across the watery floor"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". Aquatic chants echo softly from within, accompanied by the rhythmic splash of water flowing through carved channels"
        }));
    addTimeOfDayDescription("evening", ({
        ". The dome glows with soft, bioluminescent blues, and soft splashes echo through the cooling air"
        }));
    addTimeOfDayDescription("dusk", ({
        ". Pools of water reflect the twilight sky, while faint magical auras ripple across their surface"
        }));
    addTimeOfDayDescription("night", ({
        " surrounded by glowing aquatic runes that pulse gently beneath the water's surface and illuminate the entrance with shifting blue light"
        }));
    addTimeOfDayDescription("late night", ({
        " with the only illumination coming from glowing lily pads and soft pulses of arcane energy rising from the reflecting pools"
        }));
    addTimeOfDayDescription("midnight", ({
        " cloaked in silence but for the whisper of moving water, with moonlight glinting across enchanted surfaces"
        }));

    addSeasonDescription("winter", ({
        " with frozen mist forming delicate crystals around the fountains, though the central pool remains mysteriously unfrozen"
        }));
    addSeasonDescription("spring", ({
        " with new aquatic flora blooming in the shallow pools and soft rain falling from the open skylights"
        }));
    addSeasonDescription("summer", ({
        " exuding a cool, refreshing mist from its cascades, offering respite from the heat"
        }));
    addSeasonDescription("autumn", ({
        " with the scent of rain in the air and water-colored leaves drifting lazily across its surface pools"
        }));

    addSourceOfLight(8, "bioluminescent glyphs", "night");

    addDescriptionTemplate("a coral-domed sanctuary serving as the Aquamancer Guild");
    addNearDarkDescriptionTemplate("a low, dome-shaped structure surrounded by the sound of running water");
    addLowLightDescriptionTemplate("a watery sanctuary with glimmering reflections dancing across its walls");
    addDimLightDescriptionTemplate("a structure of glass and coral, water spilling from sculpted edges");
    addSomeLightDescriptionTemplate("a graceful sanctuary crowned with a coral dome, surrounded by flowing water and soft light");
}