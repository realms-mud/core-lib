//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Favor");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "Ferianth's divine favor, granting greater protection.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/sacred-fortitude.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 28
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist evil", 3);
    addSpecification("bonus soak", 1);
}
