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
        addSpecification("name", "Shock Blade");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the lightning blade technique. By means of this, the "
            "Scion is able to emit a strong, constant electrical current from their "
            "dagger. Doing so is wearying and will decrease available stamina.");

        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addPrerequisite("lib/guilds/scion/paths/dagger/root.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/dagger/electricity/shockblade.c",
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 25
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/sweeping-shock.c",
                "name" : "sweeping shock",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/shock-brand.c",
                "name" : "shock brand",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/energized-blade.c",
                "name" : "energized blade",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/shocking-edge.c",
                "name" : "shocking edge",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/thunders-pommel.c",
                "name" : "Thunder's Pommel",
                "formula" : "additive",
                "base value" : 6,
                "rate": 1.0
            ]),
        }));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 180);
        addSpecification("spell point cost", 50);
        addSpecification("stamina point cost", 200);
        addSpecification("command template", "lightning blade");
        addSpecification("bonus electricity enchantment", 10);
        addSpecification("bonus resist electricity", 25);

        addSpecification("use ability activate message", "Crawling tendrils of "
            "lightning wrap around ##InitiatorPossessive::Name## dagger.");
        addSpecification("use ability deactivate message", "The tendrils of "
            "lightning around ##InitiatorPossessive::Name## dagger subside.");
    }
}
