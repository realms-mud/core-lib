//*****************************************************************************
// Class: biologicalDictionary
// File Name: biologicalDictionary.c
//
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "materials/potions.h"
#include "materials/drinks.h"
#include "materials/food.h"

/////////////////////////////////////////////////////////////////////////////
private mapping drugEffects = ([
    "alcohol":([
        "trait": "lib/instances/traits/biological/drunk.c",
        "toxicity": 3,
    ]),
    "opiate": ([
        "trait": "lib/instances/traits/biological/wasted-on-opiates.c",
        "toxicity": 10,
    ]),
    "salicylate": ([
        "trait": "lib/instances/traits/biological/salicylate.c",
        "toxicity": 1,
    ]),
    "psychedelic": ([
        "trait": "lib/instances/traits/biological/stoned.c",
        "toxicity": 4,
    ]),
    "dissociative": ([
        "trait": "lib/instances/traits/biological/hallucinating.c",
        "toxicity": 5,
    ]),
    "dileriant": ([
        "trait": "lib/instances/traits/biological/drug-dilerious.c",
        "toxicity": 5,
    ]),
    "steroid": ([
        "trait": "lib/instances/traits/biological/steroids.c",
        "toxicity": 4,
    ]),
    "barbituate": ([
        "trait": "lib/instances/traits/biological/impaired-barbituates.c",
        "toxicity": 5,
    ]),
    "benzodiazepine": ([
        "trait": "lib/instances/traits/biological/on-benzodiazepine.c",
        "toxicity": 3,
    ]),
    "antidepressant": ([
        "trait": "lib/instances/traits/biological/antidepressant.c",
        "toxicity": 4,
    ]),
    "xanthine": ([
        "trait": "lib/instances/traits/biological/caffeinated.c",
        "toxicity": 1,
    ]),
    "adrenaline": ([
        "trait": "lib/instances/traits/biological/adrenaline.c",
        "toxicity": 1,
    ]),
    "sympathomimetic amine": ([
    ]),
    "euphoriant": ([
    ]),
    "empathogen": ([
    ]),
    "neurotoxin": ([
    ]),
    "cycloalkylamine": ([
    ]),
    "neuroleptic": ([
    ]),
    "nootropic": ([
    ]),
    "analeptic": ([
    ]),
    "magical": ([
    ]),
]);

/////////////////////////////////////////////////////////////////////////////
public nomask int applyBiologicalEffect(object livingToModify, object item)
{
    int ret = 0;
    if (objectp(livingToModify) && objectp(item))
    {
        string *typeOfItem = filter(inherit_list(item),
            (: (member(({ "lib/items/drink.c", "lib/items/food.c",
                "lib/items/potion.c" }), $1) > -1) :));

        string type = item->query("biological effect");
        if (sizeof(typeOfItem) && member(drugEffects, type))
        {
            ret = 1;
            if (member(drugEffects[type], "toxicity"))
            {
                livingToModify->addToxicity(drugEffects[type]["toxicity"]);
            }
            if (member(drugEffects[type], "trait"))
            {
                livingToModify->addTrait(drugEffects[type]["trait"]);
            }
        }
    }
    return ret;
}
    
/////////////////////////////////////////////////////////////////////////////
public nomask int removeBiologicalEffect(object livingToModify, string effect)
{
    int ret = 0;
    if (objectp(livingToModify) && stringp(effect))
    {
        if (member(drugEffects, effect))
        {
            livingToModify->addToxicity(0 - drugEffects[effect]["toxicity"]);
            livingToModify->removeTrait(drugEffects[effect]["trait"]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyPotionEffects(object actor, mapping effects)
{
    int ret = 0;
    if (sizeof(effects))
    {
        ret = 1;
        foreach(string key in m_indices(effects))
        {
            switch (key)
            {
                case "increase hit points":
                {
                    ret &&= actor->hitPoints(effects["increase hit points"]);
                    break;
                }
                case "increase spell points":
                {
                    ret &&= actor->spellPoints(effects["increase spell points"]);
                    break;
                }
                case "increase stamina points":
                {
                    ret &&= actor->staminaPoints(effects["increase stamina points"]);
                    break;
                }
                case "apply trait":
                {
                    ret &&= actor->addTrait(effects["apply trait"]);
                    break;
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int consumeItem(object actor, object item)
{
    int ret = 0;
    string blueprint = item->query("blueprint");

    mapping effects = 0;
    if ((item->query("type") == "potion") && member(potions, blueprint))
    {
        effects = potions[blueprint]["effects"];

        ret = applyPotionEffects(actor, effects);
    }

    if (ret || !sizeof(effects))
    {
        ret = applyBiologicalEffect(actor, item);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBiologicalEffect(object item)
{
    string ret = 0;

    string blueprint = item->query("blueprint");
    if ((item->query("type") == "potion") &&  member(potions, blueprint))
    {
        mapping effects = potions[blueprint]["effects"];

        if (member(effects, "biological"))
        {
            ret = effects["biological"];
        }
    }
    return ret;
}
