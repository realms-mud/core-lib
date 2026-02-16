//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frostfall");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your dragon form moves with supernatural "
        "speed, your strikes becoming a blur of frost-rimed claws and "
        "icy breath.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level", "guild": "therianthrope", "value": 57 ]));
    addPrerequisite("/guilds/therianthrope/dragon/winter-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus attack", 2);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Frost Claw": 1,
        "Tail Lash": 1, 
        "Frost Breath": 2,
        "Soul Freeze": 2, 
        "Frozen Blight": 2,
        "Glacial Tempest": 3
    ]));
}