//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("aeromancer guild");
    InteriorType("marble spire");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The spire is wreathed in mist, and faint currents of wind spiral gently around its peak"
        }));
    addTimeOfDayDescription("morning", ({
        ". Wind chimes crafted of crystal and silver dance in the breeze, echoing ethereal tones from the balconies"
        }));
    addTimeOfDayDescription("noon", ({
        ". Sunlight gleams off high glass panels and lenses mounted around the upper tier"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". Flags and streamers flutter atop the spire, catching the wind in rhythmic bursts"
        }));
    addTimeOfDayDescription("evening", ({
        ". The sky around the tower takes on a golden hue, and transparent wings of air elementals glint in the fading light"
        }));
    addTimeOfDayDescription("dusk", ({
        ". Azure light flickers across runes etched in the stone, carried by the whirling evening breeze"
        }));
    addTimeOfDayDescription("night", ({
        " under a dome of stars, the top of the tower glows with a pale blue aura, and currents of air spiral silently around it"
        }));
    addTimeOfDayDescription("late night", ({
        " with faint light circling the spire and an almost inaudible hum in the air"
        }));
    addTimeOfDayDescription("midnight", ({
        " surrounded by stillness broken only by the whisper of air magic flowing through unseen channels"
        }));

    addSeasonDescription("winter", ({
        " with frost crystals forming elegant patterns across the windows, stirred now and then by sudden gusts"
        }));
    addSeasonDescription("spring", ({
        " with the wind carrying the scent of blooming highland flowers and petal-dancers spiraling up its tower"
        }));
    addSeasonDescription("summer", ({
        " with warm, dry gusts rushing through the open terraces of its upper levels"
        }));
    addSeasonDescription("autumn", ({
        " surrounded by swirling golden leaves, caught in controlled whirlwinds that orbit the spire like lazy satellites"
        }));

    addSourceOfLight(8, "skybound glow", "night");

    addDescriptionTemplate("a tall marble spire that houses the Aeromancer Guild");
    addNearDarkDescriptionTemplate("the vague outline of a spire rising into the night");
    addLowLightDescriptionTemplate("a tall structure with banners barely visible fluttering in the dark");
    addDimLightDescriptionTemplate("a marble spire crowned with wind-blown banners and arcane windows");
    addSomeLightDescriptionTemplate("a soaring marble spire with glimmering crystal balconies and animated winds");
}
