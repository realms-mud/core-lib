//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("glen");
    addAdjectives(({ "narrow", "secluded", "wooded", "peaceful", "winding",
        "sheltered", "hidden", "verdant" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " misty in morning vapor",
        " peaceful in dawn quiet",
        " hidden in early shadows",
        " narrow in dawn light",
        " wooded in morning mist",
        " secluded in dawn stillness",
        " sheltered from early wind",
        " verdant in morning dew",
        " winding through dawn shadows",
        " quiet in morning peace"
        }));

    addTimeOfDayDescription("morning", ({
        " dappled with filtered sunlight",
        " peaceful in morning calm",
        " hidden in forest depths",
        " narrow in bright clarity",
        " wooded in morning glory",
        " secluded in morning peace",
        " sheltered from morning breeze",
        " verdant in morning growth",
        " winding through morning light",
        " quiet in forest stillness"
        }));

    addTimeOfDayDescription("noon", ({
        " cool in forest shade",
        " peaceful in midday stillness",
        " hidden from harsh sun",
        " narrow in filtered light",
        " wooded in full canopy",
        " secluded in green depths",
        " sheltered from noon heat",
        " verdant in forest abundance",
        " winding through cool shade",
        " quiet in forest peace"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in filtered light",
        " peaceful in afternoon calm",
        " hidden in forest depths",
        " narrow in dappled illumination",
        " wooded in afternoon glory",
        " secluded in green peace",
        " sheltered from afternoon heat",
        " verdant in forest richness",
        " winding through golden light",
        " quiet in afternoon stillness"
        }));

    addTimeOfDayDescription("evening", ({
        " mysterious in gathering shadow",
        " peaceful in evening quiet",
        " hidden in deepening gloom",
        " narrow in twilight dimness",
        " wooded in evening mystery",
        " secluded in forest twilight",
        " sheltered from evening wind",
        " verdant in evening moisture",
        " winding through gathering dark",
        " quiet in evening stillness"
        }));

    addTimeOfDayDescription("dusk", ({
        " dark in forest twilight",
        " peaceful in dusk stillness",
        " hidden in deep shadow",
        " narrow in fading light",
        " wooded in dusk mystery",
        " secluded in twilight peace",
        " sheltered from dusk air",
        " verdant in evening moisture",
        " winding through twilight shadow",
        " quiet in gathering darkness"
        }));

    addTimeOfDayDescription("night", ({
        " mysterious in forest darkness",
        " peaceful in night stillness",
        " hidden in complete shadow",
        " narrow in lunar filtering",
        " wooded in night mystery",
        " secluded in night peace",
        " sheltered from night wind",
        " verdant in night moisture",
        " winding through night shadow",
        " quiet in forest night"
        }));

    addTimeOfDayDescription("late night", ({
        " alive with nocturnal sounds",
        " peaceful in deep forest night",
        " hidden in protective darkness",
        " narrow in night mystery",
        " wooded in deep night",
        " secluded in forest depths",
        " sheltered from night elements",
        " verdant in night humidity",
        " winding through deep shadow",
        " quiet between forest sounds"
        }));

    addTimeOfDayDescription("midnight", ({
        " mysterious in deepest forest",
        " peaceful in midnight stillness",
        " hidden in absolute shadow",
        " narrow in cosmic darkness",
        " wooded in midnight mystery",
        " secluded in forest heart",
        " sheltered from midnight wind",
        " verdant in midnight moisture",
        " winding through midnight shadow",
        " quiet in forest depths"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " stark with bare branches",
        " peaceful in winter quiet",
        " hidden in winter depths",
        " narrow in winter clarity",
        " wooded in winter beauty",
        " secluded in winter peace",
        " sheltered from winter wind",
        " verdant with evergreen life",
        " winding through winter forest",
        " quiet in winter stillness"
        }));

    addSeasonDescription("spring", ({
        " fresh with new growth",
        " peaceful in spring awakening",
        " hidden in budding foliage",
        " narrow in spring clarity",
        " wooded in spring renewal",
        " secluded in spring peace",
        " sheltered from spring storms",
        " verdant with spring life",
        " winding through spring forest",
        " quiet in spring tranquility"
        }));

    addSeasonDescription("summer", ({
        " lush with full canopy",
        " peaceful in summer shade",
        " hidden in dense foliage",
        " narrow in green tunnel",
        " wooded in summer abundance",
        " secluded in summer peace",
        " sheltered from summer heat",
        " verdant in peak growth",
        " winding through summer forest",
        " quiet in summer stillness"
        }));

    addSeasonDescription("autumn", ({
        " colorful with fall foliage",
        " peaceful in autumn beauty",
        " hidden in autumn color",
        " narrow in golden light",
        " wooded in autumn glory",
        " secluded in autumn peace",
        " sheltered from autumn wind",
        " verdant despite season change",
        " winding through autumn forest",
        " quiet in autumn tranquility"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## glen forming a narrow, "
        "wooded valley");

    addItemTemplate("The glen forms a narrow, secluded valley that winds "
        "through wooded terrain, creating a natural corridor sheltered by "
        "trees and rising ground on either side. This peaceful hollow provides "
        "protection from wind and weather while supporting lush vegetation "
        "that thrives in the moist, shaded conditions. Streams often flow "
        "through the glen's bottom, while the enclosed nature creates an "
        "intimate, almost secret feeling. The winding course and forest cover "
        "make the glen feel removed from the outside world, a hidden sanctuary "
        "within the larger landscape.");
}
