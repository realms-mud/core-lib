//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Balanced Recovery");
    addSpecification("source", "monk");
    addSpecification("description",
        "The palm has barely landed when the rear foot draws your weight "
        "home. A teacher watches for the moment you stop falling after "
        "your own hand and stand ready for the answer.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":2
    ]));
    addPrerequisite("/guilds/monk/unarmed/measured-palm.c", ([
        "type":"research"
    ]));
    addPrerequisite("measured palm practice", ([
        "type":"observation",
        "criteria":([
            "type":"combat.kata",
            "research":"/guilds/monk/unarmed/measured-palm.c",
            "qualifying opponent":1
        ]),
        "value":10
    ]));

    addSpecification("scope", "self");

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("bonus dodge", 1);
}
