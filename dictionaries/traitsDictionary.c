//*****************************************************************************
// Class: traitsDictionary
// File Name: traitsDictionary.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private string BaseTrait = "lib/modules/traits/baseTrait.c";
private string *validTraitTypes = ({ "health", "educational", "personality", 
    "genetic", "professional", "guild", "role", "effect", "sustained effect" });

private mapping traits = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask object traitObject(string trait)
{
    // The passed in value for trait must be a file containing a valid
    // trait object.
    object ret = 0;

    if (trait && stringp(trait) && trait[0] != '/')
    {
        trait = "/" + trait;
    }

    if(trait && stringp(trait) && (file_size(trait) > 0))
    { 
        ret = load_object(trait);
        if(ret && !ret->query("type"))
        {
            ret->init();
        }

        if(!ret || (member(inherit_list(ret), BaseTrait) < 0) ||
           !ret->isValidTrait())
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidTraitType(string type)
{
    return (member(validTraitTypes, type) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitIsOfType(string trait, string type)
{
    object traitObj = traitObject(trait);
    return (traitObj && objectp(traitObj) && (traitObj->query("type") == type));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitIsNegative(string trait)
{
    object traitObj = traitObject(trait);
    return (traitObj && objectp(traitObj) && traitObj->query("negative"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitHasResearchPath(string trait)
{
    object traitObj = traitObject(trait);
    return (traitObj && objectp(traitObj) && traitObj->query("research tree"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitIsEnhancement(string trait)
{
    object traitObj = traitObject(trait);
    return (traitObj && objectp(traitObj) && traitObj->query("enhanced"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validTrait(string trait)
{
    object traitObj = traitObject(trait);
    return (traitObj && objectp(traitObj) && traitObj->isValidTrait());
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidPersistedTrait(string trait)
{
    object traitObj = traitObject(trait);
    return (traitObj && objectp(traitObj) &&
        (traitObj->query("type") == "effect"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidSustainedTrait(string trait)
{
    object traitObj = traitObject(trait);
    return (traitObj && objectp(traitObj) &&
        (traitObj->query("type") == "sustained effect"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitEffectIsLimited(string trait)
{
    int ret = 0;
    object traitObj = traitObject(trait);
    if(traitObj)
    {
        ret = traitObj->EffectIsLimited();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping characterCreationTraits()
{
    // TODO [233]
    return ([ ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *extraAttacks(string trait, object owner)
{
    mapping *ret = 0;
    
    object traitObj = traitObject(trait);
    if(traitObj && objectp(traitObj) &&
       function_exists("getExtraAttacks", traitObj))
    {
        ret = traitObj->getExtraAttacks();
    }
    ret -= ({ 0 });
    
    return ret + ({ });
}

/////////////////////////////////////////////////////////////////////////////
private nomask int lookUpBonus(string trait, string bonus)
{
    int ret = 0;
    
    object traitObj = traitObject(trait);
    if(traitObj && objectp(traitObj) && 
       function_exists("queryBonus", traitObj))
    {
        ret = traitObj->queryBonus(bonus);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int StrengthBonus(string trait)
{
    return lookUpBonus(trait, "bonus strength");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int IntelligenceBonus(string trait)
{
    return lookUpBonus(trait, "bonus intelligence");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DexterityBonus(string trait)
{
    return lookUpBonus(trait, "bonus dexterity");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int WisdomBonus(string trait)
{
    return lookUpBonus(trait, "bonus wisdom");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ConstitutionBonus(string trait)
{
    return lookUpBonus(trait, "bonus constitution");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int CharismaBonus(string trait)
{
    return lookUpBonus(trait, "bonus charisma");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxHitPoints(string trait)
{
    return lookUpBonus(trait, "bonus hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxSpellPoints(string trait)
{
    return lookUpBonus(trait, "bonus spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxStaminaPoints(string trait)
{
    return lookUpBonus(trait, "bonus stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefendAttackBonus(string trait)
{
    return lookUpBonus(trait, "bonus defend attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int AttackBonus(string trait)
{
    return lookUpBonus(trait, "bonus attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefenseBonus(string trait)
{
    return lookUpBonus(trait, "bonus defense");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DamageBonus(string trait)
{
    return lookUpBonus(trait, "bonus damage");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPoints(string trait)
{
    return lookUpBonus(trait, "bonus heal hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPoints(string trait)
{
    return lookUpBonus(trait, "bonus heal spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStamina(string trait)
{
    return lookUpBonus(trait, "bonus heal stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPointsRate(string trait)
{
    return lookUpBonus(trait, "bonus heal hit points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPointsRate(string trait)
{
    return lookUpBonus(trait, "bonus heal spell points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStaminaRate(string trait)
{
    return lookUpBonus(trait, "bonus heal stamina rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverSpellPoints(string trait)
{
    return lookUpBonus(trait, "bonus recover spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceSpellPoints(string trait)
{
    return lookUpBonus(trait, "bonus reduce spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverStaminaPoints(string trait)
{
    return lookUpBonus(trait, "bonus recover stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceStaminaPoints(string trait)
{
    return lookUpBonus(trait, "bonus reduce stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusSkillModifier(string trait, string skill)
{
    return lookUpBonus(trait, sprintf("bonus %s", skill));
}

