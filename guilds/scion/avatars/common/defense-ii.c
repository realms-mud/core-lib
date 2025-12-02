//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Defense II");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research attunes the "
        "scion's avatar to be more adept at defneding against "
        "attacks.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "Scion of Dhuras Guild",
        "value": 9
    ]));

    addPrerequisite("/guilds/scion/avatars/common/defense-i.c",
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
