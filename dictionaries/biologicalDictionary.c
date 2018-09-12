//*****************************************************************************
// Class: biologicalDictionary
// File Name: biologicalDictionary.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private mapping drugEffects = ([
    "alcohol":([
        "trait": "lib/modules/traits/biological/drunk.c",
        "toxicity": 3,
    ]),
    "opiate": ([
        "trait": "lib/modules/traits/biological/wasted-on-opiates.c",
        "toxicity": 10,
    ]),
    "salicylate": ([
        "trait": "lib/modules/traits/biological/salicylate.c",
        "toxicity": 1,
    ]),
    "psychedelic": ([
        "trait": "lib/modules/traits/biological/stoned.c",
        "toxicity": 4,
    ]),
    "dissociative": ([
        "trait": "lib/modules/traits/biological/hallucinating.c",
        "toxicity": 5,
    ]),
    "dileriant": ([
        "trait": "lib/modules/traits/biological/drug-dilerious.c",
        "toxicity": 5,
    ]),
    "steroid": ([
        "trait": "lib/modules/traits/biological/steroids.c",
        "toxicity": 4,
    ]),
    "barbituate": ([
        "trait": "lib/modules/traits/biological/impaired-barbituates.c",
        "toxicity": 5,
    ]),
    "benzodiazepine": ([
        "trait": "lib/modules/traits/biological/on-benzodiazepine.c",
        "toxicity": 3,
    ]),
    "antidepressant": ([
        "trait": "lib/modules/traits/biological/antidepressant.c",
        "toxicity": 4,
    ]),
    "xanthine": ([
        "trait": "lib/modules/traits/biological/caffeinated.c",
        "toxicity": 1,
    ]),
    "adrenaline": ([
        "trait": "lib/modules/traits/biological/adrenaline.c",
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
            livingToModify->addToxicity(drugEffects[type]["toxicity"]);
            livingToModify->addTrait(drugEffects[type]["trait"]);
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
