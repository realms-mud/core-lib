//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Holy Bastion");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "The Exarch becomes a holy bastion, "
        "greatly enhanced by Ferianth's divine protection.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/divine-sanctuary.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 53
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist fire", 5);
    addSpecification("bonus resist evil", 3);
    addSpecification("bonus resist undead", 3);
    addSpecification("bonus hit points", 50);
}