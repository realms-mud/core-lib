//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dell");
    addAdjectives(({ "wooded", "sheltered", "small", "peaceful", "hidden",
        "verdant", "secluded", "quiet" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " misty in morning vapor",
        " peaceful in dawn stillness",
        " hidden in tree shadows",
        " wooded in morning mist",
        " sheltered from dawn wind",
        " small in intimate beauty",
        " verdant in morning dew",
        " secluded in dawn quiet",
        " quiet in forest peace",
        " dappled with filtered light"
        }));

    addTimeOfDayDescription("morning", ({
        " dappled with morning sunlight",
        " peaceful in forest calm",
        " hidden in wooded depths",
        " sheltered from morning breeze",
        " small in perfect proportion",
        " verdant in morning growth",
        " secluded in forest peace",
        " quiet in morning stillness",
        " wooded in morning glory",
        " fresh with morning moisture"
        }));

    addTimeOfDayDescription("noon", ({
        " cool in forest shade",
        " peaceful in midday quiet",
        " hidden from harsh sun",
        " wooded in full canopy",
        " sheltered from noon heat",
        " small in intimate scale",
        " verdant in forest abundance",
        " secluded in green depths",
        " quiet in forest stillness",
        " dappled with filtered light"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in filtered sunlight",
        " peaceful in afternoon calm",
        " hidden in forest depths",
        " wooded in afternoon glory",
        " sheltered from afternoon heat",
        " small in cozy beauty",
        " verdant in forest richness",
        " secluded in afternoon peace",
        " quiet in forest tranquility",
        " warm in dappled light"
        }));

    addTimeOfDayDescription("evening", ({
        " mysterious in gathering shadow",
        " peaceful in evening quiet",
        " hidden in deepening gloom",
        " wooded in evening mystery",
        " sheltered from evening wind",
        " small in intimate darkness",
        " verdant in evening moisture",
        " secluded in forest twilight",
        " quiet in evening stillness",
        " shadowy in forest depths"
        }));

    addTimeOfDayDescription("dusk", ({
        " dark in forest twilight",
        " peaceful in dusk stillness",
        " hidden in deep shadow",
        " wooded in dusk mystery",
        " sheltered from dusk air",
        " small in twilight intimacy",
        " verdant in evening dampness",
        " secluded in twilight peace",
        " quiet in gathering darkness",
        " mysterious in forest shadow"
        }));

    addTimeOfDayDescription("night", ({
        " mysterious in forest night",
        " peaceful in night stillness",
        " hidden in complete darkness",
        " wooded in night mystery",
        " sheltered from night wind",
        " small in night intimacy",
        " verdant in night moisture",
        " secluded in night peace",
        " quiet in forest night",
        " dark in protective shadow"
        }));

    addTimeOfDayDescription("late night", ({
        " alive with nocturnal sounds",
        " peaceful in deep forest",
        " hidden in protective darkness",
        " wooded in deep night",
        " sheltered from night elements",
        " small in night security",
        " verdant in night humidity",
        " secluded in forest depths",
        " quiet between forest sounds",
        " mysterious in deep shadow"
        }));

    addTimeOfDayDescription("midnight", ({
        " mysterious in forest depths",
        " peaceful in midnight stillness",
        " hidden in absolute shadow",
        " wooded in midnight mystery",
        " sheltered from midnight wind",
        " small in cosmic intimacy",
        " verdant in midnight moisture",
        " secluded in forest heart",
        " quiet in deepest night",
        " dark in forest protection"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " stark with bare branches",
        " peaceful in winter quiet",
        " hidden in winter forest",
        " wooded in winter beauty",
        " sheltered from winter wind",
        " small in winter intimacy",
        " verdant with evergreen life",
        " secluded in winter peace",
        " quiet in winter stillness",
        " protected in winter depths"
        }));

    addSeasonDescription("spring", ({
        " fresh with new growth",
        " peaceful in spring awakening",
        " hidden in budding forest",
        " wooded in spring renewal",
        " sheltered from spring storms",
        " small in spring beauty",
        " verdant with spring life",
        " secluded in spring peace",
        " quiet in spring tranquility",
        " renewed in forest growth"
        }));

    addSeasonDescription("summer", ({
        " lush with full canopy",
        " peaceful in summer shade",
        " hidden in dense foliage",
        " wooded in summer abundance",
        " sheltered from summer heat",
        " small in summer intimacy",
        " verdant in peak growth",
        " secluded in summer peace",
        " quiet in summer stillness",
        " cool in forest shade"
        }));

    addSeasonDescription("autumn", ({
        " colorful with fall foliage",
        " peaceful in autumn beauty",
        " hidden in autumn colors",
        " wooded in autumn glory",
        " sheltered from autumn wind",
        " small in autumn intimacy",
        " verdant despite season change",
        " secluded in autumn peace",
        " quiet in autumn tranquility",
        " beautiful in forest color"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## dell forming a small, "
        "wooded hollow");

    addItemTemplate("The dell forms a small, secluded hollow surrounded by "
        "trees that create a natural sanctuary within the forest. This intimate "
        "woodland depression provides shelter from wind and weather while "
        "supporting lush vegetation that thrives in the protected, moist "
        "conditions. The surrounding trees form a natural canopy that filters "
        "sunlight and creates a peaceful, almost enchanted atmosphere. Small "
        "streams or springs often feed the dell, while the enclosed nature "
        "makes it feel like a secret garden hidden within the larger woodland.");
}
