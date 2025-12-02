//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mage tower");
    setFloorPlanType("trade");

    addAdjectives(({
        "tall", "mysterious", "ancient", "stone", "arcane", "spiraling"
        }));

    addDescriptionTemplate(
        "a ##Adjective## mage tower with narrow windows and a pointed roof"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the tower's silhouette stands stark against the pale sky",
        ". The first light glimmers on arcane symbols carved in the stone"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, faint lights flicker in the upper windows",
        ". The tower is quiet, its secrets hidden behind thick walls"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the tower's shadow falls long across the ground",
        ". The air shimmers with magical energy near the entrance"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the tower's bells chime, echoing through the town",
        ". The scent of incense and alchemical brews drifts from open windows"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the tower's windows glow with arcane light",
        ". The tower is alive with the hum of magical activity"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the tower's silhouette is outlined by the fading sun",
        ". Strange shadows move behind the tower's narrow windows"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the tower glows with magical light, runes pulsing softly",
        ". The tower is silent, save for the occasional flash of arcane energy"
        }));

    addSeasonDescription("spring", ({
        " surrounded by blooming herbs and magical plants",
        " as the tower's gardens are tended by apprentices"
        }));

    addSeasonDescription("summer", ({
        " with open windows letting in warm breezes and the scent of potions",
        " as the tower hosts gatherings of scholars and mages"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves swirling around the base and magical wards renewed",
        " as the tower's library is stocked for the long winter"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the stone and magical lights shining within",
        " as the tower's hearths burn bright against the cold"
        }));

    addNearDarkDescriptionTemplate(
        "a tall mage tower with glowing runes and a shadowed entryway"
    );
    addLowLightDescriptionTemplate(
        "a spiraling tower with narrow windows and arcane symbols"
    );
    addDimLightDescriptionTemplate(
        "an ancient mage tower with stone walls and flickering lights"
    );
    addSomeLightDescriptionTemplate(
        "a mysterious tower with magical lights, pointed roof, and high windows"
    );

    addItemTemplate(
        "The mage tower rises high above the town, its stone walls carved "
        "with arcane runes. Narrow windows look out from each level, and a "
        "pointed roof caps the spiraling structure. Inside, the air is thick "
        "with the scent of incense and the hum of magical energy. Shelves of "
        "books, alchemical equipment, and magical artifacts fill the rooms."
    );

    addSourceOfLight(2);
}
