//*****************************************************************************
// Class: researchDictionary
// File Name: researchDictionary.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string BaseResearch = "lib/modules/research/researchItem.c";
private string BaseResearchTree = "lib/modules/research/researchTree.c";
private mapping researchCache = ([]);
private mapping researchItemCache = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int valueIsCached(string research, string element, 
    string subElement)
{
    return member(researchCache, research) &&
        member(researchCache[research], element) &&
        (!subElement || member(researchCache[research][element], subElement));
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs void cacheValue(mixed value, string research, 
    string element, string subElement)
{
    if (!member(researchCache, research))
    {
        researchCache[research] = ([]);
    }

    if (!subElement)
    {
        researchCache[research][element] = value;
    }
    else
    {
        if (!member(researchCache[research], element))
        {
            researchCache[research][element] = ([]);
        }
        researchCache[research][element][subElement] = value;
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getResearchItem(string researchItem)
{
    object ret = 0;
    if (member(researchItemCache, researchItem) &&
        objectp(researchItemCache[researchItem]))
    {
        ret = researchItemCache[researchItem];
    }
    else
    {
        researchItemCache[researchItem] = load_object(researchItem);
        ret = researchItemCache[researchItem];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object researchObject(string researchItem)
{
    // The passed in value for researchItem must be a file containing a valid
    // researchItem object.
    object ret = 0;

    if (researchItem && stringp(researchItem) && researchItem[0] != '/')
    {
        researchItem = regreplace(researchItem, " ", "_", 1);
        researchItem = "/" + researchItem;
    }
    if(researchItem && stringp(researchItem) && (file_size(researchItem) > 0))
    { 
        ret = getResearchItem(researchItem);

        if(!ret || (member(inherit_list(ret), BaseResearch) < 0) ||
           !ret->isValidResearchItem())
        {
            ret = 0;
        }
        else
        {
            researchCache[researchItem] = ([]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object researchTree(string tree)
{
    // The passed in value for tree must be a file containing a valid
    // researchTree object.
    object ret = 0;

    if (tree && stringp(tree) && tree[0] != '/')
    {
    tree = regreplace(tree, " ", "_", 1);
        tree = "/" + tree;
    }

    if(tree && stringp(tree) && (file_size(tree) > 0))
    {
        ret = getResearchItem(tree);

        if(member(inherit_list(ret), BaseResearchTree) < 0)
        {
            ret = 0;
        }
        else
        {
            researchCache[tree] = ([]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validResearch(string researchItem)
{
    int ret = member(researchCache, researchItem);

    if (!ret)
    {
        object researchObj = researchObject(researchItem);
        ret = (researchObj && objectp(researchObj));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isSustainedResearchItem(string researchItem)
{
    int ret = 0;

    if (researchItem && stringp(researchItem))
    {
        if (valueIsCached(researchItem, "sustained research"))
        {
            ret = researchCache[researchItem]["sustained research"];
        }
        else
        {
            researchItem = (researchItem[0] == '/') ? researchItem :
                "/" + researchItem;
            ret = (file_size(researchItem) > 0) &&
                (member(inherit_list(getResearchItem(researchItem)),
                    "lib/modules/research/sustainedResearchItem.c") > -1);
            cacheValue(ret, researchItem, "sustained research");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isSustainedAbility(string researchItem)
{
    int ret = 0;

    if (valueIsCached(researchItem, "sustained ability"))
    {
        ret = researchCache[researchItem]["sustained ability"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = (researchObj->query("type") == "sustained") ||
                (researchObj->query("type") == "ritual");
            cacheValue(ret, researchItem, "sustained ability");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isActiveAbility(string researchItem)
{
    int ret = 0;

    if (valueIsCached(researchItem, "active ability"))
    {
        ret = researchCache[researchItem]["active ability"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = (researchObj->query("type") == "active");
            cacheValue(ret, researchItem, "active ability");
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isActiveOrSustainedAbility(string researchItem)
{
    int ret = 0;

    if (valueIsCached(researchItem, "active or sustained ability"))
    {
        ret = researchCache[researchItem]["active or sustained ability"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = (researchObj->query("type") == "active") ||
                (researchObj->query("type") == "ritual") ||
                (researchObj->query("type") == "sustained");

            cacheValue(ret, researchItem, "active or sustained ability");
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getResearchPrerequisites(string researchItem)
{
    mapping ret = 0;

    if (valueIsCached(researchItem, "prerequisites"))
    {
        ret = researchCache[researchItem]["prerequisites"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = researchObj->getPrerequisites();

            cacheValue(ret, researchItem, "prerequisites");
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int checkResearchPrerequisites(string researchItem, object owner)
{
    int ret = 0;
    object researchObj = researchObject(researchItem);
    if(researchObj)
    {
        ret = researchObj->checkPrerequisites(owner);
    }
    return ret;
}
    
/////////////////////////////////////////////////////////////////////////////
public nomask string getResearchType(string researchItem)
{
    string ret = 0;

    if (valueIsCached(researchItem, "research type"))
    {
        ret = researchCache[researchItem]["research type"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = researchObj->query("research type");

            cacheValue(ret, researchItem, "research type");
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getResearchCost(string researchItem)
{
    int ret = 0;
    if (valueIsCached(researchItem, "research cost"))
    {
        ret = researchCache[researchItem]["research cost"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = researchObj->query("research cost");

            cacheValue(ret, researchItem, "research cost");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int researchEffectIsLimited(string researchItem)
{
    int ret = 0;

    if (valueIsCached(researchItem, "effect is limited"))
    {
        ret = researchCache[researchItem]["effect is limited"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = researchObj->EffectIsLimited();

            cacheValue(ret, researchItem, "effect is limited");
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *extraAttacks(string researchItem, object owner)
{
    mapping *ret = 0;
   
    if (valueIsCached(researchItem, "extra attacks"))
    {
        ret = researchCache[researchItem]["extra attacks"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = function_exists("getExtraAttacks", researchObj) ?
                researchObj->getExtraAttacks() : ({});
            ret -= ({ 0 });

            cacheValue(ret, researchItem, "extra attacks");
        }
    }
    
    return ret + ({ });
}
                
/////////////////////////////////////////////////////////////////////////////
public nomask mapping enchantments(string researchItem)
{
    mapping ret = ([]);

    if (valueIsCached(researchItem, "enchantments"))
    {
        ret = researchCache[researchItem]["enchantments"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = researchObj->query("enchantments");

            cacheValue(ret, researchItem, "enchantments");
        }
    }

    return ret + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int researchCommand(string commandToExecute, string typedCommand,
    object initiator)
{
    int ret = 0;
    object researchObj = researchObject(commandToExecute);
    if(researchObj)
    {
        ret = researchObj->execute(typedCommand, initiator);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int applySustainedCostTo(string researchItem, string bonus)
{
    int ret = 0;
    
    if (valueIsCached(researchItem, "sustained cost", bonus))
    {
        ret = researchCache[researchItem]["sustained cost"][bonus];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = researchObj->applySustainedCost(bonus);

            cacheValue(ret, researchItem, "sustained cost", bonus);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int lookUpBonus(string researchItem, string bonus)
{
    int ret = 0;
   
    if (valueIsCached(researchItem, bonus))
    {
        ret = researchCache[researchItem][bonus];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = researchObj->queryBonus(bonus);

        }
        cacheValue(ret, researchItem, bonus);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int StrengthBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus strength");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int IntelligenceBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus intelligence");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DexterityBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus dexterity");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int WisdomBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus wisdom");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ConstitutionBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus constitution");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int CharismaBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus charisma");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxHitPoints(string researchItem)
{
    return lookUpBonus(researchItem, "bonus hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxSpellPoints(string researchItem)
{
    return lookUpBonus(researchItem, "bonus spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxStaminaPoints(string researchItem)
{
    return lookUpBonus(researchItem, "bonus stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefendAttackBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus defend attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int AttackBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefenseBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus defense");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DamageBonus(string researchItem)
{
    return lookUpBonus(researchItem, "bonus damage");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPoints(string researchItem)
{
    return lookUpBonus(researchItem, "bonus heal hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPoints(string researchItem)
{
    return lookUpBonus(researchItem, "bonus heal spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStamina(string researchItem)
{
    return lookUpBonus(researchItem, "bonus heal stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPointsRate(string researchItem)
{
    return lookUpBonus(researchItem, "bonus heal hit points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPointsRate(string researchItem)
{
    return lookUpBonus(researchItem, "bonus heal spell points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStaminaRate(string researchItem)
{
    return lookUpBonus(researchItem, "bonus heal stamina rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverSpellPoints(string researchItem)
{
    return lookUpBonus(researchItem, "bonus recover spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceSpellPoints(string researchItem)
{
    return lookUpBonus(researchItem, "bonus reduce spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverStaminaPoints(string researchItem)
{
    return lookUpBonus(researchItem, "bonus recover stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceStaminaPoints(string researchItem)
{
    return lookUpBonus(researchItem, "bonus reduce stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusSkillModifier(string researchItem, string skill)
{
    return lookUpBonus(researchItem, sprintf("bonus %s", skill));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int LimitedSkillModifier(string researchItem, string skill,
    object owner, object target)
{
    int ret = 0;
    object researchObj = researchObject(researchItem);
    if(researchObj && researchObj->canApplySpecification(skill, owner, target))
    {
        ret = lookUpBonus(researchItem, sprintf("bonus %s", skill));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getResearchSourcesForUser(object user)
{
    string *ret = ({});
    if (objectp(user))
    {
        string *researchList = user->completedResearch() +
            user->researchInProgress();
        if (sizeof(researchList))
        {
            foreach(string research in researchList)
            {
                object researchObj = researchObject(research);
                if (researchObj &&
                    (member(ret, researchObj->query("source")) < 0))
                {
                    ret += ({ researchObj->query("source") });
                }
            }
        }

        string *trees = user->availableResearchTrees();
        if (sizeof(trees))
        {
            foreach(string tree in trees)
            {
                object treeObj = researchTree(tree);
                if (treeObj &&
                    (member(ret, treeObj->Source()) < 0))
                {
                    ret += ({ treeObj->Source() });
                }
            }
        }
    }
    return ret - ({ 0 });
}

/////////////////////////////////////////////////////////////////////////////
private nomask string bonusName(string bonus)
{
    return capitalize(regreplace(bonus, "bonus (.+)", "\\1"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getResearchDetails(string research)
{
    string ret = "";
    object researchObj = researchObject(research);
    if (researchObj)
    {
        ret = researchObj->researchDetails();
        if (!ret)
        {
            ret = "Broken";
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getResearchTreeDetails(string research, object user)
{
    string ret = "";
    object researchObj = researchTree(research);
    if (researchObj)
    {
        ret = researchObj->researchTreeDetails(user);
        if (!ret)
        {
            ret = "Broken";
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayTreePrerequisites(string researchItem, object user)
{
    string ret = "";

    object researchObj = researchObject(researchItem);
    if (objectp(user) && objectp(researchObj))
    {
        string colorConfiguration = user->colorConfiguration();
        object configuration = getDictionary("configuration");

        string parentInfo = "";
        string *trees = user->availableResearchTrees();
        if (sizeof(trees))
        {
            string *parents = ({});
            foreach(string tree in trees)
            {
                object treeObj = researchTree(tree);
                if (objectp(treeObj))
                {
                    parents += treeObj->getParents(researchItem);
                }
            }
            if (sizeof(parents))
            {
                string *prerequisites = ({});
                foreach(string parent in parents)
                {
                    object research = researchObject(parent);
                    if (research)
                    {
                        prerequisites += ({ configuration->decorate(
                            capitalize(research->query("name")), 
                            (user->isResearched(parent) ? "known" : 
                                "missing prerequisites"), "research", 
                            colorConfiguration) });
                    }
                }
                parentInfo = implode(prerequisites, 
                    configuration->decorate(", ", "data", "selector",
                        colorConfiguration));
                parentInfo = regreplace(parentInfo, ", ([^,]+)$", " and \\1", 1);

                ret += configuration->decorate(sprintf("%-15s : %s\n",
                    "Research Prereqs", parentInfo), "description", "selector",
                    colorConfiguration);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping buildResearchList(string *researchList,
    int startIndex, object user, string type)
{
    int index = startIndex;
    mapping ret = ([]);

    researchList = filter(researchList,
        (: researchObject($1) && researchObject($1)->query("source") == $2 :),
        type);

    if (sizeof(researchList))
    {
        foreach(string research in researchList)
        {
            object researchObj = researchObject(research);
            if (objectp(researchObj))
            {
                string name = researchObj->query("name") || "UNDEFINED";
                if (sizeof(name) > 20)
                {
                    name = name[0..16] + "...";
                }
                ret[to_string(index)] = ([
                    "name":capitalize(name),
                    "type": research,
                    "do not format": 1,
                    "description": getResearchDetails(research) +
                        displayTreePrerequisites(research, user)
                ]);
            }
            index++;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getTreeMenuItem(object tree, int index)
{
    mapping ret = ([]);
    string name = tree->Name() || "UNDEFINED";
    if (sizeof(name) > 20)
    {
        name = name[0..16] + "...";
    }
    ret[to_string(index)] = ([
        "name":capitalize(name),
        "description": tree->Description(),
        "type": program_name(tree)
    ]);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping buildResearchTreeList(string *trees, 
    string type, object user, int startIndex, int hideTree)
{
    int index = startIndex;
    mapping ret = ([]);

    if (sizeof(trees))
    {
        foreach(string tree in trees)
        {
            object treeObj = researchTree(tree);

            if (!hideTree)
            {
                ret += getTreeMenuItem(treeObj, index);
                index++;
            }
            object *researchList = sort_array(
                m_indices(treeObj->getFlattenedResearchTree(user)),
                (: $1->query("name") > $2->query("name") :));

            if (sizeof(researchList))
            {
                string *researchItems = ({ });
                foreach(object research in researchList)
                {
                    if ((research->query("source") == type) &&
                        ((!user->isResearched(program_name(research)) &&
                        !user->isResearching(program_name(research))) ||
                            hideTree))
                    {
                        researchItems += ({ program_name(research) });
                    }
                }
                ret += buildResearchList(researchItems, index, user, type);
            }
            index = sizeof(ret) + startIndex + 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getResearchOfType(string type, object user, int showTreeElements)
{
    mapping ret = ([]);

    if (stringp(type) && objectp(user))
    {
        string *trees = filter(user->availableResearchTrees(),
            (: $1->Source() == $2 :), type);

        string *research = user->completedResearch() +
            user->researchInProgress();

        if (showTreeElements)
        {
            ret += buildResearchTreeList(
                filter(user->availableResearchTrees(),
                (: $1->Source() == $2 :), type),
                type, user, sizeof(ret) + 1);
        }
        else
        {
            int index = 1;
            foreach(string tree in trees)
            {
                object treeObj = researchTree(tree);
                if (treeObj)
                {
                    research = filter(research,
                        (: !$2->isMemberOfResearchTree($1) :), treeObj);
                }
                ret += getTreeMenuItem(treeObj, index);
                index++;
            }
        }
        ret += buildResearchList(sort_array(research, 
            (: $1 > $2 :)), sizeof(ret) + 1,
            user, type);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getResearchTreeChoices(string type, object user)
{
    mapping ret = ([]);

    if (stringp(type) && objectp(user))
    {
        object tree = researchTree(type);
        if (tree)
        {
            ret += buildResearchTreeList(({ type }), 
                tree->Source(), user, 1, 1);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getResearchBonuses(string researchItem)
{
    string *ret = ({});

    if (valueIsCached(researchItem, "raw bonuses"))
    {
        ret = researchCache[researchItem]["raw bonuses"];
    }
    else
    {
        object researchObj = researchObject(researchItem);
        if (researchObj)
        {
            ret = researchObj->query("raw bonuses");
        }

        cacheValue(ret, researchItem, "raw bonuses");
    }

    return ret + ({});
}
