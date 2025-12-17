//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dreamscape Shift");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of subtly shifting the perceived reality around them, "
        "making it harder for enemies to land their attacks.");

    addPrerequisite("/guilds/oneiromancer/dream-magic/slumber-ward.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 7
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("bonus defense", 2);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus parry", 2);
}
