//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        persistedActiveResearchItem::reset(arg);
        addSpecification("name", "Shocking Barrier");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the shocking barrier technique. By means of this, the "
            "Scion is able to use their sword as a conduit for emitting electric "
            "energy that swarms around and harries a foe.");

        addSpecification("limited by", (["equipment":({
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("lib/guilds/scion/paths/sword/root.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/sword/electricity/shocking-tendrils.c",
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 13
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/static-barrier.c",
                "name" : "Static Charge",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/ionized-barrier.c",
                "name" : "Ionization",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/plasma-barrier.c",
                "name" : "Plasma Eruption",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"skill",
                "name" : "long sword",
                "formula" : "additive",
                "rate" : 1.05
            ]),
            ([
                "type":"skill",
                "name" : "elemental air",
                "formula" : "additive",
                "rate" : 1.10
            ]),
            ([
                "type":"skill",
                "name" : "spellcraft",
                "formula" : "logarithmic",
                "rate" : 1.10
            ]),
            ([
                "type":"level",
                "name" : "level",
                "formula" : "logarithmic",
                "rate" : 1.10
            ]),
            ([
                "type":"attribute",
                "name" : "intelligence",
                "formula" : "additive",
                "rate" : 1.05
            ]) 
        }));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 120);
        addSpecification("duration", 60);
        addSpecification("spell point cost", 75);
        addSpecification("event handler", "shockingBarrierEvent");
        addSpecification("command template", "shocking barrier [at ##Target##]");
        addSpecification("penalty to resist electricity", 10);
        addSpecification("penalty to resist physical", 10);
        addSpecification("apply enfeebled", 1);

        addSpecification("use ability message", "A wave of electricity flies "
            "from ##InitiatorPossessive::Name## sword and engulfs "
            "##TargetName##.");
    }
}
