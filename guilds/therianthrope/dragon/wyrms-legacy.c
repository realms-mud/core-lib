//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wyrm's Legacy");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You carry the legacy of the greatest "
        "silver wyrms, your defensive mastery unmatched by any mortal "
        "creature.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level", 
            "guild": "therianthrope", 
            "value": 73 ]));

    addPrerequisite("/guilds/therianthrope/dragon/eternal-winter.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 150);
    addSpecification("bonus soak", 6);
    addSpecification("bonus defense", 4);
    addSpecification("bonus resist physical", 5);
    addSpecification("bonus resist cold", 5);
}
