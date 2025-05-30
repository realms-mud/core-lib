//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("small brick house");
    setFloorPlanType("house");

    addAdjectives(({
        "cozy", "small", "snug", "brick", "trim", "neat"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## brick house with a peaked roof and small front garden"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the red brick walls, warming their "
        "color as smoke begins to rise from the chimney",
        ". At dawn, dew glistens on the small garden plants, the brick house "
        "standing solid and reassuring in the growing light"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light reveals the pattern of the brickwork, each small block "
        "contributing to the sturdy whole of the modest dwelling",
        ". The brick absorbs the growing warmth of morning, the small house "
        "seeming to come alive as the sun rises higher"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the brick glows with a deep, warm red, the mortar lines "
        "creating a precise grid across the small facade",
        ". The tiny house casts a sharply defined shadow at noon, its simple "
        "shape clear against the ground beside it"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun deepens the brick to a rich burgundy, shadows "
        "beginning to stretch from the compact structure",
        ". Light catches on the small brass door knocker, a modest touch of "
        "decoration on this practical dwelling"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the brick retains the day's warmth while a "
        "cheerful glow appears in the small windows",
        ". The house seems most welcoming at evening, when lamplight from "
        "within makes the small windows glow like embers"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the red brick deepens to shadow, the small house becoming "
        "a darker shape as night falls",
        ". The last light catches the edges of each brick, outlining the "
        "careful craftsmanship of the small dwelling"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the brick house is a solid presence in the darkness, "
        "moonlight occasionally glinting off the window glass",
        ". The small structure seems to hold the night at bay, its solid walls "
        "promising security within its modest space"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with early flowers beginning to bloom in the small garden and new "
        "vines reaching toward the brick walls",
        " where spring rain darkens the brick periodically, the red deepening "
        "to maroon before drying again in the sun"
        }));

    addSeasonDescription("summer", ({
        " with the small window propped open to catch breezes and potted "
        "plants flanking the tidy front step",
        " surrounded by a carefully tended garden where vegetables and flowers "
        "grow together in the limited space"
        }));

    addSeasonDescription("autumn", ({
        " with a small stack of firewood neatly arranged against one wall and "
        "dried seed heads still decorating the garden",
        " where fallen leaves occasionally catch in the corners where wall meets "
        "ground, adding splashes of gold against the steady red brick"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining the roof edge and frost patterns forming on the "
        "small window panes",
        " where smoke rises more steadily from the chimney, promising warmth "
        "within the solid brick walls"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a small, rectangular shape with what appears to be a peaked roof"
    );
    addLowLightDescriptionTemplate(
        "a small structure made of dark material with a window and chimney"
    );
    addDimLightDescriptionTemplate(
        "a small brick house with a peaked roof and tiny front garden"
    );
    addSomeLightDescriptionTemplate(
        "a cozy brick house with a peaked roof, small window with curtains, "
        "wooden door, and a well-kept front garden"
    );

    // Single item template
    addItemTemplate(
        "The small brick house makes efficient use of limited space, rising in "
        "neat lines of well-laid red brick to a peaked roof of wooden shingles. "
        "A single window faces the path, its panes of glass a sign of modest "
        "prosperity, while the wooden door bears simple but decorative iron "
        "hinges. A chimney at one end promises warmth from a small hearth "
        "inside. The tiny front garden is carefully tended, combining practical "
        "herbs with a few colorful flowers that brighten the red brick facade."
    );

    addSourceOfLight(2);
}
