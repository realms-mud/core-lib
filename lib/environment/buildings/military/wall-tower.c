//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wall tower");
    setFloorPlanType("military");

    addAdjectives(({
        "stone", "defensive", "sturdy", "round", "crenellated", "watchful"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## wall tower with arrow slits and a crenellated top"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the upper stonework, illuminating "
        "the tower while the wall below remains in shadow",
        ". At dawn, the tower stands sentinel, guards visible on the top as "
        "they scan the awakening landscape"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the defensive position of the tower, jutting from "
        "the wall to provide improved visibility and firing angles",
        ". The tower's purpose becomes clear in the morning light - its height "
        "and arrow slits designed for maximum defensive advantage"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the tower casts a precise shadow along the wall, the sun "
        "highlighting every stone and defensive feature",
        ". Guards on rotation seek momentary shade within the tower as the noon "
        "sun beats down on the exposed battlements"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light plays across the weathered stonework, shadows "
        "lengthening from the crenellations along the top",
        ". As afternoon progresses, the tower's shadow stretches further from "
        "the wall, marking time as surely as any sundial"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, a torch is lit at the top of the tower, a "
        "beacon visible from considerable distance",
        ". The tower takes on a more imposing aspect in the fading light, its "
        "silhouette stark against the darkening sky"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the tower becomes a darker shape against the sky, the "
        "torchlight at its top growing more prominent",
        ". The changing of the guard occurs as darkness falls, fresh eyes "
        "taking up the watch from the tower's commanding height"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the tower is a shadow among shadows, broken only by the "
        "occasional movement of a guard's lantern along the top",
        ". Moonlight washes over the stone structure, creating a silvered "
        "silhouette that maintains its vigilance through the darkness"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with small plants finding purchase between stones at its base, green "
        "life contrasting with the gray defensive structure",
        " where nesting birds make temporary homes in its higher crevices, "
        "adding life to the military architecture"
        }));

    addSeasonDescription("summer", ({
        " with the stone radiating accumulated heat and guards seeking whatever "
        "shade the structure offers",
        " where the summer sun reveals the precision of its construction, each "
        "stone carefully placed for strength and longevity"
        }));

    addSeasonDescription("autumn", ({
        " with the chill wind whistling through its arrow slits and guards "
        "wearing heavier cloaks as they stand watch",
        " where fallen leaves gather at its base, swept by the wind into "
        "temporary piles before being dispersed again"
        }));

    addSeasonDescription("winter", ({
        " with snow gathering on the crenellations and icicles forming briefly "
        "along its upper stonework",
        " where the winter winds make their presence most felt, the tower's "
        "height exposing it fully to the elements"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a tall cylindrical shape rising from what appears to be a wall"
    );
    addLowLightDescriptionTemplate(
        "a stone tower jutting from a wall, its details obscured in the dim light"
    );
    addDimLightDescriptionTemplate(
        "a defensive wall tower with narrow windows and a crenellated top"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy stone wall tower with arrow slits, a rounded design, and "
        "crenellations along its top"
    );

    // Single item template
    addItemTemplate(
        "The wall tower is a solid defensive structure, round in design to "
        "eliminate blind corners and provide maximum structural integrity. "
        "Rising significantly above the height of the adjoining wall, it offers "
        "improved visibility and defensive positioning. Narrow arrow slits pierce "
        "the stonework at strategic levels, allowing defenders to target "
        "attackers while remaining protected. The top features a crenellated "
        "parapet, providing cover for guards while allowing them to observe or "
        "fire upon enemies. A simple wooden door at wall level provides access "
        "to the interior, which houses a spiral staircase leading to multiple "
        "fighting platforms."
    );

    addSourceOfLight(2);
}
