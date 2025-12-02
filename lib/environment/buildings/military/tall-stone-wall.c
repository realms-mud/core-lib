//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tall stone wall");
    setFloorPlanType("military");

    addAdjectives(({
        "massive", "defensive", "imposing", "stone", "weathered", "formidable"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## stone wall rising to an impressive height with a "
        "walkway along its top"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day gradually illuminates the wall from top to "
        "bottom, revealing the precise stonework",
        ". At dawn, guards walk the battlements, silhouetted against the "
        "brightening sky as they change watch"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light reveals the full extent of the defensive structure, "
        "each stone precisely placed for maximum strength",
        ". The wall casts a diminishing shadow as the morning progresses, "
        "sentries pacing along its walkway with vigilant purpose"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the wall stands stark against the sky, its rough texture "
        "highlighted by the overhead sun",
        ". The stone radiates accumulated heat, the massive structure seeming to "
        "grow more imposing in the clear light"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun brings out subtle variations in the stonework, from "
        "newer repairs to blocks weathered by centuries",
        ". Shadows begin to stretch from the wall's base as afternoon "
        "progresses, the structure still fulfilling its ancient purpose"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the walkway along the top becomes more active "
        "as guards light torches spaced along the battlements",
        ". The wall takes on a golden hue in the setting sun, its defensive "
        "purpose emphasized as darkness gathers beyond it"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the wall becomes a dark silhouette, torches along its "
        "length becoming more prominent as night falls",
        ". The last light catches the top of the battlements, the rest of the "
        "structure already embracing the coming night"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the wall is a massive shadow broken only by the occasional "
        "torch or lantern carried by patrolling guards",
        ". Moonlight washes over the ancient stones, revealing the impressive "
        "height that has protected this boundary for generations"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with small plants finding footholds in crevices between stones, "
        "adding touches of green to the weathered gray",
        " where spring rain darkens patches of the stonework, water flowing "
        "through carefully designed drainage channels"
        }));

    addSeasonDescription("summer", ({
        " with the stone radiating accumulated heat and guards seeking whatever "
        "shade they can find during their watch",
        " where the bright summer sun highlights every detail of the masonry, "
        "from defensive features to stonemasons' marks"
        }));

    addSeasonDescription("autumn", ({
        " with vines clinging to portions of its base turning crimson and "
        "gold against the gray stone",
        " where autumn winds whistle through arrow slits and between "
        "crenellations, a constant companion to the sentries"
        }));

    addSeasonDescription("winter", ({
        " with snow gathering along the battlements and in the arrow slits, "
        "adding white accents to the imposing structure",
        " where ice occasionally forms on the northern face, the stone bearing "
        "this seasonal assault as it has for countless winters"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a massive vertical barrier stretching into the darkness"
    );
    addLowLightDescriptionTemplate(
        "a high stone wall with what appears to be a walkway along its top"
    );
    addDimLightDescriptionTemplate(
        "a tall defensive wall made of fitted stone blocks with occasional "
        "arrow slits"
    );
    addSomeLightDescriptionTemplate(
        "an imposing stone wall of impressive height with crenellated "
        "battlements, arrow slits, and a protected walkway along its top"
    );

    // Single item template
    addItemTemplate(
        "The tall stone wall represents generations of defensive engineering, "
        "built of massive blocks fitted together with remarkable precision. "
        "Rising to an impressive height, the wall features a protected walkway "
        "along its top, accessed by stairs at regular intervals. Crenellated "
        "battlements provide cover for defenders, while arrow slits at various "
        "levels allow for ranged attacks from protected positions. Drainage "
        "channels and subtle outward angles demonstrate the builders' practical "
        "knowledge, ensuring the structure would stand against both attackers "
        "and the elements for centuries."
    );
}
