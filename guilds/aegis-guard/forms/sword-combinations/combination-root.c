//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/combinedInstantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Godrebh ai Megil");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of executing combined actions in swordplay.");

        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" }) ]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "tree root");
        addSpecification("maximum combination chain", 2);
        addSpecification("spell point cost", 10);
        addSpecification("stamina point cost", 25);

        addSpecification("combination rules", ([
            "must include any of": ({ 
                "guilds/aegis-guard/forms/sword-attacks/ercho.c",
                "guilds/aegis-guard/forms/sword-attacks/nestegi.c",
                "guilds/aegis-guard/forms/sword-attacks/esgeri.c",
                "guilds/aegis-guard/forms/sword-attacks/cirithu.c",
                "guilds/aegis-guard/forms/sword-attacks/dravo.c",
                "guilds/aegis-guard/forms/sword-attacks/naetho.c",
                "guilds/aegis-guard/forms/sword-attacks/maetha.c",
                "guilds/aegis-guard/forms/sword-attacks/hasto.c",
                "guilds/aegis-guard/forms/sword-attacks/maego.c",
                "guilds/aegis-guard/forms/sword-attacks/narcha.c",
            }),
            "can include only one of": ({ 
                "guilds/aegis-guard/forms/sword-mythic/auth.c",
                "guilds/aegis-guard/forms/sword-mythic/anwar.c",
                "guilds/aegis-guard/forms/sword-mythic/dagnir.c",
                "guilds/aegis-guard/forms/sword-mythic/sereg.c",
                "guilds/aegis-guard/forms/sword-mythic/edlothia.c",
                "guilds/aegis-guard/forms/sword-mythic/celair.c",
                "guilds/aegis-guard/forms/sword-mythic/guruthos.c",
                "guilds/aegis-guard/forms/sword-mythic/manadh.c",
                "guilds/aegis-guard/forms/sword-mythic/ambar.c",
                "guilds/aegis-guard/forms/sword-mythic/lhutha.c",
                "guilds/aegis-guard/forms/sword-mythic/naurtho.c",
                "guilds/aegis-guard/forms/sword-mythic/heleg.c",
                "guilds/aegis-guard/forms/sword-mythic/glauro.c",
                "guilds/aegis-guard/forms/sword-mythic/angolo.c",
                "guilds/aegis-guard/forms/sword-mythic/eiliant.c",
                "guilds/aegis-guard/forms/sword-mythic/geilo.c",
                "guilds/aegis-guard/forms/sword-mythic/alagos.c",
                "guilds/aegis-guard/forms/sword-mythic/lhorn.c",
                "guilds/aegis-guard/forms/sword-mythic/gwaeren.c",
            }),
            "can include any of": ({ 
                "guilds/aegis-guard/forms/sword-actions/athra.c",
                "guilds/aegis-guard/forms/sword-actions/celeg.c",
                "guilds/aegis-guard/forms/sword-actions/raeg.c",
                "guilds/aegis-guard/forms/sword-actions/lanc.c",
                "guilds/aegis-guard/forms/sword-actions/gleina.c",
                "guilds/aegis-guard/forms/sword-actions/delu.c",
                "guilds/aegis-guard/forms/sword-actions/braig.c",
                "guilds/aegis-guard/forms/sword-actions/beraid.c",
                "guilds/aegis-guard/forms/sword-actions/gling.c",
                "guilds/aegis-guard/forms/sword-actions/naergo.c",
                "guilds/aegis-guard/forms/sword-actions/tur.c",
                "guilds/aegis-guard/forms/sword-actions/bauglo.c",
                "guilds/aegis-guard/forms/sword-actions/dadben.c",
                "guilds/aegis-guard/forms/sword-actions/gliri.c",
                "guilds/aegis-guard/forms/sword-actions/hwinio.c",
            })
        ]));

        addSpecification("max combination chain modifier", ({ 
            ([
                "type": "research",
                "research item": 
                    "guilds/aegis-guard/forms/sword-combinations/godramin.c",
                "name": "Combo I",
                "formula": "additive",
                "base value": 1,
                "rate": 1.0
            ]), 
            ([
                "type": "research",
                "research item": 
                    "guilds/aegis-guard/forms/sword-combinations/tad-godref.c",
                "name": "Combo II",
                "formula": "additive",
                "base value": 1,
                "rate": 1.0
            ]), 
            ([
                "type": "research",
                "research item": 
                    "guilds/aegis-guard/forms/sword-combinations/neledh-godref.c",
                "name": "Combo III",
                "formula": "additive",
                "base value": 1,
                "rate": 1.0
            ]), 
        }));

        addSpecification("modifiers", ({ 
            ([
                "type": "research",
                "research item":
                    "guilds/aegis-guard/forms/sword-combinations/an-alag.c",
                "name": "an-alag",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.05
            ]),
            ([
                "type": "research",
                "research item":
                    "guilds/aegis-guard/forms/sword-combinations/thel-hannas.c",
                "name": "thel-hannas",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.05
            ]),
            ([
                "type": "research",
                "research item":
                    "guilds/aegis-guard/forms/sword-combinations/laeg-hannas.c",
                "name": "laeg-hannas",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.05
            ]),
            ([
                "type": "research",
                "research item":
                    "guilds/aegis-guard/forms/sword-combinations/bronadui-hannas.c",
                "name": "bronadui-hannas",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.10
            ]),
            ([
                "type": "research",
                "research item":
                    "guilds/aegis-guard/forms/sword-combinations/golwen-alag.c",
                "name": "golwen-alag",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": 
                    "guilds/aegis-guard/forms/sword-combinations/tur-godref.c",
                "name": "tur-godref",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type":"highest skill",
                "name" : "sword skills",
                "skills": ({ "dagger", "short sword", "long sword", 
                    "hand and a half sword", "two-handed sword" }),
                "formula" : "logarithmic",
                "base value" : 5,
                "rate" : 1.10
            ]),
            ([
                "type": "skill",
                "name": "dancing",
                "formula": "additive",
                "rate": 0.05
            ]),
            ([
                "type": "skill",
                "name": "acrobatics",
                "formula": "additive",
                "rate": 0.05
            ]),
            ([
                "type": "skill",
                "name": "anatomy and physiology",
                "formula": "additive",
                "rate": 0.05
            ]),
            ([
                "type":"attribute",
                "name": "strength",
                "formula": "additive",
                "rate": 0.05
            ]), 
            ([
                "type": "attribute",
                "name": "dexterity",
                "formula": "additive",
                "rate": 0.05
            ]),
            ([
                "type": "attribute",
                "name": "wisdom",
                "formula": "additive",
                "rate": 0.05
            ]),
        }));

        addSpecification("cooldown", 60);
        addSpecification("event handler", "godrebAiMegilEvent");
        addSpecification("command template", "godreb ai megil ##Combinations## [at ##Target##]");
        addSpecification("use ability message", "##InitiatorName## ##Infinitive::point## "
            "##InitiatorPossessive## ##InitiatorWeapon## at ##TargetName## ");

    }
}
