//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Death Resilience");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research hardens the Disciple against death itself through their deep attunement to death energy.");

    addPrerequisite("/guilds/disciple-of-argloth/blood/dark-potency.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 48
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus armor class", 5);
    addSpecification("bonus resist magical", 6);
    addSpecification("bonus hit points", 50);
}
