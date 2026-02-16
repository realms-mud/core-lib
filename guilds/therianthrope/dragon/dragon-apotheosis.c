//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dragon Apotheosis");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your dragon form transcends the merely "
        "physical, becoming an avatar of draconic perfection with "
        "devastating frost and savage precision.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level", "guild": "therianthrope", "value": 57 ]));
    addPrerequisite("/guilds/therianthrope/dragon/ancient-wyrm.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus cold enchantment", 2);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 25, 
        "Tail Lash": 25, 
        "Frost Breath": 25,
        "Soul Freeze": 25, 
        "Frozen Blight": 25, 
        "Glacial Tempest": 25
    ]));
}
