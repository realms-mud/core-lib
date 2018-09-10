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
        "bonus heal spell points": 10,
        "defend attack": -3,
        "wisdom": -1,
        "dexterity": -1,
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
        "trait": "lib/modules/traits/biological/barbituates.c",
        "toxicity": 4,
    ]),
    "benzodiazepine": ([
    ]),
    "phenethylamine": ([
    ]),
    "xanthine": ([
    ]),
    "adrenaline": ([
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
private nomask int lookUpBonus(object livingToModify, string bonus)
{
    int ret = 0;
    //TODO Finish me
    return ret;
}
    
/////////////////////////////////////////////////////////////////////////////
public nomask int MaxHitPoints(object livingToModify)
{
    return lookUpBonus(livingToModify, "hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxSpellPoints(object livingToModify)
{
    return lookUpBonus(livingToModify, "spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxStaminaPoints(object livingToModify)
{
    return lookUpBonus(livingToModify, "stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefendAttackBonus(object livingToModify)
{
    return lookUpBonus(livingToModify, "defend attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int AttackBonus(object livingToModify)
{
    return lookUpBonus(livingToModify, "attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefenseBonus(object livingToModify)
{
    return lookUpBonus(livingToModify, "defense");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DamageBonus(object livingToModify)
{
    return lookUpBonus(livingToModify, "damage");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPoints(object livingToModify)
{
    return lookUpBonus(livingToModify, "bonus heal hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPoints(object livingToModify)
{
    return lookUpBonus(livingToModify, "bonus heal spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStamina(object livingToModify)
{
    return lookUpBonus(livingToModify, "bonus heal stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPointsRate(object livingToModify)
{
    return lookUpBonus(livingToModify, "bonus heal hit points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPointsRate(object livingToModify)
{
    return lookUpBonus(livingToModify, "bonus heal spell points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStaminaRate(object livingToModify)
{
    return lookUpBonus(livingToModify, "bonus heal stamina rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverSpellPoints(object livingToModify)
{
    return lookUpBonus(livingToModify, "recover spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceSpellPoints(object livingToModify)
{
    return lookUpBonus(livingToModify, "reduce spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverStaminaPoints(object livingToModify)
{
    return lookUpBonus(livingToModify, "recover stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceStaminaPoints(object livingToModify)
{
    return lookUpBonus(livingToModify, "reduce stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusSkillModifier(object livingToModify, string skill)
{
    return lookUpBonus(livingToModify, skill);
}
