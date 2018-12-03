//*****************************************************************************
// Class: baseGuild
// File Name: baseGuild.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";

private int MaxLevel = 1000;
private float ExperienceMultiplier = 1.0;
private string PrerequisiteObject = "lib/core/prerequisites.c";
private string guildName = "BaseGuild";
private string *preferredSkills = ({ "general", "erudite", "language" });
protected int CanLeaveGuild = 1;
protected string *ProhibitedGuilds = ({ });
protected mapping prohibitedEquipment = ([]);
private int IsNonCombatGuild = 0;

private mapping ranks = ([ 
//  This mapping must have the following form:
//  "rank name": ([
//      "prerequisiste": <prereq in inherited prerequisites mapping>,
//      "name": <name>,
//      "title": <title>,
//      "pretitle": <pretitle>,
//      "previous rank": <key for previous rank>
//      "next rank": <key for next rank>
//      "delay for next promotion": 24 <time in hours>
//  ]),
// As can be noted, ranks must be linear given this form. Issue 276 has
// been created to consider broadening the scope of this.
    "default": ([
        "delay for next promotion": 4,
    ])
]);

private mapping bonusGrid = ([ ]);
private mapping advancementGrid = ([ ]);

private string *validTypes = ({ "skill", "research", "modifier", "trait", 
    "skill points", "attribute points", "research points", "attack", 
    "research tree", "research path", "research choice" });

private mapping criteriaMap = ([ 
//  criteria will be sparsely populated
//  "<item>": ([
//      "type": skill|research|research tree|modifier|trait|points|attack|research choice
//      "apply": "<#> every [<#>] level[s]|at level #|at rank #",
//      "begin at level": <level>,   // all begin/end criteria MUST match
//      "end at level": <level>,     // in order to have <item> applied
//      "begin at rank": <rank>,
//      "end at rank": <rank>,
//      "begin when researched": <research>
//  ]),
//  Examples:
//  "hit points": ([
//      "type": "modifier",
//      "apply": "5 every level",
//  ]),
//  "attribute points": ([
//      "type": "attribute points",   // meaning spendable points on any attribute
//      "apply": "1 every level"
//  ]),
//  "skill points": ([
//      "type": "skill points",
//      "apply": "3 every level",
//  ]),
//  "research points": ([
//      "type": "research points",
//      "apply": "1 every level",
//  ]),
//  "long sword": ([
//      "type": "skill",
//      "apply": "1 every 2 levels",
//      "begin at level": 3,
//      "end at level": 10
//  ]),
//  "fireball": ([
//      "type": "research",
//      "research object": "<path and file name>",
//      "apply": "at level 10",
//  ]),
//  "inquisitive": ([
//      "type": "trait",
//      "trait object": "<path and file name>",
//      "apply": "at rank archmage"
//  ]),
//  "elemental fire": ([
//      "type": "research tree",
//      "research tree": "<path and file name>",
//      "apply": "at level 5"
//   ]),
//  "magic path": ([
//      "type": "research path",
//      "name": "Magic choice",
//      "description": "...",
//      "research objects": ({ "<path and file name>", "<another>", ... }),
//      "apply": "at level 5"
//   ]),
//  "magic choice": ([
//      "type": "research choice",
//      "name": "Magic choice",
//      "description": "...",
//      "research objects": ({ "<path and file name>", "<another>", ... }),
//      "apply": "at level 5"
//   ]),
//  "fireball enhancement": ([
//      "type": "research",
//      "research object": "<path and file name>",
//      "apply": "at level 15"
//      "apply if chosen": ({ "<research or tree>" })
//   ]),
//  "weapon attack": ([
//      "type": "attack",
//      "apply": "1 every 15 levels,
//      "begin at level": 10,
//      "begin at rank": "corporal"
//  ]),
//  "fire attack": ([
//      "type": "attack",
//      "base damage": 25,
//      "apply": "1 every 15 levels,
//      "begin at level": 10,
//      "begin at rank": "corporal"
//  ])
]);

/////////////////////////////////////////////////////////////////////////////
protected nomask object getDictionary(string service)
{
    object ret = 0;
    
    if(service && stringp(service))
    {
        string dictionary = sprintf("/lib/dictionaries/%sDictionary.c",
            service);
        if(file_size(dictionary) > -1)
        {
            ret = load_object(dictionary);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{   
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        if (guildName == "BaseGuild")
        {
            SetupGuild();
        }

        object guildDictionary = getDictionary("guilds");
        if (guildDictionary && (guildName != "BaseGuild") &&
            (member(guildDictionary->validGuilds(), guildName) == -1))
        {
            guildDictionary->registerGuild(program_name(this_object()));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidCriteriaType(string type)
{
    int ret = type && stringp(type) && (member(validTypes, type) > -1);
    if(!ret)
    {
        raise_error("baseGuild::isValidCriteriaType - an invalid criteria "
            "'type' was supplied.");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidCriteriaApply(string instruction)
{
    int ret = (
       sizeof(regexp(({ instruction }), "[0-9]+ every ([0-9]+ )*level(s*)")) ||
       sizeof(regexp(({ instruction }), "at level [0-9]+")) ||
       (member(m_indices(ranks), 
               regreplace(instruction, "at rank (.+)", "\\1")) > -1));

    if(!ret)
    {
        raise_error("baseGuild::isValidCriteriaApply - an invalid apply "
            "instruction was supplied.");
    }
    return ret;    
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidCriteria(mapping criteria)
{
    // The other things will simply be ignored if invalid
    return (member(criteria, "type") && isValidCriteriaType(criteria["type"]) &&
        member(criteria, "apply") && isValidCriteriaApply(criteria["apply"]) &&
        ((member(criteria, "research object") && getDictionary("research")) ? 
             getDictionary("research")->validResearch(criteria["research object"]) : 1) &&
        ((member(criteria, "research tree") && getDictionary("research")) ? 
             getDictionary("research")->researchTree(criteria["research tree"]) : 1) &&
        ((member(criteria, "trait object") && getDictionary("traits")) ? 
             getDictionary("traits")->validTrait(criteria["trait object"]) : 1));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int insertBonusItem(int level, string rank, string key, string type, int amount)
{
    int ret = 0;

    if (!member(bonusGrid, key))
    {
        bonusGrid[key] = ([]);
    }
    if(!member(bonusGrid[key], rank))
    {
        bonusGrid[key][rank] = ([ ]);
    }

    switch(type)
    {
        case "modifier":
        case "skill":
        case "attack":
        {
            if(member(bonusGrid[key][rank], level))
            {
                bonusGrid[key][rank][level] += amount;
            }
            else
            {
                bonusGrid[key][rank][level] = amount;
            }
            ret = 1;
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int insertAdvancementItem(mixed level, string key)
{
    int ret = 0;
    if(level && key && stringp(key))
    {
        if(!member(advancementGrid, level))
        {
            advancementGrid[level] = ([ ]);
        }
        if(!member(advancementGrid[level], key))
        {
            // This is by reference... NEVER change it.
            advancementGrid[level][key] = criteriaMap[key];
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string guildName(string newName)
{
    if(newName && stringp(newName))
    {
        guildName = newName;
    }
    return guildName;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isNonCombatGuild()
{
    return IsNonCombatGuild;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void nonCombatGuild()
{
    IsNonCombatGuild = 1;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int addAdvancementPrerequisite(string grouping, mapping prerequisiteList)
{
    int ret = 1;
    string *prerequisitesInList = m_indices(prerequisiteList);
    foreach(string prerequisite in prerequisitesInList)
    {
        ret &&= validPrerequisite(prerequisiteList[prerequisite]) &&
            addPrerequisite(prerequisite, prerequisiteList[prerequisite], grouping);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addLevelPrerequisite(int level, mapping prerequisiteList)
{
    int ret = 0;
    if(level && intp(level) && sizeof(prerequisiteList))
    {
        ret = addAdvancementPrerequisite(sprintf("level %d", level), 
            prerequisiteList);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addRankPrerequisite(string rank, mapping prerequisiteList)
{
    int ret = 0;
    if(rank && stringp(rank) && member(ranks, rank) && 
        sizeof(prerequisiteList))
    {
        ret = addAdvancementPrerequisite(rank, prerequisiteList);
        ranks[rank]["prerequisite"] = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addPreferredSkillType(string type)
{
    int ret = 0;
    if (member(preferredSkills, type) < 0)
    {
        preferredSkills += ({ type });
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int setDefaultRank(string rankName)
{
    int ret = 0;
    if (member(ranks, rankName))
    {
        ranks["default"]["next rank"] = rankName;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string startingRank()
{
    string ret = 0;
    if (member(ranks, "default") && member(ranks["default"], "next rank"))
    {
        ret = ranks["default"]["next rank"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addRank(string rankName, mapping criteria)
{
    int ret = criteria && mappingp(criteria) && 
        (member(criteria, "name") ? stringp(criteria["name"]) : 1) &&
        (member(criteria, "title") ? stringp(criteria["title"]) : 1) &&
        (member(criteria, "pretitle") ? stringp(criteria["pretitle"]) : 1) &&
        (member(criteria, "previous rank") ? 
            stringp(criteria["previous rank"]) : 1) &&
        (member(criteria, "next rank") ? 
            stringp(criteria["next rank"]) : 1) &&
        (member(criteria, "delay for next promotion") ? 
            intp(criteria["delay for next promotion"]) : 1);
    if(ret)
    {
        ranks[rankName] = criteria + ([ ]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int addEveryLevelCriteria(string key, mapping criteria, string rank)
{
    int ret = 1;

    int beginAt = (member(criteria, "begin at level") &&
        intp(criteria["begin at level"])) ? criteria["begin at level"] : 1;
    int endAt = (member(criteria, "end at level") &&
        intp(criteria["end at level"])) ? criteria["end at level"] :
        MaxLevel;

    int amount;
    int frequency = 1;
    sscanf(criteria["apply"], "%d every %d", amount, frequency);
    insertBonusItem(0, rank, key, criteria["type"], 0);
    int valueAtEnd = 0;

    for (int level = 1; level <= MaxLevel; level++)
    {
        if ((level >= beginAt) && (level <= endAt))
        {
            if (member(({ "modifier", "skill", "attack" }),
                criteria["type"]) > -1)
            {
                ret &&= insertBonusItem(level, rank, key, criteria["type"], 
                    amount * ((1 + level - beginAt) / frequency));
                valueAtEnd = amount * ((1 + level - beginAt)/ frequency);
            }
            else if(((level - beginAt) % frequency) == 0)
            {
                ret &&= insertAdvancementItem(level, key);
            }
        }
        else if (member(({ "modifier", "skill", "attack" }),
                criteria["type"]) > -1)
        {
            insertBonusItem(level, rank, key, criteria["type"], valueAtEnd);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int addAtLevelCriteria(string key, mapping criteria, string rank)
{
    int ret = 1;
    int level;
    sscanf(criteria["apply"], "at level %d", level);
    if (member(({ "modifier", "skill", "attack" }),
        criteria["type"]) > -1)
    {
        ret &&= insertBonusItem(level, rank, key, criteria["type"], 1);
        for (int i = level + 1; i <= 20; i++)
        {
            bonusGrid[key][rank][i] = bonusGrid[key][rank][i - 1];
        }
    }
    else
    {
        ret &&= insertAdvancementItem(level, key);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int addAtRankCriteria(string key, mapping criteria)
{
    int ret = 1;
    string rank = regreplace(criteria["apply"], "at rank (.+)", "\\1");
    if (member(({ "modifier", "skill", "attack" }),
        criteria["type"]) > -1)
    {
        ret &&= insertBonusItem(1, rank, key, criteria["type"], 1);
    }
    else
    {
        ret &&= insertAdvancementItem(rank, key);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addCriteria(string key, mapping criteria)
{
    int ret = 0;
    if(key && stringp(key) && criteria && 
       isValidCriteria(criteria))
    {
        criteriaMap[key] = criteria + ([ ]);
        
        string rank = (member(criteria, "begin at rank") &&
            stringp(criteria["begin at rank"])) ?
            criteria["begin at rank"] : "default";

        if(sizeof(regexp(({ criteria["apply"] }), 
           "[0-9]+ every ([0-9]+ )*level(s*)")))
        {
            ret = addEveryLevelCriteria(key, criteria, rank);
        }
        else if(sizeof(regexp(({ criteria["apply"] }), "at level [0-9]+")))
        {
            ret = addAtLevelCriteria(key, criteria, rank);
        }
        else if(member(m_indices(ranks), 
               regreplace(criteria["apply"], "at rank (.+)", "\\1")) > -1)
        {
            ret = addAtRankCriteria(key, criteria);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int experienceToNextLevel(int currentLevel)
{
    int ret = 0x7FFFFFFF;
    if(currentLevel > 0)
    {
        // There's an elegance in simplicity, yes?
        ret = to_int(currentLevel * 1000 * ExperienceMultiplier);
    }
    else if (currentLevel == 0)
    {
        ret = 0;
    }
    else
    {
        raise_error(
            sprintf("baseGuild: Error in experienceToNextLevel "
                "guild file: %s", object_name(this_object())));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canAdvanceLevel(object guildMember)
{
    int ret = 0;
    if(guildMember && objectp(guildMember) && guildMember->has("guilds") &&
        guildMember->memberOfGuild(guildName()))
    {
        int curLevel = guildMember->guildLevel(guildName());

        ret = checkPrerequisites(guildMember, "level", to_string(curLevel + 1)) &&
            (guildMember->guildExperience(guildName()) >=
                experienceToNextLevel(curLevel));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getNextRank(string rank)
{
    string ret = "default";
    if(rank && member(ranks, rank) && member(ranks[rank], "next rank"))
    {
        ret = member(ranks, ranks[rank]["next rank"]) ?
            ranks[rank]["next rank"] : rank;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int delayUntilNextRank(string rank)
{
    int ret = 0;
    if(member(ranks, rank) && member(ranks[rank], "delay for next promotion") &&
       intp(ranks[rank]["delay for next promotion"]))
    {
        ret = ranks[rank]["delay for next promotion"] * 3600;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canAdvanceRank(object guildMember, string rank)
{
    int ret = 0;

    if(guildMember && objectp(guildMember) && guildMember->has("guilds") &&
        guildMember->memberOfGuild(guildName()))
    {
        string rankToCheck = rank ? rank : "default";
        string advancementRank = getNextRank(rankToCheck);

        if(rankToCheck != advancementRank)
        {
            int rankDelay = guildMember->ageWhenRankAdvanced(guildName()) +
                delayUntilNextRank(guildMember->guildRank(guildName()));

            ret = checkPrerequisites(guildMember, "rank", 
                advancementRank) && (rankDelay <= guildMember->Age());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int queryBonus(string bonus, int level, string rank)
{
    int ret =  0;
    string bonusToCheck;
    if(sscanf(bonus, "bonus %s", bonusToCheck))
    {
        if (!rank || !stringp(rank) || !sizeof(rank))
        {
            rank = "default";
        }

        if(getDictionary("bonuses") && objectp(getDictionary("bonuses")) &&
           getDictionary("bonuses")->isValidBonus(bonusToCheck) &&
           member(bonusGrid, bonusToCheck))
        {
            if (rank != "default" &&
                member(bonusGrid[bonusToCheck], "default") &&
                member(bonusGrid[bonusToCheck]["default"], level))
            {
                ret += bonusGrid[bonusToCheck]["default"][level];
            }
            if(member(bonusGrid[bonusToCheck], rank) &&
                member(bonusGrid[bonusToCheck][rank], level))
            {
                ret += bonusGrid[bonusToCheck][rank][level];
            }

            if(!member(criteriaMap[bonusToCheck], "begin at level") &&
                member(criteriaMap[bonusToCheck], "begin at rank") && 
                member(bonusGrid[bonusToCheck], rank))
            {
                ret += bonusGrid[bonusToCheck][rank][1];
            }
            if (rank != "default" && 
                !member(criteriaMap[bonusToCheck], "begin at level") &&
                member(criteriaMap[bonusToCheck], "begin at rank") &&
                member(bonusGrid[bonusToCheck], "default"))
            {
                ret += bonusGrid[bonusToCheck]["default"][1];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int advancementAmount(mapping criterion)
{
    int ret = 0;
    if (sizeof(regexp(({ criterion["apply"] }), "at level [0-9]+")) ||
        (member(m_indices(ranks),
            regreplace(criterion["apply"], "at rank (.+)", "\\1")) > -1))
    {
        ret = 1;
    }
    else
    {
        sscanf(criterion["apply"], "%d every ", ret);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyTraitCriterion(mapping criterion, object guildMember)
{
    int ret = 0;

    if (guildMember->has("traits") &&
        member(criterion, "trait object") &&
        getDictionary("traits") &&
        getDictionary("traits")->validTrait(criterion["trait object"]))
    {
        ret = guildMember->addTrait(criterion["trait object"]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applySkillCriterion(mapping criterion, object guildMember)
{
    int ret = 0;
    if (guildMember->has("skills"))
    {
        ret = guildMember->addSkillPoints(advancementAmount(criterion));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyAttributeCriterion(mapping criterion, object guildMember)
{
    int ret = 0;
    if (guildMember->has("attributes"))
    {
        ret = guildMember->addAttributePointsToSpend(advancementAmount(criterion));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyResearchPointsCriterion(mapping criterion, object guildMember)
{
    int ret = 0;
    if (guildMember->has("research"))
    {
        ret = guildMember->addResearchPoints(advancementAmount(criterion));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidResearchCriterion(mapping criterion, string type,
    object guildMember)
{
    return guildMember->has("research") && member(criterion, type) &&
        stringp(criterion[type]) && getDictionary("research") &&
        (getDictionary("research")->validResearch(criterion[type]) ||
            getDictionary("research")->researchTree(criterion[type]));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkApplyIfChosenCriteria(mapping criterion, object guildMember)
{
    int ret = 1;

    if (member(criterion, "apply if chosen") &&
        criterion["apply if chosen"] &&
        pointerp(criterion["apply if chosen"]))
    {
        foreach(string researchItem in criterion["apply if chosen"])
        {
            ret &&= (guildMember->isResearched(researchItem) ||
                (member(guildMember->availableResearchTrees(), researchItem) > -1));
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyResearchCriterion(mapping criterion, object guildMember)
{
    int ret = 0;
    if (isValidResearchCriterion(criterion, "research object", guildMember))
    {
        ret = 1;
        if (checkApplyIfChosenCriteria(criterion, guildMember))
        {
            ret = guildMember->initiateResearch(criterion["research object"]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyResearchTreeCriterion(mapping criterion, object guildMember)
{
    int ret = 0;
    if (isValidResearchCriterion(criterion, "research tree", guildMember))
    {
        ret = 1;
        if (checkApplyIfChosenCriteria(criterion, guildMember))
        {
            ret = guildMember->addResearchTree(criterion["research tree"]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyResearchChoiceCriterion(mapping criterion, object guildMember)
{
    int ret = 0;
    if(guildMember->has("research") && member(criterion, "research objects") &&
        pointerp(criterion["research objects"]) && getDictionary("research"))
    {
        ret = 1;
        guildMember->addResearchChoice(criterion);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyAdvancementCriterion(mapping criterion, object guildMember)
{
    int ret = 0;
    if(isValidCriteria(criterion) && guildMember && objectp(guildMember))
    {
        switch(criterion["type"])
        {
            case "trait":
            {
                ret = applyTraitCriterion(criterion, guildMember);
                break;
            }
            case "skill points":
            {
                ret = applySkillCriterion(criterion, guildMember);
                break;
            }
            case "attribute points":
            {
                ret = applyAttributeCriterion(criterion, guildMember);
                break;
            }
            case "research points":
            {
                ret = applyResearchPointsCriterion(criterion, guildMember);
                break;
            }
            case "research":
            {
                ret = applyResearchCriterion(criterion, guildMember);
                break;
            }
            case "research tree":
            {
                ret = applyResearchTreeCriterion(criterion, guildMember);
                break;
            }
            case "research path":
            case "research choice":
            {
                ret = applyResearchChoiceCriterion(criterion, guildMember);
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyAdvancementCriteria(int newLevel, object guildMember)
{
    int ret = 1;

    string *criteriaToApply = ({ });

    if(member(advancementGrid, newLevel) && advancementGrid[newLevel] && 
       mappingp(advancementGrid[newLevel]))
    {
        criteriaToApply = m_indices(advancementGrid[newLevel]);
        foreach(string criterion in criteriaToApply)
        {
            ret &&= applyAdvancementCriterion(
                advancementGrid[newLevel][criterion], guildMember);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int advanceLevel(object guildMember)
{
    int level = guildMember->guildLevel(guildName());

    if(canAdvanceLevel(guildMember))
    {
        level++;
        level = applyAdvancementCriteria(level, guildMember) ? level : 0;
    }
    return level;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string advanceRank(object guildMember, string currentRank)
{
    string ret = currentRank;

    if(canAdvanceRank(guildMember, currentRank))
    {
        string nextRank = getNextRank(currentRank);

        if(member(advancementGrid, nextRank) && advancementGrid[nextRank] &&
           mappingp(advancementGrid[nextRank]))
        {
            int rankAdvanced = 1;
            string *criteriaToApply = m_indices(advancementGrid[nextRank]);
            foreach(string criterion in criteriaToApply)
            {
                rankAdvanced &&= applyAdvancementCriterion(
                    advancementGrid[nextRank][criterion], guildMember);
            }
            if(rankAdvanced)
            {
                ret = nextRank;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string demoteRank(object guildMember, string currentRank)
{
    string ret = "default";
    if(currentRank && member(ranks, currentRank) && 
       member(ranks[currentRank], "previous rank") &&
       member(ranks, ranks[currentRank]["previous rank"]))
    {
        ret = ranks[currentRank]["previous rank"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isBonusAttack(string bonusItem)
{
    int ret = 0;
    string attackType = 0;
    if(bonusItem && stringp(bonusItem) && member(bonusGrid, bonusItem) &&
       sscanf(bonusItem, "%s attack", attackType) && 
       getDictionary("attacks"))
    {
        ret = (getDictionary("attacks")->getAttack(attackType) != 0) || 
              (attackType == "weapon");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *getExtraAttacks(int level, string rank)
{
    mapping *ret = ({ });
    string *keys = filter(m_indices(bonusGrid), #'isBonusAttack);
    string *ranks = m_indices(mkmapping(({ "default", rank })));

    if(keys)
    {
        foreach(string key in keys)
        {
            // attacksDictionary is verfied to exist via call to
            // isBonusAttack
            string attack = 0;

            if(sscanf(key, "%s attack", attack))
            {
                mapping attackMap =
                    getDictionary("attacks")->getAttackMapping(attack,
                    (member(criteriaMap[key], "base damage") ? 
                    criteriaMap[key]["base damage"] : 1), 35);

                foreach(string checkRank in ranks)
                {
                    if(member(bonusGrid[key], checkRank) &&
                        member(bonusGrid[key][checkRank], level))
                    {
                        for(int numAttacks = 1; 
                            numAttacks <= bonusGrid[key][checkRank][level];
                            numAttacks++)
                        {
                            ret += ({ attackMap });
                        }
                    }
                }
                if(!member(criteriaMap[key], "begin at level") &&
                    member(criteriaMap[key], "begin at rank") &&
                    member(bonusGrid[key], rank))
                {
                    for(int numAttacks = 1; 
                        numAttacks <= bonusGrid[key][rank][1];
                        numAttacks++)
                    {
                        ret += ({ attackMap });
                    }
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int costToAdvanceSkillOfType(string type)
{
    return (member(preferredSkills, type) > -1) ? 1 : 2;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string rankName(string rank)
{
    return ((member(ranks, rank) && member(ranks[rank], "name")) ? 
        ranks[rank]["name"] : 0);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string pretitle(int level, string rank)
{
    //TODO: Finish this
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string title(int level, string rank)
{
    //TODO: Finish this
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void prohibitLeavingGuild()
{
    CanLeaveGuild = 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canLeaveGuild(object guildMember)
{
    return CanLeaveGuild && !guildMember->isAnathema(guildName);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int prohibitedGuildCombinations(string *guilds)
{
    int ret = 0;

    if(guilds && pointerp(guilds) && sizeof(guilds))
    {
        ret = 1;
        ProhibitedGuilds = guilds;

        object guildDictionary = getDictionary("guilds");
        // Prune invalid guilds
        foreach(string guild in ProhibitedGuilds)
        {
            if(!guildDictionary->guildObject(guild))
            {
                ProhibitedGuilds -= ({ guild });
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *prohibitedGuilds()
{
    return ProhibitedGuilds + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int outcastUntilDelay()
{
    //TODO: Finish this? - for now, 10 days
    return 864000;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addEquipmentProhibition(string type, string *data)
{
    string *validTypes = ({ "material", "material type", "armor type", "armor location",
        "weapon type", "damage type" });

    int ret = 1;

    object materialsDictionary = getDictionary("materials");

    if(data && sizeof(data))
    {
        foreach(string material in data)
        {
            switch(type)
            {
                case "material":
                {
                    ret &&= materialsDictionary->isValidMaterial(material);
                    break;
                }
                case "material type":
                {
                    ret &&= materialsDictionary->isValidMaterialType(material);
                    break;
                }
                case "armor type":
                {
                    ret &&= materialsDictionary->isValidArmorType(material);
                    break;
                }
                case "armor location":
                {
                    ret &&= materialsDictionary->isValidArmorLocation(material);
                    break;
                }
                case "weapon type":
                {
                    ret &&= materialsDictionary->isValidWeaponType(material);
                    break;
                }
                case "damage type":
                {
                    ret &&= materialsDictionary->isValidDamageType(material);
                    break;
                }
                default:
                {
                    ret = 0;
                    break;
                }
            }
        }
    }
    if (!ret)
    {
        raise_error("baseGuild::addEquipmentProhibition - an invalid prohibition "
            "was supplied.");
    }
    else
    {
        prohibitedEquipment[type] = data;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int materialInProhibitedList(string material)
{
    return member(prohibitedEquipment, "material") &&
        (member(prohibitedEquipment["material"], material) > -1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int materialTypeInProhibitedList(string material)
{
    string materialType = 
        getDictionary("materials")->getMaterialTypeForMaterial(material);

    return materialType && stringp(materialType) &&
        member(prohibitedEquipment, "material type") &&
        (member(prohibitedEquipment["material type"], materialType) > -1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int armorTypeInProhibitedList(object equipment)
{
    string armorType = equipment->query("armor type");

    return armorType && member(prohibitedEquipment, "armor type") &&
        (member(prohibitedEquipment["armor type"], armorType) > -1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int armorLocationInProhibitedList(object equipment)
{
    int ret = 0;

    if(member(prohibitedEquipment, "armor location"))
    {
        int itemMask = equipment->query("equipment locations");
        string *armorLocations = 
            getDictionary("materials")->slotsUsedByItemMask(itemMask);

        if(armorLocations && sizeof(armorLocations))
        {
            foreach(string location in armorLocations)
            {
                ret ||= (member(prohibitedEquipment["armor location"],
                    location) > -1);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int weaponTypeInProhibitedList(object equipment)
{
    string weaponType = equipment->query("weapon type");

    return weaponType && member(prohibitedEquipment, "weapon type") &&
        (member(prohibitedEquipment["weapon type"], weaponType) > -1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int damageTypeInProhibitedList(object equipment)
{
    int ret = 0;

    if (equipment->query("weapon type") &&
        member(prohibitedEquipment, "damage type"))
    {
        string *damageTypes =
            getDictionary("materials")->getMaterialDamageType(equipment);

        if (damageTypes && sizeof(damageTypes))
        {
            foreach(string type in damageTypes)
            {
                ret ||= (member(prohibitedEquipment["damage type"],
                    type) > -1);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canUseEquipmentOfType(object equipment)
{
    return !armorTypeInProhibitedList(equipment) &&
           !armorLocationInProhibitedList(equipment) &&
           !weaponTypeInProhibitedList(equipment);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isProhibitedEquipment(object equipment)
{
    return materialInProhibitedList(equipment->query("material")) ||
        materialTypeInProhibitedList(equipment->query("material")) ||
        damageTypeInProhibitedList(equipment);
}
