//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("market");
    setFloorPlanType("trade");

    addAdjectives(({
        "bustling", "open-air", "colorful", "crowded", "lively", "sprawling"
        }));

    addDescriptionTemplate(
        "a ##Adjective## market filled with stalls, carts, and busy shoppers"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, merchants set up their stalls as the first light appears",
        ". The market is quiet, but the scent of fresh produce fills the air"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the market is alive with the sound of haggling and "
        "laughter",
        ". Shoppers crowd the stalls, seeking the best goods"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the market is at its busiest, the air filled with "
        "voices and scents",
        ". The sun beats down on colorful awnings and busy vendors"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the market begins to quiet as merchants pack up",
        ". The last bargains are struck before the stalls close"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the market is nearly empty, the ground littered "
        "with straw and scraps",
        ". The last rays of sunlight glint off empty carts and closed stalls"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the market square is quiet, the day's business done",
        ". The market is empty, save for a few lingering shoppers"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the market is dark and silent, the stalls closed tight",
        ". Only the occasional watchman passes through the empty square"
        }));

    addSeasonDescription("spring", ({
        " with stalls overflowing with early produce and flowers",
        " as the market hosts festivals and welcomes new merchants"
        }));

    addSeasonDescription("summer", ({
        " with crowds seeking fresh fruit, cool drinks, and shade",
        " as the market is busiest during the long, warm days"
        }));

    addSeasonDescription("autumn", ({
        " with stalls filled with harvest goods and the scent of spices",
        " as the market celebrates the bounty of the season"
        }));

    addSeasonDescription("winter", ({
        " with fewer stalls, but the scent of roasting chestnuts in the air",
        " as the market offers warm drinks and winter wares"
        }));

    addNearDarkDescriptionTemplate(
        "an open-air market with empty stalls and shadowed corners"
    );
    addLowLightDescriptionTemplate(
        "a bustling market with colorful awnings and busy shoppers"
    );
    addDimLightDescriptionTemplate(
        "a crowded market with carts, stalls, and the scent of produce"
    );
    addSomeLightDescriptionTemplate(
        "a lively market with bright banners, busy vendors, and fresh goods"
    );

    addItemTemplate(
        "The market is a sprawling open-air square filled with stalls, carts, "
        "and vendors selling every imaginable good. The air is filled with the "
        "scent of fresh produce, spices, and roasting meats. Shoppers haggle "
        "with merchants, and children dart between the stalls. The market is "
        "the heart of the town's commerce and community."
    );
}
