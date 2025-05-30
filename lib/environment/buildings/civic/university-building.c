//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("university building");
    setFloorPlanType("university");

    addAdjectives(({
        "majestic", "scholarly", "limestone", "ornate", "venerable", "gothic"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## university building with soaring arched windows and "
        "intricate stone carvings along its facade"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the limestone walls, giving them a "
        "soft golden glow as if illuminating centuries of knowledge within",
        ". At dawn, scholars can be seen carrying lanterns as they make their "
        "way to early lectures through the mist-shrouded courtyards"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning bells ring from the central tower, marking the hours and "
        "summoning students to their studies",
        ". Sunlight streams through the tall stained glass windows, casting "
        "colorful patterns across ancient wooden desks and stone floors"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, students gather in the colonnaded courtyard, debating "
        "philosophical points or studying manuscripts in the open air",
        ". The noon sun illuminates the weathered gargoyles and scholar-saints "
        "carved along the roofline, silent overseers of academic pursuit"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light emphasizes the building's ornate stonework, "
        "shadows deepening in the carved recesses of centuries-old symbols",
        ". Lecturers and students move between chambers, their voices sometimes "
        "carrying through open windows in passionate academic discourse"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, oil lamps and candles are lit within, giving the "
        "tall windows a warm amber glow against the darkening sky",
        ". The university building seems most at home in evening's softer light, "
        "which gently highlights its venerable architecture"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the limestone takes on a purplish hue while golden light "
        "from within transforms the great windows into glowing tableaux",
        ". The building's distinctive silhouette stands proudly against the "
        "twilight sky, its towers and chimneys clearly visible"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the university building is marked by the steady glow of "
        "lamps from windows where devoted scholars continue their studies",
        ". Moonlight washes over the ancient stones, giving the carvings an "
        "otherworldly appearance as if the knowledge within has come alive"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with ivy beginning to green along its walls and scholars sometimes "
        "holding outdoor lectures in the adjacent gardens",
        " where spring breezes carry the scent of new parchment and ink through "
        "open windows, mingling with the fragrance of blooming courtyard trees"
        }));

    addSeasonDescription("summer", ({
        " with many windows thrown open to catch cooling breezes, and students "
        "gathered in shaded cloisters to escape the heat",
        " where summer light reveals the subtle colorations in the limestone, "
        "testament to the quarries from which it was carefully selected"
        }));

    addSeasonDescription("autumn", ({
        " with golden ivy clinging to its walls and fallen leaves gathering in "
        "corners of the courtyard where students still debate",
        " as autumn winds sometimes carry the sound of lectures or heated "
        "scholarly arguments through half-opened windows"
        }));

    addSeasonDescription("winter", ({
        " with snow gathered on its window ledges and smoke curling from "
        "numerous chimneys where fires warm the chambers within",
        " where winter transforms the stone gargoyles into frost-covered "
        "guardians and icicles hang like crystal decorations from the eaves"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a massive structure with tall windows and what appear to be towers or "
        "spires rising from its roofline"
    );
    addLowLightDescriptionTemplate(
        "a grand limestone building with arched windows and elaborate "
        "architectural details visible even in the dim light"
    );
    addDimLightDescriptionTemplate(
        "an ornate university building of pale stone with numerous windows and "
        "intricate carvings along its facade"
    );
    addSomeLightDescriptionTemplate(
        "a majestic limestone university building with soaring arched windows, "
        "buttressed walls, and elaborate stone carvings of scholars and symbols"
    );

    // Single item template
    addItemTemplate(
        "The university building is an imposing structure of pale limestone with "
        "soaring gothic arches and intricately carved facades. Tall windows, "
        "many with stained glass depicting scenes of knowledge and discovery, "
        "punctuate the sturdy walls. Flying buttresses support the structure, "
        "allowing for the great height of the central halls. Carved gargoyles "
        "and figures of renowned scholars watch from above, while Latin "
        "inscriptions extolling wisdom and learning adorn the massive oak doors."
    );

    addSourceOfLight(5);
}
