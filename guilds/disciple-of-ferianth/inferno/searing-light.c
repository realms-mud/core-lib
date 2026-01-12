//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Searing Light");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill enhances the disciple's "
        "connection to Ferianth's divine fire, improving their ability "
        "to channel offensive flames.");

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
    addSpecification("bonus elemental fire", 2);
    addSpecification("bonus spellcraft", 1);
}
