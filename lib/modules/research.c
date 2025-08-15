//*****************************************************************************
// Class: research
// File Name: research.c
//
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/research.h"

/////////////////////////////////////////////////////////////////////////////
private nomask object researchService()
{
    return getService("research");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int equivalentIsResearched(string researchItem)
{
    return researchService()->equivalentIsResearched(research, researchItem);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isResearched(string researchItem)
{
    return (researchService()->validResearch(researchItem) &&
            member(research, researchItem) && mappingp(research[researchItem])       
            && member(research[researchItem], "research complete") &&
            research[researchItem]["research complete"]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isResearching(string researchItem)
{
    string *listOfTimedResearch = m_indices(research) -
        filter(m_indices(research), #'isResearched);

    return (member(listOfTimedResearch, researchItem) > -1) ?
            research[researchItem]["time spent learning"] + 1 : 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isActiveOrSustainedResearchAbility(string researchItem)
{
    int ret = 0;
    if(researchItem && stringp(researchItem) && isResearched(researchItem))
    {
        ret = researchService()->isActiveOrSustainedAbility(researchItem);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int canApplyLimitedEffect(string researchItem, string bonus)
{
    object researchObj = researchService()->researchObject(researchItem);

    object target = this_object()->itemBeingCrafted() ?
        this_object()->itemBeingCrafted() :
        this_object()->getTargetToAttack();

    return isResearched(researchItem) && 
        (researchService()->researchEffectIsLimited(researchItem) ?
        (researchObj->canApplySpecification(bonus, this_object(), target,
        isActiveOrSustainedResearchAbility(researchItem))) : 1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int canApplyResearchBonus(string researchItem, string bonus)
{
    int ret = canApplyLimitedEffect(researchItem, bonus);

    if(ret && isActiveOrSustainedResearchAbility(researchItem))
    {
        ret &&= ((member(research[researchItem], "sustained active") &&
            research[researchItem]["sustained active"]) ||
            (member(research[researchItem], "active count") &&
            (research[researchItem]["active count"] > 0)));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int sustainedResearchIsActive(string researchItem)
{
    return (researchService()->isSustainedAbility(researchItem) &&
        member(research, researchItem) &&
        member(research[researchItem], "sustained active") &&
        research[researchItem]["sustained active"]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int blockedByCooldown(string researchItem)
{
    return member(research, researchItem) && 
        member(research[researchItem], "cooldown") &&
        research[researchItem]["cooldown"] > 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int activateSustainedResearch(object researchObj,
    object modifierObject)
{
    int ret = 0;
    object inventory = getModule("inventory");
    string researchItem = objectp(researchObj) ? program_name(researchObj) : "???";

    if(inventory && !blockedByCooldown(researchItem) &&
       (!modifierObject || inventory->isModifierItem(modifierObject)) &&
        researchService()->isSustainedAbility(researchItem) &&
       (!member(research[researchItem], "sustained active") ||
       (research[researchItem]["sustained active"] == 0))
       && canApplyLimitedEffect(researchItem) &&
       !getModule("combat")->spellAction())
    {
        getModule("combat")->spellAction(1);
        research[researchItem]["sustained active"] = 1;
        ret = 1;
        
        if(member(research[researchItem], "active modifier object") &&
           research[researchItem]["active modifier object"] &&
           objectp(inventory->registeredInventoryObject(
               research[researchItem]["active modifier object"])))
        {
            object modifierToDestroy = 
                inventory->registeredInventoryObject(
                    research[researchItem]["active modifier object"]);
            m_delete(research[researchItem], "active modifier object");
            modifierToDestroy->unregisterModifierFromTargetList();
            destruct(modifierToDestroy);
        }
        if (modifierObject)
        {
            research[researchItem]["active modifier object"] = 
                modifierObject->query("fully qualified name");
        }

        object state = getModule("state");
        if (state)
        {
            state->resetCaches();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int deactivateSustainedResearch(string researchItem)
{
    int ret = 0;
    if(researchService()->isSustainedAbility(researchItem) &&
       member(research[researchItem], "sustained active") &&
       research[researchItem]["sustained active"])
    {
        m_delete(research[researchItem], "sustained active");
        ret = 1;
        
        object inventory = getModule("inventory");
        if(member(research[researchItem], "active modifier object") &&
           research[researchItem]["active modifier object"] &&
            inventory && objectp(inventory->registeredInventoryObject(
                research[researchItem]["active modifier object"])))
        {
            object modifierToDestroy =
                inventory->registeredInventoryObject(
                    research[researchItem]["active modifier object"]);

            m_delete(research[researchItem], "active modifier object");
            modifierToDestroy->unregisterModifierFromTargetList();
            destruct(modifierToDestroy);        
        }

        object researchObj = researchService()->researchObject(researchItem);
        if(researchObj)
        {
            int cooldown = researchObj->cooldown(this_object());
            if (cooldown)
            {
                research[researchItem]["cooldown"] = cooldown;
            }
        }

        object state = getModule("state");
        if (state)
        {
            state->resetCaches();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *activeAndSustainedResearchAbilities()
{
    return filter(m_indices(research), 
        #'isActiveOrSustainedResearchAbility);
}        

/////////////////////////////////////////////////////////////////////////////
public nomask int addResearchPoints(int amount)
{
    int ret = 0;
    if(intp(amount) && (amount > 0))
    {
        researchPoints += amount;
        ret = researchPoints;
        
        object events = getModule("events");
        if(events && objectp(events))
        {
            events->notify("onResearchPointsAdded");
        }        
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int researchPoints()
{
    return researchPoints;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *availableResearchTrees()
{
    string *ret = openResearchTrees;
    
    string *servicesToCheck = ({ "races", "guilds", "traits", "background" });
    
    foreach(string serviceToCheck in servicesToCheck)
    {
        string methodToExecute = sprintf("%sResearchTrees", serviceToCheck);

        object service = getModule(serviceToCheck);
        if(service && function_exists(methodToExecute, service))
        {
            string *trees = call_other(service, methodToExecute);

            if (sizeof(trees))
            {
                ret += trees;
            }
        }
    }
    
    // Strip out any redundant research trees, any possible null elements
    if (sizeof(ret))
    {
        ret = m_indices(mkmapping(ret));
        ret -= ({ 0 });
    }
    return ret + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *completedResearch()
{
    return filter(m_indices(research), #'isResearched) + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *researchInProgress()
{
    return m_indices(research) -
        filter(m_indices(research), #'isResearched) + ({});
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkTreeDependenciesMet(string tree, string researchItem)
{
    int ret = 0;
    if(tree && stringp(tree) && researchItem && stringp(researchItem))
    {
        object treeObj = researchService()->researchTree(tree);
        if(treeObj)
        {
            if(treeObj->isMemberOfResearchTree(researchItem) &&
                treeObj->getResearchItem(researchItem))
            {
                ret = treeObj->prerequisitesMetFor(researchItem,
                    this_object());
            }
            else
            {
                ret = 1;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canResearch(string researchItem)
{
    int ret = 0;
    if(researchService()->validResearch(researchItem) &&
       !isResearched(researchItem) && !equivalentIsResearched(researchItem))
    {        
        ret = 1;
        string *researchTrees = availableResearchTrees();
        foreach(string tree in researchTrees)
        {
            ret &&= checkTreeDependenciesMet(tree, researchItem);
        }
        ret &&= researchService()->checkResearchPrerequisites(researchItem,
            this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void registerResearchEvents()
{
    object eventObj = getModule("events");

    if (eventObj && objectp(eventObj))
    {
        string *researchAbilities = activeAndSustainedResearchAbilities();
        foreach(string researchItem in researchAbilities)
        {
            object researchObj =
                researchService()->researchObject(researchItem);

            if (researchObj && researchObj->query("event handler"))
            {
                eventObj->registerEventHandler(researchObj->query("event handler"));
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int initiateResearch(string researchItem)
{
    int ret = 0;
    if(researchItem && stringp(researchItem) && 
       !member(research, researchItem) && canResearch(researchItem))
    {
        switch(researchService()->getResearchType(researchItem))
        {
            case "points":
            {
                if (researchPoints >=
                    researchService()->getResearchCost(researchItem))
                {
                    researchPoints -=
                        researchService()->getResearchCost(researchItem);
                    research[researchItem] = ([
                        "when research began":time(),
                        "when research complete": time(),
                        "time spent learning": 0,
                        "research complete": 1
                    ]);

                    ret = 1;

                    object events = getModule("events");
                    if (events && objectp(events))
                    {
                        events->notify("onResearchCompleted", researchItem);
                    }
                }
                break;
            }
            case "timed":
            {
                research[researchItem] = ([
                    "when research began": time(),
                    "time to complete learning": 
                        researchService()->getResearchCost(researchItem),
                    "time spent learning": 0,
                    "research complete": 0
                ]);
                ret = 1;
                
                object events = getModule("events");
                if(events && objectp(events))
                {
                    events->notify("onResearchStarted", researchItem);
                }                 
                break;
            }
            case "granted":
            case "tree root":
            {
                research[researchItem] = ([
                    "when research began": time(),
                    "when research complete": time(),
                    "time spent learning": 0,
                    "research complete": 1
                ]);
                ret = 1;
                
                object events = getModule("events");
                if(events && objectp(events))
                {
                    events->notify("onResearchCompleted", researchItem);
                }                   
                break;
            }              
            default:
            {
                // Do nothing
            }
        }
    }
    if (ret)
    {
        string *bonuses = researchService()->getResearchBonuses(researchItem);
        if (bonuses && sizeof(bonuses) &&
            !researchService()->isActiveOrSustainedAbility(researchItem))
        {
            research[researchItem]["bonuses"] = bonuses;
        }
        registerResearchEvents();

        object state = getModule("state");
        if (state)
        {
            state->resetCaches();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getResearchChoices()
{
    return researchChoices + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addResearchChoice(mapping researchChoice)
{
    int ret = researchChoice && mappingp(researchChoice) &&
        member(researchChoice, "name") &&
        stringp(researchChoice["name"]) &&
        member(researchChoice, "description") &&
        stringp(researchChoice["description"]) &&
        member(researchChoice, "research objects") &&
        pointerp(researchChoice["research objects"]);

    if (ret)
    {
        string *availableChoices = researchChoice["research objects"] -
            m_indices(research);

        int selection = 1;
        mapping choices = ([]);
        foreach(string researchItem in availableChoices)
        {
            if(canResearch(researchItem))
            {
                object researchObj = researchService()->researchObject(researchItem);
                if(researchObj)
                {
                    choices[to_string(selection)] = ([
                        "choice": researchChoice["name"],
                        "type": "research object",
                        "name": researchObj->query("name"),
                        "description": researchObj->query("description"),
                        "key": researchItem
                    ]);

                    if (member(researchChoice, "apply if chosen"))
                    {
                        choices[to_string(selection)]["dependency"] =
                            researchChoice["apply if chosen"];
                    }
                    selection++;
                }
            }
            else if(researchService()->researchTree(researchItem))
            {
                object researchTree = researchService()->researchTree(researchItem);
                choices[to_string(selection)] = ([
                    "choice": researchChoice["name"],
                    "type": "research tree",
                    "name": researchTree->Name(),
                    "description": researchTree->Description(),
                    "key": researchItem,
                    "obsoletes": availableChoices - ({ researchItem })
                ]);

                if (member(researchChoice, "apply if chosen"))
                {
                    choices[to_string(selection)]["dependency"] =
                        researchChoice["apply if chosen"];
                }
                selection++;                
            }
            else
            {
                ret = 0;
            }
        }

        if (ret && sizeof(availableChoices))
        {
            researchChoices[researchChoice["name"]] = choices;

            object events = getModule("events");
            if (events && objectp(events))
            {
                events->notify("onResearchChoiceAvailable", choices);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void processResearchChoice(string researchItem, string choice, 
    string selection, string event)
{
    string *choicesToObsolete = member(researchChoices[choice][selection], "obsoletes") ?
        researchChoices[choice][selection]["obsoletes"] : ({});

    foreach(string potentialRemoval in m_indices(researchChoices))
    {
        if (member(researchChoices[potentialRemoval]["1"], "dependency"))
        {
            foreach(string element in
                researchChoices[potentialRemoval]["1"]["dependency"])
            {
                if (member(choicesToObsolete, element) > -1)
                {
                    m_delete(researchChoices, potentialRemoval);
                }
            }
        }
    }

    m_delete(researchChoices, choice);

    object events = getModule("events");
    if (events && objectp(events))
    {
        events->notify(event, researchItem);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int selectResearchChoice(string researchItem, string choice,
    string selection)
{

    int ret = member(researchChoices, choice) &&
        initiateResearch(researchItem);

    if(ret)
    {
        processResearchChoice(researchItem, choice, selection,
            "onResearchChoiceChosen");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addResearchTree(string researchTree)
{
    int ret = 0;

    object treeObj = researchService()->researchTree(researchTree);
    if(treeObj && (member(openResearchTrees, researchTree) < 0))
    {
        ret = treeObj->checkPrerequisites(this_object()) && treeObj->TreeRoot()
            && researchService()->checkResearchPrerequisites(treeObj->TreeRoot(),
            this_object()) && initiateResearch(treeObj->TreeRoot());
            
        if(ret)
        {
            openResearchTrees += ({ researchTree });
            
            object events = getModule("events");
            if(events && objectp(events))
            {
                events->notify("onResearchTreeOpen");
            }               
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int selectResearchPath(string researchTree, string choice,
    string selection)
{
    int ret = member(researchChoices, choice) && 
        addResearchTree(researchTree);

    if (ret)
    {
        processResearchChoice(researchTree, choice, selection,
            "onResearchPathChosen");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *researchExtraAttacks()
{
    mapping *extraAttacks = ({ });
    string *researchItems = filter(m_indices(research),
        (: (member(research[$1], "bonuses") &&
           sizeof(regexp(research[$1]["bonuses"], "bonus [^ ]+ attack"))) :));

    foreach(string researchItem in researchItems)
    {
        if(canApplyResearchBonus(researchItem))
        {
            extraAttacks += researchService()->extraAttacks(researchItem,
                this_object());
        }
    }
    
    // Strip out any potential null elements
    extraAttacks -= ({ 0 });
    
    return extraAttacks + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping researchEnchantments()
{
    mapping enchantments = ([]);
    string *researchItems = filter(m_indices(research),
        (: (member(research[$1], "bonuses") &&
            !sizeof(regexp(research[$1]["bonuses"], "crafting")) &&
            sizeof(regexp(research[$1]["bonuses"], 
                "bonus [^ ]+ enchantment$"))) :));

    foreach(string researchItem in researchItems)
    {
        if (canApplyResearchBonus(researchItem))
        {
            mapping itemEnchantment = 
                researchService()->enchantments(researchItem);

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
public nomask int researchAttributeBonus(string attribute)
{
    int ret = 0;
    
    if(attribute && stringp(attribute))
    {
        string *researchItems = filter(m_indices(research),
            (: (member(research[$1], "bonuses") &&
                sizeof(regexp(research[$1]["bonuses"], 
                "bonus " + $2))) :), attribute);

        foreach(string researchItem in researchItems)
        {
            if(canApplyResearchBonus(researchItem, attribute))
            {
                string method = sprintf("%sBonus", capitalize(attribute));
                if(function_exists(method, researchService()))
                {
                    ret += call_other(researchService(), method,
                        researchItem);
                }
            }
        }    
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int researchBonusTo(string bonus)
{
    int ret = 0;

    if (member(({ "MaxHitPoints", "MaxSpellPoints",
            "MaxStaminaPoints" }), bonus) > -1)
    {
        string *sustainedResearchActive = filter(m_indices(research),
            (: (member(research[$1], "sustained active") &&
               research[$1]["sustained active"]) :));

        foreach(string researchItem in sustainedResearchActive)
        {
            ret -= call_other(researchService(),
                "applySustainedCostTo", researchItem, bonus);
        }
    }

    if(function_exists(bonus, researchService()))
    {
        string bonusString = 
            getService("bonuses")->getBonusFromFunction(bonus);

        string *researchItems = filter(m_indices(research),
            (: (member(research[$1], "bonuses") &&
                sizeof(regexp(research[$1]["bonuses"], $2))) :), bonusString);

        foreach(string researchItem in researchItems)
        {
            if(canApplyResearchBonus(researchItem, bonus))
            {
                ret += call_other(researchService(), bonus, researchItem);
            }
        }
    }
    else if(function_exists("BonusSkillModifier", researchService()))
    {
        string *researchItems = filter(m_indices(research),
            (: (member(research[$1], "bonuses") &&
                sizeof(regexp(research[$1]["bonuses"], 
                "bonus " + $2))) :), bonus);

        foreach(string researchItem in researchItems)
        {
            if(researchService()->researchEffectIsLimited(researchItem) &&
               canApplyResearchBonus(researchItem, bonus))
            {
                object target = this_object()->itemBeingCrafted() ?
                    this_object()->itemBeingCrafted() :
                    this_object()->getTargetToAttack();

                ret += call_other(researchService(), "LimitedSkillModifier",
                    researchItem, bonus, this_object(), target);
            }        
            else if(canApplyResearchBonus(researchItem, bonus))
            {
                ret += call_other(researchService(), "BonusSkillModifier",
                    researchItem, bonus);
            }           
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void applyCooldown(string researchItem, object researchObj)
{
    int cooldown = researchObj->cooldown(this_object());
    if (cooldown)
    {
        research[researchItem]["cooldown"] = cooldown;

        if (researchObj->query("cooldown group"))
        {
            string *otherItems =
                getService("research")->cooldownGroup(researchItem);

            if (sizeof(otherItems))
            {
                foreach(string item in otherItems)
                {
                    if (isResearched(item))
                    {
                        research[item]["cooldown"] = cooldown;
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int researchCommand(string command)
{
    int ret = 0;
    string commandToExecute = 0;
    string customEvent = 0;
    object researchObj = 0;

    string *researchAbilities = activeAndSustainedResearchAbilities();

    foreach(string researchItem in researchAbilities)
    {
        researchObj = researchService()->researchObject(researchItem);
        string tempCommand = command;

        if(researchObj)
        {
            if ((researchObj->query("scope") == "targeted") &&
                researchObj->query("command combinations") &&
                !sizeof(regexp(({ command }), "at [A-Za-z]+")))
            {
                tempCommand += " at " + this_object()->Name();
            }
            else if ((researchObj->query("scope") == "targeted") &&
                !researchObj->getTarget(this_object(), command))
            {
                tempCommand +=
                    regreplace(researchObj->query("command template"),
                        command + " [[]*([a-z]+) ##Target##.*",
                        " \\1 " + this_object()->Name(), 1);
            }

            if(researchObj->canExecuteCommand(tempCommand))
            {
                customEvent = researchObj->query("event handler");
                commandToExecute = researchItem;
                command = tempCommand;
                break;
            }
        }
    }
    if(commandToExecute && canApplyLimitedEffect(commandToExecute, command))
    {
        ret = researchService()->researchCommand(commandToExecute,
            command, this_object());

        if (ret && researchObj && (researchObj->query("type") != "sustained"))
        {
            applyCooldown(commandToExecute, researchObj);
        }

        object eventObj = getModule("events");
        if (ret && customEvent && eventObj && objectp(eventObj))
        {
            eventObj->notify(customEvent);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask void researchHeartBeat()
{
    // Only increment the time spent / decrement usage counters
    // when not idle.
    if(query_idle(this_object()) < 60)
    {
        string *listOfTimedResearch = researchInProgress();

        foreach(string researchItem in listOfTimedResearch)
        {
            if (researchItem && stringp(researchItem))
            {
                if (!member(research[researchItem], "research complete") ||
                    !research[researchItem]["research complete"])
                {
                    research[researchItem]["time spent learning"] += 2;
                }

                if (research[researchItem]["time to complete learning"] <=
                    research[researchItem]["time spent learning"])
                {
                    research[researchItem]["when research complete"] = time();
                    research[researchItem]["research complete"] = 1;

                    object events = getModule("events");
                    if (events && objectp(events))
                    {
                        registerResearchEvents();
                        events->notify("onResearchCompleted", researchItem);
                    }
                }
            }
        }

        string *listOfBlockedResearch = 
            filter(m_indices(research), #'blockedByCooldown);

        foreach(string researchItem in listOfBlockedResearch)
        {
            if (researchItem && stringp(researchItem))
            {
                if(member(research[researchItem], "active count") &&
                        (research[researchItem]["active count"] > 0))
                {
                    research[researchItem]["active count"] -= 2;
                    if(research[researchItem]["active count"]  < 1)
                    {
                        m_delete(research[researchItem], "active count");
                    }
                }
                
                if (member(research[researchItem], "cooldown"))
                {
                    research[researchItem]["cooldown"] -= 2;
                    if (!blockedByCooldown(researchItem))
                    {
                        m_delete(research[researchItem], "cooldown");
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getCompositeResearch(string constraint,
    string itemName, int addParent)
{
    mapping filteredList = filter(compositeResearch,
        (: (($2["constraint"] == $3) && (!$4 || ($1 == $4) ||
           ($2["alias"] == $4))) :), constraint, itemName);

    return (!itemName || addParent || !sizeof(filteredList)) ? 
        filteredList : filteredList[m_indices(filteredList)[0]];
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getOptionsForCompositeResearch(string constraint)
{
    return getCompositeResearch(constraint);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getNextItem(mapping selectedItem, int nextInSequence)
{
    mapping *nextItem = filter(selectedItem["elements"],
        (: $1["order in sequence"] == nextInSequence :));
    return sizeof(nextItem) ? nextItem[0] : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getNextCompositeResearchElement()
{
    mapping ret = 0;
    mapping selectedItem = activeCompositeResearch ?
        getCompositeResearch(
        activeCompositeResearch["constraint"],
        activeCompositeResearch["name"]) : 0;

    object researchObj = activeCompositeResearch ?
        getService("research")->researchObject(
            activeCompositeResearch["constraint"]) : 0;

    if (sizeof(selectedItem) && member(selectedItem, "elements") &&
        sizeof(selectedItem["elements"]) &&
        member(selectedItem, "current item in sequence") &&
        researchObj && researchObj->canApplySpecification(
            activeCompositeResearch["name"], this_object(), 0, 1))
    {
        int nextItem = 1;
        if (selectedItem["current item in sequence"] != 0)
        {
            nextItem = selectedItem["current item in sequence"]
                ["order in sequence"] + 1;
        }
        ret = getNextItem(selectedItem, nextItem);

        if (ret)
        {
            selectedItem["current item in sequence"] = ret;
        }
        else
        {
            activeCompositeResearch = 0;
            m_delete(selectedItem, "current item in sequence");
        }
    }
    else
    {
        tell_object(this_object(), 
            "Your performance has been aborted.\n");
        activeCompositeResearch = 0;

        if (sizeof(selectedItem))
        {
            m_delete(selectedItem, "current item in sequence");
        }
    }
    return ret ? ret + ([]) : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int deactivateCompositeResearch(string constraint, 
    string itemName)
{
    int ret = 0;
    mapping selectedItem = getCompositeResearch(constraint, itemName);

    if (mappingp(selectedItem) && sizeof(selectedItem) &&
        activeCompositeResearch && 
        (activeCompositeResearch["constraint"] == constraint) &&
        (activeCompositeResearch["name"] == itemName))
    {
        ret = 1;
        activeCompositeResearch = 0;
        m_delete(selectedItem, "current item in sequence"); 
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasActiveCompositeResearch()
{
    return activeCompositeResearch != 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getActiveCompositeResearch()
{
    return activeCompositeResearch ? (activeCompositeResearch + ([])) : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object activeCompositeResearch()
{
    object ret = 0;
    if (activeCompositeResearch)
    {
        ret = getService("research")->researchObject(
            activeCompositeResearch["constraint"]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int activateCompositeResearch(string constraint, 
    string itemName)
{
    int ret = 0;
    mapping selectedItem = getCompositeResearch(constraint, itemName);

    if (mappingp(selectedItem) && sizeof(selectedItem) &&
        !activeCompositeResearch &&
        !member(selectedItem, "current item in sequence"))
    {
        activeCompositeResearch = ([
            "constraint": constraint,
            "name": itemName
        ]);

        selectedItem["current item in sequence"] = 0;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int setCompositeResearch(string itemName, mapping data)
{
    int ret = 0;

    if (researchService()->isValidCompositeResearch(itemName, data))
    {
        ret = 1;
        compositeResearch[itemName] = data + ([]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int deleteCompositeResearch(string itemName)
{
    int ret = 0;

    if (member(compositeResearch, itemName))
    {
        ret = 1;
        removeCompositeResearch(this_object()->RealName(),
            itemName, compositeResearch[itemName]["constraint"]);
        m_delete(compositeResearch, itemName);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping categorizedResearch()
{
    mapping ret = ([]);
    string *knownResearch =
        filter(m_indices(research), #'isResearched) + 
            availableResearchTrees() + ({});

    object service = researchService();
    foreach(string element in knownResearch)
    {
        object researchObj = service->researchObject(element);
        string source = "";
        string name = "";

        if (!researchObj)
        {
            researchObj = service->researchTree(element);
            name = lower_case(researchObj->Name());
            source = researchObj->Source();
        }
        else
        {
            name = lower_case(researchObj->query("name"));
            source = researchObj->query("source");
        }
        if (!member(ret, source))
        {
            ret[source] = ([]);
        }
        ret[source][convertToTextOfLength(name, 22)] = element;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void removeResearchBySource(string source)
{
    string* itemsToRemove =
        researchService()->getResearchItemsBySource(this_object(), source);

    if (sizeof(itemsToRemove))
    {
        foreach(string item in itemsToRemove)
        {
            mapping compositeItems = filter(compositeResearch, 
                (: $2["constraint"] == $3 :), item);
            foreach(string compositeItem in m_indices(compositeItems))
            {
                deleteCompositeResearch(compositeItem);
            }
            m_delete(research, item);
        }
    }

    string* treesToRemove =
        researchService()->getResearchTreesBySource(this_object(), source);

    if (sizeof(treesToRemove))
    {
        foreach(string item in treesToRemove)
        {
            openResearchTrees -= ({ item });
        }
    }

    removeSavedResearch(itemsToRemove, treesToRemove);
}
