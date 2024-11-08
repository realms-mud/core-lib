//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";
#include "/lib/modules/secure/traits.h"

/////////////////////////////////////////////////////////////////////////////
private nomask object traitDictionary()
{
    return getDictionary("traits");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isTraitOf(string trait)
{
    return (traitDictionary()->validTrait(trait) &&
            member(traits, trait) && mappingp(traits[trait]));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasTraitOfRoot(string root)
{
    return (sizeof(filter(m_indices(traits),
        (: traitDictionary()->traitIsOfRoot($1, $2) :), root)));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidTrait(string trait)
{
    return traitDictionary()->validTrait(trait);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int traitHasResearchTree(string trait)
{
    int ret = 0;
    object traitObj = traitDictionary()->traitObject(trait);

    if(isTraitOf(trait) && traitObj && getDictionary("research") &&
        traitObj->query("research tree"))
    {
        object treeObj = 
            getDictionary("research")->researchTree(traitObj->query("research tree"));

        ret = treeObj->checkPrerequisites(this_object());
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int traitAffectedByType(string trait, string rootType)
{
    object traitObj = traitDictionary()->traitObject(trait);

    return isTraitOf(trait) && traitObj && getDictionary("research") &&
        traitObj->query("root") && traitObj->query("opposing root") &&
        (member(({ traitObj->query("root"), traitObj->query("opposing root") }),
            rootType) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string *Traits(string type)
{
    string *traitList = m_indices(traits);
    if (type)
    {
        traitList = filter(traitList,
            (: traitDictionary()->traitIsOfType($1, $2) :), type);
    }
    return m_indices(traits);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *TraitNames()
{
    string *names = ({});
    string *traitList = Traits();

    foreach(string trait in traitList)
    {
        names += ({ traits[trait]["name"] });
    }
    return names + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addTrait(string trait)
{
    int ret = 0;

    if(!isTraitOf(trait) && isValidTrait(trait))
    {
        traits[trait] = ([ ]);
        object materialAttributes = getService("materialAttributes");

        if(materialAttributes && objectp(materialAttributes))
        {
            traits[trait]["added"] = materialAttributes->Age();
        }
        object addedTrait = traitDictionary()->traitObject(trait);
        if(addedTrait && objectp(addedTrait))
        {
            traits[trait]["name"] = addedTrait->query("name");

            if(materialAttributes && addedTrait->query("duration"))
            {
                traits[trait]["end time"] = addedTrait->query("duration") + 
                    materialAttributes->Age();
                traits[trait]["expire message"] = addedTrait->query("expire message");
                temporaryTraits += ({ trait });
            }
            else if(addedTrait->query("triggering research"))
            {
                traits[trait]["triggering research"] = addedTrait->query("triggering research");
                traits[trait]["expire message"] = addedTrait->query("expire message");
                temporaryTraits += ({ trait });
            }
        }

        string *bonuses = traitDictionary()->getTraitBonuses(trait);
        if (bonuses && sizeof(bonuses))
        {
            traits[trait]["bonuses"] = bonuses;
        }

        object events = getService("events");
        if(events && objectp(events))
        {
            events->notify("onTraitAdded", trait);
        }

        object state = getService("state");
        if (state)
        {
            state->resetCaches();
        }
        ret = 1;
    }
    else if (isTraitOf(trait) && isValidTrait(trait))
    {
        object materialAttributes = getService("materialAttributes");
        object addedTrait = traitDictionary()->traitObject(trait);
        if (addedTrait && objectp(addedTrait))
        {
            if (materialAttributes && addedTrait->query("duration"))
            {
                traits[trait]["end time"] += addedTrait->query("duration");
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeTrait(string trait)
{
    int ret = 0;

    if(isTraitOf(trait) && isValidTrait(trait))
    {
        m_delete(traits, trait);

        if(member(temporaryTraits, trait) > -1)
        {
            temporaryTraits -= ({ trait });
        }

        object events = getService("events");
        if(events && objectp(events))
        {
            events->notify("onTraitRemoved", trait);
        }

        object state = getService("state");
        if (state)
        {
            state->resetCaches();
        }
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int canApplyLimitedTrait(string trait, string bonus)
{
    object traitObj = traitDictionary()->traitObject(trait);

    return isTraitOf(trait) && traitDictionary()->traitEffectIsLimited(trait) ?
        (traitObj->canApplySpecification(bonus, this_object(),
            function_exists("getTargetToAttack", this_object()) ?
            this_object()->getTargetToAttack() : 0)) : 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *traitsExtraAttacks()
{
    mapping *extraAttacks = ({ });
    string *traitItems = filter(m_indices(traits),
        (: (member(traits[$1], "bonuses") &&
           sizeof(regexp(traits[$1]["bonuses"], "bonus [^ ]+ attack"))) :));

    foreach(string trait in traitItems)
    {
        if(canApplyLimitedTrait(trait))
        {
            extraAttacks += traitDictionary()->extraAttacks(trait,
                this_object());
        }
    }
    
    // Strip out any potential null elements
    extraAttacks -= ({ 0 });
    
    return extraAttacks + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping traitsEnchantments()
{
    mapping enchantments = ([]);
    string *traitItems = filter(m_indices(traits),
        (: (member(traits[$1], "bonuses") &&
            !sizeof(regexp(traits[$1]["bonuses"], "crafting")) &&
            sizeof(regexp(traits[$1]["bonuses"],
                "bonus [^ ]+ enchantment$"))) :));

    foreach(string trait in traitItems)
    {
        if (canApplyLimitedTrait(trait))
        {
            mapping itemEnchantment = 
                traitDictionary()->enchantments(trait);

            string *keys = m_indices(itemEnchantment);
            if (sizeof(keys))
            {
                foreach(string key in keys)
                {
                    if (!member(enchantments, key))
                    {
                        enchantments[key] = itemEnchantment[key];
                    }
                    else
                    {
                        enchantments[key] += itemEnchantment[key];
                    }
                }
            }
        }
    }
    return enchantments + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitsAttributeBonus(string attribute)
{
    int ret = 0;
    if(attribute && stringp(attribute))
    {
        string *traitItems = filter(m_indices(traits),
            (: (member(traits[$1], "bonuses") &&
                sizeof(regexp(traits[$1]["bonuses"],
                "bonus " + $2))) :), attribute);

        foreach(string trait in traitItems)
        {
            if(canApplyLimitedTrait(trait, attribute))
            {
                string method = sprintf("%sBonus", capitalize(attribute));
                if(function_exists(method, traitDictionary()))
                {
                    ret += call_other(traitDictionary(), method, trait);
                }
            }
        }    
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitsBonusTo(string bonus)
{
    int ret = 0;
    
    if(function_exists(bonus, traitDictionary()))
    {
        string bonusString =
            getDictionary("bonuses")->getBonusFromFunction(bonus);

        string *traitItems = filter(m_indices(traits),
            (: (member(traits[$1], "bonuses") &&
                sizeof(regexp(traits[$1]["bonuses"], $2))) :), bonusString);

        foreach(string trait in traitItems)
        {
            if (canApplyLimitedTrait(trait, bonus))
            {
                ret += call_other(traitDictionary(), bonus, trait);            
            }
        }
    }
    else if(function_exists("BonusSkillModifier", traitDictionary()))
    {
        string *traitItems = filter(m_indices(traits),
            (: (member(traits[$1], "bonuses") &&
                sizeof(regexp(traits[$1]["bonuses"],
                "bonus " + $2))) :), bonus);

        foreach(string trait in traitItems)
        {
            if(canApplyLimitedTrait(trait, bonus))
            {
                ret += call_other(traitDictionary(), "BonusSkillModifier", 
                    trait, bonus);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *traitsResearchTrees()
{
    string *research = ({});
    string *traitsWithResearch = filter(m_indices(traits), #'traitHasResearchTree);
    
    foreach(string trait in traitsWithResearch)
    {
        object traitObj = traitDictionary()->traitObject(trait);

        if(traitObj)
        {
            research += ({ traitObj->query("research tree") });
        }
    }

    return research + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int opinionModifier(object target)
{
    int ret = 0;

    string *appliedModifiers = ({});
    if(target && objectp(target))
    {
        string *targetTraits = target->Traits();
        if(targetTraits && sizeof(targetTraits))
        {
            foreach(string targetTrait in targetTraits)
            {
                object targetTraitObj = traitDictionary()->traitObject(targetTrait);
                string targetRoot = targetTraitObj->query("root");
                string *affectingTraits = filter(m_indices(traits), 
                    #'traitAffectedByType, 
                    targetRoot);

                if(affectingTraits && sizeof(affectingTraits))
                {
                    foreach(string affectingTrait in affectingTraits)
                    {
                        object affectingObj = traitDictionary()->traitObject(affectingTrait);
                        
                        if(member(appliedModifiers, affectingTrait) == -1)
                        {
                            if(targetRoot == affectingObj->query("root"))
                            {
                                ret += affectingObj->query("opinion");
                            }
                            else if (targetRoot == affectingObj->query("opposing root"))
                            {
                                ret += affectingObj->query("opposing opinion");
                            }
                            appliedModifiers += ({ affectingTrait });
                        }
                    }
                }
                else if (targetTraitObj->query("opinion") &&
                    !targetTraitObj->query("opposing opinion"))
                {
                    ret += targetTraitObj->query("opinion");
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void removeTemporaryTrait(string trait)
{
    if (member(traits[trait], "expire message") && 
        stringp(traits[trait]["expire message"]))
    {
        tell_object(this_object(), traits[trait]["expire message"]);
    }
    removeTrait(trait);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void traitsHeartBeat()
{
    // Only increment the time spent / decrement usage counters
    // when not idle.
    if ((query_idle(this_object()) < 60) && sizeof(temporaryTraits))
    {
        foreach(string trait in temporaryTraits)
        {
            object materialAttributes = getService("materialAttributes");
            if(materialAttributes && member(traits, trait) &&
                member(traits[trait], "end time") &&
                (traits[trait]["end time"] <= materialAttributes->Age()))
            {
                removeTemporaryTrait(trait);
            }
            else if(member(traits, trait) &&
                member(traits[trait], "triggering research"))
            {
                object research = getService("research");
                if(research && !research->sustainedResearchIsActive(
                    traits[trait]["triggering research"]))
                {
                    removeTemporaryTrait(trait);
                }
            }
            else if (!member(traits, trait))
            {
                temporaryTraits -= ({ trait });
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getTraitColor(string trait)
{
    string ret = "field header";

    if (traitDictionary()->traitIsNegative(trait))
    {
        ret = "negative trait";
    }
    else if (traitDictionary()->traitIsOfType(trait, "personality"))
    {
        ret = "personality trait";
    }
    else if (traitDictionary()->isValidPersistedTrait(trait))
    {
        ret = "persisted trait";
    }
    else if(traitDictionary()->isValidSustainedTrait(trait))
    {
        ret = "sustained trait";
    }
    else if (traitDictionary()->traitHasResearchPath(trait))
    {
        ret = "has research";
    }
    else if (traitDictionary()->traitIsEnhancement(trait))
    {
        ret = "enhancement";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string traitListForType(string type, string colorConfiguration,
    string charset, object banner, object configuration)
{
    string ret = "";
    string traitFmt;

    int columns = 0;
    string *traitList = filter(m_indices(traits),
        (: traitDictionary()->traitIsOfType($1, $2) :), type);
    if (type == "effect")
    {
        traitList += filter(m_indices(traits),
            (: traitDictionary()->traitIsOfType($1, "sustained effect") :));
    }

    if (sizeof(traitList))
    {
        traitList = sort_array(traitList, (: $1 > $2 :));

        ret += banner->buildBanner(colorConfiguration, charset, "center", 
            type, "Traits");

        string traitRow = "";
        foreach(string trait in traitList)
        {
            string name = capitalize(traits[trait]["name"]);
            if (sizeof(name) > 23)
            {
                name = name[0..19] + "...";
            }

            traitRow += configuration->decorate(sprintf(" %23s ", name),
                getTraitColor(trait), "traits", colorConfiguration);

            if ((columns % 3) == 2)
            {
                ret += banner->banneredContent(colorConfiguration, charset,
                    traitRow);
                traitRow = "";
            }
            columns++;
        }
        if ((columns % 3))
        {
            for (int i = 0; i < (3 - columns % 3); i++)
            {
                traitRow += sprintf("%25s", "");
            }
            ret += banner->banneredContent(colorConfiguration, charset,
                traitRow);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string traitsList(string *types)
{
    string ret = "";
    if (!sizeof(types))
    {
        types = ({ "health", "educational", "personality", "genetic",
            "professional", "guild", "role", "effect",
            "sustained effect", "persona" });
    }

    object settings = getService("settings");
    string colorConfiguration = "none";
    string charset = "ascii";
    if (objectp(settings))
    {
        colorConfiguration = settings->colorConfiguration();
        charset = settings->charsetConfiguration();
    }

    object banner = getDictionary("commands");
    object configuration = getDictionary("configuration");

    types = sort_array(types, (: $1 > $2 :));
    foreach(string type in types)
    {
        ret += traitListForType(type, colorConfiguration, charset, banner,
            configuration);
    }
    if (ret == "")
    {
        ret = configuration->decorate("You currently do not have any tracked "
            "traits.\n", "field header", "traits", colorConfiguration);
    }
    else
    {
        ret += banner->buildBanner(colorConfiguration, charset, "bottom",
            "", "", 1); 
    }
    return "\n" + ret;
}
