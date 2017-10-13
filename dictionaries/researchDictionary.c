//*****************************************************************************
// Class: researchDictionary
// File Name: researchDictionary.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string BaseResearch = "lib/modules/research/researchItem.c";
private string BaseResearchTree = "lib/modules/research/researchTree.c";
private string ResearchType;

/////////////////////////////////////////////////////////////////////////////
public nomask object researchObject(string researchItem)
{
    // The passed in value for researchItem must be a file containing a valid
    // researchItem object.
    object ret = 0;

    if (researchItem && stringp(researchItem) && researchItem[0] != '/')
    {
        researchItem = "/" + researchItem;
    }
    if(researchItem && stringp(researchItem) && (file_size(researchItem) > 0))
    { 
        ret = load_object(researchItem);

        if(!ret || (member(inherit_list(ret), BaseResearch) < 0) ||
           !ret->isValidResearchItem())
        {
            ret = 0;
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
        tree = "/" + tree;
    }

    if(tree && stringp(tree) && (file_size(tree) > 0))
    {
        ret = load_object(tree);

        if(member(inherit_list(ret), BaseResearchTree) < 0)
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validResearch(string researchItem)
{
    object researchObj = researchObject(researchItem);
    return (researchObj && objectp(researchObj));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isSustainedResearchItem(string researchItem)
{
    int ret = 0;

    if(researchItem && stringp(researchItem))
    {
        researchItem = (researchItem[0] == '/') ? researchItem : 
            "/" + researchItem;
        ret = (file_size(researchItem) > 0) && 
        (member(inherit_list(load_object(researchItem)), 
            "lib/modules/research/sustainedResearchItem.c") > -1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isSustainedAbility(string researchItem)
{
    int ret = 0;
    object researchObj = researchObject(researchItem);
    if(researchObj)
    {
        ret = (researchObj->query("type") == "sustained") ||
              (researchObj->query("type") == "ritual");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isActiveAbility(string researchItem)
{
    int ret = 0;
    object researchObj = researchObject(researchItem);
    if(researchObj)
    {
        ret = (researchObj->query("type") == "active");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isActiveOrSustainedAbility(string researchItem)
{
    int ret = 0;
    object researchObj = researchObject(researchItem);
    if(researchObj)
    {
        ret = (researchObj->query("type") == "active") ||
              (researchObj->query("type") == "ritual") ||
              (researchObj->query("type") == "sustained");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getResearchPrerequisites(string researchItem)
{
    mapping ret = 0;
    object researchObj = researchObject(researchItem);
    if(researchObj)
    {
        ret = researchObj->getPrerequisites();
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
    object researchObj = researchObject(researchItem);
    if(researchObj)
    {
        ret = researchObj->query("research type");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getResearchCost(string researchItem)
{
    int ret = 0;
    object researchObj = researchObject(researchItem);
    if(researchObj)
    {
        ret = researchObj->query("research cost");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int researchEffectIsLimited(string researchItem)
{
    int ret = 0;
    object researchObj = researchObject(researchItem);
    if(researchObj)
    {
        ret = researchObj->EffectIsLimited();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *extraAttacks(string researchItem, object owner)
{
    mapping *ret = 0;
    
    object researchObj = researchObject(researchItem);
    if(researchObj && objectp(researchObj) &&
       function_exists("getExtraAttacks", researchObj))
    {
        ret = researchObj->getExtraAttacks();
    }
    ret -= ({ 0 });
    
    return ret + ({ });
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
    
    object researchObj = researchObject(researchItem);
    if(researchObj && objectp(researchObj) && 
       function_exists("applySustainedCost", researchObj))
    {
        ret = researchObj->applySustainedCost(bonus);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int lookUpBonus(string researchItem, string bonus)
{
    int ret = 0;
    
    object researchObj = researchObject(researchItem);
    if(researchObj && objectp(researchObj) && 
       function_exists("queryBonus", researchObj))
    {
        ret = researchObj->queryBonus(bonus);
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
    if(researchObj && researchObj->canApplySkill(skill, owner, target))
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
public nomask string getResearchDetails(string research)
{
    string ret = "";
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping buildResearchList(string *researchList,
    int startIndex)
{
    int index = startIndex;
    mapping ret = ([]);

    researchList = filter_array(researchList,
        (: researchObject($1)->query("source") == ResearchType :));

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
                    "name": capitalize(name),
                    "type": research,
                    "description": getResearchDetails(research)
                ]);
            }
            index++;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping buildResearchTreeList(object user,
    int startIndex)
{
    int index = startIndex;
    mapping ret = ([]);

    string *trees = filter_array(user->availableResearchTrees(),
        (: $1->Source() == ResearchType :));

    if (sizeof(trees))
    {
        foreach(string tree in trees)
        {
            object treeObj = researchTree(tree);
            string name = treeObj->Name() || "UNDEFINED";
            if (sizeof(name) > 20)
            {
                name = name[0..16] + "...";
            }
            ret[to_string(index)] = ([
                "name": capitalize(name),
                "description": treeObj->Description(),
                "type": tree
            ]);
            index++;

            object *researchList = sort_array(
                m_indices(treeObj->getFlattenedResearchTree(user)),
                (: $1->query("name") > $2->query("name") :));

            if (sizeof(researchList))
            {
                string *researchItems = ({ });
                foreach(object research in researchList)
                {
                    if ((research->query("source") == ResearchType) &&
                        !user->isResearched(program_name(research)) &&
                        !user->isResearching(program_name(research)))
                    {
                        researchItems += ({ program_name(research) });
                    }
                }
                ret += buildResearchList(researchItems, index);
            }
            index = sizeof(ret) + startIndex + 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getResearchOfType(string type, object user)
{
    mapping ret = ([]);

    if (stringp(type) && objectp(user))
    {
        ResearchType = type;

        ret = buildResearchList(user->completedResearch() +
            user->researchInProgress(), sizeof(ret) + 1);

        ret += buildResearchTreeList(user, sizeof(ret) + 1);
    }
    return ret;
}

