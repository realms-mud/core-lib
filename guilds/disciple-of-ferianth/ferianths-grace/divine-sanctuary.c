//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Sanctuary");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "Ferianth's protection surrounds the "
        "Exarch, providing a sacred sanctuary against harm.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/rebirth-from-ashes.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 45
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus soak", 2);
}
