//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bard hall");
    InteriorType("colorful hall");
    setFloorPlanType("artistic guild hall");

    addTimeOfDayDescription("dawn", ({
        ". The sound of a lone flute rises with the morning mist, and the windows glow with a faint amber hue"
        }));
    addTimeOfDayDescription("morning", ({
        ". Laughter and music spill from the open doors, and a bard practices chords beneath a painted archway"
        }));
    addTimeOfDayDescription("noon", ({
        ". The hall rings with song and verse as sunlight pours through stained-glass windows, painting the floor in vibrant hues"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". Poets and musicians lounge on steps outside the hall, sharing stories and harmonizing melodies"
        }));
    addTimeOfDayDescription("evening", ({
        ". Golden lanterns begin to flicker to life, and warm music drifts into the street from within"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The final rays of light reflect off polished instruments displayed in the window"
        }));
    addTimeOfDayDescription("night", ({
        " with warm candlelight glowing behind colorful curtains and the faint sound of a harp echoing through the walls"
        }));
    addTimeOfDayDescription("late night", ({
        " with the hall quiet now, though a soft melody still drifts from an unseen source within"
        }));
    addTimeOfDayDescription("midnight", ({
        " silent except for a lone voice singing softly, accompanied by the occasional creak of old floorboards"
        }));

    addSeasonDescription("winter", ({
        " with wreaths of holly and bells decorating its doors, and smoke rising from its chimney as laughter rings from inside"
        }));
    addSeasonDescription("spring", ({
        " adorned with garlands of flowers and performers rehearsing lively spring ballads on the front steps"
        }));
    addSeasonDescription("summer", ({
        " with wide open windows letting out music and laughter into the warm night air"
        }));
    addSeasonDescription("autumn", ({
        " decorated with hanging lanterns and colorful leaves, and the smell of spiced cider wafting from within"
        }));

    addSourceOfLight(7, "candlelight and stage lanterns", "night");

    addDescriptionTemplate("a lively and colorful hall where bards gather to perform and compose");
    addNearDarkDescriptionTemplate("a low building with arched windows glowing faintly in the night");
    addLowLightDescriptionTemplate("a hall with stained-glass windows and faint shadows of movement inside");
    addDimLightDescriptionTemplate("a colorfully painted hall with open doors and the sound of music within");
    addSomeLightDescriptionTemplate("a vibrant bardic hall adorned with instruments, tapestries, and stained glass");
}