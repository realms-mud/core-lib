//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sandy ocean beach");
    addAdjectives(({ "expansive", "pristine", "wave-swept", "sun-kissed", "endless" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with sand just catching the faint dawn light",
        "reflecting the colors of ocean sunrise",
        "emerging from the morning ocean mist",
        "touched by the first oceanic dawn",
        "bathed in the pale morning light",
        "shimmering as day breaks over the ocean"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight sparkling on ocean waves",
        "warming in the morning ocean breeze",
        "bright with reflected morning sun",
        "fresh in the ocean morning air",
        "alive with morning beach activity"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "brilliant under the noon ocean sun",
        "radiating midday heat",
        "dazzling in the intense oceanic light",
        "stark white under the blazing sun",
        "shimmering with noon heat waves"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with waves rolling in steadily",
        "comfortable in the afternoon ocean breeze",
        "peaceful in the late afternoon sun",
        "dotted with afternoon ocean visitors",
        "warm beneath the softening sun",
        "serene in the late day ocean calm"
        }));
    addTimeOfDayDescription("evening", ({
        "with sand glowing in the golden evening light",
        "as the sun sets over the endless ocean",
        "painted in magnificent sunset colors",
        "beautiful in the evening ocean glow",
        "transformed by the golden oceanic hour",
        "romantic as day fades over the water"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the ocean twilight",
        "becoming mysterious as dusk settles",
        "peaceful in the gathering ocean darkness",
        "cool in the evening ocean breeze",
        "serene as night approaches the water",
        "contemplative in the deepening dusk"
        }));
    addTimeOfDayDescription("night", ({
        "outlined by moonlight on ocean waves",
        "peaceful under the ocean night sky",
        "silvered by moonlight on the water",
        "quiet save for the eternal ocean rhythm",
        "mysterious in the oceanic darkness",
        "enchanted by the night ocean sounds"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight ocean sky",
        "lost in the deep ocean darkness",
        "hidden in the profound night",
        "merged with the dark ocean waters",
        "invisible save for crashing waves",
        "swallowed by the oceanic midnight"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " battered by powerful winter storms",
        " carved by fierce winter swells", " scattered with storm wreckage",
        " reshaped by winter's ocean fury", " marked by towering winter waves",
        " transformed by seasonal ocean violence" }));
    addSeasonDescription("spring", ({ " alive with spring ocean currents",
        " visited by migrating ocean wildlife", " adorned with spring sea life",
        " fresh with seasonal ocean breezes", " renewed by spring tides",
        " awakening with ocean spring activity" }));
    addSeasonDescription("summer", ({ " perfect for ocean recreation",
        " warm with summer ocean breezes", " bustling with summer ocean life",
        " inviting for ocean activities", " alive with summer beachgoers",
        " ideal for ocean enjoyment" }));
    addSeasonDescription("autumn", ({ " swept by autumn ocean storms",
        " peaceful in the cooler ocean weather", " beautiful in autumn's ocean light",
        " marked by changing ocean patterns", " contemplative as seasons change",
        " dramatic with autumn ocean swells" }));

    addAlias("beach");
    addAlias("sand");
    addAlias("sandy beach");
    addAlias("ocean shore");
    addAlias("shore");
    addAlias("coastline");

    addDescriptionTemplate("a ##Adjective## sandy ocean beach");
    addItemTemplate("The sandy ocean beach extends endlessly along the "
        "vast oceanic coastline, its pristine sand constantly sculpted "
        "by powerful ocean waves. The relentless rhythm of the ocean "
        "creates an ever-changing shoreline where massive swells crash "
        "and retreat, leaving behind treasures from the deep. Salt spray "
        "fills the air while seabirds patrol the endless expanse. The "
        "beach represents the meeting place of two infinite realms - "
        "the solid earth and the boundless ocean. Tidal pools form in "
        "rocky outcroppings, while the sand shifts with each powerful "
        "wave, creating a dynamic landscape of oceanic grandeur.");
}
