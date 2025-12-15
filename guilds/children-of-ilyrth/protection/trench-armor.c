//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Trench Armor");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with armor "
        "forged from the pressure of the deepest ocean trenches. The caster's "
        "shields can withstand almost any assault.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 33 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/ocean-bastion.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus soak", 6);
    addSpecification("bonus resist physical", 5);

    addSpecification("affected research", ([
        "Aquatic Shield": 25,
        "Tidal Barrier": 25,
        "Ilyryth's Aegis": 25,
        "Sanctuary of Waves": 25,
        "Tsunami Shield": 20
    ]));
    addSpecification("affected research type", "percentage");
}
