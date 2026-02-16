//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Silver Dominion");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your draconic presence emanates an "
        "aura of icy dominion, bolstering your defenses and regeneration.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level", 
            "guild": "therianthrope",
            "value": 61 ]));
    addPrerequisite("/guilds/therianthrope/dragon/frostfall.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points", 10);
    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus heal spell points rate", 3);
    addSpecification("bonus heal stamina rate", 3);
    addSpecification("bonus resist cold", 10);
    addSpecification("bonus resist fire", 5);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Breath": 35,
        "Soul Freeze": 35, 
        "Glacial Tempest": 35
    ]));
}