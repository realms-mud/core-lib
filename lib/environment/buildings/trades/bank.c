//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bank");
    setFloorPlanType("bank");

    addAdjectives(({
        "imposing", "stone", "secure", "vaulted", "grand", "fortified"
        }));

    addDescriptionTemplate(
        "a ##Adjective## bank with thick stone walls and an arched entryway"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the bank's heavy doors remain closed, its stone facade "
        "catching the first golden rays of sunlight",
        ". The bank stands silent and secure as the city stirs to life"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, townsfolk begin to gather at the steps, waiting "
        "for the bank to open its doors",
        ". The bank's clerks prepare ledgers and coin for the day's business"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the bank is busy with merchants and townsfolk exchanging "
        "coin and securing valuables",
        ". The cool interior offers respite from the sun for those conducting "
        "their business"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the bank's tellers are busy counting coins and "
        "recording transactions",
        ". The sound of clinking coins and murmured conversation fills the "
        "grand hall"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the bank's doors close and guards begin their "
        "nightly watch",
        ". The last customers leave as the bank secures its vaults for the night"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the bank's windows reflect the fading light, and the "
        "building takes on a somber, imposing presence",
        ". The bank's staff finish their final tallies before locking away "
        "the day's earnings"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the bank is dark and silent, its thick walls and iron "
        "bars promising security",
        ". Only the occasional lantern carried by a patrolling guard disturbs "
        "the shadows around the building"
        }));

    addSeasonDescription("spring", ({
        " with flower boxes beneath the windows, a rare touch of color on the "
        "otherwise austere facade",
        " as townsfolk deposit the first profits of the year from spring trade"
        }));

    addSeasonDescription("summer", ({
        " with sunlight glinting off polished brass fixtures and the cool "
        "interior offering relief from the heat",
        " as merchants bring in coin from the busy summer markets"
        }));

    addSeasonDescription("autumn", ({
        " as townsfolk secure their harvest earnings and prepare for winter",
        " with ledgers filled with the records of a prosperous season"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the steps and the bank's hearth burning to "
        "warm its clerks",
        " as townsfolk seek the safety of the vaults for their valuables "
        "during the long, cold nights"
        }));

    addNearDarkDescriptionTemplate(
        "a large stone building with a heavy, shadowed entryway"
    );
    addLowLightDescriptionTemplate(
        "a fortified stone bank with iron-barred windows and a guarded door"
    );
    addDimLightDescriptionTemplate(
        "an imposing bank with thick stone walls and a vaulted ceiling"
    );
    addSomeLightDescriptionTemplate(
        "a grand bank with polished stone floors, high ceilings, and "
        "brass fixtures"
    );

    addItemTemplate(
        "The bank is constructed from heavy stone blocks, its facade "
        "dominated by an arched entryway and iron-bound doors. Inside, "
        "polished stone floors and high ceilings create an atmosphere of "
        "wealth and security. Brass fixtures gleam in the light, and "
        "tellers work behind sturdy counters. A massive vault door stands "
        "at the rear, promising safety for the town's coin and treasures. "
        "Guards patrol the halls, and the air is filled with the quiet "
        "murmur of business and the clink of coin."
    );

    addSourceOfLight(2);
}
