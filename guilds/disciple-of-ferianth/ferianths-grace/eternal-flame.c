//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Flame");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "The Exarch's connection to Ferianth "
        "becomes eternal, granting permanent divine protection and power.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/divine-vessel.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 65
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist fire", 5);
    addSpecification("bonus resist evil", 5);
    addSpecification("bonus resist undead", 5);
    addSpecification("bonus defense", 5);
    addSpecification("bonus spell points", 100);
}
