//*****************************************************************************
// Class: skills
// File Name: skills.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private int availableSkillPoints;
private mapping skills = ([ ]);


/////////////////////////////////////////////////////////////////////////////
private varargs nomask void skillsNotification(string event, string message)
{
    object eventObj = getService("events");

    if (event && stringp(event) && eventObj && objectp(eventObj))
    {
        eventObj->notify(event, message);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object skillsObject()
{
    return getDictionary("skills");
}

/////////////////////////////////////////////////////////////////////////////
static nomask string *validSkills()
{
    return skillsObject()->validSkills();
}

/////////////////////////////////////////////////////////////////////////////
static nomask string *validBonusSkills()
{
    return skillsObject()->validBonusSkills();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int AvailableSkillPoints()
{
    return availableSkillPoints;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addSkillPoints(int points)
{
    int ret = 0;
    if(intp(points) && (points > 0))
    {
        availableSkillPoints += points;
        ret = availableSkillPoints;
        skillsNotification("onSkillPointsIncreased", to_string(points));
    }
    return ret;
}
    
/////////////////////////////////////////////////////////////////////////////
public nomask int getSkill(string skill)
{
    int ret = 0;
    if(skill && skillsObject()->isValidSkill(skill))
    {
        string *servicesToCheck = ({ "races", "traits", "background", "guilds" });
        
        if(member(skills, skill))
        {
            ret = skills[skill];
            servicesToCheck += ({ "research", "biological" });

            object inventory = getService("inventory");
            if (inventory && objectp(inventory))
            {
                ret += inventory->inventoryGetModifier("bonusSkills",
                    sprintf("bonus %s", skill));
            }

            object room = environment(this_object());
            if (room && (member(inherit_list(room), "lib/environment/room.c") > -1))
            {
                ret += room->environmentalBonusTo(skill, this_object());
            }
        }
    
        foreach(string serviceToCheck in servicesToCheck)
        {
            object service = getService(serviceToCheck);
            if(service)
            {
                ret += call_other(service, 
                       sprintf("%sBonusTo", serviceToCheck), skill);
            }
        }      
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getSkillModifier(string skill)
{
    int ret = 0;
    if(skill && skillsObject()->isValidSkill(skill))
    {        
        ret = skillsObject()->skillBonus(skill, getSkill(skill));

        object attributes = getService("attributes");
        if (attributes && (ret >= 0))
        {
            ret += (attributes->attributeValue(skillsObject()->attributeForSkill(skill)) - 16) / 4;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int advanceSkillCost(string skill, int amount)
{
    int ret = 0;

    if (skill && amount && skillsObject()->isValidSkill(skill))
    {
        ret = amount;

        object guild = getService("guilds");
        if (guild)
        {
            ret = guild->costToAdvanceSkill(
                skillsObject()->skillType(skill)) * amount;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int advanceSkill(string skill, int amount)
{
    int ret = 0;

    if(skill && amount && skillsObject()->isValidSkill(skill))
    {
        if(!member(skills, skill))
        {
            skills[skill] = 0;
        }
    
        int costToAdvance = advanceSkillCost(skill, amount);
     
        if((availableSkillPoints >= costToAdvance) && 
            skillsObject()->canAdvanceSkill(this_object(), skill, 
            amount + skills[skill]))
        {
            skills[skill] += amount;
            availableSkillPoints -= costToAdvance;
            skillsNotification("onSkillAdvanced", skill);
            skillsNotification("onSkillPointsUsed", to_string(costToAdvance));
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int decrementSkill(string skill, int amount)
{
    int ret = 0;

    if(skill && amount && skillsObject()->isValidSkill(skill) &&
       member(skills, skill) && (skills[skill] >= amount))
    {
        int costToAdvance = advanceSkillCost(skill, amount);

        skills[skill] -= amount;
        availableSkillPoints += costToAdvance;
        skillsNotification("onSkillDecreased", skill);
        skillsNotification("onSkillPointsIncreased", to_string(costToAdvance));
        ret = 1;
    }
    return ret;
}

