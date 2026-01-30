//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Smoldering Defense");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "enhanced protection while their ashen ward is active.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/ashen-retribution/ashen-ward.c"
        })
    ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ashen-retribution/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 9
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus defense", 1);
}
