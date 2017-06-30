//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
public nomask string *Traits()
{
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

        object events = getService("events");
        if(events && objectp(events))
        {
            events->notify("onTraitAdded", trait);
        }
        ret = 1;
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
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int canApplyLimitedTrait(string trait, string bonus)
{
    object traitObj = traitDictionary()->traitObject(trait);

    return isTraitOf(trait) && traitDictionary()->traitEffectIsLimited(trait) ?
        (traitObj->canApplySkill(bonus, this_object(),
            function_exists("getTargetToAttack", this_object()) ?
            this_object()->getTargetToAttack() : 0)) : 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *traitsExtraAttacks()
{
    mapping *extraAttacks = ({ });
    string *traitItems = m_indices(traits);
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
public nomask int traitsAttributeBonus(string attribute)
{
    int ret = 0;
   
    if(attribute && stringp(attribute))
    {
        string *traitItems = m_indices(traits);
        foreach(string trait in traitItems)
        {
            if(canApplyLimitedTrait(trait, attribute))
            {
                string method = sprintf("%sBonus", capitalize(attribute));
                if(function_exists(method, traitDictionary()))
                {
                    ret = call_other(traitDictionary(), method, trait);
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
        string *traitItems = m_indices(traits);
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
        string *traitItems = m_indices(traits);
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
    string *traitsWithResearch = filter_array(m_indices(traits), #'traitHasResearchTree);
    
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
                string *affectingTraits = filter_array(m_indices(traits), 
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
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void removeTemporaryTrait(string trait)
{
    if (member(traits[trait], "expire message"))
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
            if(materialAttributes && member(traits[trait], "end time") &&
                (traits[trait]["end time"] <= materialAttributes->Age()))
            {
                removeTemporaryTrait(trait);
            }
            else if(member(traits[trait], "triggering research"))
            {
                object research = getService("research");
                if(research && !research->sustainedResearchIsActive(
                    traits[trait]["triggering research"]))
                {
                    removeTemporaryTrait(trait);
                }
            }
        }
    }
}