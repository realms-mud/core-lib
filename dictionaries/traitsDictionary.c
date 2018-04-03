//*****************************************************************************
// Class: traitsDictionary
// File Name: traitsDictionary.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

private string BaseTrait = "lib/modules/traits/baseTrait.c";
private string *validTraitTypes = ({ "health", "educational", "personality", 
    "genetic", "professional", "guild", "role", "effect", "sustained effect",
    "background", "racial" });

private mapping traits = ([]);

private nosave string FieldDisplay = Cyan + ": " + Value + "\n";

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

        if(!ret || (member(inherit_list(ret), BaseTrait) < 0) ||
           !ret->isValidTrait())
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitIsRegistered(string trait)
{
    return member(traits, trait) || 
        (member(m_values(traits), trait) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int registerTrait(object trait)
{
    int ret = 0;

    string location = program_name(trait);
    if (location && stringp(location) && sizeof(location) &&
        (location[0] != '/'))
    {
        location = "/" + location;
    }

    if ((file_size(location) > 0) && !traitIsRegistered(program_name(trait)))
    {
        trait = load_object(location);

        if (trait && objectp(trait) &&
            (member(inherit_list(trait), BaseTrait) > -1) &&
            trait->isValidTrait())
        {
            ret = 1;
            traits[lower_case(trait->query("name"))] = program_name(trait);
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
public nomask int traitIsOfRoot(string trait, string root)
{
    object traitObj = traitObject(trait);
    return (traitObj && objectp(traitObj) && (traitObj->query("root") == root));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitIsNegative(string trait)
{
    object traitObj = traitObject(trait);
    return (traitObj && objectp(traitObj) && !traitObj->query("enhanced") &&
        traitObj->query("negative"));
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

/////////////////////////////////////////////////////////////////////////////
private nomask string bonusName(string bonus)
{
    return capitalize(regreplace(bonus, "bonus (.+)", "\\1"));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayResearchTree(object trait)
{
    string ret = "";

    string tree = trait->query("research tree");
    if (tree)
    {
        object researchDictionary =
            load_object("/lib/dictionaries/researchDictionary.c");

        if (researchDictionary)
        {
            object treeObj = researchDictionary->researchTree(tree);
            if (tree)
            {
                ret += sprintf("[0;34;1mThis trait makes the %s research "
                    "tree available.[0m\n", tree->Name());
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayTraitBonusesAndPenalties(object trait)
{
    string ret = "";
    string *keys = trait->query("bonuses");
    if (sizeof(keys))
    {
        foreach(string bonus in keys)
        {
            ret += sprintf("[0;34;1m(+%d)[0m [0;33mBonus %s[0m\n",
                trait->query(bonus), bonusName(bonus));
        }
    }
    keys = trait->query("penalties");
    if (sizeof(keys))
    {
        foreach(string penalty in keys)
        {
            ret += sprintf("[0;31m(%d)[0m [0;33mPenalty to %s[0m\n",
                trait->query(penalty), bonusName(penalty));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayTraitComponent(object trait, string component)
{
    string ret = "";
    int value = trait->query(component);
    if (value)
    {
        ret = sprintf(Cyan + ": " +
            ((value > 0) ? "[0;34;1m+%d[0m\n" : "[0;31m%d[0m\n"),
            capitalize(component), value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string traitDetailsFromFile(string traitFile)
{
    string ret = "";
    if (traitFile && validTrait(traitFile))
    {
        object traitObj = traitObject(traitFile);

        ret = sprintf(FieldDisplay, "Trait Name",
            capitalize(traitObj->query("name")) +
            (traitIsNegative(traitFile) ? "[0;31m [Negative][0m" : "")) +
            sprintf(FieldDisplay, "Trait Type", capitalize(traitObj->query("type"))) +
            format(sprintf(Value, traitObj->query("description")), 78) + "\n" +
            sprintf(FieldDisplay, "Root Trait Class", capitalize(traitObj->query("root"))) +
            (traitObj->query("opposing root") ? sprintf(FieldDisplay, "Opposing Trait Class", 
                capitalize(traitObj->query("opposing root"))) : "") +
            displayTraitComponent(traitObj, "opinion") +
            displayTraitComponent(traitObj, "opposing opinion") +
            displayTraitComponent(traitObj, "cost") +
            displayTraitBonusesAndPenalties(traitObj) +
            displayResearchTree(traitObj) +
            traitObj->displayPrerequisites() +
            traitObj->displayLimiters();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string traitDetails(string trait)
{
    trait = lower_case(trait);
    string ret = sprintf("%s is not a valid trait.\n", capitalize(trait));

    string traitFile = traitIsRegistered(trait) ? traits[trait] : 0;
    if (traitFile)
    {
        ret = traitDetailsFromFile(traitFile);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping creationListForTraitType(string type)
{
    mapping ret = ([]);

    if ((member(validTraitTypes, type) > -1) || (type == "sexuality"))
    {
        string *traitList = get_dir(
            sprintf("/lib/modules/traits/%s/*.c", type), 0x10);

        if (sizeof(traitList))
        {
            int i = 1;
            foreach(string trait in traitList)
            {
                object traitObj = traitObject(trait);

                ret[to_string(i)] = ([
                    "name": capitalize(traitObj->query("name")),
                    "description": traitDetailsFromFile(trait),
                    "file": trait
                ]);
                i++;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getTraitBonuses(string trait)
{
    string *ret = ({});
    object traitObj = traitObject(trait);
    if (traitObj)
    {
        ret = traitObj->query("raw bonuses");
    }
    return ret + ({});
}
