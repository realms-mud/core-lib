//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Kindle");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill teaches the disciple to "
        "kindle their inner flame more efficiently, reducing the cost "
        "of fire spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 3
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/flame-touch.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 1);
    addSpecification("bonus spell points", 10);
}
