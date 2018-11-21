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
    "background", "racial", "persona" });

private mapping traits = ([]);

private nosave string FieldDisplay = Cyan + ": " + Value + "\n";
private mapping traitCache = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int valueIsCached(string trait, string element,
    string subElement)
{
    return member(traitCache, trait) &&
        member(traitCache[trait], element) &&
        (!subElement || member(traitCache[trait][element], subElement));
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs void cacheValue(mixed value, string trait,
    string element, string subElement)
{
    if (!member(traitCache, trait))
    {
        traitCache[trait] = ([]);
    }

    if (!subElement)
    {
        traitCache[trait][element] = value;
    }
    else
    {
        if (!member(traitCache[trait], element))
        {
            traitCache[trait][element] = ([]);
        }
        traitCache[trait][element][subElement] = value;
    }
}

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
            traitCache[program_name(trait)] = ([]);
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
    int ret = 0;

    if (valueIsCached(trait, "type"))
    {
        ret = traitCache[trait]["type"] == type;
    }
    else
    {
        object traitObj = traitObject(trait);
        if (traitObj)
        {
            string traitType = traitObj->query("type");
            ret = traitType == type;
            cacheValue(traitType, trait, "type");
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitIsOfRoot(string trait, string root)
{
    int ret = 0;

    if (valueIsCached(trait, "root"))
    {
        ret = traitCache[trait]["root"] == root;
    }
    else
    {
        object traitObj = traitObject(trait);
        if (traitObj)
        {
            string traitRoot = traitObj->query("root");
            ret = traitRoot == root;
            cacheValue(traitRoot, trait, "root");
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitIsNegative(string trait)
{
    int ret = 0;

    if (valueIsCached(trait, "is negative"))
    {
        ret = traitCache[trait]["is negative"];
    }
    else
    {
        object traitObj = traitObject(trait);
        if (traitObj)
        {
            ret = !traitObj->query("enhanced") && traitObj->query("negative");
            cacheValue(ret, trait, "is negative");
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitHasResearchPath(string trait)
{
    int ret = 0;

    if (valueIsCached(trait, "has research path"))
    {
        ret = traitCache[trait]["has research path"];
    }
    else
    {
        object traitObj = traitObject(trait);
        ret = traitObj && traitObj->query("research tree");
        cacheValue(ret, trait, "has research path");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitIsEnhancement(string trait)
{
    int ret = 0;

    if (valueIsCached(trait, "is enhancement"))
    {
        ret = traitCache[trait]["is enhancement"];
    }
    else
    {
        object traitObj = traitObject(trait);
        ret = traitObj && traitObj->query("enhanced");
        cacheValue(ret, trait, "is enhancement");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validTrait(string trait)
{
    int ret = 0;

    if (valueIsCached(trait, "is valid"))
    {
        ret = traitCache[trait]["is valid"];
    }
    else
    {
        object traitObj = traitObject(trait);
        ret = traitObj && traitObj->isValidTrait();
        cacheValue(ret, trait, "is valid");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidPersistedTrait(string trait)
{
    int ret = 0;

    if (valueIsCached(trait, "is valid persisted"))
    {
        ret = traitCache[trait]["is valid persisted"];
    }
    else
    {
        object traitObj = traitObject(trait);
        ret = traitObj && (traitObj->query("type") == "effect");
        cacheValue(ret, trait, "is valid persisted");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidSustainedTrait(string trait)
{
    int ret = 0;

    if (valueIsCached(trait, "is valid sustained"))
    {
        ret = traitCache[trait]["is valid sustained"];
    }
    else
    {
        object traitObj = traitObject(trait);
        ret = traitObj && (traitObj->query("type") == "sustained effect");
        cacheValue(ret, trait, "is valid sustained");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitEffectIsLimited(string trait)
{
    int ret = 0;

    if (valueIsCached(trait, "is limited"))
    {
        ret = traitCache[trait]["is limited"];
    }
    else
    {
        object traitObj = traitObject(trait);
        ret = traitObj && traitObj->EffectIsLimited();
        cacheValue(ret, trait, "is limited");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *extraAttacks(string trait, object owner)
{
    mapping *ret = 0;
   
    if (valueIsCached(trait, "extra attacks"))
    {
        ret = traitCache[trait]["extra attacks"];
    }
    else
    {
        object traitObj = traitObject(trait);
        if (traitObj)
        {
            ret = function_exists("getExtraAttacks", traitObj) ?
                traitObj->getExtraAttacks() : ({});
            ret -= ({ 0 });

            cacheValue(ret, trait, "extra attacks");
        }
    }
    
    return ret + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping enchantments(string trait)
{
    mapping ret = ([]);

    if (valueIsCached(trait, "enchantments"))
    {
        ret = traitCache[trait]["enchantments"];
    }
    else
    {
        object traitObj = traitObject(trait);
        if (traitObj)
        {
            ret = traitObj->query("enchantments");

            cacheValue(ret, trait, "enchantments");
        }
    }

    return ret + ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int lookUpBonus(string trait, string bonus)
{
    int ret = 0;
    
    if (valueIsCached(trait, bonus))
    {
        ret = traitCache[trait][bonus];
    }
    else
    {
        object traitObj = traitObject(trait);
        if(traitObj && objectp(traitObj) && 
            function_exists("queryBonus", traitObj))
        {
            ret = traitObj->queryBonus(bonus);
        }

        cacheValue(ret, trait, bonus);
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
                ret += sprintf("\x1b[0;34;1mThis trait makes the %s research "
                    "tree available.\x1b[0m\n", tree->Name());
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
            ret += sprintf("\x1b[0;34;1m(+%d)\x1b[0m \x1b[0;33mBonus %s\x1b[0m\n",
                trait->query(bonus), bonusName(bonus));
        }
    }
    keys = trait->query("penalties");
    if (sizeof(keys))
    {
        foreach(string penalty in keys)
        {
            ret += sprintf("\x1b[0;31m(%d)\x1b[0m \x1b[0;33mPenalty to %s\x1b[0m\n",
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
            ((value > 0) ? "\x1b[0;34;1m+%d\x1b[0m\n" : "\x1b[0;31m%d\x1b[0m\n"),
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

        string colorConfiguration = this_player() ?
            this_player()->colorConfiguration() : "3-bit";
        object configuration =
            load_object("/lib/dictionaries/configurationDictionary.c");

        ret = sprintf(FieldDisplay, "Trait Name",
            capitalize(traitObj->query("name")) +
            (traitIsNegative(traitFile) ? "\x1b[0;31m [Negative]\x1b[0m" : "")) +
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
            traitObj->displayPrerequisites(colorConfiguration, configuration) +
            traitObj->displayLimiters(colorConfiguration, configuration);
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

    if (valueIsCached(trait, "raw bonuses"))
    {
        ret = traitCache[trait]["raw bonuses"];
    }
    else
    {
        object traitObj = traitObject(trait);
        if (traitObj)
        {
            ret = traitObj->query("raw bonuses");
            cacheValue(ret, trait, "raw bonuses");
        }
    }

    return ret + ({});
}
