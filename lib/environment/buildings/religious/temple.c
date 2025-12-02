//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("temple");
    setFloorPlanType("church");

    addAdjectives(({
        "sacred", "ornate", "ancient", "stone", "imposing", "reverent"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## temple with columns supporting a triangular pediment "
        "and statues flanking the broad entrance steps"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first rays of morning light touch the temple's facade, seeming to "
        "awaken the stone as priests begin their dawn rituals",
        ". At dawn, sacred chants emerge from within, carrying on the still air "
        "as the temple greets the new day with ancient prayers"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the temple in all its splendor, sunlight highlighting "
        "the detailed carvings that adorn the stone columns",
        ". Devotees ascend the steps with offerings, the temple's massive doors "
        "standing open in welcome to the faithful"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the temple stands serene and timeless, the statues casting "
        "precise shadows across the immaculate stone steps",
        ". The scent of incense drifts from within, and the murmur of prayer "
        "creates a constant undertone beneath the busy sounds of noon"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light illuminates the western facade, giving the temple "
        "an almost ethereal glow as it has for countless generations",
        ". Priests in ceremonial robes move with practiced grace between the "
        "columns, their duties unchanged by the passing centuries"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, oil lamps are lit within the temple, their "
        "warm glow spilling through the colonnaded entrance",
        ". The temple seems most alive at evening, when shadows soften its "
        "lines and devotional singing echoes from within"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the temple is outlined against the darkening sky, torches "
        "at the entrance marking this sacred space against the gathering night",
        ". The stone seems to hold the day's last light, the temple standing as "
        "a beacon of faith as darkness claims the world around it"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the temple is illuminated by sacred flames that are never "
        "allowed to extinguish, markers of eternal devotion",
        ". Moonlight washes over the temple's facade, giving the carved figures "
        "an otherworldly presence as night rituals continue within"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with ritual garlands decorating the columns and spring blossoms "
        "scattered as offerings along the steps",
        " where spring ceremonies honor renewal and growth, the ancient stones "
        "witness to countless cycles of seasonal rebirth"
        }));

    addSeasonDescription("summer", ({
        " with temple doors thrown wide to catch cooling breezes and ceremonial "
        "banners hanging between the columns",
        " where summer festivals bring throngs of the faithful, the temple's "
        "broad steps accommodating both ceremony and community"
        }));

    addSeasonDescription("autumn", ({
        " with harvest offerings piled before the entrance and sacred fire "
        "vessels burning with greater intensity against the coming cold",
        " where autumn rituals give thanks for abundance while preparing for "
        "the contemplative season to come"
        }));

    addSeasonDescription("winter", ({
        " with sacred flames providing both light and warmth as winter "
        "ceremonies move deeper within the protective stone walls",
        " where even in winter's grip, the temple remains a center of community "
        "and spiritual comfort, its eternal fires never dimming"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large structure with columns and what appears to be a triangular "
        "roof"
    );
    addLowLightDescriptionTemplate(
        "a temple with columns and statues, details obscured in the dim light"
    );
    addDimLightDescriptionTemplate(
        "a sacred temple with columns supporting a triangular pediment, and "
        "statues standing sentinel beside the entrance"
    );
    addSomeLightDescriptionTemplate(
        "an ornate stone temple with carved columns supporting a triangular "
        "pediment decorated with relief sculptures, and life-sized statues of "
        "deities flanking the broad entrance steps"
    );

    // Single item template
    addItemTemplate(
        "The temple is an impressive structure devoted to spiritual worship, "
        "built in a classical style with a colonnade supporting a triangular "
        "pediment adorned with relief sculptures depicting divine scenes. "
        "Broad stone steps lead to the entrance, flanked by statues of deities "
        "or sacred figures. The interior can be glimpsed through massive bronze "
        "doors: a vast central chamber with smaller side chapels, altars for "
        "offerings, and areas for both communal worship and private devotion. "
        "Sacred symbols adorn every surface, speaking to the temple's spiritual "
        "purpose and ancient traditions."
    );

    addSourceOfLight(2);
}
