//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("keep");
    setFloorPlanType("keep");

    addAdjectives(({
        "sturdy", "fortified", "stone", "square", "defensive", "solid"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## keep with thick stone walls and a central tower rising "
        "above its battlements"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the central tower while the outer "
        "walls remain in shadow, emphasizing the keep's imposing height",
        ". At dawn, the keep's silhouette stands stark against the brightening "
        "sky, guards visible as small figures atop the battlements"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light reveals the defensive nature of the structure, from "
        "arrow slits to murder holes above the iron-bound gate",
        ". The keep's stone walls appear golden in the morning sun, belying "
        "their grim purpose of protection and defense"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the keep casts a sharply defined shadow, the stone walls "
        "radiating the heat they've absorbed from the sun",
        ". The noon sun highlights the weathered stonework, showing repairs and "
        "additions made over generations of defensive vigilance"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light emphasizes the substantial thickness of the "
        "walls, each stone carefully placed for maximum strength",
        ". Shadows lengthen from the central tower, stretching beyond the "
        "curtain walls that define the keep's defensive perimeter"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, torches and braziers are lit along the "
        "battlements, establishing a ring of light above the darkening walls",
        ". The keep takes on a more forbidding aspect in the fading light, its "
        "purpose as a final defensive position never more apparent"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the keep becomes a massive shadow against the sky, only its "
        "outline and the occasional torch marking its presence",
        ". The portcullis is lowered at dusk, the heavy grate cutting off access "
        "until the safety of morning light returns"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the keep is a dark fortress broken only by torchlight "
        "along the battlements where guards maintain their watch",
        ". Moonlight gives the stone walls an eerie pallor, the central tower "
        "standing like a sentinel against the night sky"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with small plants finding purchase in cracks between stones, defiant "
        "spots of green against the gray fortress walls",
        " where spring rains darken the stonework in patterns that highlight "
        "the skilled masonry of the defensive structure"
        }));

    addSeasonDescription("summer", ({
        " with heat radiating from the sun-baked stones and the garrison "
        "grateful for the cool interior behind thick walls",
        " surrounded by dry grass and packed earth, the area around the keep "
        "kept clear for defensive visibility"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering at the base of the walls, unable to "
        "breach the keep's defenses any more than an enemy could",
        " as autumn winds find every arrow slit and embrasure, the sounds of "
        "their passage creating an eerie chorus through the stonework"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining the battlements and icicles forming deadly "
        "spikes below the machicolations",
        " where winter transforms the already formidable structure into "
        "something even more forbidding, cold stone against white snow"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a massive building with what appears to be a central tower"
    );
    addLowLightDescriptionTemplate(
        "a fortified structure with high walls and a prominent central tower"
    );
    addDimLightDescriptionTemplate(
        "a stone keep with battlemented walls surrounding a central tower"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy stone keep with thick defensive walls, battlements, and a "
        "central tower rising above the surrounding structure"
    );

    // Single item template
    addItemTemplate(
        "The keep represents the essential fortress: a building of massive stone "
        "walls with battlements along the top and a tall central tower that "
        "serves as both lookout and last refuge. Narrow windows and arrow slits "
        "pierce the thick walls strategically, while a single heavily fortified "
        "gate provides the only entrance. The stonework shows generations of "
        "care and maintenance, for this structure was built to withstand both "
        "time and siege. Defensive features include machicolations above the "
        "gate, murder holes, and a deep ditch surrounding the base of the walls."
    );

    addSourceOfLight(4);
}
