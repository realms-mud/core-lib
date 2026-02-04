//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Resilience");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "The Exarch's divine connection "
        "provides enhanced resilience against magical attacks.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/ferianthian-judgment.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 41
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 3);
    addSpecification("bonus resist undead", 3);
    addSpecification("bonus soak", 1);
}
