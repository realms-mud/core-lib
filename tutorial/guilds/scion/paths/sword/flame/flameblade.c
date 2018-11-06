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
        addSpecification("name", "Flame Blade");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "");

        addPrerequisite("lib/tutorial/guilds/scion/paths/sword/root.c",
            (["type":"research"]));
        addPrerequisite("lib/tutorial/guilds/scion/paths/flame.c",
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/tutorial/guilds/scion/paths/sword/sweepingFlames.c",
                "name" : "sweeping flames",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/tutorial/guilds/scion/paths/sword/flameBrand.c",
                "name" : "flame brand",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/tutorial/guilds/scion/paths/sword/searingBlade.c",
                "name" : "searing blade",
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
        addSpecification("command template", "flame blade");
        addSpecification("bonus fire enchantment", 3);
        addSpecification("bonus resist fire", 3);

        addSpecification("use ability activate message", "Thin tendrils of flame "
            "wrap around ##InitiatorPossessive::Name## sword.");
        addSpecification("use ability deactivate message", "Thin tendrils of flame "
            "around ##InitiatorPossessive::Name## sword subside.");
    }
}
