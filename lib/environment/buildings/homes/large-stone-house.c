//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("large stone house");
    setFloorPlanType("house");

    addAdjectives(({
        "substantial", "solid", "two-story", "stone", "imposing", "enduring"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## house built of mortared field stones with a slate roof "
        "and multiple chimneys"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day gradually reveals the varied textures of the "
        "field stones, each chosen and placed by skilled masons",
        ". At dawn, the stone house appears particularly solid, a steadfast "
        "presence as shadows retreat from its weathered walls"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight brings out the rich palette of colors in the field "
        "stones, from warm browns to cool grays with occasional quartz sparkles",
        ". The substantial dwelling stands comfortably in the morning light, its "
        "two full stories suggesting prosperity without ostentation"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the stone walls demonstrate their practical value, the "
        "interior remaining cool despite the sun beating on the exterior",
        ". The house casts a substantial shadow, its solid presence emphasized "
        "by the clarity of noon light that reveals every detail of the masonry"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun warms the western wall, enhancing the varied hues "
        "of the field stones while casting the eastern wall in shadow",
        ". Light and shadow play across the textured stone facade, highlighting "
        "the craftsmanship that created this enduring dwelling"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, golden lamplight begins to glow behind the "
        "windows of both stories, warming the cool tones of the stone",
        ". The house seems most welcoming at evening, when the stone holds the "
        "day's warmth and windows promise comfort within"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the stone house becomes a darker presence, its substantial "
        "form still imposing as details fade into shadow",
        ". The multiple chimneys stand out against the darkening sky, smoke "
        "rising from several as the evening meal is prepared"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the stone house stands as a solid shadow, broken by "
        "the warm glow of windows on both floors",
        ". Moonlight gives the field stones a silvery cast, the varied textures "
        "creating a tapestry of light and shadow across the facade"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with climbing roses sending new shoots up carefully placed trellises "
        "and early flowers blooming in the kitchen garden",
        " where spring rain darkens the stones temporarily, revealing the full "
        "spectrum of colors hidden in the seemingly gray walls"
        }));

    addSeasonDescription("summer", ({
        " with windows open to catch cross-breezes and herb gardens flourishing "
        "in the shelter of the stone walls",
        " surrounded by carefully tended gardens that soften the imposing "
        "presence of the substantial stone structure"
        }));

    addSeasonDescription("autumn", ({
        " with ivy turning crimson against the stone and wood smoke often "
        "rising from multiple chimneys as the weather cools",
        " where fallen leaves gather against the foundation stones, their "
        "ephemeral nature contrasting with the house's permanence"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining the rugged texture of each stone and icicles "
        "hanging from the eaves like crystal decorations",
        " where the stone walls offer formidable resistance to winter winds, "
        "the solid structure a haven against the season's harshness"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large, blocky structure with what appears to be multiple chimneys"
    );
    addLowLightDescriptionTemplate(
        "a substantial stone building with two stories and several chimneys"
    );
    addDimLightDescriptionTemplate(
        "a large house constructed of varied field stones with a slate roof "
        "and multiple chimneys"
    );
    addSomeLightDescriptionTemplate(
        "a substantial two-story house built of carefully mortared field stones, "
        "featuring a slate roof, multiple chimneys, and several well-proportioned "
        "windows"
    );

    // Single item template
    addItemTemplate(
        "The house represents generations of careful construction, built of field "
        "stones gathered from the surrounding land and skillfully mortared "
        "together. Two full stories rise to a slate roof punctuated by multiple "
        "chimneys, promising warmth throughout the substantial interior. The "
        "windows are generous but not extravagant, each protected by wooden "
        "shutters that can be closed against inclement weather. A stone path "
        "leads to the front door, which features iron hardware of quality "
        "craftsmanship. The overall impression is one of enduring strength and "
        "comfortable prosperity without unnecessary display."
    );

    addSourceOfLight(4);
}
