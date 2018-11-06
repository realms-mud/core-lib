//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        sustainedResearchItem::reset(arg);
        addSpecification("name", "Energy Blade");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "");

        addPrerequisite("lib/tutorial/guilds/scion/paths/sword/root.c",
            (["type":"research"]));
        addPrerequisite("lib/tutorial/guilds/scion/paths/evocation.c",
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/tutorial/guilds/scion/paths/sword/sweepingBlast.c",
                "name" : "sweeping flames",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/tutorial/guilds/scion/paths/sword/energyBrand.c",
                "name" : "flame brand",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/tutorial/guilds/scion/paths/sword/scintilatingBlade.c",
                "name" : "scintilating blade",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/tutorial/guilds/scion/paths/sword/flamingEdge.c",
                "name" : "flaming edge",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/tutorial/guilds/scion/paths/sword/ferianthsPommel.c",
                "name" : "Ferianth's Pommel",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
        }));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 4);
        addSpecification("spell point cost", 10);
        addSpecification("stamina point cost", 50);
        addSpecification("command template", "energy blade");
        addSpecification("bonus energy enchantment", 3);
        addSpecification("bonus resist energy", 3);

        addSpecification("use ability activate message", "Thin wisps of pulsating "
            "energy wrap around ##InitiatorPossessive::Name## sword.");
        addSpecification("use ability deactivate message", "Thin wisps of pulsating "
            "energy around ##InitiatorPossessive::Name## sword fade away.");
    }
}
