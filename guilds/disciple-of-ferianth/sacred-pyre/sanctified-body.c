//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sanctified Body");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "a sanctified body that resists corruption and harm.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/divine-favor.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 36
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist undead", 3);
    addSpecification("bonus resist evil", 2);
    addSpecification("bonus soak", 1);
}
