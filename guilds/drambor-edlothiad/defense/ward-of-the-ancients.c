//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ward of the Ancients");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the ward of the ancients, the "
        "supreme defensive art of the eldest Drambor "
        "warriors. This technique weaves together "
        "every known form of magical protection into "
        "a seamless tapestry that renders the "
        "battlemage nearly impervious to harm.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "ward-of-ages.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 59
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 7);
    addSpecification("bonus resist physical", 8);
    addSpecification("bonus resist magical", 8);
}
