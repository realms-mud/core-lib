//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fort");
    setFloorPlanType("military");

    addAdjectives(({
        "sturdy", "defensive", "square", "walled", "military", "imposing"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## fort with wooden palisades, watchtowers at each corner, "
        "and a central garrison house"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day catches the watchtowers first, while the "
        "palisade walls remain in deep shadow",
        ". At dawn, the fort comes to life as guards change shift and smoke "
        "rises from cookfires within the walls"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the fort's strategic position, its wooden walls and "
        "towers commanding a view of the surrounding terrain",
        ". The fort bustles with morning activity - soldiers drilling, sentries "
        "patrolling the walls, supplies being delivered through the main gate"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the fort stands resolute under the sun, its shadow a "
        "precise geometric shape on the ground beside it",
        ". The wooden walls have weathered to a silvery gray, evidence of years "
        "standing guard against potential threats"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun highlights the defensive features - sharpened "
        "palisade tops, arrow loops in the towers, reinforced gate",
        ". Soldiers go about their duties with practiced efficiency, the fort "
        "functioning as a self-contained military community"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, torches are lit along the walls and in the "
        "watchtowers, establishing a perimeter of light",
        ". The fort takes on a more forbidding aspect in the fading light, its "
        "purpose as a defensive stronghold never more apparent"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the fort becomes a dark silhouette against the sky, only "
        "torch light marking the watchtowers and gate",
        ". The main gate is closed at dusk, the heavy wooden doors barred until "
        "morning light returns"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the fort is a pattern of torch light and shadow, sentries "
        "visible as they make their rounds along the walls",
        ". Moonlight washes over the wooden palisade, the simple but effective "
        "defensive structure silent except for occasional calls from the guards"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with new grass growing along the base of the walls and wildflowers "
        "dotting the cleared ground before the fort",
        " where spring training brings increased activity as soldiers prepare "
        "for the campaign season ahead"
        }));

    addSeasonDescription("summer", ({
        " with the wooden walls sun-bleached and the ground around the fort "
        "packed hard from constant patrols",
        " surrounded by a cleared perimeter that provides no cover for potential "
        "attackers in the summer heat"
        }));

    addSeasonDescription("autumn", ({
        " with supplies being stockpiled for winter and repairs made to the "
        "palisade walls before the weather turns",
        " where the autumn winds carry the sounds of military life - orders "
        "being called, weapons practice, and the smith's hammer"
        }));

    addSeasonDescription("winter", ({
        " with smoke rising from multiple chimneys within and snow outlining the "
        "defensive features of the structure",
        " where winter transforms the cleared ground around the fort into a "
        "treacherous expanse of snow, advantageous for the defenders"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large square structure with what appear to be towers at each corner"
    );
    addLowLightDescriptionTemplate(
        "a walled compound with watchtowers and a central building visible within"
    );
    addDimLightDescriptionTemplate(
        "a military fort with wooden palisade walls and corner watchtowers"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy wooden fort with palisade walls, watchtowers at each corner, "
        "a reinforced gate, and a garrison building at its center"
    );

    // Single item template
    addItemTemplate(
        "The fort is a practical defensive structure built primarily of wood, "
        "with a square palisade of sharpened logs surrounding a central yard. "
        "Watchtowers stand at each corner, providing visibility over the "
        "surrounding territory. The main gate is reinforced with iron bands and "
        "flanked by defensive positions. Within the walls, a garrison house "
        "serves as barracks, mess hall, and command center, while smaller "
        "structures house storage, smithy, and stables. The entire compound is "
        "designed for both defense and as a base for military operations in "
        "the region."
    );
}
