//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Parry III");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research attunes the "
        "scion's avatar to be more adept at parrying attacks.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "Scion of Dhuras Guild",
        "value": 19
    ]));

    addPrerequisite("/guilds/scion/avatars/common/parry-ii.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/scion/avatars/blood/root.c",
        "/guilds/scion/avatars/electricity/root.c",
        "/guilds/scion/avatars/evocation/root.c",
        "/guilds/scion/avatars/flame/root.c",
        "/guilds/scion/avatars/ice/root.c",
        "/guilds/scion/avatars/spirit/root.c",
    }));
}
