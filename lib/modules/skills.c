//*****************************************************************************
// Class: skills
// File Name: skills.c
//
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/skills.h"

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
public nomask varargs int getSkill(string skill, int raw)
{
    int ret = 0;
    if(skill && skillsObject()->isValidSkill(skill))
    {
        string *servicesToCheck = ({ "races", "traits", "background", "guilds" });
        
        if(member(skills, skill))
        {
            ret = skills[skill];
            servicesToCheck += ({ "research", "biological" });

            if (!raw)
            {
                object inventory = getService("inventory");
                if (inventory && objectp(inventory))
                {
                    ret += inventory->inventoryGetModifier("bonusSkills",
                        sprintf("bonus %s", skill));
                }

                object room = environment(this_object());
                if (room && (member(inherit_list(room), "/lib/environment/environment.c") > -1))
                {
                    ret += room->environmentalBonusTo(skill, this_object());
                }
            }
        }
    
        if (!raw)
        {
            foreach(string serviceToCheck in servicesToCheck)
            {
                object service = getService(serviceToCheck);
                if (service)
                {
                    ret += call_other(service,
                        sprintf("%sBonusTo", serviceToCheck), skill);
                }
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
            int attributeBonus = (attributes->attributeValue(skillsObject()->attributeForSkill(skill)) - 16) / 4;
            ret += attributeBonus > 0 ? attributeBonus : 0;
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

            object state = getService("state");
            if (state)
            {
                state->resetCaches();
            }
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
private nomask string skillListForType(string type, string colorConfiguration,
    string charset, object banner, object configuration)
{
    string ret = "";

    int x = 1;
    string *skillList = skillsObject()->validSkillsOfType(type);
    string skillsLine = "";
    foreach(string skill in skillList)
    {
        int value = 0;
        if (member(skills, skill))
        {
            value = skills[skill];
        }
        int bonus = getSkill(skill) - value;

        skillsLine += 
            configuration->decorate(sprintf("%24s : ", capitalize(skill)),
                "skill header", "skills", colorConfiguration) +
            configuration->decorate(sprintf("%3d ", value),
                "skill value", "skills", colorConfiguration) +
            ((bonus > 0) ? configuration->decorate(sprintf("(+%2d) ", bonus),
                "modifier", "skills", colorConfiguration) : "      ");

        if (!(x % 2))
        {
            ret += banner->banneredContent(colorConfiguration, charset, skillsLine);
            skillsLine = "";
        }
        else
        {
            skillsLine += " ";
        }
        x++;
    }
    if (!(x % 2))
    {
        skillsLine += sprintf("%37s", "");
        ret += banner->banneredContent(colorConfiguration, charset, skillsLine);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string skillsList(string *types)
{
    string ret = "\n";
    if (!sizeof(types))
    {
        types = ({ "combat", "crafting", "erudite", "subterfuge", "general",
            "magic", "language" });
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
        ret += banner->buildBanner(colorConfiguration, charset,
            "center", type, "Skills") + 
            skillListForType(type, colorConfiguration, charset, banner, 
                configuration);
    }

    ret += banner->buildBanner(colorConfiguration, charset,
        "bottom", "", "", 1);
    ret += configuration->decorate(sprintf("You have %d skill points "
        "available to spend.\n", availableSkillPoints),
        "points remaining", "skills", colorConfiguration);
    return ret;
}
