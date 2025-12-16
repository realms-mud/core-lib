//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Protection");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to become an avatar of Ilryth's protective aspect. The "
        "caster embodies the goddess's role as defender of her faithful.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 57 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/ilryths-sanctuary.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 8);
    addSpecification("bonus soak", 8);
    addSpecification("bonus magical essence", 6);
    addSpecification("bonus resist physical", 8);
    addSpecification("bonus resist magical", 8);

    addSpecification("affected research", ([
        "Tsunami Shield": 35,
        "Ilyryth's Sanctuary": 30,
        "Mantle of Ilyrth": 25
    ]));
    addSpecification("affected research type", "percentage");
}
