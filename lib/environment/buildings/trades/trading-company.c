//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("trading company");
    setFloorPlanType("trade");

    addAdjectives(({
        "bustling", "stone", "timber", "well-appointed", "busy", "prosperous"
        }));

    addDescriptionTemplate(
        "a ##Adjective## trading company office with ledgers and busy clerks"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the trading company is quiet, the first light glinting "
        "off polished wood",
        ". Clerks prepare for the day's business, reviewing ledgers"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the office is alive with the sound of quills and "
        "voices",
        ". Merchants and traders gather to negotiate deals"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the office is busy, the air filled with the scent of "
        "parchment and ink",
        ". Clerks pause for a meal among stacks of ledgers"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the trading company's output is at its peak, "
        "with deals struck and goods dispatched",
        ". The sound of commerce and negotiation fills the building"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the office quiets and the day's accounts are "
        "tallied",
        ". The last merchants leave as the sun sets behind the building"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the trading company stands silent, the day's business done",
        ". The building's outline is dark against the fading sky"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the office is dark and still, watched over by a lone "
        "night watchman",
        ". The trading company rests, the day's labor at an end"
        }));

    addSeasonDescription("spring", ({
        " with new contracts signed and the promise of a busy season ahead",
        " as the trading company prepares for the influx of goods"
        }));

    addSeasonDescription("summer", ({
        " with open windows letting in warm breezes and the sound of busy work",
        " as the office is filled with the hum of commerce"
        }));

    addSeasonDescription("autumn", ({
        " with ledgers stacked high and preparations for winter underway",
        " as the trading company completes deals for the harvest season"
        }));

    addSeasonDescription("winter", ({
        " with fires burning in the hearth and the office warm and bright",
        " as clerks work late to balance the year's accounts"
        }));

    addNearDarkDescriptionTemplate(
        "a stone trading company office with shadowed ledgers and silent clerks"
    );
    addLowLightDescriptionTemplate(
        "a busy trading company with open doors and the scent of parchment"
    );
    addDimLightDescriptionTemplate(
        "a prosperous office with ledgers, goods, and busy merchants"
    );
    addSomeLightDescriptionTemplate(
        "a well-appointed trading company with open doors, busy clerks, and "
        "stacks of goods"
    );

    addItemTemplate(
        "The trading company office is a well-appointed building of stone and "
        "timber, filled with ledgers, goods, and busy clerks. Merchants and "
        "traders negotiate deals, and the air is filled with the scent of "
        "parchment and ink. The trading company is the heart of the town's "
        "commerce and prosperity."
    );

    addSourceOfLight(1);
}
