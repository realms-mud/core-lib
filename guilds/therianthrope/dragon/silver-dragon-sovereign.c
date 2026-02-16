//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Silver Dragon Sovereign");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your dragon form reaches its ultimate "
        "potential, embodying the primordial silver dragon sovereign. "
        "Your claws can shatter glaciers, your breath can freeze oceans, "
        "and your scales are harder than any known material.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level", "guild": "therianthrope", "value": 85 ]));
    addPrerequisite("/guilds/therianthrope/dragon/mythic-dragon.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 200);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 5);
    addSpecification("bonus soak", 5);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus defense", 5);
    addSpecification("bonus claw attack", 30);
    addSpecification("bonus magical attack", 30);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 35, 
        "Tail Lash": 35, 
        "Frost Breath": 35,
        "Soul Freeze": 35,
        "Frozen Blight": 35, 
        "Glacial Tempest": 35
    ]));
}
