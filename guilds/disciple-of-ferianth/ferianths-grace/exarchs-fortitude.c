//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Exarch's Fortitude");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "The Exarch's connection to Ferianth "
        "grants sacred fortitude against harm.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/exarchs-resolve.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus resist evil", 2);
    addSpecification("bonus soak", 1);
}
