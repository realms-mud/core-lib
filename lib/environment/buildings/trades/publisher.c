//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("publisher");
    setFloorPlanType("trade");

    addAdjectives(({
        "bustling", "ink-stained", "book-filled", "lively", "scholarly", "busy"
        }));

    addDescriptionTemplate(
        "a ##Adjective## publisher's shop with stacks of books and papers"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the publisher's shop is quiet, the presses still",
        ". The first light glimmers on stacks of parchment and inkpots"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the shop is alive with the sound of presses and "
        "scribes at work",
        ". The scent of ink and paper fills the air as new books are bound"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the shop is busy with customers seeking the latest news "
        "and stories",
        ". The presses run hot as workers bind and stack fresh pages"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the shop is filled with the sound of quills "
        "scratching and presses thumping",
        ". The publisher reviews proofs and prepares new editions"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the presses slow and the last books are stacked "
        "for delivery",
        ". The shop glows with lamplight as scribes finish their work"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the shop is quiet, the day's work nearly done",
        ". The scent of ink lingers as the last customers depart"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the shop is dark, the presses silent and the doors locked",
        ". Only the night watchman remains, guarding the publisher's wares"
        }));

    addSeasonDescription("spring", ({
        " with new stories and pamphlets celebrating the season's festivals",
        " as the publisher prepares special editions for spring events"
        }));

    addSeasonDescription("summer", ({
        " with open windows letting in warm air and the scent of fresh ink",
        " as the shop is busy with travelers and scholars"
        }));

    addSeasonDescription("autumn", ({
        " with tales of harvest and adventure filling the shelves",
        " as the publisher prepares for the winter's long nights of reading"
        }));

    addSeasonDescription("winter", ({
        " with fires burning in the hearth and the presses running to meet "
        "holiday demand",
        " as the shop offers warmth and stories for the cold season"
        }));

    addNearDarkDescriptionTemplate(
        "a book-filled publisher's shop with shadowed shelves and quiet presses"
    );
    addLowLightDescriptionTemplate(
        "a bustling publisher with stacks of books and the scent of ink"
    );
    addDimLightDescriptionTemplate(
        "an ink-stained shop with presses, books, and busy scribes"
    );
    addSomeLightDescriptionTemplate(
        "a lively publisher's shop with fresh books, busy presses, and "
        "scholarly chatter"
    );

    addItemTemplate(
        "The publisher's shop is filled with the scent of ink and the sound "
        "of presses. Stacks of books, pamphlets, and loose pages fill the "
        "shelves and tables. Scribes and printers work busily, and customers "
        "browse the latest stories and news. The shop is a hub of learning "
        "and communication for the town."
    );
}
