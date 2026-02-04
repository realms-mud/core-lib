//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Vessel");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "The Exarch becomes a divine vessel "
        "of Ferianth's power, permanently enhanced by sacred fire.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/holy-bastion.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 61
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 2);
    addSpecification("bonus defense", 2);
    addSpecification("bonus heal hit points rate", 1);
    addSpecification("bonus heal spell points rate", 1);
}
