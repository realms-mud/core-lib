//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Aegis Guard Hall");
    InteriorType("stone fortress hall");
    setFloorPlanType("martial guild hall");

    addTimeOfDayDescription("dawn", ({
        ". The hall stands resolute in the morning haze, its banners still and the torches at the gate smoldering quietly"
        }));
    addTimeOfDayDescription("morning", ({
        ". The clang of training weapons rings from within, and armored figures patrol the outer grounds"
        }));
    addTimeOfDayDescription("noon", ({
        ". Sunlight gleams off polished steel above the entrance as banners snap in the wind"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The scent of oil and leather drifts from the armory, and sparring matches echo from the courtyard"
        }));
    addTimeOfDayDescription("evening", ({
        ". The sound of weapons being cleaned and armor being stacked fills the air as torches are lit along the parapets"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The fading light casts long shadows across the training yard, and silhouettes of sentries are seen along the walls"
        }));
    addTimeOfDayDescription("night", ({
        " lit by braziers and guarded vigilantly, its doors sealed and its battlements patrolled in silence"
        }));
    addTimeOfDayDescription("late night", ({
        " with only the occasional glint of a patrol's armor visible through the darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        " looming like a silent sentinel under the stars, its stone exterior absorbing the chill of night"
        }));

    addSeasonDescription("winter", ({
        " with a light dusting of snow covering its roof and frozen footprints marking disciplined patrol paths"
        }));
    addSeasonDescription("spring", ({
        " with the banners refreshed and warriors beginning outdoor drills in the brisk morning air"
        }));
    addSeasonDescription("summer", ({
        " radiating heat from its stone walls, with open doors revealing intense training in full swing"
        }));
    addSeasonDescription("autumn", ({
        " surrounded by fallen leaves swept neatly into piles, with recruits cleaning gear for the coming cold"
        }));

    addSourceOfLight(6, "watchfire and torchlight", "night");

    addDescriptionTemplate("a fortified hall of stone and steel, home to the elite Aegis Guard");
    addNearDarkDescriptionTemplate("a stern silhouette of stone walls and towered battlements");
    addLowLightDescriptionTemplate("a broad hall with torches lining its entrance and shield emblems glinting in the dark");
    addDimLightDescriptionTemplate("a heavy-walled fortress adorned with banners and reinforced doors");
    addSomeLightDescriptionTemplate("a fortified hall bearing the standard of the Aegis Guard, its walls marked by discipline and strength");
}